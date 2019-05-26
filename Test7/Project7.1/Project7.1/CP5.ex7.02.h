#pragma once
#ifndef CP5_ex7_02_h
#define CP5_ex7_02_h
#include <string>

using namespace std;

// Add the combine and isbn members to the Sales_data
struct Sales_data {
	std::string isbn() const { return bookNo; };
	double avg_price() const;
	Sales_data& combine(const Sales_data&);

	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

double Sales_data::avg_price() const {
	if (units_sold) return revenue / units_sold;
	else return 0;
}

Sales_data& Sales_data::combine(const Sales_data& rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}



#endif