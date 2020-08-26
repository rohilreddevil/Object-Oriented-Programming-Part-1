#ifndef MS3_PRODUCT_H_
#define MS3_PRODUCT_H_

#include "ErrorState.h"  
#include"iProduct.h"
namespace AMA {

	static constexpr size_t max_sku_length = 7, max_unit_length = 10, max_name_length = 75;
	static constexpr double TAX= 0.13;

	class Product:public iProduct {
		char type;
		char sKU[max_sku_length + 1], Product_unit[max_unit_length + 1];
		char *PRODUCT_NAME;
		int current_qty; 
		int needed_qty;
		double PRICE;
		bool status;
		//ErrorState Product_error;
	protected:
		ErrorState Product_error;
		void name(const char *);
		const char *name() const;
		double cost() const;
		void message(const char *);
		bool isClear() const;
		const char *sku() const;
		const char *unit() const;
		bool taxed() const;
		double price() const;
		ErrorState &ERROR();
	public:
		Product(char = 'N');
		Product(const char * , const char * , const char * , int  = 0, bool = true, double = 0.00, int  = 0);
		Product(const Product &);
		~Product();
		Product &operator=(const Product &);
		std::istream &read(std::istream &is);
		bool operator==(const char *) const;
		std::fstream &store(std::fstream &, bool newline = true) const;
		std::fstream &load(std::fstream &file);
		double total_cost() const;
		void quantity(int);
		bool isEmpty() const;
		int qtyNeeded() const;
		int quantity() const;
		bool operator>(const char *) const;
		bool operator>(const iProduct &) const;//1
		int operator+=(int);
		std::ostream &write(std::ostream &os, bool linear) const;
	};

	

	std::ostream &operator<<(std::ostream &, const iProduct &);//4
	std::istream &operator>>(std::istream &, iProduct &);//3
	double operator+=(double &, const iProduct &);//2

}  
#endif  
