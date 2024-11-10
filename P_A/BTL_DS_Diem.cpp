#include <bits/stdc++.h>
#include "./BTL_Diem.cpp" 
#ifndef __LISTDIEM__
#define __LISTDIEM__
using namespace std;
class ListDiem{
	list<Diem> DS_Diem;
	public:
		void nhapDiem(int n){
			for (int i = 0; i < n; ++i) {
	            Diem sv;
	            cout << "\nNhap thong tin sinh vien thu " << i + 1 << ":\n";
	            cin >> sv;
	            DS_Diem.push_back(sv);
        	}
		}
		void xuatDiem() const {
	        cout << "\nDanh sach sinh vien:\n";
	        for (const auto &sv : DS_Diem) {
	            cout << sv << endl; 
        	}
    	}
			
    	void sapXepDiem() {
        	DS_Diem.sort();
    	}
    	
    	Diem TimMAX() const{
	        Diem maxDiem = DS_Diem.front();
	        for (const auto &sv : DS_Diem) {
	        	if (maxDiem < sv){
	        		maxDiem = sv; 
				}
        	}
	        return maxDiem;
   		}
   		
   		Diem TimMIN() const{
	        Diem minDiem = DS_Diem.front();
	        for (const auto &sv : DS_Diem) {
	        	if (minDiem > sv){
	        		minDiem = sv; 
				}
        	}
	        return minDiem;
   		}
   		
   		void xoaTheoMaSV(const string &maSV) {
		    for (auto it = DS_Diem.begin(); it != DS_Diem.end(); ) {
		        if (it->lay_msv() == maSV) {
		            it = DS_Diem.erase(it);
		        } else {
		            ++it;
		        }
		    }
		}

}; 
#endif
//int main(){
//	ListDiem danhSach;
//    int n;
//    cout << "Nhap so luong sinh vien: ";
//    cin >> n;
//    cin.ignore(); 
//    danhSach.nhapDiem(n); 
//    danhSach.sapXepDiem();
//    danhSach.xoaTheoMaSV("2");
//    danhSach.xuatDiem(); 
//    
//    cout << "diem cao nhat : " << danhSach.TimMAX().lay_TBC();
//	cout << " min " << danhSach.TimMIN().lay_TBC(); 
//    return 0;	
//} 
