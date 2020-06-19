"""
Author: Sam Henry
Date: June 19, 2020

Rabin Karp pattern searching.
Complexity: O(n+m) average/best, O(nm) worst
"""

# Returns the indices of of pattern occurences in text
def rabinKarp(text, pat, d = 256, q = (1 << 31) - 1):
    n, m = len(text), len(pat)
    h = pow(d, m-1, q)
    p, t = 0, 0
    ans = []

    # Compute pattern hash and first text hash
    for i in range(m):
        p = (d * p + ord(pat[i])) % q
        t = (d * t + ord(text[i])) % q
    
    # Test the base case
    if p == t and text[:m] == pat:
        ans.append(0)

    # Test the rest of the cases
    for i in range(n - m):
        t = (d * (t - ord(text[i]) * h) + ord(text[i + m])) % q
        if p == t and text[i+1:i+m+1] == pat:
            ans.append(i+1)
    return ans
        
print(rabinKarp("abcabc", "abc"))
print(rabinKarp("abcabc", "d"))
print(rabinKarp("abcdef", "def"))