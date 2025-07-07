#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> 
#include <cctype>
using namespace std;
// Program parkir

struct Kendaraan
{
  string platNomor;
  string kode;
  string jenis;
  int waktu;
  bool penitipanHelm;
  bool kehilanganKarcis = false;
  bool member;
  float bayar;
  float biaya;
  float diskon = 0; 
  float totalBiaya = 0; 
  int denda = 0;
  float kembalian = 0;
  string metode;
  bool sudahBayar = false;
  bool keluar = false;
  string lokasi; // Lokasi parkir kendaraan
};

struct Pemasukan
{
  float pemasukankendaraan = 0;
};


class Parkir
{
  private:
  int sloatAwalMotor = 50;
  int sloatAwalMobil = 50;
  string cPlat;
  string cKode;
  int jumlah = 10;
  int jumlahKeluar = 0;
  int jumlahDenda = 0;
  Kendaraan kdr[100];
  Pemasukan PemasukanObj[100];
  public:

  Parkir(){
    cout << "\n+================================+";
    cout << endl;
    cout << "|   SELAMAT DATANG DI PARKIRAN   |";
    cout << endl;
    cout << "|           MALL JWALK           |";
    cout << endl;
    cout << "+================================+";
    cout << endl;
  }

  void data()
  {
    kdr[0].platNomor = "AD 2183 CB";
    kdr[0].kode = "A101";
    kdr[0].jenis = "motor";
    kdr[0].waktu = 2;
    kdr[0].penitipanHelm = true;
    kdr[0].kehilanganKarcis = false;
    kdr[0].member = false;
    kdr[0].lokasi = "L1";

    kdr[1].platNomor = "A 1945 SH";
    kdr[1].kode = "A102";
    kdr[1].jenis = "mobil";
    kdr[1].waktu = 10;
    kdr[1].penitipanHelm = false;
    kdr[1].member = false;
    kdr[1].lokasi = "L2";

    kdr[2].platNomor = "B 2600 DSM";
    kdr[2].kode = "A103";
    kdr[2].jenis = "motor";
    kdr[2].waktu = 24;
    kdr[2].penitipanHelm = true;
    kdr[2].member = false;
    kdr[2].lokasi = "L1";
    
    kdr[3].platNomor = "F 7437 UCK";
    kdr[3].kode = "A104";
    kdr[3].jenis = "motor";
    kdr[3].waktu = 5;
    kdr[3].penitipanHelm = true;
    kdr[3].member = false;
    kdr[3].lokasi = "L1";
    
    kdr[4].platNomor = "AA 2475 AAH";
    kdr[4].kode = "A105";
    kdr[4].jenis = "motor";
    kdr[4].waktu = 8;
    kdr[4].penitipanHelm = false;
    kdr[4].member = false;
    kdr[4].lokasi = "L1";

    kdr[5].platNomor = "AB 9841 NT";
    kdr[5].kode = "A106";
    kdr[5].jenis = "mobil";
    kdr[5].waktu = 12;
    kdr[5].penitipanHelm = false;
    kdr[5].member = false;
    kdr[5].lokasi = "L2";

    kdr[6].platNomor = "Z 3563 THR";
    kdr[6].kode = "A107";
    kdr[6].jenis = "motor";
    kdr[6].waktu = 15;
    kdr[6].penitipanHelm = false;
    kdr[6].member = false;
    kdr[6].lokasi = "L1";

    kdr[7].platNomor = "N 1274 EUE";
    kdr[7].kode = "A108";
    kdr[7].jenis = "mobil";
    kdr[7].waktu = 3;
    kdr[7].penitipanHelm = false;
    kdr[7].member = false;
    kdr[7].lokasi = "L2";

    kdr[8].platNomor = "H 9185 RD";
    kdr[8].kode = "A109";
    kdr[8].jenis = "mobil";
    kdr[8].waktu = 9;
    kdr[8].penitipanHelm = false;
    kdr[8].member = false;
    kdr[8].lokasi = "L2";

    kdr[9].platNomor = "J 4823 AWA";
    kdr[9].kode = "A200";
    kdr[9].jenis = "motor";
    kdr[9].waktu = 6;
    kdr[9].penitipanHelm = false;
    kdr[9].member = false;
    kdr[9].lokasi = "L1";

  }
  
  void login()
  {
    int batas = 0;
    string user;
    string pw;

    while (batas < 5){
      cout << "\n+================================+";
      cout << endl;
      cout << "|       LOGIN SEBAGAI ADMIN       |";
      cout << endl;
      cout << "+=================================+";
      cout << endl;
      cout << "Masukkan username: ";
      cin >> user;
      cout << "Masukkan password: ";
      cin >> pw;
      
      if (user != "admin" && pw == "123"){
        cout << "Username salah!";
        cout << endl;
        cout << "Silahkan masukkan username dengan benar";
        cout << endl;
        batas++;
      }
      
      else if(user == "admin" && pw != "123"){
        cout << "Password salah!";
        cout << endl;
        cout << "Silahkan masukkan password dengan benar";
        cout << endl;
        
        batas++;
        
      }
      else if (user == "admin" && pw == "123")
      {
        cout << "+================================+";
        cout << endl;
        cout << "|         LOGIN BERHASIL!        |";
        cout << endl;
        cout << "+================================+";
        cout << endl;
        menuAdmin();
      }
      else
      {
        cout << "Username atau Password salah!";
        cout << endl;
        cout << "Silahkan masukkan username atau password dengan benar" << endl;
        cout << endl;
        batas++;
      
      }

    }  
    cout << "Maaf anda sudah melebihi batas maksimal percobaan login";
    cout << endl;
    exit(0);
  }

  void cekKendaraan()
  {
    int pilihan;
    
    cout << "\n\n+================================+";
    cout << endl;
    cout << "|       MENU CEK KENDARAAN       |";
    cout << endl;
    cout << "+================================+";
    cout << endl;
    cout << "|1. Cari kendaraan               |";
    cout << endl;
    cout << "|2. Cek jenis kendaraan          |";
    cout << endl;
    cout << "|0. Keluar                       |";
    cout << endl;
    cout << "+================================+";
    cout << endl;
    cout << "Silahkan masukkan pilihan anda (masukkan angka): ";
    cin >> pilihan;

    if (cin.fail()) {
            cout << "Input tidak valid! Mohon masukkan angka.";
            cout << endl;
            cin.clear(); // Menghapus flag error
            cin.ignore(10000, '\n'); // Mengabaikan input yang tidak valid
            cekKendaraan(); // Memanggil ulang fungsi untuk meminta input yang benar
    }

    switch (pilihan)
    {
      case 1:
        cariKendaraan();
        break;
      case 2:
        cekJenisKendaraan();
        break;
      case 0:
        menuAdmin();
      break;
      default:
        cout << "Pilihan tidak valid!";
        cout << endl;
        cout << "Mohon masukkan angka yang tertera!";
        cout << endl;
        cekKendaraan(); 
        break;
    }

  }

  void cariKendaraan(){
    int pilihan;

    cout << "\n+================================+";
    cout << endl;
    cout << "|         CARI KENDARAAN         |";
    cout << endl;
    cout << "+================================+";
    cout << endl;
    cout << "|1. Plat Nomor kendaraan         |";
    cout << endl;
    cout << "|2. Kode karcis                  |";
    cout << endl;
    cout << "|0. Keluar                       |";
    cout << endl;
    cout << "+================================+";
    cout << endl;
    cout << "Silahkan masukkan pilihan anda (masukkan angka): ";
    cin >> pilihan;

    if (cin.fail()) {
            cout << "Input tidak valid! Mohon masukkan angka.";
            cout << endl;
            cin.clear(); // Menghapus flag error
            cin.ignore(10000, '\n'); // Mengabaikan input yang tidak valid
            cekKendaraan(); // Memanggil ulang fungsi untuk meminta input yang benar
    }

    switch (pilihan)
    {
      case 1:
        cekPlat();
        break;
      case 2:
        cekKodeKarcis();
        break;
    
      case 0:
        cekKendaraan();
        break;
      default:
        cout << "Pilihan tidak valid!";
        cout << endl;
        cout << "Mohon masukkan angka yang tertera!";
        cout << endl;
        cariKendaraan(); 
        break;
    }
  }

  void cekJenisKendaraan(){
    int pilihan;
    cout << "\n+================================+";
    cout << endl;
    cout << "|    CEK DATA JENIS KENDARAAN    |";
    cout << endl;
    cout << "+================================+";
    cout << endl;
    cout << "|1. Cek data kendaraan motor     |";
    cout << endl;
    cout << "|2. Cek data kendaraan mobil     |";
    cout << endl;
    cout << "|0. Keluar                       |";
    cout << endl;
    cout << "+================================+";
    cout << endl;
    cout << "Silahkan masukkan pilihan anda (masukkan angka): ";
    cin >> pilihan;

    if (cin.fail()) {
            cout << "Input tidak valid! Mohon masukkan angka.";
            cout << endl;
            cin.clear(); // Menghapus flag error
            cin.ignore(10000, '\n'); // Mengabaikan input yang tidak valid
            cekKendaraan(); // Memanggil ulang fungsi untuk meminta input yang benar
    }

    switch (pilihan)
    {
    case 1:
      cekDataMotor();
      break;
    case 2:
      cekDataMobil();
      break;
    case 0:
      cekKendaraan();
      break;
    default:
      cout << "Pilihan tidak valid!";
      cout << endl;
      cout << "Mohon masukkan angka yang tertera!";
      cout << endl;
      cekJenisKendaraan(); 
      break;
    }
  }

  // Menggunakan metode linear search dengan perulangan while dan 2 kondisi
  void cekDataMotor(){
    int jumlahMotor = 0;
    cout << "\nBerikut data nomor plat untuk parkir motor: ";
    cout << endl;
    int i = 0;
    while (i < jumlah) {
      if (kdr[i].jenis == "motor") {
        cout << "Motor ke-" << jumlahMotor + 1 << " dengan nomor plat: " << kdr[i].platNomor;
        cout << endl;
        jumlahMotor++;
      }
      i++;
    }

    cout << "Jumlah data motor yang parkir di mall JWALK sebanyak: " <<  jumlahMotor;
    cout << endl;
    cekJenisKendaraan();
  }
  
  // Menggunakan metode binary search untuk mencari plat nomor mobil
  void cekDataMobil() {
    int jumlahMobil = 0;
    cout << "\nBerikut data nomor plat untuk parkir Mobil: ";
    cout << endl;
    
    for (int i = 0; i < jumlah; i++)
    {
      if (kdr[i].jenis == "mobil")
      {
        jumlahMobil++;
        cout << "Mobil ke-" << jumlahMobil << " dengan nomor plat: " << kdr[i].platNomor;
        cout << endl;;
      }
      
    }

    cout << "Jumlah data mobil yang parkir di mall JWALK sebanyak: " <<  jumlahMobil;
    cout << endl;
    cekJenisKendaraan();
  }
  
  void tambahKendaraan(){
    int tambah;
    string helm;
    notifikasiSlotParkirPenuh();
    cetakSlotMotor();
    cetakSlotMobil();
    cout << "\n+================================+";
    cout << endl;
    cout << "|        TAMBAH KENDARAAN        |";
    cout << endl;
    cout << "+================================+";
    cout << endl;
    cout << "Masukkan jumlah kendaraan yang ingin ditambah: ";
    cin >> tambah;
    
    if (cin.fail()) {
            cout << "Input tidak valid! Mohon masukkan angka.";
            cout << endl;
            cin.clear(); // Menghapus flag error
            cin.ignore(10000, '\n'); // Mengabaikan input yang tidak valid
    }

    if (tambah <= 0)
    {
      cout << "Jumlah kendaraan yang ingin ditambah harus lebih dari 0!";
      cout << endl;
    } else{

      for (int i = 0; i < tambah; i++)
      {
        do {
          cout << "\nMasukkan plat nomor kendaraan: ";
          cin.ignore();
          getline(cin, kdr[jumlah+i].platNomor);
          if (kdr[jumlah+i].platNomor.length() < 5 || kdr[jumlah+i].platNomor.length() > 15) {
            cout << "Plat nomor harus terdiri dari 5 hingga 15 karakter! Silakan masukkan kembali! ";
            cout << endl;
          }
        } while (kdr[jumlah+i].platNomor.length() < 5 || kdr[jumlah+i].platNomor.length() > 15);
  
        do {
          cout << "Tentukan kode karcis kendaraan: ";
          cin >> kdr[jumlah+i].kode;
          if (kdr[jumlah+i].kode.length() != 4) {
            cout << "Kode karcis harus terdiri dari 4 karakter! Silakan masukkan kembali! ";
            cout << endl;
          }
        } while (kdr[jumlah+i].kode.length() != 4);
  
        do {
          cout << "Masukkan jenis kendaraan: ";
          cin >> kdr[jumlah+i].jenis;
          if (kdr[jumlah+i].jenis != "motor" && kdr[jumlah+i].jenis != "mobil") {
            cout << "Jenis kendaraan harus 'motor' atau 'mobil'! Silakan masukkan kembali: ";
            cout << endl;
          }
        } while (kdr[jumlah+i].jenis != "motor" && kdr[jumlah+i].jenis != "mobil");
  
        do {
          cout << "Masukkan waktu lama kendaraan (jam): ";
          cin >> kdr[jumlah+i].waktu;
          if (kdr[jumlah+i].waktu <= 0) {
          cout << "Waktu harus lebih dari 0! Silakan masukkan kembali! ";
          cout << endl;
          }
          if (cin.fail()) {
              cout << "Input tidak valid! Mohon masukkan angka.";
              cout << endl;
              cin.clear(); // Menghapus flag error
              cin.ignore(10000, '\n'); // Mengabaikan input yang tidak valid
              kdr[jumlah+i].waktu = -1; // Set waktu ke nilai negatif untuk mengulangi input
          }
        } while (kdr[jumlah+i].waktu <= 0);
  
        cout << "Apakah ada penitipan helm? (ya/tidak): ";
        cin >> helm;
        if (helm == "ya") {
          kdr[jumlah+i].penitipanHelm = true;
        } else {
          kdr[jumlah+i].penitipanHelm = false;
        }
        do{
          cout << "Masukkan lokasi parkir kendaraan (misal: L1 atau L2): ";
          cin.ignore();
          getline(cin, kdr[jumlah+i].lokasi);
          if (kdr[jumlah+i].lokasi != "L1" && kdr[jumlah+i].lokasi != "L2") {
            cout << "Lokasi parkir harus 'L1' atau 'L2'! Silakan masukkan kembali! ";
            cout << endl;
          }
        } while (kdr[jumlah+i].lokasi != "L1" && kdr[jumlah+i].lokasi != "L2");
    }
    

    }

    cout << "\n+================================+";
    cout << endl;
    cout << "| KENDARAAN BERHASIL DITAMBAHKAN |";
    cout << endl;
    cout << "+================================+";
    cout << endl;
    
    jumlah += tambah;
    menuAdmin();
  }

  void cekPlat() {
    string ulang;
    bool status = false;
    cout << "\nAnda memilih pencarian berdasarkan plat nomor";
    cout << endl;
    cout << "Masukkan plat nomor: ";
    cin.ignore();
    getline(cin, cPlat); 
    for (int i = 0; i < cPlat.length(); i++) {
        cPlat[i] = toupper(cPlat[i]);
    }
    int n = 0, index;
    bool ketemu = false;
    while(n < jumlah && !ketemu){
      if (cPlat == kdr[n].platNomor)
      {
        ketemu = true;
        index = n;
      } else {
        n++;
      }
    }
      if (ketemu)
      {
        cout << "\n======================================================================"; 
        cout << endl;
        cout << "Berikut detail kendaraanya, berdasarkan plat nomor: " << cPlat;
        cout << endl;
        cout << "Plat nomor: " <<  kdr[index].platNomor;
        cout << endl;
        cout << "Kode karcis: " <<  kdr[index].kode;
        cout << endl;
        cout << "Jenis kendaraan: " <<  kdr[index].jenis;
        cout << endl;
        cout << "Lokasi parkir: " << kdr[index].lokasi;
        cout << endl;
        cout << "======================================================================"; 
        cout << endl;
      }
    
    else {
      cout << "\n\n========================================================================"; 
      cout << endl;
      cout << "Kendaraan tidak ditemukan, pastikan anda memasukkan plat nomer yang sesuai";
      cout << endl;
      cout << "=========================================================================="; 
      cout << endl;
    }

    cout << "\nApkah anda ingin menggecek kendaraan yang lain? (ya/tidak): ";
    cin >> ulang;

    if (ulang == "ya")
    {
      cekPlat();
    }
    
  cariKendaraan();
  }
  
  void cekKodeKarcis()
  {
    string ulang;
    cout << "\nAnda memilih pencarian berdasarkan kode karcis";
    cout << endl;
    cout << "Masukkan Kode Karcis: ";
    cin >> cKode;
    for (int i = 0; i < cKode.length(); i++) {
        cKode[i] = toupper(cKode[i]);
    }

    bool ketemu = false;
    int low = 0;
    int high = jumlah - 1;
    int mid;

    while (low <= high && !ketemu) {
      mid = (low + high) / 2;
      if (cKode == kdr[mid].kode) {
        ketemu = true;
      } else if (cKode < kdr[mid].kode) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    
    if (ketemu) {
      cout << "\n======================================================================"; 
      cout << endl;
      cout << "Berikut detail kendaraanya, berdasarkan kode karcis: " << cKode;
      cout << endl;
      cout << "Plat nomor: " <<  kdr[mid].platNomor;
      cout << endl;
      cout << "Kode karcis: " <<  kdr[mid].kode;
      cout << endl;
      cout << "Jenis kendaraan: " <<  kdr[mid].jenis;
      cout << endl;
      cout << "Lokasi parkir: " << kdr[mid].lokasi;
      cout << endl;
      cout << "======================================================================"; 
      cout << endl;
    }
    
    else {
      cout << "\n\n======================================================================"; 
      cout << endl;
      cout << "Kendaraan tidak ditemukan, pastikan anda memasukkan kode karcis yang sesuai";
      cout << endl;
      cout << "======================================================================"; 
      cout << endl;
    }

    cout << "\nApkah anda ingin menggecek kendaraan yang lain? (ya/tidak): ";
    cin >> ulang;
    if (ulang == "ya"){
      cekKodeKarcis();
    }
    
    cariKendaraan();
  }
  
  void slotParkir()
  {
    int pilihan;
    cout << "\n+================================+";
    cout << endl;
    cout << "|          MENU CEK SLOT         |";
    cout << endl;
    cout << "+================================+";
    cout << endl;
    cout << "|1. Cek Slot Motor               |";
    cout << endl;
    cout << "|2. Cek Slot Mobil               |";
    cout << endl;
    cout << "|0. Keluar                       |";
    cout << endl;
    cout << "+================================+";
    cout << endl;
    cout << "Masukkan pilihan (Masukkan angka): ";
    cin >> pilihan;
    
    if (cin.fail()) {
            cout << "Input tidak valid! Mohon masukkan angka.";
            cout << endl;
            cin.clear(); // Menghapus flag error
            cin.ignore(10000, '\n'); // Mengabaikan input yang tidak valid
            cekKendaraan(); // Memanggil ulang fungsi untuk meminta input yang benar
    }

    switch (pilihan)
    {
    case 1:
      cetakSlotMotor();
      slotParkir();

      break;
      case 2:
      cetakSlotMobil();
      slotParkir();

      break;
    case 0:
      menuAdmin();
      break;
    default:
      cout << "Pilihan tidak valid!";
      cout << endl;
      cout << "Mohon masukkan angka yang tertera!";
      cout << endl;
      slotParkir();
      break;
    }
    
  }
  
  int slotMotor()
  {
    int motor = 0;
    for (int i = 0; i < jumlah; i++)
    {
      if (kdr[i].jenis == "motor")
      {
        motor++;
      }
      
    }
      return motor;
  }

  int slotMobil()
  {
    int mobil = 0;
    for (int i = 0; i < jumlah; i++)
    {
      if (kdr[i].jenis == "mobil")
      {
        mobil++;
      }
      
    }
      return mobil;
  }

  void cetakSlotMotor(){
    cout << "\n+================================+";
    cout << endl;
    cout << "|           SLOT MOTOR           |";
    cout << endl;
    cout << "+================================+";
    cout << endl;
    cout << "slot motor terpakai : ";
    cout << slotMotor();
    cout << "\nSlot motor tersedia : " << sloatAwalMotor - slotMotor();
    cout << endl;
    cout << "+================================+";
    cout << endl;
  }

  void cetakSlotMobil(){
    cout << "\n+================================+";
    cout << endl;
    cout << "|           SLOT MOBIL           |";
    cout << endl;
    cout << "+================================+";
    cout << endl;
    cout << "Slot mobil terpakai : ";
    cout << slotMobil();
    cout << "\nSlot mobil tersedia : " << sloatAwalMotor - slotMobil() << endl;
    cout << "+================================+";
    cout << endl;
  }
  
  void hitungTransaksi(){
    string karcis, cekKarcis, cekMember;
    int temp = 0;
    bool status = false;
    cout << "\n+================================+";
    cout << endl;
    cout << "|     MENU HITUNG TRANSAKSI      |";
    cout << endl;
    cout << "+================================+";
    cout << endl;
    cout << "Apakah ada karcis? (ya/tidak): ";
    cin >> cekKarcis;
    if (cekKarcis == "ya")
    {
      cout << "Masukkan kode karcis: ";
      cin >> karcis;

      for (int i = 0; i < karcis.length(); i++) {
        karcis[i] = toupper(karcis[i]);
    }

      for (int i = 0; i < jumlah; i++)
      {
        if (karcis == kdr[i].kode)
        {
          cout << "kendaraan ditemukan";
          cout << endl;
          status = true;
          break;
        }
        temp++;
      }

      if (status == true)
      {
        tampilKarcis(temp);
        if (kdr[temp].jenis == "motor")
        {
          cout << "\ncek adanya penitipan helm!";
          cout << endl;
          cout << "Proses pengecekan helm sedang dilakukan...";
          cout << endl;
          system("timeout /t 3 >nul");
          cout << "pengecekan selesai!";
          cout << endl;
          if (kdr[temp].penitipanHelm == true)
          {
            cout << "Ada penitipan helm pada kendaraan ini.";
            cout << endl;
          } else {
            cout << "Tidak ada penitipan helm pada kendaraan ini.";
            cout << endl;
          }
        }
        
        cout << "Apakah ada member mall? (ya/tidak): ";
        cin >> cekMember;
        if (cekMember == "ya")
        {
          kdr[temp].member = true;
        }
      
        biaya(temp);
        
        cout << "\n==============================";
        cout << endl;
        cout << "|       Struk Parkir         |";
        cout << endl;
        cout << "==============================";
        cout << endl;
        cout << "| Plat Nomor: "<<  kdr[temp].platNomor;
        cout << endl;
        cout << "| Kode karcis: "<<  kdr[temp].kode;
        cout << endl;
        cout << "| Jenis kendaraan: " << kdr[temp].jenis;
        cout << endl;
        cout << "| Ada penambahan penitipan: ";
        if (kdr[temp].penitipanHelm) {
          cout << "ya";
        } else {
          cout << "tidak";
        }
        cout << endl;
        cout << "| Member: ";
        if (kdr[temp].member) {
          cout << "ya";
        } else {
          cout << "tidak";
        }
        cout << endl;
        cout << "| Total waktu parkir: " << kdr[temp].waktu << " Jam";
        cout << endl;
        cout << "==============================";
  
        cout << endl;
        cout << "| Harga Parkir: " << kdr[temp].biaya;
        cout << endl;
        cout << "| Denda karcis hilang: " << kdr[temp].denda;
        cout << endl;
        cout << "| Diskon member: " << kdr[temp].diskon;
        cout << endl;
        cout << "| Total biaya: " << kdr[temp].totalBiaya;
        cout << endl;
        cout << "==============================";
        cout << endl;
        pembayaran(temp);

      } else {
        cout << "Kendaraan tidak ditemukan, Mohon masukkan nomor karcis yang sesuai!";
        cout << endl << endl;
        kdr[temp].kehilanganKarcis = true;
        hitungTransaksi();
      }
      
    } else{
      hilangKarcis();
    }
    
  }

  void tampilKarcis(int i){
    cout << "\n+=================================+";
    cout << endl;
    cout << "|          TAMPIL KARCIS          |";
    cout << endl;
    cout << "+=================================+";
    cout << endl;
    cout << "Plat Nomor: " << kdr[i].platNomor;
    cout << endl;
    cout << "Kode Karcis: " << kdr[i].kode;
    cout << endl;
    cout << "Jenis Kendaraan: " << kdr[i].jenis;
    cout << endl;
    cout << "Waktu Parkir: " << kdr[i].waktu << " Jam";
    cout << endl;
    if (kdr[i].jenis == "motor"){
      cout << "Penitipan Helm: ";
      if (kdr[i].penitipanHelm) {
        cout << "Ya";
      } else {
        cout << "Tidak";
      }
      cout << endl;
    }
    cout << "lokasi Parkir: " << kdr[i].lokasi;
    cout << endl;
    cout << "+=================================+";
    cout << endl;
  }
  
  void hilangKarcis()
  {
    int temp = 0;
    string cekPlat, cekHelm, cekMember;
    bool status;
    cout << "\nStruk karcis hilang dan akan dikenakan denda, silahkan masukkan nomor plat untuk mengecek kendaraannya";
    cout << endl;
    cout << "Masukkan nomor plat: ";
    cin.ignore();
    getline(cin, cekPlat);
    
    for (int i = 0; i < cekPlat.length(); i++) {
        cekPlat[i] = toupper(cekPlat[i]);
        cout << cekPlat[i];
    }
    cout << endl;
    for (int i = 0; i < jumlah; i++)
    {
        if (cekPlat == kdr[i].platNomor)
        {
          cout << "kendaraan ditemukan";
          cout << endl;
          status = true;
          kdr[i].kehilanganKarcis = true;
          break;
        }
        temp++;
      }

      if (status)
      {
        if (kdr[temp].jenis == "motor")
        {
          cout << "cek adanya penitipan helm!";
          cout << "Proses pengecekan helm sedang dilakukan...";
          cout << endl;
          system("timeout /t 4 >nul");
          cout << "pengecekan selesai!";
          cout << endl;
          if (kdr[temp].penitipanHelm == true)
          {
            cout << "Ada penitipan helm pada kendaraan ini.";
            cout << endl;
          } else {
            cout << "Tidak ada penitipan helm pada kendaraan ini.";
            cout << endl;
          }
        }
        
        cout << "Apakah ada member mall? (ya/tidak): ";
        cin >> cekMember;
        if (cekMember == "ya")
        {
          kdr[temp].member = true;
        }
        
        biaya(temp);

        cout << "==============================";
        cout << endl;
        cout << "|       Struk Parkir         |";
        cout << endl;
        cout << "==============================";
        cout << endl;
        cout << "| Plat Nomor: "<<  kdr[temp].platNomor;
        cout << endl;
        cout << "| Kode karcis: "<<  kdr[temp].kode;
        cout << endl;
        cout << "| Jenis kendaraan: " << kdr[temp].jenis;
        cout << endl;
        cout << "| Ada penambahan penitipan: ";
        if (kdr[temp].penitipanHelm) {
          cout << "ya";
        } else {
          cout << "tidak";
        }
        cout << endl;
        cout << "| Member: ";
        if (kdr[temp].member) {
          cout << "ya";
        } else {
          cout << "tidak";
        }
        cout << endl;
        cout << "| Total waktu parkir: " << kdr[temp].waktu << " Jam";
        cout << endl;
        cout << "==============================";
        cout << endl;
        cout << "| Harga Parkir: " << kdr[temp].biaya;
        cout << endl;
        cout << "| Denda karcis hilang: " << kdr[temp].denda;
        cout << endl;
        cout << "| Diskon member: " << kdr[temp].diskon;
        cout << endl;
        cout << "| Total biaya: " << kdr[temp].totalBiaya;
        cout << endl;
        cout << "==============================";
        cout << endl;
        pembayaran(temp);

      } else {
        cout << "Kendaraan tidak ditemukan, Mohon masukkan nomor plat yang sesuai!";
        cout << endl << endl;
        hilangKarcis();
      }

    
  }
  
  void biaya(int i){
    jumlahKeluar++;
    float harga = 0;
    if (kdr[i].kehilanganKarcis == true)
    {
      kdr[i].denda += 5000;
    }

    if (kdr[i].jenis == "motor")
    {
      if (kdr[i].penitipanHelm == true )
      {
        harga += 5000;
      }
      harga = harga + (kdr[i].waktu * 2000);
    }
    else 
    {
      harga = harga + (kdr[i].waktu * 4000);
    }

    if (kdr[i].member == true)
    {
      kdr[i].diskon = harga * 0.1;
    }
    
    kdr[i].biaya = harga;
    kdr[i].totalBiaya = (harga + kdr[i].denda) - kdr[i].diskon;
    PemasukanObj[jumlahKeluar-1].pemasukankendaraan = kdr[i].totalBiaya;
  }

  void pembayaran(int i)
  {
    int metode, bayar;
    cout <<"\nSilahkah memilih metode pembayaran berikut ini: ";
    cout << endl;
    cout << "1. Tunai";
    cout << endl;
    cout << "2. Kartu";
    cout << endl;
    cout << "Masukkan jenis metode pembayaran (1 / 2): ";
    cin >> metode;

    if (cin.fail()) {
            cout << "Input tidak valid! Mohon masukkan angka.";
            cout << endl;
            cin.clear(); // Menghapus flag error
            cin.ignore(10000, '\n'); // Mengabaikan input yang tidak valid
            cekKendaraan(); // Memanggil ulang fungsi untuk meminta input yang benar
    }

    switch (metode)
    {
      case 1:
      kdr[i].metode = "Tunai";
      cout << "Metode pembayaran yang anda pilih adalah tunai";
      cout << endl;
      cout << "Masukkan uang yang di terima: ";
      cin >> bayar;
      
        if (bayar < kdr[i].totalBiaya)
        {
          cout << "\nUang yang anda masukkan tidak cukup!";
          cout << endl;
          cout << "Silahkan memilih kembali metode pembayaran anda, dan pastikan nominal anda cukup!";
          cout << endl;
          pembayaran(i);
        } 
        else 
        {
          kdr[i].bayar = bayar;
          cout << "Pembayaran diterima";
          cout << endl;
          kdr[i].kembalian = bayar - kdr[i].totalBiaya;
          cout << "\nBerikut struk pembayaran anda";
          cout << endl;
          cetakStruk(i);
        }
        kdr[i].sudahBayar = true;
        break;

        case 2:
        kdr[i].metode = "Kartu";
        cout << "Metode pembayaran yang anda pilih adalah menggunakan kartu";
        cout << endl;
        cout << "Silahkan tempelkan kartu pada mesin pembayaran";
        cout << endl;
        cout << "Pembayaran sedang diproses...";
        cout << endl;
        system("timeout /t 4 >nul"); // Simulasi proses pembayaran

        kdr[i].bayar = kdr[i].totalBiaya;
        cout << "Pembayaran berhasil!" ;
        cout << endl;
        cout << "\nBerikut struk pembayaran anda" ;
        cout << endl;
        cetakStruk(i);
        kdr[i].sudahBayar = true;
      
      break;
      default:
      cout << "Pilihan tidak valid";
      cout << endl;
      cout << "Mohon masukkan angka yang tertera!";
      cout << endl;
      pembayaran(i);
      break;
      }
      cetakDataDenda(i);
      kendaraanKeluar(i);
      cout << "\nSlot sebelum penghapusan: ";
      cout << "\n- Motor: " << slotMotor() << " terisi";
      cout << "\n- Mobil: " << slotMobil() << " terisi";
      cout << endl;
      
      penghapusanData(i);

      cout << "\nSlot setelah penghapusan: ";
      cetakSlotMotor();
      cetakSlotMobil();

    cout << "\n\nData kendaraan yang keluar telah disimpan di file 'kendaraan_keluar.txt'";
    cout << endl;
    cout << "Silahkan cek laporan keuangan untuk melihat data kendaraan yang keluar";
    cout << endl;
    cout << "Total pemasukan saat ini: " << totalPemasukan();
    cout << endl;
      menuAdmin();
  }

  void penghapusanData(int hapus)
  {
    if (hapus < 0 || hapus >= jumlah) return;
    
    cout << "Menghapus data kendaraan: " << kdr[hapus].platNomor ;
    cout << endl;

    for (  int j = hapus; j < jumlah; j++)
    {
      kdr[j] = kdr[j + 1];
    }
    
    jumlah--;
    
    cout << "Data kendaraan berhasil dihapus"; 
    cout << endl;
    cout << "Slot tersisa: " << jumlah ;
    cout << endl;
  } 
  
  void cetakStruk(int i){
    ofstream out;
    out.open("struk.txt");
    out << "==============================" ;
    out << endl;
    out << "|        Struk Parkir        |" ;
    out << endl;
    out << "==============================" ;
    out << endl;
    out << "| Plat Nomor: " << kdr[i].platNomor ;
    out << endl;
    out << "| Kode karcis: " << kdr[i].kode ;
    out << endl;
    out << "| Jenis kendaraan: " << kdr[i].jenis ;
    out << endl;
    out << "| Ada penambahan penitipan: " << kdr[i].penitipanHelm ;
    out << endl;
    out << "| Member: " << kdr[i].member ;
    out << endl;
    out << "| Total waktu parkir: " << kdr[i].waktu ;
    out << endl;
    out << "==============================" ;
    out << endl;
    out << "| Harga Parkir: " << kdr[i].biaya ;
    out << endl;
    out << "| Diskon member: " << kdr[i].diskon ;
    out << endl;
    out << "| Denda karcis hilang: " << kdr[i].denda ;
    out << endl;
    out << "| Total Pembayaran: " << kdr[i].totalBiaya ;
    out << endl;
    out << "| Metode Pembayaran: " << kdr[i].metode ;
    out << endl;
    out << "| Uang yang diberikan: " << kdr[i].bayar ;
    out << endl;
    out << "| Kembalian: " << kdr[i].kembalian;
    out <<endl;
    out << "==============================" ;
    out << endl;
    out << "|    Terimakasih, Silahkan    |" ;
    out << endl;
    out << "|     berkunjung kembali!     |" ;
    out << endl;
    out << "==============================" ;
    out << endl;
    out.close();

    ifstream in;
    string cetak;
    in.open("struk.txt");
    while (getline(in, cetak))
    {
      cout << cetak;
      cout << endl;
    }
    in.close();
  }
  
  float totalPemasukan(int i = 0)
  {
    if (i >= jumlahKeluar) {
      return 0;
    }
    return PemasukanObj[i].pemasukankendaraan + totalPemasukan(i + 1);
  }

  void kendaraanKeluar(int i)
  {
    ofstream out;
    out.open("kendaraan_keluar.txt", ios::app);
    if (!out)
    {
      cout << "Gagal membuka file untuk menyimpan data kendaraan yang keluar.";
      out << endl;
      menuAdmin();
    }
        out << "+================================+";
        out << endl;
        out << "| Kendaraan ke-" << jumlahKeluar;
        out << endl;
        out << "+================================+";
        out << endl;
        out << "| Plat Nomor: " << kdr[i].platNomor;
        out << endl;
        out << "| Kode Karcis: " << kdr[i].kode;
        out << endl;
        out << "| Jenis Kendaraan: " << kdr[i].jenis;
        out << endl;
        out << "| Waktu Parkir: " << kdr[i].waktu << " Jam";
        out << endl;
        out << "| Total Biaya: " << kdr[i].totalBiaya;
        out << endl;
        out << "==============================" ;
        out << endl;
    
    out.close();
    
  }
  
  void laporanPemasukan()
  {
    float pemasukan = totalPemasukan();
    cout << "\n+================================+";
    cout << endl;
    cout << "|       LAPORAN PEMASUKAN        |";
    cout << endl;
    cout << "+================================+";
    cout << endl;
    cout << "| Rincian transaksi selesai:     |";
    cout << endl;
    cout << "+--------------------------------+";
    cout << endl;
    ifstream in;
    in.open("kendaraan_keluar.txt");
    if (!in)
    {
      cout << "File 'kendaraan_keluar.txt' tidak ditemukan!";
      cout << endl;
      cout << endl;
      in.close();
      menuAdmin();
    }
    if (jumlahKeluar == 0) {
      cout << "Belum ada transaksi kendaraan yang keluar.";
      cout << endl;
      cout << "Pastikan kendaraan sudah keluar dan transaksi telah dilakukan.";
      cout << endl;
      cout << "+================================+";
      in.close();
      menuAdmin();
    }
    string line;
    while (getline(in, line))
    {
      cout << line;
      cout << endl;
    }
    in.close();
    cout << "+--------------------------------+";
    cout << endl;
    cout << "| Total transaksi: " << jumlahKeluar ;
    cout << endl;
    cout << "| Kendaraan terkena denda: " << jumlahDenda ;
    cout << endl;
    cout << "| Total pemasukan: " << pemasukan ;
    cout << endl;
    cout << "+================================+";
    cout << endl;

    menuAdmin();
  }

  void cetakDataDenda(int i){
    ofstream out;
    out.open("denda.txt", ios::app); 
    if (!out)
    {
      out << "Gagal membuka file untuk menyimpan data denda.";
      out << endl;
      return;
    }
      if (kdr[i].kehilanganKarcis)
      {
        jumlahDenda++;
        out << "Kendaraan ke-" << jumlahDenda ;
        out << endl;
        out << "Plat Nomor: " << kdr[i].platNomor ;
        out << endl;
        out << "Kode Karcis: " << kdr[i].kode ;
        out << endl;
        out << "Jenis Kendaraan: " << kdr[i].jenis ;
        out << endl;
        out << "Denda: " << kdr[i].denda ;
        out << endl;
        out << "+--------------------------------+";
        out << endl;
      }
    out.close();
    
  }

  void tampilDataDenda()
  {
    ifstream in;
    in.open("denda.txt");
    if (!in)
    {
      cout << "File 'denda.txt' tidak ditemukan!";
      cout << endl;
      cout << "Pastikan ada kendaraan yang terkena denda.";
      cout << endl;
      in.close();
      return;
    }
    string line;
    cout << "\n+=================================+";
    cout << endl;
    cout << "| LAPORAN KENDARAAN TERKENA DENDA |";
    cout << endl;
    cout << "+=================================+";
    cout << endl;
    while (getline(in, line))
    {
      cout << line << endl;
    }
    if (jumlahDenda == 0) {
      cout << "Belum ada kendaraan yang terkena denda.";
      cout << endl;
      cout << "+=================================+";
      cout << endl;
    } else {
      cout << "Jumlah kendaraan yang terkena denda: " << jumlahDenda ;
      cout << endl;
    }
    in.close();
    menuAdmin();
  }

  void menuAdmin()
  {
    int pilihan;
    cout << "\n\n+==============================================+";
    cout << endl;
    cout << "|                  MENU ADMIN                  |";
    cout << endl;
    cout << "+==============================================+";
    cout << endl;
    cout << "|1. Cek kendaraan                              |";    
    cout << endl;
    cout << "|2. Tambah kendaraan                           |";    
    cout << endl;
    cout << "|3. Tampilkan data kendaraan                   |";    
    cout << endl;
    cout << "|4. Cek Slot Parkir                            |";    
    cout << endl;
    cout << "|5. Hitung transaksi parkir                    |";
    cout << endl;
    cout << "|6. Cek laporan pemasukan                      |";
    cout << endl;
    cout << "|7. Cek laporan kendaraan yang terkena denda   |";
    cout << endl;
    cout << "|8. Menu Sorting                               |";
    cout << endl;
    cout << "|0. Keluar                                     |";
    cout << endl;
    cout << "+==============================================+";
    cout << endl;
    
    cout << "Masukkan pilihan sesuai nomor yang tertera (masukkan angka): ";
    cin >> pilihan;

    if (cin.fail()) {
            cout << "Input tidak valid! Mohon masukkan angka.";
            cout << endl;
            cin.clear(); // Menghapus flag error
            cin.ignore(10000, '\n'); // Mengabaikan input yang tidak valid
            cekKendaraan(); // Memanggil ulang fungsi untuk meminta input yang benar
    }

    switch (pilihan)
    {
    case 1:
      cekKendaraan();
    break;
    case 2:
      tambahKendaraan();
    break;
    case 3:
      tampilkanData();
    break;
    case 4:
      slotParkir();
    break;
    case 5:
      hitungTransaksi();   
    break;
    case 6:
      laporanPemasukan();
    break;
    case 7:
      tampilDataDenda();
    break;
    case 8:
      menuSorting();
    break;
    case 0:
      alur();
      break;

    default:
      cout << "Pilihan tidak valid\n";
      cout << "Mohon masukkan angka yang tertera!\n";
      menuAdmin();
      break;
    }
    
  }

  void tampilkanData()
  {
    cout << "\n+================================+\n";
    cout << "|         DATA KENDARAAN         |\n";
    cout << "+================================+\n";
    for (int i = 0; i < jumlah; i++)
    {
      cout << "Kendaraan ke-" << i + 1 ;
      cout << endl;
      cout << "Plat Nomor: " << kdr[i].platNomor;
      cout << endl;
      cout << "Kode Karcis: " << kdr[i].kode ;
      cout << endl;
      cout << "Jenis Kendaraan: " << kdr[i].jenis;
      cout << endl;
      cout << "Waktu Parkir: " << kdr[i].waktu << " Jam";
      cout << endl;
      cout << "Lokasi Parkir: " << kdr[i].lokasi;
      cout << endl;
      cout << "---------------------------------\n";
    }
    menuAdmin();
  }

  void alur()
  {
    int pilihan;
    data();
    cout << "+================================+";
    cout << endl;
    cout << "|        MENU LOGIN ADMIN        |";
    cout << endl;
    cout << "+================================+";
    cout << endl;
    cout << "| 1. Admin                       |";                     
    cout << endl;
    cout << "| 0. Keluar                      |";
    cout << endl;
    cout << "+================================+";
    cout << endl;
    cout << "Silahkan pilih 1 jika ingin lanjut login, silahkan pilih 0 jika tidak jadi login: ";
    cin >> pilihan;

    if (cin.fail()) {
            cout << "Input tidak valid! Mohon masukkan angka.";
            cout << endl;
            cin.clear(); // Menghapus flag error
            cin.ignore(10000, '\n'); // Mengabaikan input yang tidak valid
            alur();
    }

    if (pilihan == 1)
    {
      login();
      menuAdmin();
    }
    else if (pilihan != 0 && pilihan != 1)
    {
      cout << "Pilihan tidak valid";
      cout << endl;
      cout << "Mohon masukkan angka yang tertera!";
      cout << endl;
      alur();
    }
    else 
    {
      cout << "\nSelesai.....";
      exit(0);
    }
  }

  void notifikasiSlotParkirPenuh() {
    cout << "\n+================================+";
    cout << endl;
    cout << "| NOTIFIKASI SLOT PARKIR PENUH   |";
    cout << endl;
    cout << "+================================+";
    cout << endl;
    int sisaMotor = sloatAwalMotor - slotMotor();
    int sisaMobil = sloatAwalMobil - slotMobil();
    bool notif = false;
    if (sisaMotor <= 5) {
      cout << "Peringatan: Slot parkir motor hampir penuh! Sisa: " << sisaMotor;
      cout << endl;
      cout << "+================================+";
      cout << endl;
      notif = true;
    }
    if (sisaMobil <= 5) {
      cout << "Peringatan: Slot parkir mobil hampir penuh! Sisa: " << sisaMobil;
      cout << endl;
      cout << "+================================+";
      cout << endl;
      notif = true;
    }
    if (!notif) {
      cout << "Slot parkir masih tersedia cukup banyak.";
      cout << endl;
      cout << "+================================+";
      cout << endl;
    }
  }

  void menuSorting(){
    int pilihan;
    cout << "\n+================================+";
    cout << endl;
    cout << "|          MENU SORTING          |";
    cout << endl;
    cout << "+================================+";
    cout << endl;
    cout << "1. Sort jenis kendaraan berdasarkan jumlah terbanyak dan sedikit";
    cout << endl;
    cout << "2. Sort kendaraan berdasarkan waktu parkir terlama dan sebentar";
    cout << endl;
    cout << "3. Sort kendaraan berdasarkan bayaran termahal dan termurah";
    cout << endl;
    cout << "0. Keluar";
    cout << endl;
    cout << "+================================+";
    cout << endl;
    cout << "Masukkan pilihan sesuai nomor yang tertera (masukkan angka): ";
    cin >> pilihan;

    if(cin.fail()) {
            cout << "Input tidak valid! Mohon masukkan angka.";
            cout << endl;
            cin.clear(); // Menghapus flag error
            cin.ignore(10000, '\n'); // Mengabaikan input yang tidak valid
            menuAdmin(); // Memanggil ulang fungsi untuk meminta input yang benar
    }

    switch(pilihan)
    {
      case 1:
        sortKendaraan();
        break;
      case 2:
        sortWaktu();
        break;
      case 3:
        sortBayaran();
        break;
      case 0:
        menuAdmin();
        break;
      default:
        cout << "Pilihan tidak valid!";
        cout  << endl;
        cout << "Mohon masukkan angka yang tertera!";
        cout  << endl;
        menuSorting(); 
        break;
    }
  }

  void sortKendaraan(){
    int pilihan;
    cout << "\n+================================+";
    cout << endl;
    cout << "|     SORTING JENIS KENDARAAN    |";
    cout << endl;
    cout << "+================================+";
    cout << endl;
    cout << "1. Sort jenis kendaraan berdasarkan jumlah terbanyak";
    cout << endl;
    cout << "2. Sort jenis kendaraan berdasarkan jumlah sedikit";
    cout << endl;
    cout << "0. Keluar";
    cout << endl;
    cout << "+================================+";
    cout << endl;
    cout << "Masukkan pilihan sesuai nomor yang tertera (masukkan angka): ";
    cin >> pilihan;

    if (cin.fail()) {
            cout << "Input tidak valid! Mohon masukkan angka.";
            cout << endl;
            cin.clear(); // Menghapus flag error
            cin.ignore(10000, '\n'); // Mengabaikan input yang tidak valid
            sortKendaraan(); // Memanggil ulang fungsi untuk meminta input yang benar
    }

    switch(pilihan)
    {
      case 1:
        sortJenisKendaraanTerbanyak();
        break;
      case 2:
        sortJenisKendaraanSedikit();
        break;
      case 0:
        menuAdmin();
        break;
      default:
        cout << "Pilihan tidak valid!";
        cout << endl;
        cout << "Mohon masukkan angka yang tertera!";
        cout << endl;
        sortKendaraan(); 
        break;
    }
    
  }

  void sortJenisKendaraanTerbanyak(){
    cout << "\n+================================+";
    cout << endl;
    cout << "|   SORT JENIS KENDARAAN TERBANYAK |"; 
    cout << endl;
    cout << "+================================+";
    cout << endl;
    int jumlahMotor = 0, jumlahMobil = 0;
    for (int i = 0; i < jumlah; i++)
    {
      if (kdr[i].jenis == "motor")
      {
        jumlahMotor++;
      }
      else if (kdr[i].jenis == "mobil")
      {
        jumlahMobil++;
      }
    }
    cout << "Jumlah kendaraan motor: " << jumlahMotor;
    cout << endl;
    cout << "Jumlah kendaraan mobil: " << jumlahMobil;
    cout << endl;
    if (jumlahMotor > jumlahMobil) {
      cout << "Jenis kendaraan terbanyak adalah motor.";
      cout << endl;
    } else if (jumlahMobil > jumlahMotor) {
      cout << "Jenis kendaraan terbanyak adalah mobil.";
      cout << endl;
    } else {
      cout << "Jumlah kendaraan motor dan mobil sama banyak.";
      cout << endl;
    }
    cout << "+================================+";
    cout << endl;
    sortKendaraan();
  }

  void sortJenisKendaraanSedikit(){
    cout << "\n+================================+";
    cout << endl;
    cout << "|   SORT JENIS KENDARAAN SEDIKIT  |"; 
    cout << endl;
    cout << "+================================+";
    cout << endl;
    int jumlahMotor = 0, jumlahMobil = 0;
    for (int i = 0; i < jumlah; i++)
    {
      if (kdr[i].jenis == "motor")
      {
        jumlahMotor++;
      }
      else if (kdr[i].jenis == "mobil")
      {
        jumlahMobil++;
      }
    }
    cout << "Jumlah kendaraan motor: " << jumlahMotor;
    cout << endl;
    cout << "Jumlah kendaraan mobil: " << jumlahMobil;
    cout << endl;
    if (jumlahMotor < jumlahMobil) {
      cout << "Jenis kendaraan sedikit adalah motor.";
      cout << endl;
    } else if (jumlahMobil < jumlahMotor) {
      cout << "Jenis kendaraan sedikit adalah mobil.";
      cout << endl;
    } else {
      cout << "Jumlah kendaraan motor dan mobil sama banyak.";
      cout << endl;
    }
    cout << "+================================+";
    cout << endl;
    sortKendaraan();
  }

  void sortWaktu(){
    int pilihan;
    cout << "\n+====================================================+";
    cout << endl;
    cout << "|             SORT WAKTU PARKIR KENDARAAN            |"; 
    cout << endl;
    cout << "+====================================================+";
    cout << endl;
    cout << "|1. Sort kendaraan berdasarkan waktu parkir terlama  |";
    cout << endl;
    cout << "|2. Sort kendaraan berdasarkan waktu parkir sebentar |";
    cout << endl;
    cout << "|0. Keluar                                           |";
    cout << endl;
    cout << "+====================================================+";
    cout << endl;
    cout << "Masukkan pilihan sesuai nomor yang tertera (masukkan angka): ";
    cin >> pilihan;

    if (cin.fail()) {
            cout << "Input tidak valid! Mohon masukkan angka.";
            cout << endl;
            cin.clear(); // Menghapus flag error
            cin.ignore(10000, '\n'); // Mengabaikan input yang tidak valid
            sortWaktu(); // Memanggil ulang fungsi untuk meminta input yang benar
    }

    switch(pilihan)
    {
      case 1:
        sortWaktuTerlama();
        break;
      case 2:
        sortWaktuSebentar();
        break;
      case 0:
        menuAdmin();
        break;
      default:
        cout << "Pilihan tidak valid!";
        cout << endl;
        cout << "Mohon masukkan angka yang tertera!";
        cout << endl;
        sortWaktu(); 
        break;
    }
  }

  void sortWaktuTerlama(){
    cout << "\n+================================+" << endl;
    cout << "|    SORT WAKTU PARKIR TERLAMA    |" << endl;
    cout << "+=================================+" << endl;
    // menggunakan bubble sort 
    for (int i = 0; i < jumlah - 1; i++) {
      for (int j = 0; j < jumlah - i - 1; j++) {
        if (kdr[j].waktu < kdr[j + 1].waktu) {
          Kendaraan temp = kdr[j];
          kdr[j] = kdr[j + 1];
          kdr[j + 1] = temp;
        }
      }
    }
    cout << "Kendaraan dengan waktu parkir terlama:";
    cout << endl;
    for (int i = 0; i < jumlah; i++) {
      cout << "Kendaraan ke-" << i + 1;
      cout << endl;
      cout << "Plat Nomor: " << kdr[i].platNomor;
      cout << endl;
      cout << "Kode Karcis: " << kdr[i].kode;
      cout << endl;
      cout << "Jenis Kendaraan: " << kdr[i].jenis;
      cout << endl;
      cout << "Waktu Parkir: " << kdr[i].waktu << " Jam";
      cout << endl;
      cout << "Lokasi Parkir: " << kdr[i].lokasi;
      cout << endl;
      cout << "---------------------------------";
      cout << endl;
    }
    cout << "+================================+";
    cout << endl;
    sortWaktu();
  }

  void sortWaktuSebentar(){
    cout << "\n+================================+";
    cout << endl;
    cout << "|   SORT WAKTU PARKIR SEBENTAR   |"; 
    cout << endl;
    cout << "+================================+";
    cout << endl;
    // gunakan bubble sort
    for (int i = 0; i < jumlah - 1; i++) {
      for (int j = 0; j < jumlah - i - 1; j++) {
        if (kdr[j].waktu > kdr[j + 1].waktu) {
          // tukar
          Kendaraan temp = kdr[j];
          kdr[j] = kdr[j + 1];
          kdr[j + 1] = temp;
        }
      }
    }
    cout << "Kendaraan dengan waktu parkir sebentar:";
    cout << endl;
    for (int i = 0; i < jumlah; i++)
    {
      cout << "Kendaraan ke-" << i + 1;
      cout << endl;
      cout << "Plat Nomor: " << kdr[i].platNomor;
      cout << endl;
      cout << "Kode Karcis: " << kdr[i].kode;
      cout << endl;
      cout << "Jenis Kendaraan: " << kdr[i].jenis;
      cout << endl;
      cout << "Waktu Parkir: " << kdr[i].waktu << " Jam";
      cout << endl;
      cout << "Lokasi Parkir: " << kdr[i].lokasi;
      cout << endl;
      cout << "---------------------------------";
      cout << endl;
    }
    cout << "+================================+";
    cout << endl;
    sortWaktu();
  }

  void sortBayaran(){
    int pilihan;
    cout << "\n+================================================+";
    cout << endl;
    cout << "|             SORT BAYARAN KENDARAAN             |"; 
    cout << endl;
    cout << "+================================================+";
    cout << endl;
    cout << "|1. Sort kendaraan berdasarkan bayaran termahal  |";
    cout << endl;
    cout << "|2. Sort kendaraan berdasarkan bayaran termurah  |";
    cout << endl;
    cout << "|0. Keluar                                       |";
    cout << endl;
    cout << "+================================================+";
    cout << endl;
    cout << "Masukkan pilihan sesuai nomor yang tertera (masukkan angka): ";
    cin >> pilihan;

    if (cin.fail()) {
            cout << "Input tidak valid! Mohon masukkan angka.";
            cout << endl;
            cin.clear(); // Menghapus flag error
            cin.ignore(10000, '\n'); // Mengabaikan input yang tidak valid
            sortBayaran(); // Memanggil ulang fungsi untuk meminta input yang benar
    }

    switch(pilihan)
    {
      case 1:
        sortBayaranTertinggi();
        break;
      case 2:
        sortBayaranTerendah();
        break;
      case 0:
        menuAdmin();
        break;
      default:
        cout << "Pilihan tidak valid!";
        cout << endl;
        cout << "Mohon masukkan angka yang tertera!";
        cout << endl;
        sortBayaran(); 
        break;
    }
  }

  void sortBayaranTertinggi(){
    cout << "\n+================================+";
    cout << endl;
    cout << "|   SORT BAYARAN TERMAHAL        |"; 
    cout << endl;
    cout << "+================================+";
    cout << endl;

    if (jumlah == 0) {
      cout << "Tidak ada kendaraan untuk diurutkan.";
      cout << endl;
      return;
    }

    for (int i = 0; i < jumlah; i++)
    {
      biaya(i);
    }

    // gunakan bubble sort
    for (int i = 0; i < jumlah - 1; i++) {
      for (int j = 0; j < jumlah - i - 1; j++) {
        if (kdr[j].biaya < kdr[j + 1].biaya) {
          // tukar
          Kendaraan temp = kdr[j];
          kdr[j] = kdr[j + 1];
          kdr[j + 1] = temp;
        }
      }
    }
    cout << "Kendaraan dengan bayaran termahal:";
    cout << endl;
    for (int i = 0; i < jumlah; i++)
    {
      cout << "Kendaraan ke-" << i + 1;
      cout << endl;
      cout << "Plat Nomor: " << kdr[i].platNomor;
      cout << endl;
      cout << "Kode Karcis: " << kdr[i].kode;
      cout << endl;
      cout << "Jenis Kendaraan: " << kdr[i].jenis;
      cout << endl;
      cout << "Waktu Parkir: " << kdr[i].waktu << " Jam";
      cout << endl;
      cout << "Lokasi Parkir: " << kdr[i].lokasi;
      cout << endl;
      cout << "Biaya parkir: " << kdr[i].biaya;
      cout << endl;
      cout << "---------------------------------";
      cout << endl;
    }

    cout << "Biaya yang diurutkan belum termasuk denda dan diskon member.";
    cout << endl;
    cout << "+================================+";
    cout << endl;
    sortBayaran();
  }

  void sortBayaranTerendah(){
    cout << "\n+================================+";
    cout << endl;
    cout << "|   SORT BAYARAN TERMURAH        |"; 
    cout << endl;
    cout << "+================================+";
    cout << endl;

    if (jumlah == 0) {
      cout << "Tidak ada kendaraan untuk diurutkan.";
      cout << endl;
      return;
    }

    for (int i = 0; i < jumlah; i++)
    {
      biaya(i);
    }

    // gunakan bubble sort
    for (int i = 0; i < jumlah - 1; i++) {
      for (int j = 0; j < jumlah - i - 1; j++) {
        if (kdr[j].biaya > kdr[j + 1].biaya) {
          // tukar
          Kendaraan temp = kdr[j];
          kdr[j] = kdr[j + 1];
          kdr[j + 1] = temp;
        }
      }
    }
    cout << "Kendaraan dengan bayaran termurah:";
    cout << endl;
    for (int i = 0; i < jumlah; i++)
    {
      cout << "Kendaraan ke-" << i + 1;
      cout << endl;
      cout << "Plat Nomor: " << kdr[i].platNomor;
      cout << endl;
      cout << "Kode Karcis: " << kdr[i].kode;
      cout << endl;
      cout << "Jenis Kendaraan: " << kdr[i].jenis;
      cout << endl;
      cout << "Waktu Parkir: " << kdr[i].waktu << " Jam";
      cout << endl;
      cout << "Lokasi Parkir: " << kdr[i].lokasi;
      cout << endl;
      cout << "Biaya parkir: " << kdr[i].biaya;
      cout << endl;
      cout << "---------------------------------";
      cout << endl;
    }

    cout << "Biaya yang diurutkan belum termasuk denda dan diskon member.";
    cout << endl;
    cout << "+================================+";
    cout << endl;
    sortBayaran();
  }

};


int main()
{
  ofstream out;
  out.open("denda.txt", ios::trunc); 
  if (!out) {
    cout << "Gagal membuka file untuk menyimpan data denda.";
    cout << endl;
    cout << "Pastikan file tidak sedang dibuka oleh program lain.";
    cout << endl;
    
    return 1;
  }
  out.close();
  ofstream keluar;
  keluar.open("kendaraan_keluar.txt", ios::trunc);
  if (!keluar) {
    out << "Gagal membuka file untuk menyimpan data kendaraan yang keluar.";
    cout << endl;
    cout << "Pastikan file tidak sedang dibuka oleh program lain.";
    cout << endl;
    
    return 1;
  }
  keluar.close();
  Parkir pkr;
  pkr.alur();
  return 0;  
}
