#include <iostream>
#include <cstring>
using namespace std;

// Cấu trúc dữ liệu SinhVien
struct SinhVien {
    char hoTen[50];
    char diaChi[70];
    char lop[10];
    int khoa;
};

// Hàm nhập và xuất sinh viên
void nhapSinhVien(SinhVien &sv) {
    cin.ignore();
    cout << "Nhap ho ten: ";
    cin.getline(sv.hoTen, 50);
    cout << "Nhap dia chi: ";
    cin.getline(sv.diaChi, 70);
    cout << "Nhap lop: ";
    cin.getline(sv.lop, 10);
    cout << "Nhap khoa: ";
    cin >> sv.khoa;
}

void xuatSinhVien(const SinhVien &sv) {
    cout << "Ho ten: " << sv.hoTen << endl;
    cout << "Dia chi: " << sv.diaChi << endl;
    cout << "Lop: " << sv.lop << endl;
    cout << "Khoa: " << sv.khoa << endl;
}

// Cấu trúc danh sách liên kết
struct Node {
    SinhVien data;
    Node *next;
};

struct ListSV {
    Node *head;
};

void khoiTao(ListSV &list) {
    list.head = nullptr;
}

void themSinhVien(ListSV &list, const SinhVien &sv) {
    Node *newNode = new Node{sv, nullptr};
    if (list.head == nullptr) {
        list.head = newNode;
    } else {
        Node *temp = list.head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }
}

void xuatDanhSach(const ListSV &list) {
    Node *temp = list.head;
    while (temp != nullptr) {
        xuatSinhVien(temp->data);
        cout << "-------------------------" << endl;
        temp = temp->next;
    }
}

void xoaSinhVienTheoTen(ListSV &list, const char *ten) {
    Node *temp = list.head, *prev = nullptr;
    while (temp != nullptr && strcmp(temp->data.hoTen, ten) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr) return;
    if (prev == nullptr) list.head = temp->next;
    else prev->next = temp->next;
    delete temp;
}

void xoaSinhVienTheoDiaChi(ListSV &list, const char *diaChi) {
    Node *temp = list.head, *prev = nullptr;
    while (temp != nullptr && strcmp(temp->data.diaChi, diaChi) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr) return;
    if (prev == nullptr) list.head = temp->next;
    else prev->next = temp->next;
    delete temp;
}

int main() {
    ListSV ds;
    khoiTao(ds);

    // Nhập 10 sinh viên
    for (int i = 0; i < 10; ++i) {
        SinhVien sv;
        cout << "Nhap thong tin sinh vien " << i + 1 << ":\n";
        nhapSinhVien(sv);
        themSinhVien(ds, sv);
    }

    cout << "\nDanh sach sinh vien vua nhap:\n";
    xuatDanhSach(ds);

    // Xóa sinh viên có tên "Nguyen Van Teo"
    xoaSinhVienTheoTen(ds, "Nguyen Van Teo");

    // Xóa sinh viên có địa chỉ "Nguyen Van Cu"
    xoaSinhVienTheoDiaChi(ds, "Nguyen Van Cu");

    // Thêm sinh viên mới
    SinhVien svMoi = {"Tran Thi Mo", "25 Hong Bang", "TT0901", 2009};
    themSinhVien(ds, svMoi);

    cout << "\nDanh sach sau khi xoa va them sinh vien:\n";
    xuatDanhSach(ds);

    return 0;
}

