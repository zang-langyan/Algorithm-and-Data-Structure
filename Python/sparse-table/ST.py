from math import gcd
# 手写 min max 更快
min = lambda a, b: b if b < a else a
max = lambda a, b: b if b > a else a

def op(a, b):
    return min(a[0], b[0]), max(a[1], b[1]), gcd(a[2], b[2])

class ST:
    def __init__(self, a):
        n = len(a)
        w = n.bit_length()
        st = [[None] * n for _ in range(w)]
        st[0] = [(x, x) for x in a]
        for i in range(1, w):
            for j in range(n - (1 << i) + 1):
                st[i][j] = op(st[i - 1][j], st[i - 1][j + (1 << (i - 1))])
        self.st = st

    # [l, r) 左闭右开
    def query(self, l, r):
        k = (r - l).bit_length() - 1
        mn, mx, g = op(self.st[k][l], self.st[k][r - (1 << k)])
        return mn, mx, g