#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
ull n, m, a[262144] = {0}, pos = 0, low_bound = 0, up_bound = UINT64_MAX;
ull product(ull supply) {
    ull sum = 0;
    for(int i=0; i<n; i++) sum += (supply / a[i]);
    return sum;
}

void binsearch(ull left, ull right) {
    while (left <= right) {
        ull mid = left + ((right - left) >> 1), sum = product(mid);
        if(sum > m) {
            right = mid - 1;
        } else if(sum < m) {
            left = mid + 1;
        } else {
            if(product(mid - 1) < m) {
                low_bound = mid;
                break;
            }
            else right = mid - 1;
        }
    }
    left = low_bound, right = UINT64_MAX;
    while (left <= right) {
        ull mid = left + ((right - left) >> 1), sum = product(mid);
        if(sum > m) {
            right = mid - 1;
        } else if(sum < m) {
            left = mid + 1;
        } else {
            if(product(mid + 1) > m) {
                up_bound = mid;
                return;
            }
            else left = mid + 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cin>>n>>m;
    for(int i=0; i<n; i++)
        cin>>a[i];
    binsearch(1, UINT64_MAX);
    cout<<up_bound - low_bound + 1<<'\n';
    return 0;
}