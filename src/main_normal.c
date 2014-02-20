#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "cdists.h"

int main(int argc, char *argv[]) {
        int n;
        double m;
        double s;

        sscanf(argv[1], "%d", &n);
        sscanf(argv[2], "%lf", &m);
        sscanf(argv[3], "%lf", &s);

        /* Set truely random seed */
        int rint;
        FILE *fp;
        fp = fopen("/dev/urandom", "r");
        fread(&rint, 1, sizeof(int), fp);
        fclose(fp);

        srand(rint);

        double *arr = normrnd(n, m, s);
        for (int i=0; i<n; i++) {
                printf("%.20f\n", arr[i]);
        }
        free(arr);
}
