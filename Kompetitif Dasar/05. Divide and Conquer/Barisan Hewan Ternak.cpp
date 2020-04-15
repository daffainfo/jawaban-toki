#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll baris[100000] = {0}, y;

ll binsearch(ll left, ll right) {
    if(left == right || (((right - left) == 1) && (baris[right] > y))) return left;
    if(((right - left) == 1) && (baris[right] <= y)) return right; 
    ll mid = left + ((right - left) >> 1);
    if(baris[mid] == y) return mid;
    else if(baris[mid] > y) return binsearch(left, mid);
    else return binsearch(mid, right);
}

int main() {
    int n, q;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    baris[0] = 1;
    for(int i=1; i<=n; i++) {
        cin>>baris[i];
        baris[i] += baris[i - 1];
    }
    cin>>q;
    while(q--) {
        cin>>y;
        cout<<binsearch(0, n - 1) + 1<<'\n';
    }
    return 0;
}