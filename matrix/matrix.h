  
#ifndef __MATRIX__
#define __MATRIX__

typedef struct {

	unsigned int    m;
	
	unsigned int    n;
	
	double *a;

} TMatrix;

void mx_free(TMatrix *m);

void mx_print(TMatrix *m);

TMatrix *mx_identity(unsigned int n);

TMatrix *mx_from_text(const char *s);

TMatrix *mx_mul(TMatrix *m1, TMatrix *m2);

TMatrix *mx_add(TMatrix *m1, TMatrix *m2);

TMatrix *mx_mul_scalar(TMatrix *m, double s);

TMatrix *mx_pow(TMatrix *m, double s);

TMatrix *mx_transponse(TMatrix *m);

double mx_det(TMatrix *m);

void mx_sort(TMatrix *m);

#endif