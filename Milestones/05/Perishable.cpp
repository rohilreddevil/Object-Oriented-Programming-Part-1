#include "Product.h"  
#include"Perishable.h"
#include"Date.h"
#include"iProduct.h"


#include <string>
#include <fstream>
#include <iomanip>
#include <cstring>
#include<iostream>
#include<cstdio>

using namespace std;
namespace AMA {
	
	Perishable::Perishable(){
		ErrorState err; 
		Product::Product('P');
		//now set the current object to safe empty state
		this->isClear();
		//err.clear();
	}

	std::fstream& Perishable::store(std::fstream& file, bool newLine = true) const {
	
		Product::store(file, false);
		file << "," << expiry_date << std::endl;
		return file;

		/*Product::store(file, false) << "," << expiry_date;
		//file << "," << expiry_date << std::endl; //inserting a comma and appending the date to the end of the file
		if (newLine) {
			file << "\n";
		}
		return file;*/
	}

	std::fstream& Perishable::load(std::fstream& file) {
		Product::load(file);
		expiry_date.read(file);
		file >> expiry_date; //read expiry date from the file
		//std::istream& ist;
		//ist.get(file);
		file.get();
		return file;
	}

	std::ostream& Perishable::write(std::ostream& os, bool linear) const {
		Product::write(os, linear);
		if (isEmpty()) {// if the current object is in a safe empty state
			return os;
		}
		if (linear) {//if true
			expiry_date.write(os);
		}
		else {
			os << "\n" << " Expiry date: ";
			expiry_date.write(os);
		}
		return os;
	}

	std::istream& Perishable::read(std::istream& is) {
		Product::read(is);
		if (is.fail()) { //if extraction is failed
			return is;
		}
		std::cout << "Expiry date (YYYY/MM/DD): " << expiry_date;
		is >> expiry_date;
		if (expiry_date.bad()) { //bad (default ios function) means the data is corrupted
			if (expiry_date.errCode() == CIN_FAILED) {
				message("Invalid Date Entry");
			}
			if (expiry_date.errCode() == YEAR_ERROR) {
				message("Inavlid Year in Date Entry");
			}
			if (expiry_date.errCode() == MON_ERROR) {
				message("Invalid Month in Date Entry");
			}
			if (expiry_date.errCode() == DAY_ERROR) {
				message("Invalid Day in Date Entry");
			}
			if (expiry_date.errCode()) {//if in an error state, set it to a failed state using the failbit function
				is.setstate(std::ios::failbit);
			}
			else {
				ErrorState err;
				err.clear();
			}
		}
		
		return is;
	}
	const Date& Perishable::expiry() const {
		return expiry_date;
	}
}