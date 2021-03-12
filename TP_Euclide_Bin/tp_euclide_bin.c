#include <stdio.h>
#include "tp_euclide_bin.h"

//#define MIN(a,b) (((a)<(b))?(a):(b))
unsigned int Log2n(long unsigned n)
{
    return (n > 1) ? 1 + Log2n(n / 2) : 0;
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


int divide(int *r,int a,int b)
{
   int deg_a = Degree(a);
   int deg_b = Degree(b);
   int q = 0;
   while(deg_a>=deg_b){
     if(a >= (b<<(deg_a-deg_b))){
       a = a-(b<<(deg_a-deg_b));
       q = q+(1<<(deg_a-deg_b));
       deg_a = Degree(a);
     } else {  
       deg_a--;
     }
   }
  *r = a;
  return q;
}


int multiplication(int x,int y){
   int r = 0;
   while(x!=0){
      if((x&1) == 1){
         r = r + y;
         x = x - 1;
      } else {
         x >>= 1;
         y <<= 1;
      }
   }
   return r;
}

int EuclideBinaire1(int a,int b){
  
  int p = 1;
  while(a != b) {
    if((a&1) == 0 && (b&1) == 0){
      p <<= 1;
      a >>= 1;
      b >>= 1;
    } else if((a&1) == 0 && (b&1) == 1){
      a >>= 1;
    } else if((a&1) == 1 && (b&1) == 0){
      b >>= 1;
    } else if(((a-b > 0? a-b : b-a)&1) == 0){ 
      int y = a-b > 0? (a-b) : (b-a);
      b = MIN(a,b);        
      a = y;
    }
  }
  return p*a;
}

int BezoutBinaire(int*pu,int*pv,int a,int b){
  int q, r, s, t, tmp;  
  *pu = 1;
  *pv = 0;
  s = 0;
  t = 1;
  
  while (b > 0) {
    q = divide(&r,a,b);
    a = b;
    b = r;
    tmp = s;
    s = *pu - multiplication(q,s);
    *pu = tmp;
    tmp = t;
    t = *pv - multiplication(q,t);;
    *pv = tmp;
  }
  return a;
}


/*
int main(){
 int a = 167;
 int b = 23;
 int x = EuclideBinaire1(a,b);
 printf("%d\n",x);
 int pu,pv,w;
 w = BezoutBinaire(&pu,&pv,a,b);
 printf("pgcd(%d,%d) = %d\n",a,b,w);
 printf("%d = %d x %d + %d x %d \n",w,pu,a,pv,b);
  
 return 0;
}
*/
