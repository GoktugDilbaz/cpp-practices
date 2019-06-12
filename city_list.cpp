// OOP - HW #3
// 01.01.2018
// Faik Göktuð Dilbaz
// 040150603

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>	//Required for std::setw

using namespace std;

struct City {
	int identity;
	int amount;
	string name;
};

class CityList {
	vector<City> records;
public:
	CityList() {}
	CityList(char*);
	void print();
	CityList operator+(const CityList&);
	CityList operator-(const CityList&);
	CityList operator+(int);
	CityList operator-(int);
};

CityList::CityList(char* filename) {
	ifstream file;
	file.open(filename);
	
	City* p = new City;
	if (file.is_open()) {
		while (!file.eof()) {
			file >> p->identity;
			file >> p->name;
			file >> p->amount;
			
			records.push_back(*p);	//Filling the object
		}
		return;
	}
	cout << "Failed to create city list..." << endl;
	return;
}

void CityList::print() {
	cout << left << setw(5) << "ID"
		<< left << setw(15) << "Name"
		<< left << setw(5) << "Amount"
		<< endl;

	for (unsigned int i = 0; i < records.size(); i++) {
		cout << left << setw(5) << records[i].identity
			<< left << setw(15) << records[i].name
			<< left << setw(5) << records[i].amount
			<< endl;
	}

	cout << "*****************************" << endl;
}
//Iterating between each CityList one-by-one
CityList CityList::operator+(const CityList& other) {
	bool same_found;
	for (unsigned int i = 0; i < other.records.size(); i++) {	//Outer loop is for targer object
		same_found = false;
		for (unsigned int j = 0; j < this->records.size(); j++) {
			if (other.records[i].identity == this->records[j].identity) {
				this->records[j].amount += other.records[i].amount;
				same_found = true;
				break;		//Breaks inner loop if same found
			}
		}
		if (same_found) continue;	//Passes pushing if same found
		this->records.push_back(other.records[i]);
	}
	CityList newList = *this;	//Returns the copy of this object, original object is also changed. 
	return newList;
}

//Same mentality with operator+, just reverse iterations between lists
CityList CityList::operator-(const CityList& other) {
	CityList newList = *this;
	bool same_found;
	for (unsigned int i = 0; i < this->records.size(); i++) {
		same_found = false;
		for (unsigned int j = 0; j < other.records.size(); j++) {	//Inner loop is for target object
			if (other.records[j].identity == this->records[i].identity) {
				same_found = true;
				break;
			}
		}
		if (same_found) continue;
		newList.records.push_back(this->records[i]);
	}
	return newList;
}

CityList CityList::operator+(int amount) {
	CityList newList = *this;
	for (unsigned int i = 0; i < records.size(); i++) {
		newList.records[i].amount += amount;
	}
	return newList;
}

CityList CityList::operator-(int amount) {
	CityList newList = *this;
	for (unsigned int i = 0; i < records.size(); i++) {
		newList.records[i].amount -= amount;
	}
	return newList;
}

int main()
{
	CityList L1("cities1.txt"), L2("cities2.txt"), L3, L4, L5, L6;
	cout << "L1--->\n\n";
	L1.print();
	L3 = L1 + L2;
	L4 = L1 - L2;
	L5 = L1 + 50;
	L6 = L1 - 30;
	cout << "L2--->\n\n";
	L2.print();
	cout << "L3--->\n\n";
	L3.print();
	cout << "L4--->\n\n";
	L4.print();
	cout << "L5--->\n\n";
	L5.print();
	cout << "L6--->\n\n";
	L6.print();
	system("pause");
    return 0;
}


