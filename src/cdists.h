#ifndef CDISTS_H
#define CDISTS_H

/* MACROS */
#define SQR(x) (x)*(x)

double _rnd();

// Normal distribution
double unifpdf(double x, double a, double b);
double unifcdf(double x, double a, double b);
double unifinv(double p, double a, double b);
double* unifrnd(unsigned n, double a, double b);

// Normal distribution
double normpdf(double x, double mu, double sig);
double normcdf(double x, double mu, double sig);
double norminv(double p, double mu, double sig);
double* normrnd(unsigned n, double mu, double sig);

// Exponential distribution
double exppdf(double x, double lambda);
double expcdf(double x, double lambda);
double expinv(double p, double lambda);
double* exprnd(unsigned n, double lambda);

// Geometric distribution
double geompdf(unsigned k, double p);
double geomcdf(unsigned k, double p);
double geominv(double q, double p);
double* geomrnd(unsigned n, double p);

void error(char* msg);

#endif /* CDISTS_H */
