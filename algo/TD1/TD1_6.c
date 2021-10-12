#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int T[n];
	int i;
	for(i=0; i<n; i++)
		scanf("%d", &T[i]);

	// séquence positive la plus longue

	int max = 0;
	int maxtab = 0;
	int ind_base = 0;
	int j;

	for(j = 0; j < n; j++) {
		if(T[j] > 0)
			max++;
		else {
			if (maxtab < max) {
				maxtab = max;
				ind_base = j - 1;
			}
			max = 0;
		}
	}

	// max somme sous-séquence contifuë
	
	int sum = 0;
	int k;
	for(k=ind_base-maxtab+1; k<=ind_base; k++) {
		sum += T[k];
	}

	int sumTest = sum;
	int maxSum = sum;
	for(k=ind_base-maxtab; k>=0; k--){
		sumTest += T[k];
		if(sumTest > maxSum)
			maxSum = sumTest;
	}
	sumTest = sum;
	for(k=ind_base+1; k<n; k++){
		sumTest += T[k];
		if(sumTest > maxSum)
			maxSum = sumTest;
	}
	printf("%d\r\n", maxSum);
	return 0;
}