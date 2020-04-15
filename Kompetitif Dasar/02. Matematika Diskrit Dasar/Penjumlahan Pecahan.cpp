#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

ull fpb(ull a, ull b) {
    if(a % b == 0) return b;
    else return fpb(b, a % b);
}

int main() {
    ull a, b, c, d, gcd, e, f;
    cin>>a>>b;
    cin>>c>>d;
    e =(a * d) + (b * c);
    f = b * d;
    if(e > f) gcd = fpb(e, f);
    else gcd = fpb(f, e);
    cout<<(e / gcd)<<" "<<(f / gcd)<<endl;
    return 0;
}