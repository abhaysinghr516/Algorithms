#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int dest;
    struct Node* next;
} Node;

typedef struct Graph {
    int vertices;
    Node** adj_list;
    bool* visited;
} Graph;

Node* create_node(int dest) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->dest = dest;
    new_node->next = NULL;
    return new_node;
}

Graph* create_graph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->adj_list = (Node**)calloc(vertices, sizeof(Node*));
    graph->visited = (bool*)calloc(vertices, sizeof(bool));
    return graph;
}

void add_edge(Graph* graph, int src, int dest) {
    Node* new_node = create_node(dest);
    new_node->next = graph->adj_list[src];
    graph->adj_list[src] = new_node;

    new_node = create_node(src);
    new_node->next = graph->adj_list[dest];
    graph->adj_list[dest] = new_node;
}

void dfs(Graph* graph, int vertex) {
    Node* current = graph->adj_list[vertex];
    graph->visited[vertex] = true;
    printf("Visited %d\n", vertex);

    while (current) {
        if (!graph->visited[current->dest]) {
            dfs(graph, current->dest);
        }
        current = current->next;
    }
}

int main() {
    Graph* g = create_graph(6);

    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 3);
    add_edge(g, 1, 4);
    add_edge(g, 2, 4);
    add_edge(g, 3, 5);
    add_edge(g, 4, 5);

    dfs(g, 0);

    return 0;
}
