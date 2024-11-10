#include<bits/stdc++.h>
#ifndef __DIEM__
#define __DIEM__
using namespace std;

class Diem{
	private:
		string msv; 
		float dToan;
		float dVan;
		float dAnh;
		float TBC; 
	public: 
		Diem(){
			msv = ""; 
			dToan = 0;
			dVan = 0;
			dAnh = 0;  
			TBC = 0; 
		} 
    	
    	friend std::istream& operator>>(std::istream &is, Diem &DiemIn) {
        cout << "Nhap ma sinh vien: ";
        is >> DiemIn.msv;
        
        cout << "Nhap diem toan: ";
        is >> DiemIn.dToan;
        
        cout << "Nhap diem van: ";
        is >> DiemIn.dVan;
		 
        cout << "Nhap diem anh: ";
        is >> DiemIn.dAnh;
        
        
        DiemIn.TBC = (DiemIn.dToan + DiemIn.dVan + DiemIn.dAnh) / 3;
        
        return is;
    	}
    	
    	friend std::ostream& operator<<(std::ostream &os, const Diem &DiemOut) {
        	os << "Ma sinh vien: " << DiemOut.msv << endl;
		    os << std::left << std::setw(12) << "Diem Toan" 
		       << std::setw(12) << "Diem Van" 
		       << std::setw(12) << "Diem Anh" 
		       << std::setw(12) << "TBC" << std::endl;
       
		    os << std::setw(12) << DiemOut.dToan 
		       << std::setw(12) << DiemOut.dVan 
		       << std::setw(12) << DiemOut.dAnh 
		       << std::setw(12) << DiemOut.TBC << std::endl;
 
        return os;
    	}
    	
    	bool operator<(const Diem &DiemSv2) const {
        	return this->TBC < DiemSv2.TBC;
    	}
    	
    	bool operator>(const Diem &DiemSv2) const {
        	return this->TBC > DiemSv2.TBC;
    	}
    	
    	string lay_msv(){
    		return this->msv; 
		}
		float lay_Toan(){
    		return this->dToan; 
		}
		float lay_Van(){
    		return this->dVan; 
		}
		float lay_Anh(){
    		return this->dAnh; 
		}
		float lay_TBC(){
            return TBC;
        }
}; 
#endif
