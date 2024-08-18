#include "Contact.h"
#include <iostream>

Contact::Contact(const std::string &name, const std::string &phone, const std::string &email)
    : name(name), phone(phone), email(email) {}

std::string Contact::getName() const {
    return name;
}

void Contact::setName(const std::string &name) {
    this->name = name;
}

std::string Contact::getPhone() const {
    return phone;
}

void Contact::setPhone(const std::string &phone) {
    this->phone = phone;
}

std::string Contact::getEmail() const {
    return email;
}

void Contact::setEmail(const std::string &email) {
    this->email = email;
}

void Contact::display() const {
    std::cout << "Tên: " << name << "\nSố điện thoại: " << phone << "\nEmail: " << email << std::endl;
}
