#include "pch.h"
#include <string>
#include <iostream>
#include <ctime>
#include <time.h>
#include <conio.h>
#include <fstream>

#define ofmax 20;
using namespace std;

struct datestruct
{
	int dtyear;
	int dtday;
	int dtmonth;
	int dthour;
	int dtmint;
	int dtsec;

};

struct f_user
{
	string Name;
	string SName;
	string User_Name;
	string Epost;
	int BDay;

};

struct file
{
	string file_NamePath;
	int F_Size;
	int Sheet_Number;
	int İmportence_Number;   //if 1 importent_N if not add regulerly

	f_user F_User;

	datestruct DateStruct;

	file* next;
};

struct CircularlyLinkedList
{	
	file* cursor;

	CircularlyLinkedList();
	~CircularlyLinkedList();

	bool empty() const;
	void add(file File);	
	void print();
};

CircularlyLinkedList::CircularlyLinkedList()						
{
	cursor = NULL;
}

CircularlyLinkedList::~CircularlyLinkedList()						
{
	while (!empty()) remove();
}

bool CircularlyLinkedList::empty() const						
{
	return cursor == NULL;
}



void CircularlyLinkedList::add(file File)		
{
	file* f=new file;
	f->file_NamePath = File.file_NamePath;
	f->F_Size = File.F_Size;
	f->Sheet_Number = File.Sheet_Number;
	
	//f->İmportence_Number = importent_N;

	if (cursor == NULL)
	{
		f->next = f;
		cursor = f;
	}
	else
	{
		f->next =cursor->next;
		cursor->next = f;
	}
}

void CircularlyLinkedList::print()
{
	

	if (empty())
	{
		cout << "List is empty ! " << endl;
		return;
	};

	file* file_n =cursor->next;

	while (!(file_n ==cursor))
	{
		cout << " " << file_n->file_NamePath << " " << file_n->F_Size   << " " << file_n->Sheet_Number <<" "<< endl;
		file_n = file_n->next;
	}

	//List last of the path
	cout << " " << file_n->file_NamePath << " " << file_n->F_Size << " " << file_n->Sheet_Number << endl;
}

int main()
{
	
	
	CircularlyLinkedList list;
	file File[10];
	
	string dosyain = "Text.txt";
	ifstream dosya;
	dosya.open(dosyain.c_str());
	int i = 0;

	while (!dosya.eof()) 
	{
		dosya >> File[i].file_NamePath;
		dosya >> File[i].F_Size;
		dosya >> File[i].Sheet_Number;
		list.add(File[i]);
		i++;
	}

	list.print();
	
	::getchar();
	return 0;
}