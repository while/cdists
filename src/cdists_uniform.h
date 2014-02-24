#ifndef CDISTS_UNIFORM_H
#define CDISTS_UNIFORM_H

#include "cdists.h"

// Uniform distribution functions
double unifpdf(double x, double a, double b);
double unifcdf(double x, double a, double b);
double unifinv(double p, double a, double b);
double* unifrnd(unsigned n, double a, double b);

#endif /* CDISTS_UNIFORM_H */

