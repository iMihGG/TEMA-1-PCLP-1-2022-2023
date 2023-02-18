#include <stdio.h>
#include <string.h>

void cod_A(char text[501], char cheie[51]) {
    int i, j, k = 0, l = 0, m = 0;
    char a[501][501];
    for(i = 0; i < strlen(text); i++) {
        for(j = 0; j < strlen(cheie); j++) {
            a[i][j] = ' ';
        }
    }
    /*se initilizeaza matricea cu spatii pentru a fi completata
    in caz de nevoie*/
    i = 0, j = -1;
    while(k < strlen(text)) {
        if(j == strlen(cheie) - 1) {
            j = -1;
            i++;
        }
        a[i][++j] = text[k];
        k++;
    }
    /*se introduce in matrice textul, pe linii*/
    char cheie2[51];
    strcpy(cheie2, cheie);
    /*se face o copie a cheii de codificare*/
    int indici[51];
    for(k = 0; k < strlen(cheie2); k++) {
        indici[k] = k;
    }
    /*se initializeaza vectorul de indici cu valoarea indicelui
    pentru a se realiza sortarea secventiala*/
    for(k = 0; k < strlen(cheie2) - 1; k++) {
        for(j = k + 1; j < strlen(cheie2); j++) {
            if(cheie2[k] > cheie2[j]) {
                char aux;
                aux = cheie2[k];
                cheie2[k] = cheie2[j];
                cheie2[j] = aux;
                int man;
                man = indici[k];
                indici[k] = indici[j];
                indici[j] = man;
            }
        }
    }
    /*se realizeaza simultan sortarea crescatoare a copiei cheii
    si sortarea indicilor ce semnifica caracterele acesteia*/
    for(k = 0; k < strlen(cheie2); k++) {
        for(l = 0; l <= i; l++) {
            text[m] = a[l][indici[k]];
            m++;
        }
    }
    text[m] = '\0';
    /*se suprascrie textul codificat in urma sortarii secventiale
    a cheii*/
}

void decod_A(char text[501], char cheie[51]) {
    int i, j, k = 0, linii, m = 0;
    char a[501][501];
    if(strlen(text) % strlen(cheie) == 0) {
        linii = strlen(text) / strlen(cheie);
    } else {
        linii = strlen(text) / strlen(cheie) + 1;
    }
    /*se stabileste numarul de linii in functie de lungimea
    cheii si lungimea textului*/
    for(i = 0; i < linii; i++) {
        for(j = 0; j < strlen(cheie); j++) {
            a[i][j] = ' ';
        }
    }
    /*se initilizeaza matricea cu spatii pentru a fi completata
    in caz de nevoie*/
    j = 0, i = -1;
    while(k < strlen(text)) {
        if(i == linii - 1) {
            i = -1;
            j++;
        } 
        a[++i][j] = text[k];
        k++;
    }
    /*se introduce in matrice textul, pe coloane*/
    char cheie2[51];
    strcpy(cheie2, cheie);
    /*se realizeaza a copie a cheii de decodificare*/
    int indici[51];
    for(k = 0; k < strlen(cheie2); k++) {
        indici[k] = k;
    }
    /*se initializeaza vectorul de indici cu valoarea indicelui
    pentru a se realiza sortarea secventiala*/
    for(k = 0; k < strlen(cheie2) - 1; k++) {
        for(i = k + 1; i < strlen(cheie2); i++) {
            if(cheie2[k] > cheie2[i]) {
                char aux;
                aux = cheie2[k];
                cheie2[k] = cheie2[i];
                cheie2[i] = aux;
                int man;
                man = indici[k];
                indici[k] = indici[i];
                indici[i] = man;
            }
        }
    }
    /*se realizeaza simultan sortarea crescatoare a copiei cheii
    si sortarea indicilor ce semnifica caracterele acesteia*/
    for(i = 0; i < linii; i++) {
        for(k = 0; k < strlen(cheie); k++) {
            int x = 0;
            while (indici[x] != k) {
                x++;
            }
            text[m] = a[i][x];
            m++;
        }
    }
    text[m] = '\0';
}
/*se parcurg in ordine crescatoare indicii cheii
nesortate si se verifica ce coloana din matrice contine
primul caracter de pe linia i ce ar trebui sa fie suprascris
, folosindu-se vectorul de indici sortati crescator dupa cheie*/

void cod_B(char text[501], int ch) {
    int copie = ch, i;
    while(copie) {
        char aux = text[strlen(text) - 1];
        for(i = strlen(text) - 1; i > 0; i--) {
            text[i] = text[i - 1];
        }
        text[0] = aux;
        copie--;
    }
    /*se realizeaza deplasarea la dreapta a textului cu
    ch caractere*/
    for(i = 0; i < ch; i++) {
        if(text[i] != ' ') {
            if((text[i] <= 'z' && text[i] >= 'a')) {
                if(text[i] + ch <= 'z' && text[i] + ch >= 'a') {
                    text[i] = text[i] + ch;
                } else {
                    text[i] = text[i] - 32 - 26 + ch;
                }
            } else {
                if((text[i] <= 'Z' && text[i] >= 'A')) {
                    if(text[i] + ch <= 'Z' && text[i] + ch >= 'A') {
                        text[i] = text[i] + ch;
                    } else {
                        text[i] = text[i] + 32 - 26 + ch;
                    }
                }
            }
        }
    }
    /*se modifica cele ch caractere mutate, considerandu-se cazuri
    speciale pentru trecerile de la litere mari la litere mici si vice-versa*/
}

void decod_B(char text[501], int ch) {
    int copie = ch, i;
    while(copie) {
        char aux = text[0];
        for(i = 0; i < strlen(text) - 1; i++) {
            text[i] = text[i + 1];
        }
        text[strlen(text) - 1] = aux;
        copie--;
    }
    /*se realizeaza deplasarea la stanga a textului cu
    ch caractere*/
    for(i = strlen(text) - 1; i > strlen(text) - ch - 1; i--) {
        if(text[i] != ' ') {
            if((text[i] <= 'z' && text[i] >= 'a')) {
                if(text[i] - ch <= 'z' && text[i] - ch >= 'a') {
                    text[i] = text[i] - ch;
                } else {
                    text[i] = text[i] - 32 + 26 - ch;
                }
            } else {
                if((text[i] <= 'Z' && text[i] >= 'A')) {
                    if(text[i] - ch <= 'Z' && text[i] - ch >= 'A') {
                        text[i] = text[i] - ch;
                    } else {
                        text[i] = text[i] + 32 + 26 - ch;
                    }
                }
            }
        }
    }
    /*se modifica cele ch caractere mutate, considerandu-se cazuri
    speciale pentru trecerile de la litere mari la litere mici si vice-versa*/
}

int main() {
    char cheie[51], text[501], codi[20];
    int ch;
    fgets(text, 500, stdin);
    text[strlen(text) - 1] = '\0';
    scanf("%s", codi);
    while(strcmp(codi, "STOP")) {
        getchar();
        if(strcmp(codi, "CodificareA") == 0) {
            fgets(cheie, 51, stdin);
            cheie[strlen(cheie) - 1] = '\0';
            cod_A(text, cheie);
            printf("%s", text);
            printf("\n");
        } else {
            if(strcmp(codi, "CodificareB") == 0) {
                scanf("%d", &ch);
                cod_B(text, ch);
                printf("%s", text);
                printf("\n");
            } else {
                if(strcmp(codi, "DecodificareA") == 0) {
                    fgets(cheie, 51, stdin);
                    cheie[strlen(cheie) - 1] = '\0';
                    decod_A(text, cheie);
                    printf("%s", text);
                    printf("\n");
                } else {
                    scanf("%d", &ch);
                    decod_B(text, ch);
                    printf("%s", text);
                    printf("\n");
                }
            }
        }
        scanf("%s", codi);
    }
    /*se considera patru cazuri pentru cele 4 tipuri de 
    codificari/decodificari propuse*/
    
    return 0;

}