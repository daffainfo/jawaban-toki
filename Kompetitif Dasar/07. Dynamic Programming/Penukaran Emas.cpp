#include <bits/stdc++.h>
using namespace std;
int dp[1001];
bool sudah[1001];

int count(int n) {
    if(n <= 4)
        return (n / 2) + (n / 3) + (n / 4);
    if(sudah[n])
        return dp[n];
    int best = max(count(n / 2), n / 2) + max(count(n / 3), n / 3) + max(count(n / 4), n / 4);
    sudah[n] = true;
    dp[n] = max(best, n);
    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    cout<<count(n)<<'\n';
    return 0;
}