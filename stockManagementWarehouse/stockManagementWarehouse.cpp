#include <iostream>
#include <string>
using namespace std;

// Namespace untuk fungsi-fungsi terkait gudang
namespace Gudang {
    // Fungsi inline untuk menghitung total harga
    inline int hitungTotalHarga(int jumlah, int hargaSatuan) {
        return jumlah * hargaSatuan;
    }
}

// Fungsi untuk menambah stok menggunakan pointer
void tambahStok(int* stok, int jumlah) {
    *stok += jumlah;
    cout << "Stok berhasil ditambahkan. Stok sekarang: " << *stok << endl;
}

// Fungsi untuk mengurangi stok menggunakan referensi
void kurangiStok(int& stok, int jumlah) {
    if (stok >= jumlah) {
        stok -= jumlah;
        cout << "Stok berhasil dikurangi. Stok sekarang: " << stok << endl;
    } else {
        cout << "Stok tidak mencukupi untuk dikurangi!" << endl;
    }
}

// Function overloading untuk menampilkan info barang berdasarkan nama
void tampilkanInfo(string namaBarang) {
    cout << "Informasi Barang berdasarkan Nama:" << endl;
    cout << "Nama Barang: " << namaBarang << endl;
    cout << "Status: Tersedia" << endl;
    cout << "------------------------" << endl;
}

// Function overloading untuk menampilkan info barang berdasarkan ID
void tampilkanInfo(int idBarang) {
    cout << "Informasi Barang berdasarkan ID:" << endl;
    cout << "ID Barang: " << idBarang << endl;
    cout << "Status: Tersedia" << endl;
    cout << "------------------------" << endl;
}

int main() {
    // Inisialisasi variabel
    int stokBarang = 100;
    int hargaSatuan = 50000;
    
    cout << "=== Sistem Manajemen Stok Gudang ===" << endl;
    cout << "Stok awal: " << stokBarang << endl;
    
    // Menggunakan fungsi pointer untuk menambah stok
    cout << "\nMenambah stok:" << endl;
    tambahStok(&stokBarang, 50);
    
    // Menggunakan fungsi referensi untuk mengurangi stok
    cout << "\nMengurangi stok:" << endl;
    kurangiStok(stokBarang, 30);
    
    // Menghitung total harga menggunakan fungsi inline
    cout << "\nMenghitung total harga:" << endl;
    int totalHarga = Gudang::hitungTotalHarga(stokBarang, hargaSatuan);
    cout << "Total harga untuk " << stokBarang << " barang: Rp " << totalHarga << endl;
    
    // Menampilkan informasi barang menggunakan function overloading
    cout << "\nMenampilkan informasi barang:" << endl;
    tampilkanInfo("Laptop");
    tampilkanInfo(12345);
    
    return 0;
} 