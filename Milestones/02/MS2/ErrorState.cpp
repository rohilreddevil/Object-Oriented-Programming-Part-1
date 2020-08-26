#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>

#include"ErrorState.h"


namespace AMA {

	ErrorState::ErrorState(const char*errorMessage){
		MESSAGE = nullptr;
		message(errorMessage); //call the message function and pass the pointer
	}
	//the copy constructor has been deleted
	//the copy assignment operator has been deleted
	ErrorState::~ErrorState() { //deallocator

		if (this!=0) {
			delete[] this; 
		}
		//call the clear function to clear out any message stored, hence, dealloacting its memory
		//clear(); 
	}
	void ErrorState::clear() { //dealloactes the memory, hence, clearing the message
		if (MESSAGE != nullptr) {
			delete[] MESSAGE;
			MESSAGE = nullptr;
		}

	}
	

	bool ErrorState::isClear() const {

		bool flag = false;
		if (MESSAGE==nullptr) {
			flag = true;
		}
		return flag;
	}

	void ErrorState::message(const char* str) {
		if (str == nullptr) {
			return;
		}
		clear();
		const int sizelength = strlen(str);
		if (sizelength != 0) {
			MESSAGE = new char[sizelength];
			strncpy(MESSAGE, str, sizelength);
		}
	}

	const char* ErrorState::message() const {

		return MESSAGE; //returning the address of the message
	}

	std::ostream& operator<<(std::ostream&os, const ErrorState&er) {

		if (er.isClear()) { //if message does not exist
			return os;
		}
		return os << er.message(); // if message exists, return the ErrorState message
	}
}