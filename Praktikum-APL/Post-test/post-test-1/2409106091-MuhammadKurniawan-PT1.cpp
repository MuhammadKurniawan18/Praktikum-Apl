#include <iostream>
#include <cmath> // Untuk fungsi pow
using namespace std;

#define PI 3.14

void hitungLuas();
void hitungKeliling();
void hitungVolume();

double validateInput(string message) {
    double value;
    do {
        cout << message;
        cin >> value;
        if (value < 0) {
            cout << "Input tidak boleh negatif! Silakan masukkan ulang.\n";
        }
    } while (value < 0);
    return value;
}

int main() {
    string username, password;
    string correctUsername = "MuhammadKurniawan";
    string correctPassword = "2409106091";
    
    do {
    cout << "Masukkan Username: ";
    getline(cin, username); //  getline agar bisa menangkap input kosong

    cout << "Masukkan Password: ";
    getline(cin, password);

    if (username.empty() || password.empty()) {
        cout << "Username dan Password tidak boleh kosong! Silakan masukkan kembali.\n";
    } else if (username != correctUsername || password != correctPassword) {
        cout << "Username atau Password salah! Coba lagi.\n";
    }

    } while (username.empty() || password.empty() || username != correctUsername || password != correctPassword);
    
    int pilihan;
    do {
        cout << "\n== SISTEM HITUNG BANGUN DATAR DAN BANGUN RUANG ==\n";
        cout << "1. Hitung Luas\n2. Hitung Keliling\n3. Hitung Volume\n4. Logout\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1: hitungLuas(); break;
            case 2: hitungKeliling(); break;
            case 3: hitungVolume(); break;
            case 4: cout << "Logout berhasil!\n"; break;
            default: cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 4);
    
    return 0;
}

void hitungLuas() {
    int pilihan;
    do {
        cout << "\n== HITUNG LUAS ==\n";
        cout << "1. Persegi\n2. Persegi Panjang\n3. Lingkaran\n4. Segitiga\n5. Kembali\n";
        cout << "Pilih bangun: ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1: {
                double s = validateInput("Masukkan sisi persegi: ");
                cout << "Luas: " << s * s << "\n";
                break;
            }
            case 2: {
                double p = validateInput("Masukkan panjang: ");
                double l = validateInput("Masukkan lebar: ");
                cout << "Luas: " << p * l << "\n";
                break;
            }
            case 3: {
                double r = validateInput("Masukkan jari-jari lingkaran: ");
                cout << "Luas: " << PI * r * r << "\n";
                break;
            }
            case 4: {
                double a = validateInput("Masukkan alas: ");
                double t = validateInput("Masukkan tinggi: ");
                cout << "Luas: " << 0.5 * a * t << "\n";
                break;
            }
            case 5: return;
            default: cout << "Pilihan tidak valid.\n";
        }
    } while (true);
}

void hitungKeliling() {
    int pilihan;
    do {
        cout << "\n== HITUNG KELILING ==\n";
        cout << "1. Persegi\n2. Persegi Panjang\n3. Lingkaran\n4. Segitiga\n5. Kembali\n";
        cout << "Pilih bangun: ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1: {
                double s = validateInput("Masukkan sisi persegi: ");
                cout << "Keliling: " << 4 * s << "\n";
                break;
            }
            case 2: {
                double p = validateInput("Masukkan panjang: ");
                double l = validateInput("Masukkan lebar: ");
                cout << "Keliling: " << 2 * (p + l) << "\n";
                break;
            }
            case 3: {
                double r = validateInput("Masukkan jari-jari lingkaran: ");
                cout << "Keliling: " << 2 * PI * r << "\n";
                break;
            }
            case 4: {
                double a = validateInput("Masukkan sisi pertama segitiga: ");
                double b = validateInput("Masukkan sisi kedua segitiga: ");
                double c = validateInput("Masukkan sisi ketiga segitiga: ");
                cout << "Keliling: " << a + b + c << "\n";
                break;
            }
            case 5: return;
            default: cout << "Pilihan tidak valid.\n";
        }
    } while (true);
}

void hitungVolume() {
    int pilihan;
    do {
        cout << "\n== HITUNG VOLUME ==\n";
        cout << "1. Kubus\n2. Balok\n3. Bola\n4. Kerucut\n5. Kembali\n";
        cout << "Pilih bangun: ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1: {
                double s = validateInput("Masukkan sisi kubus: ");
                cout << "Volume: " << pow(s, 3) << "\n";
                break;
            }
            case 2: {
                double p = validateInput("Masukkan panjang balok: ");
                double l = validateInput("Masukkan lebar balok: ");
                double t = validateInput("Masukkan tinggi balok: ");
                cout << "Volume: " << p * l * t << "\n";
                break;
            }
            case 3: {
                double r = validateInput("Masukkan jari-jari bola: ");
                cout << "Volume: " << (4.0 / 3.0) * PI * pow(r, 3) << "\n";
                break;
            }
            case 4: {
                double r = validateInput("Masukkan jari-jari kerucut: ");
                double t = validateInput("Masukkan tinggi kerucut: ");
                cout << "Volume: " << (1.0 / 3.0) * PI * pow(r, 2) * t << "\n";
                break;
            }
            case 5: return;
            default: cout << "Pilihan tidak valid.\n";
        }
    } while (true);
}
