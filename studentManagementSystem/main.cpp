#include <iostream>
#include <string>
using namespace std;

struct Student {
    string nim;
    string nama;
    string jurusan;
    int semester;
    Student* next;
    Student* prev;
};

void displayMenu() {
    cout << "\n=== STUDENT MANAGEMENT SYSTEM ===" << endl;
    cout << "1. Manajemen Data Mahasiswa" << endl;
    cout << "2. Sistem Kehadiran" << endl;
    cout << "3. Antrian Bimbingan" << endl;
    cout << "4. Manajemen Nilai" << endl;
    cout << "5. Daftar Mata Kuliah" << endl;
    cout << "0. Keluar" << endl;
    cout << "Pilihan: ";
}

int main() {
    int choice;
    do {
        displayMenu();
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "\nMenu Manajemen Data Mahasiswa" << endl;
                break;
            case 2:
                cout << "\nMenu Sistem Kehadiran" << endl;
                break;
            case 3:
                cout << "\nMenu Antrian Bimbingan" << endl;
                break;
            case 4:
                cout << "\nMenu Manajemen Nilai" << endl;
                break;
            case 5:
                cout << "\nMenu Daftar Mata Kuliah" << endl;
                break;
            case 0:
                cout << "\nTerima kasih!" << endl;
                break;
            default:
                cout << "\nPilihan tidak valid!" << endl;
        }
    } while (choice != 0);
    
    return 0;
}