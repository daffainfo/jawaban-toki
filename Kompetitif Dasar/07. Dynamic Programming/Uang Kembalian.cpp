#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool filled[50000] = {0};
ll dp[50000] = {0};
unsigned short n, k, coin[500];

ll tukar(int x) {
    if(x == 0) return 0;
    if(filled[x - 1]) return dp[x - 1];
    if(x < coin[0]) {
        filled[x - 1] = true;
        dp[x - 1] = INT_MAX;
    }
    ll min = INT_MAX;
    for(unsigned short i=0; i<n; i++) {
        if(coin[i] <= x){
            ll val = tukar(x - coin[i]) + 1;
            if(val < min) min = val;
        }
    }
    filled[x - 1] = true;
    dp[x - 1] = min;
    return min;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(short i=0; i<n; i++)
        cin>>coin[i];
    cin>>k;
    ll val = tukar(k);
    cout<<((val >= INT_MAX) ? -1 : val)<<'\n';
    return 0;
}