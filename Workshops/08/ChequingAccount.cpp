// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file implements the ChequingAccount class
///////////////////////////////////////////////////
#include <iostream>
#include "ChequingAccount.h"

using namespace std;

namespace sict {
	// constructor initializes balance and transaction fee
	ChequingAccount::ChequingAccount(double BAL, double TRANSACTION, double MONTHEND) : Account(BAL) {

		if (TRANSACTION > 0) {
			transaction_fee = TRANSACTION;
		}
		else {
			transaction_fee = 0.0;
		}
		if (MONTHEND > 0) {
			month_end_fee = MONTHEND;
		}
		else {
			month_end_fee = 0.0;
		}
	
	}



	// credit (add) an amount to the account balance and charge fee
	// returns bool indicating whether money was credited
	bool ChequingAccount::credit(double BAL) {
		//Account::credit(BAL);
		//return true;
		bool flag = Account::credit(BAL);
		if (flag) {
			Account::debit(transaction_fee);
		}
		return true;
	}


	// debit (subtract) an amount from the account balance and charge fee
	// returns bool indicating whether money was debited
	bool ChequingAccount::debit(double BAL) {
		bool flag = Account::debit(BAL);
		if (flag) {
			Account::debit(transaction_fee);
		}
		return true;
	}

	// monthEnd debits month end fee
	void ChequingAccount::monthEnd() {
		Account::debit(month_end_fee +transaction_fee);
	}



	// display inserts account information into ostream os
	//
	void ChequingAccount::display(std::ostream& os) const {
		os << "Account type: Chequing" << std::endl;
		os.unsetf(std::ios::floatfield);
		os.precision(2);
		os.setf(std::ios::fixed, std::ios::floatfield);
		os << "Balance: $" << balance() << std::endl;
		os << "Per Transaction Fee: " << transaction_fee << std::endl;
		os << "Monthly Fee: " << month_end_fee << std::endl;

	}



}