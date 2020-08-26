
#ifndef SICT_SAVINGSACCOUNT_H__
#define SICT_SAVINGSACCOUNT_H__

#include "Account.h" //derived from the account class

namespace sict {
	class SavingsAccount: public Account{ //derived from the account class
		double interest;
	
	public:
			// TODO: constructor initializes balance and interest rate
		SavingsAccount(double BALANCE, double INTEREST);

			// TODO: perform month end transactions
		void monthEnd();

			// TODO: display inserts the account information into an ostream			
		void display(std::ostream&) const; 
	};
}
#endif
