// Copyright 2018 Fedorov G <your_email>

#ifndef INCLUDE_STRING_HPP_
#define INCLUDE_STRING_HPP_

#include "..\include\stdafx.h"
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


using namespace std;

void error(char* strErr);
int strLen(char *str1);
void strCpy(char *str, char *dest);
char* strConct(char *str1, char *str2, char *newStr);


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
    int i = 0;
    int len1 = strLen(str1);
    int len2 = strLen(str2);
    int n = 0;

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

void test2()
{
    int a = 0;
    char* str = "bbb ccc";
    cout << strLen(str);
    cin >> a;
}

void test1()
{
    char* str1 = "abc d";
    char* str2 = "qqq r";
    int superCount = strLen(str1) + strLen(str2) + 1;
    char* newStr = new char[superCount];
    strConct(str1, str2, newStr);
    char* str3 = "abc dqqq r";
    for (int i = 0; i < superCount; i++)
    {
        if (newStr[i] != str3[i])
        {
            delete[] newStr;
            error("strConct не работает");
        }
    }
    cout << newStr << endl;
    delete[] newStr;

}

void error(char* strErr)
{
    int a;
    cout << strErr;
    cin >> a;
    exit(0);
}

class String {
public:
    /// Деструктор
    ~String()
    {
        delete[] m_Data;
    }

    /// Конструктор по умолчанию
    String()
    {
        m_Data = new char[1];
        m_Data[0] = '\0';
    }

    /// Конструктор копирования
    /// <param name="rhs">Объект, который копируем </param>
    String(const String& rhs)
    {
        int len = strLen(rhs.m_Data);
        m_Data = new char[len + 1];
        strCpy(rhs.m_Data, m_Data);
        m_Data[len] = 0;
    }

    /// Пользовательский конструктор
    /// <param name="data">Данные, которые требуется поместить в создаваемый
    /// объект </param>
    String(const char* data)
    {
        int len = strLen((char*)data);
        m_Data = new char[len + 1];
        strCpy((char*)data, m_Data);
        m_Data[len] = 0;
    }
    /// Оператор присваивания
    /// <param name="data">Объект, который копируем </param>
    /// <returns>Возвращаем ссылку на себя</returns>
    String& operator=(const String& rhs)
    {
        int len = rhs.Size();
        m_Data = new char[len + 1];
        m_Data[len] = 0;
        strCpy(rhs.m_Data, m_Data);
        return *this;
    }

    /// Оператор +=
    /// <param name="rhs">Объект, который стоит после знака '+=' </param>
    /// <returns>Возвращаем ссылку на себя</returns>
    String& operator+=(const String& rhs)
    {
        char* newMData = new char[this->Size() + rhs.Size() + 1];
        strCpy(m_Data, newMData);
        strCpy(rhs.m_Data, newMData + this->Size());
        delete[] m_Data;
        m_Data = newMData;
        return *this;
    }

    String& operator+=(const char* s)
    {
        int size = strLen((char*)s);
        char* newMData = new char[this->Size() + size + 1];
        strCpy(m_Data, newMData);
        strCpy((char*)s, newMData + this->Size());
        delete[] m_Data;
        m_Data = newMData;
        return *this;
    }

    /// Оператор *=
    /// <returns>Возвращаем ссылку на себя</returns>
    String& operator*=(unsigned int m)
    {
        int a = this->Size();
        int b = (this->Size())*m;
        char* newMData = new char[b + 1];
        for (int i = 0; i < b; i = i + a)
        {
            for (int j = 0; j < a; j++)
            {
                newMData[i + j] = m_Data[j];
            }
        }
        return *this;
    }

    /// Оператор ==
    /// <param name="rhs">Объект, который стоит после знака '==' </param>
    /// <returns>Возвращаем значения равенства двух строк</returns>
    bool operator==(const String& rhs) const
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

    /// Оператор &lt;
    /// <param name="rhs">Объект, который стоит после знака "&lt;" </param>
    /// <returns>Возвращаем значения сравнения двух строк</returns>
    bool operator<(const String& rhs) const
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

    /// Функция поиска подстроки
    /// <param name="substr">Подстрока, которую необходимо найти </param>
    /// <returns>Возвращаем позицию substr. Если подстрока не найдена, то
    /// возвратить -1</returns>
    size_t Find(const String& substr) const
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
    }

    /// Функция замены символов, заменяет все символы oldSymbol на newSymbol.
    /// <param name="oldSymbol">Символ, который требуется заменить </param>
    /// <param name="newSymbol">Символ, на который требуется заменить </param>
    void Replace(char oldSymbol, char newSymbol)
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

    /// Функция возвращает длину строки
    /// <returns>Возвращаем длину строки</returns>
    size_t Size() const
    {
        return strLen(m_Data);
    }

    /// Функция для определения пуста ли строка
    bool Empty() const
    {
        if (Size() == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    /// Оператор []
    /// <example>
    /// <code>
    /// String str = "some string";
    /// char symbol = str[2]; // symbol == 'm'
    /// </code>
    /// </example>
    /// <param name="index"> Индекс символа </param>
    /// <returns> Значение символа в строке с индексом index</returns>
    char operator[](size_t index) const
    {
        return m_Data[index];
    }

    /// Оператор []
    /// <example>
    /// <code>
    /// String str = "some string";
    /// str[0] = 'S'; // теперь переменная str равна "Some string"
    /// </code>
    /// </example>
    /// <param name="index"> Индекс символа </param>
    /// <returns> Ссылка на символ в строке с индексом index</returns>
    char& operator[](size_t index)
    {
        return m_Data[index];
    }

    /// Смотри пример
    /// <example>
    /// <code>
    /// String str = "___some string___";
    /// str.RTrim('_'); // теперь переменная str равна "___some string"
    /// </code>
    /// </example>
    /// <param name="symbol"> Значение символов, которе отрезаем </param>
    void RTrim(char symbol)
    {
        int size = this->Size() - 1;
        for (int i = size; i > 0; i--)
        {
            bool flag = true;
            if (m_Data[i] == symbol)
            {
                m_Data[i] = '\0';
            }
            else
            {
                break;
            }
        }
    }

    void swap(String& oth)
    {
        int size1 = oth.Size();
        int size2 = this->Size();
        char* newMData = new char[size2];
        strCpy(this->m_Data, newMData);
        strCpy(oth.m_Data, m_Data);
        strCpy(newMData, oth.m_Data);
    }

    friend ostream& operator<<(std::ostream& out, const String& str);

private:
    char* m_Data;
};

/// Оператор +
/// <example>
/// <code>
/// String a = "Hello";
/// String b = "World";
/// String c = a + b; // c равна "HelloWorld"
/// </code>
/// </example>
/// <returns>Возвращаем строку равную a + b</returns>
String operator+(const String& a, const String& b)
{
    int size1 = a.Size();
    int size2 = b.Size();
    char* newMData = new char[size1 + size2 + 1];
    for (int i = 0; i < (size1 + size2 + 1); i++)
    {
        if (i < size1)
        {
            newMData[i] = a[i];
        }
        else
        {
            newMData[i] = b[i];
        }
    }
    return newMData;
}
/// Оператор +
/// <example>
/// <code>
/// String a = "A";
/// String c = a * 5; // c равна "AAAAA"
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
            newMData[i] = a[j];
        }
    }
    newMData[i] = '\0';
    return newMData;
}

/// Оператор !=
bool operator!=(const String& a, const String& b)
{
    if (a == b)
    {
        return false;
    }
    else
    {
        return true;
    }
}

/// Оператор &gt;
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

/// Оператор вывода
/// <param name="out">Поток куда выводим строку </param>
/// <param name="str">Строка, которую выводим </param>
/// <returns>Возвращаем ссылку на поток</returns>
std::ostream& operator<<(std::ostream& out, const String& str)
{
    out << str.m_Data;
    return out;
}

bool operator==(const char*s, const String& d)
{
    if (s != d)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void test3()
{
    char* str = "Hello world";
    String a(str);
    int len = strLen(str);
    if (a.Size() == len)
    {
        cout << "Пользовательский конструктор работает" << endl;
    }
    else
    {
        error("Пользовательский конструктор не работет");
    }
    String b(a);
    if (b.Size() == len)
    {
        cout << "Конструктор копирования работает" << endl;
    }
    else
    {
        error("Конструктор копирования не работет");
    }
    String c;
    if (c.Size() == 0)
    {
        cout << "Конструктор по умолчанию работает" << endl;
    }
    else
    {
        cout << "Конструктор по умолчанию не работает" << endl;
    }
}

void test4()
{
    String a;
    char* str = "qrt";
    String b(str);
    a = b;
    if (a.Size() == b.Size())
    {
        cout << "Перегрузка оператора = работает" << endl;
    }
    else
    {
        error("Перегрузка оператора = не работает");
    }
}

void test5()
{
    char* str1 = "aaa bbb";
    char* str2 = "ccc ddd";
    String a(str1);
    String b(str2);
    a += b;
    if (a.Size() == 14)
    {
        cout << "Оператор += работает1" << endl;
    }
    else
    {
        error("Оператор += не работает");
    }
    // Написать оператор +=
}

void test6()
{
    char* str1 = "aaa";
    char* str2 = "bbb";
    char* str3 = "aaa";
    String a(str1);
    String b(str2);
    String c(str3);
    if ((!(a == b)) && a == c)
    {
        cout << "Оператор == работает";
    }
    else
    {
        error("Оператор == не работает");
    }
}

void test7()
{
    char* str1 = "aaa";
    char* str2 = "aab";
    String a(str1);
    String b(str2);
    if (a<b)
    {
        cout << "Оператор < работает" << endl;
    }
    else
    {
        error("Оператор < не работает");
    }
    a = "aa";
    b = "a";
    if (b < a)
    {
        cout << "Оператор < работает" << endl;
    }
    else
    {
        error("Оператор < не работает");
    }
}

void test8()
{
    char* str1 = "aaa";
    unsigned int m = 2;
    char* str2 = "aaaaaa";
    String a(str1);
    String b(str2);
    if ((a *= 2) == b)
    {
        cout << "Оператор *= работает" << endl;
    }
    else
    {
        error("Оператор *= не работает");
    }
}

void test9()
{
    char* str1 = "New technologies";
    char* str2 = "nologi";
    String a(str1);
    if (a.Find(str2) == 8)
    {
        cout << "Оператор Find работает" << endl;
    }
    else
    {
        error("Оператор Find не работает");
    }
}

void test10()
{
    char ch1 = 'a';
    char ch2 = 'b';
    String a("aaa");
    String b("bbb");
    a.Replace(ch1, ch2);
    if (a == b)
    {
        cout << "Функция замены работает" << endl;
    }
    else
    {
        error("Функция замены не работает");
    }
}

void test11()
{
    String a("\0");
    String b("aaa");
    if ((a.Empty() == true) && b.Empty() == false)
    {
        cout << "Функция по определению пуста ли строка - работает" << endl;
    }
    else
    {
        error("Функция по определению пуста ли строка не работает");
    }
}

void test12()
{
    String a("abc");
    int index = 2;
    if (a[index] == 'c')
    {
        cout << "Функция взятия элемента по индексу рабоатет" << endl;
    }
    else
    {
        error("Функция взятия элемента по индексу не работает");
    }
}

void test13()
{
    String s("hello");
    s[2] = 'a';
    if (s[2] == 'a')
    {
        cout << "Функция изменения элемента по индексу работает" << endl;
    }
    else
    {
        error("Функция изменения элемента по индексу не работает");
    }
}

void test14()
{
    String a("aaa");
    String b("bbb");
    a.swap(b);
    if ((a == "bbb") && (b == "aaa"))
    {
        cout << ("Перестановка работает");
    }
    else
    {
        error("Перестановка не работает");
    }
}

void test15()
{
    String a("___some string___");
    String b("___some string");
    a.RTrim('_');
    if (a == b)
    {
        cout << "Удаление символов с правого края работает" << endl;
    }
    else
    {
        error("Удаление символов с правого края не работает");
    }
}

void test16()
{
    String a("aaa");
    String b("bbb");
    if ((a + b) == "aaabbb")
    {
        cout << "Оператор + работает";
    }
    else
    {
        error("Оператор + не работает");
    }
}

void test17()
{
    String a("a");
    String b("aaa");
    if (a * 3 == b)
    {
        cout << ("Оператор * работает") << endl;
    }
    else
    {
        error("Оператор * не работает");
    }
}

void test18()
{
    String a("aaa");
    String b("bbb");
    if (a != b)
    {
        cout << ("Оператор != работает");
    }
    else
    {
        error("Оператор != не работает");
    }
}

void test19()
{
    String a("aaa");
    String b("b");
    if (a < b)
    {
        cout << ("Оператор < работает");
    }
    else
    {
        error("Оператор < не работает");
    }
}

void test20()
{
    cout << "Оператор << работает";
}

void test22()
{
    char* str1 = "aaa";
    String a("aaa");
    if (str1 == a)
    {
        cout << "== работает";
    }
    else
    {
        error("== не работает");
    }
}

void test21()
{
    String a("aaa");
    char* str2 = "ccc";
    a += str2;
    if (a.Size() == 6)
    {
        cout << "Оператор += работает1" << endl;
    }
    else
    {
        error("Оператор += не работает");
    }
    // Написать оператор +=
}

/*int main()
{
    setlocale(LC_ALL, "Russian");
    int a;
    test22();
    cout << "Finished";
    cin >> a;
}*/

#endif  // INCLUDE_STRING_HPP_
