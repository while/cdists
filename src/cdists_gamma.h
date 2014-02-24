#ifndef CDISTS_GAMMA_H
#define CDISTS_GAMMA_H

#include "cdists.h"

double gammapdf(double x, double shape, double rate);
double gammacdf(double x, double shape, double rate);
double gammainv(double p, double shape, double rate);
double* gammarnd(unsigned n, double shape, double rate);

#endif /* CDISTS_GAMMA_H */

