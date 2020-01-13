# Sokoban

Projet : jeu du Sokoban  – L2 informatique, programmation avancée

## Objectifs

A faire :
- [x] Chargement et affichage d’un plateau de jeu.
- [x] Positionnement et gestion du personnage.
- [x] Positionnement des points à couvrir.
- [x] Positionnement des caisses et leurs déplacement.

Facultatif :
- [ ] Chargement d’un labyrinthe depuis un fichier texte, à la manière de la description qui est faite dans le TP5. Où le caractère # représentera les murs, le caractère P représentera le personnage, le caractère C représentera une caisse et le caractère I représentera un point d’intérêt.
- [ ] Affichage d’un score (qui pourra être calculé en fonction du temps passé, du nombre de mouvements du personnage et du nombre de caisses bien placées).
- [ ] Affichage d’un chronomètre.
- [ ] Gestion de niveaux et de difficultés.

## Idées

- Représenter le jeu par un tableau en deux dimensions dans lequel on représentera les différents objets par exemple :
  - ' ' pour le sol
  - '#' pour les murs
  - 'I' pour les points d'intérêts
  - 'C' pour les caisses et 'c' si elles sont sur des points d'intérêts
  - 'P' pour le personnage et 'p' si il est sur un points d'intérêt
