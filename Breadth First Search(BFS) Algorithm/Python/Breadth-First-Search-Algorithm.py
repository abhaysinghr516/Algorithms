from collections import deque

class Graph:
    def __init__(self, vertices):
        self.vertices = vertices
        self.adj_list = [[] for _ in range(vertices)]

    def add_edge(self, src, dest):
        self.adj_list[src].append(dest)
        self.adj_list[dest].append(src)

    def bfs(self, start_vertex):
        visited = [False] * self.vertices
        queue = deque([start_vertex])

        visited[start_vertex] = True

        while queue:
            current_vertex = queue.popleft()
            print("Visited", current_vertex)

            for adj_vertex in self.adj_list[current_vertex]:
                if not visited[adj_vertex]:
                    visited[adj_vertex] = True
                    queue.append(adj_vertex)

g = Graph(6)

g.add_edge(0, 1)
g.add_edge(0, 2)
g.add_edge(1, 3)
g.add_edge(1, 4)
g.add_edge(2, 4)
g.add_edge(3, 5)
g.add_edge(4, 5)

g.bfs(0)
