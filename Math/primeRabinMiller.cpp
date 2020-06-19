/*
 * Author: Sam Henry
 * Date: April 1, 2019
 * 
 * Rabin Miller deterministic prime checker.
 * Complexity: O(logn)
 */

#include <iostream>
using namespace std;

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
 
bool witness(ll n, ll s, ll d, ll a) {
    ll x = pow(a, d, n), y;
 
    while (s) {
        y = x * x % n;
        if (y == 1 && x != 1 && x != n - 1) return false;
        x = y;
        s--;
    }
    return y == 1;
}
 
bool isPrime(ll n) {
    if (n < 2) return false;
    if (!(n & 1) && n != 2) return false;
    if (n % 3 == 0 && n != 3) return false;
    if (n <= 3) return true;
 
    ll d = n >> 1;
    ll s = 1;
    while (!(d & 1)) {
        d >>= 1;
        s++;
    }
 
    if (n < 1373653)
        return witness(n, s, d, 2) && witness(n, s, d, 3);
    if (n < 9080191)
        return witness(n, s, d, 31) && witness(n, s, d, 73);
    if (n < 4759123141)
        return witness(n, s, d, 2) && witness(n, s, d, 7) && witness(n, s, d, 61);
    if (n < 1122004669633)
        return witness(n, s, d, 2) && witness(n, s, d, 13) && witness(n, s, d, 23) && witness(n, s, d, 1662803);
    if (n < 2152302898747)
        return witness(n, s, d, 2) && witness(n, s, d, 3) && witness(n, s, d, 5) && witness(n, s, d, 7) && witness(n, s, d, 11);
    if (n < 3474749660383)
        return witness(n, s, d, 2) && witness(n, s, d, 3) && witness(n, s, d, 5) && witness(n, s, d, 7) && witness(n, s, d, 11) && witness(n, s, d, 13);
    return witness(n, s, d, 2) && witness(n, s, d, 3) && witness(n, s, d, 5) && witness(n, s, d, 7) && witness(n, s, d, 11) && witness(n, s, d, 13) && witness(n, s, d, 17);
}

int main() {
    for (int i = 2; i < 100; i++) {
        cout << i << ": " << isPrime(i) << endl;
    }
    
    return 0;
}