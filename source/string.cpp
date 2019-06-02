// Copyright 2018 Your Name <your_email>
//#ifndef INCLUDE_STRING_HPP_
//#define INCLUDE_STRING_HPP_
#include "../include/string.hpp"
bool operator==(const char* first, const String& second) {
	size_t a = second.Size();
	for (size_t i = 0; i < a; i++) {
		if (second[i] != first[i]) {
			return false;
		}
	}
	return true;
}
void String::strMyCpy(const char* str, char* dest) {
	size_t i = 0;
	while (str[i] != '\0') {
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
}
size_t String::strMyLen(const char* str) {
	size_t count = 0;
	size_t i = 0;
	while (str[i] != '\0') {
		count++;
		i++;
	}
	return count;
}
size_t String::strMyLen(char* str) {
	size_t count = 0;
	size_t i = 0;
	while (str[i] != '\0') {
		count++;
		i++;
	}
	return count;
}
String::~String() { delete[] Data; }
String::String() {
	Data = new char[1];
	Data[0] = '\0';
}
String::String(const String& rhs) {
	size_t len = strMyLen(rhs.Data);
	Data = new char[len + 1];
	strMyCpy(rhs.Data, Data);
	Data[len] = 0;
}
String::String(const char* data) {
	size_t len = strMyLen(data);
	Data = new char[len + 1];
	strMyCpy(data, Data);
}
String& String::operator=(const String& rhs) {
	size_t len = rhs.Size();
	delete[] Data;
	Data = new char[len + 1];
	Data[len] = 0;
	strMyCpy(rhs.Data, Data);
	return *this;
}
String& String::operator+=(const String& rhs) {
	char* result = new char[Size() + rhs.Size() + 1];
	std::memcpy(result, Data, Size());
	std::memcpy(result + Size(), rhs.Data, rhs.Size());
	result[Size() + rhs.Size()] = '\0';
	delete[] Data;

	const size_t lengh = std::strlen(result) + 1;
	Data = new char[lengh];
	memcpy(Data, result, lengh);
	delete[] result;

	return *this;
}
String& String::operator*=(size_t m) {
	{
		size_t x = this->Size();
		size_t y = (this->Size()) * m;
		char* newData = new char[y + 1];
		for (size_t i = 0; i < y; i = i + x) {
			for (size_t j = 0; j < x; j++) {
				newData[i + j] = Data[j];
			}
		}
		delete[] newData;
		return *this;
	}
}
bool String::operator==(const String& rhs) const {
	size_t a = this->Size();
	size_t flag = 1;
	for (size_t i = 0; i < a; i++) {
		if (Data[i] != rhs.Data[i]) {
			flag = 0;
		}
		if (flag == 0) {
			return false;
		}
	}
	return true;
}
bool String::operator<(const String& rhs) const {
	size_t minLen = (rhs.Size() < this->Size()) ? rhs.Size() : this->Size();
	for (size_t i = 0; i < minLen; i++) {
		if (Data[i] < rhs.Data[i]) {
			return true;
		}
	}
	return this->Size() < rhs.Size();
}
size_t String::Find(const String& substr) const {
	size_t a = substr.Size();
	size_t b = this->Size();
	for (size_t i = 0; i < b; i++) {
		if (substr.Data[0] == Data[i]) {
			size_t j = 0;
			for (; j < a; j++) {
				if (substr.Data[j] != Data[i + j]) {
					break;
				}
			}
			if (j == a) {
				return i;
			}
		}
	}
	return -1;
}
void String::Replace(char oldSymbol, char newSymbol) {
	size_t size = this->Size();
	for (size_t i = 0; i < size; i++) {
		if (Data[i] == oldSymbol) {
			Data[i] = newSymbol;
		}
	}
}
size_t String::Size() const { return strlen(Data); }
bool String::Empty() const {
	if (this->Size() == 0) {
		return 1;
	}
	else {
		return 0;
	}
}
char String::operator[](size_t index) const { return Data[index]; }
char& String::operator[](size_t index) { return Data[index]; }
void String::RTrim(char symbol) {
	size_t pos = Size() - 1;
	for (; pos > 0; pos--) {
		if (Data[pos] != symbol) {
			break;
		}
	}

	char* result = new char[pos + 1];
	memcpy(result, Data, pos + 1);

	delete[] Data;
	Data = new char[pos + 2];
	memcpy(Data, result, pos + 1);
	Data[pos + 1] = '\0';
	delete[] result;
}
void String::LTrim(char symbol) {
	size_t pos = 0;
	for (; pos < Size(); pos++) {
		if (Data[pos] != symbol) {
			break;
		}
	}

	const size_t lengh = Size() - pos;
	char* result = new char[lengh];
	memcpy(result, Data + pos, lengh);

	delete[] Data;
	Data = new char[lengh + 1];
	memcpy(Data, result, lengh);
	Data[lengh] = '\0';
	delete[] result;
}
void String::swap(String& oth) { std::swap(Data, oth.Data); }
String operator+(const String& a, const String& b) {
	String prom(a);
	prom += b;
	return prom;
}
String operator*(const String& a, size_t b) {
	String prom(a);
	prom *= b;
	return prom;
}
bool operator!=(const String& a, const String& b) {
	if (a.Size() != b.Size()) {
		return true;
	}
	else {
		return false;
	}
}
bool operator>(const String& a, const String& b) {
	if (a.Size() > b.Size()) {
		return true;
	}
	else {
		return false;
	}
}
std::ostream& operator<<(std::ostream& out, const String& str) {
	out << str.Data;
	return out;
}
