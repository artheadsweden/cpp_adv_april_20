#include <iostream>
#include <string>

using namespace std;

void process(string& arg)
{
	cout << "lvalue process" << endl;
}

void process(string&& arg)
{
	cout << "rvalue process" << endl;
}


template <typename T>
void log_and_process(T&& param)
{
	// .. do some logging
	process(forward<T>(param));
}


string get_text()
{
	return "hi";
}


int main()
{
	string str = "hi again";
	log_and_process(str);
	log_and_process(get_text());
	return 0;
}