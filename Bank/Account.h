#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Account {
		char currency;
		string mystr, firstName, lastName;
		int accountNo, amount, balance, zone;
	public:
		char * currencyptr = &currency;
		string * mystrptr;
		int * myptr;
		int * balanceptr = &balance;
		Account(int area, int amount) : zone(area), balance(amount) {};

		void setCurrency() {
			switch(zone) {
				case 1: // Pound Sterling
					*currencyptr = 0x9C;
					break;
				case 2: // US Dollar
					*currencyptr = 0x24;
					break;
				case 3: // Euro
					*currencyptr = 0xEE;
					break;
				default:
					break;
			}
		}

		void createAccount() {
			cout << "\nPlease enter your first name: ";
			getline(cin, mystr);
			mystrptr = &firstName;
			(stringstream)mystr >> *mystrptr;
			cout << "\nPlease enter your last name: ";
			getline(cin, mystr);
			mystrptr = &lastName;
			(stringstream)mystr >> *mystrptr;

			cout << "\nYour account has been created successfully. Welcome " << firstName << " " << lastName << ".\n\n";
		}
		void deleteAccount() {}

		void checkBalance() {
			cout << "\nYour balance is: " << *currencyptr << *balanceptr << ".\n\n";
		}
		
		void deposit() {
			myptr = &amount;
			cout << "\nHow much would you like to deposit?\n";
			getline(cin, mystr);
			(stringstream)mystr >> *myptr;
			if(*myptr < 1) {
				cout << "\nUnable to carry out requested action. Returning to front end\n\n";
			}
			else {
				*balanceptr += *myptr;
				cout << '\n' << *currencyptr << *myptr << " has been successfully deposited.\nYour new balance is: " << *currencyptr << *balanceptr << '\n' << endl;
			}
		}

		void withdraw() {
			myptr = &amount;
			cout << "\nHow much would you like to withdraw?\n";
			getline(cin, mystr);
			(stringstream)mystr >> *myptr;
			if(*myptr > *balanceptr) {
				cout << "\nWithdraw unsuccessful. You have insufficient funds\n\n";
			}
			else if(*myptr < 1) {
				cout << "\nUnable to carry out requested action. Returning to front end\n\n";
			}
			else {
				*balanceptr -= *myptr;
				cout << '\n' << *currencyptr << *myptr << " has been successfully withdrawn.\nYour new balance is: " << *currencyptr << *balanceptr << '\n' << endl;
			}
		}
};

#endif