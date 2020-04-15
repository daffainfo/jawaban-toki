#include <iostream>
#include <cstring>

using namespace std;
char Name[1000][11];
unsigned short n;

unsigned short getPos(char *, unsigned short);
void swap(char*, char*);

int main() {
    cin>>n;
    for(unsigned short i = 0; i<n; i++) {
        char temp[11];
        cin>>temp;
        cout<<getPos(temp, i)+1<<endl;
    }
    return 0;
}

unsigned short getPos(char * nama, unsigned short n) {
    unsigned short i = n;
    strcpy(Name[i], nama);
    if(i!=0) {
        while (strcmp(Name[i-1], Name[i])>0 && i>0) {
            swap(Name[i-1], Name[i]);
            i--;
        }
    }
    return i;
}

void swap(char * str1, char* str2) {
    char tmp[11];
    strcpy(tmp, str1);
    strcpy(str1, str2);
    strcpy(str2, tmp);
}