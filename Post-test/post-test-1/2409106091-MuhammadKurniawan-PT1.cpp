#include <iostream>
#include <cmath> // Untuk fungsi pow
using namespace std;

#define PI 3.14

void hitungLuas();
void hitungKeliling();
void hitungVolume();

int main() {
    string username, password;
    string correctUsername = "Nama Lengkap";
    string correctPassword = "2409106XXX";
    
    // Sistem Login
    do {
        cout << "Masukkan Username: ";
        cin >> username;
        cout << "Masukkan Password: ";
        cin >> password;
        
        if (username != correctUsername || password != correctPassword) {
            cout << "Username atau Password salah! Coba lagi.\n";
        }
    } while (username != correctUsername || password != correctPassword);
    
    int pilihan;
    do {
        cout << "\n== SISTEM HITUNG BANGUN DATAR DAN BANGUN RUANG ==\n";
        cout << "1. Hitung Luas\n";
        cout << "2. Hitung Keliling\n";
        cout << "3. Hitung Volume\n";
        cout << "4. Logout\n";
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
        
        double s, p, l, r, a, t;
        switch (pilihan) {
            case 1:
                cout << "Masukkan sisi persegi: ";
                cin >> s;
                cout << "Luas: " << s * s << "\n";
                break;
            case 2:
                cout << "Masukkan panjang dan lebar: ";
                cin >> p >> l;
                cout << "Luas: " << p * l << "\n";
                break;
            case 3:
                cout << "Masukkan jari-jari lingkaran: ";
                cin >> r;
                cout << "Luas: " << PI * r * r << "\n";
                break;
            case 4:
                cout << "Masukkan alas dan tinggi segitiga: ";
                cin >> a >> t;
                cout << "Luas: " << 0.5 * a * t << "\n";
                break;
            case 5:
                return;
            default:
                cout << "Pilihan tidak valid.\n";
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
        
        double s, p, l, r, a, b, c;
        switch (pilihan) {
            case 1:
                cout << "Masukkan sisi persegi: ";
                cin >> s;
                cout << "Keliling: " << 4 * s << "\n";
                break;
            case 2:
                cout << "Masukkan panjang dan lebar: ";
                cin >> p >> l;
                cout << "Keliling: " << 2 * (p + l) << "\n";
                break;
            case 3:
                cout << "Masukkan jari-jari lingkaran: ";
                cin >> r;
                cout << "Keliling: " << 2 * PI * r << "\n";
                break;
            case 4:
                cout << "Masukkan sisi a, b, dan c segitiga: ";
                cin >> a >> b >> c;
                cout << "Keliling: " << a + b + c << "\n";
                break;
            case 5:
                return;
            default:
                cout << "Pilihan tidak valid.\n";
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
        
        double s, p, l, t, r;
        switch (pilihan) {
            case 1:
                cout << "Masukkan sisi kubus: ";
                cin >> s;
                cout << "Volume: " << pow(s, 3) << "\n";
                break;
            case 2:
                cout << "Masukkan panjang, lebar, dan tinggi balok: ";
                cin >> p >> l >> t;
                cout << "Volume: " << p * l * t << "\n";
                break;
            case 3:
                cout << "Masukkan jari-jari bola: ";
                cin >> r;
                cout << "Volume: " << (4.0 / 3.0) * PI * pow(r, 3) << "\n";
                break;
            case 4:
                cout << "Masukkan jari-jari dan tinggi kerucut: ";
                cin >> r >> t;
                cout << "Volume: " << (1.0 / 3.0) * PI * pow(r, 2) * t << "\n";
                break;
            case 5:
                return;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (true);
}
