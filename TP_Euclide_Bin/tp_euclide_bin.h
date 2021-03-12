#ifndef H_TP_EUCLIDE_BIN
#define H_TP_EUCLIDE_BIN

#define MIN(a,b) (((a)<(b))?(a):(b))
unsigned int Log2n(long unsigned n);
int Degree(long unsigned x);
int divide(int *r,int a,int b);
int multiplication(int x,int y);
int EuclideBinaire1(int a,int b);
int BezoutBinaire(int*pu,int*pv,int a,int b);

#endif
