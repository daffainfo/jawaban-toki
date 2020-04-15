#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef struct pelat {
    ull nomor, harga;
}plat;
ull n, duit;
plat * calon_sorted, * calon;
int * terbeli;

bool compVal(plat a, plat b) {
    if(a.harga == b.harga)
        return a.nomor > b.nomor;
    return a.harga < b.harga;
}

void beliPlat(ull start, ull end, bool isSaveToArray = false) {
    for(ull i=start; i<end; i++) {
        for(int j=n; j>=0; j--) {
            if(calon[j].harga <= duit) {
                duit -= calon[j].harga;
                if(isSaveToArray) terbeli[i] = j;
                cout<<j;
                break;
            }
        }
    }
    cout<<'\n';
}

void getPlat() {
    bool termurahnyanol = (calon_sorted[0].nomor == 0);
    ull murahbukannol = ((termurahnyanol) ? calon_sorted[1].harga : calon_sorted[0].harga);
    ull termurah = calon_sorted[0].harga;
    bool isinyanol = (murahbukannol > duit);
    if(isinyanol || n == 0) {
        cout<<"1\n0\n0\n";
        return;
    }
    ull length = ((duit - murahbukannol) / termurah) + 1;
    cout<<length<<'\n';
    duit -= murahbukannol;
    duit -= ((length - 1) * termurah);
    for(ull i=0; i<=n; i++)
        calon[i].harga -= termurah;
    if(length < 100) terbeli = new int[length];
    duit += murahbukannol;
    for(int i=n; i>=0; i--) {
        ull currentprice = calon[i].harga + termurah;
        if(currentprice <= duit) {
            duit -= currentprice;
            if(length < 100) terbeli[0] = i;
            cout<<i;
            break;
        }
    }
    if(length < 100) {
        beliPlat(1, ((length <= 50) ? length : 50), true);
        if(length <= 50) {
            for(int i=0; i<length; i++)
                cout<<terbeli[i];
            cout<<'\n';
        } else {
            for(int i=(length - 50); i<50; i++)
                cout<<terbeli[i];
            ull sisa = length - 50;
            beliPlat(0, sisa);
        }
    } else if(length >= 100) {
        beliPlat(1, 50);
        ull takterprint = (length - 100), terbelinonprint = 0;
        for(int i=n; i>=0 && duit > 0 && (terbelinonprint < takterprint); i--) {
            if(calon[i].harga == 0) break;
            ull buy = (duit/calon[i].harga);
            if((terbelinonprint + buy) > takterprint)
                buy = (takterprint - terbelinonprint);
            terbelinonprint += buy;
            buy *= calon[i].harga;
            duit -= ((duit > buy) ? buy : duit);
        }
        beliPlat(0, 50);
    }
}

int main() {
    cin>>n;
    calon_sorted = new plat[n + 1], calon = new plat[n + 1];
    for(ull i=0; i<=n; i++){
        calon_sorted[i].nomor = i;
        calon[i].nomor = i;
        cin>>calon_sorted[i].harga;
        calon[i].harga = calon_sorted[i].harga;
    }
    cin>>duit;
    sort(calon_sorted, calon_sorted + n + 1, compVal);
    if(calon_sorted[0].harga > duit)
        cout<<"0\n";
    else
        getPlat();
    return 0;
}