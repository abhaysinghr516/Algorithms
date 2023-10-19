package main

import (
	"fmt"
	"math"
)

const V = 4
const INF = math.MaxInt32

func floydWarshall(graph [][]int) {
	dist := make([][]int, V)
	for i := 0; i < V; i++ {
		dist[i] = make([]int, V)
		copy(dist[i], graph[i])
	}

	for k := 0; k < V; k++ {
		for i := 0; i < V; i++ {
			for j := 0; j < V; j++ {
				if dist[i][k]+dist[k][j] < dist[i][j] {
					dist[i][j] = dist[i][k] + dist[k][j]
				}
			}
		}
	}

	printSolution(dist)
}

func printSolution(dist [][]int) {
	fmt.Println("Following matrix shows the shortest distances between every pair of vertices:")
	for i := 0; i < V; i++ {
		for j := 0; j < V; j++ {
			if dist[i][j] == INF {
				fmt.Printf("INF\t")
			} else {
				fmt.Printf("%d\t", dist[i][j])
			}
		}
		fmt.Println()
	}
}

func main() {
	graph := [][]int{
		{0, 5, INF, 10},
		{INF, 0, 3, INF},
		{INF, INF, 0, 1},
		{INF, INF, INF, 0},
	}

	floydWarshall(graph)
}
