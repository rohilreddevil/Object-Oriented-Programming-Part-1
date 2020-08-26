
#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__

#include "iAccount.h"

namespace sict {
   
	class Account : public iAccount{
		double current_balance; //holds the current balance

	protected:
		double balance() const;

	public:
		// TODO: constructor initializes account balance, defaults to 0.0 
		Account(double BALANCE);

		// TODO: credit adds +ve amount to the balance 
		bool credit(double CREDIT_AMOUNT);

		// TODO: debit subtracts a +ve amount from the balance
		bool debit(double DEBIT_AMOUNT);
	};

	iAccount*CreateAccount(const char* TYPE, double BALANCE); //documentation
}
#endif
