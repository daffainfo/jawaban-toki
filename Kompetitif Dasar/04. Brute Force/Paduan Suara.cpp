#include <bits/stdc++.h>
using namespace std;
int m, n, *freq, periode;
bool *batas, ketemu = false;
void resetbatas() {
    for(int i=0; i<m; i++)
        batas[i] = false;
}

bool cekbatas() {
    for(int i=0; i<m; i++) {
        if(batas[i] && freq[i] == freq[i - 1])
            return false;
    }
    for(int i=(m - 1); i>=0; i--) {
        if(batas[i]) {
            if(i == 0 || ((m - i) != periode && (m - i) != (periode + 1)))
                return false;
            break;
        }
    }
    return true;
}

void setbatas(int indexbatas, int jumlahbatas) {
    if(ketemu) return;
    batas[indexbatas] = true;
    if(jumlahbatas == (n - 1)) {
        ketemu = cekbatas();
        if(!ketemu) batas[indexbatas] = false;
        return;
    }
    setbatas(indexbatas + periode, jumlahbatas + 1);
    setbatas(indexbatas + periode + 1, jumlahbatas + 1);
    if(!ketemu) batas[indexbatas] = false;
}

int main() {
    cin>>m;
    freq = new int[m];
    batas = new bool[m];
    resetbatas();
    for(int i=0; i<m; i++)
        cin>>freq[i];
    cin>>n;
    sort(freq, freq + m);
    periode = (m / n);
    if((m % n) == 0) {
        for(int i=periode; i<m; i += periode) {
            cout<<freq[i];
            if((i + periode) < m) cout<<' ';
        }
        cout<<'\n';
    } else {
        setbatas(periode, 1);
        setbatas(periode + 1, 1);
        int counter = 1;
        for(int i=0; i<m; i++) {
            if(batas[i])
                cout<<freq[i]<<((counter == (n - 1) ? '\n' : ' '));
        }
    }
    return 0;
}