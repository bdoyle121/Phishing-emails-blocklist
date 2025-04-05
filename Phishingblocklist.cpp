// Brian Doyle 
// March 31st 2025 
// This is the class file for the C++ program Phisingblocklist. This file will hold all the information about the class file. 

#include<iostream>
#include "Phishingblocklist.h"
using namespace std;

// Constructor will Initialize the capacity and allocate memory 
PhishingBlocklist::PhishingBlocklist(){
    capacity = 10;
    size = 0;
    emails = new string[capacity];
}
// Destructor Will free up memory when the function scope has passed
PhishingBlocklist::~PhishingBlocklist(){
    delete[] emails;
}

// This will double the size of the array and copy all the old emails into the new array with double the capacity 
void PhishingBlocklist::resize(){
    capacity *= 2;
    std::string* newEmails = new std::string[capacity];
    // This loop is responible for copying over the old emails to the new array 
    for(int i=0; i < size; i++){
        newEmails[i] = emails[i];
    }
    // This updats the pointer and delets the old array
    delete[] emails;
    emails = newEmails;
}

bool PhishingBlocklist::addEmail(const std::string& email){
    // This if statement checks for duplicates in the list
    if(contains(email)){
        return false;
    }
    // This statment will check the size of the array and resize if needed
    if(size == capacity){
        resize();
    }
    emails[size++] = email;
    return true;
}

bool PhishingBlocklist::removeEmail(const std::string& email){
    for(int i=0; i < size; i++){
        if(emails[i] == email){
            for(int j = i; j < size - 1; j++){
                // shift j to the left 
                emails[j] = emails[j + 1];
            }
            --size;
            return true;
        }
    }
    // if email is not found in the list it will return false
    return false;
}

// Checks if an email is in the list 
bool PhishingBlocklist::contains(const std::string& email)const{
    for(int i = 0; i < size; i++){
        if(emails[i] == email) {
            return true;
        }
    }
    return false;
}

// prints all emails in the current list
void PhishingBlocklist::printBlocklist() const{
    if(size == 0){
        std::cout << "List is empty" << endl;
        return;
    }
    for(int i = 0; i < size; i++){
        std::cout << emails[i] << std::endl;
    }
}
