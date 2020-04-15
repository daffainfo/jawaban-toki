#include <iostream>

using namespace std;

int main() {
    short n,k;
    bool height[100001] = {0};
    cin>>n>>k;
    for(int i=1; i<=n; i++) {
        int arrayIndex;
        cin>>arrayIndex;
        height[arrayIndex] = 1;
    }
    short count = 0;
    int arrayIndex;
    for(int i=1; i<=100000; i++) {
        if(height[i] == 1) {
            count++;
        } else continue;
        if(count==k) {
            arrayIndex = i;
            break;
        }
    }
    cout<<arrayIndex<<endl;
    return 0;
}