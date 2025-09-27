const V = 4;
const INF = 99999;

function floydWarshall(graph) {
    const dist = [];
    for (let i = 0; i < V; i++) {
        dist[i] = graph[i].slice();
    }

    for (let k = 0; k < V; k++) {
        for (let i = 0; i < V; i++) {
            for (let j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printSolution(dist);
}

function printSolution(dist) {
    console.log('Following matrix shows the shortest distances between every pair of vertices:');
    for (let i = 0; i < V; i++) {
        for (let j = 0; j < V; j++) {
            if (dist[i][j] === INF) {
                process.stdout.write('INF\t');
            } else {
                process.stdout.write(`${dist[i][j]}\t`);
            }
        }
        console.log();
    }
}

const graph = [
    [0, 5, INF, 10],
    [INF, 0, 3, INF],
    [INF, INF, 0, 1],
    [INF, INF, INF, 0]
];

floydWarshall(graph);
