#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <future>

using namespace std;

string fetchFromDb(string data)
{
	this_thread::sleep_for(chrono::seconds(2));
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
	future<string> future_dbData = async(launch::async, fetchFromDb, "Data");
	future<string> future_fileData = async(launch::async, fetchFromFile, "Data");

	string dbData = future_dbData.get();
	cout << "Got dbData" << endl;
	string fileData = future_fileData.get();

	// Now we got all the data

	auto end = chrono::system_clock::now();
	auto diff = chrono::duration_cast<chrono::seconds>(end - start).count();
	cout << "Time taken: " << diff << " seconds" << endl;

	cout << dbData << " - " << fileData << endl;
	return 0;
}