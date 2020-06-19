/*
 * Author: Sam Henry
 * Date: June 15, 2020
 * 
 * Segment Tree for sum.
 * Complexity: O(n) build, O(logn) update/query
 */

#include <iostream>
using namespace std;

#define MAXN 100001

int seg[2*MAXN];
int a[MAXN];
int n;

void build() {
    for (int i = 0; i < n; i++)
        seg[n + i] = a[i];
    for (int i = n - 1; i > 0; i--)
        seg[i] = seg[i << 1] + seg[i << 1 | 1];
}

void update(int u, int v) {
    u += n;
    seg[u] = v;
    for (int i = u; i > 1; i >>= 1)
        seg[i >> 1] = seg[i] + seg[i ^ 1];
}

int query(int l, int r) {
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res += seg[l++];
        if (r & 1) res += seg[--r];
    }
    return res;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    build();
    update(0, 1);
    
    cout << query(0, 5) << endl;

    return 0;
}