#include <iostream>

using namespace std;

// M sebagai penunjuk akhir array, posisi untuk menyimpan index yang dicari
int M = -1;

int main();
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

void hapus(string nama, int *hasil){
    int posisi,akhir;
    cari(nama,&posisi);
    if (posisi!=-1){
        *hasil=1;
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

void inputUser(int pilihan){
    int pilih=99;
    system("CLS");
    if (pilihan==1){
        string nama;
        float x,y;
        cout << "TAMBAH DATA BARU" << endl;
        cout << "Masukkan Nama Kota :" << endl;
        cin >> nama;
        cout << "Masukkan Koordinat X :" << endl;
        cin >> x;
        cout << "Masukkan Koordinat Y :" << endl;
        cin >> y;
        tambah(nama,x,y);
        system("CLS");
        cout << "Data Baru Telah Ditambahkan!" << endl;
    }
    if (pilihan==2){
        string nama;
        int posisi;
        cout << "CARI DATA BERDASARKAN NAMA" << endl;
        cout << "Masukkan Nama Kota :" << endl;
        cin >> nama;
        cari(nama,&posisi);
        system("CLS");
        if (posisi!=-1){
           cout << "Data Kota Ditemukan pada index ke :" << posisi << endl;
           cout << "Nama Kota : "<< nama << endl;
           cout << "Koordinat X : "<< Kota[posisi].x << endl;
           cout << "Koordinat Y : "<< Kota[posisi].y << endl;
        }
        else {
            cout << "Data Kota " << nama << " Tidak Ditemukan!"<< endl;
        }
    }
    if (pilihan==3){
        string nama;
        float x,y,posisi;
        cout << "MENYISIPKAN DATA BARU" << endl;
        cout << "Masukkan Nama Kota :" << endl;
        cin >> nama;
        cout << "Masukkan Koordinat X :" << endl;
        cin >> x;
        cout << "Masukkan Koordinat Y :" << endl;
        cin >> y;
        cout << "Data Disisipkan Pada Index :" << endl;
        cin >> posisi;
        sisipkan(nama,x,y,posisi);
        system("CLS");
        cout << "Data Baru Telah Ditambahkan!" << endl;
    }
    if (pilihan==4){
        string nama;
        int hasil=0;
        cout << "MENGHAPUS DATA" << endl;
        cout << "Masukkan Nama Kota :" << endl;
        cin >> nama;
        hapus(nama,&hasil);
        system("CLS");
        if (hasil==1){
            cout << "Data Telah Dihapus!" << endl;
        }
        else{
            cout << "Data Yang Akan Dihapus Tidak Ditemukan!" << endl;
        }
    }
    if (pilihan==5){
        cout << "Data Kota :" <<endl;
       tampilkanSemua();
    }
    if (pilihan==6){
        string asal,tujuan;
        cout << "SAMBUNGKAN DATA" <<endl;
        cout << "Masukkan Nama Kota Asal : " <<endl;
        cin >> asal;
        cout << "Masukkan Nama Kota Tujuan : " <<endl;
        cin >> tujuan;
        hubungkan(asal,tujuan);
        system("CLS");
        cout << "Data Telah Dihubungkan!" << endl;
    }
    while (pilih!=0 || pilih!=1){
        cout << "Lagi? (1 untuk ya,0 untuk tidak)" << endl;
        cin >> pilih;
        if (pilih==1){
            inputUser(pilihan);
        }
        else if (pilih == 0){
            main();
        }
        else{
            cout << "Input Salah" << endl;
        }
    }
}

int main(){
    int pilihan;
    system("CLS");
    cout << "MENU" << endl;
    cout << "Pilihan 1 : Menambahkan Data Baru" << endl;
    cout << "Pilihan 2 : Mencari Data Berdasarkan Nama" << endl;
    cout << "Pilihan 3 : Menyisipkan Data Baru" << endl;
    cout << "Pilihan 4 : Menghapus Data" << endl;
    cout << "Pilihan 5 : Menampilkan Semua Data" << endl;
    cout << "Pilihan 6 : Sambungkan Data" << endl;
    cout << "Pilihan 7 : Keluar Program" << endl;
    cout << "Masukkan Pilihan Anda ";
    cin >> pilihan;
    switch (pilihan){
    case 1 :
        inputUser(1);
        break;
    case 2 :
        inputUser(2);
        break;
    case 3 :
        inputUser(3);
        break;
    case 4 :
        inputUser(4);
        break;
    case 5 :
        inputUser(5);
        break;
    case 6 :
        inputUser(6);
        break;
    case 7 :
        break;
    }
    return 0;
}
