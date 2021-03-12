#include <stdio.h>
#include <stdlib.h>
#include "tp_euclide_bin.h"
#include "tp_residu_quadratique.h"

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
  	for (int i=2 ; i<=nombre ; i++){
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


int residu_quadratique(int n,int **cs){

	// Déclaration de variables
	int * e,* d;
        int k = 1;
	int j = phi(n);
        int z;

	// Allocation Mémoire
     	e = malloc(n*sizeof(int));
     	*e = 0;

	// Inititialisation
     	for(int i = 1; i<n; i++){
       		e[i] = 0;
     	}
	// Résidu Modulo n
     	for(int i = 1; i<n+1; i++){
       		divide(&k,multiplication(i,i),n);
       		e[k]++;
     	}

	// Si n est un nombre premier
	if(j == n-1){
     		j = (n-1)>>1;
     		z = j;  //Cardinal des résidus quadratiques
     		d = malloc(j*sizeof(int));
	        *d=0;
		// Construction de la liste des Résiduq Quadratique
     		for(int i = n+1; i>0; i--){
       			if(e[i] == 2){
         			d[j] = i;
         			j--;
       			}
     		}
                *cs=d;
		return z;
	// Si nombre constitue de deux nombre premiers
	} else if (fact_premier(n) == 2) {
     		j = phi(n)>>2;
     		int z = j;
     		d = malloc(j*sizeof(int));
     	        *d=0;
		// Ajout à la liste
		for(int i = n; i>0; i--){
       			if(e[i] == 4){
         			d[j] = i;
         			j--;
       			}
     		}
                *cs = d;
     		return z;
   	}
	free(e);
	free(d);
	return 0;
}

int Legendre(long unsigned int a,long unsigned int p){
	int t[2] = {1,-1};
	int e;
	if(a==1) return 1;
	if((a&1) == 0) return Legendre(a>>1,p) * t[((multiplication(p,p)-1)>>3)&1];
	if((a&1) == 1){
		divide(&e,p,a);
	        return Legendre(e,a) * t[(multiplication(p-1,a-1)>>2)&1];
	}
}


int main(){
  int n = 10205;
  printf("phi(%d) = %d\n",n,phi(n));
  int e = fact_premier(n);
  printf("e = %d\n",e);
  int *w = NULL;;
  int b = residu_quadratique(n,&w);
  for(int i = 1; i<=b; i++){
    printf("e[%d] = %d\n",i,w[i]);
  }
  long unsigned int a = 541;
  long unsigned int p = 2011;
  int z = Legendre(a,p);
  printf("Symbole de Legendre de (%d,%d) est %d\n",a,p,z);
  free(w);
 return 0;
}
