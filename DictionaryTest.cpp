/********************************************************************************* 
* Diwa Ashwini Vittala, dashwini
* 2022 Spring CSE101 PA8
* DictionaryTest.cpp
* DictionaryTest file: tests Dictionary ADT
**********************************************************************************/

#include<iostream>
#include<string>
#include<stdexcept>
#include <stdio.h>
#include <ctype.h>
#include "Dictionary.h"

using namespace std;

int main() {
    Dictionary A;
    A.setValue("a", 1);
    A.setValue("b", 2);
    A.setValue("c", 50);
    A.setValue("d", 40);
    A.setValue("e", 100);
    A.setValue("f", 20);

    cout << "Dictionary pre-order RBT:\n" << A.pre_string();
    cout << "\nDictionary in-order RBT:\n" << A;

    cout << "\nSo the size of this dictionary is: " << A.size();

    cout << "\nCheck: does key=a exist in the dictionary?\n";
    cout << " - " << (A.contains("a")?"true\n":"false\n");
    A.remove("a");
    cout << "Check: After removing key=a, does key=a exist in the dictionary?\n";
    cout << " - " << (A.contains("a")?"true\n":"false\n");
    cout << "And size is now : " << A.size() << "\n";

    A.begin();
    cout << "\nBegin at this key = " << A.currentKey() << ", value = " << A.currentVal() << "\n";
    A.next();
    cout << "Next is this key = " << A.currentKey() << ", value = " << A.currentVal() << "\n";
    A.end();
    cout << "End at this key = " << A.currentKey() << ", value = " << A.currentVal() << "\n";
    A.prev();
    cout << "Move back to this key = " << A.currentKey() << ", value = " << A.currentVal() << "\n";

    Dictionary cpy;
    cpy = A;
    cout << "\nThis is a copy of A: \n" << cpy << "\n";
    cout << "This is A: \n" << A << "\n";
    return 0;
}
