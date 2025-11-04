#!/bin/sh 

## Cree un repertoire temporel ".tmp" et copie tous les repertoires "dir" dedans
mkdir .tmp && cp -r ./dir* .tmp/

## Affiche un banner
echo "%%%%%%%%%%%%%%%%%%%%%%%%"
echo "%     Shell Linux      %"
echo "%%%%%%%%%%%%%%%%%%%%%%%%"

echo "Current PATH :"               ## Affiche un message
pwd                                 ## Affiche le chemin actuel du repertoire
echo "Creating subtree .."
mkdir -p dir31/dir311 dir32/dir321  ## Cree des reperoires imbriques (nested)
mkdir dir32/dir322                  ## Cree un repertoire "dir322" dans "dir32"

echo "Folder contents : "
ls -l                               ## Affiche une liste detaillee des repertoires/fichiers
echo "Folder tree : "
tree                                ## Affiche la structure du repertoire actuel
tree ..                             ## Affiche la structure du repertoire parent
           
echo "Cleaning ..."
rm -rv dir* > clean.log             ## Supprime tous les repertoires qui commence
                                    ## avec dir et enregitre dans clean.log

echo "END!!"
cp -r .tmp/dir* .                   ## Restore les repertoires depuis .tmp 
                                    ## et recopie les repertoires sauvegardes
