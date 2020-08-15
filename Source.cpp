#include <iostream>
#include "Fortess.h"
using namespace std;
int main()
{


	Fortess x(10, 5);

	cout << endl << endl;
	x.shotArcher();
	cout << endl << endl;
	x.shotRange();
	cout << endl << endl;
	x.shotCatapult();
	cout << endl << endl;
	system("pause");
	return 0;
}