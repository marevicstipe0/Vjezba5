#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Cvor {
    int broj;
    struct Cvor* sljedeci;
} Cvor;

void dodaj(Cvor** lista, int broj) {
    Cvor* novi = (Cvor*)malloc(sizeof(Cvor));
    novi->broj = broj;
    novi->sljedeci = NULL;

    if (*lista == NULL) {
        *lista = novi;
    }
    else {
        Cvor* temp = *lista;

        while (temp->sljedeci != NULL) {
            temp = temp->sljedeci;
        }

        temp->sljedeci = novi;
    }
}

void ispisi(Cvor* lista) {
    while (lista != NULL) {
        printf("%d ", lista->broj);
        lista = lista->sljedeci;
    }

    printf("\n");
}

Cvor* unija(Cvor* L1, Cvor* L2) {
    Cvor* L3 = NULL;

    while (L1 != NULL && L2 != NULL) {
        if (L1->broj < L2->broj) {
            dodaj(&L3, L1->broj);
            L1 = L1->sljedeci;
        }
        else if (L1->broj > L2->broj) {
            dodaj(&L3, L2->broj);
            L2 = L2->sljedeci;
        }
        else {
            dodaj(&L3, L1->broj);
            L1 = L1->sljedeci;
            L2 = L2->sljedeci;
        }
    }

    while (L1 != NULL) {
        dodaj(&L3, L1->broj);
        L1 = L1->sljedeci;
    }

    while (L2 != NULL) {
        dodaj(&L3, L2->broj);
        L2 = L2->sljedeci;
    }

    return L3;
}

Cvor* presjek(Cvor* L1, Cvor* L2) {
    Cvor* L3 = NULL;

    while (L1 != NULL && L2 != NULL) {
        if (L1->broj < L2->broj) {
            L1 = L1->sljedeci;
        }
        else if (L1->broj > L2->broj) {
            L2 = L2->sljedeci;
        }
        else {
            dodaj(&L3, L1->broj);
            L1 = L1->sljedeci;
            L2 = L2->sljedeci;
        }
    }

    return L3;
}

int main() {
    Cvor* L1 = NULL;
    Cvor* L2 = NULL;
    Cvor* L3 = NULL;
    Cvor* L4 = NULL;

    int n, broj, i;

    printf("Unesi broj elemenata prve liste: ");
    scanf("%d", &n);

    printf("Unesi sortirane elemente prve liste:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &broj);
        dodaj(&L1, broj);
    }

    printf("Unesi broj elemenata druge liste: ");
    scanf("%d", &n);

    printf("Unesi sortirane elemente druge liste:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &broj);
        dodaj(&L2, broj);
    }

    printf("\nPrva lista: ");
    ispisi(L1);

    printf("Druga lista: ");
    ispisi(L2);

    L3 = unija(L1, L2);
    L4 = presjek(L1, L2);

    printf("\nUnija L1 U L2: ");
    ispisi(L3);

    printf("Presjek L1 n L2: ");
    ispisi(L4);

    return 0;
}