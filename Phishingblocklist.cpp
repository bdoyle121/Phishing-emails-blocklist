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
    capacity *= 2;
    std::string* newEmails = new std::string[capacity];
    for(int i=0; i < size; i++){
        newEmails[i] = emails[i];
    }
    delete[] emails;
    emails = newEmails;
}

bool PhishingBlocklist::addEmail(const std::string& email){
    if(contains(email)){
        return false;
    }
    if(size == capacity){
        resize();
    }
    emails[size++] = email;
    return false;
}

bool PhishingBlocklist::removeEmail(const std::string& email){
    for(int i=0; i < size; i++){
        if(emails[i] == email){
            for(int j = i; j < size - 1; j++){
                // shift j to the left 
                emails[j] = emails[j + 1];
            }
            size--;
            return true;
        }
    }
    return false;
}

bool PhishingBlocklist::contains(const std::string& email)const{
    for(int i=0; i < size; i++){
        if(emails[i] == email) {
            return true;
        }
    }
    return false;
}

void PhishingBlocklist::printBlocklist() const{
    if(size == 0){
        std::cout << "List is empty" << endl;
        return;
    }
    for(int i = 0; i < size; i++){
        std::cout << emails[i] << std::endl;
    }
}
