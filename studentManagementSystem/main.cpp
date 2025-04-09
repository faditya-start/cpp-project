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

struct Attendance {
    string nim;
    string tanggal;
    string status;
    Attendance* next;
};

class DoubleLinkedList {
private:
    Student* head;
    Student* tail;
    
public:
    DoubleLinkedList() {
        head = NULL;
        tail = NULL;
    }
    
    void insertStudent(string nim, string nama, string jurusan, int semester) {
        Student* newStudent = new Student;
        newStudent->nim = nim;
        newStudent->nama = nama;
        newStudent->jurusan = jurusan;
        newStudent->semester = semester;
        newStudent->next = NULL;
        newStudent->prev = NULL;
        
        if (head == NULL) {
            head = tail = newStudent;
        } else {
            tail->next = newStudent;
            newStudent->prev = tail;
            tail = newStudent;
        }
        cout << "Data mahasiswa berhasil ditambahkan!" << endl;
    }
    
    void displayStudents() {
        Student* current = head;
        if (current == NULL) {
            cout << "Tidak ada data mahasiswa" << endl;
            return;
        }
        
        while (current != NULL) {
            cout << "\nNIM: " << current->nim << endl;
            cout << "Nama: " << current->nama << endl;
            cout << "Jurusan: " << current->jurusan << endl;
            cout << "Semester: " << current->semester << endl;
            cout << "------------------------" << endl;
            current = current->next;
        }
    }
    
    Student* searchStudent(string nim) {
        Student* current = head;
        while (current != NULL) {
            if (current->nim == nim) {
                return current;
            }
            current = current->next;
        }
        return NULL;
    }
    
    void deleteStudent(string nim) {
        Student* current = searchStudent(nim);
        if (current == NULL) {
            cout << "Mahasiswa tidak ditemukan" << endl;
            return;
        }
        
        if (current == head && current == tail) {
            head = tail = NULL;
        } else if (current == head) {
            head = head->next;
            head->prev = NULL;
        } else if (current == tail) {
            tail = tail->prev;
            tail->next = NULL;
        } else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }
        
        delete current;
        cout << "Data mahasiswa berhasil dihapus" << endl;
    }
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
    DoubleLinkedList studentList;
    int choice, studentChoice;
    string nim, nama, jurusan;
    int semester;

    do {
        displayMenu();
        cin >> choice;
        
        switch(choice) {
            case 1:
                do {
                    displayStudentMenu();
                    cin >> studentChoice;
                    
                    switch(studentChoice) {
                        case 1:
                            cout << "Masukkan NIM: ";
                            cin >> nim;
                            cout << "Masukkan Nama: ";
                            cin.ignore();
                            getline(cin, nama);
                            cout << "Masukkan Jurusan: ";
                            getline(cin, jurusan);
                            cout << "Masukkan Semester: ";
                            cin >> semester;
                            studentList.insertStudent(nim, nama, jurusan, semester);
                            break;
                        case 2:
                            studentList.displayStudents();
                            break;
                        case 3:
                            cout << "Masukkan NIM yang dicari: ";
                            cin >> nim;
                            if (Student* found = studentList.searchStudent(nim)) {
                                cout << "\nMahasiswa ditemukan:" << endl;
                                cout << "NIM: " << found->nim << endl;
                                cout << "Nama: " << found->nama << endl;
                                cout << "Jurusan: " << found->jurusan << endl;
                                cout << "Semester: " << found->semester << endl;
                            } else {
                                cout << "Mahasiswa tidak ditemukan" << endl;
                            }
                            break;
                        case 4:
                            cout << "Masukkan NIM yang akan dihapus: ";
                            cin >> nim;
                            studentList.deleteStudent(nim);
                            break;
                        case 5:
                            cout << "Kembali ke menu utama..." << endl;
                            break;
                        default:
                            cout << "Pilihan tidak valid!" << endl;
                    }
                } while (studentChoice != 5);
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