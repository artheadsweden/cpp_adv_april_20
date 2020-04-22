#include <iostream>

using namespace std;

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int doit(int x, int y, int(*c)(int, int))
{
	return c(x, y);
}


int main()
{
	cout << doit(3, 4, add) << endl;
	cout << doit(3, 4, sub) << endl;
	int(*minus)(int, int) = sub;
	cout << doit(3, 4, minus) << endl;
	return 0;
}