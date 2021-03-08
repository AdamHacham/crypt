#include <stdio.h>
#include "tp_gauss.h"


// affichage
// si cr!=0, passe \‘a la ligne, sinon, affiche un blanc
void GaussAffiche(GaussType x,int cr)
{
  // on affiche a - b V5 si b est négatif
  printf("(%d %s %d V5) / %d%s",x.a,x.b<0?"-":"+",x.b<0?-x.b:x.b,x.d,cr?"\n":" ");
}

// Algorithme d’Euclide
long int pgcd(long int a, long int b){
  // valeurs absolues de x et y
  if (a<0) a=-a;
  if (b<0) b=-b;
  if (b==0) return a; // cette fonction rend donc 0 si a et b sont
  // tous les deux nuls. Il suffit de le savoir.
  while (a){
     b%=a;
     if (b==0) return a;
     a%=b;
  }
  return b;
}

void Reduire(GaussType *x){
  long int gcd = pgcd(pgcd(x->a,x->b),x->d);
  if(gcd == 1) return;
  x->a = x->a/gcd;
  x->b = x->b/gcd;
  x->d = x->d/gcd;
}

void GaussAdd(GaussType *s,GaussType x,GaussType y){
  s->d = x.d * y.d;
  s->a = (x.a * y.d) + (y.a * x.d);
  s->b = (x.b * y.d) + (y.b * x.d);
  Reduire(s);
}

void GaussMul(GaussType *p,GaussType x,GaussType y){
  p->d = x.d * y.d;
  p->a = (x.a * y.a) + (x.b * y.b * 5);
  p->b = (x.a * y.b) + (x.b * y.a);  
  Reduire(p);
}

void GaussOpp(GaussType *o,GaussType x){
  o->d = x.d;
  o->a = -x.a;
  o->b = -x.b; 
}

void GaussInv(GaussType *i,GaussType x){
  i->d = (x.a * x.a) + (x.b * (-x.b) * 5);
  i->a = x.d * x.a;
  i->b = x.d * (-x.b); 
}

void GaussSoustrait(GaussType *s,GaussType x,GaussType y){
  GaussType o;
  GaussOpp(&o,y);
  GaussAdd(s,x,o);
}

void GaussDivise(GaussType *q,GaussType x,GaussType y){
  GaussType i;
  GaussInv(&i,y);
  GaussMul(q,x,i);
}

GaussType GaussPuiss(GaussType x,unsigned int n){
  GaussType y = x;
  GaussType produit = {1,0,1};
  unsigned int expo = n;

  while(expo != 0){
    if(expo%2 == 1) {
      GaussMul(&produit,produit,y);
      if(expo==1) return produit;  
    }
    GaussMul(&y,y,y);
    expo = expo/2;
  }
 return produit;  
}

/*
int main()
{
 GaussType x={1,1,2};
 GaussType *c ;
 GaussType y={-6, 7,100};
 GaussType s,p;
 GaussAdd(&s,x,y);
 GaussMul(&p,x,y);
 printf("Somme = ");
 GaussAffiche(s,1);
 printf("Produit = ");
 GaussAffiche(p,1);


 GaussType o,i,r;
 GaussOpp(&o,x);
 printf("Oppose = ");
 GaussAffiche(o,1);
 printf("Verification : ");
 GaussAffiche(x,0);
 printf(" + ");
 GaussAffiche(o,0);
 GaussAdd(&r,x,o);
 printf(" = ");
 GaussAffiche(r,1);

 GaussInv(&i,x);
 printf("Inverse = ");
 GaussAffiche(i,1);
 printf("Verification : ");
 GaussAffiche(x,0);
 printf(" x ");
 GaussAffiche(i,0);
 GaussMul(&r,x,i);
 printf(" = ");
 GaussAffiche(r,1);

 GaussType q;

 GaussDivise(&q,x,y);
 x = GaussPuiss(x,4);
 GaussAffiche(x,1);
 

}
*/
