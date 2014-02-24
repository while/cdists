#ifndef CDISTS_GEOMETRIC_H
#define CDISTS_GEOMETRIC_H

#include "cdists.h"

// Geometric distribution
double geompdf(unsigned k, double p);
double geomcdf(unsigned k, double p);
double geominv(double q, double p);
double* geomrnd(unsigned n, double p);

#endif /* CDISTS_GEOMETRIC_H */
