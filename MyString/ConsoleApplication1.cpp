#include <stdio.h>
#include "stdafx.h"
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
#include <iostream>
#include "..\include\string.hpp"
using namespace std;

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

int main()
{
    setlocale(LC_ALL, "Russian");
    int a;
    //test22();
    cout << "Finished";
    cin >> a;
}