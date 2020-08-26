#include "Product.h"  

#include <string>
#include <fstream>
#include <iomanip>
#include <cstring>

namespace AMA {

       static constexpr char kFieldDelim = ',';

       Product::Product(char TYPE) : type(TYPE), sKU{ '\0' }, Product_unit{ '\0' }, PRODUCT_NAME{ '\0' }, current_qty(0), needed_qty(0), PRICE(0.00), status(false), Product_error() {}
	//data members set to a safe empty state
	

	Product::Product(const char* SKU, const char*NAME, const char*UNIT, int ON_HAND, bool STATUS, double pRICE, int NEED) : PRODUCT_NAME(nullptr), current_qty(ON_HAND), needed_qty(NEED), PRICE(pRICE), status(STATUS), Product_error(){
		name(NAME);
		if(SKU != nullptr){
		strncpy(sKU, SKU, sizeof(sKU));
		}
		if(UNIT != nullptr){
		strncpy(Product_unit, UNIT, sizeof(Product_unit));
		}
	}
	Product::Product(const Product &pr){
		PRODUCT_NAME ={'\0'};
		*this = pr;  //assigning the parameter to the current object
	}

	Product::~Product() {
		name(nullptr);
	}
	void Product::name(const char *p_name) {
		if (p_name == nullptr && PRODUCT_NAME != nullptr) {
			delete[] PRODUCT_NAME;
			PRODUCT_NAME = nullptr;
		}
		else if (p_name != nullptr) {
			if (PRODUCT_NAME != nullptr) {
				delete[] PRODUCT_NAME;
				PRODUCT_NAME= nullptr;
			}
			size_t size = strlen(p_name) + 1;
			PRODUCT_NAME = new char[size];
			strncpy(PRODUCT_NAME, p_name, size);
		}
	}
	const char *Product::name() const {
	      //  return name_ == nullptr || strlen(name_) == 0U ? nullptr : name_;
		if(PRODUCT_NAME[0] == '\0'){
			return nullptr;
		}
		return PRODUCT_NAME;
	}
	double Product::cost() const {
		double total = PRICE; //assigning a data member to a new variable
		if (status) {
			total*=0.13;
		}
		return total;
	}
	void Product::message(const char *msg) {
	       Product_error.message(msg);
	}
	bool Product::isClear() const {
		 return Product_error.isClear();
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
		return PRICE;
	}
	Product &Product::operator=(const Product &pr) {
	      //  if(this!= pr){ //checks for self assignment
		type = pr.type;
		strncpy(sKU, pr.sKU, sizeof(sKU));
		strncpy(Product_unit, pr.Product_unit, sizeof(Product_unit));
		name(pr.PRODUCT_NAME); //call the name function
		current_qty = pr.current_qty;
		needed_qty = pr.needed_qty;
		PRICE = pr.PRICE;
		status = pr.status;
		message(pr.Product_error.message()); //call the message function
		       
		return *this;
	}

	ErrorState &Product::ERROR() {
		return Product_error;
	}
      
	std::istream& Product::read(std::istream& is) {
	
	std::cout << " Sku: ";
		std::string value_tmp;
		std::getline(is, value_tmp);
		strncpy(sKU, value_tmp.c_str(), sizeof(sKU));

		std::cout << " Name (no spaces): ";
		std::getline(is, value_tmp);
		name(value_tmp.c_str());

		std::cout << " Unit: ";
		std::getline(is, value_tmp); //getline used to extract a bunch of character from a single line from the input buffer
		strncpy(Product_unit, value_tmp.c_str(), sizeof(Product_unit));

		std::cout << " Taxed? (y/n): ";
		std::getline(is, value_tmp);
		char value_ch = toupper(value_tmp[0]);   
		if (value_tmp.length() > 1 || (value_ch != 'Y' && value_ch != 'N')) {
			is.setstate(std::ios::failbit); // calling istream ::setstate(std::ios::failbit)
			message("Only (Y)es or (N)o are acceptable");
			return is;
		}
		status = value_ch != 'N'; //if taxable

		std::cout << " Price: ";
		std::getline(is, value_tmp);
		double value_d = strtod(value_tmp.c_str(), NULL);
		if (!value_d && !is.fail()) { //calling the fail member function whih is part of the istream class
			message("Invalid Price Entry");
			return is;
		}
		PRICE = value_d;

		std::cout << " Quantity on hand: ";
		std::getline(is, value_tmp);
		int value_i = strtol(value_tmp.c_str(), NULL, 10) ; //strlol converts string to long int
		if (!value_i && !is.fail()) {
			message("Invalid Quantity Entry");
			return is;
		}
		current_qty = value_i;

		std::cout << " Quantity needed: ";
		std::getline(is, value_tmp);
		value_i = strtol(value_tmp.c_str(), NULL, 10);
		if (!value_i && !is.fail()) {
			is.setstate(std::ios::failbit); // caal failbit again and pass the error message to message function
			message("Invalid Quantity Needed Entry");
			return is;
		}
		needed_qty = value_i;
		return is;       
		
	}
	      
			     

	bool Product::operator==(const char *str) const {
		return !strcmp(sKU, str); // this means that the two strings are not equal
	}
	std::fstream &Product::store(std::fstream &file, bool newline) const {
		file.put(type);
		file << "," << sKU << "," << Product_unit << "," << PRODUCT_NAME << "," << current_qty << "," << needed_qty << "," << PRICE << "," << status;
		if (newline) {
			file << "\n";
			//file << std::endl;
		}
		return file;
	}
	std::ostream &Product::write(std::ostream &os, bool linear) const {
		if (linear) {
			os << std::left << std::setfill(' ') << std::setw(max_sku_length); //input manipulators
			os << sKU << std::setw(0) << std::right << "|";
			os << std::left << std::setw(20) << PRODUCT_NAME << std::setw(0) << std::right << "|";
			char cost_str[256] = { '\0' };
			sprintf(cost_str, "%.2lf", status ? PRICE * (1.0 + 0.13) : PRICE);
			os << std::setw(7) << cost_str << std::setw(0) << "|";
			os << std::setw(4) << current_qty << std::setw(0) << "|";
			os << std::left << std::setw(max_unit_length) << Product_unit << std::setw(0) << std::right << "|";
			os << std::setw(4) << needed_qty << std::setw(0) << "|";
		}
		else {
			os << "Sku: " << sKU << std::endl;
			os << "Name (no spaces): " << PRODUCT_NAME << std::endl;
			os << "Price: " << PRICE << std::endl;
			if (status) {
				os << "Price after tax: " << total_cost() << std::endl;
			}
			else {
				os << "N/A" << std::endl;
			}
			os << "Quantity on hand: " << current_qty << std::endl;
			os << "Quantity needed: " << needed_qty << std::endl;
		}
		return os;
	}
	std::fstream &Product::load(std::fstream &file) {
		Product tmp;
		size_t field_count = 0;
		do {
			std::string field_tmp;
			std::getline(file, field_tmp, kFieldDelim);
			switch (field_count++) {
			case 0:
				tmp.type = field_tmp[0];
				break;
			case 1:
				strncpy(tmp.sKU, field_tmp.c_str(), sizeof(tmp.sKU));
				break;
			case 2:
				strncpy(tmp.Product_unit, field_tmp.c_str(), sizeof(tmp.Product_unit));
				break;
			case 3:
				name(field_tmp.c_str());
				break;
			case 4:
				tmp.current_qty = strtol(field_tmp.c_str(), NULL, 10); //converts string to a long int
				break;
			case 5:
				tmp.needed_qty = strtol(field_tmp.c_str(), NULL, 10);
				break;
			case 6:
				tmp.PRICE = strtod(field_tmp.c_str(), NULL);
				break;
			case 7:
				tmp.status = strtol(field_tmp.c_str(), NULL, 10);
				break;
			}
		} while (!file.eof());
		*this = tmp;
		return file;
	}
	double Product::total_cost() const {
		//double total;
		double total = PRICE * current_qty;
		if (status) {
			total *= 1 + 0.13;
		}
		return total;
	}
	void Product::quantity(int Received) {
		current_qty = Received;
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
	int Product::quantity() const {
		return current_qty;
	}
	bool Product::operator>(const char *SKU) const {
		return strcmp(sKU, SKU) > 0; //sKU is greater than SKU if strcmp is greater than 0
	}
	bool Product::operator>(const iProduct &pr) const {
		
		int check = strcmp(sKU, pr.name());
		if (check > 0) //sKU is bigger than the name
			return true;
		else
			return false;
	}
		
		//return *this > pr.sku();
	int Product::operator+=(int ADD) {
	     
	       if (ADD > 0) {
	       current_qty += ADD;
	       }        
     
		return current_qty;

	}
	
	std::ostream &operator<<(std::ostream &os, const iProduct &product) {
		return product.write(os, true);
	}
	std::istream &operator>>(std::istream &is, iProduct &product) {
		return product.read(is);
	}
	double operator+=(double &cst, const iProduct &product) {
	      return  cst += product.total_cost();
	       
	}

}  
     
