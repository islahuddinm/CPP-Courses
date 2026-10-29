
/*

Kelompok:

    1. Nama : Muhammad Islahuddin
       NIM  : 202651050
       Kelas: B Informatika

    2. Nama : M Naufal Hasan Mubarok
       NIM  : 202651063
       Kelas: B Informatika

    3. Nama : Muhamad Nurul Ilmi
       NIM  : 202651064
       Kelas: B Informatika

*/

#include<iostream>

// Compilation Command: g++ 00TokoPrabotan.cpp -o 00TokoPrabotan
// Command for Running .exe File: ./00TokoPrabotan

using namespace std;

int main() {

    cout << "\nDaftar/Stock Barang di Etalase *Toko Prabot*\n"
    "\n"
    "Perabotan Dapur:\n"
    "1. Lamari Dapur - Rp.900.000\n"
    "2. Kursi Dapur - Rp.90.000\n"
    "3. Meja Dapur - Rp.250.000\n"
    "4. Kulkas - Rp.1.150.000\n"
    "5. Kompor - Rp.250.000\n"
    "6. Rice Cooker - Rp.300.000\n"
    "7. Panci - Rp.60.000\n"
    "8. Wajan - Rp.70.000\n"
    "9. Rak Piring - Rp180.000\n"
    // "\n"
    // "Perabotan Kamar Tidur:\n"
    // "10. Kasur\n"
    // "11. Lemari Baju\n"
    // "12. Bantal\n"
    // "13. Guling\n"
    // "14. Selimut\n"
    // "\n"
    // "Perabotan Ruang Tamu:\n"
    // "15. Sofa\n"
    // "16. Meja\n"
    // "17. Karpet\n"
    // "18. Tirai atau Gorden"
    // "19. Jam Dinding\n"
    ;

    int barangPilihan;

    // Perlu menginisialisasi nilai variabel supaya tidak menghasilkan nilai sampah.
    int hargaLemariDapur = 0, hargaKursiDapur = 0, hargaMejaDapur = 0, hargaKulkas = 0,
    hargaKompor = 0, hargaRiceCooker = 0, hargaPanci = 0, hargaWajan = 0, hargaRakPiring = 0;
    
    int jumlahLemariDapurDibeli = 0, jumlahKursiDapurDibeli = 0, jumlahMejaDapurDibeli = 0, jumlahKulkasDibeli = 0,
    jumlahKomporDibeli = 0, jumlahRiceCookerDibeli = 0, jumlahPanciDibeli = 0, jumlahWajanDibeli = 0, jumlahRakPiringDibeli = 0;

    int hargaBarang = 0;
    int jumlahHargaBarangDibeli = 0;
    int jumlahBarangDibeli = 0;
    int total = 0;

    bool loop = true;
    char inginBeli;

    

    while(loop) {

        cout << "\nPilih barang yang dibeli dengan mengetik/menulis nomor urut barang tersebut!" << endl;
        cin >> barangPilihan;

        if(barangPilihan == 1) {
            
            cout << "Masukkan jumlah 'Lemari Dapur': "; cin >> jumlahLemariDapurDibeli;
            hargaLemariDapur = 900000;
            hargaBarang = hargaLemariDapur;

            cout << "\nApakah anda igin menambah barang lagi? y/n" << '\n';
            cin >> inginBeli;
            if(inginBeli == 'n') {
                loop = false;
            } else if(inginBeli == 'y') {
                loop = true;
            } else {
                cout << "*** INPUT TIDAK VALID ***" << endl;
                break;
            }
        }

        else if(barangPilihan == 2) {
            
            cout << "Masukkan jumlah 'Kursi Dapur': "; cin >> jumlahKursiDapurDibeli;
            hargaKursiDapur = 90000;
            hargaBarang = hargaKursiDapur;

            cout << "\nApakah anda igin menambah barang lagi? y/n" << '\n';
            cin >> inginBeli;
            if(inginBeli == 'n') {
                loop = false;
            } else if(inginBeli == 'y') {
                loop = true;
            } else {
                cout << "*** INPUT TIDAK VALID ***" << endl;
                break;
            }
        }

        else if(barangPilihan == 3) {
            
            cout << "Masukkan jumlah 'Meja Dapur': "; cin >> jumlahMejaDapurDibeli;
            hargaMejaDapur = 250000;
            hargaBarang = hargaMejaDapur;

            cout << "\nApakah anda igin menambah barang lagi? y/n" << '\n';
            cin >> inginBeli;
            if(inginBeli == 'n') {
                loop = false;
            } else if(inginBeli == 'y') {
                loop = true;
            } else {
                cout << "*** INPUT TIDAK VALID ***" << endl;
                break;
            }
        }

        else if(barangPilihan == 4) {
            
            cout << "Masukkan jumlah 'Kulkas': "; cin >> jumlahKulkasDibeli;
            hargaKulkas = 1500000;
            hargaBarang = hargaKulkas;

            cout << "\nApakah anda igin menambah barang lagi? y/n" << '\n';
            cin >> inginBeli;
            if(inginBeli == 'n') {
                loop = false;
            } else if(inginBeli == 'y') {
                loop = true;
            } else {
                cout << "*** INPUT TIDAK VALID ***" << endl;
                break;
            }
        }

        else if(barangPilihan == 5) {
            
            cout << "Masukkan jumlah 'Kompor': "; cin >> jumlahKomporDibeli;
            hargaKompor = 250000;
            hargaBarang = hargaKompor;

            cout << "\nApakah anda igin menambah barang lagi? y/n" << '\n';
            cin >> inginBeli;
            if(inginBeli == 'n') {
                loop = false;
            } else if(inginBeli == 'y') {
                loop = true;
            } else {
                cout << "*** INPUT TIDAK VALID ***" << endl;
                break;
            }
        }

        else if(barangPilihan == 6) {
            
            cout << "Masukkan jumlah 'Rice Cooker': "; cin >> jumlahRiceCookerDibeli;
            hargaRiceCooker = 300000;
            hargaBarang = hargaRiceCooker;

            cout << "\nApakah anda igin menambah barang lagi? y/n" << '\n';
            cin >> inginBeli;
            if(inginBeli == 'n') {
                loop = false;
            } else if(inginBeli == 'y') {
                loop = true;
            } else {
                cout << "*** INPUT TIDAK VALID ***" << endl;
                break;
            }
        }

        else if(barangPilihan == 7) {
            
            cout << "Masukkan jumlah 'Panci': "; cin >> jumlahPanciDibeli;
            hargaPanci = 60000;
            hargaBarang = hargaPanci;

            cout << "\nApakah anda igin menambah barang lagi? y/n" << '\n';
            cin >> inginBeli;
            if(inginBeli == 'n') {
                loop = false;
            } else if(inginBeli == 'y') {
                loop = true;
            } else {
                cout << "*** INPUT TIDAK VALID ***" << endl;
                break;
            }
        }

        else if(barangPilihan == 8) {
            
            cout << "Masukkan jumlah 'Wajan': "; cin >> jumlahWajanDibeli;
            hargaWajan = 70000;
            hargaBarang = hargaWajan;

            cout << "\nApakah anda igin menambah barang lagi? y/n" << '\n';
            cin >> inginBeli;
            if(inginBeli == 'n') {
                loop = false;
            } else if(inginBeli == 'y') {
                loop = true;
            } else {
                cout << "*** INPUT TIDAK VALID ***" << endl;
                break;
            }
        }

        else if(barangPilihan == 9) {
            
            cout << "Masukkan jumlah 'Rak Piring': "; cin >> jumlahRakPiringDibeli;
            hargaRakPiring = 180000;
            hargaBarang = hargaRakPiring;

            cout << "\nApakah anda igin menambah barang lagi? y/n" << '\n';
            cin >> inginBeli;
            if(inginBeli == 'n') {
                loop = false;
            } else if(inginBeli == 'y') {
                loop = true;
            } else {
                cout << "*** INPUT TIDAK VALID ***" << endl;
                break;
            }
        }

        else {

            cout << "*** INPUT TIDAK VALID ***" << endl;
            break;
        } 

    }    

    jumlahHargaBarangDibeli = (hargaLemariDapur * jumlahLemariDapurDibeli) + 
    (hargaKursiDapur * jumlahKursiDapurDibeli) + (hargaMejaDapur * jumlahMejaDapurDibeli) +
    (hargaKulkas * jumlahKulkasDibeli) + (hargaKompor * jumlahKomporDibeli) + (hargaRiceCooker * jumlahRiceCookerDibeli) +
    (hargaPanci * jumlahPanciDibeli) + (hargaWajan * jumlahWajanDibeli) + (hargaRakPiring * jumlahRakPiringDibeli);

    jumlahBarangDibeli = jumlahLemariDapurDibeli + jumlahKursiDapurDibeli + jumlahMejaDapurDibeli + jumlahKulkasDibeli +
    jumlahKomporDibeli + jumlahRiceCookerDibeli + jumlahPanciDibeli + jumlahWajanDibeli + jumlahRakPiringDibeli;

    if(jumlahHargaBarangDibeli >= 1000000) {

        // Total ≥ Rp1.000.000: mendapatkan diskon 10%. 

        total = jumlahHargaBarangDibeli - jumlahHargaBarangDibeli / 100 * 10;

        cout << "\n-----------------------------------------------" << endl;
        cout << "\n=================== RECEIPT ===================" << endl;
        //cout << "Harga barang: " << hargaBarang << endl;
        cout << "Jumlah barang \t\t: " << jumlahBarangDibeli << endl;
        cout << "Jumlah harga barang \t: Rp." << jumlahHargaBarangDibeli << endl;
        cout << "Diskon barang \t\t: 10 %" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Total \t\t\t: Rp." << total << endl;
        cout << "-----------------------------------------------" << endl;
    }
    else if(jumlahHargaBarangDibeli >= 500000) {

        // Total ≥ Rp500.000 dan kurang dari Rp1.000.000: mendapatkan diskon 5%. 

        total = jumlahHargaBarangDibeli - jumlahHargaBarangDibeli / 100 * 5;

        cout << "\n-----------------------------------------------" << endl;
        cout << "\n=================== RECEIPT ===================" << endl;
        cout << "\n-----------------------------------------------" << endl;
        //cout << "Harga barang: " << hargaBarang << endl;
        cout << "Jumlah barang \t\t: " << jumlahBarangDibeli << endl;
        cout << "Jumlah harga barang \t: Rp." << jumlahHargaBarangDibeli << endl;
        cout << "Diskon barang \t\t: 5 %" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Total \t\t\t: Rp." << total << endl;
        cout << "-----------------------------------------------" << endl;
    }
    else {

        // Total kurang dari Rp500.000: tidak mendapatkan diskon.

        total = jumlahHargaBarangDibeli;

        cout << "\n-----------------------------------------------" << endl;
        cout << "\n=================== RECEIPT ===================" << endl;
        cout << "\n-----------------------------------------------" << endl;
        //cout << "Harga barang: " << hargaBarang << endl;
        cout << "Jumlah barang \t\t: " << jumlahBarangDibeli << endl;
        cout << "Jumlah harga barang \t: Rp." << jumlahHargaBarangDibeli << endl;
        cout << "Diskon barang \t\t: Tidak Mendapat Diskon" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Total \t\t\t: Rp." << total << endl;
        cout << "-----------------------------------------------" << endl;
    }

    if(jumlahBarangDibeli >= 5 && jumlahHargaBarangDibeli >= 500000) {
        
        cout << "*** ANDA MENDAPAT BONUS ***\n\n";
    } else {

        cout << "*** ANDA TIDAK MENDAPAT BONUS ***\n\n";
    }
    

    

/// EXPERIMENT //////////////////////////////////////////////////////////////////////////////

    // char inginBeli;
    // cout << "\nApakah anda igin membeli barang? y/n" << '\n';
    // cin >> inginBeli;

    // int jumlahBarangDibeli = 0;

    // int barangPilihan1;
    // int barangPilihan2;
    // int barangPilihan3;
    // int barangPilihan4;
    // int barangPilihan5;
    // int barangPilihan6;
    // int barangPilihan7;
    // int barangPilihan8;
    // int barangPilihan9;

    // if(inginBeli == 'y') {

    //     cout << "\nPilih barang yang dibeli dengan mengetik/menulis nomor urut barang tersebut!" << endl;
    //     cin >> barangPilihan1;        
    //     jumlahBarangDibeli++;
        
    //     cout << "\nApakah anda igin menambah barang lagi? Jika tidak, ketik 'n' dan jika iya, silahkan mengetik/menulis nomor urut barang tersebut!" << '\n';
    //     if(inginBeli == 'y') {
    //         cin >> barangPilihan2;
    //         jumlahBarangDibeli++;
    //     }

        
    // }    

    // int lemariDapur;
    // lemariDapur = (barangPilihan1 = 1) ? 100000 : 0;
    // lemariDapur = (barangPilihan2 = 1) ? 100000 : 0;
    // lemariDapur = (barangPilihan3 = 1) ? 100000 : 0;
    // lemariDapur = (barangPilihan4 = 1) ? 100000 : 0;
    // lemariDapur = (barangPilihan5 = 1) ? 100000 : 0;
    // lemariDapur = (barangPilihan6 = 1) ? 100000 : 0;
    // lemariDapur = (barangPilihan7 = 1) ? 100000 : 0;
    // lemariDapur = (barangPilihan8 = 1) ? 100000 : 0;
    // lemariDapur = (barangPilihan9 = 1) ? 100000 : 0;

    // int kursiDapur;
    // kursiDapur = (barangPilihan1 = 1) ? 100000 : 0;    
    // kursiDapur = (barangPilihan2 = 1) ? 100000 : 0;
    // kursiDapur = (barangPilihan3 = 1) ? 100000 : 0;
    // kursiDapur = (barangPilihan4 = 1) ? 100000 : 0;
    // kursiDapur = (barangPilihan5 = 1) ? 100000 : 0;
    // kursiDapur = (barangPilihan6 = 1) ? 100000 : 0;
    // kursiDapur = (barangPilihan7 = 1) ? 100000 : 0;
    // kursiDapur = (barangPilihan8 = 1) ? 100000 : 0;
    // kursiDapur = (barangPilihan9 = 1) ? 100000 : 0;

    

    return 0;
}