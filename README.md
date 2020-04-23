# Sokoban

Projet : jeu du Sokoban  – L2 informatique, programmation avancée.

Créé par Baptiste et Lilian.

## Installation

Prérequis : SDL1.2
Installation du jeu :
```
git clone https://github.com/LilianHiault/sokoban.git
cd sokoban/game/
make
make clean
```

Pour jouer lancez simplement `./sokoban`.


## Créer un niveau

- Représenter le jeu par un tableau en deux dimensions dans lequel on représentera les différents objets par exemple :
- ' ' pour le sol
- '#' pour les murs
- 'I' pour les points d'intérêts
- 'C' pour les caisses et 'c' si elles sont sur des points d'intérêts (les caisses doivent être en nombre supérieur ou égal au nombre de points d'intérêts pour pouvoir finir le jeu)
- 'P' pour le personnage et 'p' si il est sur un points d'intérêt (il ne doit exister que un seul joueur)

## Objectifs

A faire :
- [x] Chargement et affichage d’un plateau de jeu.
- [x] Positionnement et gestion du personnage.
- [x] Positionnement des points à couvrir.
- [x] Positionnement des caisses et leurs déplacement.

Facultatif :
- [x] Chargement d’un labyrinthe depuis un fichier texte. Le caractère '#' représentera les murs, 'P' le personnage, 'C' une caisse et 'I' un point d’intérêt.
- [ ] Affichage d’un score (qui pourra être calculé en fonction du temps passé, du nombre de mouvements du personnage et du nombre de caisses bien placées).
- [ ] Affichage d’un chronomètre.
- [ ] Gestion de niveaux et de difficultés.
