#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "cdists.h"

int main(int argc, char *argv[]) {
        int n;
        double p;

        sscanf(argv[1], "%d", &n);
        sscanf(argv[2], "%lf", &p);

        /* Set truely random seed */
        int rint;
        FILE *fp;
        fp = fopen("/dev/urandom", "r");
        fread(&rint, 1, sizeof(int), fp);
        fclose(fp);

        srand(rint);

        double *arr = geomrnd(n, p);
        for (int i=0; i<n; i++) {
                printf("%.20f\n", arr[i]);
        }
        free(arr);
}
