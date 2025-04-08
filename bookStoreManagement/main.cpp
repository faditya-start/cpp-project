#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

// Custom namespace untuk fungsi-fungsi toko buku
namespace BookStore {
    // Template function untuk perbandingan
    template<typename T>
    T getMax(T a, T b) {
        return (a > b) ? a : b;
    }

    // Template function untuk konversi
    template<typename T, typename U>
    U convert(T value, float rate) {
        return static_cast<U>(value * rate);
    }
}

// Struct untuk menyimpan data buku
struct Book {
    string title;
    string category;
    double price;
    int stock;
    
    // Constructor untuk memudahkan pembuatan objek Book
    Book(string t, string c, double p, int s) 
        : title(t), category(c), price(p), stock(s) {}
};

// Struct untuk menyimpan data transaksi
struct Transaction {
    string bookTitle;
    int quantity;
    double totalPrice;
    string date;
    
    // Constructor
    Transaction(string bt, int q, double tp, string d) 
        : bookTitle(bt), quantity(q), totalPrice(tp), date(d) {}
};

// Deklarasi vector untuk menyimpan data
vector<Book> books;
vector<Transaction> transactions;

// Inline function untuk header
inline void displayHeader() {
    cout << "\n================================\n";
    cout << "   TOKO BUKU DIGITAL SYSTEM     \n";
    cout << "================================\n";
}

// Function untuk membersihkan buffer input
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Function untuk mencari buku
int findBook(const vector<Book>& items, const string& searchTerm) {
    for (int i = 0; i < items.size(); i++) {
        if (items[i].title == searchTerm) {
            return i;
        }
    }
    return -1;
}

// Function untuk mencari transaksi
int findTransaction(const vector<Transaction>& items, const string& searchTerm) {
    for (int i = 0; i < items.size(); i++) {
        if (items[i].bookTitle == searchTerm) {
            return i;
        }
    }
    return -1;
}

// Fungsi yang menggunakan pointer untuk update harga
void updatePrice(Book* book, double newPrice) {
    if (book != nullptr) {
        book->price = newPrice;
        cout << "Harga buku " << book->title << " berhasil diupdate\n";
    }
}

// Overloaded functions untuk menambah stok
void addStock(Book& book, int quantity) {
    if (quantity > 0) {
        book.stock += quantity;
        cout << "Stok berhasil ditambahkan\n";
    } else {
        cout << "Jumlah stok tidak valid\n";
    }
}

void addStock(const string& title, int quantity) {
    int index = findBook(books, title);
    if (index != -1) {
        if (quantity > 0) {
            books[index].stock += quantity;
            cout << "Stok berhasil ditambahkan\n";
        } else {
            cout << "Jumlah stok tidak valid\n";
        }
    } else {
        cout << "Buku tidak ditemukan\n";
    }
}

// Function untuk menampilkan buku
void displayBook(const Book& book) {
    cout << setw(30) << left << book.title 
         << setw(15) << book.category 
         << setw(10) << fixed << setprecision(2) << book.price 
         << setw(10) << book.stock << endl;
}

// Function untuk menambah buku baru
void addNewBook() {
    string title, category;
    double price;
    int stock;
    
    clearInputBuffer();
    cout << "Masukkan judul buku: ";
    getline(cin, title);
    
    cout << "Masukkan kategori: ";
    getline(cin, category);
    
    cout << "Masukkan harga: ";
    while (!(cin >> price) || price < 0) {
        cout << "Harga tidak valid. Masukkan ulang: ";
        clearInputBuffer();
    }
    
    cout << "Masukkan stok awal: ";
    while (!(cin >> stock) || stock < 0) {
        cout << "Stok tidak valid. Masukkan ulang: ";
        clearInputBuffer();
    }
    
    books.push_back(Book(title, category, price, stock));
    cout << "Buku berhasil ditambahkan\n";
}

// Function untuk menampilkan semua buku
void displayAllBooks() {
    if (books.empty()) {
        cout << "Tidak ada buku dalam sistem\n";
        return;
    }
    
    cout << "\nDaftar Buku:\n";
    cout << setw(30) << left << "Judul" 
         << setw(15) << "Kategori" 
         << setw(10) << "Harga" 
         << setw(10) << "Stok" << endl;
    cout << string(65, '-') << endl;
    
    for (const auto& book : books) {
        displayBook(book);
    }
}

// Function untuk mencatat transaksi penjualan
void recordTransaction() {
    string title;
    int quantity;
    
    clearInputBuffer();
    cout << "Masukkan judul buku: ";
    getline(cin, title);
    
    int index = findBook(books, title);
    if (index == -1) {
        cout << "Buku tidak ditemukan\n";
        return;
    }
    
    cout << "Masukkan jumlah: ";
    while (!(cin >> quantity) || quantity <= 0) {
        cout << "Jumlah tidak valid. Masukkan ulang: ";
        clearInputBuffer();
    }
    
    if (quantity > books[index].stock) {
        cout << "Stok tidak mencukupi\n";
        return;
    }
    
    double totalPrice = books[index].price * quantity;
    transactions.push_back(Transaction(title, quantity, totalPrice, "today"));
    books[index].stock -= quantity;
    
    cout << "Transaksi berhasil dicatat\n";
    cout << "Total: Rp" << fixed << setprecision(2) << totalPrice << endl;
}

// Function untuk menghitung total pendapatan
void displayTotalIncome() {
    double total = 0;
    for (const auto& trans : transactions) {
        total += trans.totalPrice;
    }
    cout << "Total pendapatan: Rp" << fixed << setprecision(2) << total << endl;
}

// Function untuk mencari buku
void searchBook() {
    string searchTerm;
    clearInputBuffer();
    cout << "Masukkan judul buku: ";
    getline(cin, searchTerm);
    
    int index = findBook(books, searchTerm);
    if (index != -1) {
        cout << "\nBuku ditemukan:\n";
        cout << setw(30) << left << "Judul" 
             << setw(15) << "Kategori" 
             << setw(10) << "Harga" 
             << setw(10) << "Stok" << endl;
        cout << string(65, '-') << endl;
        displayBook(books[index]);
    } else {
        cout << "Buku tidak ditemukan\n";
    }
}

// Function untuk update stok
void updateStock() {
    string title;
    int quantity;
    
    clearInputBuffer();
    cout << "Masukkan judul buku: ";
    getline(cin, title);
    
    cout << "Masukkan jumlah penambahan stok: ";
    while (!(cin >> quantity) || quantity <= 0) {
        cout << "Jumlah tidak valid. Masukkan ulang: ";
        clearInputBuffer();
    }
    
    addStock(title, quantity);
}

// Function untuk update harga buku
void updateBookPrice() {
    string title;
    clearInputBuffer();
    cout << "Masukkan judul buku: ";
    getline(cin, title);
    
    int index = findBook(books, title);
    if (index != -1) {
        double newPrice;
        cout << "Masukkan harga baru: ";
        cin >> newPrice;
        
        // Menggunakan pointer
        updatePrice(&books[index], newPrice);
    } else {
        cout << "Buku tidak ditemukan\n";
    }
}

// Function untuk konversi harga
void convertPrice() {
    string title;
    clearInputBuffer();
    cout << "Masukkan judul buku: ";
    getline(cin, title);
    
    int index = findBook(books, title);
    if (index != -1) {
        float rate;
        cout << "Masukkan kurs konversi: ";
        cin >> rate;
        
        // Menggunakan template function untuk konversi
        double originalPrice = books[index].price;
        double convertedPrice = BookStore::convert<double, double>(originalPrice, rate);
        
        cout << "Harga asli: Rp" << fixed << setprecision(2) << originalPrice << endl;
        cout << "Harga konversi: Rp" << convertedPrice << endl;
    } else {
        cout << "Buku tidak ditemukan\n";
    }
}

// Menu utama
void displayMenu() {
    displayHeader(); // Menggunakan inline function
    cout << "1. Tambah Buku Baru\n";
    cout << "2. Tampilkan Semua Buku\n";
    cout << "3. Catat Transaksi Penjualan\n";
    cout << "4. Lihat Total Pendapatan\n";
    cout << "5. Cari Buku\n";
    cout << "6. Update Stok\n";
    cout << "7. Update Harga\n";
    cout << "8. Konversi Harga\n";
    cout << "9. Keluar\n";
    cout << "Pilih menu: ";
}

int main() {
    int choice;
    do {
        displayMenu();
        while (!(cin >> choice)) {
            cout << "Input tidak valid. Masukkan angka: ";
            clearInputBuffer();
        }
        
        switch (choice) {
            case 1:
                addNewBook();
                break;
            case 2:
                displayAllBooks();
                break;
            case 3:
                recordTransaction();
                break;
            case 4:
                displayTotalIncome();
                break;
            case 5:
                searchBook();
                break;
            case 6:
                updateStock();
                break;
            case 7:
                updateBookPrice();
                break;
            case 8:
                convertPrice();
                break;
            case 9:
                cout << "Terima kasih telah menggunakan sistem ini\n";
                break;
            default:
                cout << "Pilihan tidak valid\n";
        }
    } while (choice != 9);
    
    return 0;
}