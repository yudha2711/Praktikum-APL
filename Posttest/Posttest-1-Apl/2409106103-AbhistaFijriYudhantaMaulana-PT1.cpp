#include <iostream>
using namespace std;

int main() {
    string username, password;
    
    // Sistem Login
    do {
        cout << "Masukkan Username: "; 
        getline(cin, username);
        cin.ignore();
        cout << "Masukkan Password: "; cin >> password;
        if (username != "Abhista Fijri Yudhanta Maulana" || password != "2409106103") {
            cout << "Login gagal Kak! Coba lagi yuk.\n";
        }
    } while (username != "Abhista Fijri Yudhanta Maulana" || password != "2409106103");

    int pilihan;
    do {
        // Menu Utama
        cout << "\n-- Welkam, Punten bang dan Mbak silahkan --\n";
        cout << "1. Hitung Luas\n2. Hitung Keliling\n3. Hitung Volume\n4. Logout\nPilih: ";
        cin >> pilihan;
        
        if (pilihan == 1) {
            int subPilihan;
            do {
                cout << "\n== HITUNG LUAS ==\n";
                cout << "1. Persegi\n2. Persegi Panjang\n3. Lingkaran\n4. Segitiga\n5. Kembali\nPilih: ";
                cin >> subPilihan;
                if (subPilihan == 1) {
                    double sisi;
                    do {
                        cout << "Masukkan sisi: "; cin >> sisi;
                    } while (sisi < 0);
                    cout << "Luas Persegi: " << sisi * sisi << "\n";
                } else if (subPilihan == 2) {
                    double p, l;
                    do {
                        cout << "Masukkan panjang: "; cin >> p;
                        cout << "Masukkan lebar: "; cin >> l;
                    } while (p < 0 || l < 0);
                    cout << "Luas Persegi Panjang: " << p * l << "\n";
                } else if (subPilihan == 3) {
                    double r;
                    do {
                        cout << "Masukkan jari-jari: "; cin >> r;
                    } while (r < 0);
                    cout << "Luas Lingkaran: " << 3.14 * r * r << "\n";
                } else if (subPilihan == 4) {
                    double a, t;
                    do {
                        cout << "Masukkan alas: "; cin >> a;
                        cout << "Masukkan tinggi: "; cin >> t;
                    } while (a < 0 || t < 0);
                    cout << "Luas Segitiga: " << 0.5 * a * t << "\n";
                }
            } while (subPilihan != 5);
        } else if (pilihan == 2) {
            int subPilihan;
            do {
                cout << "\n== HITUNG KELILING ==\n";
                cout << "1. Persegi\n2. Persegi Panjang\n3. Lingkaran\n4. Segitiga\n5. Kembali\nPilih: ";
                cin >> subPilihan;
                if (subPilihan == 1) {
                    double sisi;
                    do {
                        cout << "Masukkan sisi: "; cin >> sisi;
                    } while (sisi < 0);
                    cout << "Keliling Persegi: " << 4 * sisi << "\n";
                } else if (subPilihan == 2) {
                    double p, l;
                    do {
                        cout << "Masukkan panjang: "; cin >> p;
                        cout << "Masukkan lebar: "; cin >> l;
                    } while (p < 0 || l < 0);
                    cout << "Keliling Persegi Panjang: " << 2 * (p + l) << "\n";
                } else if (subPilihan == 3) {
                    double r;
                    do {
                        cout << "Masukkan jari-jari: "; cin >> r;
                    } while (r < 0);
                    cout << "Keliling Lingkaran: " << 2 * 3.14 * r << "\n";
                } else if (subPilihan == 4) {
                    double a, b, c;
                    do {
                        cout << "Masukkan sisi 1: "; cin >> a;
                        cout << "Masukkan sisi 2: "; cin >> b;
                        cout << "Masukkan sisi 3: "; cin >> c;
                    } while (a < 0 || b < 0 || c < 0);
                    cout << "Keliling Segitiga: " << a + b + c << "\n";
                }
            } while (subPilihan != 5);
        } else if (pilihan == 3) {
            int subPilihan;
            do {
                cout << "\n== HITUNG VOLUME ==\n";
                cout << "1. Kubus\n2. Balok\n3. Bola\n4. Kerucut\n5. Kembali\nPilih: ";
                cin >> subPilihan;
                if (subPilihan == 1) {
                    double sisi;
                    do {
                        cout << "Masukkan sisi: "; cin >> sisi;
                    } while (sisi < 0);
                    cout << "Volume Kubus: " << sisi * sisi * sisi << "\n";
                } else if (subPilihan == 2) {
                    double p, l, t;
                    do {
                        cout << "Masukkan panjang: "; cin >> p;
                        cout << "Masukkan lebar: "; cin >> l;
                        cout << "Masukkan tinggi: "; cin >> t;
                    } while (p < 0 || l < 0 || t < 0);
                    cout << "Volume Balok: " << p * l * t << "\n";
                } else if (subPilihan == 3) {
                    double r;
                    do {
                        cout << "Masukkan jari-jari: "; cin >> r;
                    } while (r < 0);
                    cout << "Volume Bola: " << (4.0 / 3.0) * 3.14 * r * r * r << "\n";
                } else if (subPilihan == 4) {
                    double r, t;
                    do {
                        cout << "Masukkan jari-jari: "; cin >> r;
                        cout << "Masukkan tinggi: "; cin >> t;
                    } while (r < 0 || t < 0);
                    cout << "Volume Kerucut: " << (1.0 / 3.0) * 3.14 * r * r * t << "\n";
                }
            } while (subPilihan != 5);
        }
    } while (pilihan != 4);
    
    cout << "Makaseh, nanti balek lagi yaa!!";
    return 0;
}
