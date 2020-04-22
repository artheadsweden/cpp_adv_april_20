#include <iostream>
#include <vector>
#include <functional>
#include <string>


using namespace std;

int main()
{
	vector<function<string(string)>> functions
	{
		[](string instring) {return "<strong>" + instring + "</strong>"; },
		[](string instring) {return "<h3>" + instring + "</h3>"; },
		[](string instring) {return "<p>" + instring + "</p>"; },
		[](string instring) {return "<div>" + instring + "</div>"; },
	};

	string input = "Tag me";
	for (auto func : functions)
	{
		input = func(input);
	}

	cout << input << endl;
	return 0;
}