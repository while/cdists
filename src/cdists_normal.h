#ifndef CDISTS_NORMAL_H
#define CDISTS_NORMAL_H

#include "cdists.h"

// Normal distribution functions
double normpdf(double x, double mu, double sig);
double normcdf(double x, double mu, double sig);
double norminv(double p, double mu, double sig);
double* normrnd(unsigned n, double mu, double sig);

#endif /* CDISTS_NORMAL_H */

