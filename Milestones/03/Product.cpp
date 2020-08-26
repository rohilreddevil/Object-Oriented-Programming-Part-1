#define _CRT_SECURE_NO_WARNINGS

#include"Product.h"

#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;

namespace AMA {


	void Product::name(const char* p_name) {
		const int SIZE = strlen(p_name);
	
		if (p_name == nullptr) {
			delete[SIZE] p_name;
		}
		
		if (SIZE != 0 && SIZE <=max_name_length) {
			PRODUCT_NAME = new char[SIZE];
			strncpy(PRODUCT_NAME, p_name, SIZE);
		}
	}

	const char* Product::name() const {
	
		if (PRODUCT_NAME[0] == '\0') {
			return nullptr;
		}
		
		return PRODUCT_NAME;
	}

	double Product::cost() const {
		double total = pRICE + tax;
		return total; 
	}

	void Product::message(const char* msg) {
		
		product_error.message(msg);
	}

	bool Product::isClear() const {
		ErrorState obj;
		bool flag = false;
		if (obj.isClear()) {
			flag = true;
		}
		return flag;
	}
	const char *Product::sku() const {
		return sKU;
	}
	const char *Product::unit() const {
		return Product_unit;
	}
	bool Product::taxed() const {
		return status;
	}
	double Product::price() const {
		return pRICE;
	}


	Product::Product(char TYPE) {
		type = TYPE;
		type = '\0';
		sKU[0] = '\0';
		Product_unit[0] = '\0';
		PRODUCT_NAME = nullptr;
		current_qty = 0;
		needed_qty =0;
		pRICE =0;
		status = true; //value is true if the product is taxable
		product_error.isClear(); //holds the errorstate of the product object
	}

	Product::Product(const char* SKU, const char*NAME, const char*UNIT, int ON_HAND = 0, bool STATUS = true, double PRICE = 0, int NEED = 0) {
		name(NAME);
		*this = Product();
	}

	Product::Product(const Product& pr) {
		type = pr.type;
		//sku[7] = pr.sku[7];
		current_qty = pr.current_qty;
		needed_qty = pr.needed_qty;
		pRICE = pr.pRICE;
		status = pr.status;
		strncpy(sKU, pr.sKU, 7);
		strncpy(Product_unit, pr.Product_unit, max_name_length);
		if (pr.PRODUCT_NAME != nullptr && pr.product_error.message()) {
			name(pr.PRODUCT_NAME);
			product_error.message(pr.product_error.message());
		}
	
		else {
			PRODUCT_NAME = nullptr;
		}
	}

	Product& Product::operator=(const Product& pr){
	
		if (this != &pr) { //self assignment check
			type = pr.type;
			current_qty = pr.current_qty;
			needed_qty = pr.needed_qty;
			pRICE = pr.pRICE;
			status = pr.status;
			strncpy(sKU, pr.sKU, 7);
			strncpy(Product_unit, pr.Product_unit, max_unit_length);
			delete[] PRODUCT_NAME; //dealloacate previously associated memory
			if (pr.PRODUCT_NAME != nullptr) {
				PRODUCT_NAME = new char[sizeof(pr.PRODUCT_NAME)];
				strncpy(PRODUCT_NAME, pr.PRODUCT_NAME, strlen(pr.PRODUCT_NAME));
			}
			else {
				PRODUCT_NAME = nullptr;
			}
		}
		return *this;
	}
	Product::~Product() {
		if (PRODUCT_NAME != nullptr) {
			delete[] PRODUCT_NAME;
		}
	}

	std::fstream& Product::store(std::fstream& file, bool newLine = true) const{

		file << type << std::endl;
		file << sKU << " , " << PRODUCT_NAME << " , " << pRICE << " , " << current_qty << " , " << Product_unit << " , " << needed_qty << endl;
		if (newLine) {
			file << "\n";
		}
		return file;
	}

	std::fstream& Product::load(std::fstream& file) {
		Product pr; // inititating a product object
		size_t field_count = 0;
		const char delimitor = ',';
		do {
			string field_tmp; //an empty string
			std::getline(file, field_tmp, delimitor);//getLine is a member function for an istream object which extract a line of character from the input buffer
			switch (field_count++) { //keep iterating until all fields are loaded
			case 0:
				pr.type = field_tmp[0];
				break;
			case 1:
				strncpy(pr.sKU, field_tmp.c_str(), sizeof(pr.sKU));
				break;
			case 2:
				strncpy(pr.Product_unit, field_tmp.c_str(), sizeof(pr.Product_unit));
				break;
			case 3:
				name(field_tmp.c_str());
				break;
			case 4:
				pr.current_qty = strtol(field_tmp.c_str(), NULL, 10);
				break;
			case 5:
				pr.needed_qty = strtol(field_tmp.c_str(), NULL, 10);
				break;
			case 6:
				pr.price = strtod(field_tmp.c_str(), NULL); //strtod converts a string to a double
				break;
			case 7:
				pr.status = strtol(field_tmp.c_str(), NULL, 10); //strlol converts string to a long int
				break;
			}
		} while (!file.eof());
		*this = pr;
		return file;
	}

	std::ostream&  Product:: write(std::ostream& os, bool linear) const {
	
		if (linear == true) {
			os << std::left << std::setfill(' ') << std::setw(max_sku_length);
			os << sku << std::setw(0) << std::right << "|";
			os << std::left << std::setw(20) << PRODUCT_NAME << std::setw(0) << std::right << "|";
			char cost_str[256] = { '\0' };
			sprintf(cost_str, "%.2lf", status==true ? pRICE * (1.0 + TAX) : pRICE);
			os << std::setw(7) << cost_str << std::setw(0) << "|";
			os << std::setw(4) << current_qty << std::setw(0) << "|";
			os << std::left << std::setw(max_unit_length) << Product_unit << std::setw(0) << std::right << "|";
			os << std::setw(4) << qtyNeeded << std::setw(0) << "|";
		}
		else {
			os << "Sku: " << sKU <<std::endl;
			os << "Name (no spaces): " << PRODUCT_NAME << std::endl; 
			os << "Price: " << pRICE << std::endl;
			if (status == true) {
				os << "Price after tax: " << total_cost() << std::endl;
			}
			else {
				os << "N/A: " << std::endl;
			}
			os << "Quantity on hand: " << current_qty << std::endl;
			os << "Quantity needed: " << needed_qty << std::endl;
		}

		return os;
	}

	std::istream& Product::read(std::istream& is) {
		int counter = 0;

		std::cout << " Sku: ";
		if (!is.fail()) { //if the string input is successfully written without any invalid input entered
			is >> sKU;
			counter++;
		}
		else {
			return is;
		}
		std::cout << " Name (no spaces): ";
		if (!is.fail()) {
			is >> PRODUCT_NAME;
			counter++;
		}
		else {
			return is;
		}
		std::cout << " Unit: ";
		if (!is.fail()) {
			is >> Product_unit;
			counter++;
		}
		else {
			return is;
		}
		std::cout << " Taxed? (y/n): ";
		char input;
		is >> input;
		if (input == 'y' || input == 'Y' || input == 'N' || input == 'n') {
			if (!is.fail()) {
				if (input == 'y' || input == 'Y') {
					status = true; //taxable is possible
				}
				else {
					status = false;
				}
				counter++;
			}
			else {//if the input fails
				is.setstate(std::ios::failbit); //calling istream::setstate(std::ios::failbit)
				message("Only (Y)es or (N)o are acceptable"); //pass the message to the message function
			}
		}
		else {

			return is;
		}
		std::cout << " Price: ";
		if (!is.fail()) {
			double temp;
			is >> temp;
			if (temp > 0) {
				pRICE = temp;
				counter++;
			}
			else {
				message("Invalid Price Entry");
			}
		}
		else {

			return is;
		}
		std::cout << " Quantity on hand: ";
		if (!is.fail()) {
			int temp;// a new variable to store the quantity
			is >> temp;
			if (temp > 0) {
				current_qty = temp;
				counter++;
			}
			else {
				message("Invalid Quantity On Hand Entry");
			}
		}
		else {
			return is;
		}
	}

	bool Product::operator==(const char* str) const {
	
		if (strcmp(this->sKU, str) == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	double Product::total_cost() const {
		if (status == true) {
			double total = (current_qty*pRICE) + tax;
			return total;
		}
	}
	void Product::quantity(int Received) {
		//QTY describes the units of the Product that are on hand
		
		current_qty = Received;
		//int TOTAL = current_qty + needed_qty;
		
		//current_qty += QTY;
	}

	bool Product::isEmpty() const {
		bool flag = false;
		if (PRODUCT_NAME[0] == '\0') {
			flag = true;
		}
		else {
			flag = false;
		}
		return flag;
	}

	int Product::qtyNeeded() const {
		return needed_qty;
	}

	bool Product::operator>(const char* SKU) const {
		bool flag = false;;
		if (strlen(sKU) > strlen(SKU)) {
			flag = true;
		}
		else {
			flag = false;
		}
		return flag;		
	}

	bool Product::operator>(const Product& pr) const {
		bool flag = false;
		if (strlen(PRODUCT_NAME) > strlen(pr.PRODUCT_NAME)) {
			flag = true;
		}
		else {
			flag = false;
		}
		return flag;
	}

	int Product::operator+=(int ADD) {
		
		if (ADD > 0) {
			current_qty += ADD;
			return current_qty;
		}
		else if (ADD <= 0) {
			return current_qty;
		}
	}

	std::ostream& operator<<(std::ostream& os, const Product& pr) {
		pr.write(os, true); //successfully insert a product record into the stream
		return os;
	}
	
	std::istream& operator>>(std::istream& is, Product& pr) {
		return pr.read(is);
	}

	double operator+=(double& cst, const Product& pr) {
		cst += pr.total_cost();
		return cst;
	}
}