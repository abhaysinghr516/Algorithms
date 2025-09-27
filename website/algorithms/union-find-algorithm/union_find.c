#include <stdio.h>
#include <stdlib.h>

// Structure to represent a subset
struct Subset {
    int parent;
    int rank;
};

// Function to initialize subsets
void makeSet(struct Subset subsets[], int n) {
    for (int i = 0; i < n; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
}

// Find the root of a given element 'x'
int find(struct Subset subsets[], int x) {
    if (subsets[x].parent != x)
        subsets[x].parent = find(subsets, subsets[x].parent); // Path compression
    return subsets[x].parent;
}

// Union two subsets based on rank
void unionSets(struct Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (rootX != rootY) {
        if (subsets[rootX].rank < subsets[rootY].rank)
            subsets[rootX].parent = rootY;
        else if (subsets[rootX].rank > subsets[rootY].rank)
            subsets[rootY].parent = rootX;
        else {
            subsets[rootY].parent = rootX;
            subsets[rootX].rank++;
        }
    }
}

int main() {
    int n = 6; // Number of elements

    struct Subset subsets[n];
    makeSet(subsets, n);

    // Perform some union operations
    unionSets(subsets, 0, 1);
    unionSets(subsets, 1, 2);
    unionSets(subsets, 3, 4);

    // Check if elements are in the same subset
    printf("Are 0 and 2 in the same subset? %s\n", (find(subsets, 0) == find(subsets, 2)) ? "Yes" : "No");
    printf("Are 0 and 4 in the same subset? %s\n", (find(subsets, 0) == find(subsets, 4)) ? "Yes" : "No");

    return 0;
}