// Final Project Milestone 1
//
// Version 1.0
// Date
// Author
// Description
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name  Rohil Khakhar             Date 15/03/18                Reason N/A
/////////////////////////////////////////////////////////////////
#ifndef AMA_DATE_H
#define AMA_DATE_H

#include<iostream>

#define NO_ERROR 0
#define CIN_FAILED 1
#define YEAR_ERROR 2
#define MON_ERROR 3
#define DAY_ERROR 4

namespace AMA {

	const int min_year = 2000;
	const int max_year = 2030;

  class Date {

	  int year;
	  int month;
	  int day;
	  int date_compare;
	  int error_state;
	  int mdays(int , int)const; //already done
	  void errCode(int errorCode);

  public:
	  Date();
	  Date(int, int, int);
	  bool operator==(const Date&rhs) const;
	  bool operator!=(const Date&rhs) const;
	  bool operator<(const Date&rhs) const;
	  bool operator>(const Date&rhs) const;
	  bool operator<=(const Date&rhs) const;
	  bool operator>=(const Date&rhs) const;
	  int errCode() const;
	  bool bad() const;
	  std::istream& read(std::istream& istr);
	  std::ostream& write(std::ostream& ostr)const;
	friend std::istream &operator>>(std::istream &, Date &rhs);
	  friend std::ostream &operator<<(std::ostream &, const Date &rhs);
  

};

 // std::istream &operator>>(std::istream& is, Date& rhs);
 // std::ostream &operator<<(std::ostream& os, Date& rhs);



}
#endif

