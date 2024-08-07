from typing import List
from math import inf

"""
Dijkstra算法
有向图D, 根结点root
1. 初始化 l(x) - root -> x 最短路, l[x] = inf, l[root] = 0;
   visited数组; q 中存储下一个起点
2. 更新与 q 中存储的当前节点 v 存在 v->x 有向路的 l[x] = min(l[x], l[v]+g[v][x])
3. 重复步骤2, 直到 q 为空
"""
def dijkstra(root: int, g: List[List[int]]):
    n = len(g)
    l = [inf for _ in range(n)]
    l[root] = 0
    vis = [False for _ in range(n)]
    vis[root] = True

    q = [root]
    while q:
        v = q.pop()
        cur = inf
        for i in range(n):
            if not vis[i] and g[v][i]:
                l[i] = min(l[i], l[v]+g[v][i])
                if l[i] < cur:
                    cur = l[i]
                    q = [i]
        if q: vis[q[0]] = True
    return l

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
        # g[e[1]][e[0]] = e[2] # 无向图

    r = input()
    while(r):
        print(dijkstra(int(r), g))
        r = input()
    

