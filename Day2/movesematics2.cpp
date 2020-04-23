#include <iostream>

using namespace std;

class MyClass
{
public:
	MyClass(): value(nullptr)
	{
		cout << "Default Constructor" << endl;
	}

	MyClass(int v) : value(new int(v))
	{
		cout << "Constructor with argument" << endl;
	}

	MyClass(const MyClass& other) : value(new int(*other.value))
	{
		cout << "Copy constructor" << endl;
	}

	MyClass(MyClass&& other) noexcept: value(nullptr)
	{
		swap(value, other.value);
		cout << "Move constructor" << endl;
	}

	~MyClass()
	{
		cout << "Destructor" << endl;
		delete value;
	}

	MyClass& operator=(const MyClass& other)
	{
		value = new int(*other.value);
		cout << "Copy asignment operator" << endl;
		return *this;
	}

	MyClass& operator=(MyClass&& other) noexcept 
	{
		value = nullptr;
		swap(value, other.value);
		cout << "Move asignment operator" << endl;
		return *this;
	}

	void print()
	{
		if (value != nullptr)
		{
			cout << *value << endl;
		}
		else
		{
			cout << "null" << endl;
		}
	}

private:
	int* value;
};

MyClass func(int i)
{
	MyClass obj(i);
	return obj;
}


int main()
{

	MyClass m1(10);
	MyClass m2 = func(45);
	m1.print();
	m2.print();
	return 0;
}