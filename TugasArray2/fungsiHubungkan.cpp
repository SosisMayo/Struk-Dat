void hubungkan(string asal,string tujuanKiri,string tujuanKanan){
    int indexAsal,indexTujuanKiri,indexTujuanKanan;
    cari(asal,&indexAsal);
    cari(tujuanKiri,&indexTujuanKiri);
    cari(tujuanKanan,&indexTujuanKanan);
    Kota[indexAsal].tujuanKiri = indexTujuanKiri;
    Kota[indexAsal].tujuanKanan = indexTujuanKanan;
}