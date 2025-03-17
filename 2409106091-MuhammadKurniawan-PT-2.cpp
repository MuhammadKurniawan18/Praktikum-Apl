#include <iostream>
#include <string>
#include <iomanip> 
using namespace std;

int main() {
    const int MAX_AKUN = 100;
    const int MAX_BUKU = 100;
    
    string akun_pengguna[MAX_AKUN][3]; // [username, password, role]
    
    string judul_buku[MAX_BUKU] = {"One Piece", "Naruto", "Dragon Ball"};
    string harga_buku[MAX_BUKU] = {"50000", "45000", "55000"};
    string penulis_buku[MAX_BUKU] = {"Eiichiro Oda", "Masashi Kishimoto", "Akira Toriyama"};
    
    int jumlah_akun = 0;
    int jumlah_buku = 3;
    string admin_username = "MuhammadKurniawan";
    string admin_password = "2409106091";

    while (true) {
        cout << "Halo! Selamat Datang di List Pembelian Buku Komik " << endl;
        cout << "Silakan pilih 'Daftar akun' jika belum punya akun, dan jika sudah memiliki akun silahkan 'Login'" << endl;
        // cout << "――――――――――――――――――――――――" << endl;
        cout << "1. Daftar akun" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        // cout << "――――――――――――――――――――――――" << endl;
        
        int opsi;
        cout << "Pilih opsi: ";
        cin >> opsi;
        
        if (opsi == 1) {
            cout << "Halo Pengguna baru! Ayo buat akun dulu" << endl;
            string username, password;
            bool usernameExists = false;

            cout << "Username: ";
            cin >> username;

            for (int i = 0; i < jumlah_akun; i++) {
                if (akun_pengguna[i][0] == username) {
                    usernameExists = true;
                    break;
                }
            }

            if (usernameExists) {
                cout << "Username sudah dipakai! Silakan pilih username lain.\n";
            } else {
                cout << "Password: ";
                cin >> password;
                akun_pengguna[jumlah_akun][0] = username;
                akun_pengguna[jumlah_akun][1] = password;
                akun_pengguna[jumlah_akun][2] = "pembeli";
                jumlah_akun++;
                cout << "Akun berhasil terdaftar " << username << "!" << endl;
            }
        } 
        else if (opsi == 2) {
            int attempts = 0;
            bool login_berhasil = false;
            cout << "Hi, Silahkan login dulu ya!" << endl;
            string username, password;
            
            while (attempts < 3) {
                cout << "Masukkan Username: ";
                cin >> username;
                cout << "Masukkan Password: ";
                cin >> password;

                if (username == admin_username && password == admin_password) {
                    login_berhasil = true;
                    break;
                }
                
                for (int i = 0; i < jumlah_akun; i++) {
                    if (akun_pengguna[i][0] == username && akun_pengguna[i][1] == password) {
                        login_berhasil = true;
                        break;
                    }
                }

                if (login_berhasil) break;

                attempts++;
                cout << "Username atau password salah! Percobaan ke-" << attempts << "/3" << endl;
            }

            if (!login_berhasil) {
                cout << "Anda telah gagal login 3 kali. Program kembali ke menu utama.\n";
                continue;
            }

            if (username == admin_username) {

                while (true) {
                    cout << "\nSelamat datang Admin !" << endl;
                    cout << "―――Silakan pilih langkah yang kamu mau!―――" << endl;
                    cout << "1. Tambah Buku" << endl;
                    cout << "2. Edit Buku" << endl;
                    cout << "3. Hapus Buku" << endl;
                    cout << "4. Lihat Buku" << endl;
                    cout << "5. Logout" << endl;

                    int pilihan;
                    cout << "Pilih opsi: ";
                    cin >> pilihan;

                    if (pilihan == 1) {
                        cout << "Masukkan Judul Buku: ";
                        cin >> judul_buku[jumlah_buku];
                        cout << "Masukkan Harga Buku: ";
                        cin >> harga_buku[jumlah_buku];
                        cout << "Masukkan Nama Penulis: ";
                        cin >> penulis_buku[jumlah_buku];
                        jumlah_buku++;
                        cout << "Buku berhasil ditambahkan!" << endl;
                    }
                    else if (pilihan == 2) {
                        cout << "Masukkan nomor buku yang ingin diedit: ";
                        int index;
                        cin >> index;
                        if (index > 0 && index <= jumlah_buku) {
                            cout << "Masukkan Judul Baru: ";
                            cin >> judul_buku[index-1];
                            cout << "Masukkan Harga Baru: ";
                            cin >> harga_buku[index-1];
                            cout << "Masukkan Penulis Baru: ";
                            cin >> penulis_buku[index-1];
                            cout << "Buku berhasil diedit!" << endl;
                        } else {
                            cout << "Nomor buku tidak valid!" << endl;
                        }
                    }
                    else if (pilihan == 3) {
                        cout << "Masukkan nomor buku yang ingin dihapus: ";
                        int index;
                        cin >> index;
                        if (index > 0 && index <= jumlah_buku) {
                            for (int i = index-1; i < jumlah_buku-1; i++) {
                                judul_buku[i] = judul_buku[i+1];
                                harga_buku[i] = harga_buku[i+1];
                                penulis_buku[i] = penulis_buku[i+1];
                            }
                            jumlah_buku--;
                            cout << "Buku berhasil dihapus!" << endl;
                        } else {
                            cout << "Nomor buku tidak valid!" << endl;
                        }
                    }
                    else if (pilihan == 4) {
                        cout << "\nDaftar Buku:\n";
                        cout << left << setw(5) << "No" << setw(20) << "Judul" << setw(10) << "Harga" << setw(20) << "Penulis" << endl;
                        cout << "------------------------------------------------------------\n";
                        for (int i = 0; i < jumlah_buku; i++) {
                            cout << left << setw(5) << i+1 << setw(20) << judul_buku[i] << setw(10) << harga_buku[i] << setw(20) << penulis_buku[i] << endl;
                        }
                    }
                    else if (pilihan == 5) {
                        break;
                    }else {
                        cout << "Input tidak valid,silahkan pilih sesuai nomor di menu" << endl;
                    }
                }
            } 
            else {
                // Pembeli Menu
                cout << "Login Berhasil!" << endl;
                while (true) {
                    cout << "\nSelamat datang " << username << "!" << endl;
                    cout << "―――Silakan pilih langkah yang kamu mau!―――" << endl;
                    cout << "\n1. Lihat Buku" << endl;
                    cout << "2. Beli Buku" << endl;
                    cout << "3. Logout" << endl;
                    int pilihan;
                    cout << "Pilih opsi: ";
                    cin >> pilihan;
                    if (pilihan == 1) {
                        cout << "\nDaftar Buku:\n";
                        cout << left << setw(5) << "No" << setw(20) << "Judul" << setw(10) << "Harga" << setw(20) << "Penulis" << endl;
                        cout << "------------------------------------------------------------\n";
                        for (int i = 0; i < jumlah_buku; i++) {
                            cout << left << setw(5) << i+1 << setw(20) << judul_buku[i] << setw(10) << harga_buku[i] << setw(20) << penulis_buku[i] << endl;
                        }
                    }
                    else if (pilihan == 2) {
                        cout << "Masukkan nomor buku yang ingin dibeli: ";
                        int index;
                        cin >> index;
                        if (index > 0 && index <= jumlah_buku) {
                            cout << "Anda telah membeli buku " << judul_buku[index-1] << "!" << endl;
                        } else {
                            cout << "Nomor buku tidak valid!" << endl;
                        }
                    }
                    else if (pilihan == 3) {
                        break;
                    }else {
                        cout << "Input tidak valid, silahkan pilih 1, 2, atau 3" << endl;
                    }
                }
            }
        }
        else if (opsi == 3) {
            cout << "Terima kasih telah menggunakan aplikasi!" << endl;
            break;
        } else {
            cout << "Input tidak valid, silahkan pilih 1, 2, atau 3" << endl;
        }
        
    }
    return 0;
}