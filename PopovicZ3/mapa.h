#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

enum tip { ZEMLJANI, KAMENI };

class nata {
public:
	explicit nata() {};
	virtual void pisi(ostream& os) = 0;
	friend ostream& operator<<(ostream& os, nata& p);
	virtual int& getneprohodnost() = 0;
	virtual void setneprohodnost(const int neprohodnost) = 0;

 protected:
	 int neprohodnost = 100;
};

class Polje:public nata {
public:
	Polje() = default;
	Polje(int neprohodnost);
	Polje(const Polje& p);
	int& getneprohodnost();
	void setneprohodnost(const int neprohodnost);
	Polje operator++(int);
	Polje operator--(int);
	void  pisi(ostream& os);
private:

};

class PoljeP:public Polje {
public:
	PoljeP(tip a);
	PoljeP(tip a, int b);
	
private:
	
	tip put;
	void pisi(ostream& os) override;
	
};

class PoljeS :public Polje {
public:
	PoljeS(int s);
	PoljeS(int s,int n);
	
private:
	unsigned int suma;
	void pisi(ostream& os) override;
};

class Mapa {
public:
	nata*** mapa;
	void zameni(tip a, int i, int j);
	void zameni(unsigned int s, int i, int j);
	Mapa(int a, int b);
	Mapa* operator+=(unsigned int i);
	Mapa* operator-=(unsigned int i);
	friend ostream& operator<<(ostream& os, Mapa m);
	void pisi(ostream& os);
private:
	
	int a, b;
};
