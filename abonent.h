#pragma once
#pragma once
#include <iostream>
#include<Windows.h>
#include<fstream>

using namespace std;
class Abonent
{
	const char* name;
	const char* phone;
	const char* mobile_phone;
	const char* place_of_work;
public:
	Abonent() {}
	Abonent(const char* name, const char* phone, const char* mobile_phone,const char* place_of_work) ://Конструктор
		name{ name },
		phone{ phone }, mobile_phone{ mobile_phone }, place_of_work{place_of_work} {
		this->name = name;
		this->phone = phone;
		this->mobile_phone = mobile_phone;
		this->place_of_work = place_of_work;
	}
	~Abonent() {} //Деструктор - очищает память
	const char* getName() {
		return name;
	}
	const char* getPhone() {
		return phone;
	}
	const char* getMobilePhone() {
		return mobile_phone;
	}
	const char* getWork() {
		return place_of_work;
	}
};

class PhoneBook {
	Abonent* abonents;
	int size = 0;
public:
	PhoneBook() {};
	PhoneBook(const char* filename) {
		read(filename);
	};
	void add(const char* name, const char* phone, const char* mobile_phone, const char* place_of_work) {
		Abonent abon(name, phone,mobile_phone,place_of_work);
		Abonent* buff = new Abonent[size + 1];
		for (int i = 0; i < size; i++)
			buff[i] = abonents[i];

		buff[size] = abon;
		delete[] abonents;
		abonents = buff;
		size++;
	}
	void write(const char* filename) {//записать в файл
		ofstream fout(filename);
		for (int i = 0; i < size; i++) {
			fout << abonents[i].getName() << " " << abonents[i].getPhone() <<" " << abonents[i].getMobilePhone() <<" " << abonents[i].getWork() << endl;
		}
		fout.close();
	}
	void read(const char* filename) {
		ifstream fin(filename);
		if (fin.is_open()) {
			string name, phone,mobile_phone, place_of_work;
			while (!fin.eof()) {
				fin >> name;
				fin >> phone;
				fin >> mobile_phone;
				fin >> place_of_work;
				add(name.data(), phone.data(),mobile_phone.data(),place_of_work.data()); //что бы string преобр в char
				//cout << name.data() << " " << phone.data()<<endl;
			}
			fin.close();
		}

	}
	inline void show() {
		for (int i = 0; i < size; i++)
			cout << abonents[i].getName() << " " << abonents[i].getPhone() << " " << abonents[i].getMobilePhone() << " " << abonents[i].getWork() <<"\n" << endl;
	}
	~PhoneBook() {
		delete[] abonents;
	}
};



