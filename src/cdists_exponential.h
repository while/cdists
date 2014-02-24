#ifndef CDISTS_EXPONENTIAL_H
#define CDISTS_EXPONENTIAL_H

#include "cdists.h"

// Exponential distribution
double exppdf(double x, double lambda);
double expcdf(double x, double lambda);
double expinv(double p, double lambda);
double* exprnd(unsigned n, double lambda);

#endif /* CDISTS_EXPONENTIAL_H */
