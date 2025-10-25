#!/bin/sh
echo "%%%%%%%%%%%%%%%%%%%%%%%%"
echo "%  Regular Expression  %"
echo "%%%%%%%%%%%%%%%%%%%%%%%%"
echo "========================"
ip a    ## Affiche les informations detaillees des interfaces reseau
          ## (noms, etats, adresses IP, ...)

echo "========================"
ip a | grep -Eo 'inet ([0-9]*\.){3}[0-9]*'
## Explication : Extrait toutes les lignes contenant 'inet' suivie d'une adresse IP
## Explication : -E active les expressions regulieres etendues, -o affiche uniquement la partie correspondante

echo "========================"
ip a | grep -Eo 'inet ([0-9]*\.){3}[0-9]*' | grep -Eo '([0-9]*\.){3}[0-9]*'
## Explication : Premiere commande extrait 'inet X.X.X.X', deuxieme commande extrait seulement l'adresse IP
## Explication : Le deuxieme grep isole uniquement la partie adresse IP sans le mot 'inet'
## Explication : Resultat : affiche toutes les adresses IP des interfaces reseau

echo "========================"
ip a | grep -Eo 'inet ([0-9]*\.){3}[0-9]*' | grep -Eo '([0-9]*\.){3}[0-9]*' | grep -v '127.0.0.1'
## Explication : Meme traitement que precedent mais exclut l'adresse de loopback
## Explication : grep -v inverse la selection pour exclure l'adresse 127.0.0.1
## Explication : Resultat : affiche seulement les adresses IP non-loopback

echo "========================"
ip a | sed -En 's/127.0.0.1//;s/.*inet (([0-9]*\.){3}[0-9]*)\.*/\1/p'
## Explication : sed -E active les regex etendues, -n supprime l'affichage par defaut
## Explication : Premiere substitution supprime 127.0.0.1, deuxieme capture l'adresse IP apres 'inet'
## Explication : /\1/p affiche seulement le groupe capture (l'adresse IP) et p imprime les lignes modifiees
