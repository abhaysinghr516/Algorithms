#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int vertex;
    struct node* next;
} node;

typedef struct graph {
    int num_vertices;
    int* visited;
    node** adj_list;
} graph;

node* create_node(int vertex);
graph* create_graph(int vertices);
void add_edge(graph* g, int src, int dest);
void bfs(graph* g, int start_vertex);

int main() {
    graph* g = create_graph(6);

    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 3);
    add_edge(g, 1, 4);
    add_edge(g, 2, 4);
    add_edge(g, 3, 5);
    add_edge(g, 4, 5);

    bfs(g, 0);

    return 0;
}

node* create_node(int vertex) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->vertex = vertex;
    new_node->next = NULL;
    return new_node;
}

graph* create_graph(int vertices) {
    graph* g = (graph*)malloc(sizeof(graph));
    g->num_vertices = vertices;
    g->adj_list = (node**)malloc(vertices * sizeof(node*));
    g->visited = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        g->adj_list[i] = NULL;
        g->visited[i] = 0;
    }

    return g;
}

void add_edge(graph* g, int src, int dest) {
    node* new_node = create_node(dest);
    new_node->next = g->adj_list[src];
    g->adj_list[src] = new_node;

    new_node = create_node(src);
    new_node->next = g->adj_list[dest];
    g->adj_list[dest] = new_node;
}

void bfs(graph* g, int start_vertex) {
    node** queue = (node**)malloc(g->num_vertices * sizeof(node*));
    int front = 0;
    int back = 0;

    g->visited[start_vertex] = 1;
    queue[back++] = g->adj_list[start_vertex];

    while (front != back) {
        node* current_vertex = queue[front++];
        printf("Visited %d\n", current_vertex->vertex);

        node* temp = g->adj_list[current_vertex->vertex];
        while (temp) {
            int adj_vertex = temp->vertex;
            if (!g->visited[adj_vertex]) {
                g->visited[adj_vertex] = 1;
                queue[back++] = g->adj_list[adj_vertex];
            }
            temp = temp->next;
        }
    }
}
