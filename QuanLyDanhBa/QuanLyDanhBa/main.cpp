#include "DanhBa.h"
#include <iostream>
#include <regex> // Thư viện để sử dụng biểu thức chính quy

// Hàm xóa màn hình console
void clearScreen() {
#if defined(_WIN32)
    system("cls"); // Xóa màn hình trên hệ điều hành Windows
#elif defined(__linux__) || defined(__APPLE__)
    system("clear"); // Xóa màn hình trên hệ điều hành Linux và macOS
#endif
}

// Hàm hiển thị menu chính của chương trình
void hienThiMenu() {
    std::cout << "\n=== QUAN LY DANH BA ===" << std::endl;
    std::cout << "1. Thêm liên hệ" << std::endl;
    std::cout << "2. Sửa liên hệ" << std::endl;
    std::cout << "3. Xóa liên hệ" << std::endl;
    std::cout << "4. Tìm kiếm liên hệ" << std::endl;
    std::cout << "5. Hiển thị tất cả liên hệ" << std::endl;
    std::cout << "0. Thoát" << std::endl;
    std::cout << "========================" << std::endl;
    std::cout << "Chọn chức năng: ";
}

// Hàm kiểm tra tính hợp lệ của tên liên hệ
bool kiemTraTen(const std::string& ten) {
    // Tên liên hệ phải không rỗng, không chứa số và chỉ chứa ký tự chữ cái và khoảng trắng
    return !ten.empty() && std::regex_match(ten, std::regex("^[A-Za-z\\s]+$"));
}

// Hàm kiểm tra tính hợp lệ của số điện thoại
bool kiemTraSoDienThoai(const std::string& soDienThoai) {
    // Số điện thoại phải chứa đúng 10 chữ số và không chứa ký tự đặc biệt
    return std::regex_match(soDienThoai, std::regex("^\\d{10}$"));
}

int main() {
    DanhBa danhBa; // Tạo đối tượng DanhBa để quản lý danh bạ
    std::string tenFile = "danhba.txt";  // Tên file để lưu trữ danh bạ
    danhBa.taiDanhBa(tenFile);           // Tải danh bạ từ file

    int luaChon; // Biến lưu lựa chọn của người dùng

    do {
        clearScreen();  // Xóa màn hình trước khi hiển thị menu
        hienThiMenu();  // Hiển thị menu
        std::cin >> luaChon;  // Nhận lựa chọn từ người dùng

        // Kiểm tra nếu đầu vào không hợp lệ
        if (std::cin.fail()) {
            std::cin.clear(); // Xóa cờ lỗi trên dòng
            std::cin.ignore(10000, '\n'); // Bỏ qua các ký tự còn lại trong dòng
            luaChon = -1; // Đặt một giá trị không hợp lệ để kích hoạt thông báo lỗi
        }

        clearScreen();  // Xóa màn hình sau khi nhận lựa chọn

        switch (luaChon) {
        case 1: { // Thêm liên hệ
            std::string ten, soDienThoai;
            std::cout << "Nhập tên liên hệ: ";
            std::cin >> ten; // Nhập tên liên hệ
            if (!kiemTraTen(ten)) {
                std::cout << "Tên không hợp lệ. Tên không được chứa số hoặc để trống." << std::endl;
                break;
            }
            // Kiểm tra xem liên hệ đã tồn tại chưa
            if (danhBa.timLienHeTheoTen(ten) != nullptr) {
                std::cout << "Liên hệ với tên này đã tồn tại." << std::endl;
                break;
            }
            std::cout << "Nhập số điện thoại: ";
            std::cin >> soDienThoai; // Nhập số điện thoại
            if (!kiemTraSoDienThoai(soDienThoai)) {
                std::cout << "Số điện thoại không hợp lệ. Số điện thoại phải chứa đúng 10 chữ số và không chứa ký tự đặc biệt." << std::endl;
                break;
            }
            LienHe lienHe(ten, soDienThoai); // Tạo đối tượng LienHe mới
            danhBa.themLienHe(lienHe); // Thêm liên hệ vào danh bạ
            std::cout << "Đã thêm liên hệ: " << ten << std::endl;
            break;
        }
        case 2: { // Sửa liên hệ
            std::string ten, soDienThoaiMoi;
            std::cout << "Nhập tên liên hệ cần sửa: ";
            std::cin >> ten; // Nhập tên liên hệ cần sửa
            if (!kiemTraTen(ten)) {
                std::cout << "Tên không hợp lệ. Tên không được chứa số hoặc để trống." << std::endl;
                break;
            }
            std::cout << "Nhập số điện thoại mới: ";
            std::cin >> soDienThoaiMoi; // Nhập số điện thoại mới
            if (!kiemTraSoDienThoai(soDienThoaiMoi)) {
                std::cout << "Số điện thoại không hợp lệ. Số điện thoại phải chứa đúng 10 chữ số và không chứa ký tự đặc biệt." << std::endl;
                break;
            }
            // Sửa số điện thoại của liên hệ
            if (danhBa.suaLienHe(ten, soDienThoaiMoi)) {
                std::cout << "Đã sửa số điện thoại của " << ten << " thành " << soDienThoaiMoi << std::endl;
            }
            else {
                std::cout << "Không tìm thấy liên hệ để sửa." << std::endl;
            }
            break;
        }
        case 3: { // Xóa liên hệ
            std::string ten;
            std::cout << "Nhập tên liên hệ cần xóa: ";
            std::cin >> ten; // Nhập tên liên hệ cần xóa
            if (!kiemTraTen(ten)) {
                std::cout << "Tên không hợp lệ. Tên không được chứa số hoặc để trống." << std::endl;
                break;
            }
            // Xóa liên hệ khỏi danh bạ
            if (danhBa.xoaLienHe(ten)) {
                std::cout << "Đã xóa liên hệ: " << ten << std::endl;
            }
            else {
                std::cout << "Không tìm thấy liên hệ để xóa." << std::endl;
            }
            break;
        }
        case 4: { // Tìm kiếm liên hệ
            std::string ten;
            std::cout << "Nhập tên cần tìm kiếm: ";
            std::cin >> ten; // Nhập tên cần tìm kiếm
            if (!kiemTraTen(ten)) {
                std::cout << "Tên không hợp lệ. Tên không được chứa số hoặc để trống." << std::endl;
                break;
            }
            LienHe* lienHe = danhBa.timLienHeTheoTen(ten); // Tìm liên hệ theo tên
            if (lienHe) {
                std::cout << "Tìm thấy: " << lienHe->getTen()
                    << " với số điện thoại: " << lienHe->getSoDienThoai() << std::endl;
            }
            else {
                std::cout << "Không tìm thấy liên hệ." << std::endl;
            }
            break;
        }
        case 5: { // Hiển thị tất cả liên hệ
            std::cout << "\n--- Danh Sách Liên Hệ ---\n";
            danhBa.inTatCaLienHe(); // In tất cả liên hệ trong danh bạ
            std::cout << "-------------------------\n";
            break;
        }
        case 0: // Thoát chương trình
            std::cout << "Đang thoát chương trình và lưu danh bạ..." << std::endl;
            danhBa.luuDanhBa(tenFile);  // Lưu danh bạ vào file khi thoát
            break;
        default:
            std::cout << "Lựa chọn không hợp lệ. Vui lòng chọn lại." << std::endl;
        }

        if (luaChon != 0) {
            std::cout << "\nNhấn phím Enter để tiếp tục...";
            std::cin.ignore(); // Xóa bộ đệm đầu vào
            std::cin.get();  // Đợi người dùng nhấn Enter
        }

    } while (luaChon != 0); // Lặp lại cho đến khi người dùng chọn thoát

    return 0; // Kết thúc chương trình
}
