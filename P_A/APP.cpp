#include <bits/stdc++.h>
#include "./BTL_DS_Diem.cpp" 
#include "./BTL_Diem.cpp"
#ifndef __APP__
#define __APP__ 
using namespace std;
class App {
    ListDiem danhSachDiem;  

public:
    void runMenu() {
        int choice;
        do {
            cout << "==== MENU ====" << endl;
            cout << "1. Nhap thong tin sinh vien" << endl;
            cout << "2. Xuat danh sach sinh vien" << endl;
            cout << "3. Sap xep danh sach theo TBC" << endl;
            cout << "4. Tim diem trung binh cao nhat" << endl;
            cout << "5. Tim diem trung binh thap nhat" << endl;
            cout << "6. Xoa sinh vien theo ma" << endl;
            cout << "0. Thoat" << endl;
            cout << "Nhap lua chon: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    int n; 
                    cout << "Nhap so luong sinh vien: ";
                    cin >> n; 
                    danhSachDiem.nhapDiem(n);
                    break;
                }
                case 2:
                    danhSachDiem.xuatDiem();
                    break;
                case 3:
                    danhSachDiem.sapXepDiem();
                    cout << "Danh sach da duoc sap xep theo TBC." << endl;
                    break;
                case 4:
                    cout << "\nSinh vien co TBC cao nhat:\n";
                    cout << danhSachDiem.TimMAX();
                    break;
                case 5:
                    cout << "\nSinh vien co TBC cao nhat:\n";
                    cout << danhSachDiem.TimMIN();
                    break;
                case 6: {
                    string maSV; 
                    cout << "Nhap ma SV can xoa: "; 
                    cin >> maSV; 
                    danhSachDiem.xoaTheoMaSV(maSV);
                    cout << "Danh sach sau khi xoa:\n";
                    danhSachDiem.xuatDiem();
                    break;
                }
                case 0:
                    cout << "Thoat chuong trinh." << endl;
                    break;
                default:
                    cout << "Lua chon khong hop le." << endl;
            }
            cout << endl;
        } while (choice != 0);
    }
};
#endif
