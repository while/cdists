/* 
 * CDISTS Exponential distribution
 * by Vilhelm von Ehrenheim
 *
 */
#include <stdlib.h>
#include <limits.h>
#include <math.h>

#include "cdists_exponential.h"

/* Probability density function for exponential distribution  */
double exppdf(double x, double lambda)
{
        if (lambda < 0) 
                error("Parameter lambda is smaller than 0.");
        if (x < 0) 
                return 0.0;

        return lambda * exp(-lambda * x);
}

/* umulative distribution function for exponential distribution */
double expcdf(double x, double lambda)
{
        if (lambda < 0) 
                error("Parameter lambda is smaller than 0.");
        if (x < 0) 
                return 0.0;

        return 1 - exp(-lambda * x);
}

/* Inverse cumulative distribution function of exponential distribution */
double expinv(double p, double lambda)
{
        if (lambda < 0) 
                error("Parameter lambda is smaller than 0.");
        return -log(1 - p) / lambda;

}

/* Random number generation of exponential distribution */
double* exprnd(unsigned n, double lambda)
{
        if (lambda < 0) 
                error("Parameter b is smaller than a.");

        double *arr = calloc(n, sizeof(double));

        for (int i = 0; i < n; i++) {
                arr[i] = expinv((double)rand() / (double)RAND_MAX, lambda); 
        }
        return arr;

}

