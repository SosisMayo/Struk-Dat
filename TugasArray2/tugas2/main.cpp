#include <iostream>
#include <stdio.h>

using namespace std;

class CKota{
public:
    string nama;
    float x,y;
    int tujuanKiri = -1, tujuanKanan = -1;
};CKota Kota[100];

void tambah(int *M, string nama, int x, int y){
    int N = 100;
    if (*M < N - 1){
        *M = *M + 1;
        Kota[*M].nama = nama;
        Kota[*M].x = x;
        Kota[*M].y = y;
    }
}

void cari(int M,string nama,int *posisi){
    *posisi = -1;
    for(int i=0; i<=M; i++){
        if(Kota[i].nama == nama){
            *posisi = i;
            break;
        }
    }
}

void hubungkan(string asal,string tujuanKiri,string tujuanKanan,int M){
    int indexAsal,indexTujuanKiri,indexTujuanKanan;
    cari(M,asal,&indexAsal);
    cari(M,tujuanKiri,&indexTujuanKiri);
    cari(M,tujuanKanan,&indexTujuanKanan);
    Kota[indexAsal].tujuanKiri = indexTujuanKiri;
    Kota[indexAsal].tujuanKanan = indexTujuanKanan;
}

int main()
{
    // M sebagai penunjuk akhir array, posisi untuk menyimpan index yang dicari
    int M = -1,posisi;

    // MENAMBAHKAN DATA KOTA
    tambah(&M,"A",0,0);
    tambah(&M,"B",1,1);
    tambah(&M,"D",1,-1);
    tambah(&M,"F",2,1);
    tambah(&M,"E",3,-1);

    //MENGHUBUNGKAN KOTA SATU DENGAN KOTA LAINNYA
    hubungkan("A","B","D",M);
    hubungkan("B","F","E",M);
    hubungkan("D","F","E",M);
    cout << "Kota " << Kota[0].nama << " berhubungan dengan Kota " << Kota[Kota[0].tujuanKiri].nama << " dan Kota " << Kota[Kota[0].tujuanKanan].nama << endl;
    cout << "Kota " << Kota[1].nama << " berhubungan dengan Kota " << Kota[Kota[1].tujuanKiri].nama << " dan Kota " << Kota[Kota[1].tujuanKanan].nama << endl;
    cout << "Kota " << Kota[2].nama << " berhubungan dengan Kota " << Kota[Kota[2].tujuanKiri].nama << " dan Kota " << Kota[Kota[2].tujuanKanan].nama << endl;

    //MENCARI DATA KOTA MELALUI NAMA KOTA
    cari(M,"E",&posisi);
    cout << "Kota E berada pada index " << posisi <<endl;
    return 0;
}
