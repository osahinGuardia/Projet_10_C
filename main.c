#include <stdio.h>

int main() {
    
    int t, a, b, c;

    printf("Choisissez le nombre de commencement : ");
    scanf("%d", &a);

    b = a;

    printf("Choisissez la valeur à ne pas dépasser : ");
    scanf("%d", &t);

    printf("la suite commence a partir de %d:\n", a);

    printf("%d, %d", a, b);

    c = a + b;
    while (c <= t) {
        printf(", %d", c);
        a = b;
        b = c;
        c = a + b;
    }

    printf("\nLa valeur max atteinte est : %d\n", b);

    if (t % 2 == 0) {
        printf("La valeur max est paire.\n");
    } else {
        printf("La valeur max est impaire.\n");
    }

    if (t % 3 == 0) {
        printf("La valeur max est un multiple de 3.\n");
    } else {
        printf("La valeur max n'est pas un multiple de 3.\n");
    }

    return 0;
}
