class Graph:
    def __init__(self, vertices):
        self.vertices = vertices
        self.adj_list = [[] for _ in range(vertices)]
        self.visited = [False] * vertices

    def add_edge(self, src, dest):
        self.adj_list[src].append(dest)
        self.adj_list[dest].append(src)

    def dfs(self, vertex):
        self.visited[vertex] = True
        print(f"Visited {vertex}")

        for adj_vertex in self.adj_list[vertex]:
            if not self.visited[adj_vertex]:
                self.dfs(adj_vertex)

g = Graph(6)

g.add_edge(0, 1)
g.add_edge(0, 2)
g.add_edge(1, 3)
g.add_edge(1, 4)
g.add_edge(2, 4)
g.add_edge(3, 5)
g.add_edge(4, 5)

g.dfs(0)
