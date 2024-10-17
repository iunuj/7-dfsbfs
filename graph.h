#pragma once
#include "list.h"

#define MAX_VERTICES 10

typedef struct {
	int vertex_list[MAX_VERTICES];
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphMatType;

typedef struct {
	DListNode adj_list[MAX_VERTICES];
}GraphListType;

extern GraphMatType* create_mat_graph();
extern void destroy_mat_graph(GraphMatType* g);
extern void init_mat_graph(GraphMatType* g);
extern void insert_vertex_mat_graph(GraphMatType* g, int v);
extern void insert_edge_mat_graph(GraphMatType* g, int s, int e);
extern void delete_vertex_mat_graph(GraphMatType* g, int v);
extern void delete_edge_mat_graph(GraphMatType* g, int s, int e);
extern void print_adj_mat(GraphMatType* g);

extern GraphListType* create_list_graph();
extern void destroy_list_graph(GraphListType* g);
extern void init_list_graph(GraphListType* g);
extern void insert_vertex_list_graph(GraphListType* g, int v);
extern void insert_edge_list_graph(GraphListType* g, int s, int e);
extern void delete_vertex_list_graph(GraphListType* g, int v);
extern void delete_edge_list_graph(GraphListType* g, int s, int e);
extern void print_adj_list(GraphListType* g);