#include <iostream>
#include <chrono>
#include <string>
#include <thread>

using namespace std;

string fetchFromDb(string data)
{
	this_thread::sleep_for(chrono::seconds(5));
	return "DB_" + data;
}

string fetchFromFile(string data)
{
	this_thread::sleep_for(chrono::seconds(4));
	return "File_" + data;
}

int main()
{
	auto start = chrono::system_clock::now();
	auto dbData = fetchFromDb("Data");
	auto fileData = fetchFromFile("Data");
	auto end = chrono::system_clock::now();
	auto diff = chrono::duration_cast<chrono::seconds>(end - start).count();
	cout << "Time taken: " << diff << " seconds" << endl;

	cout << dbData << " - " << fileData << endl;
	return 0;
}