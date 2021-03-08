#include<stdio.h>
#include<stdlib.h>

#define L 9 // dimension du LFSR
int Etat[L]; // etat interne du LFSR
int Polynome[L]={1,0,0,1,0,0,1,1,0}; // Le polynôme 1+X^3+X^6+X^7+X^9

// initialisation de l’état initial avec une table d’entiers donnée
void Initialise(int *e)
{
  int i;
  for (i=0;i<L;i++) Etat[i]=e[i];
}

// affichage de l’état interne du LFSR
void AfficheEtat()
{
  int i;
  for (i=L-1;i>=0;i--) printf("%2d ",Etat[i]);
  printf("\n");
}

// Teste si deux tableau sont égaux, indispensable pour le calcul de la periode
int SontEgaux(int *a,int *b){
  int i = 1;
  while(i<L){
    if(*(a+i) != *(b+i)) return 0;
    i++;
  }
  return 1;
}

// Fonctions Avance qui fait avancer le lfsr a pas de 1
int avance(){
  int new_lfsr_bit = 0;
  int sorti_lfsr = Etat[0];
  for(int i = 0; i<L-1;i++){
     if(Polynome[i] == 1){
       new_lfsr_bit ^= Etat[i];
     }
     Etat[i] = Etat[i+1];
  }
  Etat[L-1] = new_lfsr_bit;
  return sorti_lfsr;
}

// Fonction pour avancer de 20 états
void etat_vingt(int * s){
  Initialise(s);
  int i = 0;
  while(i<20){
  avance();
  i++;
 }
}


// Calcul la periode d'un lfsr
int periode_lfsr(int * e){
  int i = 0;
  Initialise(e);
  avance();
  while(!SontEgaux(Etat,e)){
   AfficheEtat();
   avance();
   i++;
  }
  return i+1;
}

int main(){
  int s[L] = {1,0,0,0,0,0,0,0,0};

  printf("Periode LFSR  T = %d\n",periode_lfsr(s));
//  Initialise(s);
//  etat_vingt(s);
  return 0;
}
