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

struct Guidance {
    string nim;
    string nama;
    string keperluan;
    Guidance* next;
};

struct Grade {
    string nim;
    string mataKuliah;
    float nilai;
    Grade* left;
    Grade* right;
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

class Stack {
private:
    Attendance* top;
    
public:
    Stack() {
        top = NULL;
    }
    
    void push(string nim, string tanggal, string status) {
        Attendance* newAttendance = new Attendance;
        newAttendance->nim = nim;
        newAttendance->tanggal = tanggal;
        newAttendance->status = status;
        newAttendance->next = top;
        top = newAttendance;
        cout << "Kehadiran berhasil dicatat!" << endl;
    }
    
    void pop() {
        if (isEmpty()) {
            cout << "Tidak ada data kehadiran" << endl;
            return;
        }
        Attendance* temp = top;
        top = top->next;
        delete temp;
        cout << "Data kehadiran terakhir dihapus" << endl;
    }
    
    bool isEmpty() {
        return top == NULL;
    }
    
    void displayAttendance() {
        if (isEmpty()) {
            cout << "Tidak ada data kehadiran" << endl;
            return;
        }
        
        Attendance* current = top;
        cout << "\nDaftar Kehadiran (Terbaru ke Terlama):" << endl;
        while (current != NULL) {
            cout << "\nNIM: " << current->nim << endl;
            cout << "Tanggal: " << current->tanggal << endl;
            cout << "Status: " << current->status << endl;
            cout << "------------------------" << endl;
            current = current->next;
        }
    }
};

class Queue {
private:
    Guidance* front;
    Guidance* rear;
    
public:
    Queue() {
        front = NULL;
        rear = NULL;
    }
    
    void enqueue(string nim, string nama, string keperluan) {
        Guidance* newGuidance = new Guidance;
        newGuidance->nim = nim;
        newGuidance->nama = nama;
        newGuidance->keperluan = keperluan;
        newGuidance->next = NULL;
        
        if (isEmpty()) {
            front = rear = newGuidance;
        } else {
            rear->next = newGuidance;
            rear = newGuidance;
        }
        cout << "Berhasil mendaftar antrian bimbingan!" << endl;
    }
    
    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }
        
        Guidance* temp = front;
        cout << "\nMemanggil mahasiswa:" << endl;
        cout << "NIM: " << temp->nim << endl;
        cout << "Nama: " << temp->nama << endl;
        cout << "Keperluan: " << temp->keperluan << endl;
        
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        delete temp;
    }
    
    bool isEmpty() {
        return front == NULL;
    }
    
    void displayQueue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }
        
        Guidance* current = front;
        int position = 1;
        
        cout << "\nDaftar Antrian Bimbingan:" << endl;
        while (current != NULL) {
            cout << "\nPosisi: " << position << endl;
            cout << "NIM: " << current->nim << endl;
            cout << "Nama: " << current->nama << endl;
            cout << "Keperluan: " << current->keperluan << endl;
            cout << "------------------------" << endl;
            current = current->next;
            position++;
        }
    }
};

class BST {
private:
    Grade* root;
    
    Grade* insertRecursive(Grade* node, string nim, string mataKuliah, float nilai) {
        if (node == NULL) {
            node = new Grade;
            node->nim = nim;
            node->mataKuliah = mataKuliah;
            node->nilai = nilai;
            node->left = node->right = NULL;
            return node;
        }
        
        if (nim < node->nim) {
            node->left = insertRecursive(node->left, nim, mataKuliah, nilai);
        } else if (nim > node->nim) {
            node->right = insertRecursive(node->right, nim, mataKuliah, nilai);
        }
        
        return node;
    }
    
    void inorderRecursive(Grade* node) {
        if (node != NULL) {
            inorderRecursive(node->left);
            cout << "\nNIM: " << node->nim << endl;
            cout << "Mata Kuliah: " << node->mataKuliah << endl;
            cout << "Nilai: " << node->nilai << endl;
            cout << "------------------------" << endl;
            inorderRecursive(node->right);
        }
    }
    
    Grade* searchRecursive(Grade* node, string nim) {
        if (node == NULL || node->nim == nim) {
            return node;
        }
        
        if (nim < node->nim) {
            return searchRecursive(node->left, nim);
        }
        
        return searchRecursive(node->right, nim);
    }
    
public:
    BST() {
        root = NULL;
    }
    
    void insert(string nim, string mataKuliah, float nilai) {
        root = insertRecursive(root, nim, mataKuliah, nilai);
        cout << "Nilai berhasil ditambahkan!" << endl;
    }
    
    void displayGrades() {
        if (root == NULL) {
            cout << "Tidak ada data nilai" << endl;
            return;
        }
        
        cout << "\nDaftar Nilai (Inorder):" << endl;
        inorderRecursive(root);
    }
    
    Grade* search(string nim) {
        return searchRecursive(root, nim);
    }
    
    float calculateGPA(string nim) {
        Grade* current = root;
        float totalNilai = 0;
        int count = 0;
        
        while (current != NULL) {
            if (current->nim == nim) {
                totalNilai += current->nilai;
                count++;
            }
            if (nim < current->nim) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        
        if (count == 0) {
            return 0;
        }
        
        return totalNilai / count;
    }
};

void displayGradeMenu() {
    cout << "\n=== Menu Manajemen Nilai ===" << endl;
    cout << "1. Input Nilai" << endl;
    cout << "2. Tampilkan Semua Nilai" << endl;
    cout << "3. Cari Nilai Mahasiswa" << endl;
    cout << "4. Hitung IPK" << endl;
    cout << "5. Kembali ke Menu Utama" << endl;
    cout << "Pilihan: ";
}

void displayStudentMenu() {
    cout << "\n=== Menu Manajemen Mahasiswa ===" << endl;
    cout << "1. Tambah Mahasiswa" << endl;
    cout << "2. Tampilkan Semua Mahasiswa" << endl;
    cout << "3. Cari Mahasiswa" << endl;
    cout << "4. Hapus Mahasiswa" << endl;
    cout << "5. Kembali ke Menu Utama" << endl;
    cout << "Pilihan: ";
}

void displayAttendanceMenu() {
    cout << "\n=== Menu Sistem Kehadiran ===" << endl;
    cout << "1. Catat Kehadiran" << endl;
    cout << "2. Tampilkan Kehadiran" << endl;
    cout << "3. Hapus Data Terakhir" << endl;
    cout << "4. Kembali ke Menu Utama" << endl;
    cout << "Pilihan: ";
}

void displayGuidanceMenu() {
    cout << "\n=== Menu Antrian Bimbingan ===" << endl;
    cout << "1. Daftar Antrian" << endl;
    cout << "2. Panggil Antrian" << endl;
    cout << "3. Lihat Antrian" << endl;
    cout << "4. Kembali ke Menu Utama" << endl;
    cout << "Pilihan: ";
}

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
            case 2: {
                Stack attendanceStack;
                int attendanceChoice;
                string nim, tanggal, status;
                
                do {
                    displayAttendanceMenu();
                    cin >> attendanceChoice;
                    
                    switch(attendanceChoice) {
                        case 1:
                            cout << "Masukkan NIM: ";
                            cin >> nim;
                            cout << "Masukkan Tanggal (DD/MM/YYYY): ";
                            cin >> tanggal;
                            cout << "Masukkan Status (Hadir/Tidak Hadir): ";
                            cin >> status;
                            attendanceStack.push(nim, tanggal, status);
                            break;
                        case 2:
                            attendanceStack.displayAttendance();
                            break;
                        case 3:
                            attendanceStack.pop();
                            break;
                        case 4:
                            cout << "Kembali ke menu utama..." << endl;
                            break;
                        default:
                            cout << "Pilihan tidak valid!" << endl;
                    }
                } while (attendanceChoice != 4);
                break;
            }
            case 3: {
                Queue guidanceQueue;
                int guidanceChoice;
                string nim, nama, keperluan;
                
                do {
                    displayGuidanceMenu();
                    cin >> guidanceChoice;
                    
                    switch(guidanceChoice) {
                        case 1:
                            cout << "Masukkan NIM: ";
                            cin >> nim;
                            cout << "Masukkan Nama: ";
                            cin.ignore();
                            getline(cin, nama);
                            cout << "Masukkan Keperluan: ";
                            getline(cin, keperluan);
                            guidanceQueue.enqueue(nim, nama, keperluan);
                            break;
                        case 2:
                            guidanceQueue.dequeue();
                            break;
                        case 3:
                            guidanceQueue.displayQueue();
                            break;
                        case 4:
                            cout << "Kembali ke menu utama..." << endl;
                            break;
                        default:
                            cout << "Pilihan tidak valid!" << endl;
                    }
                } while (guidanceChoice != 4);
                break;
            }
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