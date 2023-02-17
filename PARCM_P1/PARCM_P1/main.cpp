#include <iomanip>

#include "iostream"
#include <windows.h>

#include "CalculationThread.h"
#include "time.h"

#include "helloWorld.h"


const int maxNum = 2147483647;
int numToCheck = -1;
bool isPrime = true;
int threadCount = 4;
bool isDone = false;

bool isUsingThreads = true;

std::vector<CalculationThread*> threadList;
std::vector<helloWorld*> helloList;

void main()
{
	//hello.start();

	clock_t start, end;

	std::cout << "Give a number to check for prime bitch: ";
	std::cin >> numToCheck;

	std::cout << "Calculating bitch... \n";

	start = clock();

	//Sleep(1000);


	// this is for not using threads
	if(!isUsingThreads)
	{
		for (int i = numToCheck - 1; i > 1; i--)
		{
			if (numToCheck % i == 0)
			{
				isPrime = false;
				break;
			}
		}
	}


	//this is for using threads
	else if(isUsingThreads)
	{
		for(int i = 0; i < threadCount; i++)
		{
			helloWorld* helloThread = new helloWorld(i, numToCheck, threadCount);
			helloList.push_back(helloThread);
			helloThread->start();
		}

		std::cout << "Using threads \n";
		/*for (int i = 0; i < threadCount; i++)
		{
			CalculationThread* thread = new CalculationThread(i , numToCheck, threadCount);
			threadList.push_back(thread);
			thread->start();
		}*/

		while (isDone == false)
		{
			isDone = true;
			//cout << "Checking if still running\n";

			for (auto thread:helloList)
			{
				if(thread->isRunning)
				{
					isDone = false;
					break;
				}
			}

			for (auto thread : helloList)
			{
				if (thread->isPrime == false)
				{
					isPrime = false;
					isDone = true;
					break;
				}
			}
		}
	}
	

	end = clock();

	for(auto thread:helloList)
	{
		thread->dismiss();
	}

	if(isPrime)
	{
		std::cout << numToCheck << " is a prime number bitch \n";
	}
	else
	{
		std::cout << numToCheck << " is not a prime number bitch \n";
	}

	

	double time_taken = double(end - start) / double (CLOCKS_PER_SEC);
	std::cout << "Time taken by program is: " << std::fixed << time_taken << std::setprecision(5);
	std::cout << " sec " << std::endl;
}