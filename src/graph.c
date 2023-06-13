#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "./lib/graph.h"

graph *graphAlloc() {
	graph *grp = malloc(sizeof(graph));

	assert(grp != NULL);

	grp->first_vertex = NULL;
	grp->vertex_amount = 0;

	return grp;
}

void edgeFree(edge *first_edge) {
	edge *ed = NULL, *aux_ed = NULL;

	ed = first_edge;
	while (ed) {
		aux_ed = ed;
		ed = ed->next_edge;
		free(aux_ed);
	}
}

void vertexFree(vertex *first_vertex) {
	vertex *vert = NULL, *aux_vert = NULL;

	vert = first_vertex;
	while (vert) {
		edgeFree(vert->first_edge);
		aux_vert = vert;
		vert = vert->next_vertex;

		free(aux_vert);
	}
}

void graphFree(graph *grp) {
	assert(grp != NULL);
	vertexFree(grp->first_vertex);
	free(grp);
}

void graphShowUser(vertex *vtx) {
	printf("%s", (char*)vtx->value);
}
