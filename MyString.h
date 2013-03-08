/* 
 * File:   MyString.h
 * Author: Daniela
 *
 * Created on March 6, 2013, 4:17 PM
 */

#ifndef MYSTRING_H
#define	MYSTRING_H

class MyString {
public:
    MyString();
    MyString(const MyString& orig);//constructor copy
    MyString(const char* _string);
    virtual ~MyString();
    

    MyString& operator=(const MyString& other); //assignment operator
    
    MyString& operator+(const char* str);
    MyString& operator+(const MyString& str);
    
    void operator+=(const MyString& other);
    void operator+=(const char* other);
    
    unsigned int size();
    char* getData();
    
private:
    char* _string;
    
    void release();
    void init(const char* string);
};

#endif	/* MYSTRING_H */

