#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

const int MAX_AKUN = 100;
const int MAX_BUKU = 100;

struct Buku {
    string judul;
    string harga;
    string penulis;
};

struct Akun {
    string username;
    string password;
    string role;
};

void daftarAkun(Akun akun_pengguna[], int &jumlah_akun);
bool login(string &role, Akun akun_pengguna[], int jumlah_akun, string admin_username, string admin_password, int &attempts);
void menuAdmin(Buku daftar_buku[], int &jumlah_buku);
void menuPembeli(Buku daftar_buku[], int jumlah_buku);
void tampilkanBuku(Buku daftar_buku[], int jumlah_buku);
void tampilkanBuku(Buku daftar_buku[], int jumlah_buku, int harga_min, int harga_max);
void tambahBuku(Buku daftar_buku[], int &jumlah_buku);
void editBuku(Buku daftar_buku[], int jumlah_buku);
void hapusBuku(Buku daftar_buku[], int &jumlah_buku);
void beliBuku(Buku daftar_buku[], int jumlah_buku);
int cariBuku(Buku daftar_buku[], int jumlah_buku, string judul, int indeks = 0);
void sortBukuByHarga(Buku daftar_buku[], int &jumlah_buku);
void lihatDetailBuku(Buku *buku_ptr);
int getNumericInput();
bool isEmptyOrWhitespace(const string &str);

int getNumericInput() {
    int input;
    cin >> input;
    
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return -1;
    }
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return input;
}

bool isEmptyOrWhitespace(const string &str) {
    for (char c : str) {
        if (!isspace(c)) {
            return false;
        }
    }
    return true;
}

int main() {
    Akun akun_pengguna[MAX_AKUN];
    Buku daftar_buku[MAX_BUKU] = {
        {"One Piece", "50000", "Eiichiro Oda"},
        {"Naruto", "45000", "Masashi Kishimoto"},
        {"Dragon Ball", "55000", "Akira Toriyama"}
    };
    
    int jumlah_akun = 0, jumlah_buku = 3;
    string admin_username = "MuhammadKurniawan";
    string admin_password = "2409106091";
    int attempts = 0;

    while (true) {
        cout << "\nHalo, selamat datang di list pembelian buku komik\n";
        cout << "1. Daftar akun\n2. Login\n3. Exit\nPilih opsi: ";
        
        int opsi = getNumericInput();
        
        if (opsi == -1) {
            cout << "Pilihan tidak valid! Harap masukkan angka." << endl;
            continue;
        }

        if (opsi == 1) {
            daftarAkun(akun_pengguna, jumlah_akun);
        } 
        else if (opsi == 2) {
            string role;
            bool login_berhasil = login(role, akun_pengguna, jumlah_akun, admin_username, admin_password, attempts);
            if (!login_berhasil) continue;

            if (role == "admin") {
                menuAdmin(daftar_buku, jumlah_buku);
            } else {
                menuPembeli(daftar_buku, jumlah_buku);
            }
        } 
        else if (opsi == 3) {
            cout << "Terima kasih telah menggunakan aplikasi kami!";
            break;
        }
        else {
            cout << "Pilihan tidak valid! Harap masukkan angka 1-3." << endl;
        }
    }
    return 0;
}

void daftarAkun(Akun akun_pengguna[], int &jumlah_akun) {
    string username, password;
    
    cout << "\nBuat akun baru!\nUsername: ";
    cin >> username;
    
    if (username.empty()) {
        cout << "Username tidak boleh kosong!" << endl;
        return;
    }

    for (int i = 0; i < jumlah_akun; i++) {
        if (akun_pengguna[i].username == username) {
            cout << "Username sudah dipakai!\n";
            return;
        }
    }

    cout << "Password: ";
    cin >> password;
    
    if (password.empty()) {
        cout << "Password tidak boleh kosong!" << endl;
        return;
    }
    
    akun_pengguna[jumlah_akun++] = {username, password, "pembeli"};
    cout << "Akun berhasil terdaftar!\n";
}

bool login(string &role, Akun akun_pengguna[], int jumlah_akun, string admin_username, string admin_password, int &attempts) {
    if (attempts >= 3) {
        cout << "Anda telah gagal login 3 kali. Program berhenti.\n";
        exit(0);
    }

    string username, password;
    cout << "\nMasukkan Username: ";
    cin >> username;
    
    if (username.empty()) {
        cout << "Username tidak boleh kosong!" << endl;
        attempts++;
        cout << "Login gagal! Percobaan ke-" << attempts << "/3\n";
        return false;
    }
    
    cout << "Masukkan Password: ";
    cin >> password;
    
    if (password.empty()) {
        cout << "Password tidak boleh kosong!" << endl;
        attempts++;
        cout << "Login gagal! Percobaan ke-" << attempts << "/3\n";
        return false;
    }

    if (username == admin_username && password == admin_password) {
        role = "admin";
        attempts = 0;
        return true;
    }

    for (int i = 0; i < jumlah_akun; i++) {
        if (akun_pengguna[i].username == username && akun_pengguna[i].password == password) {
            role = "pembeli";
            attempts = 0;
            return true;
        }
    }

    attempts++;
    cout << "Login gagal! Percobaan ke-" << attempts << "/3\n";
    return false;
}

void menuAdmin(Buku daftar_buku[], int &jumlah_buku) {
    while (true) {
        cout << "\nSelamat Datang Admin, silahkan pilih menu yang anda inginkan!";
        cout << "\n1. Tambah Buku\n2. Edit Buku\n3. Hapus Buku\n4. Lihat Buku\n";
        cout << "5. Lihat Buku (Filter Harga)\n6. Cari Buku\n7. Sort Buku (Address-of)\n";
        cout << "8. Lihat Detail Buku (Dereference)\n9. Logout\n\nPilih opsi: ";
        
        int pilihan = getNumericInput();
        
        if (pilihan == -1) {
            cout << "Pilihan tidak valid! Harap masukkan angka." << endl;
            continue;
        }

        switch (pilihan) {
            case 1: tambahBuku(daftar_buku, jumlah_buku); break;
            case 2: editBuku(daftar_buku, jumlah_buku); break;
            case 3: hapusBuku(daftar_buku, jumlah_buku); break;
            case 4: tampilkanBuku(daftar_buku, jumlah_buku); break;
            case 5: {
                cout << "Masukkan harga minimum: ";
                int min = getNumericInput();
                if (min == -1) {
                    cout << "Input tidak valid! Harap masukkan angka." << endl;
                    continue;
                }
                
                cout << "Masukkan harga maksimum: ";
                int max = getNumericInput();
                if (max == -1) {
                    cout << "Input tidak valid! Harap masukkan angka." << endl;
                    continue;
                }
                
                tampilkanBuku(daftar_buku, jumlah_buku, min, max);
                break;
            }
            case 6: {
                string judul;
                cout << "Masukkan judul buku yang dicari: ";
                cin.ignore(0);
                getline(cin, judul);
                
                if (isEmptyOrWhitespace(judul)) {
                    cout << "Judul tidak boleh kosong!" << endl;
                    continue;
                }
                
                int hasil = cariBuku(daftar_buku, jumlah_buku, judul);
                if (hasil != -1) {
                    cout << "Buku ditemukan pada indeks " << hasil+1 << endl;
                    cout << "Judul: " << daftar_buku[hasil].judul << endl;
                    cout << "Harga: " << daftar_buku[hasil].harga << endl;
                    cout << "Penulis: " << daftar_buku[hasil].penulis << endl;
                } else {
                    cout << "Buku dengan judul '" << judul << "' tidak ditemukan." << endl;
                }
                break;
            }
            case 7: sortBukuByHarga(daftar_buku, jumlah_buku); break;
            case 8: {
                cout << "Masukkan nomor buku yang ingin dilihat detailnya: ";
                int index = getNumericInput();
                
                if (index == -1) {
                    cout << "Input tidak valid! Harap masukkan angka." << endl;
                    continue;
                }
                
                if (index > 0 && index <= jumlah_buku) {
                    lihatDetailBuku(&daftar_buku[index-1]);
                } else {
                    cout << "Nomor buku tidak valid!" << endl;
                }
                break;
            }
            case 9: return;
            default: cout << "Pilihan tidak valid! Harap masukkan angka 1-9." << endl;
        }
    }
}

void menuPembeli(Buku daftar_buku[], int jumlah_buku) {
    while (true) {
        cout << "\nSelamat datang di aplikasi kami!";
        cout << "\n1. Lihat Buku\n2. Lihat Buku (Filter Harga)\n3. Cari Buku\n4. Beli Buku\n";
        cout << "5. Lihat Detail Buku (Dereference)\n6. Logout\n\nPilih opsi: ";
        
        int pilihan = getNumericInput();
        
        if (pilihan == -1) {
            cout << "Pilihan tidak valid! Harap masukkan angka." << endl;
            continue;
        }

        switch (pilihan) {
            case 1: tampilkanBuku(daftar_buku, jumlah_buku); break;
            case 2: {
                cout << "Masukkan harga minimum: ";
                int min = getNumericInput();
                if (min == -1) {
                    cout << "Input tidak valid! Harap masukkan angka." << endl;
                    continue;
                }
                
                cout << "Masukkan harga maksimum: ";
                int max = getNumericInput();
                if (max == -1) {
                    cout << "Input tidak valid! Harap masukkan angka." << endl;
                    continue;
                }
                
                tampilkanBuku(daftar_buku, jumlah_buku, min, max);
                break;
            }
            case 3: {
                string judul;
                cout << "Masukkan judul buku yang dicari: ";
                cin.ignore(0);
                getline(cin, judul);
                
                if (isEmptyOrWhitespace(judul)) {
                    cout << "Judul tidak boleh kosong!" << endl;
                    continue;
                }
                
                int hasil = cariBuku(daftar_buku, jumlah_buku, judul);
                if (hasil != -1) {
                    cout << "Buku ditemukan pada indeks " << hasil+1 << endl;
                    cout << "Judul: " << daftar_buku[hasil].judul << endl;
                    cout << "Harga: " << daftar_buku[hasil].harga << endl;
                    cout << "Penulis: " << daftar_buku[hasil].penulis << endl;
                } else {
                    cout << "Buku dengan judul '" << judul << "' tidak ditemukan." << endl;
                }
                break;
            }
            case 4: beliBuku(daftar_buku, jumlah_buku); break;
            case 5: {
                cout << "Masukkan nomor buku yang ingin dilihat detailnya: ";
                int index = getNumericInput();
                
                if (index == -1) {
                    cout << "Input tidak valid! Harap masukkan angka." << endl;
                    continue;
                }
                
                if (index > 0 && index <= jumlah_buku) {
                    lihatDetailBuku(&daftar_buku[index-1]);
                } else {
                    cout << "Nomor buku tidak valid!" << endl;
                }
                break;
            }
            case 6: return;
            default: cout << "Pilihan tidak valid! Harap masukkan angka 1-6." << endl;
        }
    }
}

void tampilkanBuku(Buku daftar_buku[], int jumlah_buku) {
    cout << "\nDaftar Buku:\n";
    for (int i = 0; i < jumlah_buku; i++) {
        cout << i+1 << ". " << daftar_buku[i].judul << " - " << daftar_buku[i].harga << " - " << daftar_buku[i].penulis << endl;
    }
}

void tampilkanBuku(Buku daftar_buku[], int jumlah_buku, int harga_min, int harga_max) {
    cout << "\nDaftar Buku (Harga " << harga_min << " - " << harga_max << "):\n";
    bool ada_buku = false;
    for (int i = 0; i < jumlah_buku; i++) {
        int harga = stoi(daftar_buku[i].harga);
        if (harga >= harga_min && harga <= harga_max) {
            cout << i+1 << ". " << daftar_buku[i].judul << " - " << daftar_buku[i].harga << " - " << daftar_buku[i].penulis << endl;
            ada_buku = true;
        }
    }
    if (!ada_buku) {
        cout << "Tidak ada buku dalam rentang harga tersebut.\n";
    }
}

void tambahBuku(Buku daftar_buku[], int &jumlah_buku) {
    string judul, harga, penulis;
    
    cout << "Masukkan Judul Buku: ";
    cin.ignore(0);
    getline(cin, judul);
    
    if (isEmptyOrWhitespace(judul)) {
        cout << "Judul tidak boleh kosong!" << endl;
        return;
    }
    
    cout << "Masukkan Harga Buku: ";
    string hargaInput;
    cin >> hargaInput;
    
    bool isNumeric = true;
    for (char c : hargaInput) {
        if (!isdigit(c)) {
            isNumeric = false;
            break;
        }
    }
    
    if (!isNumeric) {
        cout << "Harga tidak valid! Harap masukkan angka." << endl;
        return;
    }
    
    cin.ignore(); 
    cout << "Masukkan Nama Penulis: ";
    getline(cin, penulis);
    
    if (isEmptyOrWhitespace(penulis)) {
        cout << "Nama penulis tidak boleh kosong!" << endl;
        return;
    }
    
    daftar_buku[jumlah_buku].judul = judul;
    daftar_buku[jumlah_buku].harga = hargaInput;
    daftar_buku[jumlah_buku].penulis = penulis;
    jumlah_buku++;
    cout << "Buku berhasil ditambahkan!\n";
}

void editBuku(Buku daftar_buku[], int jumlah_buku) {
    cout << "Masukkan nomor buku yang ingin diedit: ";
    int index = getNumericInput();
    
    if (index == -1) {
        cout << "Input tidak valid! Harap masukkan angka." << endl;
        return;
    }
    
    if (index > 0 && index <= jumlah_buku) {
        string judul, harga, penulis;
        
        cout << "Masukkan Judul Baru: ";
        cin.ignore(0);
        getline(cin, judul);
        
        if (isEmptyOrWhitespace(judul)) {
            cout << "Judul tidak boleh kosong!" << endl;
            return;
        }
        
        cout << "Masukkan Harga Baru: ";
        cin >> harga;
        
        bool isNumeric = true;
        for (char c : harga) {
            if (!isdigit(c)) {
                isNumeric = false;
                break;
            }
        }
        
        if (!isNumeric) {
            cout << "Harga tidak valid! Harap masukkan angka." << endl;
            return;
        }
        
        cin.ignore();
        cout << "Masukkan Penulis Baru: ";
        getline(cin, penulis);
        
        if (isEmptyOrWhitespace(penulis)) {
            cout << "Nama penulis tidak boleh kosong!" << endl;
            return;
        }
        
        daftar_buku[index-1].judul = judul;
        daftar_buku[index-1].harga = harga;
        daftar_buku[index-1].penulis = penulis;
        cout << "Buku berhasil diedit!\n";
    } else {
        cout << "Nomor buku tidak valid!" << endl;
    }
}

void hapusBuku(Buku daftar_buku[], int &jumlah_buku) {
    cout << "Masukkan nomor buku yang ingin dihapus: ";
    int index = getNumericInput();
    
    if (index == -1) {
        cout << "Input tidak valid! Harap masukkan angka." << endl;
        return;
    }
    
    if (index > 0 && index <= jumlah_buku) {
        for (int i = index-1; i < jumlah_buku-1; i++) {
            daftar_buku[i] = daftar_buku[i+1];
        }
        jumlah_buku--;
        cout << "Buku berhasil dihapus!\n";
    } else {
        cout << "Nomor buku tidak valid!" << endl;
    }
}

void beliBuku(Buku daftar_buku[], int jumlah_buku) {
    cout << "Masukkan nomor buku yang ingin dibeli: ";
    int index = getNumericInput();
    
    if (index == -1) {
        cout << "Input tidak valid! Harap masukkan angka." << endl;
        return;
    }
    
    if (index > 0 && index <= jumlah_buku) {
        cout << "Anda membeli " << daftar_buku[index-1].judul << " seharga " << daftar_buku[index-1].harga << "\n";
    } else {
        cout << "Nomor buku tidak valid!" << endl;
    }
}

int cariBuku(Buku daftar_buku[], int jumlah_buku, string judul, int indeks) {
    if (indeks >= jumlah_buku) {
        return -1;
    }
    if (daftar_buku[indeks].judul == judul) {
        return indeks;
    }

    return cariBuku(daftar_buku, jumlah_buku, judul, indeks + 1);
}

void sortBukuByHarga(Buku daftar_buku[], int &jumlah_buku) {
    for (int i = 0; i < jumlah_buku - 1; i++) {
        for (int j = 0; j < jumlah_buku - i - 1; j++) {
            if (stoi(daftar_buku[j].harga) > stoi(daftar_buku[j + 1].harga)) {

                Buku temp = daftar_buku[j];
                daftar_buku[j] = daftar_buku[j + 1];
                daftar_buku[j + 1] = temp;
            }
        }
    }
    
    cout << "Total " << jumlah_buku << " buku telah diurutkan berdasarkan harga (terendah-tertinggi)!" << endl;
    cout << "Jumlah buku setelah pengurutan: " << jumlah_buku << endl;
    tampilkanBuku(daftar_buku, jumlah_buku);
}

void lihatDetailBuku(Buku *buku_ptr) {
    cout << "\n===== Detail Buku =====" << endl;
    cout << "Judul   : " << buku_ptr->judul << endl; 
    cout << "Harga   : Rp " << buku_ptr->harga << endl;
    cout << "Penulis : " << buku_ptr->penulis << endl;
    cout << "\nDetail dengan operator dereference (*)" << endl;
    cout << "Judul buku: " << (*buku_ptr).judul << endl;
    cout << "======================" << endl;
}