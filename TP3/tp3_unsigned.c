#include<stdio.h>

#define L 9 // dimension du LFSR
unsigned int Etat;
unsigned int Polynome=0xc9; // Le polynôme 1+X^3+X^6+X^7+X^9


// initialisation de l’état initial avec une table d’entiers donnée
void Initialise(unsigned int e)
{
  Etat=e;
}

// affichage de l’état interne du LFSR
void AfficheEtat()
{
  int i;
  for (i=L-1;i>=0;i--) printf("%2d",(Etat >> i) & 1);
  printf("\n");
}


// Fonction de rebouclage 
unsigned int Rebouclage()
{
  int i;
  unsigned int x;
  x=Etat & Polynome;
  x^=(x>>8);
  x^=(x>>4);
  x^=(x>>2);
  return (x^(x>>1))&1;
}

// Avance avec un pas de 1
void avance(){
   unsigned int r = (Rebouclage() << 8); 
   Etat = Etat >> 1;
   Etat ^= r;
}

// Avance de 20 iteration
void etat_vingt(unsigned int s){
  Initialise(s);
  int i = 0;
 while(i<20){
  avance();
  i++;
 }
}


// Periode du LFSR 
int periode_lfsr(unsigned int e){
  int i = 0;
  Initialise(e);
  avance();
  while(Etat != e){
   avance();
   i++;
  }
  return i+1;
}

int main(){  

  Initialise(0x100);
  printf("periode_lfsr : %d\n",periode_lfsr(0x100));

 return 0;
}
