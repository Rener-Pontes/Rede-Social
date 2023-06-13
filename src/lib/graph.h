typedef struct graph graph;
typedef struct vertex vertex;
typedef struct edge edge;


struct graph {
	int 	vertex_amount;
	vertex *first_vertex;
};
struct vertex {
	void   *value;
	int 	label;
	int 	edges_amount;
	vertex *next_vertex;
	edge   *first_edge;
};
struct edge {
	int 	label;
	vertex *origin;
	vertex *destiny;
	edge   *next_edge;
};


graph  *graphAlloc();
void	graphFree(graph *grp);
void graphPrint(vertex *vtx);
