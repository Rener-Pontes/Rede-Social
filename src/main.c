#include <stdio.h>
#include <stdlib.h>
#include "./lib/operation.h"

/*
void print(graph *grp) {
	vertex *vert = NULL;
	edge *ed = NULL;

	vert = grp->first_vertex;
	printf("Grafo: ->\n");
	while (vert) {
		printf("    %d:", vert->label);

		ed = vert->first_edge;
		while (ed) {
			printf("(%d)", ed->destiny->label);
			ed = ed->next_edge;
		}
		printf("\n");
		vert = vert->next_vertex;
	}
}
*/

int main() {
	run();
	return 0;
}
