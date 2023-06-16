#include "./lib/operation.h"

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
	run();
	return 0;
}
