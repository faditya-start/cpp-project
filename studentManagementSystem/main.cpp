#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
using namespace std;

// ===== STRUKTUR DATA =====

// 1. Double Linked List untuk Data Mahasiswa
struct Student {
    string nim;
    string nama;
    string jurusan;
    int semester;
    Student* next;
    Student* prev;
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
    
    Student* getHead() const {
        return head;
    }
};

// 2. Circular Linked List untuk Mata Kuliah
struct Course {
    string kode;
    string nama;
    int sks;
    Course* next;
};

class CircularList {
private:
    Course* head;
    
public:
    CircularList() {
        head = NULL;
    }
    
    void insertCourse(string kode, string nama, int sks) {
        Course* newCourse = new Course;
        newCourse->kode = kode;
        newCourse->nama = nama;
        newCourse->sks = sks;
        
        if (head == NULL) {
            head = newCourse;
            newCourse->next = head;
        } else {
            Course* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newCourse;
            newCourse->next = head;
        }
        cout << "Mata kuliah berhasil ditambahkan!" << endl;
    }
    
    void deleteCourse(string kode) {
        if (head == NULL) {
            cout << "Tidak ada mata kuliah" << endl;
            return;
        }
        
        Course* current = head;
        Course* prev = NULL;
        
        do {
            if (current->kode == kode) {
                if (current == head) {
                    if (current->next == head) {
                        head = NULL;
                    } else {
                        Course* last = head;
                        while (last->next != head) {
                            last = last->next;
                        }
                        head = current->next;
                        last->next = head;
                    }
                } else {
                    prev->next = current->next;
                }
                delete current;
                cout << "Mata kuliah berhasil dihapus" << endl;
                return;
            }
            prev = current;
            current = current->next;
        } while (current != head);
        
        cout << "Mata kuliah tidak ditemukan" << endl;
    }
    
    void displayCourses() {
        if (head == NULL) {
            cout << "Tidak ada mata kuliah" << endl;
            return;
        }
        
        Course* current = head;
        cout << "\nDaftar Mata Kuliah:" << endl;
        do {
            cout << "\nKode: " << current->kode << endl;
            cout << "Nama: " << current->nama << endl;
            cout << "SKS: " << current->sks << endl;
            cout << "------------------------" << endl;
            current = current->next;
        } while (current != head);
    }
    
    Course* searchCourse(string kode) {
        if (head == NULL) {
            return NULL;
        }
        
        Course* current = head;
        do {
            if (current->kode == kode) {
                return current;
            }
            current = current->next;
        } while (current != head);
        
        return NULL;
    }
};

// 3. Stack untuk Kehadiran
struct Attendance {
    string nim;
    string tanggal;
    string status;
    Attendance* next;
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
    
    Attendance* getTop() const {
        return top;
    }
};

// 4. Queue untuk Antrian Bimbingan
struct Guidance {
    string nim;
    string nama;
    string keperluan;
    Guidance* next;
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
    
    Guidance* getFront() const {
        return front;
    }
};

// 5. Binary Search Tree untuk Nilai
struct Grade {
    string nim;
    string mataKuliah;
    float nilai;
    Grade* left;
    Grade* right;
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
    
    void preorderRecursive(Grade* node) {
        if (node != NULL) {
            cout << "\nNIM: " << node->nim << endl;
            cout << "Mata Kuliah: " << node->mataKuliah << endl;
            cout << "Nilai: " << node->nilai << endl;
            cout << "------------------------" << endl;
            preorderRecursive(node->left);
            preorderRecursive(node->right);
        }
    }
    
    void postorderRecursive(Grade* node) {
        if (node != NULL) {
            postorderRecursive(node->left);
            postorderRecursive(node->right);
            cout << "\nNIM: " << node->nim << endl;
            cout << "Mata Kuliah: " << node->mataKuliah << endl;
            cout << "Nilai: " << node->nilai << endl;
            cout << "------------------------" << endl;
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
    
    void displayGradesInorder() {
        if (root == NULL) {
            cout << "Tidak ada data nilai" << endl;
            return;
        }
        
        cout << "\nDaftar Nilai (Inorder):" << endl;
        inorderRecursive(root);
    }
    
    void displayGradesPreorder() {
        if (root == NULL) {
            cout << "Tidak ada data nilai" << endl;
            return;
        }
        
        cout << "\nDaftar Nilai (Preorder):" << endl;
        preorderRecursive(root);
    }
    
    void displayGradesPostorder() {
        if (root == NULL) {
            cout << "Tidak ada data nilai" << endl;
            return;
        }
        
        cout << "\nDaftar Nilai (Postorder):" << endl;
        postorderRecursive(root);
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

// ===== MENU DISPLAY =====

void displayStudentMenu() {
    cout << "\n=== Menu Manajemen Mahasiswa (Double Linked List) ===" << endl;
    cout << "1. Tambah Mahasiswa" << endl;
    cout << "2. Tampilkan Semua Mahasiswa" << endl;
    cout << "3. Cari Mahasiswa" << endl;
    cout << "4. Hapus Mahasiswa" << endl;
    cout << "5. Kembali ke Menu Utama" << endl;
    cout << "Pilihan: ";
}

void displayCourseMenu() {
    cout << "\n=== Menu Daftar Mata Kuliah (Circular Linked List) ===" << endl;
    cout << "1. Tambah Mata Kuliah" << endl;
    cout << "2. Tampilkan Semua Mata Kuliah" << endl;
    cout << "3. Cari Mata Kuliah" << endl;
    cout << "4. Hapus Mata Kuliah" << endl;
    cout << "5. Kembali ke Menu Utama" << endl;
    cout << "Pilihan: ";
}

void displayAttendanceMenu() {
    cout << "\n=== Menu Sistem Kehadiran (Stack) ===" << endl;
    cout << "1. Catat Kehadiran" << endl;
    cout << "2. Tampilkan Kehadiran" << endl;
    cout << "3. Hapus Data Terakhir" << endl;
    cout << "4. Kembali ke Menu Utama" << endl;
    cout << "Pilihan: ";
}

void displayGuidanceMenu() {
    cout << "\n=== Menu Antrian Bimbingan (Queue) ===" << endl;
    cout << "1. Daftar Antrian" << endl;
    cout << "2. Panggil Antrian" << endl;
    cout << "3. Lihat Antrian" << endl;
    cout << "4. Kembali ke Menu Utama" << endl;
    cout << "Pilihan: ";
}

void displayGradeMenu() {
    cout << "\n=== Menu Manajemen Nilai (Binary Search Tree) ===" << endl;
    cout << "1. Input Nilai" << endl;
    cout << "2. Tampilkan Nilai (Inorder)" << endl;
    cout << "3. Tampilkan Nilai (Preorder)" << endl;
    cout << "4. Tampilkan Nilai (Postorder)" << endl;
    cout << "5. Cari Nilai Mahasiswa" << endl;
    cout << "6. Hitung IPK" << endl;
    cout << "7. Kembali ke Menu Utama" << endl;
    cout << "Pilihan: ";
}

void displayMenu() {
    cout << "\n=== STUDENT MANAGEMENT SYSTEM ===" << endl;
    cout << "1. Manajemen Data Mahasiswa (Double Linked List)" << endl;
    cout << "2. Sistem Kehadiran (Stack)" << endl;
    cout << "3. Antrian Bimbingan (Queue)" << endl;
    cout << "4. Manajemen Nilai (Binary Search Tree)" << endl;
    cout << "5. Daftar Mata Kuliah (Circular Linked List)" << endl;
    cout << "0. Keluar" << endl;
    cout << "Pilihan: ";
}

// ===== MAIN FUNCTION =====

int main() {
    DoubleLinkedList studentList;
    Stack attendanceStack;
    Queue guidanceQueue;
    BST gradeTree;
    CircularList courseList;
    
    int choice, subChoice;
    string nim, nama, jurusan, tanggal, status, keperluan, kode, mataKuliah;
    int semester, sks;
    float nilai;
    
    do {
        displayMenu();
        cin >> choice;
        
        switch(choice) {
            case 1: // Manajemen Data Mahasiswa (Double Linked List)
                do {
                    displayStudentMenu();
                    cin >> subChoice;
                    
                    switch(subChoice) {
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
                } while (subChoice != 5);
                break;
                
            case 2: // Sistem Kehadiran (Stack)
                do {
                    displayAttendanceMenu();
                    cin >> subChoice;
                    
                    switch(subChoice) {
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
                } while (subChoice != 4);
                break;
                
            case 3: // Antrian Bimbingan (Queue)
                do {
                    displayGuidanceMenu();
                    cin >> subChoice;
                    
                    switch(subChoice) {
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
                } while (subChoice != 4);
                break;
                
            case 4: // Manajemen Nilai (Binary Search Tree)
                do {
                    displayGradeMenu();
                    cin >> subChoice;
                    
                    float gpa;
                    
                    switch(subChoice) {
                        case 1:
                            cout << "Masukkan NIM: ";
                            cin >> nim;
                            cout << "Masukkan Mata Kuliah: ";
                            cin.ignore();
                            getline(cin, mataKuliah);
                            cout << "Masukkan Nilai: ";
                            cin >> nilai;
                            gradeTree.insert(nim, mataKuliah, nilai);
                            break;
                        case 2:
                            gradeTree.displayGradesInorder();
                            break;
                        case 3:
                            gradeTree.displayGradesPreorder();
                            break;
                        case 4:
                            gradeTree.displayGradesPostorder();
                            break;
                        case 5:
                            cout << "Masukkan NIM yang dicari: ";
                            cin >> nim;
                            if (Grade* found = gradeTree.search(nim)) {
                                cout << "\nNilai ditemukan:" << endl;
                                cout << "NIM: " << found->nim << endl;
                                cout << "Mata Kuliah: " << found->mataKuliah << endl;
                                cout << "Nilai: " << found->nilai << endl;
                            } else {
                                cout << "Nilai tidak ditemukan" << endl;
                            }
                            break;
                        case 6:
                            cout << "Masukkan NIM: ";
                            cin >> nim;
                            gpa = gradeTree.calculateGPA(nim);
                            if (gpa > 0) {
                                cout << "IPK: " << gpa << endl;
                            } else {
                                cout << "Data nilai tidak ditemukan" << endl;
                            }
                            break;
                        case 7:
                            cout << "Kembali ke menu utama..." << endl;
                            break;
                        default:
                            cout << "Pilihan tidak valid!" << endl;
                    }
                } while (subChoice != 7);
                break;
                
            case 5: // Daftar Mata Kuliah (Circular Linked List)
                do {
                    displayCourseMenu();
                    cin >> subChoice;
                    
                    switch(subChoice) {
                        case 1:
                            cout << "Masukkan Kode MK: ";
                            cin >> kode;
                            cout << "Masukkan Nama MK: ";
                            cin.ignore();
                            getline(cin, nama);
                            cout << "Masukkan SKS: ";
                            cin >> sks;
                            courseList.insertCourse(kode, nama, sks);
                            break;
                        case 2:
                            courseList.displayCourses();
                            break;
                        case 3:
                            cout << "Masukkan Kode MK yang dicari: ";
                            cin >> kode;
                            if (Course* found = courseList.searchCourse(kode)) {
                                cout << "\nMata Kuliah ditemukan:" << endl;
                                cout << "Kode: " << found->kode << endl;
                                cout << "Nama: " << found->nama << endl;
                                cout << "SKS: " << found->sks << endl;
                            } else {
                                cout << "Mata Kuliah tidak ditemukan" << endl;
                            }
                            break;
                        case 4:
                            cout << "Masukkan Kode MK yang akan dihapus: ";
                            cin >> kode;
                            courseList.deleteCourse(kode);
                            break;
                        case 5:
                            cout << "Kembali ke menu utama..." << endl;
                            break;
                        default:
                            cout << "Pilihan tidak valid!" << endl;
                    }
                } while (subChoice != 5);
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