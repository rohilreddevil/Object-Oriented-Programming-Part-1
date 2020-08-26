#include"Account.h"
#include<iostream>
#include<cstdio>
#include<string>

namespace sict {
	
	Account::Account(double BALANCE) {
		if (BALANCE > 0) {
			current_balance = BALANCE;
		}
		else {
			current_balance = 0.0;
		}
	}

	bool Account::credit(double CREDIT_AMOUNT) {
		bool success =false;
		if (CREDIT_AMOUNT > 0) {
			success = true;
			current_balance += CREDIT_AMOUNT;
		}
		else {
			success = false;
		}
		return success;
	}

	bool Account::debit(double DEBIT_AMOUNT) {
		bool success = false;
		if (DEBIT_AMOUNT > 0) {
			success = true;
			current_balance =-DEBIT_AMOUNT;
		}
		else {
			success = false;
		}
		return success;
	}

	double Account::balance() const {
		return current_balance;
	}
}
