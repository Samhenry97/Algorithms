#include <algorithm>
#include <iostream>
using namespace std;

#define MAXN 100001

int disjoint[MAXN];

int find(int x) {
    int par = x;
    while(disjoint[par] >= 0) par = disjoint[par];
    if (par != x) disjoint[x] = par;
    return par;
}

void merge(int x, int y) {
    int parx = find(x);
    int pary = find(y);

    if (parx == pary) return;
    if (disjoint[parx] < disjoint[pary]) {
        disjoint[pary] += disjoint[parx];
        disjoint[parx] = pary;
    } else {
        disjoint[parx] += disjoint[pary];
        disjoint[pary] = parx;
    }
}

int main() {
    fill(disjoint, disjoint + MAXN, -1);
    merge(1, 2);
    find(1);
}