#include <iostream>

using namespace std;

auto func(int a, int b) 
{
	return a + b;
}

int main()
{
	int x = 10;
	int y = 11;

	auto value = [&x, y](int a, int b) 
	{
		return a + b + x + y;
	}(2, 3);
	cout << value << endl;
	return 0;
}