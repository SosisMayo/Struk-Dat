#include <iostream>
#include <stdio.h>

using namespace std;

class CKota{
public:
    string nama;
    float x,y;
    int node1,node2;
};CKota Kota[100];

void tambah(CKota Kota[100], int *M, string nama, int x, int y, int node1, int node2){
    int N = 100;
    if (*M < N - 1){
        *M = *M + 1;
        Kota[*M].nama = nama;
        Kota[*M].x = x;
        Kota[*M].y = y;
        Kota[*M].node1 = node1;
        Kota[*M].node2 = node2;
    }
}

void cari(CKota Kota[100],int M,string nama){
    int posisi=-1;
    for(int i=0; i<=M; i++){
        if(Kota[i].nama == nama){
            posisi = i;
        }
    }
    cout << posisi << endl;
}

int main()
{
    int M = -1;
    tambah(Kota,&M,"A",0,0,2,3);
    tambah(Kota,&M,"B",1,1,4,5);
    tambah(Kota,&M,"D",1,-1,4,5);
    tambah(Kota,&M,"F",2,1,2,3);
    tambah(Kota,&M,"E",3,-1,2,3);
    cari(Kota,M,"E");
    return 0;
}
