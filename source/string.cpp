// Copyright 2018 Fedorov G <your_email>
// Copyright 2018 Fedorov G <your_email>

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <utility>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <cstddef>
#include "./../include/string.hpp"
using namespace std;
int strLen(char *str)
{
	int count = 0;
	int i = 0;
	while (str[i] != '\0')
	{
		count++;
		i++;
	}
	return count;
}
void strCpy(char *str, char *dest)
{
	int i = 0;
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
}
char* strConct(char *str1, char *str2, char *newStr)
{
	//int i = 0;
	int len1 = strLen(str1);
	int len2 = strLen(str2);
	//int n = 0;
	int superCount = len1 + len2 + 1;
	strCpy(str1, newStr);
	/*for (int i = 0; i <= len1; i++)
	{
	newStr[i] = str1[i];
	}*/
	strCpy(str2, newStr + len1);
	/*for (int i = len1; i <= (superCount - 2); i++)
	{
	newStr[i] = str2[n];
	n++;
	}*/
	newStr[superCount - 1] = '\0';
	return newStr;
}
String::~String()
{
	delete[] m_Data;
}
/// ����������� �� ���������
String::String()
{
	m_Data = new char[1];
	m_Data[0] = '\0';
}
/// ����������� �����������
/// <param name="rhs">������, ������� �������� </param>
String::String(const String& rhs)
{
	int len = strLen(rhs.m_Data);
	m_Data = new char[len + 1];
	strCpy(rhs.m_Data, m_Data);
	m_Data[len] = 0;
}
/// ���������������� �����������
/// <param name="data">������, ������� ��������� ��������� � �����������
/// ������ </param>
String::String(const char* data)
{
	int len = strLen(const_cast<char*>(data));
	m_Data = new char[len + 1];        strCpy(const_cast<char*>(data), m_Data);
	m_Data[len] = 0;
}
/// �������� ������������
/// <param name="data">������, ������� �������� </param>
/// <returns>���������� ������ �� ����</returns>
String& String::operator=(const String& rhs)
{
	int len = rhs.Size();
	m_Data = new char[len + 1];
	m_Data[len] = 0;
	strCpy(rhs.m_Data, m_Data);
	return *this;
}
/// �������� +=
/// <param name="rhs">������, ������� ����� ����� ����� '+=' </param>
/// <returns>���������� ������ �� ����</returns>
String& String::operator+=(const String& rhs)
{
	char* newMData = new char[this->Size() + rhs.Size() + 1];
	strCpy(m_Data, newMData);
	strCpy(rhs.m_Data, newMData + this->Size());
	delete[] m_Data;
	m_Data = newMData;
	return *this;
}
String& String::operator+=(const char* s)
{
	int size = strLen(const_cast<char*>(s));
	char* newMData = new char[this->Size() + size + 1];
	strCpy(m_Data, newMData);        strCpy(const_cast<char*>(s), newMData + this->Size());
	delete[] m_Data;
	m_Data = newMData;
	return *this;
}
/// �������� *=
/// <returns>���������� ������ �� ����</returns>
String& String::operator*=(unsigned int m)
{
	int a = this->Size();
	int b = (this->Size())*(m + 1);
	char* newMData = new char[b + 1];
	for (int i = 0; i < b; i = i + a)
	{
		for (int j = 0; j < a; j++)
		{
			newMData[i + j] = m_Data[j];
		}
	}
	newMData[b] = 0;
	delete[] m_Data;
	m_Data = newMData;
	return *this;
}
/// �������� ==
/// <param name="rhs">������, ������� ����� ����� ����� '==' </param>
/// <returns>���������� �������� ��������� ���� �����</returns>
bool String::operator==(const String& rhs) const
{
	int a = this->Size();
	int flag = 1;
	for (int i = 0; i < a; i++)
	{
		if (m_Data[i] != rhs.m_Data[i])
		{
			flag = 0;
		}
		if (flag == 0)
		{
			return false;
		}
	}
	return true;
}
/// �������� &lt;
/// <param name="rhs">������, ������� ����� ����� ����� "&lt;" </param>
/// <returns>���������� �������� ��������� ���� �����</returns>
bool String::operator<(const String& rhs) const
{
	int minLen = (rhs.Size() < this->Size()) ? rhs.Size() : this->Size();
	for (int i = 0; i < minLen; i++)
	{
		if (m_Data[i] < rhs.m_Data[i])
		{
			return true;
		}
	}
	return this->Size() < rhs.Size();
}
/// ������� ������ ���������
/// <param name="substr">���������, ������� ���������� ����� </param>
/// <returns>���������� ������� substr. ���� ��������� �� �������, ��
/// ���������� -1</returns>
size_t String::Find(const String& substr) const
{
	int a = substr.Size();
	int b = this->Size();
	for (int i = 0; i < b; i++)
	{
		if (substr.m_Data[0] == m_Data[i])
		{
			int j = 0;
			for (; j < a; j++)
			{
				if (substr.m_Data[j] != m_Data[i + j])
				{
					break;
				}
			}
			if (j == a)
			{
				return i;
			}
		}
	}
	return -1;
}
/// ������� ������ ��������, �������� ��� ������� oldSymbol �� newSymbol.
/// <param name="oldSymbol">������, ������� ��������� �������� </param>
/// <param name="newSymbol">������, �� ������� ��������� �������� </param>
void String::Replace(char oldSymbol, char newSymbol)
{
	int size = this->Size();
	for (int i = 0; i < size; i++)
	{
		if (m_Data[i] == oldSymbol)
		{
			m_Data[i] = newSymbol;
		}
	}
}
/// ������� ���������� ����� ������
/// <returns>���������� ����� ������</returns>
size_t String::Size() const
{
	return strLen(m_Data);
}
/// ������� ��� ����������� ����� �� ������
bool String::Empty() const
{
	if (Size() == 0){
		return true;
	}
	else{
		return false;
	}
}
/// �������� []
/// <example>
/// <code>
/// String str = "some string";
/// char symbol = str[2]; // symbol == 'm'
/// </code>
/// </example>
/// <param name="index"> ������ ������� </param>
/// <returns> �������� ������� � ������ � �������� index</returns>
char String::operator[](size_t index) const
{
	return m_Data[index];
}
/// �������� []
/// <example>
/// <code>
/// String str = "some string";
/// str[0] = 'S'; // ������ ���������� str ����� "Some string"
/// </code>
/// </example>
/// <param name="index"> ������ ������� </param>
/// <returns> ������ �� ������ � ������ � �������� index</returns>
char& String::operator[](size_t index)
{
	return m_Data[index];
}
/// ������ ������
/// <example>
/// <code>
/// String str = "___some string___";
/// str.RTrim('_'); // ������ ���������� str ����� "___some string"
/// </code>
/// </example>
/// <param name="symbol"> �������� ��������, ������ �������� </param>
void String::RTrim(char symbol)
{
	int size = this->Size() - 1;
	for (int i = size; i > 0; i--)
	{
		//bool flag = true;
		if (m_Data[i] == symbol){
			m_Data[i] = '\0';
		}
		else{
			break;
		}
	}
}
void String::LTrim(char symbol)
{
	int n = 0;
	int size = this->Size();
	for (int i = 0; i < size; i++)
	{
		if (m_Data[i] == symbol){
			n++;
		}
		else{
			break;
		}
	}
	if (n != 0)
	{
		char* newMData = new char[size - n + 1];
		strCpy(m_Data + n, newMData);
		delete[] m_Data;
		m_Data = newMData;
	}
}
void String::swap(String& oth)
{
	int size1 = oth.Size();
	int size2 = this->Size();
	char* newMData = new char[size2>size1 ? size2 : size1 + 1];
	char* newMData = new char[size2 > size1 ? size2 : size1 + 1];
	strCpy(this->m_Data, newMData);
	strCpy(oth.m_Data, m_Data);
	strCpy(newMData, oth.m_Data);
	delete[] newMData;
}


/// �������� +
/// <example> 
/// <code> 
/// <example>
/// <code>
/// String a = "Hello";
/// String b = "World";
/// String c = a + b; // c ����� "HelloWorld"
/// </code>
/// </example>
/// <returns>���������� ������ ������ a + b</returns>
String operator + (const String& a, const String& b)
{
	int size1 = a.Size();
	int size2 = b.Size();
	char* newMData = new char[size1 + size2 + 1];
	for (int i = 0; i < (size1 + size2 + 1); i++)
	{
		if (i < size1){
			newMData[i] = a[i];
		}
		else{
			newMData[i] = b[i - size1];
		}
	}
	String result(newMData);
	delete[] newMData;
	return result;
}
/// �������� +
/// <example>
/// <code>
/// String a = "A";
/// String c = a * 5; // c ����� "AAAAA"
/// </code>
/// </example>
String operator*(const String& a, unsigned int b)
{
	int size1 = a.Size();
	int size2 = size1*b;
	char* newMData = new char[size2 + 1];
	int i = 0;
	for (; i < size2; i = i + size1)
	{
		for (int j = 0; j < size1; j++)
		{
			newMData[i + j] = a[j];
		}
	}
	newMData[i] = '\0';
	String result(newMData);
	delete[] newMData;
	return result;
}
/// �������� !=
bool operator!=(const String& a, const String& b)
{
	if (a == b){
		return false;
	}
	else{
		return true;
	}
}
/// �������� &gt;
bool operator>(const String& a, const String& b)
{
	int minLen = (b.Size() < a.Size()) ? b.Size() : a.Size();
	for (int i = 0; i < minLen; i++)
	{
		if (a[i] < b[i])
		{
			return true;
		}
	}
	return a.Size() < b.Size();
}
/// �������� ������
/// <param name="out">����� ���� ������� ������ </param>
/// <param name="str">������, ������� ������� </param>
/// <returns>���������� ������ �� �����</returns>
std::ostream& operator<<(std::ostream& out, const String& str)
{
	out << str.m_Data;
	return out;
}
bool operator==(const char*s, const String& d)
{
	if (String(s) != d){
		return false;
	}
	else{
		return true;
	}
}
