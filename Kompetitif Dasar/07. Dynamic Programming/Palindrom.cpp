#include <bits/stdc++.h>
using namespace std;

void func() {
    string s1, s2;
    cin>>s1;
    s2 = s1;
    reverse(s2.begin(), s2.end());
    int len = s1.length(), dp[len + 1][len + 1];
    for(int i=0; i<=len; i++)
        dp[i][0] = 0, dp[0][i] = 0;
    for(int i=1; i<=len; i++)
        for(int j=1; j<=len; j++)
            if(s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j],
                                dp[i][j - 1]);
    cout<<dp[len][len]<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    while(n--)
        func();
    return 0;
}