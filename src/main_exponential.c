#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "cdists.h"

int main() {
        int n = 1000000;

        /* Set truely random seed */
        int rint;
        FILE *fp;
        fp = fopen("/dev/urandom", "r");
        fread(&rint, 1, sizeof(int), fp);
        fclose(fp);

        srand(rint);

        double *arr = exprnd(n, 0.5);
        for (int i=0; i<n; i++) {
                printf("%.20f\n", arr[i]);
        }
        free(arr);
}
