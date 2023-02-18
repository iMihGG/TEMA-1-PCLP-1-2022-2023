#include <stdio.h>

void prisoners(int sir[501], int p) {
    int i, nrp = 0;
    for(i = 1; i <= p; i++) {
        /*se parcurge vectorul de prizonieri*/
        int nrc = 0;
        int j = i;
        while(sir[j] != i && nrc < p / 2) {
            nrc++;
            j = sir[j];
        }
        /*se verifica daca se poate forma un ciclu si
        se contorizeaza lungimea sa*/
        if(sir[j] == i && nrc < p / 2) {
            nrp++;
        }
        /*in cazul in care exista un ciclu cu lungime cel
        mult n / 2 - 1 se contorizeaza*/
    }
    if(nrp == p) {
        printf("Da");
        printf("\n");
    } else {
        printf("Nu");
        printf("\n");
    }
    /*se verifica daca numarul de cicluri cu lungime cel 
    mult n / 2 - 1 este egal cu numarul de prizonieri*/
}

void cycles(int sir[501], int p) {
    int verific[501] = {0}, i;
    /*vector in care se va marca daca s-a trecut printr-o cutie*/
    for(i = 1; i <= p; i++) {
        /*se parcurge vectorul de prizonieri*/
        int a[501] = {0};
        /*vectorul in care se retine solutia*/
        int k = 0;
        a[++k] = i;
        int j = i;
        while(verific[j] == 0 && sir[j] != i) {
            a[++k] = sir[j];
            verific[j]++;
            j = sir[j];
        }
        /*se formeaza ciclul si se verifica validitatea sa*/
        if(sir[j] == i) {
            verific[j]++;
            int x = 1;
            for(x = 1; x < k; x++) {
                printf("%d ", a[x]);
            }
            printf("%d", a[x]);
            printf("\n");
            }
            /*in cazul in care s-a ajuns la cutia dorita se va
            afisa solutia*/
    }
}

int main() {
    int n, sir[501];
    int i;
    scanf("%d", &n);
    for(i = 1; i <= n; i++) {
        scanf("%d", &sir[i]);
    }
    prisoners(sir, n);
    cycles(sir, n);
    
    return 0; 
    
}