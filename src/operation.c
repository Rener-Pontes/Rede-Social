#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./lib/operation.h"
#include "./lib/graph.h"

#define STANDARD_USER_NAME_LENGTH 20
#define EQUAL_NAMES 0

int compare_users(const void *a, const void *b) {
	vertex *v1 = (vertex*)a;
	vertex *v2 = (vertex*)b;

	return v1->edges_amount - v2->edges_amount;
}

int cmpName(void *nameUser1, void *nameUser2) {
	char *name1 = (char*)nameUser1;
	char *name2 = (char*)nameUser2;

	return strcmp(name1, name2);
}

void userGetFollowers(graph *grp, user user_name) {
	int amountFollower = 0,
		labelUser = graphFindVertexLabelByValue(grp, user_name, cmpName);
	vertex *vertexUser = graphFindVertex(grp, labelUser),
		   *vertexAux = grp->first_vertex;
	edge *ed = NULL;

	printf("[%s]\n", ((user)user_name));
	while (vertexAux) {
		ed = vertexAux->first_edge;
		while (ed) {
			if (ed->destiny == vertexUser) {
				amountFollower++;
				printf("|> %s\n", ((user)vertexAux->value));
				break;
			}
			ed = ed->next_edge;
		}

		vertexAux = vertexAux->next_vertex;
	}

	printf("SEGUIDORES: %d\n", amountFollower);
}

void userGetFollowing(graph *grp, user user_name) {
	vertex *vertexUser = NULL;
	edge *ed = NULL;
	int labelUser;

	labelUser = graphFindVertexLabelByValue(grp, user_name,  cmpName);
	if (vertexUser = graphFindVertex(grp, labelUser)) {
		printf("[%s]\n", (char*)vertexUser->value);
		ed = vertexUser->first_edge;
		while (ed) {
			printf("|> %s\n", (char*)ed->destiny->value);
			ed = ed->next_edge;
		}
		printf("SEGUIDOS: %d\n", vertexUser->edges_amount);
	}
	else printf("! USUÁRIO NÃO ENCONTRADO !\n");
}

void userListNoFollowing(graph *grp) {
	vertex *vert = NULL;
	user user_name = NULL;

	assert(grp != NULL);

	vert = grp->first_vertex;

	while (vert) {
		if (vert->edges_amount == 0) {
			user_name = (user)vert->value;
			printf("%s\n", user_name);
		}

		vert = vert->next_vertex;
	}
}

void userListByFollowersAmount(graph *grp) {
	vertex **vert_array = NULL, *vert = NULL;
	user user_name = NULL;

	assert(grp != NULL);

	vert_array = calloc(grp->vertex_amount, sizeof(vertex*));
	vert = grp->first_vertex;

	for (int i = 0; i < grp->vertex_amount; i++) {
		vert_array[i] = vert;
		vert = vert->next_vertex;
	}

	qsort(vert_array, grp->vertex_amount, sizeof(vertex*), compare_users);

	for (int i = 0; i < grp->vertex_amount; i++) {
		user_name = (user)vert_array[i]->value;
		printf("%s: %d seguidores.\n", user_name, vert_array[i]->edges_amount);
	}
}

void userCreate(graph *grp){
	user newUser = malloc(sizeof(user));
	printf("NOme do novo usuário: ");
	scanf("%s", newUser);
	graphInsertVertex(grp, newUser);
}

void userFollow(graph *grp, user first_user, user second_user){
	int u1, u2;
	u1 = graphFindVertexLabelByValue(grp, first_user, cmpName);
	u2 = graphFindVertexLabelByValue(grp, second_user, cmpName);
	graphInsertEdge(grp, u1, u2);
}

void userUnfollow(graph *grp, user first_user, user second_user){
	int u1, u2;
	u1 = graphFindVertexLabelByValue(grp, first_user, cmpName);
	u2 = graphFindVertexLabelByValue(grp, second_user, cmpName);
	graphRemoveEdge(grp, u1, u2);
}

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

void run() {
	int networkOnline = ONLINE, i, labelUser;
	char option,
		 teste[][STANDARD_USER_NAME_LENGTH] = {{"rener"}, {"yuri"}, {"yago"}, {"elias"}};
	user userName = malloc(sizeof(char)), userName2 = malloc(sizeof(char));
	vertex *vertexUser = NULL;
	graph *grp = graphAlloc();

	for (i = 0; i < 4; ++i)
		graphInsertVertex(grp, teste[i]);

	graphInsertEdge(grp, 0, 1);
	graphInsertEdge(grp, 0, 2);
	graphInsertEdge(grp, 2, 3);
	graphInsertEdge(grp, 1, 2);

	printf("\e[1J\e[1H_______________________  BEM-VINDO AO GRAFNET  _______________________\n\n");

	do {
		printf(
		"----------------------------------------------------------------------\n"
		" [ 1 ] Selecionar um usuário e listar os seus seguidores\n"
		" [ 2 ] Selecionar um usuário e listar os seus seguidos\n"
		" [ 3 ] Listar usuários que não são seguidos por ninguém\n"
		" [ 4 ] Listar usuários que não seguem ninguém\n"
		" [ 5 ] Listar todos os usuários ordenados por n° seguidores\n"
		" [ 6 ] Inserir um novo usuário\n"
		" [ 7 ] Selecionar dois usuários e fazer o primeiro seguir o segundo\n"
		" [ 8 ] Selecionar dois usuários e fazer o primeiro deixar de seguir o segundo\n"
		" [ 9 ] Sair\n"
		"----------------------------------------------------------------------\n+> "
		);

		scanf(" %c", &option);
		printf("\e[1J\e[1H");
		switch (option) {
			case '1':
			printf("\nUsuário: ");
			scanf("%s", userName);
			userGetFollowers(grp, userName);
			break;
			case '2':
			printf("\nUsuário: ");
			scanf("%s", userName);
			userGetFollowing(grp, userName);
			break;
			case '3':
			//userListNoFollowers(graph *grp);
			break;
			case '4':
			userListNoFollowing(grp);
			break;
			case '5':
			//userListByFollowersAmount(graph *grp);
			break;
			case '6':
			userCreate(grp);
			break;
			case '7':
			printf("\nQual o usuário?: ");
			scanf("%s", userName);
			printf("\nQuem você quer que ele siga?: ");
			scanf("%s", userName2);
			userFollow(grp, userName, userName2);
			break;
			case '8':
			printf("\nQual o usuário?: ");
			scanf("%s", userName);
			printf("\nQuem você quer que ele deixe de siguir?: ");
			scanf("%s", userName2);
			userUnfollow(grp, userName, userName2);
			break;
			case '9':
			networkOnline = OFFLINE;
			break;
			default:
				printf("! OPÇÃO INVÁLIDA !\n");
		}
	} while (networkOnline);
}
