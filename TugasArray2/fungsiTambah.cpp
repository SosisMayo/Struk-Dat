void tambah(string nama, float x, float y){
    int N = 99;
    if (M < N){
        M = M + 1;
        Kota[M].nama = nama;
        Kota[M].x = x;
        Kota[M].y = y;
    }
}