// ConsoleApplication34.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Header.h"

int main()
{
	try
	{
		Array array;
		array.get_array();
		array.sort();
		array.get_array();
		array.Add();
		array.get_array();
		array.Task();
		array.Save();
	}
	catch (Array::input)
	{
		cout << "invalid input" << endl;
	}
	catch (Array::Delete)
	{
		cout << "array size is smaller" << endl;
	}
	system("pause");
}
