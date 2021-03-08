#ifndef H_TP_GAUSS
#define H_TP_GAUSS

typedef struct {
  long int a,b,d;
} GaussType;


// affichage
// si cr!=0, passe \‘a la ligne, sinon, affiche un blanc
void GaussAffiche(GaussType x,int cr);
long int pgcd(long int a, long int b);
void Reduire(GaussType *x);
void GaussAdd(GaussType *s,GaussType x,GaussType y);
void GaussMul(GaussType *p,GaussType x,GaussType y);
void GaussOpp(GaussType *o,GaussType x);
void GaussInv(GaussType *i,GaussType x);
void GaussSoustrait(GaussType *s,GaussType x,GaussType y);
void GaussDivise(GaussType *q,GaussType x,GaussType y);
GaussType GaussPuiss(GaussType x,unsigned int n);

#endif
