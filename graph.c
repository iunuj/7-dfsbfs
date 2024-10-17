#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "list.h"

GraphMatType* create_mat_graph() {
	return (GraphMatType*)malloc(sizeof(GraphMatType));
}

void destroy_mat_graph(GraphMatType* g) {
	free(g);
}

void init_mat_graph(GraphMatType* g) {
	for (int i = 0; i < MAX_VERTICES; i++)
		g->vertex_list[i] = 0;
	for (int i = 0; i < MAX_VERTICES; i++)
		for (int j = 0; j < MAX_VERTICES; j++)
			g->adj_mat[i][j] = 0;
}

void insert_vertex_mat_graph(GraphMatType* g, int v) {
	if (g->vertex_list[v] == 1) {
		fprintf(stderr, "%d exist already\n", v);
		return;
	}
	if (v > (MAX_VERTICES - 1)) {
		fprintf(stderr, "Over number of vertex\n");
		return;
	}
	g->vertex_list[v] = 1;
}

void insert_edge_mat_graph(GraphMatType* g, int s, int e) {

	if (g->vertex_list[s] == 0 || g->vertex_list[e] == 0) {
		fprintf(stderr, " edge insert fail: vertex %d or %d dost not exist\n", s, e);
		return;
	}
	g->adj_mat[s][e] = 1;
	g->adj_mat[e][s] = 1;
}

void delete_vertex_mat_graph(GraphMatType* g, int v) {
	for (int i = 0; i < MAX_VERTICES; i++) {
		if (g->adj_mat[v][i] == 1) {
			fprintf(stderr, " Fail vertex delete: vetex %d has edge to %d\n", v, i);
			return;
		}
	}
	g->vertex_list[v] = 0;
}

void delete_edge_mat_graph(GraphMatType* g, int s, int e) {
	if (g->adj_mat[s][e] != 1 || g->adj_mat[e][s] != 1) {
		fprintf(stderr, "Edge delete fail: edge dose not exist (%d,%d)\n", s, e);
		return;
	}
	g->adj_mat[s][e] = g->adj_mat[e][s] = 0;
}

void print_adj_mat(GraphMatType* g) {
	printf("\n인접행렬 출력\n");
	printf("     ");
	for (int i = 0; i < MAX_VERTICES; i++) {
		if (g->vertex_list[i] == 1) printf(" %02d ", i);
	}
	printf("\n");
	for (int i = 0; i < MAX_VERTICES; i++) {
		if (g->vertex_list[i] == 1) printf("-----");
	}
	printf("\n");
	for (int i = 0; i < MAX_VERTICES; i++) {
		if (g->vertex_list[i] == 0) continue;
		else printf(" %02d: ", i);
		for (int j = 0; j < MAX_VERTICES; j++)
			if (g->vertex_list[j] == 1) printf(" %02d ", g->adj_mat[i][j]);
		printf("\n");
	}
}


GraphListType* create_list_graph() {
	return (GraphListType*)malloc(sizeof(GraphListType));
}
void destroy_list_graph(GraphListType* g) {
	free(g);
}
void init_list_graph(GraphListType* g) {

	for (int i = 0; i < MAX_VERTICES; i++) {
		init_Dlist(&(g->adj_list[i]));
		g->adj_list[i].data = -1;
	}
}
void insert_vertex_list_graph(GraphListType* g, int v) {
	g->adj_list[v].data = 1;
}

void insert_edge_list_graph(GraphListType* g, int s, int e) {
	/* search_DListf(&(g->adj_list[s]), e)*/
	insert_Dlist(&(g->adj_list[s]), e);
	insert_Dlist(&(g->adj_list[e]), s);
}

void delete_vertex_list_graph(GraphListType* g, int v) {
	if (g->adj_list[v].rlink != &(g->adj_list[v])) {
		fprintf(stderr, " vertex delete fail: %d has edge\n", v);
		return;
	}
	g->adj_list[v].data = 0;
}

void delete_edge_list_graph(GraphListType* g, int s, int e) {
	DListNode* v;

	v = search_Dlist(&(g->adj_list[s]), e);
	if (v != NULL) delete_Dlist(&(g->adj_list[s]), v);
	v = search_Dlist(&(g->adj_list[e]), s);
	if (v != NULL) delete_Dlist(&(g->adj_list[e]), v);
}

void print_adj_list(GraphListType* g) {
	printf("\n입접 리스트 출력\n");
	for (int i = 0; i <= MAX_VERTICES; i++) {
		if (g->adj_list[i].data == 1) {
			printf(" Vertex %d ", i);
			print_Dlist(&(g->adj_list[i]));
		}
	}
}