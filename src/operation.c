#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./lib/operation.h"
#include "./lib/graph.h"

#define STANDARD_USER_NAME_LENGTH 20
#define EQUAL_NAMES 0

int cmpName(void *nameUser1, void *nameUser2) {
	char *name1 = (char*)nameUser1;
	char *name2 = (char*)nameUser2;

	return strcmp(name1, name2);
}

void userGetFollowers(graph *grp, user user_name) {

}

void userGetFollowing(graph *grp, user user_name) {
	vertex *vertexUser = NULL;
	edge *ed = NULL;
	int labelUser;

	labelUser = graphFindVertexLabelByValue(grp, user_name,  cmpName);
	if (vertexUser = graphFindVertex(grp, labelUser)) {
		printf("[%s] SEGUIDOS: %d\n", (char*)vertexUser->value, vertexUser->edges_amount);
		ed = vertexUser->first_edge;
		while (ed) {
			printf("|> %s\n", (char*)ed->destiny->value);
			ed = ed->next_edge;
		}
	}
	else printf("! USUÁRIO NÃO ENCONTRADO !\n");
}

void userListNoFollowers(graph *grp) {

}

void userListNoFollowing(graph *grp) {

}

void userListByFollowersAmount(graph *grp) {

}

void userCreate(graph *grp) {

}

void userFollow(graph *grp, user first_user, user second_user) {

}

void userUnfollow(graph *grp, user first_user, user second_user) {

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
	user userName = malloc(sizeof(char));
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
			//userGetFollowers(graph *grp, user user_name);
			break;
			case '2':
			printf("\nUsuário: ");
			scanf("%s", userName);
			if ((labelUser = graphFindVertexLabelByValue(grp, userName, cmpName)) != -1) {
				vertexUser = graphFindVertex(grp, labelUser);
				userGetFollowing(grp, vertexUser->value);
			}
			else printf("! USUÁRIO NÃO ENCONTRADO !\n");
			break;
			case '3':
			//userListNoFollowers(graph *grp);
			break;
			case '4':
			//userListNoFollowing(graph *grp);
			break;
			case '5':
			//userListByFollowersAmount(graph *grp);
			break;
			case '6':
			//userCreate(graph *grp);
			break;
			case '7':
			//userFollow(graph *grp, user first_user, user second_user);
			break;
			case '8':
			//userUnfollow(graph *grp, user first_user, user second_user);
			break;
			case '9':
			networkOnline = OFFLINE;
			break;
			default:
				printf("! OPÇÃO INVÁLIDA !\n");
		}
	} while (networkOnline);
}
