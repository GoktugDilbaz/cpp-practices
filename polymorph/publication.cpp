// Defines a class named publication and uses polymorphism with that

#include <iostream>
#include <stdlib.h>
#include <string>
#define SIZE 20

using namespace std;

//functions to take input (defined at the end of script)
int getInteger();
char getCharacter();
float getFloating();
//

//Declerations of classes
class Publication {
protected:
	string title;
	float price;
public:
	Publication();					// empty constructor for abstract class
	virtual void print() {
		cout << "Title: " << title << " Price: " << price << " ";	// this function's work will be completed with other print functions...
	}
	virtual bool check_discount() = 0;
};

class Book : public Publication {
protected:
	int pages;
public:
	Book();
	void print();
	bool check_discount();
};

class VTR : public Publication {
protected:
	int time;
public:
	VTR();
	void print();
	bool check_discount();
};

class Disk : public Publication {
protected:
	int capacity;
public:
	Disk();
	void print();
	bool check_discount();
};

Publication::Publication() {
	string input;
	float input2;
	
	cin.ignore();
	cout << "Enter publication title: ";
	getline(cin, input);					//Whole line is publication's name
	
	cout << "Enter publication price: ";
	input2 = getFloating();

	title = input;
	price = abs(input2);					//To prevent negative price
}

//	For Book
Book::Book() {
	int input;
	
	cout << "Enter the number of pages: ";
	input = getInteger();
	
	pages = abs(input);				//To prevent negative page number
}

void Book::print() {
	Publication::print();					//abstract class' print first
	cout << "Book pages: " << pages << " ";

	if (check_discount()) {					//function returns true if it's discounted
		cout << "Discounted product\n";
	}
	else {
		cout << "\n";
	}
}

bool Book::check_discount() {
	if (pages < 1000) {					//discount condition
		return true;
	}
	return false;
}

//	For VTR
VTR::VTR() {
	int input;
	
	cout << "Enter the time of VTR: ";
	input = getInteger();
	
	time = abs(input);
}

// Almost the same with book's print()
void VTR::print() {
	Publication::print();
	cout << "VTR time: " << time << " ";

	if (check_discount()) {
		cout << "Discounted product\n";
	}
	else {
		cout << "\n";
	}
}

bool VTR :: check_discount() {
	if (time < 120) {					//discount condition
		return true;
	}
	return false;
}

//	For Disk
Disk::Disk() {
	int input;
	
	cout << "Enter disk capacity(GB): ";
	input = getInteger();

	capacity = abs(input);
}

void Disk::print() {
	Publication::print();
	cout << "Disk capacity(GB): " << capacity << " ";

	if (check_discount()) {
		cout << "Discounted product\n";
	}
	else {
		cout << "\n";
	}
}

bool Disk::check_discount() {
	if (capacity < 8) {					//discount condition
		return true;
	}
	return false;
}

int main()
{
	Publication *p[SIZE];
	int counter = 0;
	char input;
	while (true){
		
		//checking if the array is full
		if (counter >= SIZE) {
			cout << "Memory is full, terminating...\n";
			break;
		}

		cout << "Enter publication type to add (B: Book, V: VTR, D: Disk): ";
		input = getCharacter();

		//determining which object to create
		if (input == 'B' || input == 'b') {
			p[counter++] = new Book;
		}
		else if (input == 'V' || input == 'v') {
			p[counter++] = new VTR;
		}
		else if (input == 'D' || input == 'd') {
			p[counter++] = new Disk;
		}
		else {
			cout << "Wrong input...\n\n";
		}

		//terminating only if the input is N, else continue
		
		cout << "Continue (Y/N) ? ";
		input = getCharacter();

		if (input == 'N' || input == 'n') { cout << endl; break; }
		cout << endl;
	}

	cout << "LIST OF ALL PUBLICATIONS" << endl;

	//listing all entries
	for (int i = 0; i < counter; i++) {
		p[i]->print();
	}
	
	system("pause");
    return 0;
}

//These functions aim to increase stability of console input
int getInteger() {
	int n;
	cin >> n;
	
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Not a valid number. Please reenter: ";
		cin >> n;
	}
	
	return n;
}

char getCharacter() {
	char n;
	cin >> n;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Not a valid character. Please reenter: ";
		cin >> n;
	}

	return n;
}

float getFloating() {
	float n;
	cin >> n;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Not a valid number. Please reenter: ";
		cin >> n;
	}

	return n;
}
