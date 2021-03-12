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
    GaussPuiss(&f,f,n);
    GaussPuiss(&fp,fp,n);
    GaussSoustrait(&f,f,fp);
    return f.b;    
}

void Fibonacci2(int n){
  
  int x = Log2n(n);
  GaussType * v = malloc((n+1)*sizeof(GaussType));
  GaussType * u = malloc((n+1)*sizeof(GaussType));
  u[0].a = 1;
  u[0].b = 0;
  u[0].d = 1;
  v[0].a = 0;
  v[0].b = 0;
  v[0].d = 1;
  v[1].a = 1;
  v[1].b = 0;
  v[1].d = 2;
  u[1].a = 1;
  u[1].b = 0;
  u[1].d = 2;
  
  GaussType ie = {1,1,2};
  
  GaussType e = {2,0,1};
  GaussType e1 = {4,0,1};
  GaussType tmp,tmp3,tmp1,tmp2;
  int c = 0;
  for(int i = x; i>=0; i--){
      GaussPuiss(&tmp1,v[c],2);
      GaussPuiss(&tmp,v[c+1],2);
      GaussMul(&tmp2,v[c],v[c+1]);
      GaussMul(&tmp2,tmp2,e1);    
      if(((n>>i)&1) == 1){
         GaussMul(&tmp,tmp,e);
         GaussMul(&tmp1,tmp1,e);
         GaussAdd(&v[2*c+1],tmp,tmp1);
         GaussAdd(&v[2*c+2],tmp,tmp2);
         c=2*c+1;
      } else if (((n>>i)&1) == 0){
         GaussMul(&tmp,tmp,e);
         GaussMul(&tmp1,tmp1,e);
         GaussSoustrait(&v[2*c],tmp2,tmp1);
         GaussAdd(&v[2*c+1],tmp,tmp1);
         c = 2*c;
      }
      GaussMul(&tmp3,v[c+1],e);
      GaussSoustrait(&u[c],tmp3,v[c]);     
  }
  for(int j = 0; j<n+1;j++){
    if(v[j].a != 0 && v[j].d!=0){ 
    printf("\nv[%d] = ",j);
    GaussAffiche(v[j],0);
    printf("u[%d] = ",j);
    GaussAffiche(u[j],0);
    printf("F[%d] = %ld\n",j,v[j].d==2? v[j].a : 2*v[j].a);
    }
  }
}


int main (){

  unsigned long int n = 35;
  unsigned long int F;
  F = Fibonacci1(n);
  printf("F de %ld est : %ld\n",n,F);
  Fibonacci2(n);

  return 0;
}
