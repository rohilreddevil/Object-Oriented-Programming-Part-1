#ifndef AMA_PERISHABLE_H
#define AMA_PERISHABLE_H

#include<iostream>
#include<fstream>
#include"iProduct.h"
#include"Date.h"



namespace AMA {
	class Perishable : public Product {
	private:
		Date expiry_date; //holds the expiry date of the perishable object
	public:
		Perishable();//no argument constructor
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		const Date& expiry() const;

	};
}


#endif // !AMA_PERISHABLE_H
