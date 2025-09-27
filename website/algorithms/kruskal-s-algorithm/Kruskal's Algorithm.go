package main

import (
    "fmt"
    "sort"
)

type Edge struct {
    src, dest, weight int
}

type Graph struct {
    vertices, edges int
    edgeList        []Edge
}

func (g *Graph) addEdge(src, dest, weight int) {
    g.edgeList = append(g.edgeList, Edge{src, dest, weight})
}

func (g *Graph) kruskalMST() []Edge {
    // Sort the edges by weight in ascending order
    sort.Slice(g.edgeList, func(i, j int) bool {
        return g.edgeList[i].weight < g.edgeList[j].weight
    })

    parent := make([]int, g.vertices)
    for i := 0; i < g.vertices; i++ {
        parent[i] = i
    }

    var result []Edge
    for _, edge := range g.edgeList {
        srcParent := g.find(parent, edge.src)
        destParent := g.find(parent, edge.dest)

        if srcParent != destParent {
            result = append(result, edge)
            parent[srcParent] = destParent
        }
    }

    return result
}

func (g *Graph) find(parent []int, vertex int) int {
    if parent[vertex] != vertex {
        return g.find(parent, parent[vertex])
    }
    return vertex
}

func main() {
    g := Graph{
        vertices: 4,
        edges:    5,
    }
    g.addEdge(0, 1, 10)
    g.addEdge(0, 2, 6)
    g.addEdge(0, 3, 5)
    g.addEdge(1, 3, 15)
    g.addEdge(2, 3, 4)

    mst := g.kruskalMST()

    fmt.Println("Edges in Minimum Spanning Tree:")
    for _, edge := range mst {
        fmt.Printf("Edge: %d - %d, Weight: %d\n", edge.src, edge.dest, edge.weight)
    }
}
