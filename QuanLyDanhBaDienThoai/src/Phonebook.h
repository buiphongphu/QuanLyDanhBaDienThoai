#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <vector>
#include "Contact.h"

class Phonebook {
private:
    std::vector<Contact> contacts;

public:
    // Thêm liên lạc mới
    void addContact(const Contact &contact);

    // Xóa liên lạc theo tên
    void removeContact(const std::string &name);

    // Tìm kiếm liên lạc theo tên
    Contact* findContact(const std::string &name);

    // Hiển thị toàn bộ danh bạ
    void displayAll() const;

    // Lưu dữ liệu vào file
    void saveToFile(const std::string &filename) const;

    // Tải dữ liệu từ file
    void loadFromFile(const std::string &filename);
};

#endif // PHONEBOOK_H
