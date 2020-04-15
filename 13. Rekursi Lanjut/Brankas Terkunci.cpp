#include <bits/stdc++.h>

using namespace std;
int N, K;
int catat[1000];
bool pernah[1000] = {0};

void tulis(int kedalaman) {
    if(kedalaman >= K) {
        bool menaik = true;
        for(int i=0; i<K-1; i++) {
            if(catat[i] > catat[i+1]) menaik = false;
        }
        if(menaik) {
            for(int i=0; i<K; i++) {
				cout<<catat[i];
				if(i < K-1) cout<<" ";
			}
            cout<<'\n';
        }
    } else {
        for(int i=1; i<=N; i++) {
            if(!pernah[i]) {
                pernah[i] = true;
                catat[kedalaman] = i;
                tulis(kedalaman+1);
                pernah[i] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cin>>N>>K;
    tulis(0);
    return 0;
}