#include <iostream>
#include <cstring>

using namespace std;

struct phonebook {
    char name[11];
    char num[7];
};

typedef struct phonebook Phonebook;
Phonebook PB[100001];
unsigned int n;

void searchPhonebook(char *);

int main() {
    unsigned int q;
    cin>>n>>q;
    for(unsigned int i=1; i<=n; i++) {
        cin>>PB[i].name>>PB[i].num;
    }

    for(unsigned int i=1; i<=q; i++) {
        char search[11];
        cin>>search;
        searchPhonebook(search);
    }
    return 0;
}

void searchPhonebook(char search[]) {
    unsigned int kiri = 1, kanan = n;
    char num[7] = "NIHIL";
    while(kiri<=kanan && (strcmp(num, "NIHIL") == 0)) {
        unsigned int tengah = (kanan+kiri)/2;
        if(strcmp(search, PB[tengah].name) > 0) {
            kiri = tengah+1;
        } else if (strcmp(search, PB[tengah].name) < 0) {
            kanan = tengah-1;
        } else {
            strcpy(num, PB[tengah].num);
        }
    }
    cout<<num<<endl;
}