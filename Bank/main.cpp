#include "Account.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define POUND 1
#define DOLLAR 2
#define EURO 3

void writeBinary(Account x) {
	ofstream myfile("bank.bin");
	if(myfile.is_open()) {
		myfile << x.currencyptr << '\n' << x.balanceptr;
		myfile.close();
	}
	else {
		cout << "Unable to open file";
	}
}

int beginProcess(Account account) {
	string mystr;
	int option;
	int * myptr = &option;
	cout << "\nWhat service do you require?\n";
	getline(cin, mystr);
	(stringstream)mystr >> *myptr;
	switch(*myptr) {
	case 1:
		account.checkBalance();
		beginProcess(account);
		break;
	case 2:
		account.deposit();
		beginProcess(account);
		break;
	case 3:
		account.withdraw();
		beginProcess(account);
		break;
	case 4:
		account.createAccount();
		beginProcess(account);
		break;
	case 5:
		account.deleteAccount();
		break;
	default:
		break;
	}
	return 0;
}

int main() {
	Account account(POUND, 200);
	account.setCurrency();

	cout << "Welcome.\n\n";
	beginProcess(account);

	system("PAUSE");
	return 0;
}