// Brian Doyle 
// April 3rd 2025
// This is the Main file for the Phishing block list program.

#include<iostream>
#include<string>
#include "Phishingblocklist.h"
using namespace std;

int main() {
    PhishingBlocklist blocklist;

    // Test adding phishing emails
    cout << "Adding Emails:\n";
    cout << (blocklist.addEmail("phish1@malicious.com") ? "Added" : "Duplicate") << "\n";
    cout << (blocklist.addEmail("scam@fraud.net") ? "Added" : "Duplicate") << "\n";
    cout << (blocklist.addEmail("attack@phishers.org") ? "Added" : "Duplicate") << "\n";
    cout << (blocklist.addEmail("phish1@malicious.com") ? "Added" : "Duplicate") << " (duplicate test)\n";

    // Print current blocklist
    cout << "\nCurrent Phishing Blocklist:\n";
    blocklist.printBlocklist();

    // Test membership
    string searchEmail = "scam@fraud.net";
    cout << "\nSearching for " << searchEmail << ": "
         << (blocklist.contains(searchEmail) ? "Found" : "Not Found") << "\n";

    // Test removal
    cout << "\nRemoving 'attack@phishers.org'... "
         << (blocklist.removeEmail("attack@phishers.org") ? "Success" : "Not Found") << "\n";

    cout << "Removing 'unknown@phishers.org'... "
         << (blocklist.removeEmail("unknown@phishers.org") ? "Success" : "Not Found") << "\n";

    // Print final blocklist
    cout << "\nBlocklist after removals:\n";
    blocklist.printBlocklist();

    return 0;
}
