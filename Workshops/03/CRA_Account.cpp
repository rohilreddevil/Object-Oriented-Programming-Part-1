//Name- Rohil Khakhar
//Date- 08/02/18
//OOP244 Workshop3

#include<iostream>
#include<cstring>
#include<iomanip>
#include"CRA_Account.h"
using namespace std;


namespace sict {

	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {

		if (sin >= min_sin && sin <= max_sin && strcmp(familyName, "") != 0 && strcmp(givenName, "") != 0) {
			int final = 0;
			int temp1 = sin; // assigning the parameter to a temporary value since it needs to be split
			do {
				final += temp1 % 10;
				temp1 = temp1 / 10;
			} while (temp1 > 10);
			if (final % 10 == 0) { //remainder of the sum is 0
				strncpy_s(family_name, familyName, max_name_length); //copying a set number of characters from the function parameter varibale to the original class data member
				strncpy_s(given_name, givenName, max_name_length);
				SIN = sin;
			}
		}
		else {
			SIN = 0;
		}



	}
		
		
		
		/*int num9 = sin % 10;
		int num8 = sin / 10 % 10;
		int num7 = sin / 100 % 10;
		int num6 = sin / 1000 % 10;
		int num5 = sin / 10000 % 10;
		int num4 = sin / 100000 % 10;
		int num3 = sin / 1000000 % 10;
		int num2 = sin / 10000000 % 10;
		int num1 = sin / 100000000 % 10;
		int value = 0;
		int sum1 = num2 + num2; // adding the digits to itself
		int sum2 = num4 + num4;
		int sum3 = num6 + num6;
		int sum4 = num8 + num8;

		//splitting the digits
		int tempB = sum1 % 10; 
		int tempA = sum1 / 10 % 10;

		int tempD = sum3 % 10;
		int tempC = sum3 / 10 % 10;

		int tempF = sum4 % 10;
		int tempE = sum4 / 10 % 10;

		int temp_sin = tempA + tempB + tempC + sum2 + tempD + tempE + tempF;
		int temp_num = num1 + num3 + num5 + num7;
		int total = temp_sin + temp_num;


		if (total % 10) {
			value = total + (10 - total % 10);
		}

		int difference = value - total;

		if (difference == num7) {


		
			if (sin >= min_sin&&sin <= max_sin) // will only return the names if the SIN is valid, or else nothing
			{
				    strncpy_s(family_name, familyName, max_name_length); //copying a set number of characters from the function parameter varibale to the original class data member
					family_name[max_name_length] = '\0';
					strncpy_s(given_name, givenName, max_name_length);
					given_name[max_name_length] = '\0';
					SIN = sin; // assigning the value of the parameter variable to the original data 
				
			}
		
			else
			{
				SIN = 0;
				given_name[0] = '\0';
				family_name[0] = '\0';
			}

		}*/

	

	void CRA_Account::set(int year, double bal) {


		int i = 0;
		int counter = 0;
		if (SIN >= min_sin && SIN <= max_sin) {
			for (i = 0; i < max_yrs; i++) {
				if (tax_rtn[i] == 0)
				{
					counter = i;
					break;
				}
			}
			//this->balance[i] = bal;
			tax_rtn[counter] = year;
			balance[counter] = bal;
			//check the first index. if empty, move on		

		}
	}


	bool CRA_Account::isEmpty() const {
		
		bool outcome = false;
		if (SIN != 0 && family_name[0]!= '\0' && given_name[0] !='\0' ) {
			outcome = false;
	}
		else
		{
			outcome = true; // returns true is the SIN number does not fall in the stated condition
		}
		return outcome; 

	}

	void CRA_Account::display() const {
		if (isEmpty() == 0) {
			//if (SIN != 0) // if the object SIN is valid and not empty (not equal to zero)
			{
				cout << "Family Name:" << family_name << endl;
				cout << "Given Name:" << given_name << endl;
				cout << "CRA Account:" << SIN << endl;

			}
			for (int i = 0; i < max_yrs; i++) {
				if (balance[i] > 2) {
					cout << "Year " << "(" << tax_rtn[i] << ")" << " balance owing:" << setprecision(2)<<fixed <<balance[i] << endl;
				}
			
				else if (balance[i]<0)
				{
					cout << "Year " << "(" << tax_rtn[i] << ")" << " refund due" << setprecision(2)<< fixed<< (-1)*balance[i] << endl;
				}
			
				else
				{
					cout << "Year " << "(" << tax_rtn[i] << ")" << " No balance owing or refund due" << endl;
				}
			
			}
		
	}
		else // if empty (SIN==0)
		{
			cout << "Account object is empty!" << endl;
		}
	
	}
}





