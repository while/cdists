all:
	gcc -O3 -std=c99 -Wall -Werror -pedantic -lm src/main_uniform.c src/cdists.c -o bin/uniform
	gcc -O3 -std=c99 -Wall -Werror -pedantic -lm src/main_exponential.c src/cdists.c -o bin/exponential
	gcc -O3 -std=c99 -Wall -Werror -pedantic -lm src/main_normal.c src/cdists.c -o bin/normal
	gcc -O3 -std=c99 -Wall -Werror -pedantic -lm src/main_geometric.c src/cdists.c -o bin/geometric
