#include "Phonebook.h"
#include <fstream>
#include <iostream>
#include <sstream>

void Phonebook::addContact(const Contact &contact) {
    contacts.push_back(contact);
}

void Phonebook::removeContact(const std::string &name) {
    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        if (it->getName() == name) {
            contacts.erase(it);
            return;
        }
    }
    std::cout << "Liên lạc không tồn tại!" << std::endl;
}

Contact* Phonebook::findContact(const std::string &name) {
    for (auto &contact : contacts) {
        if (contact.getName() == name) {
            return &contact;
        }
    }
    return nullptr;
}

void Phonebook::displayAll() const {
    for (const auto &contact : contacts) {
        contact.display();
        std::cout << "------------------------" << std::endl;
    }
}

void Phonebook::saveToFile(const std::string &filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto &contact : contacts) {
            file << contact.getName() << "," << contact.getPhone() << "," << contact.getEmail() << "\n";
        }
        file.close();
    } else {
        std::cout << "Không thể mở file để lưu dữ liệu!" << std::endl;
    }
}

void Phonebook::loadFromFile(const std::string &filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            std::stringstream ss(line);
            std::string name, phone, email;
            getline(ss, name, ',');
            getline(ss, phone, ',');
            getline(ss, email, ',');
            contacts.push_back(Contact(name, phone, email));
        }
        file.close();
    } else {
        std::cout << "Không thể mở file để tải dữ liệu!" << std::endl;
    }
}
