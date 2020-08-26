// TODO: add file header comments here
//Name- Rohil Khakhar
//Date- 17/2/18
//Workshop4

// TODO: add header file guard here
#ifndef sict_Passenger_h
#define sict_Passenger_h

// TODO: declare your namespace here
namespace sict {

	class Passenger { //sets the foundation for the passenger information

		char passenger_name[32]; //31 + null terminator
		char destination[32];	 //31 + null terminator
		int departure_year;
		int departure_month;
		int departure_day;

	public:
		Passenger(); //constructor1
		Passenger( const char * passName, const char * dest  ); //constructor2
		bool isEmpty() const;
		void display() const;
		Passenger(const char * passName, const char * dest, int dep_year, int dep_month, int dep_day);
		const char* name() const;
		bool canTravelWith(const Passenger&pass_enger)const;


	};



}
    // TODO: define the Passenger class here

#endif