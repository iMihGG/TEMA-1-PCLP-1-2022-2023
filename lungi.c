#include <stdio.h>
#include <string.h>
#include <math.h>

void change(char v[], int rea[], int ima[], int n ) {
    int i = -1, k;
    for(k = 0; k <= n / 2 - 1; k++) {
        rea[++i] = v[k] - 48;
    }
    i = -1;
    for(k = n / 2; k <= n - 1; k++) {
        ima[++i] = v[k] - 48;
    } 
}
/*se transforma numarul primit sub forma de sir de caractere
in doi vectori de tip int, aferenti partii reale, respectiv partii
imaginare.*/

void afisare(int a[], int n) {
    int i;
    for(i = 0; i <= n - 1; i++) {
        printf("%d", a[i]);
    }
}

void adunare(int a[], int b[], int n) {
    int i;
    for(i = n - 1; i > 1; i--) {
        int x = a[i];
        a[i] = (a[i] + b[i]) % 10;
        a[i - 1] = a[i - 1] + (x + b[i]) / 10;
    }
    a[1] = (a[1] + b[1]) % 10;
}
/*se aduna partile reale sau partile imaginare
a doua numere, bit cu bit, incepand de la sfarsitul vectorului.*/

void scadere(int a[], int b[], int n) {
    int i, minus = 0, plus = 0, semn = 0;
    for(i = 1; i < n; i++) {
        if(a[i] < b[i]) {
            minus++;
            break;
        } else {
            if(a[i] > b[i]) {
                plus++;
                break;
            }
        }
    }
    /*se verifica daca scaderea se realizeaza intre un numar mare si unul mic*/
    if(minus) {
        int aux;
        for(i = 1; i < n; i++) {
            aux = a[i];
            a[i] = b[i];
            b[i] = aux;
       }
       semn = 1;
       /*se interschimba numerele si se schimba bit-ul de semn in cazul 
       anterior mentionat*/
    } else {
        semn = 0;
    }
    for(i = n - 1; i > 0; i--) {
        if(a[i] - b[i] < 0) {
            a[i] = a[i] - b[i] + 10;
            int j;
            for(j = i - 1; j >= 1; j--) {
                if(a[j] > 0) {
                    a[j]--;
                    break;
                } else {
                    a[j] = 9;
                }
            }
        }
        else {
            a[i] = a[i] - b[i];
        }
    }
    a[0] = semn;
    /*se realizeaza scaderea bit cu bit de la sfarsit
    avand grija sa se realizeze corect imprumuturile*/
}

int main() {
    int rea[1001] = {0}, ima[1001] = {0};
    char a[1001], b[1001], semn;
    int n, i;
    scanf("%d", &n);
    n--;
    scanf("%s", a);
    getchar();
    change(a, rea, ima, n);
    scanf("%c", &semn);
    getchar();
    while(semn != '0') {
        int reb[1001] = {0}, imb[1001] = {0};
        scanf("%s", b);
        getchar();
        change(b, reb, imb, n);
        if(semn == '-') {
            if(reb[0] == 0) {
                reb[0] = 1;
            } else {
                reb[0] = 0;
            }
            if(imb[0] == 0) {
                imb[0] = 1;
            } else {
                imb[0] = 0;
            }
        }
        /*se schimba bit-urile de semn pentru al doilea numar, in cazul in care
        semnul citit este minus*/
        if((rea[0] == 0 && reb[0] == 0) || (rea[0] == 1 && reb[0] == 1)) {
            adunare(rea, reb, n / 2);
            afisare(rea, n / 2);
            /*se apeleaza functia de adunare in cazul in care se aduna doua 
            numere pozitive sau negative*/
        } else {
            if(rea[0] == 0 && reb[0] == 1) {
                scadere(rea, reb, n / 2);
                afisare(rea, n / 2);
                /*se apeleaza functia de scadere in cazul in care se scad
                doua numere pozitive*/
            } else {
                if(rea[0] == 1 && reb[0] == 0) {
                    scadere(reb, rea, n / 2);
                    afisare(reb, n / 2);
                    /*se apeleaza functia de scadere in cazul in care se aduna
                    un numar negativ si unul pozitiv, caz in care se schimba 
                    ordinea pentru a se realiza scaderea in locul adunarii*/
                    for(i = 0; i < n / 2; i++) {
                        rea[i] = reb[i];
                    }
                    /*se copiaza vectorul apelat primul peste cel de-al doilea
                    pentru a se lucra in continuare cu acesta in cazul in care 
                    ordinea celor doi s-a schimbat(cazul anterior)*/
                } 
            }
        }
        if((ima[0] == 0 && imb[0] == 0) || (ima[0] == 1 && imb[0] == 1)) {
            adunare(ima, imb, n / 2);
            afisare(ima, n / 2);
        } else {
            if(ima[0] == 0 && imb[0] == 1) {
                scadere(ima, imb, n / 2);
                afisare(ima, n / 2);
            } else {
                if(ima[0] == 1 && imb[0] == 0) {
                    scadere(imb, ima, n / 2);
                    afisare(imb, n / 2);
                    for(i = 0; i < n / 2; i++) {
                        ima[i] = imb[i];
                    }
                } 
            }
        }
        /*aceeasi logica ca la partea reala*/
        printf("\n");
        scanf("%c", &semn);
        getchar();
        /*se citeste in continuare semnul pana la intalnirea lui 0*/
    }
    
    return 0;

}