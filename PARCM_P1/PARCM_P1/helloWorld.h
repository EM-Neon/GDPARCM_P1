#pragma once
#include "IETThread.h"

class helloWorld: public IETThread
{
private:
	typedef std::string String;
public:
	helloWorld(int id, int numToCheck, int threadCount);
	~helloWorld();
	void dismiss();

private:
	void run() override;

	int id;
	int numToCheck;
	int threadCount;

public:
	bool isPrime = true;
	bool isRunning;
};

