#ifndef AMA_PRODUCT_H
//#define AMA_PRODUCT_H
//#define SKU 7
//#define DESC_PRODUCT 10
//#define LENGTH 75

#include"ErrorState.h"
#include<iostream>

namespace AMA {
	const int max_sku_length = 7;
	const int max_unit_length = 10;
	const int max_name_length = 75;
	const double TAX = 0.13;
	class Product{
		char type;
		char sKU[max_sku_length +1];
		char Product_unit[max_unit_length+1];
		char * PRODUCT_NAME;
		int current_qty;
		int needed_qty;
		double pRICE;
		bool status; //value is true if the product is taxable
		ErrorState product_error; //holds the errorstate of the product object
		int tax = TAX; //for convenience
	protected: //access only limited to derived class member functions
		void name(const char*);	//1
		const char* name() const;	//2	
		double cost() const;	//3
		void message(const char*);	//4
		bool isClear() const;	//5
		const char*sku () const; //new
		const char* unit() const; //new 
		bool taxed() const ; //new 
		double price() const; //new 
	public:
		Product( char TYPE = 'N');
		Product(const char *, const char *, const char *, int = 0, bool = true, double= 0.00, int =0);
		Product(const Product&);
		Product& operator=(const Product&);
		~Product();
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		bool operator==(const char*) const;
		double total_cost() const;
		void quantity(int);
		bool isEmpty() const;
		int qtyNeeded() const;
		int quantity() const;
		bool operator>(const char*) const;
		bool operator>(const Product&) const;
		int operator+=(int);
	};
	std::ostream& operator<<(std::ostream&, const Product&);
	std::istream& operator>>(std::istream&, Product&);
	double operator+=(double&, const Product&); 


}


#endif // !AMA_PRODUCT_H

