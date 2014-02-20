#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "cdists.h"

int main(int argc, char *argv[]) {
        int n;
        sscanf(argv[1], "%d", &n);

        for (int i=0; i<n; i++) {
                printf("%.20f\n", _rnd());
        }
}
