#ifndef LIENHE_H
#define LIENHE_H

#include <string>

// Lớp Liên Hệ đại diện cho một liên hệ đơn giản với tên và số điện thoại.
class LienHe {
public:
    // Hàm khởi tạo với các tham số: tên và số điện thoại
    LienHe(const std::string& ten, const std::string& soDienThoai);

    // Lấy tên liên hệ
    std::string getTen() const;

    // Lấy số điện thoại liên hệ
    std::string getSoDienThoai() const;

    // Cập nhật số điện thoại mới cho liên hệ
    void setSoDienThoai(const std::string& soDienThoai);

private:
    std::string ten;           // Tên của liên hệ
    std::string soDienThoai;   // Số điện thoại của liên hệ
};

#endif // LIENHE_H
