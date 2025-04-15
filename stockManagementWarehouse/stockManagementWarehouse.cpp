#include <iostream>
#include <string>
using namespace std;

/*
Namespace Gudang
Berisi fungsi-fungsi yang berkaitan dengan operasi gudang
Menggunakan namespace untuk mengorganisir kode dan menghindari konflik nama
*/
namespace Gudang {
    /**
    Fungsi inline hitungTotalHarga
    Tujuan: Menghitung total harga barang secara efisien
    Parameter:
    - jumlah: Jumlah barang yang akan dihitung
    - hargaSatuan: Harga per unit barang
    Return: Total harga (jumlah * hargaSatuan)
    Catatan: Menggunakan inline untuk optimasi performa pada operasi sederhana
     */
    inline int hitungTotalHarga(int jumlah, int hargaSatuan) {
        return jumlah * hargaSatuan;
    }
}

/*
Fungsi tambahStok
Tujuan: Menambah jumlah stok barang menggunakan pointer
Parameter:
- stok: Pointer ke variabel stok yang akan diubah
- jumlah: Jumlah yang akan ditambahkan ke stok
Catatan: Menggunakan pointer untuk memodifikasi nilai variabel secara langsung
 */
void tambahStok(int* stok, int jumlah) {
    *stok += jumlah;
    cout << "Stok berhasil ditambahkan. Stok sekarang: " << *stok << endl;
}

/*
Fungsi kurangiStok
Tujuan: Mengurangi jumlah stok barang menggunakan referensi
Parameter:
- stok: Referensi ke variabel stok yang akan diubah
- jumlah: Jumlah yang akan dikurangi dari stok
Catatan: 
- Menggunakan referensi untuk memodifikasi nilai variabel secara langsung
- Memiliki pengecekan stok untuk mencegah stok negatif
*/
void kurangiStok(int& stok, int jumlah) {
    if (stok >= jumlah) {
        stok -= jumlah;
        cout << "Stok berhasil dikurangi. Stok sekarang: " << stok << endl;
    } else {
        cout << "Stok tidak mencukupi untuk dikurangi!" << endl;
    }
}

/*
Function Overloading: tampilkanInfo
Versi 1: Menampilkan informasi barang berdasarkan nama
Parameter:
- namaBarang: Nama barang yang akan ditampilkan informasinya
Catatan: Implementasi function overloading untuk fleksibilitas penggunaan
*/
void tampilkanInfo(string namaBarang) {
    cout << "Informasi Barang berdasarkan Nama:" << endl;
    cout << "Nama Barang: " << namaBarang << endl;
    cout << "Status: Tersedia" << endl;
    cout << "------------------------" << endl;
}

/*
Function Overloading: tampilkanInfo
Versi 2: Menampilkan informasi barang berdasarkan ID
Parameter:
- idBarang: ID barang yang akan ditampilkan informasinya
Catatan: Implementasi function overloading untuk fleksibilitas penggunaan
*/
void tampilkanInfo(int idBarang) {
    cout << "Informasi Barang berdasarkan ID:" << endl;
    cout << "ID Barang: " << idBarang << endl;
    cout << "Status: Tersedia" << endl;
    cout << "------------------------" << endl;
}

/*
Fungsi Main
Tujuan: Menjalankan simulasi sistem manajemen stok
Fitur yang didemonstrasikan:
1. Penggunaan pointer untuk menambah stok
2. Penggunaan referensi untuk mengurangi stok
3. Perhitungan total harga menggunakan fungsi inline
4. Function overloading untuk menampilkan informasi
 */
int main() {
    // Inisialisasi variabel
    int stokBarang = 100;
    int hargaSatuan = 50000;
    
    cout << "=== Sistem Manajemen Stok Gudang ===" << endl;
    cout << "Stok awal: " << stokBarang << endl;
    
    //Demo penggunaan pointer untuk menambah stok
    cout << "\nMenambah stok:" << endl;
    tambahStok(&stokBarang, 50);
    
    //Demo penggunaan referensi untuk mengurangi stok
    cout << "\nMengurangi stok:" << endl;
    kurangiStok(stokBarang, 30);
    
    //Demo penggunaan fungsi inline untuk menghitung total harga
    cout << "\nMenghitung total harga:" << endl;
    int totalHarga = Gudang::hitungTotalHarga(stokBarang, hargaSatuan);
    cout << "Total harga untuk " << stokBarang << " barang: Rp " << totalHarga << endl;
    
    //Demo function overloading untuk menampilkan informasi
    cout << "\nMenampilkan informasi barang:" << endl;
    tampilkanInfo("Laptop");
    tampilkanInfo(12345);
    
    return 0;
}