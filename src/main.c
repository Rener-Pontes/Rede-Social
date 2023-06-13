#include <stdio.h>
#include <stdlib.h>
#include "./lib/graph.h"

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

int main() {
	graph *grp = graphAlloc();
	vertex *vert = NULL;
	int n[] = {10, 20, 30, 40, 50},
		*p = NULL;

	for (int i = 0; i < 5; i++)
		graphInsertVertex(grp, &n[i]);


	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			if (i != j) graphInsertEdge(grp, i, j);

	print(grp);
	graphRemoveEdge(grp, 0, 3);
	graphRemoveVertex(grp, 3);
	print(grp);

	graphFree(grp);

	return 0;
}
