Top 10 et création de graphe à partir d'un fichier de logs d'un serveur
Mode d'emploi

----------------------------------------------------------------------------------

Structure des dossiers :
- Le code source est dans le dossier bin. Ce dernier contient les .cpp, .h et un makfile
- Le dossier Tests contient différents tests pour vérifier le bon fonctionnement de notre application
- Le dossier tmp contient des fichiers de logs servant aux tests

----------------------------------------------------------------------------------

Utilisation de l'application :
L'exécutable est nommé analog. L'application prend obligatoirement un fichier de logs en paramètre.
La syntaxe minimale pour utiliser l'application est donc, quand on se trouve dans le dossier bin :
./analog ../tmp/MesLogs.log
L'application fait alors un top 10 des targets les plus accédées.

Il y a trois options supplémentaires possibles :
_ -e = permet de ne pas prendre en compte les fichiers image, css et javascript
_ -t h = permet de prendre en compte seulement les targets accédées entre h et h+1. h doit être un entier entre 0 et 23 et toujours spécifié après -t
_ -g monGraphe.dot : permet de créer ou modifier un fichier .dot qui permet ensuite de générer un graphe correspondant aux logs mis en paramètres. Le fichier de sortie .dot doit obligatoirement être spécifié

Les options peuvent êtres utilisées ensemble (1, 2 ou 3 options).
Le fichier de logs doit toujours être spécifié en dernier dans les arguments.
L'option -g doit toujours être la dernière des options spécifiées.
Voici un exemple de syntaxe correcte :
./analog -t 21 -e -g monGraphe.dot ../tmp/MesLogs.log
La syntaxe reste correcte si '-t 21' et '-e' sont interchangés.
