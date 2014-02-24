/* 
 * CDISTS Continuous uniform distribution
 * by Vilhelm von Ehrenheim
 *
 */
#include <stdlib.h>
#include <limits.h>
#include <math.h>

#include "cdists_uniform.h"

/* Probability density function for uniform distribution  */
double unifpdf(double x, double a, double b)
{
        if (b < a) 
                error("Parameter b is smaller than a.");
        if (x < a || x > b) 
                return 0.0;

        return 1.0/(b-a);
}

/* umulative distribution function for uniform distribution */
double unifcdf(double x, double a, double b)
{
        if (b < a) 
                error("Parameter b is smaller than a.");
        if (x < a) 
                return 0.0;
        if (x > b) 
                return 1.0;

        return (x-a)/(b-a);

}

/* Inverse cumulative distribution function of uniform distribution */
double unifinv(double p, double a, double b)
{
        if (b < a) 
                error("Parameter b is smaller than a.");
        return p*(b-a) + a;

}

/* Random number generation of unbiform distribution */
double* unifrnd(unsigned n, double a, double b)
{
        if (b < a) 
                error("Parameter b is smaller than a.");

        double *arr = calloc(n, sizeof(double));

        for (int i=0; i<n; i++) {
                arr[i] = unifinv((double)rand()/(double)RAND_MAX, a, b); 
        }
        return arr;

}
