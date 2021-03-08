#include<stdio.h>
#include<stdlib.h>
#include"tp2.h"

/* Fonction Log en base 2 permet de nous donner 
   la taille en binaire de l'entier à convertir */
unsigned int Log2n(long unsigned n) 
{ 
    return (n > 1) ? 1 + Log2n(n / 2) : 0; 
} 

long unsigned PolMul(long unsigned a,long unsigned b){
   
  unsigned int i = Log2n(b);
  long unsigned res = 0;
  if(b%2 == 1){
    res = a;
  }  
  for(;i>0;i--)
  {  
    if((b >> i) & 1){
      res = res ^ (a << i);
    }  
  }
  return res;
}


long unsigned PolSqr(long unsigned a){

  unsigned int i = Log2n(a);
  long unsigned res = 0;
  long unsigned b = a;
  if(a%2 == 1){
    res = a;
  }
  i = i*2;
  for(;i>0;i--)
  {
    if((b >> i) & 1){
      res = res ^ (a << i);
    }
  }
  return res;
}


int Degree(long unsigned x){

  unsigned int i = Log2n(x);
  if(x == 0 || x == 1){
    return 0;
  }
  for(;i;i--)
  {
    if((x >> i) & 1){
      return i;
    }
  }
  return i;
}

void print_binary(long unsigned x){
  
  unsigned int i = Log2n(x);
  
  for(;i;i--)
  {  
    printf("%lu ",(x >> i) & 1);  
  }
  
  printf("%lu\n",(x%2));
  
}

long unsigned PolModDiv(long unsigned *r,long unsigned a,long unsigned b){

   int deg_a = Degree(a);
   int deg_b = Degree(b);
   long unsigned q = 0;
   while(deg_a>=deg_b){
     a = a^(b<<(deg_a-deg_b));
     q = q^(1<<(deg_a-deg_b));
     deg_a = Degree(a);
   }
  *r = a;   
  return q;
}

long unsigned PowerSerial(long unsigned a,long unsigned b){

int deg_a = Degree(a);
   int deg_b = Degree(b);
   long unsigned q = 0;
   if(a%2 == 1){
    q = 1;
   }
   for(int i = 1; i<31 ;i++){
     if((a >> i) & 1){
      q = q^(1<<i);
      a = a^(b<<i);       
     }
   }
   return q;
}

long unsigned PolPowerMod(long unsigned a, long unsigned n, long unsigned p) {
        long unsigned r = 1;
        if (n == 0) {
                return 1;
        }
        while (n > 1) {
          if (n%2 == 0) {
             PolModDiv(&a, PolSqr(a), p);
             n = n/2;
          } else {
             PolModDiv(&r, PolMul(a, r), p);
             PolModDiv(&a, PolSqr(a), p);
             n = (n - 1)/2;
          }
        }
        PolModDiv(&r, PolMul(a, r), p);
        return r;
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



/*
int main(int argc,char *argv[]){
  
  printf("%u\n",Log2n(0x203));
  long unsigned *r = NULL;
  r = malloc(sizeof(long unsigned));
  long unsigned v;
  v = PolModDiv(r,0x203,0x9B);
  PrintPol(v);
  PrintPol(*r);
  PrintPol(PolPowerMod(0x2,255,0x11b));
 print_binary(0x203);
  PrintPol(0x203);

  printf("degre  =  %d\n",Degree(0x234));
  printf("dpl  =  %lx\n",PolSqr(0xA2));

  for(int i = 0 ; i<=Log2n(123); i++){
    printf("%d",tab[i]);
  }
  printf("%u\n",Degree(1));
  printf("%u\n",Degree(0));
  printf("%u\n",Degree(2));
   printf("%u\n",Degree(3));
  printf("%u\n",Degree(4));
 printf("%u\n",Degree(5));
        PrintPol(PowerSerial(0x1252, 0x19));
        printf("\n");
        PrintPol(PolPowerMod(0x2, 255, 0x11b));
        printf("\n");
        PrintPol(PolPowerMod(0x2, 15, 0x11b));
  printf("\n");
  return 0;
}
*/
