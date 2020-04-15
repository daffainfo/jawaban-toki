#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, b, arr[20000], i, sum = 0;
    cin>>n>>b;
    for(i=0; i<n; i++) cin>>arr[i];
    sort(arr, arr + n);
    while(sum < b) sum += arr[--i];
    cout<<(n - i)<<'\n';
    return 0;
}