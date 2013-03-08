/* 
 * File:   MyString.cpp
 * Author: Daniela
 * 
 * Created on March 6, 2013, 4:17 PM
 */

#include "MyString.h"
#include "StringFunctions.h"
#include <stdio.h>

MyString::MyString() {
    this->_string = 0;
}

MyString::MyString(const MyString& orig) {
    init(orig._string);
}

MyString::MyString(const char* string) {
    init(string);
}

MyString::~MyString() {
    release();
}

void MyString::release() {
    if (this->_string) {
        delete[] this->_string;
        this->_string = 0;
    }
}

void MyString::init(const char* string) {
    this->_string = new char[length(string) + 1];
    copy(this->_string, string);
}

MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        this->release();
        this->init(other._string);
    }
    return *this;
}

MyString& MyString::operator+(const char* str) {
    char* temp = new char[size() + length(str) + 1];
    copy(temp, this->_string);
    copy(temp, this->size(), str);
    MyString* res = new MyString(temp);
    delete[] temp;
    return *res;
}

MyString& MyString::operator+(const MyString& str) {
    return operator +(str._string);
}

void MyString::operator+=(const MyString& str) {
    operator +=(str._string);
}

void MyString::operator+=(const char* str) {
    char* temp = new char[size() + length(str) + 1];
    copy(temp, this->_string);
    copy(temp, this->size(), str);
    release();
    init(temp);
    delete[] temp;
}

unsigned int MyString::size() {
    int index = 0;
    while (this->_string[index] != '\0') {
        index++;
    }

    return index;
}

char* MyString::getData() {
    return this->_string;
}


