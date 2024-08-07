from typing import List

def kmp_table(pat: str) -> List[int]:
    m = len(pat)
    # lps[i] = the longest proper prefix of pat[0..i] which is also a suffix of pat[0..i]. 
    lps = [0 for _ in range(m)]
    
    # sub_len -> length of the previous longest prefix suffix
    sub_len, i = 0, 1
    while i < m:
        if pat[i] == pat[sub_len]:
            sub_len += 1
            lps[i] = sub_len
            i += 1
        else:
            if sub_len:
                sub_len = lps[sub_len-1]
            else:
                lps[i] = 0
                i += 1
    return lps

def kmp(pat: str, txt: str) -> List[int]:
    # 双指针, i -> txt, j -> pat
    i = j = 0
    m, n = len(pat), len(txt)

    kmpT = kmp_table(pat)
    ans = []
    while i < n:
        if txt[i] == pat[j]:
            i += 1
            j += 1
        
        if j == m:
            ans.append(i-j)
            j = kmpT[j-1]
        elif i < n and txt[i] != pat[j]:
            if j:
                j = kmpT[j-1]
            else:
                i += 1

    return ans


if __name__ == "__main__":
    pat = "BAC"
    txt = "BACCBAC"
    idx = kmp(pat, txt)
    for i in idx:
        print("index: ", i, "->",  txt[i:i+len(pat)])

