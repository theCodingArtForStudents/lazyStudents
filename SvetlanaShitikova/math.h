#ifndef MATH_H
#define MATH_H


// matrix


struct matrix{
	unsigned int raw;
	unsigned int col;
	double **item;
};

struct matrix* init_matrix(int n, int m);
struct matrix* init_square_matrix(int nm);

struct matrix* fill_matrix(struct matrix* A);

// matrix math

double determinant_M(const struct matrix* A);

struct matrix* add_M(const struct matrix* A, const struct matrix* B);
struct matrix* sub_M(const struct matrix* A, const struct matrix* B);
struct matrix* mul_M(const struct matrix* A, const struct matrix* B);

struct matrix* mul_d_M(const struct matrix* A, const double b);

struct matrix* div_M(const struct matrix* A, const struct matrix* B);
struct matrix* mod_M(const struct matrix* A, const struct matrix* B);

struct matrix* invers_M(const struct matrix* A);

// /matrix math


char* toString_matrix(const struct matrix*);
void print_matrix(const struct matrix*);

#endif
