#include <iostream>
#include <string>
#include <iomanip>
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
        int opsi;
        cin >> opsi;

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
            break;
        }
    }
    return 0;
}

void daftarAkun(Akun akun_pengguna[], int &jumlah_akun) {
    cout << "\nBuat akun baru!\nUsername: ";
    string username, password;
    cin >> username;

    for (int i = 0; i < jumlah_akun; i++) {
        if (akun_pengguna[i].username == username) {
            cout << "Username sudah dipakai!\n";
            return;
        }
    }

    cout << "Password: ";
    cin >> password;
    akun_pengguna[jumlah_akun++] = {username, password, "pembeli"};
    cout << "Akun berhasil terdaftar!\n";
}

bool login(string &role, Akun akun_pengguna[], int jumlah_akun, string admin_username, string admin_password, int &attempts) {
    if (attempts >= 3) {
        cout << "Anda telah gagal login 3 kali. Program berhenti.\n";
        exit(0);
    }

    cout << "\nMasukkan Username: ";
    string username, password;
    cin >> username;
    cout << "Masukkan Password: ";
    cin >> password;

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
        cout << "\n1. Tambah Buku\n2. Edit Buku\n3. Hapus Buku\n4. Lihat Buku\n";
        cout << "5. Lihat Buku (Filter Harga)\n6. Cari Buku\n7. Logout\nPilih opsi: ";
        int pilihan;
        cin >> pilihan;

        switch (pilihan) {
            case 1: tambahBuku(daftar_buku, jumlah_buku); break;
            case 2: editBuku(daftar_buku, jumlah_buku); break;
            case 3: hapusBuku(daftar_buku, jumlah_buku); break;
            case 4: tampilkanBuku(daftar_buku, jumlah_buku); break;
            case 5: {
                int min, max;
                cout << "Masukkan harga minimum: ";
                cin >> min;
                cout << "Masukkan harga maksimum: ";
                cin >> max;
                tampilkanBuku(daftar_buku, jumlah_buku, min, max);
                break;
            }
            case 6: {
                string judul;
                cout << "Masukkan judul buku yang dicari: ";
                cin.ignore();
                getline(cin, judul);
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
            case 7: return;
        }
    }
}

void menuPembeli(Buku daftar_buku[], int jumlah_buku) {
    while (true) {
        cout << "\n1. Lihat Buku\n2. Lihat Buku (Filter Harga)\n3. Cari Buku\n4. Beli Buku\n5. Logout\nPilih opsi: ";
        int pilihan;
        cin >> pilihan;

        switch (pilihan) {
            case 1: tampilkanBuku(daftar_buku, jumlah_buku); break;
            case 2: {
                int min, max;
                cout << "Masukkan harga minimum: ";
                cin >> min;
                cout << "Masukkan harga maksimum: ";
                cin >> max;
                tampilkanBuku(daftar_buku, jumlah_buku, min, max);
                break;
            }
            case 3: {
                string judul;
                cout << "Masukkan judul buku yang dicari: ";
                cin.ignore();
                getline(cin, judul);
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
            case 5: return;
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
    cout << "Masukkan Judul Buku: ";
    cin.ignore();
    getline(cin, daftar_buku[jumlah_buku].judul);
    cout << "Masukkan Harga Buku: ";
    cin >> daftar_buku[jumlah_buku].harga;
    cout << "Masukkan Nama Penulis: ";
    cin.ignore();
    getline(cin, daftar_buku[jumlah_buku].penulis);
    jumlah_buku++;
    cout << "Buku berhasil ditambahkan!\n";
}

void editBuku(Buku daftar_buku[], int jumlah_buku) {
    cout << "Masukkan nomor buku yang ingin diedit: ";
    int index;
    cin >> index;
    if (index > 0 && index <= jumlah_buku) {
        cout << "Masukkan Judul Baru: ";
        cin.ignore();
        getline(cin, daftar_buku[index-1].judul);
        cout << "Masukkan Harga Baru: ";
        cin >> daftar_buku[index-1].harga;
        cout << "Masukkan Penulis Baru: ";
        cin.ignore();
        getline(cin, daftar_buku[index-1].penulis);
        cout << "Buku berhasil diedit!\n";
    }
}

void hapusBuku(Buku daftar_buku[], int &jumlah_buku) {
    cout << "Masukkan nomor buku yang ingin dihapus: ";
    int index;
    cin >> index;
    if (index > 0 && index <= jumlah_buku) {
        for (int i = index-1; i < jumlah_buku-1; i++) {
            daftar_buku[i] = daftar_buku[i+1];
        }
        jumlah_buku--;
        cout << "Buku berhasil dihapus!\n";
    }
}

void beliBuku(Buku daftar_buku[], int jumlah_buku) {
    cout << "Masukkan nomor buku yang ingin dibeli: ";
    int index;
    cin >> index;
    if (index > 0 && index <= jumlah_buku) {
        cout << "Anda membeli " << daftar_buku[index-1].judul << " seharga " << daftar_buku[index-1].harga << "\n";
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