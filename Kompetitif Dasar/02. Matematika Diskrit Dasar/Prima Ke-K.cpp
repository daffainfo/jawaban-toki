#include <bits/stdc++.h>
using namespace std;
int prime[77777];
bool prima[990000];

bool isprime(int n) {
    for(int i=2; i*i<=n; i++) {
        if((n % 2) == 0) return false;
    }
    return true;
}

void sieve() {
    int in = 0;
    memset(prima, true, 990000);
    for(int i = 2; i <= 989999; i++) {
        if (prima[i]) {
            if(isprime(i)) {
                prime[in] = i;
                in++;
                int j = 2;
                while ((j * i) <= 989999){
                    prima[j * i] = false;
                    j++;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        cout<<prime[n-1]<<'\n';
    }
    
    return 0;
}