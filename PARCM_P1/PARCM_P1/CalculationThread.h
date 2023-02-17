#pragma once
#include "IETThread.h"
#include <vector>

class CalculationThread: public IETThread
{
private:
	typedef std::string String;
public:
	CalculationThread(int id, int numToCheck, int threadCount);
	~CalculationThread();

private:
	void run() override;

	int id;
	int numToCheck;
	int threadCount;

	
public:
	bool isPrime = true;
	bool isRunning;

	std::vector<int> list;
};

