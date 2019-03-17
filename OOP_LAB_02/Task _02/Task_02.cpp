#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class Time {
private:
	int *hour = new int;
	int *min = new int;
	int *sec = new int;
public:
	Time();
	Time(const Time* ti);
	Time(int h, int m, int s);
	void timeChange(int h, int m, int s);
	void showTime1();
	void showTime2();
	void setTime(int h, int m, int s);
	~Time();
};
int main() {
	Time *t = new Time;
	int a, b, c;
	scanf("\n%d\n%d\n%d", &a, &b, &c);
	(*t).setTime(a, b, c);
	(*t).showTime1();
	(*t).showTime2();
	printf("\ninput other time");
	scanf("\n%d\n%d\n%d", &a, &b, &c);
	(*t).timeChange(a, b, c);
	(*t).showTime1();
	(*t).showTime2();
	Time ti(t);
	ti.showTime1();
	ti.showTime2();
	delete t;
	getchar();
	getchar();
}
void Time::timeChange(int h, int m, int s) {
	int i = 0;
	if (h >= 0 && h < 24) *(this->hour) = h;
	else ++i;
	if (m >= 0 && m < 60) *(this->min) = m;
	else ++i;
	if (s >= 0 && s < 60) *(this->sec) = s;
	else ++i;
}
void Time::showTime1() {
	printf("%d hours %d minutes %d seconds", *(this->hour), *(this->min), *(this->sec));
}
void Time::showTime2() {
	printf("\n%d:%d:%d", *(this->hour), *(this->min), *(this->sec));
}
void Time::setTime(int h, int m, int s) {
	if (h >= 0 && h < 24) *(this->hour) = h;
	if (m >= 0 && m < 60) *(this->min) = m;
	if (s >= 0 && s < 60) *(this->sec) = s;
}
Time::Time() {
	printf("constructor without parameters\n");
}
Time::Time(const Time* ti) {
	printf("\ncopy constructor\n");
	*this->hour = *ti->hour;
	*this->min = *ti->min;
	*this->sec = *ti->sec;
}
Time::Time(int h, int m, int s) {
	printf("\nconstructor with parameters\n");
	if (h >= 0 && h < 24) *(this->hour) = h;
	if (m >= 0 && m < 60) *(this->min) = m;
	if (s >= 0 && s < 60)*(this->sec) = s;
}
Time::~Time() {
	printf("\ndestructor\n");
	delete hour;
	delete min;
	delete sec;
}