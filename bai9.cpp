#include <iostream>
#include <string.h>
#include <vector>
#include <map>
using namespace std;

// tạo lớp khách hàng.
class Khách_Hàng {
private: // tạo bên trong lớp gồm có các thành viên không được truy cập.
    string Mã_Khách_Hàng;
    string Khu_Vực;
    int Chỉ_số_cũ;
    int Chỉ_số_mới;

public:// xác định các thuộc tính trong lớp 
    Khách_Hàng(string Mã, string Kv, int csc, int csm) : // csc = chỉ số cũ, csm = chỉ số mới, Kv = khu vực
        Mã_Khách_Hàng(Mã),
        Khu_Vực(Kv),
        Chỉ_số_cũ(csc),
        Chỉ_số_mới(csm) {}

    int Tính_số_KW() // tạo hàm trên lớp khách hàng
        const // cho phép không thay đổi
    {
        return Chỉ_số_mới - Chỉ_số_cũ;
    }

    double Đơn_Giá(const map<string, map<string, double>>& giá_thành) // khởi tạo máp với key là string và value là double.
        const
    {
        if (giá_thành.find(Khu_Vực) != giá_thành.end()) {
            if (giá_thành.at(Khu_Vực).find("loại") != giá_thành.at(Khu_Vực).end()) {
                return giá_thành.at(Khu_Vực).at("loại");
            }
        }
        return 0;
    }

    double Sum_tiền(const map<string, map<string, double>>& giá_thành) // khởi tạo máp với key là string và value là double.
        const
    {
        return Đơn_Giá(giá_thành) * Tính_số_KW();
    }

    void In_Thông_Tin()
        const
    {
        cout << "Danh sách khách hàng theo khu vực " << Khu_Vực << "\n";
        cout << " Mã khách hàng: " << Mã_Khách_Hàng << "\n";
        cout << " Khu vực:       " << Khu_Vực << "\n";
        cout << " Chỉ số cũ:     " << Chỉ_số_cũ << "\n";
        cout << " Chỉ số mới:    " << Chỉ_số_mới << "\n";

    }

};
// tạo lớp quản ly khách hàng:
class Quản_lý_khách_hàng {
private:

    vector < Khách_Hàng > danh_sách_khách_hàng; // ta sử dụng vector để có thể thêm xóa...
    map<string, map<string, double>>giá_thành;

public:
    // tạo hàm thêm khách hàng ở trong lớp quản lý...
    void Thếm_khách_hàng(const Khách_Hàng& khách_hàng) {
        danh_sách_khách_hàng.push_back(khách_hàng);// thêm phần tử vào vector 
    }

    // hàm in danh sách khách hàng:
    void In_ds_khách_hàng()
        const // không thay đổi đối tượng
    {

        for (const auto& khách_hàng : danh_sách_khách_hàng) {
            khách_hàng.In_Thông_Tin();
            cout << "Số KW được sử dụng: " << khách_hàng.Tính_số_KW() << endl;
            cout << "Đơn giá của khách hàng: " << khách_hàng.Đơn_Giá(giá_thành) <<" VND" << endl;
            cout << "Tổng tiền KH phải trả: " << khách_hàng.Sum_tiền(giá_thành) <<" VND" << endl;
            cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
        }
    }

    void thêm_giá_thành(const string& Khu_Vực, const map<string, double>& giá) {
        giá_thành[Khu_Vực] = giá;
    }
};

int main() {
    Quản_lý_khách_hàng Ql_khách_hàng;
    // thêm giữ liệu giá thành cho từng khu vực
    map<string, double > khu_vực_A01 = { {"loại", 500} }; // 01 ra khách hàng có khu vực loại 1
    map<string, double > khu_vực_A02 = { {"loại", 450} }; // 02 ra khách hàng có khu vực loại 2
    map<string, double > khu_vực_B01 = { {"loại", 460} };
    map<string, double > khu_vực_B02 = { {"loại", 440} };
    map<string, double > khu_vực_C01 = { {"loại", 450} };
    map<string, double > khu_vực_C02 = { {"loại", 430} };
    map<string, double > khu_vực_D01 = { {"loại", 420} };
    map<string, double > khu_vực_D02 = { {"loại", 410} };
    map<string, double > khu_vực_E01 = { {"loại", 410} };
    map<string, double > khu_vực_E02 = { {"loại", 400} };

    Ql_khách_hàng.thêm_giá_thành("A01", khu_vực_A01); // 01 ra khách hàng có khu vực loại 1
    Ql_khách_hàng.thêm_giá_thành("A02", khu_vực_A02); // 02 ra khách hàng có khu vực loại 2
    Ql_khách_hàng.thêm_giá_thành("B01", khu_vực_B01);
    Ql_khách_hàng.thêm_giá_thành("B02", khu_vực_B02);
    Ql_khách_hàng.thêm_giá_thành("C01", khu_vực_C01);
    Ql_khách_hàng.thêm_giá_thành("C02", khu_vực_C02);
    Ql_khách_hàng.thêm_giá_thành("D01", khu_vực_D01);
    Ql_khách_hàng.thêm_giá_thành("D02", khu_vực_D02);
    Ql_khách_hàng.thêm_giá_thành("E01", khu_vực_E01);
    Ql_khách_hàng.thêm_giá_thành("E02", khu_vực_E02);

    // nhập thông tin cho từng khách hàng
    int sl_khách_hàng;
    cout << "Nhập số lượng khách hàng: ";
    cin >> sl_khách_hàng;
    int Kv, csm, csc;
    string khu_vực, Mã;

    for (int i = 0; i < sl_khách_hàng; i++) {
        cout << "Nhập mã khách hàng: ";
        cin >> Mã;
        cout << "Nhập khu vực A01, A02, B01, B02, C01, C02, D01, D02, E01, E02: ";
        cin >> khu_vực;
        cout << "Nhập chỉ số cũ: ";
        cin >> csc;
        cout << "Nhập chỉ số mới: ";
        cin >> csm;

        Khách_Hàng khách_hàng(Mã, khu_vực, csc, csm);
        Ql_khách_hàng.Thếm_khách_hàng(khách_hàng);
    }

    // in danh sách khách hàng
    cout << "======================================" << endl;
    Ql_khách_hàng.In_ds_khách_hàng();
    return 0;
}
