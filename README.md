
# Sudoku disktop game for children

This game was developed with the purpose of being used as a project for the course 'Data structure' with ENSIAS -college of engineering- in Morocco.<br />
The project was done in 02 styles; <b>style01: console - style02: GUI.</b><br />
Developed by: Amina Baniabaz & Imane Elharchaoui <br />
Year: 2018

# First style of the game: 'console'
## About the source code:
This program has been realized in C language, with the use of SDL libraries to program the game interfaces.<br />
In the source code "user.h" we have defined a user structure that contains the data of each player (name, password, score, and level).<br />

<p align="center">
  <img src="https://github.com/AmiBZ/sudoku/blob/master/img/consol.PNG">
</p>


<b>.int est_solution(int A[4][4])</b><br />
A function that tests if the matrix given in the parameter fulfills the Sudoku rules.<br />
<b>.int repeterligne(int A[4][4],int l)</b><br />
A function that checks if there is a repetition of the same value in the same line.<br />
<b>.int repetercolonne(int A[4][4],int c)</b><br />
A function that checks if there is a repetition of the same value in the same column.<br />
<b>.void copie_bloc(int A[4][4],int b,int T[4])</b><br />
Fonction qui copie les éléments du bloc d'indice "b"  de la matrice A dans le tableau T.<br />
<b>.int repeterbloc(int A[4][4],int b)</b><br />
Fonction qui vérifie s'il y a une répétition de la même valeur dans un même bloc.<br />
<b>.void selectionNiveau(SDL_Surface* ecran)</b><br />
Fonction qui renvoie une interface qui demande de l’utilisateur de choisir un niveau de jeu (facile, moyen, difficile).<br />
<b>void afficherLesGrilles(SDL_Surface *ecran,int difficulte)</b><br />
Fonction qui renvoie la grille choisie selon la difficulté choisie.<br />


## Rules of the game:
The rules of sudoku are very simple. The sudoku contains 4 rows and 4 columns, so 16 cells in total.
The goal of the game is to fill in these cells with one of the four figures (rectangle, square, circle, or triangle), always making sure that the same figure appears only once per column, once per row, and once per square of four cells.

# :camera: Interfaces

<p align="center">
  <img src="https://github.com/AmiBZ/sudoku/blob/master/img/GUI.png">
</p>

# :wrench: tools
![ref](https://github.com/AmiBZ/sudoku/blob/master/img/tools.PNG)
