#ifndef CDISTS_H
#define CDISTS_H

/* MACROS */
#define SQR(x) (x)*(x)

#include "cdists_normal.h"
#include "cdists_uniform.h"
#include "cdists_exponential.h"
#include "cdists_geometric.h"
#include "cdists_gamma.h"

/* Definitions */
double rnd();
void error(char* msg);

#endif /* CDISTS_H */
