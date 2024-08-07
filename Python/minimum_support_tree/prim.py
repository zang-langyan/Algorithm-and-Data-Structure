from typing import List
from math import inf

def Prim(g: List[List[int]]):
    n = len(g)
    V = set([i for i in range(1,n)]) # remaining vertices
    k = 0 # chosen vertex
    
    l = [inf for _ in range(n)] # initialize each vertex weight
    l[0] = 0

    while V:
        cur_min, cur = inf, -1
        for v in V:
            if g[k][v]:
                l[v] = min(l[v], g[k][v])
            if l[v] < cur_min:
                cur, cur_min = v, l[v]
        k = cur
        V.remove(k)

    return sum(l)

g = [  # 0   1   2   3   4   5   6
        [0,  1,  2,  0,  0, 15, 16], # 0
        [1,  0, 10,  3,  0,  1,  0], # 1
        [2, 10,  0,  9,  0,  0,  6], # 2
        [0,  3,  9,  0,  4,  0,  0], # 3
        [0,  0,  0,  4,  0,  5,  8], # 4
        [15, 1,  0,  0,  5,  0,  0], # 5
        [16, 0,  6,  0,  8,  0,  0]  # 6
    ]

if __name__ == "__main__":
    print(Prim(g))
