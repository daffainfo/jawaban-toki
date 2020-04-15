#include <iostream>
#include <cstring>

using namespace std;

unsigned short n;
char nama[500][11];

void insertandsort(const char*, unsigned short);
void swap(char*, char*);

int main() {
    cin>>n;
    for(unsigned short i = 0; i<n; i++) {
        char tmp[11];
        cin>>tmp;
        insertandsort(tmp, i);
    }
    for(unsigned short i = 0; i<n; i++) {
        cout<<nama[i]<<endl;
    }
}

void insertandsort(const char* tmp, unsigned short n) {
    unsigned short i = n;
    strcpy(nama[i], tmp);
    if(i!=0) {
        while (strlen(nama[i-1])>strlen(nama[i]) && i>0) {
            swap(nama[i-1], nama[i]);
            i--;
        }
        while (strcmp(nama[i-1], nama[i])>0 && i>0) {
            if(strlen(nama[i-1])==strlen(nama[i])) {
                swap(nama[i-1], nama[i]);
                i--;
            } else break;
        }
    }
}

void swap(char * str1, char* str2) {
    char tmp[11];
    strcpy(tmp, str1);
    strcpy(str1, str2);
    strcpy(str2, tmp);
}