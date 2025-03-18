#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
// Cấu trúc ListInt để quản lý danh sách liên kết
struct ListInt {
    Node* head; // Con trỏ đầu danh sách

    // Hàm khởi tạo danh sách rỗng
    ListInt() {
        head = nullptr;
    }

    // Hàm thêm phần tử vào cuối danh sách
    void append(int value) {
        Node* newNode = new Node{ value, nullptr };
        if (!head) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }

    // Hàm in danh sách
    void print() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Hàm chuyển từ mảng sang danh sách liên kết
    void fromArray(int a[], int n) {
        for (int i = 0; i < n; i++) {
            append(a[i]);
        }
    }
};
void nhapMang(int a[], int& n) {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void xuatMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void xoaPhanTu(int a[], int& n, int k) {
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == k) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < n - 1; i++) {
            a[i] = a[i + 1];
        }
        n--; // Giảm kích thước mảng
    }
}
void ghepMang(int a[], int& n, int b[], int m) {
    for (int i = 0; i < m; i++) {
        a[n] = b[i]; // Thêm phần tử từ b vào cuối a
        n++;
    }
}
// Hàm xuất danh sách liên kết
void xuatDanhSach(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int a[100], b[100], n = 10, m=5;

    // Nhập 10 số nguyên
    cout << "Nhap 10 so: ";
    nhapMang(a, n);

    // In danh sách
    cout << "Danh sach: ";
    xuatMang(a, n);

    // Nhập số cần xóa
    cout << "Nhap so can xoa: ";
    int k;
    cin >> k;
    xoaPhanTu(a, n, k);

    // In danh sách sau khi xóa
    cout << "Danh sach sau khi xoa: ";
    xuatMang(a, n);


    cout << "Nhap 5 so vao danh sach thu hai: ";
    nhapMang(b, m);

    // Ghép danh sách thứ hai vào danh sách thứ nhất
    ghepMang(a, n, b, m);

    // In danh sách sau khi ghép
    cout << "Danh sach sau khi ghep: ";
    xuatMang(a, n);
   

    ListInt list1; list1.fromArray(a, n);
    cout << "Danh sach lien ket tu mang: "; list1.print();


    return 0;
}
