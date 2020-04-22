#include <iostream>
#include <thread>
#include <string>

using namespace std;

class Worker
{
public:
	Worker(string n): name(n){}
	void operator()()
	{
		cout << name << " " << this_thread::get_id() << endl;
	}
private:
	string name;
};

void worker1()
{
	cout << "Worker 1 " << this_thread::get_id() << endl;
}

int main()
{
	thread t1(worker1);

	thread t2([] {
		cout << "Worker 2 " << this_thread::get_id() << endl;
		});

	thread t3(Worker("Worker 3"));

	auto worker2 = []
	{
		cout << "Worker 4 " << this_thread::get_id() << endl;
	};

	thread t4(worker2);
	t4.join();
	t1.join();
	t2.join();
	t3.join();
	cout << "All threads are done." << endl;
	return 0;
}