#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> 
using namespace std;
// Program parkir

struct Kendaraan
{
  string platNomor;
  string kode;
  string jenis;
  int waktu;
  bool penitipanHelm;
  bool kehilanganKarcis;
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
  int jumlah = 4;
  int jumlahKeluar = 0;
  int jumlahDenda = 0;
  Kendaraan kdr[100];
  Pemasukan PemasukanObj[100];
  public:

  void data()
  {
    kdr[0].platNomor = "AD 2183 CB";
    kdr[0].kode = "A101";
    kdr[0].jenis = "motor";
    kdr[0].waktu = 2;
    kdr[0].penitipanHelm = false;
    kdr[0].kehilanganKarcis = false;
    kdr[0].member = false;
    kdr[0].lokasi = "L1";

    kdr[1].platNomor = "A 1945 SH";
    kdr[1].kode = "A102";
    kdr[1].jenis = "mobil";
    kdr[1].waktu = 10;
    kdr[1].penitipanHelm = false;
    kdr[1].kehilanganKarcis = false;
    kdr[1].member = false;
    kdr[1].lokasi = "L2";

    kdr[2].platNomor = "B 2600 DSM";
    kdr[2].kode = "A103";
    kdr[2].jenis = "motor";
    kdr[2].waktu = 24;
    kdr[2].penitipanHelm = false;
    kdr[2].kehilanganKarcis = false;
    kdr[2].member = false;
    kdr[2].lokasi = "L1";
    
    kdr[3].platNomor = "F 7437 UCK";
    kdr[3].kode = "A104";
    kdr[3].jenis = "motor";
    kdr[3].waktu = 5;
    kdr[3].penitipanHelm = false;
    kdr[3].kehilanganKarcis = false;
    kdr[3].member = false;
    kdr[3].lokasi = "L1";
    
    kdr[4].platNomor = "AA 2475 AAH";
    kdr[4].kode = "A105";
    kdr[4].jenis = "motor";
    kdr[4].waktu = 8;
    kdr[4].penitipanHelm = false;
    kdr[4].kehilanganKarcis = false;
    kdr[4].member = false;
    kdr[4].lokasi = "L1";

    kdr[5].platNomor = "AB 9841 NT";
    kdr[5].kode = "A106";
    kdr[5].jenis = "mobil";
    kdr[5].waktu = 12;
    kdr[5].penitipanHelm = false;
    kdr[5].kehilanganKarcis = false;
    kdr[5].member = false;
    kdr[5].lokasi = "L2";

    kdr[6].platNomor = "Z 3563 THR";
    kdr[6].kode = "A107";
    kdr[6].jenis = "motor";
    kdr[6].waktu = 15;
    kdr[6].penitipanHelm = false;
    kdr[6].kehilanganKarcis = false;
    kdr[6].member = false;
    kdr[6].lokasi = "L1";

    kdr[7].platNomor = "N 1274 EUE";
    kdr[7].kode = "A108";
    kdr[7].jenis = "mobil";
    kdr[7].waktu = 3;
    kdr[7].penitipanHelm = false;
    kdr[7].kehilanganKarcis = false;
    kdr[7].member = false;
    kdr[7].lokasi = "L2";

    kdr[8].platNomor = "H 9185 RD";
    kdr[8].kode = "A109";
    kdr[8].jenis = "mobil";
    kdr[8].waktu = 9;
    kdr[8].penitipanHelm = false;
    kdr[8].kehilanganKarcis = false;
    kdr[8].member = false;
    kdr[8].lokasi = "L2";

    kdr[9].platNomor = "J 4823 AWA";
    kdr[9].kode = "A200";
    kdr[9].jenis = "motor";
    kdr[9].waktu = 6;
    kdr[9].penitipanHelm = false;
    kdr[9].kehilanganKarcis = false;
    kdr[9].member = false;
    kdr[9].lokasi = "L1";

  }
  
  void login()
  {
    int batas = 0;
    string user;
    string pw;

    while (batas < 5){
      cout << "\n+================================+\n";
      cout << "|       LOGIN SEBAGAI ADMIN       |\n";
      cout << "+================================+\n";
      cout << "Masukkan username: ";
      cin >> user;
      cout << "Masukkan password: ";
      cin >> pw;
      
      if (user != "admin" && pw == "123"){
        cout << "Username salah!\n";
        cout << "Silahkan masukkan username dengan benar\n" << endl;
        batas++;
      }
      
      else if(user == "admin" && pw != "123"){
        cout << "Password salah!\n";
        cout << "Silahkan masukkan password dengan benar\n" << endl;
        batas++;
        
      }
      else if (user == "admin" && pw == "123")
      {
        cout << "+================================+\n";
        cout << "|         LOGIN BERHASIL!        |\n";
        cout << "+================================+\n";
        menuAdmin();
      }
      else
      {
        cout << "Username atau Password salah!\n";
        cout << "Silahkan masukkan username atau password dengan benar\n" << endl;
        batas++;
      
      }

    }  
    cout << "Maaf anda sudah melebihi batas maksimal percobaan login\n";
    exit(0);
  }

  void cekKendaraan()
  {
    int pilihan;
    
    cout << "\n+================================+\n";
    cout << "|       MENU CEK KENDARAAN       |\n";
    cout << "+================================+\n";
    cout << "Pilih opsi berikut untuk mengecek kendaraan: \n";
    cout << "1. Cari kendaraan              |\n";
    cout << "2. Cek jenis kendaraan         |\n";
    cout << "0. Keluar                        |\n";
    cout << "+================================+\n";
    cout << "Silahkan masukkan pilihan anda (masukkan angka): ";
    cin >> pilihan;

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
        cout << "Pilihan tidak valid!\n";
        cout << "Mohon masukkan angka yang tertera!\n";
        cekKendaraan(); 
        break;
    }

  }

  void cariKendaraan(){
    int pilihan;

    cout << "\n+================================+\n";
    cout << "|         CARI KENDARAAN         |\n";
    cout << "+================================+\n";
    cout << "Pilih opsi berikut untuk mencari kendaraan: \n";
    cout << "1. Plat Nomor kendaraan          |\n";
    cout << "2. Kode karcis                   |\n";
    cout << "0. Keluar                        |\n";
    cout << "+================================+\n";
    cout << "Silahkan masukkan pilihan anda (masukkan angka): ";
    cin >> pilihan;

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
        cout << "Pilihan tidak valid!\n";
        cout << "Mohon masukkan angka yang tertera!\n";
        cariKendaraan(); 
        break;
    }
  }

  void cekJenisKendaraan(){
    int pilihan;
    cout << "\n+================================+\n";
    cout << "|    CEK DATA JENIS KENDARAAN    |\n";
    cout << "+================================+\n";
    cout << "1. Cek data kendaraan motor          |\n";
    cout << "2. Cek data kendaraan mobil                  |\n";
    cout << "0. Keluar                        |\n";
    cout << "+================================+\n";
    cout << "Silahkan masukkan pilihan anda (masukkan angka): ";
    cin >> pilihan;

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
      cout << "Pilihan tidak valid!\n";
      cout << "Mohon masukkan angka yang tertera!\n";
      cekJenisKendaraan(); 
      break;
    }
  }

  void cekDataMotor(){
    int jumlahMotor = 0;
    cout << "\nBerikut data nomor plat untuk parkir motor: " << endl;

    for (int i = 0; i < jumlah; i++)
    {
      if (kdr[i].jenis == "motor")
      {
        cout << "Motor ke-" << jumlahMotor+1 << " dengan nomor plat: " << kdr[i].platNomor << endl;;
        jumlahMotor++;
      }
    }

    cout << "Jumlah data motor yang parkir di mall JWALK sebanyak: " <<  jumlahMotor << endl;
    cekJenisKendaraan();
  }
  
  void cekDataMobil(){
    int jumlahMobil = 0;
    cout << "\nBerikut data nomor plat untuk parkir Mobil: " << endl;
    
    for (int i = 0; i < jumlah; i++)
    {
      if (kdr[i].jenis == "mobil")
      {
        cout << "Mobil ke-" << i+1 << " dengan nomor plat: " << kdr[i].platNomor << endl;;
        jumlahMobil++;
      }
      
    }

    cout << "Jumlah data mobil yang parkir di mall JWALK sebanyak: " <<  jumlahMobil << endl;
    cekJenisKendaraan();
  }
  
  void tambahKendaraan(){
    int tambah;
    notifikasiSlotParkirPenuh();
    cetakSlotMotor();
    cetakSlotMobil();
    cout << "\n+================================+\n";
    cout << "|        TAMBAH KENDARAAN        |\n";
    cout << "+================================+\n";
    cout << "Masukkan jumlah kendaraan yang ingin ditambah: ";
    cin >> tambah;
    for (int i = 0; i < tambah; i++)
    {
      cout << "\nMasukkan plat nomor kendaraan: ";
      cin.ignore();
      getline(cin, kdr[jumlah+i].platNomor);
      cout << "Tentukan kode karcis kendaraan: ";
      cin >> kdr[jumlah+i].kode;
      cout << "Masukkan jenis kendaraan: ";
      cin >> kdr[jumlah+i].jenis;
      cout << "Masukkan waktu lama kendaraan: ";
      cin >> kdr[jumlah+i].waktu;
      cout << "Masukkan lokasi parkir kendaraan (misal: Lantai 1, Blok A3): ";
      cin.ignore();
      getline(cin, kdr[jumlah+i].lokasi);
    }
    cout << "\n+================================+\n";
    cout << "| KENDARAAN BERHASIL DITAMBAHKAN |\n";
    cout << "+================================+\n";
    jumlah += tambah;
    cout << jumlah;
    menuAdmin();
  }

  void cekPlat()
  {
    string ulang;
    bool status = false;
    cout << "\nAnda memilih pencarian berdasarkan plat nomor\n";
    cout << "Masukkan plat nomor: ";
    cin.ignore();
    getline(cin, cPlat); 
    for (int i = 0; i < jumlah; i++)
    {
      if (cPlat == kdr[i].platNomor)
      {
        cout << "\n======================================================================\n"; 
        cout << "Berikut detail kendaraanya, berdasarkan plat nomor: " << cPlat << endl;
        cout << "Plat nomor: " <<  kdr[i].platNomor << endl;
        cout << "Kode karcis: " <<  kdr[i].kode << endl;
        cout << "Jenis kendaraan: " <<  kdr[i].jenis << endl;
        cout << "Lokasi parkir: " << kdr[i].lokasi << endl;
        cout << "\n======================================================================\n"; 
        status = true;
      }
      
    }

    if (status == false)
    {
      cout << "Kendaraan tidak ditemukan, pastikan anda memasukkan plat nomer yang sesuai\n";
    }

    cout << "Apkah anda ingin menggecek kendaraan yang lain? (ya/tidak): ";
    cin >> ulang;

    if (ulang == "ya")
    {
      cekPlat();
    }
    
  menuAdmin();
  }
  
  void cekKodeKarcis()
  {
    string ulang;
    bool status = false;
    cout << "\nAnda memilih pencarian berdasarkan kode karcis\n";
    cout << "Masukkan Kode Karcis: ";
    cin >> cKode;
    for (int i = 0; i < jumlah; i++)
      {
      if (cKode == kdr[i].kode)
      {
        cout << "\n======================================================================\n"; 
        cout << "Berikut detail kendaraanya, berdasarkan kode karcis: " << cKode << endl;
        cout << "Plat nomor: " <<  kdr[i].platNomor << endl;
        cout << "Kode karcis: " <<  kdr[i].kode << endl;
        cout << "Jenis kendaraan: " <<  kdr[i].jenis << endl;
        cout << "Lokasi parkir: " << kdr[i].lokasi << endl;
        cout << "\n======================================================================\n"; 
        status = true;

      }
      
    }
    if (status == false)
    {
      cout << "Kendaraan tidak ditemukan, pastikan anda memasukkan kode karcis yang sesuai\n";
    }
    cout << "Apkah anda ingin menggecek kendaraan yang lain? (ya/tidak): ";
    cin >> ulang;
    if (ulang == "ya")
    {
      cekKodeKarcis();
    }
    
    menuAdmin();
  }
  
  void slotParkir()
  {
    int pilihan;
    cout << "\n+================================+\n";
    cout << "|          MENU CEK SLOT         |\n";
    cout << "+================================+\n";
    cout << "1. Cek Slot Motor              |\n";
    cout << "2. Cek Slot Mobil              |\n";
    cout << "0. Keluar                        |\n";
    cout << "+================================+\n";
    cout << "Masukkan pilihan (Masukkan angka): ";
    cin >> pilihan;
    
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
      cout << "Pilihan tidak valid!\n";
      cout << "Mohon masukkan angka yang tertera!\n";
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
    cout << "\n+================================+\n";
    cout << "|           SLOT MOTOR           |\n";
    cout << "+================================+\n";
    cout << "slot motor terpakai : ";
    cout << slotMotor();
    cout << "\nSlot motor tersedia : " << sloatAwalMotor - slotMotor() << endl;
    cout << "+================================+\n";
  }

  void cetakSlotMobil(){
    cout << "\n+================================+\n";
    cout << "|           SLOT MOBIL           |\n";
    cout << "+================================+\n";
    cout << "Slot mobil terpakai : ";
    cout << slotMobil();
    cout << "\nSlot mobil tersedia : " << sloatAwalMotor - slotMobil() << endl;
    cout << "+================================+\n";
  }
  
  void hitungTransaksi(){
    string karcis, cekKarcis, cekHelm, cekMember;
    int temp = 0;
    bool status = false;
    cout << "\n+================================+\n";
    cout << "|     MENU HITUNG TRANSAKSI      |\n";
    cout << "+================================+\n";
    cout << "Apakah ada karcis? (ya/tidak): ";
    cin >> cekKarcis;
    if (cekKarcis == "ya")
    {
      cout << "Masukkan kode karcis: ";
      cin >> karcis;
      
      for (int i = 0; i < jumlah; i++)
      {
        if (karcis == kdr[i].kode)
        {
          cout << "kendaraan ditemukan" << endl;
          status = true;
          break;
        }
        temp++;
      }

      if (status == true)
      {
        if (kdr[temp].jenis == "motor")
        {
          cout << "Apakah ada penitipan helm? (ya/tidak): ";
          cin >> cekHelm;
          if (cekHelm == "ya")
          {
            kdr[temp].penitipanHelm = true;
          }
        }
        
        cout << "Apakah ada member mall? (ya/tidak): ";
        cin >> cekMember;
        if (cekMember == "ya")
        {
          kdr[temp].member = true;
        }
      
        biaya(temp);
        
        cout << "\n==============================" << endl;
        cout << "|       Struk Parkir         |" << endl;
        cout << "==============================" << endl;
        cout << "| Plat Nomor: "<<  kdr[temp].platNomor << endl;
        cout << "| Kode karcis: "<<  kdr[temp].kode << endl;
        cout << "| Jenis kendaraan: " << kdr[temp].jenis << endl;
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
        cout << "| Total waktu parkir: " << kdr[temp].waktu << " Jam" << endl;
        cout << "==============================" << endl;
        cout << "| Harga Parkir: " << kdr[temp].biaya << endl;
        cout << "| Denda karcis hilang: " << kdr[temp].denda << endl;
        cout << "| Diskon member: " << kdr[temp].diskon << endl;
        cout << "| Total biaya: " << kdr[temp].totalBiaya << endl;
        cout << "==============================" << endl;
        pembayaran(temp);

      } else {
        cout << "Kendaraan tidak ditemukan, Mohon masukkan nomor karcis yang sesuai!" << endl << endl;
        kdr[temp].kehilanganKarcis = true;
        hitungTransaksi();
      }
      
    } else{
      hilangKarcis();
    }
    
  }
  
  void hilangKarcis()
  {
    int temp = 0;
    string cekPlat, cekHelm, cekMember;
    bool status;
    cout << "\nStruk karcis hilang dan akan dikenakan denda, silahkan masukkan nomor plat untuk mengecek kendaraannya" << endl;
    cout << "Masukkan nomor plat: ";
    cin.ignore();
    getline(cin, cekPlat);
    
    for (int i = 0; i < jumlah; i++)
      {
        if (cekPlat == kdr[i].platNomor)
        {
          cout << "kendaraan ditemukan" << endl;
          status = true;
          kdr[i].kehilanganKarcis = true;
          break;
        }
        temp++;
      }

      if (status == true)
      {
        if (kdr[temp].jenis == "motor")
        {
          cout << "Apakah ada penitipan helm? (ya/tidak): ";
          cin >> cekHelm;
          if (cekHelm == "ya")
          {
            kdr[temp].penitipanHelm = true;
          }
        }
        
        cout << "Apakah ada member mall? (ya/tidak): ";
        cin >> cekMember;
        if (cekMember == "ya")
        {
          kdr[temp].member = true;
        }
        
        biaya(temp);

        cout << "==============================" << endl;
        cout << "|       Struk Parkir         |" << endl;
        cout << "==============================" << endl;
        cout << "| Plat Nomor: "<<  kdr[temp].platNomor << endl;
        cout << "| Kode karcis: "<<  kdr[temp].kode << endl;
        cout << "| Jenis kendaraan: " << kdr[temp].jenis << endl;
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
        cout << "| Total waktu parkir: " << kdr[temp].waktu << " Jam" << endl;
        cout << "==============================" << endl;
        cout << "| Harga Parkir: " << kdr[temp].biaya << endl;
        cout << "| Denda karcis hilang: " << kdr[temp].denda << endl;
        cout << "| Diskon member: " << kdr[temp].diskon << endl;
        cout << "| Total biaya: " << kdr[temp].totalBiaya << endl;
        cout << "==============================" << endl;
        pembayaran(temp);

      } else {
        cout << "Kendaraan tidak ditemukan, Mohon masukkan nomor plat yang sesuai!" << endl << endl;
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
    cout <<"\nSilahkah memilih metode pembayaran berikut ini: " << endl;
    cout << "1. Tunai" << endl;
    cout << "2. Kartu" << endl;
    cout << "Masukkan jenis metode pembayaran (1 / 2): ";
    cin >> metode;
    switch (metode)
    {
      case 1:
      kdr[i].metode = "Tunai";
      cout << "Metode pembayaran yang anda pilih adalah tunai" << endl;
      cout << "Masukkan uang yang di terima: ";
      cin >> bayar;
      
        if (bayar < kdr[i].totalBiaya)
        {
          cout << "\nUang yang anda masukkan tidak cukup!\n";
          cout << "Silahkan memilih kembali metode pembayaran anda, dan pastikan nominal anda cukup!\n";
          pembayaran(i);
        } 
        else 
        {
          kdr[i].bayar = bayar;
          cout << "Pembayaran diterima" << endl;
          kdr[i].kembalian = bayar - kdr[i].totalBiaya;
          cout << "\nBerikut struk pembayaran anda" << endl;
          cetakStruk(i);
        }
        kdr[i].sudahBayar = true;
        break;

        case 2:
        kdr[i].metode = "Kartu";
        cout << "Metode pembayaran yang anda pilih adalah menggunakan kartu" << endl;
        cout << "Silahkan tempelkan kartu pada mesin pembayaran" << endl;
        kdr[i].bayar = kdr[i].totalBiaya;
        cout << "Pembayaran berhasil!" << endl;
        cout << "\nBerikut struk pembayaran anda" << endl;
        cetakStruk(i);
        kdr[i].sudahBayar = true;
      
      break;
    default:
      cout << "Pilihan tidak valid\n";
      cout << "Mohon masukkan angka yang tertera!\n";
      pembayaran(i);
      break;
    }
    kendaraanKeluar(i);

      cout << "\nSlot sebelum penghapusan: ";
      cout << "\n- Motor: " << slotMotor() << " terisi";
      cout << "\n- Mobil: " << slotMobil() << " terisi\n";
      
      penghapusanData(i);

      cout << "\nSlot setelah penghapusan: ";
      cetakSlotMotor();
      cetakSlotMobil();

      menuAdmin();
  }

  void penghapusanData(int hapus)
  {
    if (hapus < 0 || hapus >= jumlah) return;
    
    cout << "Menghapus data kendaraan: " << kdr[hapus].platNomor << endl;

    for (  int j = hapus; j < jumlah; j++)
    {
      kdr[j] = kdr[j + 1];
    }
    
    jumlah--;
    
    cout << "Data kendaraan berhasil dihapus" << endl;
    cout << "Slot tersisa: " << jumlah << endl;
  } 
  
  void cetakStruk(int i){
    ofstream out;
    out.open("struk.txt");
    out << "==============================" << endl;
    out << "|        Struk Parkir        |" << endl;
    out << "==============================" << endl;
    out << "| Plat Nomor: " << kdr[i].platNomor << endl;
    out << "| Kode karcis: " << kdr[i].kode << endl;
    out << "| Jenis kendaraan: " << kdr[i].jenis << endl;
    out << "| Ada penambahan penitipan: " << kdr[i].penitipanHelm << endl;
    out << "| Member: " << kdr[i].member << endl;
    out << "| Total waktu parkir: " << kdr[i].waktu << endl;
    out << "==============================" << endl;
    out << "| Harga Parkir: " << kdr[i].biaya << endl;
    out << "| Diskon member: " << kdr[i].diskon << endl;
    out << "| Denda karcis hilang: " << kdr[i].denda << endl;
    out << "| Total Pembayaran: " << kdr[i].totalBiaya << endl;
    out << "| Metode Pembayaran: " << kdr[i].metode << endl;
    out << "| Uang yang diberikan: " << kdr[i].bayar << endl;
    out << "| Kembalian: " << kdr[i].kembalian <<endl;
    out << "==============================" << endl;
    out << "|    Terimakasih, Silahkan    |" << endl;
    out << "|     berkunjung kembali!     |" << endl;
    out << "==============================" << endl;
    out.close();

    ifstream in;
    string cetak;
    in.open("struk.txt");
    while (getline(in, cetak))
    {
      cout << cetak << endl;
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
      cout << "Gagal membuka file untuk menyimpan data kendaraan yang keluar.\n";
      return;
    }
        out << "+================================+\n";
        out << "| Kendaraan ke-" << jumlahKeluar << endl;
        out << "+================================+\n";
        out << "| Plat Nomor: " << kdr[i].platNomor << endl;
        out << "| Kode Karcis: " << kdr[i].kode << endl;
        out << "| Jenis Kendaraan: " << kdr[i].jenis << endl;
        out << "| Waktu Parkir: " << kdr[i].waktu << " Jam" << endl;
        out << "| Total Biaya: " << kdr[i].totalBiaya << endl;
        out << "==============================" << endl;
    
    out.close();
    cout << "\nData kendaraan yang keluar telah disimpan di file 'kendaraan_keluar.txt'\n";
    cout << "Silahkan cek laporan keuangan untuk melihat data kendaraan yang keluar\n";
    cout << "Total pemasukan saat ini: " << totalPemasukan() << endl;
  }
  
  void laporanPemasukan()
  {
    float pemasukan = totalPemasukan();
    cout << "\n+================================+\n";
    cout << "|       LAPORAN PEMASUKAN        |\n";
    cout << "+================================+\n";
    cout << "| Rincian transaksi selesai:     |\n";
    cout << "+--------------------------------+\n";
    ifstream in;
    in.open("kendaraan_keluar.txt");
    if (!in)
    {
      cout << "File 'kendaraan_keluar.txt' tidak ditemukan!\n";
      cout << "Pastikan kendaraan sudah keluar dan transaksi telah dilakukan.\n";
      in.close();
      return;
    }
    string line;
    while (getline(in, line))
    {
      cout << line << endl;
    }
    in.close();
    cout << "+--------------------------------+\n";
    cout << "| Total transaksi: " << jumlahKeluar << endl;
    cout << "| Kendaraan terkena denda: " << jumlahDenda << endl;
    cout << "| Total pemasukan: " << pemasukan << endl;
    cout << "+================================+\n";
    menuAdmin();
  }

  void cetakDataDenda(int i){
    ofstream out;
    out.open("denda.txt"); 
    if (!out)
    {
      cout << "Gagal membuka file untuk menyimpan data denda.\n";
      return;
    }
      if (kdr[i].kehilanganKarcis)
      {
        jumlahDenda++;
        out << "Kendaraan ke-" << jumlahDenda << endl;
        out << "Plat Nomor: " << kdr[i].platNomor << endl;
        out << "Kode Karcis: " << kdr[i].kode << endl;
        out << "Jenis Kendaraan: " << kdr[i].jenis << endl;
        out << "Denda: " << kdr[i].denda << endl;
        out << "+--------------------------------+\n";
      }
    out.close();
    
  }

  void tampilDataDenda()
  {
    ifstream in;
    in.open("denda.txt");
    if (!in)
    {
      cout << "File 'denda.txt' tidak ditemukan!\n";
      cout << "Pastikan ada kendaraan yang terkena denda.\n";
      in.close();
      return;
    }
    string line;
    cout << "\n+================================+\n";
    cout << "|   LAPORAN KENDARAAN TERKENA DENDA |\n";
    cout << "+================================+\n";
    while (getline(in, line))
    {
      cout << line << endl;
    }
    in.close();
    menuAdmin();
  }

  void menuAdmin()
  {
    int pilihan;
    cout << "\n+================================+\n";
    cout << "|           MENU ADMIN           |\n";
    cout << "+================================+\n";
    cout << "1. Cek kendaraan\n";    
    cout << "2. Tambah kendaraan\n";    
    cout << "3. Tampilkan data\n";    
    cout << "4. Cek Slot Parkir\n";    
    cout << "5. Hitung transaksi parkir\n";
    cout << "6. Cek laporan pemasukan\n";
    cout << "7. Cek laporan kendaraan yang terkena denda\n";
    cout << "0. Keluar\n";
    cout << "+================================+\n";

    cout << "Masukkan pilihan sesuai nomor yang tertera (masukkan angka): ";
    cin >> pilihan;

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
      cout << "Kendaraan ke-" << i + 1 << endl;
      cout << "Plat Nomor: " << kdr[i].platNomor << endl;
      cout << "Kode Karcis: " << kdr[i].kode << endl;
      cout << "Jenis Kendaraan: " << kdr[i].jenis << endl;
      cout << "Waktu Parkir: " << kdr[i].waktu << " Jam" << endl;
      cout << "Lokasi Parkir: " << kdr[i].lokasi << endl;
      cout << "Penitipan Helm: " << (kdr[i].penitipanHelm ? "Ya" : "Tidak") << endl;
      cout << "Kehilangan Karcis: " << (kdr[i].kehilanganKarcis ? "Ya" : "Tidak") << endl;
      cout << "Member: " << (kdr[i].member ? "Ya" : "Tidak") << endl;
      cout << "\n---------------------------------\n";
    }
    menuAdmin();
  }

  void alur()
  {
    int pilihan;
    data();
    cout << "\n+================================+\n";
    cout << "|   SELAMAT DATANG DI PARKIRAN   |\n";
    cout << "|           MALL JWALK           |\n";
    cout << "+================================+\n";
    cout << "+================================+\n";
    cout << "|        MENU LOGIN ADMIN        |\n";
    cout << "+================================+\n";
    cout << "| 1. Admin                       |\n";                     
    cout << "| 0. Keluar                      |\n";
    cout << "+================================+\n";
    cout << "Silahkan pilih 1 jika ingin lanjut login, silahkan pilih 0 jika tidak jadi login: ";
    cin >> pilihan;

    if (pilihan == 1)
    {
      login();
      menuAdmin();
    }
    else if (pilihan != 0 && pilihan != 1)
    {
      cout << "Pilihan tidak valid\n";
      cout << "Mohon masukkan angka yang tertera!\n";
      alur();
    }
    else 
    {
      cout << "\nSelesai.....";
      exit(0);
    }
  }

  void notifikasiSlotParkirPenuh() {
    cout << "\n+================================+\n";
    cout << "| NOTIFIKASI SLOT PARKIR PENUH   |\n";
    cout << "+================================+\n";
    int sisaMotor = sloatAwalMotor - slotMotor();
    int sisaMobil = sloatAwalMobil - slotMobil();
    bool notif = false;
    if (sisaMotor <= 5) {
      cout << "Peringatan: Slot parkir motor hampir penuh! Sisa: " << sisaMotor << endl;
      cout << "+================================+\n";
      notif = true;
    }
    if (sisaMobil <= 5) {
      cout << "Peringatan: Slot parkir mobil hampir penuh! Sisa: " << sisaMobil << endl;
      cout << "+================================+\n";
      notif = true;
    }
    if (!notif) {
      cout << "Slot parkir masih tersedia cukup banyak." << endl;
      cout << "+================================+\n";
    }
  }
};


int main()
{
  ofstream out;
  out.open("denda.txt", ios::trunc); 
  if (!out) {
    cout << "Gagal membuka file untuk menyimpan data denda.\n";
    return 1;
  }
  out.close();
  ofstream out;
  out.open("kendaraan_keluar.txt", ios::trunc);
  if (!out) {
    cout << "Gagal membuka file untuk menyimpan data kendaraan yang keluar.\n";
    return 1;
  }
  out.close();
  
  Parkir pkr;
  pkr.alur();
  
  return 0;  
}
