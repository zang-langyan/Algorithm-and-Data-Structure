from typing import List
from math import inf

class UF:
    def __init__(self, n: int):
        self.n_sets = n
        self.id = [i for i in range(n)]
        self.sz = [1 for _ in range(n)]

    def union(self, p: int, q: int) -> None:
        pRoot, qRoot = self.find(p), self.find(q)
        if pRoot == qRoot: return

        if self.sz[pRoot] < self.sz[qRoot]:
            self.id[pRoot] = qRoot
            self.sz[qRoot] += self.sz[pRoot]
        else:
            self.id[qRoot] = pRoot
            self.sz[pRoot] += self.sz[qRoot]
        self.n_sets -= 1

    def find(self, p: int) -> int:
        while p != self.id[p]:
            p = self.id[p]
        return p

    def connected(self, p: int, q: int) -> bool:
        return self.find(p) == self.find(q)

class Kruskal(UF):
    def __init__(self, n: int, edges: List[List[int]]):
        super().__init__(n)
        self.edges = edges
        self.edges.sort(key=lambda e: e[2])
        
    def mst(self) -> int:
        ans = 0
        for u, v, w in self.edges:
            if not self.connected(u, v):
                self.union(u,v)
                ans += w
        return ans 

if __name__ == "__main__":
    edges = [
                [0, 1, 1],
                [0, 2, 2],
                [0, 5, 15],
                [0, 6, 16],
                [1, 2, 10],
                [1, 3, 3],
                [1, 5, 7],
                [2, 3, 9],
                [2, 6, 6],
                [3, 4, 4],
                [4, 5, 5],
                [4, 6, 8]
            ]
    n = 7
    kruskal = Kruskal(n, edges)
    print(kruskal.mst())


