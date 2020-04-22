#include <iostream>
#include <functional>

using namespace std;

function<int(int)> funcfact2(int x)
{
	return [=](int y)
	{
		return x * y;
	};
}


auto funcfact3(int x)
{
	return [=](int y)
	{
		return x * y;
	};
}

int main()
{
	auto funcfact = [](int x)
	{
		return [=](int y)
		{
			return x * y;
		};
	};

	auto f1 = funcfact3(2);
	auto f2 = funcfact3(3);

	cout << f1(3) << endl;
	cout << f2(3) << endl;
	return 0;
}