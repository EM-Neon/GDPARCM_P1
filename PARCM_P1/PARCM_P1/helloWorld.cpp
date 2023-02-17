#include "helloWorld.h"
#include <iostream>
#include <string>
#include <vector>

helloWorld::helloWorld(int id, int numToCheck, int threadCount)
{
	this->id = id;
	this->numToCheck = numToCheck;
	this->threadCount = threadCount;

	std::string str = "Creating thread: " + std::to_string(id) + "\n";
	std::cout << str;
}

helloWorld::~helloWorld()
{
	std::string str = "Destroying thread: " + std::to_string(id) + "\n";
	std::cout << str;
}

void helloWorld::dismiss()
{
	delete this;
}

void helloWorld::run()
{
	isRunning = true;
	std::cout << "Thread is running\n";

	/*int i = id + 2;

	std::cout << "inputting numbers\n";
	while (i < numToCheck)
	{
		list.push_back(i);
		i += threadCount;
	}*/

	int x = id+1;

	std::cout << "solving\n";

	int i = numToCheck - x;
	while(i > 1)
	{
		/*std::string string = std::to_string(id) + ": " + std::to_string(i) + "\n";
		std::cout << string;*/

		if(numToCheck % i == 0)
		{
			isPrime = false;

			std::string str = "Thread is " + std::to_string(isPrime) + ": " + std::to_string(numToCheck) + "/" + std::to_string(i) + "\n";

			std::cout << str;
			/*std::cout << isPrime << std::endl;*/

			break;
		}

		i -= threadCount;

		//IETThread::sleep(500);
	}

	isRunning = false;
}
