#include <stdio.h>
#include <stdlib.h>

//programme de création de sudoku


//creation de la grille :

void ft_grille(largeur, hauteur){

    int i = 0, j = 0;
    for(i=0; i<largeur; i++){
        printf("\n");
        for(j=0; j<hauteur; j++){

            print("*");
        }
    }
}

int main(int argc, char *argv){

    ft_grille(argv[1], argv[2]);
}
