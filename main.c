#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n=9;
    int T[n][n];
    int choix;
    int i,j,N;


     for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            T[i][j] = 0;
        }
    }
    srand(time(NULL));

    do{
    menu:
    printf("\n****************** MENU ******************\n");
    printf("\n1. Jouer le sudoku.\n");
    printf("2. Effacer un nombre dans la cellule.\n");
    printf("3. Afficher le sudoku.\n");
    printf("4. Vider le sudoku.\n");
    printf("5. Quitter.\n");

    printf("\nEntrer votre choix : ");
    scanf("%d",&choix);


    switch(choix){
        case 1:

            do {
                printf("\nEntrez les coordonnees de la cellule que vous souhaitez remplire (ligne colonne) : ");
                scanf("%d%d", &i, &j);

                if (i < 0 || i >= n || j < 0 || j >= n) {
                    printf("\nERREUR: Les coordonnees sont invalides.\n");
                    continue;
                }

                printf("Entrer la valeur (entre 1 et 9) (Saisir 0 pour revenir au menu) : ");
                scanf("%d", &N);

                if (N == 0) {
                    printf("Retour au menu.\n");
                    break;
                }

                int valid = 1;

                for (int x = 0; x < n; x++) {
                    if (T[i][x] == N) {
                        valid = 0;
                        break;
                    }
                }

                if (valid) {
                    for (int x = 0; x < n; x++) {
                        if (T[x][j] == N) {
                            valid = 0;
                            break;
                        }
                    }
                }

                            for (int count = 0; count < 15; ) {
                i = rand() % n;
                j = rand() % n;
                N = (rand() % 9) + 1;

                int valid = 1;

                for (int x = 0; x < n; x++) {
                    if (T[i][x] == N) {
                        valid = 0;
                        break;
                    }
                }

                if (valid) {
                    for (int x = 0; x < n; x++) {
                        if (T[x][j] == N) {
                            valid = 0;
                            break;
                        }
                    }
                }

                if (valid) {
                    int startRow = (i / 3) * 3;
                    int startCol = (j / 3) * 3;

                    for (int x = startRow; x < startRow + 3; x++) {
                        for (int y = startCol; y < startCol + 3; y++) {
                            if (T[x][y] == N) {
                                valid = 0;
                                break;
                            }
                        }
                        if (!valid)
                            break;
                    }
                }

                if (valid) {
                    T[i][j] = N;
                    count++;
                }
            }

            for (int i = 0; i < n; i++) {
                    if (i == 0 || i == 3 || i == 6)
                        printf(" \n ___________ ___________ ___________ \n\n|");
                    else
                        printf(" \n|___________|___________|___________|\n|");

                    for (int j = 0; j < n; j++) {
                        if (T[i][j] == 0)
                            printf("   |");
                        else
                            printf(" %d |", T[i][j]);
                    }
                }
                printf(" \n ___________ ___________ ___________ \n");

                if (valid) {
                    int startRow = (i / 3) * 3;
                    int startCol = (j / 3) * 3;

                    for (int x = startRow; x < startRow + 3; x++) {
                        for (int y = startCol; y < startCol + 3; y++) {
                            if (T[x][y] == N) {
                                valid = 0;
                                break;
                            }
                        }
                        if (!valid)
                            break;
                    }
                }

                if (valid && N >= 1 && N <= 9) {
                    T[i][j] = N;
                    printf("\nLa valeur a ete ajoutee avec succes.\n");
                } else {
                    printf("\nERREUR : La valeur doit etre entre 1 et 9 et ne doit pas se repeter dans la ligne, la colonne ou le carre 3x3.\n");
                }

                for (int i = 0; i < n; i++) {
                    if (i == 0 || i == 3 || i == 6)
                        printf(" \n ___________ ___________ ___________ \n\n|");
                    else
                        printf(" \n|___________|___________|___________|\n|");

                    for (int j = 0; j < n; j++) {
                        if (T[i][j] == 0)
                            printf("   |");
                        else
                            printf(" %d |", T[i][j]);
                    }
                }
                printf(" \n ___________ ___________ ___________ \n");

            } while (N != 0);

        break;

        case 2:

            printf("\nEntrez les coordonnees de la cellule que vous souhaitez effacer (ligne colonne) : ");
            scanf("%d%d",&i,&j);

            if (i < 0 || i >= n || j < 0 || j >= n) {

                printf("\nERREUR: Les coordonnées sont invalides.\n");

                break;

            } else {

                T[i][j] = 0;
            }
            printf("\nLa valeur a ete effacer avec succes.\n");

            for (int i = 0; i < n; j++) {
                    if (i == 0 || i == 3 || i == 6)
                        printf(" \n ___________ ___________ ___________ \n\n|");
                    else
                        printf(" \n|___________|___________|___________|\n|");

                    for (int j = 0; j < n; j++) {
                        if (T[i][j] == 0)
                            printf("   |");
                        else
                            printf(" %d |", T[i][j]);
                    }
                }
                printf(" \n ___________ ___________ ___________ \n");

            break;

        case 3:
            for (i = 0; i < n; i++){
                if ( i==0 || i==3 || i==6)
                    printf(" \n ___________ ___________ ___________ \n|");
                else
                    printf(" \n|___________|___________|___________|\n|");
                for (j = 0; j < n; j++){
                    if (T[i][j] == 0)
                        printf("   |");
                    else
                        printf(" %d |", T[i][j]);
                }
            }
            printf(" \n ___________ ___________ ___________ \n");
            break;

        case 4:
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        T[i][j] = 0;
                    }
                }
                printf("\nLe sudoku a ete vide avec succes.\n");
                for (int i = 0; i < n; i++) {
                    if (i == 0 || i == 3 || i == 6)
                        printf(" \n ___________ ___________ ___________ \n\n|");
                    else
                        printf(" \n|___________|___________|___________|\n|");

                    for (int j = 0; j < n; j++) {
                        if (T[i][j] == 0)
                            printf("   |");
                        else
                            printf(" %d |", T[i][j]);
                    }
                }
                printf(" \n ___________ ___________ ___________ \n");

                break;



        }

    }while(choix!=5);

    return 0;
}
