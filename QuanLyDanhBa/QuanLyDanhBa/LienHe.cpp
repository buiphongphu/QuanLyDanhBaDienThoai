#include "LienHe.h"

// Hàm khởi tạo lớp Liên Hệ
LienHe::LienHe(const std::string& ten, const std::string& soDienThoai)
    : ten(ten), soDienThoai(soDienThoai) {}

// Lấy tên của liên hệ
std::string LienHe::getTen() const {
    return ten;
}

// Lấy số điện thoại của liên hệ
std::string LienHe::getSoDienThoai() const {
    return soDienThoai;
}

// Cập nhật số điện thoại của liên hệ
void LienHe::setSoDienThoai(const std::string& soDienThoai) {
    this->soDienThoai = soDienThoai;
}
