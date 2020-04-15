#include <bits/stdc++.h>
using namespace std;
#define mod 1000000

long long bigpower(long long a, long long b) {
    if(a == 0) return 0;
    if(b == 0) return 1;
    if(b & 1) return ((bigpower(a, b - 1) % mod) * (a % mod) % mod);
    else {
        a = bigpower(a, (b >> 1)) % mod;
        return (a * a) % mod;
    }
}

int main() {
    long long a, b;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a>>b;
    long long res = bigpower(a % mod, b);
    if(pow(a, b) >= mod) {
        long long tmp = res;
        short digit = 0;
        if(tmp == 0) digit = 1;
        for(;tmp > 0; digit++, tmp /= 10);
        digit = 6 - digit;
        while (digit--) cout<<0;
        cout<<res<<'\n';
    } else cout<<res<<'\n';
    return 0;
}