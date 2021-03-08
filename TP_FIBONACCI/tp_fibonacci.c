#include <stdio.h>
#include <stdlib.h>
#include "tp_gauss.h"



long unsigned Log2n(long unsigned n)
{
    return (n > 1) ? 1 + Log2n(n / 2) : 0;
}


unsigned long int Fibonacci1(unsigned int n){
    
    GaussType f = {1,1,2};
    GaussType fp = {1,-1,2};
    GaussType fn=GaussPuiss(f,n);
    GaussType fpn = GaussPuiss(fp,n);
    GaussSoustrait(&f,fn,fpn);
    return f.b;    
}

void Fibonacci2(int n){
  
  int x = Log2n(n);
  GaussType * v = malloc((n+1)*sizeof(GaussType));
  GaussType * u = malloc((n+1)*sizeof(GaussType));
  u[0].a = 1;
  u[0].b = 1;
  u[0].d = 1;

  v[0].a = 0;
  v[0].b = 0;
  v[0].d = 0;

  v[1].a = 1;
  v[1].b = 0;
  v[1].d = 2;

  u[1].a = 1;
  u[1].b = 1;
  u[1].d = 2;

  GaussType e = {2,0,1};
  GaussType e1 = {4,0,1};
  GaussType tmp2;

  for(int i = 0; i<x+1; i++){
//      GaussType tmp = GaussPuiss(v[i+1],2);
//      GaussType tmp1 = GaussPuiss(v[i],2);
//      GaussMul(&tmp2,v[i],v[i+1]);
//      GaussMul(&tmp2,tmp2,e1);    
      if(((n>>(x-i))&1) == 1){
//         GaussMul(&tmp,tmp,e);
//         GaussMul(&tmp1,tmp1,e);
//         GaussAdd(&v[2*i+1],tmp,tmp1);
//         GaussAdd(&v[2*i+2],tmp,tmp2);
         printf("\n(%d,%d) le n = %d",2*i+1,2*i+2, ((n>>(x-i))&1));
      } else {
//         GaussMul(&tmp,tmp,e);
//         GaussMul(&tmp1,tmp1,e);
//         GaussOpp(&tmp1,tmp1);
//         GaussAdd(&v[2*i],tmp2,tmp1);
//         GaussAdd(&v[2*i+1],tmp,tmp1);
         printf("\n(%d,%d) n est  : %d",2*i,2*i+1,((n>>(x-i))&1));
      }
  }
/*  for(int j = 0; j<n+1;j++){
    GaussAffiche(v[j],1);

  }
*/
}


int main (){

  unsigned long int n = 16;
  unsigned long int F;
  F = Fibonacci1(n);
  printf("F de %d est : %ld\n",n,F);
  Fibonacci2(13);



}
