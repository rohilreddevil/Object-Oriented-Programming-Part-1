


#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>

#include"ErrorState.h"

namespace AMA {

	ErrorState::ErrorState(const char *errorMessage){
		MESSAGE= nullptr;
		message(errorMessage); //call the message function and pass the pointer
	}
	ErrorState::~ErrorState() {
	       /* if(this != 0){
		delete[] this;
		}*/
	       clear();
	}
	void ErrorState::clear() { //deallocates the memory, hence clearing the message
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

		// return message_ == nullptr;
       
	void ErrorState::message(const char *str) {
		if (str == nullptr) {
			return;
		}
		clear();
		const int sizelength = strlen(str);
		if (sizelength != 0) {
			MESSAGE = new char[sizelength+1];
			strncpy(MESSAGE, str, sizelength+1);
		}
	}
	const char *ErrorState::message() const {
		return MESSAGE;
	}
	std::ostream &operator<<(std::ostream &os, const ErrorState &er) {
		if (er.isClear()) {
			return os;
		}
		return os << er.message();
	}

}  
