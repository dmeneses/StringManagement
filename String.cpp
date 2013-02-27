/* 
 * File:   String.cpp
 * Author: Daniela
 *
 * Created on February 16, 2013, 9:14 AM
 */
#include <iostream>

using namespace std;

int length(char* string) {
    int index = 0;
    while (string[index] != '\0') {
        index++;
    }
    return index;
}

char* concat(char *s1, const char *s2, int n) {
    int s1Index = length(s1);
    for (int i = 0; i < n; i++) {
        s1[s1Index] = s2[i];
        s1Index++;
    }

    return s1;
}

int compareTo(char* str1, char* str2) {
    int str1Size = length(str1);
    for (int i = 0; i < str1Size; i++) {
        if (str1[i] > str2[i]) {
            return 1;
        }
        if (str1[i] < str2[i]) {
            return -1;
        }
    }

    return 0;
}

void toLower(char* str) {
    int size = length(str);
    char temp;
    for (int i = 0; i < size; i++) {
        temp = str[i];
        if (temp > 64 && temp < 91) {
            temp += 32;
            str[i] = temp;
        }
    }
}

void toUpper(char* str) {
    int size = length(str);
    char temp;
    for (int i = 0; i < size; i++) {
        temp = str[i];
        if (temp >= 'a' && temp <= 'z') {
            temp -= 32;
            str[i] = temp;
        }
    }
}

void reverse(char* str) {
    int size = length(str) - 1;
    int index = 0;
    char temp;
    while (index < size) {
        temp = str[index];
        str[index] = str[size];
        str[size] = temp;
        size--;
        index++;
    }
}

bool palindrome(char* str) {
    int size = length(str) - 1;
    int index = 0;
    bool equal = true;
    while (index < size && equal) {
        if (str[index] != str[size]) {
            equal = false;
        }
        size--;
        index++;
    }

    return equal;
}

char* copy(char** destination, char* source) {
    int size = (length(source) + 1);
    *destination = (char*) malloc(size * sizeof (char));
    char* copy = *destination;
    while (*source) {
        *copy = *source;
        *source++;
        *copy++;
    }
    *copy = '\0';
    return *destination;
}

/**
 * @param[in] str  The original string
 * @param[out] upperCopy  The upper case version of str
 * @Return Return the amount of characters of str that were needed to move to upper case.
 */
int toUpperCopy(char* str, char** upperCopy) {
    int res = 0;
    int size = length(str);
    copy(upperCopy, str);
    toUpper(*upperCopy);
    int index = 0;
    char* aux = *upperCopy; //If I don't create this a have segment fault
    while (index < size) {
        if (str[index] != aux[index]) {//here if I use *upperCopy[index]
            res++;
        }
        index++;
    }

    return res;
}

char* find(char* str, char* toFind) {
    bool equal = false;
    while (*str && !equal) {
        if (*str == *toFind) {
            char* aux = str;
            char* toFindAux = toFind;
            equal = true;
            while (*toFindAux && *aux && equal) {
                if (*aux != *toFindAux) {
                    equal = false;
                }

                *toFindAux++;
                *aux++;
            }
        }

        if (!equal) {
            *str++;
        }
    }

    return str;
}

char* findReverse(char* str, char* toFind) {
    int strSize = length(str);
    char* newStr = str + strSize - 1;
    bool equal = false;
    while (strSize-- && !equal) {
        if (*newStr == *toFind) {
            char* auxStr = newStr;
            char* auxToFind = toFind;
            equal = true;
            int auxStrSize = strSize;
            while (*auxToFind && auxStrSize-- && equal) {
                if (*auxStr != *auxToFind) {
                    equal = false;
                }

                *auxToFind++;
                *auxStr--;
            }
            if (equal) {
                newStr = auxStr + 2;
            }
        }

        *newStr--;
    }

    return newStr;
}

int main() {
    const int BufferSize = 200;
    char str[] = " is a simple string";
    char buffer[BufferSize];
    buffer[0] = 'T';
    buffer[1] = 'h';
    buffer[2] = 'i';
    buffer[3] = 's';
    buffer[4] = '\n';

    char* res = concat(buffer, str, 200);
    printf("CONCAT: %s\n", res);

    char* compare1 = "hola";
    char* compare2 = "chau";
    int comparation = compareTo(compare1, compare2);
    printf("COMPARE between hola and chau : %d\n", comparation);

    char* lower = "HELlo";
    toLower(lower);
    printf("LOWER HELlo: %s\n", lower);
    toUpper(lower);
    printf("UPPER hello: %s\n", lower);

    reverse(lower);
    printf("REVERSE HELLO: %s\n", lower);

    char* palindrome1 = "oruro";
    char* palindrome2 = "gfhf";
    printf("PALINDROME oruro: %d\n", palindrome(palindrome1));
    printf("PALINDROME gfhf: %d\n", palindrome(palindrome2));

    char toCopy[] = "Sample string";
    char* strCopied = 0;

    copy(&strCopied, toCopy);

    printf("COPY\nToCopy: %s\nCopied: %s\n", toCopy, strCopied);
    toCopy[0] = 'a';
    printf("Modified toCopy: %s\nCopied: %s\n", toCopy, strCopied);

    char* strUpperCopy = 0;
    int modifiedChars = toUpperCopy(toCopy, &strUpperCopy);
    printf("UPPER COPY:\nToCopy: %s\nupper copied: %s\nmodified chars: %d\n", toCopy, strUpperCopy, modifiedChars);

    char* strFind = "Hola como estas";
    char* toFind = "omo";
    char* found = find(strFind, toFind);
    printf("Found: %s\n", found);

    char* strFindReverse = "Hola como estas";
    char* toFindReverse = "omo";
    char* found2 = findReverse(strFindReverse, toFindReverse);
    printf("Found: %s\n", found2);

    char* a = "Hola como estas";
    char* b = "u";
    char* c = find(a, b);
    printf("A: %s\n", a);
    printf("B: %s\n", b);
    printf("C: %s\n", c);


}


