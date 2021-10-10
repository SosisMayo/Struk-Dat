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