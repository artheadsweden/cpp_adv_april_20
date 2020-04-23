#include <iostream>

using namespace std;

void func(int& x)
{
	cout << "lvalue" << endl;
}

void func(int&& x)
{
	cout << "rvalue" << endl;
}

int main()
{
	int x = 10;
	func(x);
	func(10);
	return 0;
}