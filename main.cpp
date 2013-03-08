/* 
 * File:   main.cpp
 * Author: Daniela
 *
 * Created on March 7, 2013, 2:34 PM
 */

#include <cstdlib>
#include "stdio.h"
#include "MyString.h"
using namespace std;



using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    MyString* s1 = new MyString("Hello");
    MyString* s2 = new MyString(" John");
    MyString s3 = *s1 + *s2;
    const char* s4 = " Paul";
    MyString s5 = *s1 + s4;
    printf("Hello+ John>%s\n", s3.getData());
    printf("Hello+ Paul>%s\n", s5.getData());
    printf("Hello>%s\n", s1->getData());
    printf(" John>%s\n", s2->getData());
    printf(" Paul>%s\n", s4);
    
    *s1 += *s2;
    printf("Hello+= John>%s\n", s1->getData());
    
    



    return 0;
}

