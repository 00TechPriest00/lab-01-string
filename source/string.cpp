// Copyright 2018 Your Name <your_email>
//#ifndef INCLUDE_STRING_HPP_
//#define INCLUDE_STRING_HPP_
#include "../include/string.hpp"
#include "string.hpp"

String::String() {
    Data = new char[1]();
    Data[0] = '\0';
}

String::~String() {
    delete[] Data;
}

String::String(const String& rhs) {
    size_t n = std::strlen(rhs.Data);
    Data = new char[n + 1]();
    for (size_t i = 0; i < n; i++) {
        Data[i] = rhs.Data[i];
    }
    Data[n] = '\0';
}

String::String(const char* data) {
    size_t  n = std::strlen(data);
    Data = new char [n+1]();
    for (size_t i = 0; i < n; i++) {
        Data[i] = data[i];
    }
    Data[n] = '\0';
}

String& String::operator=(const String& rhs) {
    if (*this == rhs) {
        return *this;
    }
    if (Data) {
        delete[] Data;
    }
    size_t  n = std::strlen(rhs.Data);
    Data = new char[n + 1]();
    for (size_t i = 0; i < n; i++) {
        Data[i] = rhs.Data[i];
    }
    Data[n] = '\0';
    return *this;
}

String& String::operator+=(const String& rhs) {
    size_t n1 = std::strlen(Data);
    size_t n2 = std::strlen(rhs.Data);
    char* mem = new char[n1+n2+1]();
    for (size_t i = 0; i < n1; i++) {
        mem[i] = Data[i];
    }
    for (size_t i = n1; i < n1+n2; i++) {
        mem[i] = rhs.Data[i-n1];
    }
    mem[n1 + n2] = '\0';
    delete[] Data;
    Data = new char[n1 + n2 + 1];
    for (size_t i = 0; i < n1 + n2; i++) {
      Data[i] = mem[i];
    }
    Data[n1 + n2] = '\0';
    delete[] mem;
    return *this;
}

String& String::operator*=(unsigned int m){
    size_t n = std::strlen(Data);
    auto mem = new char[n*m + 1]();
    for (size_t i = 0; i < n*m; i++) {
       mem[i] = Data[i%n];
    }
    delete[] Data;
    Data = new char[n*m+1];
    for (size_t i = 0; i < n*m; i++) {
        Data[i] = mem[i];
    }
    Data[n*m] = '\0';
    delete[] mem;
    return *this;
}

String operator+(const String& a, const String& b) {
    String prom(a);
    prom += b;
    return prom;
}

String operator*(const String& a, unsigned int b) {
    String prom(a);
    prom *= b;
    return prom;
}

bool String::operator==(const String& rhs) const {
    size_t n1 = std::strlen(Data);
    size_t n2 = std::strlen(rhs.Data);
    if (n1 != n2) {
        return 0;
    } else {
        for (size_t i = 0; i < n1; i++) {
            if (Data[i] != rhs.Data[i]) {
                return 0;
            }
        }
    }
    return 1;
}

bool String::operator<(const String& rhs) const {
    size_t n1 = std::strlen(Data);
    size_t n2 = std::strlen(rhs.Data);
    if (n1 > n2) {
        n1 = n2;
    }
    for (size_t i = 0; i < n1; i++) {
        if (Data[i] > rhs.Data[i]) {
            return 0;
        }
    }
    return 1;
}

bool operator!=(const String& a, const String& b){
    return a == b ? 0 : 1;
}

bool operator==(const char* data, const String& rhs) {
    size_t n1 = std::strlen(data);
    size_t n2 = rhs.Size();
    if (n1 != n2) {
      return 0;
    } else {
        for (size_t i = 0; i < n1; i++){
            if (data[i] != rhs[i]) {
                return 0;
            }
        }
    }
    return 1;
}

bool operator>(const String& a, const String& b){
    return b < a ? 0 : 1;
}

size_t String::Find(const String& substr) const {
    size_t n1 = std::strlen(Data);
    size_t n2 = std::strlen(substr.Data);
    if (n1 < n2) {
        return static_cast<size_t>(-1);
    }
    size_t k = 0;
    for (size_t i = 0; i < n1 - n2; i++) {
        for (size_t j = 0; j < n2; j++) {
            if (Data[i + j] == (substr.Data[j])) k++;
        }
        if (k == n2) {
            return i;
        } else {
            k = 0;
        }
    }
    return static_cast<size_t>(-1);
}

void String::Replace(char oldSymbol, char newSymbol) {
    size_t n1 = std::strlen(Data);
    for (size_t i = 0; i < n1; i++) {
        if (Data[i] == oldSymbol) {
            Data[i] = newSymbol;
        }
    }
}

size_t String::Size() const {
    return std::strlen(Data);
}

bool String::Empty() const {
    return (std::strlen(Data) != 0) ? 0 : 1;
}

void String::RTrim(char symbol) {
    size_t n1 = std::strlen(Data);
    n1--;
    while (Data[n1] == symbol) {
        n1--;
    }
    n1++;
    auto mem = new char[n1 + 1]();
    for (size_t i = 0; i < n1; i++) {
        mem[i] = Data[i];
    }
    mem[n1] = '\0';
    delete[] Data;
    Data = new char[n1 + 1];
    for (size_t i = 0; i < n1; i++) {
        Data[i] = mem[i];
    }
    Data[n1] = '\0';
    delete[] mem;
}

void String::LTrim(char symbol) {
    size_t n1 = std::strlen(Data);
    size_t k = 0;
    while (Data[k] == symbol) {
        k++;
    }
    auto mem = new char[n1 - k + 1]();
    for (size_t i = k; i < n1; i++) {
        mem[i - k] = Data[i];
    }
    mem[n1 - k] = '\0';
    delete[] Data;
    Data = new char[n1 - k + 1];
    for (size_t i = 0; i < n1 - k; i++) {
        Data[i] = mem[i];
    }
    Data[n1 - k] = '\0';
    delete[] mem;
}

void String::swap(String& oth) {
    auto p = *this;
    *this = oth;
    oth = p;
}

char String::operator[](size_t index) const {
    return Data[index];
}

char& String::operator[](size_t index) {
    return Data[index];
}

std::ostream& operator<<(std::ostream& out, const String& str){
    out << str.Data;
    return out;
}
