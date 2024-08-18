#include <iostream>
#include <limits>
#include "Phonebook.h"

void printMenu() {
    std::cout << "1. Thêm liên lạc\n"
              << "2. Xóa liên lạc\n"
              << "3. Tìm kiếm liên lạc\n"
              << "4. Hiển thị toàn bộ danh bạ\n"
              << "5. Lưu dữ liệu\n"
              << "6. Tải dữ liệu\n"
              << "0. Thoát\n"
              << "Chọn một tùy chọn: ";
}

int main() {
    Phonebook phonebook;
    int choice;
    std::string name, phone, email, filename;

    do {
        printMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer

        switch (choice) {
            case 1:
                std::cout << "Nhập tên liên lạc: ";
                std::getline(std::cin, name);
                std::cout << "Nhập số điện thoại: ";
                std::getline(std::cin, phone);
                std::cout << "Nhập email: ";
                std::getline(std::cin, email);
                phonebook.addContact(Contact(name, phone, email));
                break;
            case 2:
                std::cout << "Nhập tên liên lạc cần xóa: ";
                std::getline(std::cin, name);
                phonebook.removeContact(name);
                break;
            case 3:
                std::cout << "Nhập tên liên lạc cần tìm: ";
                std::getline(std::cin, name);
                Contact* contact;
                contact = phonebook.findContact(name);
                if (contact) {
                    contact->display();
                } else {
                    std::cout << "Liên lạc không tồn tại!" << std::endl;
                }
                break;
            case 4:
                phonebook.displayAll();
                break;
            case 5:
                std::cout << "Nhập tên file để lưu dữ liệu: ";
                std::getline(std::cin, filename);
                phonebook.saveToFile(filename);
                break;
            case 6:
                std::cout << "Nhập tên file để tải dữ liệu: ";
                std::getline(std::cin, filename);
                phonebook.loadFromFile(filename);
                break;
            case 0:
                std::cout << "Thoát chương trình." << std::endl;
                break;
            default:
                std::cout << "Lựa chọn không hợp lệ, vui lòng thử lại." << std::endl;
                break;
        }
    } while (choice != 0);

    return 0;
}
