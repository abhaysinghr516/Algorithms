class UnionFind {
    private int[] parent;
    private int[] rank;

    public UnionFind(int n) {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    public int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    public void union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) {
            return;
        }

        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

public class Main {
    public static void main(String[] args) {
        int n = 6; 
        UnionFind uf = new UnionFind(n);

        uf.union(0, 1);
        uf.union(1, 2);
        uf.union(3, 4);
        uf.union(4, 5);

        System.out.println("Are 0 and 2 in the same set? " + (uf.find(0) == uf.find(2))); // Should be true
        System.out.println("Are 1 and 5 in the same set? " + (uf.find(1) == uf.find(5))); // Should be false
    }
}