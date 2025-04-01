// Brian Doyle 
// March 31st 2025 
// This is the class file for the C++ program Phisingblocklist. This file will hold all the information about the class file. 

#include<iostream>
#include "Phishingblocklist.h"
using namespace std;

PhishingBlocklist::PhishingBlocklist(){
    capacity = 20;
    size = 0;
    emails = new string[capacity];
}

PhishingBlocklist::~PhishingBlocklist(){
    delete[] emails;
}

void PhishingBlocklist::resize(){
    capacity = 2;
    for(int i=0; i > capacity; i++){

    }
}


}