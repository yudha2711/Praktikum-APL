#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;

const int MAX_USERS = 100;
string users[MAX_USERS][2];
string logs[MAX_USERS][2];
int userCount = 0, logCount = 0;

// Fungsi: Konversi Overloading
double convert(double jumlah, double rate) {
    return jumlah * rate;
}
double convert(double jumlah, string from, string to) {
    if (from == "Rupiah" && to == "USD") return jumlah / 15000;
    if (from == "USD" && to == "Yen") return jumlah * 150;
    if (from == "Yen" && to == "Won") return jumlah * 8.6;
    if (from == "Baht" && to == "Peso") return jumlah * 1.85;
    return 0;
}

// Fungsi dengan parameter address-of
void tambahUser(string* username, string* password) {
    users[userCount][0] = *username;
    users[userCount][1] = *password;
    userCount++;
}

// Prosedur: Registrasi User
void registrasi() {
    if (userCount < MAX_USERS) {
        string username, password;
        cout << "Masukkan Username: ";
        getline(cin, username);
        cout << "Masukkan Password: ";
        getline(cin, password);

        if (username.empty() || password.empty()) {
            cout << "Mohon masukkan username/password!\n";
            return;
        }

        tambahUser(&username, &password); // Pakai pointer (address-of)
        cout << "Registrasi Berhasil!\n";
    } else {
        cout << "User penuh!\n";
    }
}

// Fungsi: Cek login user biasa
bool loginUser(string username, string password) {
    for (int i = 0; i < userCount; i++) {
        if (users[i][0] == username && users[i][1] == password) {
            return true;
        }
    }
    return false;
}

// Prosedur: Simpan log login (pakai dereference pointer)
void simpanLog(string* usernamePtr) {
    time_t now = time(0);
    logs[logCount][0] = *usernamePtr;
    logs[logCount][1] = ctime(&now);
    logCount++;
}

// Fungsi Rekursif: Tampilkan semua log login
void tampilLog(int index = 0) {
    if (index >= logCount) return;
    cout << left << setw(20) << logs[index][0] << logs[index][1];
    tampilLog(index + 1);
}

// Prosedur: Admin Menu
void menuAdmin() {
    int choice;
    while (true) {
        cout << "\n=== MENU ADMIN ===\n";
        cout << "1. Lihat Aktivitas Login\n2. Hapus User\n3. Exit ke Menu Utama\nPilih: ";
        cin >> choice;
        cin.ignore();
        if (choice == 1) {
            cout << "\n=== Aktivitas Login ===\n";
            cout << left << setw(20) << "Username" << "Waktu Login\n";
            cout << "------------------------------\n";
            tampilLog();
        } else if (choice == 2) {
            string delUser;
            cout << "Masukkan Username yang ingin dihapus: ";
            getline(cin, delUser);
            bool found = false;
            for (int i = 0; i < userCount; i++) {
                if (users[i][0] == delUser) {
                    users[i][0] = users[userCount - 1][0];
                    users[i][1] = users[userCount - 1][1];
                    userCount--;
                    cout << "User berhasil dihapus!\n";
                    found = true;
                    break;
                }
            }
            if (!found) cout << "User tidak ditemukan!\n";
        } else if (choice == 3) {
            break;
        }
    }
}

// Prosedur: Menu Konversi
void menuKonversi() {
    int choice;
    while (true) {
        cout << "\n--- MENU KONVERSI MATA UANG ---\n";
        cout << "1. Rupiah > USD\n2. Yen > Won\n3. Baht > Peso\n4. USD > Yen\n5. Logout\nPilih: ";
        cin >> choice;
        if (choice == 5) break;

        double jumlah, hasil;
        cout << "Masukkan jumlah: ";
        cin >> jumlah;

        switch (choice) {
            case 1: hasil = convert(jumlah, "Rupiah", "USD"); cout << "Hasil: " << hasil << " USD\n"; break;
            case 2: hasil = convert(jumlah, 8.6); cout << "Hasil: " << hasil << " Won\n"; break;
            case 3: hasil = convert(jumlah, 1.85); cout << "Hasil: " << hasil << " Peso\n"; break;
            case 4: hasil = convert(jumlah, "USD", "Yen"); cout << "Hasil: " << hasil << " Yen\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    }
}

int main() {
    string username, password;
    int choice;

    while (true) {
        cout << "\n--- SELAMAT DATANG!! ---\n";
        cout << "1. Registrasi\n2. Login\n3. Exit\nPilih: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            registrasi();
        } else if (choice == 2) {
            int loginAttempts = 0;
            while (loginAttempts < 3) {
                cout << "Masukkan Username: ";
                getline(cin, username);
                cout << "Masukkan Password: ";
                getline(cin, password);

                if (username == "CPPAPL" && password == "CPPC124") {
                    cout << "Login Admin Berhasil!\n";
                    menuAdmin();
                    break;
                } else if (loginUser(username, password)) {
                    cout << "Login Berhasil!\n";
                    simpanLog(&username); // kirim pointer ke fungsi simpanLog
                    menuKonversi();
                    break;
                } else {
                    loginAttempts++;
                    cout << "Login gagal! Percobaan tersisa: " << (3 - loginAttempts) << "\n";
                }
            }
            if (loginAttempts == 3) {
                cout << "udah abis kesempatannya, nanti lagi ya!.\n";
                break;
            }
        } else if (choice == 3) {
            cout << "makasih!\n";
            break;
        }
    }
    return 0;
}
