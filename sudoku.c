#include <stdio.h>
#include <stdlib.h>

//programme de création de sudoku


//creation de la grille :

void ft_grille(int largeur, int hauteur){

    int i, j, k, l;
    for(i=0; i<4; i++){
        printf("\n");
        
        for(j=0; j<3; j++)
            printf("|---");
        
        l = 0;
        for(k=0; k<3; k++){
            
            for(l; l<1; l++)
                printf("|\n");
            
            printf("|   ");
        }
        printf("|");
       
    }
    printf("\n");
    for(j=0; j<3; j++)
        printf("|---");
        
    printf("|"); 
}

int main(int argc, char *argv){

    argv[1] = 3;
    argv[2] = 4;
    ft_grille(argv[1], argv[2]);
}