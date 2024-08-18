#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact {
private:
    std::string name;
    std::string phone;
    std::string email;

public:
    // Constructor
    Contact(const std::string &name = "", const std::string &phone = "", const std::string &email = "");

    // Getter và Setter
    std::string getName() const;
    void setName(const std::string &name);

    std::string getPhone() const;
    void setPhone(const std::string &phone);

    std::string getEmail() const;
    void setEmail(const std::string &email);

    // Hiển thị thông tin liên lạc
    void display() const;
};

#endif // CONTACT_H
