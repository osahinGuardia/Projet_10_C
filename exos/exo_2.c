// Rentre trois valeur : Titre, Prix unitaire et Quantité
// Ensuite il demande si on veut continuer (boolean : TRUE ou FALSE)
// Afficher par lignes formatées :
// Titre, prix unitaire, quantité, prix * quantité, prix TTC = (prix * q * 24) + prix)
// Une ligne total

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define TVA 1.24
#define MAX_PRODUCTS 100
#define MAX_TITLE_LENGTH 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    float price;
    int quantity;
} Product;

// Affiche les informations d'un produit
void print_product(Product* product) {
    printf("Titre : %s\n", product->title);
    printf("Prix : %.2f\n", product->price);
    printf("Quantite : %d\n", product->quantity);
}

// Affiche toutes les informations des produits
void print_products(Product* products[], int productCount) {
    printf("Liste des produits :\n");
    for (int i = 0; i < productCount; i++) {
        printf("Produit %d :\n", i+1);
        print_product(products[i]);
        printf("\n");
    }
}

// Calcule le montant total HT d'un produit
float calculate_total(Product* product) {
    return product->price * product->quantity;
}

// Calcule le montant total TTC d'un produit
float calculate_total_ttc(Product* product) {
    return calculate_total(product) * TVA;
}

// Ajoute un produit à la liste des produits et met à jour le montant total TTC
void add_product(Product* product, Product* products[], int* product_count, float* total_ttc) {
    if (*product_count < MAX_PRODUCTS) {
        products[*product_count] = product;
        *total_ttc += calculate_total_ttc(product);
        (*product_count)++;
    }
}

// Vérifie si une chaîne de caractères représente un nombre
bool is_number(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i]) && str[i] != '.') {
            return false;
        }
    }
    return true;
}

// Vérifie si une chaîne de caractères représente un prix valide
bool is_valid_price(char* str) {
    float price = atof(str);
    return is_number(str) && price > 0;
}

// Vérifie si une chaîne de caractères représente une quantité valide
bool is_valid_quantity(char* str) {
    int quantity = atoi(str);
    return is_number(str) && quantity > 0;
}

// Vide le tampon d'entrée standard
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Demande à l'utilisateur de répondre "O" ou "N" à une question et retourne la réponse
bool get_yes_no_input(char* message) {
    char input[2];
    do {
        printf("%s (O/N) : ", message);
        fgets(input, sizeof(input), stdin);
        clear_input_buffer();
    } while (tolower(input[0]) != 'o' && tolower(input[0]) != 'n');
    return tolower(input[0]) == 'o';
}

int main() {
    Product* products[MAX_PRODUCTS];
    int productCount = 0;
    float totalTTC = 0;

    do {
        char title[MAX_TITLE_LENGTH];
        char priceStr[20];
        char quantityStr[10];
        float price;
        int quantity;

        printf("Entrez le titre: ");
        fgets(title, MAX_TITLE_LENGTH, stdin);
        // Supprimer le retour à la ligne de fgets
        title[strcspn(title, "\n")] = '\0';

        do {
            printf("Entrez le prix: ");
            fgets(priceStr, 20, stdin);
            priceStr[strcspn(priceStr, "\n")] = '\0';
        } while (!is_valid_price(priceStr));

        do {
            printf("Entrez la quantite: ");
            fgets(quantityStr, 10, stdin);
            quantityStr[strcspn(quantityStr, "\n")] = '\0';
        } while (!is_valid_quantity(quantityStr));

        price = atof(priceStr);
        quantity = atoi(quantityStr);

        Product* product = malloc(sizeof(Product));
        strncpy(product->title, title, MAX_TITLE_LENGTH);
        product->price = price;
        product->quantity = quantity;

        add_product(product, products, &productCount, &totalTTC);
    } while (get_yes_no_input("Voulez-vous ajouter un autre produit ?"));

    print_products(products, productCount);
    printf("Total TTC: %.2f\n", totalTTC);

    for (int i = 0; i < productCount; i++) {
        free(products[i]);
    }

    return 0;
}