#include <iostream>
using namespace std;

class MyClass
{
private:
	int var1;
public:
	MyClass()
	{
		var1 = 0;
		cout << "MyClass Default Constructor." << endl;
	}

	~MyClass()
	{
		cout << "Destructor Invoked" << endl;
	}

	MyClass(int i)
	{
		var1 = i;
		cout << "MyClass Constructor." << endl;
	}

	void setVar(int i)
	{
		var1 = i;
	}

	int getVar()
	{
		return var1;
	}
};

void main()
{
	MyClass* clsptr = new MyClass[3* sizeof(MyClass)];
	
	cout << "==============================" << endl;
	
	new(clsptr) MyClass(5);
	new(clsptr+1) MyClass(15);
	new(clsptr+2) MyClass(35);
	cout << "3 Objects of type MyClass was created with 5, 15 and 35 as input" << endl;
	cout << "=============================" << endl;
	cout << endl;
	cout << "clsptr->getVar() = " << clsptr->getVar() << endl;
	cout << "clsptr+1->getVar() = " << (clsptr+1)->getVar() << endl;
	cout << "clsptr+2->getVar() = " << (clsptr+2)->getVar() << endl;

	//in order to delete, you just invoke the destructor 
	cout << "clsptr[1].~MyClass();" << endl;
	clsptr[1].~MyClass();

	//now you can add a new item
	
	cout << "new(clsptr) MyClass(222);" << endl;
	new(clsptr) MyClass(222);
	cout << "clsptr->getVar();" << endl;
	cout << "clsptr->getVar() = " << clsptr->getVar() << endl;
	
};