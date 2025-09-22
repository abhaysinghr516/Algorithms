package main

import (
	"fmt"
	"container/list"
)

type Graph struct {
	vertices int
	adj_list []list.List
}

func NewGraph(vertices int) *Graph {
	g := &Graph{
		vertices: vertices,
		adj_list: make([]list.List, vertices),
	}
	return g
}

func (g *Graph) AddEdge(src, dest int) {
	g.adj_list[src].PushBack(dest)
	g.adj_list[dest].PushBack(src)
}

func (g *Graph) BFS(start_vertex int) {
	visited := make([]bool, g.vertices)
	queue := list.New()

	visited[start_vertex] = true
	queue.PushBack(start_vertex)

	for queue.Len() > 0 {
		current_vertex := queue.Front()
		queue.Remove(current_vertex)
		fmt.Printf("Visited %d\n", current_vertex.Value)

		for e := g.adj_list[current_vertex.Value.(int)].Front(); e != nil; e = e.Next() {
			adj_vertex := e.Value.(int)
			if !visited[adj_vertex] {
				visited[adj_vertex] = true
				queue.PushBack(adj_vertex)
			}
		}
	}
}

func main() {
	g := NewGraph(6)

	g.AddEdge(0, 1)
	g.AddEdge(0, 2)
	g.AddEdge(1, 3)
	g.AddEdge(1, 4)
	g.AddEdge(2, 4)
	g.AddEdge(3, 5)
	g.AddEdge(4, 5)

	g.BFS(0)
}
