void sisipkan(string nama,float x,float y,int posisi){
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