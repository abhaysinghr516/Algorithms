def bellman_ford(graph, source):
    num_vertices = len(graph)
    distances = [float('inf')] * num_vertices
    distances[source] = 0

    for _ in range(num_vertices - 1):
        for u, v, weight in graph:
            if distances[u] != float('inf') and distances[u] + weight < distances[v]:
                distances[v] = distances[u] + weight

    for u, v, weight in graph:
        if distances[u] != float('inf') and distances[u] + weight < distances[v]:
            print("Graph contains a negative-weight cycle")
            return

    print("Vertex\tDistance from Source")
    for i in range(num_vertices):
        print(f"{i}\t{distances[i]}")

graph = [
    (0, 1, -1),
    (0, 2, 4),
    (1, 2, 3),
    (1, 3, 2),
    (1, 4, 2),
    (3, 2, 5),
    (3, 1, 1),
    (4, 3, -3)
]

bellman_ford(graph, 0)
