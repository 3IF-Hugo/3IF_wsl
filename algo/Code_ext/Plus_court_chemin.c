# PLUS COURTS CHEMINS ENTRE TOUTES LES PAIRES DE SOMMETS DANS UN GRAPHE ORIENTÉ ET PONDÉRÉ - FLOYD-WARSHALL
# Dans un premier temps, nous initialisons la matrice de solution, identique à celle du graphe d'entrée.
# Ensuite, nous mettons à jour la matrice de solution en considérant tous les sommets comme un sommet intermédiaire.
# L'idée est de sélectionner un à un tous les sommets et de mettre à jour tous les chemins les plus courts incluant le 
# sommet sélectionné en tant que sommet intermédiaire du chemin le plus court.
# Lorsque nous choisissons le nombre de sommets k comme sommet intermédiaire, nous avons déjà considéré les sommets {0, 1, 2, .. k-1} 
# comme des sommets intermédiaires.
# Pour chaque paire (i, j) des sommets source et destination, respectivement, il existe deux cas possibles.

# k n'est pas un sommet intermédiaire sur le chemin le plus court de i à j. Nous gardons la valeur de dist[i][j] telle qu'elle est.
# k est un sommet intermédiaire dans le plus court chemin de i à j. Nous mettre à jour la valeur de dist[i][j] par dist[i][k]+dist[k][j] 
# si dist[i][j] > dist[i][k] + dist[k][j].


import math
 
class Graphe():
 
    def __init__(self, noeuds):
        self.matriceAdj = noeuds.copy()
 
    def Afficher(self, res):
        print("les chemins les plus courts allant de  est : ")
        n = len(res)
        for i in range(n):
            print("les chemins les plus courts allant de ", i+1, " est : ")
            for j in range(n):
                print(res[i][j], end=" ")
            print("")
 
    def FloydWarshal(self):
        res = self.matriceAdj.copy()
        n = len(self.matriceAdj)
 
        for k in range(n):
            for i in range(n):
                for j in range(n):
                    res[i][j] = min(res[i][j], res[i][k]+res[k][j])
 
        self.Afficher(res)
 
 
# Test
matriceAdj = [[0, 3, math.inf, 7],
              [8, 0, 2, math.inf],
              [5, math.inf, 0, 1],
              [2, math.inf, math.inf, 0],
              ]
g = Graphe(matriceAdj)
g.FloydWarshal()