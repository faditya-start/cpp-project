#include <iostream>
#include <string>
using namespace std;


// Namespace untuk fungsi-fungsi terkait sensor
namespace Sensor {
    // Fungsi inline untuk konversi suhu dari Celsius ke Fahrenheit
    inline float konversiKeFahrenheit(float celsius) {
        return (celsius * 9.0 / 5.0) + 32.0;
    }
    
    // Fungsi untuk menampilkan suhu dalam format Celsius
    void tampilkanSuhu(float suhu) {
        cout << "Suhu saat ini: " << suhu << " C" << endl;
    }
}

// Fungsi untuk memperbarui nilai suhu menggunakan referensi
// Parameter suhu menggunakan referensi (&) sehingga perubahan langsung
// mempengaruhi variabel asli, tidak perlu return value
void updateSuhu(float& suhu, float selisih) {
    suhu += selisih;
    cout << "Suhu diperbarui: " << suhu << " C" << endl;
}

// Function overloading untuk menampilkan alert berdasarkan tipe data
// Versi 1: Menerima parameter float dan menampilkan alert berdasarkan ambang batas
void tampilkanAlert(float suhu) {
    if (suhu > 30.0) {
        cout << "ALERT: Suhu terlalu tinggi! (" << suhu << " C)" << endl;
    } else if (suhu < 18.0) {
        cout << "ALERT: Suhu terlalu rendah! (" << suhu << " C)" << endl;
    } else {
        cout << "Suhu dalam batas normal (" << suhu << " C)" << endl;
    }
}

// Versi 2: Menerima parameter int dan menampilkan pesan umum
// Ini adalah contoh function overloading - nama sama, parameter berbeda
void tampilkanAlert(int suhu) {
    cout << "Pesan umum: Suhu saat ini adalah " << suhu << " C" << endl;
}

int main() {
    // Deklarasi variabel suhu dengan nilai awal
    float suhu = 25.0;
    
    cout << "=== SISTEM MONITORING SUHU RUANGAN ===" << endl;
    
    // Menampilkan suhu awal menggunakan fungsi dari namespace Sensor
    Sensor::tampilkanSuhu(suhu);
    
    // Memperbarui suhu menggunakan fungsi dengan referensi
    // Perhatikan bahwa variabel suhu akan berubah setelah pemanggilan fungsi ini
    updateSuhu(suhu, 2.5);
    
    // Konversi ke Fahrenheit menggunakan fungsi inline dari namespace Sensor
    float suhuFahrenheit = Sensor::konversiKeFahrenheit(suhu);
    cout << "Suhu dalam Fahrenheit: " << suhuFahrenheit << " F" << endl;
    
    // Menampilkan alert berdasarkan suhu (menggunakan function overloading)
    // Ini akan memanggil versi float dari fungsi tampilkanAlert
    tampilkanAlert(suhu);
    
    // Simulasi perubahan suhu
    cout << "\n=== SIMULASI PERUBAHAN SUHU ===" << endl;
    
    // Simulasi suhu naik
    updateSuhu(suhu, 5.0);
    tampilkanAlert(suhu);
    
    // Simulasi suhu turun
    updateSuhu(suhu, -10.0);
    tampilkanAlert(suhu);
    
    // Menggunakan function overloading dengan tipe data int
    // Konversi float ke int menggunakan static_cast
    int suhuInt = static_cast<int>(suhu);
    // Ini akan memanggil versi int dari fungsi tampilkanAlert
    tampilkanAlert(suhuInt);
    
    return 0;
}
