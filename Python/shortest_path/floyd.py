from typing import List
from math import inf

def floyd(g: List[List])->List[List]:
    n = len(g)
    for k in range(n):
        for x in range(n):
            for y in range(n):
                g[x][y] = min(g[x][y], g[x][k]+g[k][y])
    return g

if __name__ == "__main__": 
    edges = [
                [0, 1, 7],
                [0, 2, 1],
                [1, 3, 4],
               # [3, 1, 4],
                [1, 5, 1],
                [2, 1, 5],
                [2, 4, 2],
                [2, 5, 7],
                [4, 1, 2],
                [4, 3, 5],
               # [3, 4, 5],
                [5, 4, 3]
            ]
    n = 6
    g = [[inf for _ in range(n)] for _ in range(n)]
    for i in range(n):
        g[i][i] = 0
    for e in edges:
        g[e[0]][e[1]] = e[2]
        # g[e[1]][e[0]] = e[2] # 无向图

    print("Directional Graph:\n", g)
    print("Shortest Path:\n",floyd(g))
