#include <iostream>

using namespace std;

int main()
{
	auto generator = [value = 0]() mutable
	{
		return value++;
	};

	int x;
	do {
		x = generator();
		cout << x << endl;

	} while (x < 5);
	cout << generator() << endl;
	return 0;
}