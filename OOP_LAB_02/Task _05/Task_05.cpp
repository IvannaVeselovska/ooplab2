#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Mnozhina {
private:
	int *k = new int;
	int* m;
public:
	Mnozhina() {
		printf("constructor without parameters\n");
	}
	Mnozhina(int k, int *d) {
		printf("\nconstructor with parameters\n");
		*this->k = k;
		m = new int[k];
		for (int i = 0; i <= k; ++i)
			this->m[i] = d[i];
	}
	Mnozhina(const Mnozhina* d) {
		printf("\ncopy constructor\n");
		*this->k = *d->k;
		this->m = new int[*d->k];
		for (int i = 0; i <= *d->k; ++i)
			m[i] = (*d).m[i];
	}
	~Mnozhina() {
		printf("destructor\n");
		delete k;
		delete[]m;
	}
	void set(int, int*);
	void setK(int);
	void setM(int*);
	void get();
	int getK();
	int* getM();
	void peretin(Mnozhina);
	void riznitsya(Mnozhina);
};

int main() {
	Mnozhina n, *l = new Mnozhina;
	int k = 6;
	printf("\ninput number of elements");
	scanf("%d", &k);
	int h[6];
	printf("\ninput elements");
	for (int i = 0; i < k; ++i)
		scanf("%d", h[i]);
	n.set(k, h);
	printf("\ninput number of elements");
	(*l).setK(k);
	printf("\ninput elements");
	(*l).setM(h);
	printf("\nelements\n");
	(*l).get();
	printf("\nperetin\n");
	n.peretin(*l);
	printf("\n riznitsya\n");
	(*l).riznitsya(n);
	delete l;
	system("pause");
}
void Mnozhina::set(int k, int *d) {
	*this->k = k;
	m = new int[k];
	for (int i = 0; i <= k; ++i)
		this->m[i] = d[i];

}
void Mnozhina::setK(int k) {
	*this->k = k;
}
void Mnozhina::setM(int *d) {
	m = new int[*this->k];
	for (int i = 0; i <= *this->k; ++i)
		this->m[i] = d[i];
}
int Mnozhina::getK() {
	return *this->k;
}
int* Mnozhina::getM() {
	return this->m;
}
void Mnozhina::get() {

	for (int j = 0; j <= *this->k; ++j)
		printf("\t%d", this->getM()[j]);
}
void Mnozhina::peretin(Mnozhina l) {
	for (int i = 0; i <= this->getK(); ++i)
		for (int j = 0; j <= l.getK(); ++j)
			if (this->getM()[i] == l.getM()[j])
				printf("\t%d", this->getM()[i]);
}
void Mnozhina::riznitsya(Mnozhina l) {
	int s;
	for (int i = 0; i <= this->getK(); ++i) {
		s = 0;
		for (int j = 0; j <= l.getK(); ++j)
			if (this->getM()[i] == l.getM()[j])
				++s;
		if (!s) printf("\t%d", this->getM()[i]);
	}
}