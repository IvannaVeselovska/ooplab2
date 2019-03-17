#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Date {
private:
	int *day = new int;
	int *month = new int;
	int *year = new int;
public:
	Date();
	Date(int d, int m, int y);
	Date(Date* s);
	~Date();
	void set(int, int, int);
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	void get();
	void get2();
	int getDay();
	int getMonth();
	int getYear();
	void increase();
};

int main() {
	int d, m, y;
	printf("\ninput your date");
	scanf("\n%d%d%d", &d, &m, &y);
	Date *a = new Date(d, m, y);
	/*printf("\ninput your date");
	scanf("\n%d%d%d", &d, &m, &y);
	//a.set();*/
	(*a).get();
	printf("\ninput your day");
	scanf("\n%d", &d);
	(*a).setDay(d);
	printf("\ninput your month");
	scanf("\n%d", &m);
	(*a).setMonth(m);
	printf("\ninput your year");
	scanf("\n%d", &y);
	(*a).setYear(y);
	(*a).get2();
	Date g(a);
	g.increase();
	printf("\n day - %d", g.getDay());
	printf("\n month - %d", g.getMonth());
	printf("\n year - %d", g.getYear());
	system("pause");
}
Date::Date() {
	printf("constructor without parameters\n");
}
Date::~Date() {
	printf("destructor\n");
}
Date::Date(Date*s) {
	printf("\ncopy constructor\n");
	*this->day = *s->day;
	*this->month = *s->month;
	*this->year = *s->year;
}
Date::Date(int d, int m, int y) {
	printf("\nconstructor with parameters\n");
	if (d > 0 && m > 0 && d < 32 & m < 13 && y>0)
		if (m == 2)
			if (y % 4 == 0)
				if (d < 30) {
					*this->day = d;
					*this->month = m;
					*this->year = y;
				}
				else printf("\nsomething went wrong");
			else if (d < 29) {
				*this->day = d;
				*this->month = m;
				*this->year = y;
			}
			else printf("\nsomething went wrong");
		else if (m == 4 || m == 6 || m == 9 || m == 11)
			if (d < 31) {
				*this->day = d;
				*this->month = m;
				*this->year = y;
			}
			else printf("\nsomething went wrong");
		else {
			*this->day = d;
			*this->month = m;
			*this->year = y;
		}
}
void Date::set(int d, int m, int y) {

	if (d > 0 && m > 0 && d < 32 & m < 13 && y>0)
		if (m == 2)
			if (y % 4 == 0)
				if (d < 30) {
					*this->day = d;
					*this->month = m;
					*this->year = y;
				}
				else printf("\nsomething went wrong");
			else if (d < 29) {
				*this->day = d;
				*this->month = m;
				*this->year = y;
			}
			else printf("\nsomething went wrong");
		else if (m == 4 || m == 6 || m == 9 || m == 11)
			if (d < 31) {
				*this->day = d;
				*this->month = m;
				*this->year = y;
			}
			else printf("\nsomething went wrong");
		else {
			*this->day = d;
			*this->month = m;
			*this->year = y;
		}
}
void Date::setDay(int d) {

	if (d > 0 && d < 32) *this->day = d;
}
void Date::setMonth(int m) {

	if (m > 0 && m < 13) *this->month = m;
}
void Date::setYear(int y) {

	if (y > 0) *this->year = y;
}
int Date::getDay() {
	return *this->day;
}
int Date::getMonth() {
	return *this->month;
}
int Date::getYear() {
	return *this->year;
}
void Date::increase() {
	if (*this->month == 2)
		if (*this->year % 4 == 0)
			if (*this->day == 29) {
				*this->day = 1;
				(*this->month)++;
			}
			else printf("\nsomething went wrong");
		else if (*this->day == 28) {
			*this->day = 1;
			(*this->month)++;
		}
		else printf("\nsomething went wrong");
	else if (*this->month == 4 || *this->month == 6 || *this->month == 9 || *this->month == 11)
		if (*this->day == 30) {
			*this->day = 1;
			(*this->month)++;
		}
		else printf("\nsomething went wrong");
	else if (*this->day == 31 && *this->month == 12) {
		*this->day = 1;
		*this->month = 1;
		(*this->year)++;
	}
}
void Date::get() {
	printf("\n%d/%d/%d", *this->day, *this->month, *this->year);
}
void Date::get2() {
	printf("\n%d-%d-%d", *this->year, *this->month, *this->day);
}
