#include "SavingsAccount.h" 
//#include"Account.h" 
#include"ChequingAccount.h"
namespace sict {

	// define interest rate
	double interest_rate = 0.05;
	double transaction = 0.50;
	double monthly = 2.00;

	// TODO: Allocator function
	iAccount*CreateAccount(const char* TYPE, double BALANCE) {
		iAccount*p = nullptr; // a pointer with a static type of iAccount
		if (TYPE[0] == 'S') {
			p = new SavingsAccount(BALANCE, interest_rate); //dynamic type
		}
		if (TYPE[0] == 'C') {
			p = new ChequingAccount(BALANCE, transaction, monthly);
		}
		else
		{
			return nullptr;
		}


		return p; //the address of the dynamic type
	}








}
