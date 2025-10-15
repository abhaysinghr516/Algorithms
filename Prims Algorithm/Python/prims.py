V = 5

def minKey(key, mstSet):
    min_val = float('inf')
    min_index = -1
    for v in range(V):
        if key[v] < min_val and not mstSet[v]:
            min_val = key[v]
            min_index = v
    return min_index

graph = [
    [0, 2, 0, 6, 0],
    [2, 0, 3, 8, 5],
    [0, 3, 0, 0, 7],
    [6, 8, 0, 0, 9],
    [0, 5, 7, 9, 0]
]

key = [float('inf')] * V
parent = [-1] * V
mstSet = [False] * V
key[0] = 0

for _ in range(V - 1):
    u = minKey(key, mstSet)
    mstSet[u] = True
    for v in range(V):
        if graph[u][v] and not mstSet[v] and graph[u][v] < key[v]:
            key[v] = graph[u][v]
            parent[v] = u

for i in range(1, V):
    print(parent[i], "-", i)
