#include<iostream>
#include "SavingsAccount.h"
#include"Account.h"
#include<cstring>



namespace sict {

	SavingsAccount::SavingsAccount(double BALANCE, double INTEREST): Account(BALANCE){
		if (INTEREST > 0) {
			interest = INTEREST;
		}
		else {
			interest = 0.0;
		}
	}

	void SavingsAccount::monthEnd() {

		double iNTEREST = (balance()*interest); // callig the balance function will give the latest balance
		//call the credit function now
		credit(iNTEREST);
	}

	void SavingsAccount::display(std::ostream& os) const {
		os << "Account type: Savings" << std::endl;
		os.precision(2); // sets the decimal precision to 2 for the forthcoming output fields
		os.setf(std::ios::fixed, std::ios::floatfield);
		os << "Balance: $" << balance() << std::endl;
		os << "Interest Rate (%): " << interest * 100 << std::endl;


	}


}
