/* 
 * CDISTS Normal distribution
 * by Vilhelm von Ehrenheim
 *
 */
#include <stdlib.h>
#include <limits.h>
#include <math.h>

#include "cdists_normal.h"

/* Probability density function for normal distribution  */
double normpdf(double x, double mu, double sig)
{
        if (sig < 0) 
                error("Parameter sig is smaller than 0.");

        return (0.3989422804014327/sig)*exp(-0.5*SQR(x-mu)/SQR(sig));
}

/* Cumulative distribution function for normal distribution */
double normcdf(double x, double mu, double sig)
{
        if (sig < 0) 
                error("Parameter sig is smaller than 0.");
        if (x > 3*sig) 
                return 0.5*erfc(-0.7071067811865475*(x - mu)/sig);

        return 0.5*(1 + erf(0.7071067811865475*(x - mu)/sig));
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
