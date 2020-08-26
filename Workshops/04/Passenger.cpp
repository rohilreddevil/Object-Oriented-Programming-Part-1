// TODO: add file header comments here
//Name- Rohil Khakhar
//Date- 17/2/18
//Workshop4


// TODO: add your headers here
#include<iostream>
#include<cstring>
#include"Passenger.h"

using namespace std;


namespace sict {

	Passenger::Passenger() { // entire object set to empty state
		passenger_name[0] = '\0'; //or strcpy(passenger_name,"");
		destination[0] = '\0';	//or strcpy(destination_name,"");		
		departure_year = 0;
		departure_month = 0;
		departure_day = 0;



	}

	Passenger::Passenger(const char * passName, const char * dest) {
		if (passName == 0 || strcmp(passName, "") == 0 || dest == 0 || strcmp(dest, "") == 0)  //int *p_x
		{																					//p_x=&x
			//set the whole object to an empty state																				//p_x= 0- address of x  is null	

			passenger_name[0] = '\0'; //passName==0 - The address is null address since passName (pointer) = address of passName
			destination[0] = '\0';		// strcmp(passName,"") == 0- The string at that particular address is empty
			departure_year = 0;
			departure_month = 0;
			departure_day = 0;							//this compares the string at the address with an empty string. it is empty if the output is zero

		}
		else { 

			strncpy(passenger_name, passName,31);
			strncpy(destination, dest,31);
			departure_year = 2017;
			departure_month = 7;
			departure_day = 1;
		
		
		}
	}

	bool Passenger::isEmpty() const {
		bool flag;
		if (passenger_name[0] == '\0'&& destination[0] == '\0') //if in an empty state, return true since it is valid
		{
			flag = true;
		}

		else //if it is not in an empty state
		{
			flag = false;
		}

		return flag;

	}
	void Passenger::display() const {
		if (passenger_name[0] == '\0'&& destination[0] == '\0') {
			cout << "No passenger!" << endl;
		}

		else
		{
			if (departure_month <= 9) { // checking if the month is a 2 digit value
				cout << passenger_name << " - " << destination << " on " <<
					departure_year << "/0" << departure_month << "/" << departure_day << endl;
			}
			else {
				cout << passenger_name << " - " << destination << " on " <<
					departure_year << "/" << departure_month << "/" << departure_day << endl;
			}
		}
	}



	Passenger::Passenger(const char * passName, const char * dest, int dep_year, int dep_month, int dep_day) {
		if (passName == 0 || strcmp(passName, "") == 0 || dest == 0 || strcmp(dest, "") == 0) {
			passenger_name[0] = '\0';
			destination[0] = '\0';
		}
		else
		{
			strcpy(passenger_name, passName);
			strcpy(destination, dest);
		}

		if (dep_year <= 2020 && dep_year >= 2017) {
			departure_year = dep_year;
		}
		else {
			departure_year = 0;
		}
		if (dep_month <= 12 && dep_month >= 1) {
			departure_month = dep_month;
		}
		else {
			departure_month = 0;
		}
		if (dep_day <= 31 && dep_day >= 1) {
			departure_day = dep_day;
		}
		else {
			departure_day = 0;
		}
	}
	const char* Passenger::name() const {
		return passenger_name;
	}

	bool Passenger::canTravelWith(const Passenger&PG) const {
		bool result = false;
		bool match = (strcmp(PG.destination, destination) == 0) ? true : false;  
		//ternary operator used 
		// zero means stringcompare will not give any different outputs. 
		if (match && PG.departure_day == departure_day && PG.departure_month == departure_month && PG.departure_year == departure_year) {
			// if the match condition is met
			result = true;
		} //checking if the referenced passenger has the same travel details as the current Passenger object

		return result;
	
	}
}

// TODO: continue your namespace here

    // TODO: implement the default constructor here

	// TODO: implement the constructor with 2 parameters here

    // TODO: implement isEmpty query here

    // TODO: implement display query here

