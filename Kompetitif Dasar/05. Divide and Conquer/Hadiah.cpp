#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n;

ll bigpower(ll a, ll b) {
    if(a == 0) return 0;
    if(b == 0) return 1;
    if(b & 1) return ((bigpower(a, b - 1) % n) * (a % n) % n);
    else {
        a = bigpower(a, (b >> 1)) % n;
        return (a * a) % n;
    }
}

ll hadiah(ll a, ll b, ll c) {
    if(a == 0) return 0;
    if(a == 1 || b == 0) return 1;
    if(b == 1 || c == 0) return a % n;
    if(c == 1) return bigpower(a, b);
    return bigpower(hadiah(a, b, c - 1) % n, b);
}

int main() {
    ll a, b, c;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a>>b>>c>>n;
    cout<<hadiah(a % n, b, c) + 1<<'\n';
    return 0;
}