#include<stdio.h>
#include<stdlib.h>
#include"tp1.h"

/* Fonction Log en base 2 permet de nous donner la taille en binaire de l'entier à convertir */
long unsigned Log2n(long unsigned n) 
{ 
    return (n > 1) ? 1 + Log2n(n / 2) : 0; 
} 

/* Conversion en base 2 */
void print_binary(long unsigned x){
  
  
//  unsigned int i = Log2n(x);
  for(int i = 32;i;i--)
  {  
    printf("%lu", (x >> i) & 1);  
  }

  printf("%lu\n",(x%2));  
}


/* Représentation polynomial à partir de l'Hexadecimal */
void PrintPol(long unsigned x){
  
  unsigned int i = Log2n(x);

  for(;i;i--)
  {
    if((x >> i) & 1){
      printf("X^%u + ",i);
    }
  }
  if(x%2 == 1){
     printf("%d\n",1);
  } else {
     printf("%d\n",0);
  }
}

/* Affiche le plus Haut degree du polynome */
int Degree(long unsigned x){

  unsigned int i = Log2n(x);

  for(;i;i--)
  {
    if((x >> i) & 1){
      return i;
    }
  }
  return 0;
}

/*
int main(int argc,char *argv[]){
  
  long unsigned a = 0x21A;

  printf("Taille du chiffre : %lu\n",Log2n(0x21A));
  printf("l'ecriture binaire de %lx est : ",a);  
  print_binary(a);
  printf("le polynome de %lx est : ",a);  
  PrintPol(a);
  printf("le degree le plus eleve du polynome est %d",Degree(a));
  printf("\n");
  return 0;
}
*/
