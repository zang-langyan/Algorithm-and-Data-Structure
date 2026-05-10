import heapq
from heapq import heappush, heappop
from typing import List, Tuple
from math import inf

"""
Dijkstra算法
有向图D, 根结点root
1. 初始化 l(x) - root -> x 最短路, l[x] = inf, l[root] = 0;
   visited数组; q 中存储下一个起点
2. 更新与 q 中存储的当前节点 v 存在 v->x 有向路的 l[x] = min(l[x], l[v]+g[v][x])
3. 重复步骤2, 直到 q 为空
"""
def dijkstra_dense(root: int, g: List[List[int]]):
    n = len(g)
    l = [inf] * n
    l[root] = 0
    vis = [False] * n
    vis[root] = True

    q = [root]
    while q:
        u = q.pop()
        nxt, nxt_mi = -1, inf
        for v in range(n):
            if vis[v]:
                continue
            if g[u][v]:
                l[v] = min(l[v], l[u]+g[u][v])
            if l[v] < nxt_mi:
                nxt_mi = l[v]
                nxt = v
        if nxt != -1:
            q = [nxt]
            vis[nxt] = True
    return l

# g 是稀疏临界图
def dijkstra_sparse(root: int, g: List[List[Tuple(int, int)]]):
    n = len(g)
    d = [inf] * n
    pq = [(0, root)]
    while pq:
        du, u = heappop(pq)
        if du > d[u]: # u is already updated
            continue
        for v, w in g[u]:
            nd = du + w
            if nd < d[v]:
                d[v] = nd
                heappush(pq, (nd, v))
    return d

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
    g = [[0 for _ in range(n)] for _ in range(n)]
    for e in edges:
        g[e[0]][e[1]] = e[2]
        g[e[1]][e[0]] = e[2] # 无向图

    r = input()
    while r:
        print(dijkstra_dense(int(r), g))
        r = input()
    

    g = [[] for _ in range(n)]
    for u, v, w in edges:
        g[u].append((v, w))
        g[v].append((u, w))


    r = input()
    while r:
        print(dijkstra_sparse(int(r), g))
        r = input()

