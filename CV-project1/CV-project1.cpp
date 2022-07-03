#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "header.h"

int main()
{
	std::ofstream out;

	out.open("Vehicle.txt", std::ios::trunc);

	if (!out)
	{
		std::cout << "\n\nFAILED TO OPEN THE FILE!\n\n";
		exit(1);
	}

	Vehicle vObj1;
	char nume[30], producer[30];
	int power, capacity, wheels;

	std::cout << "Please enter the data: \n\tName:"; std::cin.getline(nume, 29); vObj1.setName(nume);
	std::cout << "\tProducer: "; std::cin.getline(producer, 29); vObj1.setProducer(producer);
	std::cout << "\tWheels: "; std::cin >> wheels;	vObj1.setWheels(wheels);

	Vehicle vObj2 = vObj1;
	Vehicle cloneObjV(vObj2);

	Car carObj1;
	std::cout << "Please enter the data: \n\tName:"; std::cin.get(); std::cin.getline(nume, 29);
	std::cout << "\tProducer: "; std::cin.getline(producer, 29);
	std::cout << "\tWheels, Power, Capacity: "; std::cin >> wheels >> power >> capacity;
	carObj1.setName(nume); carObj1.setProducer(producer); carObj1.setCapacity(capacity); carObj1.setPower(power);
	carObj1.setWheels(wheels);

	Car carObj2 = carObj1;
	Car cloneObjC(carObj2);

	out << vObj1 << cloneObjV << carObj1 << cloneObjC;

	std::cout << "\n\nVEHICLE OBJECTS: \n";
	vObj1.display();
	vObj2.display();
	cloneObjV.display();

	std::cout << "\n\nCAR OBJECTS: \n";
	carObj1.display();
	carObj2.display();
	cloneObjC.display();

	Vehicle* pVehicle = &vObj1;
	std::cout << "\n\nPlease enter the data: \n\tName:"; std::cin.get(); std::cin.getline(nume, 29); pVehicle->setName(nume);
	std::cout << "\tProducer: "; std::cin.getline(producer, 29);	pVehicle->setProducer(producer);
	std::cout << "\tWheels: "; std::cin >> wheels;
	pVehicle->setWheels(wheels);


	std::cout << "\n\nPointer OBJECT: \n";
	pVehicle->display();

	out << *pVehicle;

	pVehicle = (Vehicle*)&carObj1;

	std::cout << "\n\nPlease enter the data: \n\tName:"; std::cin.get(); std::cin.getline(nume, 29); pVehicle->setName(nume);
	std::cout << "\tProducer: "; std::cin.getline(producer, 29);	pVehicle->setProducer(producer);
	std::cout << "\tWheels, Capacity, Power: "; std::cin >> wheels >> capacity >> power; pVehicle->setWheels(wheels);
	carObj1.setCapacity(capacity); carObj1.setPower(power);
	std::cout << "\n\nPOINTER OBJECT: \n";
	pVehicle->display();

	out << *pVehicle;
	
	return 0;
}