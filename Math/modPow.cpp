/*
 * Author: Sam Henry
 * Date: January 1, 2019
 * 
 * Modular power.
 * Complexity: O(log exp)
 */

#include <iostream>
using namespace std;

#define MOD 1000000007

typedef long long int ll;

ll pow(ll base, ll exp, ll mod) {
    ll res = 1;
    while (exp) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

int main() {
    cout << pow(5, 5, MOD);
}