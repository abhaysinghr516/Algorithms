package main

import (
	"fmt"
)

type Graph struct {
	vertices int
	adj_list []([]int)
	visited  []bool
}

func newGraph(vertices int) *Graph {
	return &Graph{
		vertices: vertices,
		adj_list: make([]([]int), vertices),
		visited:  make([]bool, vertices),
	}
}

func (g *Graph) addEdge(src, dest int) {
	g.adj_list[src] = append(g.adj_list[src], dest)
	g.adj_list[dest] = append(g.adj_list[dest], src)
}

func (g *Graph) dfs(vertex int) {
	g.visited[vertex] = true
	fmt.Printf("Visited %d\n", vertex)

	for _, adj_vertex := range g.adj_list[vertex] {
		if !g.visited[adj_vertex] {
			g.dfs(adj_vertex)
		}
	}
}

func main() {
	g := newGraph(6)

	g.addEdge(0, 1)
	g.addEdge(0, 2)
	g.addEdge(1, 3)
	g.addEdge(1, 4)
	g.addEdge(2, 4)
	g.addEdge(3, 5)
	g.addEdge(4, 5)

	g.dfs(0)
}
