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

int cmp(void *a, void *b){
	user *u1 = (user *)a;
	user *u2 = (user *)b;
}

void userCreate(graph *grp){
	vertex *v = NULL;
	user newUser;
	printf("NOme do novo usuário: ");
	scanf("%s", newUser);
	graphInsertVertex(grp, *newUser);
}

void userFollow(graph *grp, user first_user, user second_user){
	int u1, u2;
	u1 = graphFindVertexLabelByValue(grp, first_user);
	u2 = graphFindVertexLabelByValue(grp, second_user);
	graphInsertEdge(grp, u1, u2);
}

void userUnfollow(graph *grp, user first_user, user second_user){
	int u1, u2;
	u1 = graphFindVertexLabelByValue(grp, first_user);
	u2 = graphFindVertexLabelByValue(grp, second_user);
	graphRemoveEdge(grp, u1, u2);
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

}
