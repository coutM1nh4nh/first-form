#include <iostream>
using namespace std;
 
class NhanVien {
private:
    // mã nhân viên là tự động được gán khi tạo đối tượng
    // thay vì truyền từ bên ngoài
    int code;
    string name;
    string gender;
    string date;
    string address;
    string taxCode;
    string contractDate;
 
    
public:
    static string titleString() {
        return "updatedString";
    }
    static int counter;
    NhanVien() {
        this->code = counter;
        counter += 1;
    }
    NhanVien(string name, string gender, string date, string address, string taxCode, string contractDate) {
        // khi khởi tạo gán cho 1 cái mã tăng dần từ 1->
        this->code = counter;
        counter += 1;
        this->name = name;
        this->gender = gender;
        this->date = date;
        this->address = address;
        this->taxCode = taxCode;
        this->contractDate = contractDate;
    }
 
    int getCode() {
        return this->code;
    }
    string getName() {
        return this->name;
    }
    string getGender() {
        return this->gender;
    }
 
    void setName(string name) {
        this->name = name;
    }
 
    void setGender(string gender) {
        this->gender = gender;
    }
    
};
 
int NhanVien::counter = 1;
 
int main() {
    NhanVien a, b, c;
    cout << a.getCode() << " " << b.getCode();
 
    NhanVien::titleString();
 
    // cout << NhanVien::counter;
}