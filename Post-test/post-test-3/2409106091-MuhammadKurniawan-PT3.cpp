#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX_AKUN = 100;
const int MAX_BUKU = 100;

// Struct untuk menyimpan informasi buku
struct Buku {
    string judul;
    string harga;
    string penulis;
};

// Struct untuk menyimpan akun pengguna
struct Akun {
    string username;
    string password;
    string role;
};

int main() {
    Akun akun_pengguna[MAX_AKUN];
    Buku daftar_buku[MAX_BUKU] = {
        {"One Piece", "50000", "Eiichiro Oda"},
        {"Naruto", "45000", "Masashi Kishimoto"},
        {"Dragon Ball", "55000", "Akira Toriyama"}
    };
    
    int jumlah_akun = 0;
    int jumlah_buku = 3;
    string admin_username = "MuhammadKurniawan";
    string admin_password = "2409106091";
    int attempts = 0;

    while (true) {
        cout << "\nHalo, selamat datang di list pembelian buku komik" << endl; 
        cout << "1. Daftar akun\n2. Login\n3. Exit\nPilih opsi: ";
        int opsi;
        cin >> opsi;
        
        if (opsi == 1) {
            cout << "\nBuat akun baru!\nUsername: ";
            string username, password;
            cin >> username;
            
            bool usernameExists = false;
            for (int i = 0; i < jumlah_akun; i++) {
                if (akun_pengguna[i].username == username) {
                    usernameExists = true;
                    break;
                }
            }

            if (usernameExists) {
                cout << "Username sudah dipakai!\n";
            } else {
                cout << "Password: ";
                cin >> password;
                akun_pengguna[jumlah_akun] = {username, password, "pembeli"};
                jumlah_akun++;
                cout << "Akun berhasil terdaftar!\n";
            }
        } 
        else if (opsi == 2) {
            if (attempts >= 3) {
                cout << "Anda telah gagal login 3 kali. Program berhenti.\n";
                break;
            }
            
            cout << "\nMasukkan Username: ";
            string username, password;
            cin >> username;
            cout << "Masukkan Password: ";
            cin >> password;
            
            bool login_berhasil = false;
            string role = "pembeli";
            if (username == admin_username && password == admin_password) {
                login_berhasil = true;
                role = "admin";
            }
            
            for (int i = 0; i < jumlah_akun; i++) {
                if (akun_pengguna[i].username == username && akun_pengguna[i].password == password) {
                    login_berhasil = true;
                    break;
                }
            }
            
            if (!login_berhasil) {
                attempts++;
                cout << "Login gagal! Percobaan ke-" << attempts << "/3\n";
                continue;
            }
            
            attempts = 0;
            
            if (role == "admin") {
                while (true) {
                    cout << "\n1. Tambah Buku\n2. Edit Buku\n3. Hapus Buku\n4. Lihat Buku\n5. Logout\nPilih opsi: ";
                    int pilihan;
                    cin >> pilihan;
                    
                    if (pilihan == 1) {
                        cout << "Masukkan Judul Buku: ";
                        cin >> daftar_buku[jumlah_buku].judul;
                        cout << "Masukkan Harga Buku: ";
                        cin >> daftar_buku[jumlah_buku].harga;
                        cout << "Masukkan Nama Penulis: ";
                        cin >> daftar_buku[jumlah_buku].penulis;
                        jumlah_buku++;
                        cout << "Buku berhasil ditambahkan!\n";
                    } 
                    else if (pilihan == 2) {
                        cout << "Masukkan nomor buku yang ingin diedit: ";
                        int index;
                        cin >> index;
                        if (index > 0 && index <= jumlah_buku) {
                            cout << "Masukkan Judul Baru: ";
                            cin >> daftar_buku[index-1].judul;
                            cout << "Masukkan Harga Baru: ";
                            cin >> daftar_buku[index-1].harga;
                            cout << "Masukkan Penulis Baru: ";
                            cin >> daftar_buku[index-1].penulis;
                            cout << "Buku berhasil diedit!\n";
                        }
                    }
                    else if (pilihan == 3) {
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
                    else if (pilihan == 4) {
                        cout << "\nDaftar Buku:\n";
                        for (int i = 0; i < jumlah_buku; i++) {
                            cout << i+1 << ". " << daftar_buku[i].judul << " - " << daftar_buku[i].harga << " - " << daftar_buku[i].penulis << endl;
                        }
                    }
                    else if (pilihan == 5) {
                        break;
                    }
                }
            } else {
                while (true) {
                    cout << "\n1. Lihat Buku\n2. Beli Buku\n3. Logout\nPilih opsi: ";
                    int pilihan;
                    cin >> pilihan;
                    if (pilihan == 1) {
                        cout << "\nDaftar Buku:\n";
                        for (int i = 0; i < jumlah_buku; i++) {
                            cout << i+1 << ". " << daftar_buku[i].judul << " - " << daftar_buku[i].harga << " - " << daftar_buku[i].penulis << endl;
                        }
                    } else if (pilihan == 2) {
                        cout << "Masukkan nomor buku yang ingin dibeli: ";
                        int index;
                        cin >> index;
                        if (index > 0 && index <= jumlah_buku) {
                            cout << "Anda membeli " << daftar_buku[index-1].judul << " seharga " << daftar_buku[index-1].harga << "\n";
                        }
                    } else if (pilihan == 3) {
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
