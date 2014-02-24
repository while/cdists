/* 
 * CDISTS
 * A simple random number generator library with distributio n functions.
 * by Vilhelm von Ehrenheim
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

#include "cdists.h"

double _rnd() 
{
        //unsigned rint;
        //FILE *fp;
        //fp = fopen("/dev/urandom", "r");
        //fread(&rint, 1, sizeof(int), fp);
        //fclose(fp);
        return (double)rand() / (double)RAND_MAX;
}

/***** Continuous Uniform Distribution  *****/


/***** Exponential distribution *****/

/***** DISCRETE DISTRIBUTIONS *****/
/***** Geometric distribution *****/
/* Probability density function for geometric distribution  */
double geompdf(unsigned k, double p)
{
        if (p <= 0 || p > 1) 
                error("Parameter lambda is smaller than 0.");
        if (k < 0) 
                return 0.0;

        return pow(1 - p, k) * p;
}

/* umulative distribution function for geometric distribution */
double geomcdf(unsigned k, double p)
{
        if (p <= 0 || p > 1) 
                error("Parameter lambda is smaller than 0.");
        if (k < 0) 
                return 0.0;

        return 1 - pow(1 - p, k);
}

/* Inverse cumulative distribution function of geometric distribution */
double geominv(double q, double p)
{
        if (p <= 0 || p > 1) 
                error("Parameter lambda is smaller than 0.");
        if (q <= 0 || q > 1) 
                error("Parameter q must be a probability.");

        unsigned k = 0;
        while (q > geomcdf(k++, p))
                continue;
        return k;
}

/* Random number generation of geometric distribution */
double* geomrnd(unsigned n, double p)
{
        if (p <= 0 || p > 1) 
                error("Parameter lambda is smaller than 0.");

        double *arr = calloc(n, sizeof(double));

        for (int i = 0; i < n; i++) {
                arr[i] = geominv((double)rand() / (double)RAND_MAX, p); 
        }
        return arr;

}




/* Simple error handling */
void error(char *msg) 
{
        fprintf(stderr, "Error: %s\n", msg);
        exit(1);
}
