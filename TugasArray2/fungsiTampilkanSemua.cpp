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