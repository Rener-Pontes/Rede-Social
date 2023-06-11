#include <stdio.h>
#include <stdlib.h>

#include "./lib/graph.h"

int main() {
	graph *grp = graphAlloc();
	vertex *vert = NULL;
	int n[] = {10, 20, 30, 40, 50},
		*p = NULL;

	for (int i = 0; i < 5; i++) 
		graphInsertVertex(grp, &n[i]);
	
	vert = grp->first_vertex;

	for (int i = 0; i < 5; i++) {
		p = (int*) vert->value;
		printf("%d  ", *p);
		vert = vert->next_vertex;
	}
	printf("\n");

	graphRemoveVertex(grp, 3);
	
	vert = grp->first_vertex;

	for (int i = 0; i < grp->vertex_amount; i++) {
		p = (int*) vert->value;
		printf("%d  ", *p);
		vert = vert->next_vertex;
	}
	printf("\n");

}
