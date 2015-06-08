#include <iostream> 

using namespace std;

#ifndef TRANSACTION_H
#define TRANSACTION_H

class Transaction
{
private:
	int* mItems;
	int mTransID;
	int mCapacity;
	int mTop;

public:
	Transaction();
	Transaction(int id, int capacity);
	~Transaction();
	int getCapacity();
	int getID();
	void insert(int& item);
	bool isFull();
	int& operator[](const int index);

	bool operator<(Transaction& rhs);
	bool operator>(Transaction& lhs);
	bool Transaction::operator<=(Transaction& rhs);
	bool Transaction::operator>=(Transaction& rhs);
	friend ostream& operator<<(ostream& str, Transaction& rhs);
};

#endif