
//
//
// Revision History
// -----------------------------------------------------------
// Name Rohil Khakhar              Date 16/03/18                Reason N/A
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS

#include "Date.h"
#include <ctime>
#include <cstdio>
#include <cstring>


namespace AMA {

  
	int Date::mdays(int mon, int yr) const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month_tmp = mon >= 1 && mon <= 12 ? mon : 13; 
		month_tmp--;
		return days[month_tmp] + int((month_tmp == 1)*((yr % 4 == 0) && (yr % 100 != 0)) || (yr % 400 == 0));
	}
	void Date::errCode(int errorCode) {
		error_state = errorCode;
	}
	Date::Date(){
		
		year= 0;
		day=0;
		month=0;
		date_compare=0;
		errCode(NO_ERROR); 
	}
	Date::Date(int year_, int month_, int day_){
			error_state= NO_ERROR;

			if (year_ < min_year || year_ > max_year) {
			Date();
			errCode(YEAR_ERROR);
			return;
		}
		year = year_;
		if (month_ < 1 || month_ > 12) {
			Date();
			errCode(MON_ERROR);
			return;
		}
		month = month_;
		int days_in_month = mdays(month, year);
		if (day_ < 1 || day_ > days_in_month) {
			Date();
			errCode(DAY_ERROR);
			return;
		}
		day = day_;
		date_compare= year*372 + month*13+day;
	}
	bool Date::operator==(const Date &rhs) const {
		return date_compare == rhs.date_compare;
	}
	bool Date::operator!=(const Date &rhs) const {
		return !(*this == rhs);
	}
	bool Date::operator<(const Date &rhs) const {
		return date_compare < rhs.date_compare;
	}
	bool Date::operator>(const Date &rhs) const {
		return date_compare > rhs.date_compare;
	}
	bool Date::operator<=(const Date &rhs) const {
		return *this < rhs || *this == rhs;
	}
	bool Date::operator>=(const Date &rhs) const {
		return *this > rhs || *this == rhs;
	}
	int Date::errCode() const {
		return error_state;
	}
	bool Date::bad() const {
		bool flag;
		flag= (error_state != NO_ERROR);
		return flag;
	}
	std::istream &Date::read(std::istream &rhs) {
		char date_in[0004 + 1 + 02 + 1 + 02 + 1] = { '\0' };
		rhs >> date_in;
		int year_ = 0, month_ = 0, day_ = 0;
		
		if (rhs.fail() || (sscanf(date_in, "%4d/%2d/%2d", &year_, &month_, &day_) < 3 && sscanf(date_in, "%4d-%2d-%2d", &year_, &month_, &day_) < 3)) {
			errCode(CIN_FAILED);
			return rhs;
		}
		if (year_ < min_year || year_ > max_year) {
			errCode(YEAR_ERROR);
			return rhs;
		}
		year = year_;
		if (month_ < 1 || month_ > 12) {
			errCode(MON_ERROR);
			return rhs;
		}
		month = month_;
		int days_in_month = mdays(month, year);
		if (day_ < 1 || day_ > days_in_month) {
			errCode(DAY_ERROR);
			return rhs;
		}
		day = day_;
		date_compare= year* 372+month*13 +day;
		return rhs;
	}
	std::ostream &Date::write(std::ostream &rhs) const {
		tm date_tm = { 0 };
		
		date_tm.tm_year = std::max(year - 1900, 0);
		date_tm.tm_mon = std::max(month - 1, 0);
		date_tm.tm_mday = std::max(day, 1);
		char date_str[0004 + 1 + 02 + 1 + 02 + 1] = { '\0' };
		if (date_tm.tm_year == year - 1900 && date_tm.tm_mon == month - 1 && date_tm.tm_mday == day) {
			strftime(date_str, sizeof(date_str), "%Y/%m/%d", &date_tm);
		} else {
			
			strcpy(date_str, "0/00/00");
		}
		rhs << date_str;
		return rhs;
	}
	std::istream &operator>>(std::istream &lhs, Date &rhs) {
		return rhs.read(lhs);
	}
	std::ostream &operator<<(std::ostream &lhs, const Date &rhs) {
		return rhs.write(lhs);
	}

}
