#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;

const int MAX_USERS = 100;
string users[MAX_USERS][2]; // Menyimpan username dan password
string logs[MAX_USERS][2];  // Menyimpan username dan waktu login
int userCount = 0, logCount = 0;

int main() {
    string username, password;
    int loginAttempts = 0;
    int choice;

    while (true) {
        cout << "\n--- SELAMAT DATANG!! ---\n";
        cout << "1. Registrasi\n2. Login\n3. Exit\nPilih: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            if (userCount < MAX_USERS) {
                cout << "Masukkan Username: ";
                getline(cin, users[userCount][0]);
                cout << "Masukkan Password: ";
                getline(cin, users[userCount][1]);
                cout << "Registrasi Berhasil!\n";
                userCount++;
            } else {
                cout << "User penuh!\n";
            }
        } else if (choice == 2) {
            loginAttempts = 0;
            while (loginAttempts < 3) {
                cout << "Masukkan Username: ";
                getline(cin, username);
                cout << "Masukkan Password: ";
                getline(cin, password);
                
                if (username == "CPPAPL" && password == "CPPC124") {
                    cout << "Login Admin Berhasil!\n";
                    while (true) {
                        cout << "\n=== MENU ADMIN ===\n";
                        cout << "1. Lihat Aktivitas Login\n2. Hapus User\n3. Exit ke Menu Utama\nPilih: ";
                        cin >> choice;
                        cin.ignore();
                        
                        if (choice == 1) {
                            cout << "\n=== Aktivitas Login ===\n";
                            cout << left << setw(20) << "Username" << "Waktu Login\n";
                            cout << "------------------------------\n";
                            for (int i = 0; i < logCount; i++) {
                                cout << left << setw(20) << logs[i][0] << logs[i][1] << "\n";
                            }
                        } else if (choice == 2) {
                            cout << "Masukkan Username yang ingin dihapus: ";
                            string delUser;
                            getline(cin, delUser);
                            bool found = false;
                            for (int i = 0; i < userCount; i++) {
                                if (users[i][0] == delUser) {
                                    users[i][0] = users[userCount - 1][0];
                                    users[i][1] = users[userCount - 1][1];
                                    userCount--;
                                    found = true;
                                    cout << "User berhasil dihapus!\n";
                                    break;
                                }
                            }
                            if (!found) cout << "User tidak ditemukan!\n";
                        } else if (choice == 3) {
                            break;
                        }
                    }
                    break;
                }
                
                bool userFound = false;
                for (int i = 0; i < userCount; i++) {
                    if (users[i][0] == username && users[i][1] == password) {
                        time_t now = time(0);
                        logs[logCount][0] = username;
                        logs[logCount][1] = ctime(&now);
                        logCount++;
                        
                        cout << "Login Berhasil!\n";
                        while (true) {
                            cout << "\n--- MENU KONVERSI MATA UANG --- \n";
                            cout << "1. Rupiah > USD\n2. Yen > Won\n3. Baht > Peso\n4. USD > Yen\n5. Logout\nPilih: ";
                            cin >> choice;
                            if (choice == 5) break;
                            
                            double jumlah, hasil;
                            cout << "Masukkan jumlah: ";
                            cin >> jumlah;
                            
                            switch (choice) {
                                case 1: hasil = jumlah / 15000; cout << "Hasil: " << hasil << " USD\n"; break;
                                case 2: hasil = jumlah * 8.6; cout << "Hasil: " << hasil << " Won\n"; break;
                                case 3: hasil = jumlah * 1.85; cout << "Hasil: " << hasil << " Peso\n"; break;
                                case 4: hasil = jumlah * 150; cout << "Hasil: " << hasil << " Yen\n"; break;
                                default: cout << "Pilihan tidak valid!\n";
                            }
                        }
                        userFound = true;
                        break;
                    }
                }
                if (userFound) break;
                loginAttempts++;
                cout << "Login gagal! Percobaan tersisa: " << (3 - loginAttempts) << "\n";
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
