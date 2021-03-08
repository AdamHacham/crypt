#include<stdlib.h>
#include<stdio.h>
#include"tp2.h"

long unsigned PolGCD(long unsigned a, long unsigned b){
 int deg_a = Degree(a);
 int deg_b = Degree(b);
 static long unsigned pgcd = 1;
 if(deg_b == 0 || deg_a == 0) return 1;
 if(deg_a >= deg_b) {
    long unsigned t = PolModDiv(&a,a,b);
    if (a == 0) return pgcd;
    pgcd = a;    
    PolGCD(b,a);
 }
 else { 
    PolGCD(b,a);
 }  
 return pgcd;
}

long unsigned PolInverseMod(long unsigned a, long unsigned p){

 long unsigned* u = malloc(100*sizeof(*u));
 long unsigned* v = malloc(100*sizeof(*v));
 long unsigned* b = malloc(100*sizeof(*b));
 u[0] = v[1] = 1;
 u[1] = v[0] = 0;
 b[0] = a;
 b[1] = p;
 int i = 1;
 long unsigned q = 0;
 do{
  q=PolModDiv(&b[i+1],b[i-1],b[i]);
  if(b[i+1] == 1) return q;
  u[i+1] = u[i-1] ^ PolMul(q,u[i]);
  v[i+1] = v[i-1] ^ PolMul(q,v[i]);
  i++;
 } while(b[i]);
 return u[i-1];
}


int PolIsIrreductible(long unsigned x){

   long unsigned d = Degree(x);
   long unsigned dg = 0;
   long unsigned s = x;

   while(dg<(d>>1)){
     x = PolSqr(x);
     s= x+0x2;
     if(s == 0) return 0;
     else if(PolGCD(s,x) != 1) return 0;
     else if(x == 0x2) return 0;
     else if(dg == 0) { 
      dg=1;
      return 1;
     }
     dg*=2;
   }
   
   return 1;
}


void trinome15(){
  long unsigned x = 0x8001;
  long unsigned k = 0x2;
  for(int i= 0; i<15; i++){
    if(PolIsIrreductible(x^k) == 1){
      PrintPol(x^k);
    }
    k<<=1;
  }
} 



int main(){

 long unsigned c = 0x2C1;
 long unsigned d = 0x151; 
 long unsigned b = 0x2;
 long unsigned a = 0x805;
/* printf("La division Euclidienne de ");
 PrintPol(c);
 printf(" par ");
 PrintPol(d);
 printf(" est : ");
 printf("La division Euclidienne de ");
 PrintPol(a);
 printf(" par ");
 PrintPol(b);
 printf(" est : ");
 PolModDiv(&a,a,b);
 PrintPol(a);*/


// PrintPol(PolGCD(c,d));
// PrintPol(PolInverseMod(d,c));

  trinome15();
  printf("\nisreductible : %d\n",PolIsIrreductible(0x11B));
  

// PrintPol(PolPowerMod(0x2, 2046, 0x805));
 return 0;
}
