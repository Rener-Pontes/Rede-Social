#include "graph.h"

#define STANDARD_USER_NAME_LENGTH 20
#define EQUAL_NAMES 0

typedef char* user;

static void userGetFollowers(graph *grp, user user_name);
static void userGetFollowing(graph *grp, user user_name);

static void userListNoFollowers(graph *grp);
static void userListNoFollowing(graph *grp);
static void userListByFollowersAmount(graph *grp);

static void userCreate(graph *grp);

static void userFollow(graph *grp, user first_user, user second_user);
static void userUnfollow(graph *grp, user first_user, user second_user);

void run();
