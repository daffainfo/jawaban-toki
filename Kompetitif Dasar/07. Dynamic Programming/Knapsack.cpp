#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int berat[101], harga[101], n_barang;
bool sudah[101][2001], ambil[101][2001];
pii dp[101][2001];
#define mpair make_pair

pii compute(int barang, int kapasitas) {
    if(barang == 0 || kapasitas == 0)
        return mpair(0, kapasitas);
    if(sudah[barang][kapasitas])
        return dp[barang][kapasitas];
    
    pii best = compute(barang - 1, kapasitas);
    ambil[barang][kapasitas] = false;
    if(kapasitas >= berat[barang]) {
        pii best2 = compute(barang - 1, kapasitas - berat[barang]);
        best2.first += harga[barang];
        if(best2.first > best.first || (best2.first == best.first && best2.second > best.second))
            best = best2, ambil[barang][kapasitas] = true;
    }
    sudah[barang][kapasitas] = true;
    dp[barang][kapasitas] = best;
    return best;
}
set<int> barangdiambil;
void print(int barang, int kapasitas) {
    if(barang == 0)
        return;
    if(ambil[barang][kapasitas]) {
        barangdiambil.insert(barang);
        print(barang - 1, kapasitas - berat[barang]);
    } else print(barang - 1, kapasitas);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int kapasitas;
    cin>>kapasitas>>n_barang;
    for(int i=1; i<=n_barang; i++)
        cin>>berat[i]>>harga[i];
    compute(n_barang, kapasitas);
    print(n_barang, kapasitas);
    for(auto i=barangdiambil.begin(); i != barangdiambil.end(); i++)
        cout<<*i<<'\n';
    return 0;
}