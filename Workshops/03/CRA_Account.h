//Name- Rohil Khakhar
//Date- 08/02/18
//OOP244 Workshop3

#ifndef sict_CRA_Account_h
#define sict_CRA_Account_h

namespace sict {

	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	const int max_yrs = 4;
	
		class CRA_Account {
		char family_name[max_name_length];
		char given_name[max_name_length];
		int SIN;
		int tax_rtn[max_yrs];
		double balance[max_yrs];
		int years;

	
	public: 
		void set(const char* familyName, const char* givenName, int sin);
		bool isEmpty() const;
		void display() const; 
		void set(int, double);
	};
	


}

#endif // !sict_CRA_Account_h

