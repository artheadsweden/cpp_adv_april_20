#include <iostream>

using namespace std;

int main()
{
	int x = 10;
	int y = 11;
	int const* iptr = &x;
	iptr = &y;



	return 0;
}