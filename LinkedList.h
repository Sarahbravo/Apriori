/* ***
*       Author:  Li Jun ZHANG
*  Last Update:  August 4, 2014
*        Class:  CSI-281
*     Filename:  linkedList.h
*
*  Description:
*      This is the template linked list definition.
*
*  Certification of Authenticity:
*     I certify that this assignment is entirely my own work.
**********************************************************************/

#ifndef LINKED_LIST
#define LINKED_LIST

//#include "Header.h"

using namespace std;

template <class T>
class LinkedList
{
	template <class T>
	struct Node
	{
		T    mData;
		Node *mNext;

		/*      Pre:  None
		*     Post:  This object is initialized using default values
		*  Purpose:  To initialize date object
		*************************************************************************/
		Node()
		{
			mData = T();
			mNext = NULL;
		}


		/*      Pre:  None
		*     Post:  This object is initialized using specified data
		*  Purpose:  To intialize date object
		*************************************************************************/
		Node(const T& data)
		{
			mData = data;
			mNext = NULL;
		}

		~Node()
		{

		}

		/*	template <class T>
		struct FNode
		{
		FNode<T>* mNext;
		int mSize;
		int mFrequency;

		FNode(int& size, int& freq)
		{
		mSize = size;
		mFrequency = freq;
		mNext = NULL;
		}

		~FNode()
		{

		}
		};*/

	};

private:
	Node<T> *mHead, *mTail;
	int  mCount;

public:
	LinkedList();
	~LinkedList();

	int  getCount();
	T    getData(int index);
	void setData(int index, T data);

	void clear();

	void display();
	bool insert(T& data);
	bool isEmpty();
	bool isExist(T searchKey);
	T get(int index);
	T remove(T searchKey);
	T removeAt(int index);



	T operator[](int index);
};


/*      Pre:  None
*     Post:  This object is initialized using the default
*  Purpose:  To initialize date object
*****************************************************************************/
template <class T>
LinkedList<T>::LinkedList()
{
	mHead = NULL;
	mTail = NULL;
	mCount = 0;
}


/*      Pre:  None
*     Post:  All the nodes in the list is deleted
*  Purpose:  To remove all the nodes in the list
*****************************************************************************/
template <class T>
LinkedList<T>::~LinkedList()
{
	clear();
}




/*      Pre:  The object is instantiated
*     Post:  The number of nodes in the linked list is returned to the caller
*  Purpose:  To retrieve the number of nodes in the list
*****************************************************************************/
template <class T>
int LinkedList<T>::getCount()
{
	return mCount;
}


/*      Pre:  The list is instantiated and the index is valid
*     Post:  The data in the specified index is returned to the caller
*  Purpose:  To retrieve the specified nodes in the list
*****************************************************************************/
template <class T>
T LinkedList<T>::getData(int index)
{
	Node<T>* temp = mHead;

	for (int i = 0; i < index; i++)
	{
		temp = temp->mNext;
	}
	return temp->mData;
}


/*      Pre:  The list is instantiated, the index is valid and the data is
*            available
*     Post:  The data in the specified index is updated with the specified
*            data
*  Purpose:  To update the specified nodes in the list
*****************************************************************************/
template <class T>
void LinkedList<T>::setData(int index, T data)
{
	Node<T>* temp = mHead;
	for (int i = 0; i < index; i++)
	{
		temp = temp->mNext;
	}

	temp->mData = data;
}

/*      Pre:  The list is initiated
*     Post:  All the nodes in the list is deleted
*  Purpose:  To remove all the nodes in the list
*****************************************************************************/
template <class T>
void LinkedList<T>::clear()
{
	Node<T>* temp = mHead;

	while (mCount > 0)
	{
		temp = mHead;
		mHead = mHead->mNext;
		delete temp;
		mCount--;
	}

	mTail = mHead = NULL;
}



/*      Pre:  The list is instantiated
*     Post:  The entire list is displayed on the screen
*  Purpose:  To show the content of the list
*****************************************************************************/
template <class T>
void LinkedList<T>::display()
{
	Node<T>* temp = mHead;

	cout << "{ ";
	while (temp != NULL)
	{
		cout << temp->mData << " ";
		temp = temp->mNext;
		cout << endl;
	}
	cout << "}";
}


/*      Pre:  The list is instantiated and the data is available
*     Post:  The data is inserted in ascending order
*  Purpose:  To insert a data into the list in ascending order.  However, if
*            the data already existed in the list, it will not be added again
*****************************************************************************/
template <class T>
bool LinkedList<T>::insert(T& data)
{
	Node<T>* n;
	n = new Node<T>(data);


	if (mCount == 0)
	{
		mHead = n;
		mTail = n;
		++mCount;
		return true;
	}
	else if (data <= mHead->mData)
	{
		n->mNext = mHead;
		mHead = n;
		++mCount;
		return true;
	}
	else if (n->mData >= mTail->mData)
	{
		mTail->mNext = n;
		mTail = n;
		++mCount;
		return true;
	}

	else
	{
		Node<T>* next = mHead->mNext;
		Node<T>* previous = mHead;

		while (n->mData > next->mData)
		{
			next = next->mNext;
			previous = previous->mNext;
		}

		previous->mNext = n;
		n->mNext = next;
		++mCount;
		return true;
	}


}



/*      Pre:  The list is instantiated
*     Post:  The function returns true is the list is empty; false otherwise
*  Purpose:  To determine if the list is empty
*****************************************************************************/
template <class T>
bool LinkedList<T>::isEmpty()
{
	if (mHead == NULL)
	{
		return true;
	}

	return false;
}


/*      Pre:  The list is instantiated and the searchKey is available
*     Post:  The function returns true if the search key exists in the list;
*            otherwise false
*  Purpose:  To determine if a specific value exists in the list or not
*****************************************************************************/
template <class T>
bool LinkedList<T>::isExist(T searchKey)
{
	Node<T>* temp = mHead;

	for (int i = 0; i < mCount; i++)
	{
		if (temp->mData == searchKey)
		{
			return true;
		}
		temp = temp->mNext;
	}
	return false;
}

template <class T>
T LinkedList<T>::get(int index){
	Node<T>* node = mHead;
	if (index < 0) index = mCount + 1 + index;
	if (index <= mCount && index > -1){
		int i = 0;
		while (i < index){
			node = node->mNext;
			i++;
		}
	}

	return node->mData;
}


/*      Pre:  The list is instantiated and the searchKey is available
*     Post:  If the searchKey exists, removes it from the list and the
*            function returns true; otherwise the function does nothing
*            and returns false
*  Purpose:  To remove a specific value from the list
*****************************************************************************/
template <class T>
T LinkedList<T>::remove(T searchKey)
{
	Node<T>* temp = mHead;
	T data;

	for (int i = 0; i < mCount; i++)
	{
		if (temp->mNext->mData == searchKey)
		{
			Node<T>* temp2;
			temp2 = temp->mNext;
			temp->mNext = temp2->mNext;
			data = temp2->mData;
			delete temp2;

			mCount--;


		}
		temp = temp->mNext;
	}
	return data;
}


/*      Pre:  The list is instantiated and the index is valid
*     Post:  Remove the element in the specified index location and returns
*            its content to the caller.  If the index location is invalid, the
*            function returns the default value
*  Purpose:  To remove an item in the specified index location
*****************************************************************************/
template <class T>
T LinkedList<T>::removeAt(int index)
{
	Node<T>* temp = mHead;
	T data;

	if (index == 0)
	{
		mHead = temp->mNext;
		data = temp->mData;
		delete temp;
		mCount--;
	}
	else if (index == mCount - 1)
	{
		for (int i = 0; i < mCount - 1; i++)
		{
			temp = temp->mNext;
		}

		mTail = temp;
		data = temp->mNext->mData;
		delete temp->mNext;
		mCount--;
		temp->mNext = NULL;
	}
	else
	{
		for (int i = 0; i < index - 1; i++)
		{
			temp = temp->mNext;
		}
		Node<T>* temp2;
		temp2 = temp;
		temp = temp->mNext;
		temp2->mNext = temp->mNext;
		mCount--;
		data = temp->mData;
		delete temp;
	}
	return data;
}


/*      Pre:  The list is instantiated and the index is valid
*     Post:  The data in the specified index is returned to the caller
*  Purpose:  To retrieve the specified nodes in the list using [] operator
*****************************************************************************/
template <class T>
T LinkedList<T>::operator[](int index)
{
	return getData(index);
}






#endif