#include <iostream>
#include<Windows.h>
#include"abonent.h"

using namespace std;

int main(){
	const char* name1[]{ "RRRR" };

PhoneBook pb;
pb.add("Petrov Petr", "1234", "8901231456","OOO MEGAFON");
pb.add("Sidorov Oleg", "4567","8976542267","OAO TELE2");
pb.add("Ivanov Ivan", "1325","8906543288","OOO BEELINE");
pb.add("Smirnov Fedor", "9829","8976432356","OAO MTC");
pb.show();
pb.write("pb.txt");


}