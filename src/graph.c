#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "./lib/graph.h"

graph  *graphAlloc() {
	graph *grp = malloc(sizeof(graph));

	assert(grp != NULL);

	grp->vertex_amount = 0;
	grp->first_vertex = NULL;
	grp->last_vertex = NULL;

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

void	graphFree(graph *grp) {
	assert(grp != NULL);
	vertexFree(grp->first_vertex);
	free(grp);
}



void   *graphFindVertex(graph *grp, int vertex_label) {
	vertex *vert = NULL;

	assert(grp != NULL);

	vert = grp->first_vertex;
	while (vert) {
		if (vert->label == vertex_label)
			return vert;
		
		vert = vert->next_vertex;
	}

	return NULL;	
}

void 	graphInsertVertex(graph *grp, void *value) {
	vertex *new_vert = NULL;

	assert(grp != NULL);

	new_vert = malloc(sizeof(vertex));

	assert(new_vert != NULL);

	new_vert->value = value;
	new_vert->label = grp->vertex_amount++;
	new_vert->edges_amount = 0;
	new_vert->first_edge = NULL;
	new_vert->next_vertex = NULL;

	if (grp->first_vertex == NULL)
		grp->first_vertex = new_vert;
	else 
		grp->last_vertex->next_vertex = new_vert;
	
	grp->last_vertex = new_vert;
}

void	graphRemoveVertex(graph *grp, int vertex_label) {
	vertex *vert = NULL, *prev_vert = NULL;

	assert(grp != NULL);

	vert = grp->first_vertex;

	while (vert) {
		if (vert->label != vertex_label) {
			prev_vert = vert;
			vert = vert->next_vertex;
			continue;
		}

		edgeFree(vert->first_edge);

		/*TODO a way to remove all the edges that references to this vertex*/

		if (prev_vert == NULL) 
			grp->first_vertex = vert->next_vertex;
		else
			prev_vert->next_vertex = vert->next_vertex;
		
		grp->vertex_amount--;

		free(vert);
	}
}