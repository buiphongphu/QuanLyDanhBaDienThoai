#ifndef DANHBA_H
#define DANHBA_H

#include "LienHe.h"
#include <vector>
#include <algorithm>
#include <fstream>   // Thư viện để sử dụng file I/O

// Lớp DanhBa quản lý danh bạ liên hệ
class DanhBa {
public:
    // Thêm một liên hệ mới vào danh bạ
    void themLienHe(const LienHe& lienHe);

    // Tìm liên hệ theo tên và trả về con trỏ đến liên hệ tìm được
    LienHe* timLienHeTheoTen(const std::string& ten);

    // Sửa số điện thoại của liên hệ theo tên
    bool suaLienHe(const std::string& ten, const std::string& soDienThoaiMoi);

    // Xóa liên hệ theo tên
    bool xoaLienHe(const std::string& ten);

    // In tất cả các liên hệ trong danh bạ
    void inTatCaLienHe() const;

    // Hàm mới để lưu danh bạ vào file
    void luuDanhBa(const std::string& tenFile) const;

    // Hàm mới để tải danh bạ từ file
    void taiDanhBa(const std::string& tenFile);

private:
    std::vector<LienHe> danhSachLienHe; // Danh sách các liên hệ
};

#endif // DANHBA_H
