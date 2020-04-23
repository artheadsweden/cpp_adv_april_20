#include <iostream>
#include <string>

using namespace std;

int main()
{
	string name1 = "Anna";
	string name2 = move(name1);

	cout << "!!" << name1 << "!!" << endl;
	cout << "!!" << name2 << "!!" << endl;
	return 0;
}