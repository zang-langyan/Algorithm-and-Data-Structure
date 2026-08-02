# 值域树状数组
class Fenwick:
    def __init__(self, n):
        self.n = n
        self.tree = [0] * (n + 2)

    def add(self, i, d = 1):
        while i <= self.n:
            self.tree[i] += d
            i += i & -i
        
    def query(self, i):
        s = 0
        while i > 0:
            s += self.tree[i]
            i -= i & -i
        return s