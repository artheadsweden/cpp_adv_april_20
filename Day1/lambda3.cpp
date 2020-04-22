#include <iostream>
#include <string>

using namespace std;

int main()
{
	auto x = 10;
	auto f = [&r = x] {
		r++;
	};

	f();
	cout << x << endl;


	string name = "Anna";
	auto f2 = [n = move(name)]{
		cout << "inside the lambda " << n << endl;
	};

	f2();
	cout << "outside the lambda " << name << endl;
	f2();
	return 0;
}