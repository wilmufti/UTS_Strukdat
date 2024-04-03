#include <iostream>
#include <string>
using namespace std;

// Structure informasi di dalam tiket
struct Tiket {
    string namaPenumpang;
    int nomorKursi;
    bool status;
};

// linked list untuk menyimpan data tiket
struct Node {
    Tiket data;
    Node* next;
};

// Fungsi untuk menambahkan node baru ke linked list
void tambahNode(Node*& head, Tiket tiket) {
    Node* newNode = new Node;
    newNode->data = tiket;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Fungsi untuk menampilkan data tiket
void tampilkanTiket(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << "Nama Penumpang: " << temp->data.namaPenumpang << ", Nomor Kursi: " << temp->data.nomorKursi;
        if (temp->data.status)
            cout << " (Sudah Dipesan)";
        else
            cout << " (Belum Dipesan)";
        cout << endl;
        temp = temp->next;
    }
}

int main() {
    const int JUMLAH_KURSI = 10;
    // Array satu dimensi untuk menyimpan data tiket
    Tiket tiketBus[JUMLAH_KURSI];
    Node* head = nullptr;

    // Inisialisasi data tiket awal
    for (int i = 0; i < JUMLAH_KURSI; ++i) {
        tiketBus[i].nomorKursi = i + 1;
        tiketBus[i].status = false;
    }

    int pilihan;
    do {
        cout << "-------------------PO. Bus Brawijaya----------------------------\n";
        cout << "\nPilih Menu:\n";
        cout << "1. Pesan Tiket\n";
        cout << "2. Tampilkan Tiket yang Dipesan\n";
        cout << "3. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                string nama;
                int nomorKursi;
                cout << "Masukkan Nama Penumpang: ";
                cin >> nama;
                cout << "Masukkan Nomor Kursi yang Ingin Dipesan (1-" << JUMLAH_KURSI << "): ";
                cin >> nomorKursi;
                if (nomorKursi < 1 || nomorKursi > JUMLAH_KURSI) {
                    cout << "Nomor Kursi tidak valid\n";
                } else if (tiketBus[nomorKursi - 1].status) {
                    cout << "Maaf, kursi tersebut sudah dipesan\n";
                } else {
                    tiketBus[nomorKursi - 1].namaPenumpang = nama;
                    tiketBus[nomorKursi - 1].status = true;
                    tambahNode(head, tiketBus[nomorKursi - 1]);
                    cout << "Tiket berhasil dipesan untuk " << nama << " pada kursi nomor " << nomorKursi << endl;
                }
                break;
            }
            case 2:
                cout << "Daftar Tiket yang Sudah Dipesan:\n";
                tampilkanTiket(head);
                break;
            case 3:
                cout << "Terima kasih telah membeli tiket di PO kami.\n";
                break;
            default:
                cout << "Pilihan tidak valid\n";
        }
    } while (pilihan != 3);

    return 0;
}
