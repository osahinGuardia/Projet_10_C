#include <stdio.h>
#include <stdlib.h>

//programme de création de sudoku


//creation de la grille :

void ft_grille(int largeur, int hauteur){

    int i, j, k, l;
    char letter = 'A';
    char number = '1';
    for(j=0; j<largeur; j++)
            printf("  %c ", letter++);
        
        
    for(i=0; i<hauteur; i++){
        printf("\n");
        
        
        for(j=0; j<largeur; j++)
            printf("|---");
        
        l = 0;
        for(k=0; k<largeur; k++){
            
            for(l; l<1; l++)
                printf("|\n");
            
            printf("|   ");
        }
        printf("| %c", number++);
       
    }
    printf("\n");
    for(j=0; j<largeur; j++)
        printf("|---");
        
    printf("|"); 
}

int main(int argc, char *argv){

    argv[1] = 4;
    argv[2] = 4;
    ft_grille(argv[1], argv[2]);
}