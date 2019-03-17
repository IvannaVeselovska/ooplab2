#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class Fraction {
private:
	int *numerator = new int;
	int *denominator = new int;
public:
	Fraction();
	Fraction(int n, int d);
	Fraction(Fraction *d);
	~Fraction();
	double frac();
	void set(int, int);
	double sum(Fraction*);
	double diference(Fraction*);
	double multiply(Fraction*);
	double divide(Fraction*);
};

int main() {
	Fraction *j = new Fraction;
	int n, d;
	printf("\ninput your numenator and denominator");
	scanf("\n%d%d", &n, &d);
	Fraction i(n, d);
	printf("\ninput your numenator and denominator");
	scanf("\n%d%d", &n, &d);
	(*j).set(n, d);
	printf("\nsum - %.2lf", i.sum(j));
	printf("\ndiference - %.2lf", i.diference(j));
	printf("\nmultiply - %.2lf", i.multiply(j));
	printf("\ndivide - %.2lf", i.divide(j));
	delete j;
	system("pause");
}
Fraction::Fraction() {
	printf("\nconstructor without parameters\n");
}
Fraction::Fraction(int n, int d) {
	printf("\nconstructor with parameters\n");
	*(this->numerator) = n;
	*(this->denominator) = d;
}
Fraction::Fraction(Fraction *d) {
	printf("\ncopy constructor\n");
	*(this->numerator) = *d->numerator;
	*(this->denominator) = *d->denominator;
}
Fraction::~Fraction() {
	printf("\ndestructor\n");
	delete numerator;
	delete denominator;
}
void Fraction::set(int n, int d) {
	if (d > 0) {
		*(this->numerator) = n;
		*(this->denominator) = d;
	}
}
double Fraction::frac() {
	if (*(this->denominator) > 0) return *(this->numerator)*1.0 / *(this->denominator);
}
double Fraction::sum(Fraction *j) {
	return this->frac() + (*j).frac();
}
double Fraction::diference(Fraction *j) {
	return this->frac() - (*j).frac();
}
double Fraction::multiply(Fraction *j) {
	return this->frac()* (*j).frac();
}
double Fraction::divide(Fraction *j) {
	return this->frac() / (*j).frac();
}