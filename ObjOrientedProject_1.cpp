#include "pch.h"
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

struct file
{
	string file_NamePath;
	string F_Type;
	int F_Size;
	int Sheet_Number;

	file* next;
};

struct f_user
{
	string Name;
	string SName;
	string User_Name;
	string Epost;
	int BDay;

	f_user* next;
};

struct datestruct
{
	int dtyear;
	int dtday;
	int dtmonth;
	int dthour;
	int dtmint;
	int dtsec;

};


struct ArrayofStruct
{
	f_user* F_User = new f_user;
	file* File = new file;
	datestruct* DateStruct = new datestruct;

	ArrayofStruct* next;
};

struct CircularlyLinkedList
{

	ArrayofStruct* curser_ArrayofStruct;
	CircularlyLinkedList();
	~CircularlyLinkedList();

	bool empty() const;
	const string& front() const;
	const string& back() const;
	void advance();
	void add(const int& i, const string& e, const string& btipi, const int ysayi);	// add after cursor
	void remove();								// delete curser_ArrayofStruct->next
	void print();
};

CircularlyLinkedList::CircularlyLinkedList()						
{
	curser_ArrayofStruct = NULL;
}

CircularlyLinkedList::~CircularlyLinkedList()						
{
	while (!empty()) remove();
}

bool CircularlyLinkedList::empty() const						
{
	return curser_ArrayofStruct == NULL;
}

const string& CircularlyLinkedList::front() const					
{
	return curser_ArrayofStruct->next->File->file_NamePath;
}

const string& CircularlyLinkedList::back() const					
{
	return curser_ArrayofStruct->File->file_NamePath;
}

void CircularlyLinkedList::advance()								
{
	curser_ArrayofStruct = curser_ArrayofStruct->next;
}



void CircularlyLinkedList::add(const int& i, const string& e, const string& btipi, const int ysayi)		// add after cursor
{
	ArrayofStruct* f = new ArrayofStruct;
	f->File->file_NamePath = e;

	f->File->F_Size = i;
	f->File->F_Type = btipi;
	f->File->Sheet_Number = ysayi;

	if (curser_ArrayofStruct == NULL)
	{
		f->next = f;
		curser_ArrayofStruct = f;
	}
	else
	{
		f->next = curser_ArrayofStruct->next;
		curser_ArrayofStruct->next = f;
	}
}

void CircularlyLinkedList::remove()									// remove node after cursor
{
	if (empty())
	{
		cout << "List is empty ! " << endl;
		return;
	};

	ArrayofStruct* temp = curser_ArrayofStruct->next;							// the node being removed

	if (temp == curser_ArrayofStruct) 											
		curser_ArrayofStruct = NULL;												// list is now empty
	else
		curser_ArrayofStruct->next = temp->next;									// link out the old node

	delete temp;													// delete the old node
}






void CircularlyLinkedList::print()
{
	if (empty())
	{
		cout << "List is empty ! " << endl;
		return;
	};

	ArrayofStruct* arrayofstruct = curser_ArrayofStruct->next;

	while (!(arrayofstruct == curser_ArrayofStruct))
	{
		cout << "File Size : " << arrayofstruct->File->F_Size << " file Name : " << arrayofstruct->File->file_NamePath << " file Type : " << arrayofstruct->File->F_Type << " Number of Sheets : " << arrayofstruct->File->Sheet_Number << endl;
		arrayofstruct = arrayofstruct->next;
	}

	//List last of the path
	cout << "File Size : " << arrayofstruct->File->F_Size << " file Name : " << arrayofstruct->File->file_NamePath << " file Type : " << arrayofstruct->File->F_Type << " Number of Sheets : " << arrayofstruct->File->Sheet_Number << endl;
}

int main()
{
	string Name, SName, U_Name, Epost;

	string b_Nameyl, F_Type;

	CircularlyLinkedList list[2];
	list[0].add(2000, "File", "A4", 20);
	list[1].add(3000, "File2", "A3", 21);
	//list.add(2000, "File", "A4", 20);

	for (int i = 0; i < 2; i++)
	{
		list[i].print();

	}
	//list[i].print();


	::getchar();
	return 0;
}