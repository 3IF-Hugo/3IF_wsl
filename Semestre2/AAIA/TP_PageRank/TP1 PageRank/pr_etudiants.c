/* PageRank 
   The genetic.dat dataset comes from:
   http://www.cs.toronto.edu/~tsap/experiments/datasets/
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* allocate one object of given type */
#define NEW(type) ((type*)calloc((size_t)1,(size_t)sizeof(type)))

/* allocate num objects of given type */
#define NEW_A(num,type) ((type*)calloc((size_t)(num),(size_t)sizeof(type)))

typedef unsigned int u_int;

/* vector */
typedef struct
{
  u_int dim;
  double *e;
} VEC;

/* row of a sparse matrix */
typedef struct
{
  u_int  nnz;  /* # of non-zero (nz) value on this row */
  u_int  *col; /* column identifier for each nz value */
  double *val; /* value for each nz value */
} SROW;

/* sparse matrix */
typedef struct
{
  u_int m, n;
  SROW *row;
} SMAT;

/* v_new -- gets a VEC of dimension 'dim'
   Precondition: size >= 0
   Postcondition: initialized to zero */
VEC *v_new( u_int size )
{
  VEC *v;
  
  if( (v = NEW(VEC)) == (VEC *)NULL )
  {
    fprintf( stderr, "v_new memory error" );
    exit( -1 );
  }
  
  v->dim = size;
  if( (v->e = NEW_A(size,double)) == (double *)NULL )
  {
    free( v );
    fprintf( stderr, "v_new memory error" );
    exit( -1 );
  }
  
  return v;
}

/* v_free -- returns VEC & associated memory back to memory heap */
int v_free( VEC *v )
{
  if( v == (VEC *)NULL )
    return -1;
  
  if( v->e == (double *)NULL ) 
  {
    free( v );
  }
  else
  {
    free( v->e );
    free( v );
  }
  
  return 0;
}

/* sm_new -- gets an mxn sparse matrix by dynamic memory allocation 
   Precondition: m>=0 && n>=0
   Postcondition: each row is empty*/
SMAT *sm_new( u_int m, u_int n )
{
  SMAT *M;
  u_int i;
  
  if( (M = NEW(SMAT)) == (SMAT *)NULL )
  {
    fprintf( stderr, "sm_new memory error" );
    exit( -1 );
  }
  
  M->m = m ; M->n = n;

  if( (M->row = NEW_A(m,SROW)) == (SROW *)NULL )
  {
    free( M );
    fprintf( stderr, "sm_new memory error" );
    exit( -1 );
  }
  
  for( i = 0 ; i < m ; i++ )
  {
    (M->row[i]).nnz = 0;
    (M->row[i]).col = (u_int *) NULL;
    (M->row[i]).val = (double *) NULL;
  }

  return M;
}

/* sm_free -- returns SMAT & associated memory back to memory heap */
int sm_free( SMAT *M )
{
  u_int i;
  SROW *ri;

  if( M == (SMAT *)NULL ) return -1;
  
  if( M->row == (SROW *)NULL ) 
  {
    free( M );
  }
  else
  {
    for( i = 0 ; i < M->m ; i++ )
    {
      ri = &(M->row[i]);
      if( ri->nnz > 0 )
      {
        free( ri->col );
        free( ri->val );
      }
    }
    free( M->row );
    free( M );
  }
  
  return 0;
}

/* sm_input -- file input of sparse matrix 
   Precondition: will only work with a binary matrix. */
SMAT *sm_input( FILE *fp )
{
  SMAT *M;
  u_int *col; /* temp array to store the nz col of the current row */
  u_int r;    /* index of current row */
  int c;      /* index of current column */
  SROW *ri;   /* pointer to the current row in M */
  u_int m,n,i,j,k;
  
  /* get dimension */
  if( fscanf( fp, " SparseMatrix: %u by %u", &m, &n ) < 2 )
  {
    fprintf( stderr, "sm_input error reading dimensions" );
    exit( -1 );
  }
  
  if( (col = NEW_A(n,u_int)) == (u_int *)NULL )
  {
    fprintf( stderr, "sm_input memory error" );
    exit( -1 );
  }

  M = sm_new( m, n );
  
  /* get entries */
  for( i=0 ; i<m ; i++ )
  {
    if( fscanf( fp, " row %u:", &r ) < 1 )
    {
      fprintf( stderr, "sm_input error reading line %u", i );
      exit( -1 );
    }
    ri = &(M->row[i]);
    j = 0;
    for( ; ; )
    {
      if( fscanf( fp, "%d", &c ) < 1 )
      {
        fprintf( stderr, "sm_input error reading line %u col x", i );
        exit( -1 );
      }
      if( c < 0 ) break;
      col[j] = c;
      j++;
    } /* j is the number of nz value in row i */

    if( j!= 0 )
    {
      if( (ri->col = NEW_A(j,u_int)) == (u_int *)NULL )
      {
        fprintf( stderr, "sm_input memory error" );
        exit( -1 );
      }
      if( (ri->val = NEW_A(j,double)) == (double *)NULL )
      {
        fprintf( stderr, "sm_input memory error" );
        exit( -1 );
      }
    }

    ri->nnz = j;

    for( k = 0 ; k < j ; k++ )
    {
      ri->col[k] = col[k]; 
      ri->val[k] = 1.0;
    }
  }
  
  free( col );

  return M;
}

/* sm_output -- file output of sparse matrix 
   Postcondition: the result is not a valid entry for sm_input,
     since it also works for a non-binary matrix. */
void sm_output( FILE *fp, SMAT *M )
{
  u_int i,j;
  SROW *ri;

  fprintf( fp, "SparseMatrix: %d by %d\n", M->m, M->n );

  for( i = 0 ; i < M->m ; i++ )
  {
    fprintf( fp, "row %u: ", i ); 
    ri = &( M->row[i] );
    for( j = 0 ; j < ri->nnz ; j++ )
    {
      fprintf( fp, "%u:%1.5g ", ri->col[j], ri->val[j] );
    }
    fprintf( fp, "-1\n" );
  }
}

/* v_output -- file output of vector */
void v_output( FILE *fp, VEC *v )
{
  u_int i;

  fprintf( fp, "Vector: %d\n", v->dim );
  for( i = 0 ; i < v->dim ; i++ ) fprintf( fp,"%1.5g", v->e[i] );
  putc( '\n', fp );
}

int main()
{
  FILE *fp;
  SMAT *SM;

  fp = fopen( "genetic.dat", "r" );
  SM = sm_input( fp );
  fclose( fp );

  int m = SM->m;
  int n = SM->n;
  double alpha;

  u_int k;
  printf("choisir k :\n");
  scanf("%u", &k );

  printf("choisir alpha :\n");
  scanf("%lf", &alpha);

  VEC *r = v_new(n);
  VEC *tmp = v_new(n);
  for (int i = 0; i < n; ++i)
  {
    r->e[i] = 1.0/6.0;
    tmp->e[i] = 1.0/6.0;
  }
  SMAT *H = sm_new(m, n);
  int cpt = 0;

  for(int i=0; i<m; ++i)
  {
    if(i != 1){
      H->row[i].nnz = SM->row[i].nnz;
      H->row[i].col = NEW_A(SM->row[i].nnz, u_int);
      H->row[i].val = NEW_A(SM->row[i].nnz, double);
      for(int j=0; j<SM->row[i].nnz; ++j)
      {
        H->row[i].col[j] = SM->row[i].col[j];
        H->row[i].val[j] = SM->row[i].val[j] * 1/SM->row[i].nnz;
      }
    }
  }
  VEC *e = v_new(n);
  for(int i=0; i<n; ++i)
  {
    e->e[i] = 1;
  }

  VEC *a = v_new(SM->m);
  a->dim = SM->m;
  for(int i=0; i<SM->m; ++i)
  {
    if(H->row[i].nnz == 0)
    {
      a->e[i] = (double) i;
    }
    else{
      a->e[i] = 0;
    }
  }
  //On transforme H en S, ici S reste H...
  H->row[1].nnz = SM->m;
  H->row[1].col = NEW_A(SM->m, u_int);
  H->row[1].val = NEW_A(SM->m, double);
  for(u_int i=0; i < SM->m; ++i)
  { 
    H->row[1].col[i] = i;
    H->row[1].val[i] = 1.0/(double)(SM->m);
  }

  v_output(stdout, a);

  sm_output(stdout, H);

  VEC *temp;
  for (int i = 0; i < k; i++) // Multiplication k times
  {
    temp = v_new(SM->m);
    memcpy(temp->e, r->e, sizeof(double)*SM->m);
    memset(r->e, 0, H->m*sizeof(double));
    for (int j = 0; j < H->m; j++)
    {
      for (int m = 0; m < H->row[j].nnz; m++)
      {
        int c = H->row[j].col[m];
        //r->e[c] += H->row[j].val[m]*temp->e[j];
        r->e[c] = alpha * H->row[j].val[m] * temp->e[j] + (alpha*temp->e[j]*a->e[j]+1-alpha)*1.0/n*e->e[j];
      }
    }
    v_free(temp);
  }
  sm_output( stdout, SM );

  sm_output(stdout, H);

  v_output(stdout, r);

  sm_free( SM );
  sm_free( H );

  return 0;
}
