#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "./lib/operation.h"

#define STANDARD_USER_NAME_LENGTH 20
#define EQUAL_NAMES 0
#define ONLINE 1
#define OFFLINE 0

int compare_users(void *a, void *b) {
	vertex *v1 = (vertex*)a;
	vertex *v2 = (vertex*)b;

	return v1->edges_amount - v2->edges_amount;
}

static void userGetFollowers(graph *grp, user user_name) {

}

static void userGetFollowing(graph *grp, user user_name) {

}

static void userListNoFollowers(graph *grp) {

}

static void userListNoFollowing(graph *grp) {
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

static void userListByFollowersAmount(graph *grp) {
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

static void userCreate(graph *grp) {

}

static void userFollow(graph *grp, user first_user, user second_user) {

}

static void userUnfollow(graph *grp, user first_user, user second_user) {

}

static void print(graph *grp) {
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
	int networkOnline = ONLINE;
	char option;

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
			//userGetFollowing(graph *grp, user user_name);
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
