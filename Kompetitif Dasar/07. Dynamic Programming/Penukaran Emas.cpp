#include <bits/stdc++.h>
using namespace std;
int dp[1001];
bool sudah[1001];

int count(int n) {
    if(n < 2)
        return 0;
    if(n == 2 || n == 3)
        return 1;
    if(n == 4)
        return 2;
    if(sudah[n])
        return dp[n];
    int tukarlagi2 = count(n / 2);
    int tukarlagi3 = count(n / 3);
    int tukarlagi4 = count(n / 4);
    int best = max(tukarlagi2, n / 2) + max(tukarlagi3, n / 3) + max(tukarlagi4, n / 4);
    sudah[n] = true;
    dp[n] = max(best, n);
    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    count(n);
    cout<<dp[n]<<'\n';
}