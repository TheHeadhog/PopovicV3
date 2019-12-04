#pragma once
#include "mapa.h"
#pragma region nata
ostream& operator<<(ostream& os, nata& p)
{
	p.pisi(os);
	return os;
}
ostream& operator<<(ostream& os, Mapa m)
{
	m.pisi(os);
	return os;
}

#pragma endregion

#pragma region Polje
Polje::Polje(int neprohodnost) {
	this->setneprohodnost(neprohodnost);
}
Polje::Polje(const Polje& p) {
	this->setneprohodnost(p.neprohodnost);
}
int& Polje::getneprohodnost() {
	return this->neprohodnost;
}
void Polje::setneprohodnost(int neprohodnost) {
	this->neprohodnost = neprohodnost;
}
Polje Polje::operator++(int) {
	if (this->getneprohodnost() < 1000) this->neprohodnost++;
	return *this;
}
Polje Polje::operator--(int) {
	if (this->getneprohodnost() > 0) this->neprohodnost--;
	return *this;
}
void Polje::pisi(ostream& os)
{
	os << "P_" << this->getneprohodnost();
}
#pragma endregion

#pragma region PoljeP
PoljeP::PoljeP(tip a, int b) {
	put = a;
	neprohodnost = b;
}
void PoljeP::pisi(ostream& os)
{
	char t;
	if (put == ZEMLJANI) { t = 'Z'; }
	else t = 'K';
	os << t << "_" << getneprohodnost();
}
PoljeP::PoljeP(tip a) {
	put = a;
}
#pragma endregion

#pragma region Poljes
PoljeS::PoljeS(int s)
{
	suma = s;
}
PoljeS::PoljeS(int s, int n)
{
	suma = s;
	neprohodnost = n;
}
void PoljeS::pisi(ostream& os)
{
	os << "S_" << neprohodnost << "(" << suma << ")";
}
#pragma endregion

#pragma region Mapa
Mapa::Mapa(int a, int b)
{
	mapa = new nata * *[a];
	for (int i = 0; i < a; i++)
	{
		mapa[i] = new nata * [b];
		for (int j = 0; j < b; j++)
		{
			mapa[i][j] = new  Polje();
		}
	}
	this->a = a; this->b = b;
}
Mapa* Mapa::operator+=(unsigned int c)
{
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++) {
			mapa[i][j]->setneprohodnost(mapa[i][j]->getneprohodnost() + c);
		}
	}
	return this;
}
Mapa* Mapa::operator-=(unsigned int c)
{
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++) {
			mapa[i][j]->setneprohodnost(mapa[i][j]->getneprohodnost() - c);
		}
	}
	return this;
}
void Mapa::pisi(ostream& os)
{
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++) {
			os << *mapa[i][j] << "\t";
		}
		os << endl;
	}
}
void Mapa::zameni(tip a, int i, int j) {
	nata* p = new PoljeP(a, mapa[i][j]->getneprohodnost());
	mapa[i][j] = p;
}
void Mapa::zameni(unsigned int s, int i, int j)
{
	nata* p = new PoljeS(s, mapa[i][j]->getneprohodnost());
	mapa[i][j] = p;
}

#pragma endregion
