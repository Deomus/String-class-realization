#include <iostream>
using namespace std;

class String
{
	char *str;
	int size = 0;
public:
	// Конструкторы / Деструктор
	String()
	{
		str = nullptr;
	}
	String(const char *str)
	{
		size = 0;
		while (str[size] != '\0')
			size++;

		this->str = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			this->str[i] = str[i];
		}
		this->str[size] = '\0';
	}
	String(const String &other)
	{
		size = other.size;
		this->str = new char[size + 1];
		for (int i = 0; i < other.size; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[size] = '\0';
	}
	~String()
	{
		delete[] str;
	}

	// Методы
	int length()
	{
		return size;
	}
	const char *getStr()
	{
		return this->str;
	}

	// Операторы 
	String &operator= (const String &other)
	{
		if (this != &other)
		{
			delete[] this->str;
			size = other.size;
			this->str = new char[size + 1];
			for (int i = 0; i < other.size; i++)
			{
				this->str[i] = other.str[i];
			}
			this->str[size] = '\0';
		}
	}
	String operator+(const String &other)
	{
		String outStr;
		outStr.size = this->size + other.size;
		outStr.str = new char[outStr.size + 1];
		int i = 0;
		for (; i < this->size; i++)
		{
			outStr.str[i] = this->str[i];
		}
		for (int j = 0; j < other.size; j++, i++)
		{
			outStr.str[i] = other.str[j];
		}
		outStr.str[outStr.size] = '\0';
		return outStr;
	}
	char &operator[](int i)
	{
		return this->str[i];
	}
	friend ostream &operator << (ostream &os, const String &str);
};

ostream &operator << (ostream &os, const String &str)
{
	os << str.str;
	return os;
}


int main()
{
	String str("TEST");
	String str2("str2");
	for (int i = 0; i < str.length(); i++)
	{
		str[i] = str2[i];
	}
	cout << str + " " + str2 << endl;
}
