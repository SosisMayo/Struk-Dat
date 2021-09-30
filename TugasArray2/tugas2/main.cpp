#include <iostream>

using namespace std;

// M sebagai penunjuk akhir array, posisi untuk menyimpan index yang dicari
int M = -1;

class CKota{
public:
    string nama;
    float x,y;
    int tujuanKiri = -1, tujuanKanan = -1;
};CKota Kota[100];

void tambah(string nama, int x, int y){
    int N = 100;
    if (M < N - 1){
        M = M + 1;
        Kota[M].nama = nama;
        Kota[M].x = x;
        Kota[M].y = y;
    }
}

void cari(string nama,int *posisi){
    *posisi = -1;
    for(int i=0; i<=M; i++){
        if(Kota[i].nama == nama){
            *posisi = i;
            break;
        }
    }
}

void hubungkan(string asal,string tujuanKiri,string tujuanKanan){
    int indexAsal,indexTujuanKiri,indexTujuanKanan;
    cari(asal,&indexAsal);
    cari(tujuanKiri,&indexTujuanKiri);
    cari(tujuanKanan,&indexTujuanKanan);
    Kota[indexAsal].tujuanKiri = indexTujuanKiri;
    Kota[indexAsal].tujuanKanan = indexTujuanKanan;
}

void sisipkan(string nama,int x,int y,int posisi){
    if (M < 99){
        M = M + 1;
        for(int i = M; i >= posisi+1; i--){
            Kota[i].nama=Kota[i-1].nama;
            Kota[i].x=Kota[i-1].x;
            Kota[i].y=Kota[i-1].y;
            if (Kota[i-1].tujuanKanan >= posisi){
                Kota[i].tujuanKanan=Kota[i-1].tujuanKanan + 1;
            }
            else if (Kota[i-1].tujuanKanan < posisi){
                Kota[i].tujuanKanan=Kota[i-1].tujuanKanan;
            }
            if (Kota[i-1].tujuanKiri >= posisi){
                Kota[i].tujuanKiri=Kota[i-1].tujuanKiri + 1;
            }
            else if (Kota[i-1].tujuanKanan < posisi){
                Kota[i].tujuanKiri=Kota[i-1].tujuanKiri;
            }
        }
        for (int i=0;i<posisi;i++){
            if (Kota[i].tujuanKanan >= posisi){
                Kota[i].tujuanKanan++;
            }
            if (Kota[i].tujuanKiri >= posisi){
                Kota[i].tujuanKiri++;
            }
        }
        Kota[posisi].nama = nama;
        Kota[posisi].x = x;
        Kota[posisi].y = y;
        Kota[posisi].tujuanKanan = -1;
        Kota[posisi].tujuanKiri = -1;
    }
}

void hapus(string nama){
    int posisi;
    cari(nama,&posisi);
    M = M -1;
    for (int i = posisi;i<=M;i++){
        Kota[i].nama=Kota[i+1].nama;
        Kota[i].x=Kota[i+1].x;
        Kota[i].y=Kota[i+1].y;
        if (Kota[i+1].tujuanKanan >= posisi){
            Kota[i].tujuanKanan=Kota[i+1].tujuanKanan - 1;
        }
        else if (Kota[i+1].tujuanKanan < posisi){
            Kota[i].tujuanKanan=Kota[i+1].tujuanKanan;
        }
        if (Kota[i+1].tujuanKiri >= posisi){
            Kota[i].tujuanKiri=Kota[i+1].tujuanKiri - 1;
        }
        else if (Kota[i+1].tujuanKanan < posisi){
            Kota[i].tujuanKiri=Kota[i+1].tujuanKiri;
        }
    }
    for (int i=0;i<posisi;i++){
        if (Kota[i].tujuanKanan >= posisi){
            Kota[i].tujuanKanan--;
        }
        if (Kota[i].tujuanKiri >= posisi){
            Kota[i].tujuanKiri--;
        }
    }
}

void tampilkanSemua(){
    for(int i=0;i<=M;i++){
        if (Kota[i].tujuanKanan != -1 && Kota[i].tujuanKiri != -1 ){
            cout << "Kota " << Kota[i].nama << " berhubungan dengan Kota " << Kota[Kota[i].tujuanKiri].nama << " dan Kota " << Kota[Kota[i].tujuanKanan].nama << endl;
        }
        else if ((Kota[i].tujuanKanan != -1 && Kota[i].tujuanKiri == -1)){
            cout << "Kota " << Kota[i].nama << " berhubungan dengan Kota " << Kota[Kota[i].tujuanKanan].nama << endl;
        }
        else if ((Kota[i].tujuanKanan == -1 && Kota[i].tujuanKiri != -1)){
            cout << "Kota " << Kota[i].nama << " berhubungan dengan Kota " << Kota[Kota[i].tujuanKiri].nama << endl;
        }
        else if (Kota[i].tujuanKanan == -1 && Kota[i].tujuanKiri == -1 ){
            cout << "Kota " << Kota[i].nama << " tidak berhubungan dengan kota manapun" << endl;
        }
    }
}

int main()
{
    int posisi;

    // MENAMBAHKAN DATA KOTA
    tambah("A",0,0);
    tambah("B",1,1);
    tambah("D",1,-1);
    tambah("F",2,1);
    tambah("E",3,-1);

    // MENGHUBUNGKAN KOTA SATU DENGAN KOTA LAINNYA
    hubungkan("A","B","D");
    hubungkan("B","F","E");
    hubungkan("D","F","E");
    tampilkanSemua();

    // MENCARI DATA KOTA MELALUI NAMA KOTA
    cari("E",&posisi);
    cout << "Kota E berada pada index " << posisi <<endl;

    // MENYISIPKAN DATA KOTA PADA POSISi TERTENTU
    sisipkan("Z",-2,7,2);
    tampilkanSemua();

    // MENGHAPUS DATA KOTA PADA POSISI TERTENTU
    hapus("Z");
    tampilkanSemua();
    return 0;
}
