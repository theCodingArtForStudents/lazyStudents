#ifndef MATH_H
#define MATH_H

// int

int n_add(int a, int b);
int n_sub(int a, int b);
int n_mul(int a, int b);
int n_div(int a, int b);
int n_mod(int a, int b);

// /int

// float

// /float

// matrix


struct matrix{
	int raw;
	int col;
	double **item;
};

struct matrix* init_matrix(int n, int m);
struct matrix* init_square_matrix(int nm);


void toString_matrix(const struct matrix*);


#endif
