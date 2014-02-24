/* 
 * CDISTS Gamma 
 * Gamma distribution functions and random number generation.
 * by Vilhelm von Ehrenheim
 *
 */
#include <stdlib.h>
#include <math.h>

#include "cdists_gamma.h"

/* Probability density function for gamma distribution  */
double gammapdf(double x, double shape, double rate)
{
        if (shape <= 0 || rate <= 0) 
                error("Both parameters must be larger than 0.");

        return pow(rate, shape)/tgamma(shape)*pow(x, shape-1)*exp(-rate*x);
}

/* umulative distribution function for gamma distribution */
double gammacdf(double x, double shape, double rate)
{
        if (shape <= 0 || rate <= 0) 
                error("Both parameters must be larger than 0.");
        if (x <= 0) 
                return 0.;

        return NAN;
}

/* Inverse cumulative distribution function of gamma distribution */
double gammainv(double p, double shape, double rate)
{
        if (shape <= 0 || rate <= 0) 
                error("Both parameters must be larger than 0.");
        return NAN;

}

/* Random number generator of gamma deviates */
double* gammarnd(unsigned n, double shape, double rate)
{
        if (shape <= 0 || rate <= 0) 
                error("Both parameters must be larger than 0.");

        double *arr = calloc(n, sizeof(double));

        double orig_shape, a1, a2, u, v;
        double* x;

        orig_shape = shape;
        if (shape < 1.)
                shape += 1.;

        a1 = shape - 1./3.;
        a2 = 1./sqrt(9.*a1);

        for (int i=0; i<n; i++) {
                do {
                        do {
                                x = normrnd(1, 0, 1);
                                v = 1. + a2 * *x;
                        } while (v <= 0);
                        v = v*v*v;
                        u = rnd();
                } while (u > 1. - 0.331*SQR(SQR(*x)) &&
                                log(u) > 0.5*SQR(*x) + a1*(1. - v + log(v)));
                if (shape == orig_shape)
                        arr[i] = a1*v/rate;
                else
                        arr[i] = pow(u, 1./orig_shape)*a1*v/rate; 
        }
        return arr;
}

