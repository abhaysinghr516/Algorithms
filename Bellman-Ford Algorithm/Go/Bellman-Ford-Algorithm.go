package main

import (
	"fmt"
	"math"
)

type Edge struct {
	src, dest, weight int
}

func BellmanFord(vertices int, edges []Edge, start int) ([]int, []int) {
	distances := make([]int, vertices)
	predecessors := make([]int, vertices)

	for i := 0; i < vertices; i++ {
		distances[i] = math.MaxInt32
		predecessors[i] = -1
	}
	distances[start] = 0

	for i := 1; i <= vertices-1; i++ {
		for _, edge := range edges {
			if distances[edge.src]+edge.weight < distances[edge.dest] {
				distances[edge.dest] = distances[edge.src] + edge.weight
				predecessors[edge.dest] = edge.src
			}
		}
	}

	for _, edge := range edges {
		if distances[edge.src]+edge.weight < distances[edge.dest] {
			fmt.Println("Negative weight cycle detected.")
			return nil, nil
		}
	}

	return distances, predecessors
}

func main() {
	vertices := 5
	edges := []Edge{
		{0, 1, -1},
		{0, 2, 4},
		{1, 2, 3},
		{1, 3, 2},
		{1, 4, 2},
		{3, 2, 5},
		{3, 1, 1},
		{4, 3, -3},
	}

	start := 0
	distances, predecessors := BellmanFord(vertices, edges, start)

	if distances != nil && predecessors != nil {
		fmt.Println("Distances:", distances)
		fmt.Println("Predecessors:", predecessors)
	}
}
