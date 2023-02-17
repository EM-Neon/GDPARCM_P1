#include "CalculationThread.h"
#include <iostream>

CalculationThread::CalculationThread(int id, int numToCheck, int threadCount)
{
	this->id = id;
	this->numToCheck = numToCheck;
	this->threadCount = threadCount;

	

	std::cout << "Creating thread: " << id << std::endl;
}

CalculationThread::~CalculationThread()
{
	std::cout << "Destroying thread: " << id << std::endl;
}

void CalculationThread::run()
{
	isRunning = true;
	IETThread::sleep(1000);

	std::cout << "Thread: " << id << " is running.\n";

	//do calculations here

	int i = id + 2;

	while (i < numToCheck)
	{
		list.push_back(i);
		i += threadCount;
	}

	for(auto num:list)
	{
		//check here
		if(numToCheck % num == 0)
		{
			isPrime = false;
			break;
		}
	}

	isRunning = false;
}
