#include "mapa.h"

int main() {
	//nata* s = new PoljeP(KAMENI, 200);
	//cout << *s;
	//system("PAUSE");
	Mapa m(10, 10);
	m += 40;
	cout << m;
	system("PAUSE");
	m -= 20;
	cout << m;
	system("PAUSE");
	for (int i = 0; i < 10; i++) {
		m.zameni(KAMENI, i, 4);
		m.zameni(42, 4, i);
	}
	cout << m;
	system("PAUSE");
	return 0;
}