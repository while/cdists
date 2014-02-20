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


/***** Exponential distribution *****/
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


/***** Exponential distribution *****/
/* Probability density function for normal distribution  */
double normpdf(double x, double mu, double sig)
{
        if (sig < 0) 
                error("Parameter mu is smaller than 0.");
        return 0.0; // TODO

}

/* umulative distribution function for normal distribution */
double normcdf(double x, double mu, double sig)
{
        if (sig < 0) 
                error("Parameter sig is smaller than 0.");
        if (x < 0) 
                return 0.0;

        return 0.0; // TODO
}

/* Inverse cumulative distribution function of normal distribution */
double norminv(double p, double mu, double sig)
{
        if (sig < 0) 
                error("Parameter sig is smaller than 0.");
        return 0.0; // TODO

}

/* Help function generating std normal deviate using the ratio of uniforms */
double _stdnormrnd() {
        double u,v,x,y,q;
        do {
                u = _rnd();
                v = 1.7156*(_rnd() - 0.5);
                x = u - 0.449871;
                y = fabs(v) + 0.386595;
                q = x*x + y*(0.19600*y - 0.25472*x);
        } while (q > 0.27597 && (q > 0.27846 || SQR(v) > -4*log(u)*SQR(u)));

        return v/u;
}

/* Random number generation of normal distribution */
double* normrnd(unsigned n, double mu, double sig)
{
        if (sig <= 0) 
                error("Parameter sig has to be larger than 0.");

        double *arr = calloc(n, sizeof(double));

        for (int i = 0; i < n; i++) {
                arr[i] = mu + _stdnormrnd()*sig; 
        }
        return arr;

}


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
