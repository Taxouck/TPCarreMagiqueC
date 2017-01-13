#include <stdio.h>
#include <stdlib.h>

#define TAILLE 5

typedef struct Curseur{


    int x;
    int y;

}Curseur;

void initialisercarre(Curseur *pos, int tableau[TAILLE][TAILLE]);
void avancer(Curseur *pos, int tableau[TAILLE][TAILLE]);
void corrigerposition(Curseur *pos);
void testerposition(Curseur *pos, int tableau[TAILLE][TAILLE]);
void affichercarre(int tableau[TAILLE][TAILLE]);
void placer(Curseur *pos, int tableau[TAILLE][TAILLE], int *valeur);

int main()
{
    int carre[TAILLE][TAILLE];
    Curseur pos;    //D�claration du tableau et du curseur
    int inci;
    inci=1;
    initialisercarre(&pos, carre);  //mise � 0 des valeurs du tableau + mise � 1 de la premi�re valeur
    do{
        avancer(&pos, carre); //D�place le curseur vers la prochaine position
        corrigerposition(&pos); //Si le curseur est hors des limites du tableau, le faire boucler de l'autre c�t�
        testerposition(&pos, carre); //Si le curseur est sur une case non-vide c�d d�j� attribu�e, le d�placer
        corrigerposition(&pos); //Puisque le curseur a potentiellement �t� red�plac�, il faut recorriger sa position
        placer(&pos, carre, &inci); //Incr�mente la valeur et la positionne dans la case o� le curseur pointe actuellement
    }while(inci<(TAILLE*TAILLE)); //Quitte la boucle lorsqu'elle a �t� it�r�e TAILLE^2-1 fois
    affichercarre(carre); //Une fois la boucle quitt�e, c�d toutes les cases du carr� ont une valeur attribu�e, l'afficher � l'�cran
    return 0;
}

void initialisercarre(Curseur *pos, int tableau[TAILLE][TAILLE]){

    for (pos->x=0;pos->x<TAILLE;pos->x++){
        for (pos->y=0;pos->y<TAILLE;pos->y++){
            tableau[pos->x][pos->y]=0;
        }
    }
    pos->x=trunc(TAILLE/2)-1; //Mettre � la position initiale, c�d une case au nord du centre du carr�
    pos->y=trunc(TAILLE/2);
    tableau[pos->x][pos->y]=1; //Mettre cette case � 1
}

void avancer(Curseur *pos, int tableau[TAILLE][TAILLE]){
    pos->x=pos->x-1;
    pos->y=pos->y+1;
}

void corrigerposition(Curseur *pos){
    if (pos->x<0)
        pos->x=pos->x+TAILLE;

    if (pos->y>=TAILLE)
        pos->y=pos->y%TAILLE;

    if (pos->y<0)
        pos->y=pos->y+TAILLE;
}

void testerposition(Curseur *pos, int tableau[TAILLE][TAILLE]){
    if (tableau[pos->x][pos->y]!=0){
        pos->x=pos->x-1;
        pos->y=pos->y-1;
    }
}

void affichercarre(int tableau[TAILLE][TAILLE]){
    int i=0;
    int j=0;
    for (i=0;i<TAILLE;i++){
        for (j=0;j<TAILLE;j++){
            printf("%i  ",tableau[i][j]); //Affiche les valeurs du carr�
            if (tableau[i][j]<10){
                    printf(" "); //Pour meilleure lisibilit�
            }
        }
        printf("\n");
    }
}

void placer(Curseur *pos, int tableau[TAILLE][TAILLE], int *valeur){
    *valeur=*valeur+1;
    tableau[pos->x][pos->y]=*valeur;
}
