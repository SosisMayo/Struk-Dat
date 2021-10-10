void cari(string nama,int *posisi){
    *posisi = -1;
    for(int i=0; i<=M; i++){
        if(Kota[i].nama == nama){
            *posisi = i;
            break;
        }
    }
}