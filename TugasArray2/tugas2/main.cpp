#include <iostream>

using namespace std;

// M sebagai penunjuk akhir array, posisi untuk menyimpan index yang dicari
int M = -1;

struct CKota{
    string nama;
    float x,y;
    int indexTujuan[100],indexTerakhirTujuan=-1;
};CKota Kota[100];

void tambah(string nama, float x, float y){
    int N = 99;
    if (M < N){
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

void hubungkan(string asal,string tujuan){
    int indexAsal,indexTujuan,akhir;
    cari(asal,&indexAsal);
    cari(tujuan,&indexTujuan);
    Kota[indexAsal].indexTerakhirTujuan ++;
    akhir = Kota[indexAsal].indexTerakhirTujuan;
    Kota[indexAsal].indexTujuan[akhir] = indexTujuan;

}

void sisipkan(string nama,float x,float y,int posisi){
    int akhir;
    if (M < 99){
        M = M + 1;
        for(int i = M; i >= posisi+1; i--){
            akhir = Kota[i-1].indexTerakhirTujuan;
            Kota[i].nama=Kota[i-1].nama;
            Kota[i].x=Kota[i-1].x;
            Kota[i].y=Kota[i-1].y;
            Kota[i].indexTerakhirTujuan = Kota[i-1].indexTerakhirTujuan;
            for(int j=0;j<=akhir;j++){
                if (Kota[i-1].indexTujuan[j] >= posisi){
                    Kota[i].indexTujuan[j]=Kota[i-1].indexTujuan[j] + 1;
                }
                else if (Kota[i-1].indexTujuan[j] < posisi){
                    Kota[i].indexTujuan[j] = Kota[i-1].indexTujuan[j];
                }
            }
        }
        for (int i=0;i<posisi;i++){
            akhir = Kota[i].indexTerakhirTujuan;
            for(int j=0;j<=akhir;j++){
                if (Kota[i].indexTujuan[j] >= posisi){
                    Kota[i].indexTujuan[j]++;
                }
            }
        }
        Kota[posisi].nama = nama;
        Kota[posisi].x = x;
        Kota[posisi].y = y;
        Kota[posisi].indexTerakhirTujuan=-1;
    }
}

void hapus(string nama){
    int posisi,akhir;
    cari(nama,&posisi);
    if (posisi!=-1){
        M = M -1;
        for (int i = posisi;i<=M;i++){
            akhir = Kota[i+1].indexTerakhirTujuan;
            Kota[i].nama=Kota[i+1].nama;
            Kota[i].x=Kota[i+1].x;
            Kota[i].y=Kota[i+1].y;
            Kota[i].indexTerakhirTujuan = Kota[i+1].indexTerakhirTujuan;
            for(int j=0;j<=akhir;j++){
                if (Kota[i+1].indexTujuan[j] >= posisi){
                    Kota[i].indexTujuan[j] =Kota[i+1].indexTujuan[j] - 1;
                }
                else if (Kota[i+1].indexTujuan[j] < posisi){
                    Kota[i].indexTujuan[j] = Kota[i+1].indexTujuan[j];
                }
            }
        }
        for (int i=0;i<posisi;i++){
            akhir = Kota[i].indexTerakhirTujuan;
            for (int j=0;j<=akhir;j++){
                if (Kota[i].indexTujuan[j] >= posisi){
                Kota[i].indexTujuan[j]--;
                }
            }
        }
    }
    else{
        cout << "Kota yang akan dihapus tidak ditemukan !" << endl;
    }
}

void tampilkanSemua(){
    int akhir;
    for(int i=0;i<=M;i++){
        akhir = Kota[i].indexTerakhirTujuan;
        if (Kota[i].indexTerakhirTujuan==-1){
            cout << "Kota " << Kota[i].nama << " Tidak memiliki hubungan dengan kota manapun" << endl;
        }
        else {
            for(int j=0;j<=akhir;j++){
                cout << "Kota " << Kota[i].nama << " Berhubungan dengan Kota " << Kota[Kota[i].indexTujuan[j]].nama << endl;
            }
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
    hubungkan("A","B");
    hubungkan("A","D");
    hubungkan("B","F");
    hubungkan("B","E");
    hubungkan("D","F");
    hubungkan("D","E");
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
