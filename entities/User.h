//
// Created by NicolaeMarius.Ghergu on 10/21/2021.
//

#ifndef UTILITYIT_USER_H
#define UTILITYIT_USER_H

#include <iostream>
#include <utility>

class User {
private:
    std::string firstName;
    std::string lastName;
    int cnp;
    std::string email;
    std::string sex;
    long birthdayDate;

public:
    User(std::string firstName, std::string lastName, int cnp, std::string email,
         std::string sex, long birthdayDate) : firstName(std::move(firstName)), lastName(std::move(lastName)), cnp(cnp), email(std::move(email)),
                                                      sex(std::move(sex)), birthdayDate(birthdayDate) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->email = email;
        this->cnp = cnp;
        this->sex = sex;
        this->birthdayDate = birthdayDate;
    }

    const std::string &getFirstName() const {
        return firstName;
    }

    void setFirstName(const std::string &firstName) {
        this->firstName = firstName;
    }

    const std::string &getLastName() const {
        return lastName;
    }

    void setLastName(const std::string &lastName) {
        this->lastName = lastName;
    }

    int getCnp() const {
        return cnp;
    }

    void setCnp(int cnp) {
        this->cnp = cnp;
    }

    const std::string &getEmail() const {
        return email;
    }

    void setEmail(const std::string &email) {
        this->email = email;
    }

    const std::string &getSex() const {
        return sex;
    }

    void setSex(const std::string &sex) {
        this->sex = sex;
    }

    long getBirthdayDate() const {
        return birthdayDate;
    }

    void setBirthdayDate(long birthdayDate) {
        this->birthdayDate = birthdayDate;
    }

    bool operator==(const User &rhs) const {
        return cnp == rhs.cnp;
    }

    bool operator!=(const User &rhs) const {
        return !(rhs == *this);
    }
};


#endif //UTILITYIT_USER_H
