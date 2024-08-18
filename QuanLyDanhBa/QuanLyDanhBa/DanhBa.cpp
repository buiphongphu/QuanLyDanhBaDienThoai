#include "DanhBa.h"
#include <iostream>
#include <fstream>
#include <algorithm>

// Hàm thêm liên hệ vào danh sách
void DanhBa::themLienHe(const LienHe& lienHe) {
    // Sử dụng hàm timLienHeTheoTen để kiểm tra xem liên hệ đã tồn tại chưa
    if (timLienHeTheoTen(lienHe.getTen()) == nullptr) {
        // Nếu chưa tồn tại, thêm liên hệ vào danh sách
        danhSachLienHe.push_back(lienHe);
        std::cout << "Đã thêm liên hệ: " << lienHe.getTen() << std::endl;
        // Lưu danh bạ vào file sau khi thêm liên hệ
        luuDanhBa("danhba.txt"); // Thay "danhba.txt" bằng tên file bạn muốn lưu
    }
    else {
        // Nếu đã tồn tại, thông báo rằng liên hệ đã có trong danh sách
        std::cout << "Liên hệ đã tồn tại!" << std::endl;
    }
}

// Hàm tìm liên hệ theo tên
LienHe* DanhBa::timLienHeTheoTen(const std::string& ten) {
    // Sử dụng std::find_if để tìm liên hệ có tên tương ứng
    auto it = std::find_if(danhSachLienHe.begin(), danhSachLienHe.end(),
        [&ten](const LienHe& lienHe) {
            return lienHe.getTen() == ten;  // Điều kiện tìm kiếm là so sánh tên liên hệ
        });

    // Nếu tìm thấy liên hệ, trả về con trỏ đến liên hệ đó
    if (it != danhSachLienHe.end()) {
        return &(*it);
    }
    // Nếu không tìm thấy, trả về nullptr
    return nullptr;
}

// Hàm sửa số điện thoại của một liên hệ dựa trên tên
bool DanhBa::suaLienHe(const std::string& ten, const std::string& soDienThoaiMoi) {
    // Tìm liên hệ bằng tên
    LienHe* lienHe = timLienHeTheoTen(ten);
    if (lienHe) {
        // Nếu tìm thấy, cập nhật số điện thoại mới
        lienHe->setSoDienThoai(soDienThoaiMoi);
        std::cout << "Đã sửa số điện thoại của " << ten << " thành " << soDienThoaiMoi << std::endl;
        // Lưu danh bạ vào file sau khi sửa liên hệ
        luuDanhBa("danhba.txt"); // Thay "danhba.txt" bằng tên file bạn muốn lưu
        return true;
    }
    std::cout << "Không tìm thấy liên hệ để sửa." << std::endl;
    return false;
}

// Hàm xóa liên hệ khỏi danh sách dựa trên tên
bool DanhBa::xoaLienHe(const std::string& ten) {
    // Sử dụng std::remove_if để tìm và xóa liên hệ có tên tương ứng
    auto it = std::remove_if(danhSachLienHe.begin(), danhSachLienHe.end(),
        [&ten](const LienHe& lienHe) {
            return lienHe.getTen() == ten;  // Điều kiện xóa là tên liên hệ
        });

    // Kiểm tra xem có liên hệ nào đã bị xóa hay không
    if (it != danhSachLienHe.end()) {
        // Xóa liên hệ khỏi danh sách
        danhSachLienHe.erase(it, danhSachLienHe.end());
        std::cout << "Đã xóa liên hệ: " << ten << std::endl;
        // Lưu danh bạ vào file sau khi xóa liên hệ
        luuDanhBa("danhba.txt"); // Thay "danhba.txt" bằng tên file bạn muốn lưu
        return true;
    }
    std::cout << "Không tìm thấy liên hệ để xóa." << std::endl;
    return false;
}

// Hàm in tất cả các liên hệ ra màn hình
void DanhBa::inTatCaLienHe() const {
    for (const auto& lienHe : danhSachLienHe) {
        // In thông tin của từng liên hệ
        std::cout << "Tên: " << lienHe.getTen()
            << ", Số Điện Thoại: " << lienHe.getSoDienThoai() << std::endl;
    }
}

// Hàm lưu danh sách liên hệ vào file
void DanhBa::luuDanhBa(const std::string& tenFile) const {
    // Mở file để ghi dữ liệu
    std::ofstream fileOut(tenFile);
    if (fileOut.is_open()) {
        for (const auto& lienHe : danhSachLienHe) {
            // Ghi tên và số điện thoại của từng liên hệ vào file
            fileOut << lienHe.getTen() << "," << lienHe.getSoDienThoai() << std::endl;
        }
        fileOut.close();
        std::cout << "Đã lưu danh bạ vào file " << tenFile << std::endl;
    }
    else {
        std::cerr << "Không thể mở file để lưu danh bạ!" << std::endl;
    }
}

// Hàm tải danh bạ từ file vào danh sách
void DanhBa::taiDanhBa(const std::string& tenFile) {
    // Mở file để đọc dữ liệu
    std::ifstream fileIn(tenFile);
    if (fileIn.is_open()) {
        // Xóa danh sách hiện tại trước khi tải danh sách mới
        danhSachLienHe.clear();
        std::string ten, soDienThoai;
        while (std::getline(fileIn, ten, ',') && std::getline(fileIn, soDienThoai)) {
            // Thêm liên hệ mới vào danh sách
            danhSachLienHe.emplace_back(ten, soDienThoai);
        }
        fileIn.close();
        std::cout << "Đã tải danh bạ từ file " << tenFile << std::endl;
    }
    else {
        std::cerr << "Không thể mở file để tải danh bạ!" << std::endl;
    }
}
