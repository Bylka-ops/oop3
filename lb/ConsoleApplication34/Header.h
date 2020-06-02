#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>	
#include <stdlib.h>

using namespace std;

class TextFile
{
public:
	TextFile();
	int Count;
	string* File;
private:
	string Path;
};

class Labrary
{
public:
	int RegistrationNumber;
	int NumberOfBooks;
	string BookGenres;
	int NumberOfBooksTakenForReading;
	int TheNumberOfBooksTakenForReadingInTheHall;
	int TheNumberOfVisitsPerMonthOfTheHall;
	Labrary(){};
	~Labrary() {};
	Labrary(int _RegistrationNumber, int _NumberOfBooks, string _BookGenres, int _NumberOfBooksTakenForReading, int _TheNumberOfBooksTakenForReadingInTheHall, int _TheNumberOfVisitsPerMonthOfTheHall);
};

class Array
{
private:
	TextFile textFile;
	Labrary *_Labrary;
	int Count;
	void add_array(Labrary _labrary, int _Count);
	void quickSortRN(Labrary *numbers, int left, int right);
	void quickSortNOB(Labrary *numbers, int left, int right);
	void quickSortBG(Labrary *numbers, int left, int right);
	void quickSortNOBTFR(Labrary *numbers, int left, int right);
	void quickSortTNOBTFRITH(Labrary *numbers, int left, int right);
	void quickSortTNOVPMOTH(Labrary *numbers, int left, int right);
public:
	Array();
	class input
	{

	};
	class Delete
	{

	};
	void Save();
	void Task();
	void Add();
	void Del(int RN);
	void Find(int RN);
	void get_array();
	void sort();
	friend ostream& operator<< (ostream &out, const Labrary &a);
};

ostream& operator<< (ostream &out, const Labrary &a)
{
	out << setw(20) << a.RegistrationNumber << setw(20) << a.NumberOfBooks << setw(40) << a.BookGenres << setw(20) << a.NumberOfBooksTakenForReading << setw(20) << a.TheNumberOfBooksTakenForReadingInTheHall << setw(20) << a.TheNumberOfVisitsPerMonthOfTheHall << endl;
	return out;
}

Array::Array()
{
	Count = textFile.Count / 6;
	_Labrary = new Labrary[Count];
	int k = 0;
	int number=0;
	Labrary lb;
	while (textFile.Count > k)
	{
		if (k % 6 == 0)
			lb.RegistrationNumber = atoi(textFile.File[k].c_str());
		if (k % 6 == 1)
			lb.NumberOfBooks = atoi(textFile.File[k].c_str());
		if (k % 6 == 2)
			lb.BookGenres = textFile.File[k];
		if (k % 6 == 3)
			lb.NumberOfBooksTakenForReading = atoi(textFile.File[k].c_str());
		if (k % 6 == 4)
			lb.TheNumberOfBooksTakenForReadingInTheHall = atoi(textFile.File[k].c_str());
		if (k % 6 == 5) 
		{
			lb.TheNumberOfVisitsPerMonthOfTheHall = atoi(textFile.File[k].c_str());
			add_array(lb, number);
			number++;
		}
		k++;
	}
}

void Array::add_array(Labrary lb,int number)
{
	_Labrary[number].RegistrationNumber = lb.RegistrationNumber;
	_Labrary[number].NumberOfBooks = lb.NumberOfBooks;
	_Labrary[number].BookGenres = lb.BookGenres;
	_Labrary[number].NumberOfBooksTakenForReading = lb.NumberOfBooksTakenForReading;
	_Labrary[number].TheNumberOfBooksTakenForReadingInTheHall = lb.TheNumberOfBooksTakenForReadingInTheHall;
	_Labrary[number].TheNumberOfVisitsPerMonthOfTheHall = lb.TheNumberOfVisitsPerMonthOfTheHall;
}

void Array::get_array()
{
	for (int i = 0; i < Count; i++)
	{
		cout << _Labrary[i].RegistrationNumber << " " << _Labrary[i].NumberOfBooks << " "<<_Labrary[i].BookGenres << " "<<_Labrary[i].NumberOfBooksTakenForReading << " "<<_Labrary[i].TheNumberOfBooksTakenForReadingInTheHall << " "<<_Labrary[i].TheNumberOfVisitsPerMonthOfTheHall <<endl;
	}
}

void Array::sort()
{
	cout << "to sort by registration number, press 1" << endl;
	cout << "to sort by the number of books, press 2" << endl;
	cout << "to sort by genre of books that are in the library of books, press 3" << endl;
	cout << "to sort by the number of books taken for reading, press 4" << endl;
	cout << "to sort by the number of books taken for reading in the room, press 5" << endl;
	cout << "to sort by the number of visits in the hall per month, press 6" << endl;
	int choise = 0;
	cin >> choise;
	if (choise == 1)
	{
		quickSortRN(_Labrary,0,  Count - 1);
	}
	if (choise == 2)
	{
		quickSortNOB(_Labrary, 0, Count - 1);
	}
	if (choise == 3)
	{
		quickSortBG(_Labrary, 0, Count - 1);;
	}
	if (choise == 4)
	{
		quickSortNOBTFR(_Labrary, 0, Count - 1);
	}
	if (choise == 5)
	{
		quickSortTNOBTFRITH(_Labrary, 0, Count - 1);
	}
	if (choise == 6)
	{
		quickSortTNOVPMOTH(_Labrary, 0, Count - 1);
	}
}

void Array::quickSortRN(Labrary *lb, int left, int right)
{
	register int i, j;
	int x;
	Labrary temp;

	i = left; j = right;
	x = lb[(left + right) / 2].RegistrationNumber;

	do {
		while ((lb[i].RegistrationNumber< x ) && (i < right)) i++;
		while ((lb[j].RegistrationNumber> x ) && (j > left)) j--;
		if (i <= j) {
			temp = lb[i];
			lb[i] = lb[j];
			lb[j] = temp;
			i++; j--;
		}
	} while (i <= j);

	if (left < j) quickSortRN(lb, left, j);
	if (i < right) quickSortRN(lb, i, right);
}

void Array::quickSortNOB(Labrary *lb, int left, int right)
{
	register int i, j;
	int x;
	Labrary temp;

	i = left; j = right;
	x = lb[(left + right) / 2].NumberOfBooks;

	do {
		while ((lb[i].NumberOfBooks< x) && (i < right)) i++;
		while ((lb[j].NumberOfBooks> x) && (j > left)) j--;
		if (i <= j) {
			temp = lb[i];
			lb[i] = lb[j];
			lb[j] = temp;
			i++; j--;
		}
	} while (i <= j);

	if (left < j) quickSortNOB(lb, left, j);
	if (i < right) quickSortNOB(lb, i, right);
}

void Array::quickSortBG(Labrary *lb, int left, int right)
{
	register int i, j;
	string x;
	Labrary temp;

	i = left; j = right;
	x = lb[(left + right) / 2].BookGenres;

	do {
		while ((strcmp(lb[i].BookGenres.c_str(), x.c_str()) < 0) && (i < right)) i++;
		while ((strcmp(lb[j].BookGenres.c_str(), x.c_str()) > 0) && (j > left)) j--;
		if (i <= j) {
			temp = lb[i];
			lb[i] = lb[j];
			lb[j] = temp;
			i++; j--;
		}
	} while (i <= j);

	if (left < j) quickSortBG(lb, left, j);
	if (i < right) quickSortBG(lb, i, right);
}

void Array::quickSortNOBTFR(Labrary *lb, int left, int right)
{
	register int i, j;
	int x;
	Labrary temp;

	i = left; j = right;
	x = lb[(left + right) / 2].NumberOfBooksTakenForReading;

	do {
		while ((lb[i].NumberOfBooksTakenForReading< x) && (i < right)) i++;
		while ((lb[j].NumberOfBooksTakenForReading> x) && (j > left)) j--;
		if (i <= j) {
			temp = lb[i];
			lb[i] = lb[j];
			lb[j] = temp;
			i++; j--;
		}
	} while (i <= j);

	if (left < j) quickSortNOBTFR(lb, left, j);
	if (i < right) quickSortNOBTFR(lb, i, right);
}

void Array::quickSortTNOBTFRITH(Labrary *lb, int left, int right)
{
	register int i, j;
	int x;
	Labrary temp;

	i = left; j = right;
	x = lb[(left + right) / 2].TheNumberOfBooksTakenForReadingInTheHall;

	do {
		while ((lb[i].TheNumberOfBooksTakenForReadingInTheHall< x) && (i < right)) i++;
		while ((lb[j].TheNumberOfBooksTakenForReadingInTheHall> x) && (j > left)) j--;
		if (i <= j) {
			temp = lb[i];
			lb[i] = lb[j];
			lb[j] = temp;
			i++; j--;
		}
	} while (i <= j);

	if (left < j) quickSortTNOBTFRITH(lb, left, j);
	if (i < right) quickSortTNOBTFRITH(lb, i, right);
}

void Array::quickSortTNOVPMOTH(Labrary *lb, int left, int right)
{
	register int i, j;
	int x;
	Labrary temp;

	i = left; j = right;
	x = lb[(left + right) / 2].TheNumberOfVisitsPerMonthOfTheHall;

	do {
		while ((lb[i].TheNumberOfVisitsPerMonthOfTheHall< x) && (i < right)) i++;
		while ((lb[j].TheNumberOfVisitsPerMonthOfTheHall> x) && (j > left)) j--;
		if (i <= j) {
			temp = lb[i];
			lb[i] = lb[j];
			lb[j] = temp;
			i++; j--;
		}
	} while (i <= j);

	if (left < j) quickSortTNOVPMOTH(lb, left, j);
	if (i < right) quickSortTNOVPMOTH(lb, i, right);
}

void Array::Add()
{
	Labrary lb;
	cout<<"Enter registration number"<<endl;
	while (!(cin >> lb.RegistrationNumber) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		throw input();
	}
	cout << "Enter the number of books" << endl;
	while (!(cin >> lb.NumberOfBooks) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		throw input();
	}
	cout << "Enter the genres of books that are in the library" << endl;
	while (!(cin >> lb.BookGenres) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		throw input();
	}
	cout << "Enter the number of books to read" << endl;
	while (!(cin >> lb.NumberOfBooksTakenForReading) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		throw input();
	}
	cout << "Enter the number of books taken for reading in the hall " << endl;
	while (!(cin >> lb.TheNumberOfBooksTakenForReadingInTheHall) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		throw input();
	}
	cout << "Enter the number of visits per month in the room" << endl;
	while (!(cin >> lb.TheNumberOfVisitsPerMonthOfTheHall) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		throw input();
	}
	Labrary *lab = new Labrary[Count];
	for (int i = 0; i < Count; i++)
	{
		lab[i] = _Labrary[i];
	}
	delete [] _Labrary;
	_Labrary = new Labrary[Count + 1];
	for (int i = 0; i < Count; i++)
	{
		_Labrary[i] = lab[i];
	}
	add_array(lb, Count);
	Count++;
}

void Array::Del(int RN)
{
	if (RN > Count)
	{
		throw Delete();
	}
	else
	{
		if (RN == Count)
			Count--;
		else
		{
			Labrary *lb = new Labrary[Count - 1];
			int k = 0;
			for (int i = 0; i < Count; i++)
			{
				if (RN - 1 == i)
					i++;
				lb[k] = _Labrary[i];
				k++;
			}
			Count--;
			for (int i = 0; i < Count; i++)
			{
				_Labrary[i] = lb[i];
			}
			delete[] lb;
		}
	}
}

void Array::Find(int RN)
{
	bool flag = false;
	for (int i = 0; i < Count; i++)
	{
		if (_Labrary[i].RegistrationNumber == RN)
			flag = true;
	}
	if (flag == true)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
}

void Array::Task()
{
	cout<< "Enter registration number" <<endl;
	int choise;
	cin>>choise;
	for (int i = 0; i < Count; i++)
	{
		if (_Labrary[i].RegistrationNumber == choise)
		{
			cout<< _Labrary[i].BookGenres << " " << _Labrary[i].NumberOfBooksTakenForReading << " " << _Labrary[i].TheNumberOfBooksTakenForReadingInTheHall << " " << _Labrary[i].TheNumberOfVisitsPerMonthOfTheHall << endl;
		}
	}
}

TextFile::TextFile()
{
	cout << "Enter a file name to read" << endl;
	getline(cin, Path);
	Path += ".txt";
	ifstream _File;
	_File.open(Path);
	if (!_File)
		cout << "\nCant find this file : " << Path << endl;
	else
	{
		cout << "file open" << endl;
		string line;
		Count = 0;
		while (getline(_File, line))
		{
			Count++;
		}
		File = new string[Count];
		_File.close();
		_File.open(Path);
		int k = 0;
		while (getline(_File, line))
		{
			File[k] = line;
			k++;
		}
	}
	_File.close();
}

Labrary::Labrary(int _RegistrationNumber,int _NumberOfBooks,string _BookGenres,int _NumberOfBooksTakenForReading,int _TheNumberOfBooksTakenForReadingInTheHall,int _TheNumberOfVisitsPerMonthOfTheHall)
{
	RegistrationNumber = _RegistrationNumber;
	NumberOfBooks = _NumberOfBooks;
	BookGenres = _BookGenres;
	NumberOfBooksTakenForReading = _NumberOfBooksTakenForReading;
	TheNumberOfBooksTakenForReadingInTheHall = _TheNumberOfBooksTakenForReadingInTheHall;
	TheNumberOfVisitsPerMonthOfTheHall = _TheNumberOfVisitsPerMonthOfTheHall;
}

void Array::Save()
{
	cout << "Enter a file name to save" << endl;
	string path;
	cin >> path;
	path += ".txt";
	ofstream out;
	out.open(path);
	if (out.is_open())
	{
		for (int i = 1; i < Count; i++)
		{
			out << _Labrary[i].RegistrationNumber << endl;
			out << _Labrary[i].NumberOfBooks << endl;
			out << _Labrary[i].BookGenres << endl;
			out << _Labrary[i].NumberOfBooksTakenForReading << endl;
			out << _Labrary[i].TheNumberOfBooksTakenForReadingInTheHall << endl;
			out << _Labrary[i].TheNumberOfVisitsPerMonthOfTheHall << endl;
		}
	}
	out.close();
	cout << "save" << endl;
}
