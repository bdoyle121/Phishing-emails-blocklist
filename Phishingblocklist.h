#ifndef PHISHINGBLOCKLIST_H
#define PHISHINGBLOCKLIST_H

#include<string> 

class PhishingBlocklist 
{
    private:
        std::string* emails;
        int size;
        int capacity;

        void resize();

    public:
        // Constructors and Deconstructors
        PhishingBlocklist();
        ~PhishingBlocklist();

        bool addEmail(const std::string& email);
        bool removeEmail(const std::string& email);
        bool contains(const std::string& email) const;
        void printBlocklist() const;
};

#endif