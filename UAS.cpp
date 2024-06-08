#include <iostream>
#include <string>
using namespace std;

struct pelanggan {
    string nama,
    awal,
    tujuan,
    TglLahir;
    pelanggan *next;
};
pelanggan* awal = NULL, *baru, *bantu, *sebelum;


struct Queue {
    int front = 0;
    int rear = 0;
    string nokereta[15];
    string keberangkatan[15];
    string tujuan[15];
    float harga[15];
} Q;


// check apakah queue full
bool isFull() {
    return Q.rear == 15;
}

// check apakah queue kosong
bool isEmpty() {
    return Q.rear == 0;
}

void printQueue() { //function untuk menampilkan queue
    if (isEmpty()) {
        cout << "Antrian Kosong\n\n";
    } else {
        cout << "Antiran Kereta: \n";
        for (int i = Q.front; i < Q.rear; i++) {
            cout << "Kereta NO." << Q.nokereta[i] 
                 << ", Keberangkatan: " << Q.keberangkatan[i]
                 << ", Tujuan: " << Q.tujuan[i]
                 << ", Harga: " << Q.harga[i] << endl;
        }
        cout << endl << endl;
    }
};

// function untuk menambahkan data di queue
void enqueue() {
    if (isFull()) {
        cout << "Queue Penuh" << endl;
    } else {
        string nokereta, keberangkatan, tujuan;
        float harga;

        cout << "Masukkan No Kereta: ";
        cin >> nokereta;
        cout << "Masukkan Keberangkatan: ";
        cin >> keberangkatan;
        cout << "Masukkan Tujuan: ";
        cin >> tujuan;
        cout << "Masukkan Harga: ";
        cin >> harga;

        Q.nokereta[Q.rear] = nokereta;
        Q.keberangkatan[Q.rear] = keberangkatan;
        Q.tujuan[Q.rear] = tujuan;
        Q.harga[Q.rear] = harga;

        Q.rear++;
        cout << "Data Ditambahkan\n"; system("cls");
    }
}

// function untuk menghapus data di queue
void dequeue() {
    if (isEmpty()) {
        cout << "Queue Kosong" << endl;
    } else {
        cout << "Mengeluarkan Kereta dari Antrian | No Kereta: " << Q.nokereta[Q.front] 
             << ", Keberangkatan: " << Q.keberangkatan[Q.front] 
             << ", Tujuan: " << Q.tujuan[Q.front] 
             << ", Harga: " << Q.harga[Q.front] << " |\n";

        for (int i = Q.front; i < Q.rear - 1; i++) {
            Q.nokereta[i] = Q.nokereta[i + 1];
            Q.keberangkatan[i] = Q.keberangkatan[i + 1];
            Q.tujuan[i] = Q.tujuan[i + 1];
            Q.harga[i] = Q.harga[i + 1];
        }
        Q.rear--;
        cout << "Kereta telah berangkat\n" <<endl;
    }
}

pelanggan bisnis[10];
int bns = 0;

void TambahBisnis(){
    if(bns > 9){
        cout << "Bisnis udah penuh" ;
        return;
    }
    cout << "Nama : "; cin >> bisnis[bns].nama;
    cout << "Stasiun Awal : "; cin >> bisnis[bns].awal;
    cout << "Tujuan : "; cin >> bisnis[bns].tujuan;
    cout << "Tgl Lahir (DD/MM/YY) : "; cin >> bisnis[bns].TglLahir; system("cls");
    bns += 1;
    return;
}

void TambahEkonomi() {
    baru = new pelanggan; // Membuat simpul baru untuk menyimpan data
    cout << "Nama : "; cin >> baru->nama;
    cout << "Stasiun Awal : "; cin >> baru->awal;
    cout << "Tujuan : "; cin >> baru->tujuan;
    cout << "Tgl Lahir (DD/MM/YY) : "; cin >> baru->TglLahir; system("cls");
    baru->next = awal; // Mengatur pointer next dari data baru untuk menunjuk ke data awal
    awal = baru; // Menjadikan data baru sebagai data awal
    system("cls");
}

void CariData() {
    string kls, cari;
    cout << "Masukkan Kelas (Bisnis/Ekonomi): "; 
    cin >> kls;
    
    if (kls == "Bisnis" || kls == "bisnis") {
        cout << "Masukkan Tanggal Lahir: "; cin >> cari; system("cls");
        
        for (int i = 0; i < bns; i++) {
            if (bisnis[i].TglLahir == cari) {
                for (int j = 0; j < Q.rear; j++) {
                    if (bisnis[i].awal == Q.keberangkatan[j] && bisnis[i].tujuan == Q.tujuan[j]) {
                        cout << "Nama: " << bisnis[i].nama << endl;
                        cout << "Stasiun Awal: " << bisnis[i].awal << endl;
                        cout << "Tujuan: " << bisnis[i].tujuan << endl;
                        cout << "Tgl Lahir: " << bisnis[i].TglLahir << endl;
                        cout << "No Kereta: " << Q.nokereta[j] << endl;
                        cout << "Harga: Rp." << Q.harga[j] << endl;
                        cout << endl;
                    }
                }
            }
        }
    } 
    else if (kls == "Ekonomi" || kls == "ekonomi") {
        cout << "Masukkan Tanggal Lahir: "; cin >> cari; system("cls");

        bantu = awal;
        while (bantu != NULL) {
            if (bantu->TglLahir == cari) {
                for (int j = 0; j < Q.rear; j++) {
                    if (bantu->awal == Q.keberangkatan[j] && bantu->tujuan == Q.tujuan[j]) {
                        cout << "Nama: " << bantu->nama << endl;
                        cout << "Stasiun Awal: " << bantu->awal << endl;
                        cout << "Tujuan: " << bantu->tujuan << endl;
                        cout << "Tgl Lahir: " << bantu->TglLahir << endl;
                        cout << "No Kereta: " << Q.nokereta[j] << endl;
                        cout << "Harga: Rp." << Q.harga[j] << endl;
                        cout << endl;
                    }
                }
            }
            bantu = bantu->next;
        }
    } 
    else {
        cout << "Kelas tidak valid." << endl;
    }
}

void EditData(){
    string kls,
    cari;
    int ubah;
    cout << "Masukan Kelas (Bisnis/Ekonomi): "; cin >> kls;
        if(kls == "Bisnis" || kls == "bisnis"){
            cout << "Masukan Tanggal Lahir : "; cin >> cari;
            for(int i = 0; i <= 9; i++){
                if(bisnis[i].TglLahir == cari){
                    cout << "Ubah apa?" << endl;
                    cout << "1. keberangkatan" << endl;
                    cout << "2. tujuan " << endl;
                    cout << "No : " ; cin >> ubah;system("cls");
                    
                    switch(ubah){
                        case 1:
                        cout << "Masukan Keberangkatan Baru : "; cin >> bisnis[i].awal;system("cls");
                        break;
                        case 2:
                        cout << "Masukan Tujuan Baru : "; cin >> bisnis[i].tujuan;system("cls");
                        break;
                    }
                }
            }
        }
        if(kls == "Ekonomi" || kls == "ekonomi"){
            cout << "Masukan Tgl Lahir : "; cin >> cari; // Meminta input tanggal lahir yang akan diedit
            bantu = awal;
            if(cari == bantu->TglLahir){
                    cout << "Ubah apa?" << endl;
                    cout << "1. keberangkatan" << endl;
                    cout << "2. tujuan " << endl;
                    cout << "No : "; cin >> ubah;system("cls");
                    
                    switch(ubah){
                        case 1:
                        cout << "Masukan Keberangkatan Baru : "; cin >> bisnis->awal;system("cls");
                        break;
                        case 2:
                        cout << "Masukan Tujuan Baru : "; cin >> bisnis->tujuan;system("cls");
                        break;
                    }
                }
        }
}

void DeleteData(){
    string kls,
    cari;
    int ubah;
    cout << "Masukan Kelas (Bisnis/Ekonomi): "; cin >> kls;
        if(kls == "Bisnis" || kls == "bisnis"){
            cout << "Masukan Tanggal Lahir : "; cin >> cari; system("cls");
            for(int i = 0; i <= 9; i++){
                if(bisnis[i].TglLahir == cari){
                    bisnis[i].nama = "";
                    bisnis[i].awal = "";
                    bisnis[i].TglLahir = "";
                    bisnis[i].tujuan = "";
                    bns -= 1;
                }
            }
        }
        if(kls == "Ekonomi" || kls == "ekonomi"){
            cout << "Masukan Tgl Lahir : "; cin >> cari; system("cls");
            bantu = awal;
            if(cari == bantu->TglLahir){
                    bantu = awal;
            sebelum = NULL;
            while (bantu != NULL) {
                if (bantu->TglLahir == cari) {
                    if (sebelum == NULL) {
                        awal = bantu->next; // Jika data yang akan dihapus adalah data awal, maka pointer awal diatur ke data berikutnya
                    }
                    else {
                        sebelum->next = bantu->next; // Jika data yang akan dihapus bukan data awal, maka pointer next dari data sebelumnya diatur ke data setelahnya
                    }
                    delete bantu; // Menghapus data yang telah ditemukan
                    cout << "Data berhasi dihapus yeay";
                    char blk;
                    cout << "\nKetik 1 untuk kembali ke menu  "; cin >> blk; system("cls");
                    return;
                }
                sebelum = bantu;
                bantu = bantu->next;
            }
        }
    }
}

void TampilData() {
    cout << "Kelas Bisnis : " << endl;
    for(int i =0; i <=10; i++){
        if(bisnis[i].nama != ""){
            cout << "Nama : " << bisnis[i].nama;
            cout << ", Stasiun Awal : " << bisnis[i].awal ;
            cout << ", Stasiun Tujuan : " << bisnis[i].tujuan ;
            cout << ", Tgl Lahir : " << bisnis[i].TglLahir << endl;
        }
    }
    cout << endl;
    cout << "Kelas Ekonomi : " << endl;
    bantu = awal; // Mengatur pointer bantu untuk menunjuk ke data awal
    while (bantu != NULL) {
        cout << "Nama : " << bantu->nama ;
        cout << ", Stasiun Awal : " << baru->awal ;
        cout << ", Tujuan : " << baru->tujuan ;
        cout << ", Tgl Lahir : " << bantu->TglLahir << endl;
        bantu = bantu->next; // Pindah ke data berikutnya dalam linked list
        cout << endl;
    }
}

void MenuAdmin(){
    int pil;
    char ubah;
    bool ulg = true;

    do{
    cout << "1. Atur Jadwal Kereta" << endl;
    cout << "2. Lihat Jadwal Kereta" << endl;
    cout << "3. Lihat Pesanan Tiket Kereta" << endl;
    cout << "4. Edit Pesanan Tiket Kereta" << endl;
    cout << "5. Hapus Pesanan Tiket Kereta" << endl;
    cout << "6. Kembali ke menu awal" << endl;
    cout << "No : "; cin >> pil; system("cls");

    switch (pil){
        case 1:
        cout << "Tambah Kereta atau Hapus Kereta (T/H) : "; cin >> ubah; system("cls");
        if(ubah == 'T' || ubah == 't'){
            enqueue();
        }
        if(ubah == 'H' || ubah == 'h'){
            dequeue();
        }
        break;
        case 2:
        printQueue();
        break;
        case 3:
        TampilData();
        break;
        case 4:
        EditData();
        break;
        case 5:
        DeleteData();
        break;
        case 6:
        ulg = false;
        break;
    }
    }while(ulg == true);
}

void LoginAdmin(){
    string Mimin[5]{"Kevin","Icshan","Faiz","Nania","Asfa"};
    string sandi[5]{"23025","23001","23002","23003","23004"};
    string staff;
    string password;
    cout << "Login : "; cin >> staff;
    for(int i = 0; i < 5; i++){
        if(staff == Mimin[i]){
            cout << "Password : "; cin >> password; system("cls");
        }
            if(password == sandi[i]){
                MenuAdmin();
            }
    }
}

void MenuPelanggan(){
    int pil;
    string kls;
    bool ulg = true;

    do {
    cout << "1. Lihat Jadwal Kereta" << endl;
    cout << "2. Pesan Tiket Kereta" << endl;
    cout << "3. Lihat Pesanan Tiket Kereta" << endl;
    cout << "4. Kembali ke menu awal" << endl;
    cout << "No : "; cin >> pil; system("cls");

    switch (pil){
        case 1:
        printQueue();
        break;
        case 2:
        cout << "Masukan Kelas (Bisnis/Ekonomi): "; cin >> kls;
        if(kls == "Bisnis" || kls == "bisnis"){
            TambahBisnis();
        }
        if(kls == "Ekonomi" || kls == "ekonomi"){
            TambahEkonomi();
        }
        break;
        case 3:
        CariData();
        break;
        case 4:
        ulg = false;
        break;
    }
    }while(ulg == true);
}


int main(){
    int pil;
    bool ulg = true;
    do {
        cout << " Selamat Datang " << endl;
        cout << "1. Admin" << endl;
        cout << "2. Pelanggan" << endl;
        cout << "3. Keluar" << endl;
        cout << "No : "; cin >> pil; system("cls");
        switch (pil){
            case 1:
            LoginAdmin();
            break;
            case 2:
            MenuPelanggan();
            break;
            case 3:
            ulg = false;
            break;
        }
    }while(ulg == true);


}