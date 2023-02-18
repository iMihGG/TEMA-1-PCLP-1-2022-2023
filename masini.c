#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cerinta_a(char **combustibil, int n, int tip[]) {
    int i;
    for(i = 0; i < 4; i++) {
        tip[i] = 0;
    }
    /*vectorul tip va retine cate masini din fiecare tip
    de motorizare exista*/
    for(i = 0; i < n; i++) {
        if(strcmp(combustibil[i], "benzina") == 0) {
            tip[0]++;
        } else {
            if(strcmp(combustibil[i], "motorina") == 0) {
                tip[1]++;
            } else {
                if(strcmp(combustibil[i], "hibrid") == 0) {
                    tip[2]++;
                } else {
                    if(strcmp(combustibil[i], "electric") == 0) {
                        tip[3]++;
                    }
                }
            }
        }
    }
    /*se incrementeaza vectorul in functie de tipul de motorizare*/
}   

void cerinta_b(char **brand, char **combustibil, double *consum, int *km, 
int n, double c[], char b[][100], double l[], int p[1]) {
    int i;
    int j = -1;
    for(i = 0; i < n; i++) {
        c[i] = 0;
        l[i] = 0;
    }
    /*se initializeaza cu 0 vectorul de consum si vectorul de cost*/
    for(i = 0; i < n; i++) {
        int obs = 1;
        int k = 0;
        while(k <= j) {
            if(strcmp(brand[i], b[k]) == 0) {
                obs = 0;
                break;
            }
            k++;
        }
        /*se verifica in matricea de brand-ri daca a fost gasit 
        anterior acelasi brand de masina*/
        if(obs) {
            strcpy(b[++(j)], brand[i]);
            /*daca nu a fost gasit i se va adauga numele in matrice*/
            double x = (double)((consum[i] * km[i]) / 100);
            c[j] = c[j] + x;
            if(strcmp(combustibil[i], "motorina") == 0) {
                l[j] = l[j] + (double)(x * 9.29);
            } else {
                if((strcmp(combustibil[i], "benzina") == 0) ||
                 (strcmp(combustibil[i], "hibrid") == 0)) {
                    l[j] = l[j] + (double)(x * 8.02);
                }
            }
            /*se calculeaza consumul si costul in functie de motorizare*/
        } else {
            /*se intra in cazul in care a fost gasit acelasi brand*/
            double x = (double)((consum[i] * km[i]) / 100);
            c[k] = c[k] + x;
            if(strcmp(combustibil[i], "motorina") == 0) {
                l[k] = l[k] + (double)(x * 9.29);
            } else {
                if((strcmp(combustibil[i], "benzina") == 0) ||
                 (strcmp(combustibil[i], "hibrid") == 0)) {
                    l[k] = l[k] + (double)(x * 8.02);
                }
            }
        }
    }
    p[0] = j;
    /*se retine numarul de brand-uri distincte gasite*/
}

void cerinta_c(char **numar, int n, int incorecte[]) {
    int i;
    for(i = 0; i < n; i++) {
        incorecte[i] = 0;
        /*se initializeaza vectorul care va retine ce numere 
        de inmatriculare sunt introduse gresit*/
    }
    for(i = 0 ;i < n; i++) {
         if(strlen(numar[i]) > 8 || strlen(numar[i]) < 6) {
            incorecte[i] = 1;
            continue;
        }
        /*se verifica daca lungimea numarului este intre 6 si 8*/
        if(strlen(numar[i]) == 6) {
            if(numar[i][0] < 'A' || numar[i][0] > 'Z') {
                incorecte[i] = 1;
                continue;
            }
            if(numar[i][1] < '0' || numar[i][1] > '9') {
                incorecte[i] = 1;
                continue;
            }
            if(numar[i][2] < '0' || numar[i][2] > '9') {
                incorecte[i] = 1;
                continue;
            }
            if(numar[i][3] < 'A' || numar[i][3] > 'Z') {
                incorecte[i] = 1;
                continue;
            }
            if(numar[i][4] < 'A' || numar[i][4] > 'Z') {
                incorecte[i] = 1;
                continue;
            }
            if(numar[i][5] < 'A' || numar[i][5] > 'Z') {
                incorecte[i] = 1;
                continue;
            }
            /*se trateaza cazul in care lungimea acestuia este 
            de 6 caractere, verificand fiecare caracter*/
        } else {
            if(strlen(numar[i]) == 7) {
                if(numar[i][0] < 'A' || numar[i][0] > 'Z') {
                    incorecte[i] = 1;
                    continue;
                }
                if((numar[i][1] < '0' || numar[i][1] > '9') &&
                 (numar[i][1] < 'A' || numar[i][1] > 'Z')) {
                    incorecte[i] = 1;
                    continue;
                }
                if(numar[i][2] < '0' || numar[i][2] > '9') {
                    incorecte[i] = 1;
                    continue;
                }
                if(numar[i][3] < '0' || numar[i][3] > '9') {
                    incorecte[i] = 1;
                    continue;
                }
                if(numar[i][4] < 'A' || numar[i][4] > 'Z') {
                    incorecte[i] = 1;
                    continue;
                }
                if(numar[i][5] < 'A' || numar[i][5] > 'Z') {
                    incorecte[i] = 1;
                    continue;
                }
                if(numar[i][6] < 'A' || numar[i][6] > 'Z') {
                    incorecte[i] = 1;
                    continue;
                }
                /*se trateaza cazul in care lungimea acestuia este 
                de 7 caractere, verificand fiecare caracter*/
            } else {
                if(strlen(numar[i])== 8) {
                    if(numar[i][0] < 'A' || numar[i][0] > 'Z') {
                        incorecte[i] = 1;
                        continue;
                    }
                    if(numar[i][1] < 'A' || numar[i][1] > 'Z') {
                        incorecte[i] = 1;
                        continue;
                    }
                    if(numar[i][2] < '0' || numar[i][2] > '9') {
                        incorecte[i] = 1;
                        continue;
                    }
                    if(numar[i][3] < '0' || numar[i][3] > '9') {
                        incorecte[i] = 1;
                        continue;
                    }
                    if(numar[i][4] < '0' || numar[i][4] > '9') {
                        incorecte[i] = 1;
                        continue;
                    }
                    if(numar[i][5] < 'A' || numar[i][5] > 'Z') {
                        incorecte[i] = 1;
                        continue;
                    }
                    if(numar[i][6] < 'A' || numar[i][6] > 'Z') {
                        incorecte[i] = 1;
                        continue;
                    }
                    if(numar[i][7] < 'A' || numar[i][7] > 'Z') {
                        incorecte[i] = 1;
                        continue;
                    }
                }
                /*se trateaza cazul in care lungimea acestuia este 
                de 8 caractere, verificand fiecare caracter*/
            }
        }
    }
}

int main() {
    char **brand, **numar, **combustibil;
    int *km;
    double *consum;
    int n, i = 0;
    scanf("%d", &n);
    brand = malloc(n * sizeof(char *));
    for(i = 0; i < n; i++) {
        brand[i] = malloc(21 * sizeof(char));
    }
    combustibil = malloc(n * sizeof(char *));
    for(i = 0; i < n; i++) {
        combustibil[i] = malloc(21 * sizeof(char));
    }
    numar = malloc(n * sizeof(char *));
    for(i = 0; i < n; i++) {
        numar[i] = malloc(21 * sizeof(char));
    }
    km = malloc(n * sizeof(int));
    consum = malloc(n * sizeof(double));
    /*se aloca dinamic vectorii si matricile ce retin
    informatii despre masini*/
    for(i = 0; i < n; i++) {
        scanf("%s", brand[i]);
        getchar();
        scanf("%s", numar[i]);
        getchar();
        scanf("%s", combustibil[i]);
        getchar();
        scanf("%lf", &consum[i]);
        scanf("%d", &km[i]);
    }
    char task;
    getchar();
    scanf("%c", &task);
    getchar();
    /*se citeste caracterul aferent task-ului dorit*/
    if(task == 'a') {
        int tip[4];
        cerinta_a(combustibil , n, tip);
        printf("benzina - %d", tip[0]);
        printf("\n");
        printf("motorina - %d", tip[1]);
        printf("\n");
        printf("hibrid - %d", tip[2]);
        printf("\n");
        printf("electric - %d", tip[3]);
        printf("\n");
    } else {
            if(task == 'b') {
                char b[100][100];
                double c[100], l[100];
                int p[1];
                cerinta_b(brand, combustibil, consum, km, n,
                 c, b, l, p);
                for(i = 0; i <= p[0]; i++) {
                    printf("%s a consumat %.2lf - %.2lf lei", 
                    b[i], c[i], l[i]);
                    printf("\n");
                }
            } else {
                int incorecte[101];
                int inc = 0;
                cerinta_c(numar, n ,incorecte);
                for(i = 0; i < n; i++) {
                    if(incorecte[i] == 1) {
                        inc++;
                        printf("%s cu numarul %s: numar invalid", 
                        brand[i] ,numar[i]);
                        printf("\n");
                    }
                }
                if(inc == 0) {
                    printf("Numere corecte!");
                    printf("\n");
                    /*se verifica daca toate numerele sunt 
                    introduse corect*/
                }
            }
        }
    free(brand);
    free(combustibil);
    free(numar);
    free(km);
    free(consum);
    /*este eliberata memoria alocata*/

    return 0;

}