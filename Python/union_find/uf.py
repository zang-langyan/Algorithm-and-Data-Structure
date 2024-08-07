class UF:
    def __init__(self, n: int):
        self.id = [i for i in range(n)]
        self.n_components = n
        self.sz = [1 for _ in range(n)]
        self.n = n
    
    def insert(self, p: int, q: int) -> None:
        pRoot = self.find(p)
        qRoot = self.find(q)
        if (pRoot == qRoot): return
        
        # weighted quick union find
        if (self.sz[pRoot] < self.sz[qRoot]):
            self.id[pRoot] = qRoot
            self.sz[qRoot] += self.sz[pRoot]
        else:
            self.id[qRoot] = pRoot
            self.sz[pRoot] += self.sz[qRoot]

        self.n_components -= 1

    def find(self, i: int) -> int:
        while self.id[i] != i:
            i = self.id[i]
        return i

    def connected(self, p: int, q: int) -> bool:
        return self.find(p) == self.find(q)

    def __repr__(self) -> str:
        return f"Union Find Instance, Initialized with {self.n} nodes, Currently with {self.n_components} unions (sets)"

    def __str__(self) -> str:
        s = ""
        for i in range(self.n):
            s += f"{i} -> {self.find(i)}\n"
        s += f"Union Find Instance, Initialized with {self.n} nodes, Currently with {self.n_components} unions (sets)"
        return s


if __name__ == "__main__":
    uf = UF(10)

    print(repr(uf))
    uf.insert(4,3)
    uf.insert(3,8)
    uf.insert(6,5)
    uf.insert(9,4)
    uf.insert(2,1)
    uf.insert(8,9)
    uf.insert(5,0)
    uf.insert(7,2)
    uf.insert(6,1)
    uf.insert(1,0)
    uf.insert(6,7)


    print(uf)
    
