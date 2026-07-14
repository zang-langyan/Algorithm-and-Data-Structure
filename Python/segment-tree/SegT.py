class SegT:
    def __init__(self, a):
        n = len(a)
        # [(max, min)]
        self.x = [(0,0)] * 4 * n
        self.build(a, 1, 0, n-1)

    def build(self, a, p, l, r):
        if l == r:
            self.x[p] = (a[l], a[l])
            return 
        
        mid = (l + r) // 2
        self.build(a, p * 2, l, mid)
        self.build(a, p * 2 + 1, mid + 1, r)
        self.update(p)
    
    def update(self, p):
        # left node
        lmx, lmi = self.x[p * 2]
        # right node
        rmx, rmi = self.x[p * 2 + 1]
        self.x[p] = (max(lmx, rmx), min(lmi, rmi))

    def merge(self, a, b):
        mxa, mia = a
        mxb, mib = b
        return max(mxa, mxb), min(mia, mib)

    def query(self, p, ql, qr, l, r):
        if ql <= l and r <= qr:
            return self.x[p]
        mid = (l + r) // 2
        if qr <= mid: # query in left node
            return self.query(p * 2, ql, qr, l, mid)
        if ql > mid: # query in right node
            return self.query(p * 2 + 1, ql, qr, mid + 1, r)
        lnode = self.query(p * 2    , ql, qr, l      , mid)
        rnode = self.query(p * 2 + 1, ql, qr, mid + 1, r  )
        return self.merge(lnode, rnode)