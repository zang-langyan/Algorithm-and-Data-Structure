# 字符串字典序最小的循环同构串（最小表示法）
def min_rot(s):
    if not s:
        return ''
    n = len(s)
    ss = s + s
    i, j, k = 0, 1, 0
    while i < n and j < n and k < n:
        a = ss[i+k]
        b = ss[j+k]
        if a == b:
            k += 1
        elif a < b:
            j += k + 1
            k = 0
            if i == j:
                j += 1
        else:
            i += k + 1
            k = 0
            if i == j:
                i += 1
    start = i if i < j else j
    return ss[start:start+n]

