/* ***
*       Author:  Li Jun ZHANG
*  Last Update:  August 4, 2014
*        Class:  CSI-281
*     Filename:  ItemsetList.h
*
*  Description:
*      This is the template linked list definition.
*
*  Certification of Authenticity:
*     I certify that this assignment is entirely my own work.
**********************************************************************/

#ifndef ITEMSET_LIST
#define ITEMSET_LIST
#include "Transaction.h"
#include "LinkedList.h"

using namespace std;

class ItemsetList
{
	template <typename T>
	struct DNode
	{
		DNode<T>* mNext;
		int mFrequency;
		LinkedList<T> mItems;


		/*      Pre:  None
		*     Post:  This object is initialized using default values
		*  Purpose:  To initialize date object
		*************************************************************************/
		DNode()
		{
			mFrequency = 0; 
			mNext = NULL;
		}

		~DNode()
		{
			mItems.clear();
		}

		T& operator[](int& index)
		{
			return mItems[index];
		} 
		
		int getCount()
		{
			return mItems.getCount();
		}

		void insert(T& data)
		{
			mItems.insert(data);
		}

		friend ostream& operator<<(ostream& str, DNode<T>& rhs)
		{
			str << mItems; 
			return str;
		}

		
	};

private:
	DNode<int> *mHead, *mTail;
	int  mCount;

public:
	ItemsetList();
	~ItemsetList();

	int  getCount();
	int    getData(int index);
	void setData(int index, int data);

	void clear();
	void display();
	bool insert(LinkedList<int>& list);
	bool isEmpty();
	bool isExist(int searchKey);
	int get(int index);
	void removeAt(int index);
	void kPlusOneItemset(ItemsetList& Itemset, bool& isFinished, double& s);
	void sizeOneItemset(LinkedList<Transaction>& transactionList);
	
	ItemsetList::DNode<int>* ItemsetList::operator[](int& index);

	friend void prune(ItemsetList& list, double s);
	friend bool findSubsets(ItemsetList& Itemset, LinkedList<int>& set);
};

#endif