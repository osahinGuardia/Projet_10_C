#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "module.h"



struct Product{

    char title[100];
    double price;
    int quantity;
    double quantityPrice;
    double ttc;

};

typedef struct Product Product;

typedef enum {
    XS = 130, S = 150, M = 170, L = 180, XL = 200, XXL
} Taille;

typedef enum {
    VRAI = 1, FAUX = 0 //,QUANTIQUE = 2
} Booleen;

int main(){
    
    
    // Product newPresta;
    // fgets("%s", newPresta.title, stdin);
    // scanf("%s", newPresta.quantity);
    // scanf("%f", newPresta.price);
    
    // newPresta.quantityPrice = newPresta.price * newPresta.quantity;

    // Product products[100];
    







    // Product newPresta2
    // Product *pointeurPresta = &newPresta2

    // pointeurPresta->price = 20
    // //c'est pareil que : (*pointeurPresta).price = 20, mais en plus récent

    bonchouranh(1, 2)

    Taille alexandre = 200;
    if (alexandre == XXL){
        printf("T'as repris du dessert mon salal");
    }

    system("pause");
    return 0;


}