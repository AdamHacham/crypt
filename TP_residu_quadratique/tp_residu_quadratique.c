#include <stdio.h>
#include <stdlib.h>
#include "tp_euclide_bin.h"

int phi(int n){
   int cpt=0;
   for(int i = 1; i<n; i++){
     int e = EuclideBinaire1(i,n);
     if(e==1) cpt++; 
   }
   return cpt;
}

int fact_premier(int n){
  int *e = malloc(4*sizeof(int));;
  int nombre = n;
  int tmp,t,cpt;
  cpt = 1;
  *e = 1;
  for (int i=2 ; i<=nombre ; i++)
  {
    t = divide(&tmp,nombre,i);
    if (tmp==0){
      if(cpt >= 4) return 0;
      *(e+cpt) = i;
      if(divide(&t,i,e[cpt-1])==e[cpt-1]) return 0;
      if(cpt == 3) return 2;
      cpt++;
    } 
  }
  return 1;
}

int * residu_quadratique(int n){
   int * e,*d;
 if(phi(n) == n-1){
   int j = (n-1);
   e = malloc(j*sizeof(int));
   *e = 0;
   int r = 1;
   for(int i = 1; i<n; i++){
      divide(&r,multiplication(i,i),n);
      e[r]++;
   }
   j = (n-1)>>1;
   d = malloc(j*sizeof(int));
   for(int i = n; i>0; i--){
     if(e[i] == 2){
       d[j] = i;
       printf("e[%d] = %d\n",j,d[j]);
       j--;   
     }
   }   
 } else if (fact_premier(n) == 2)
 {
  int y = phi(n);
  e = malloc(y*sizeof(int));
  *e = 0;
  int k = 1;
   for(int i = 1; i<n; i++){
      divide(&k,multiplication(i,i),n);
      e[k]++;
   }
   y = phi(n)>>2;
   d = malloc(y*sizeof(int));
   for(int i = n; i>0; i--){
     if(e[i] == 4){
       d[y] = i;
      printf("e[%d] = %d\n",y,d[y]);
       y--;   
     }
   }   
  } else {
   printf("Erreur\n");
 } 
}

int main(){
  int n = 10205;
  printf("phi(%d) = %d\n",n,phi(n));
  int e = fact_premier(35);
  printf("e = %d\n",e);
  int * w = residu_quadratique(209);

 return 0;
}
