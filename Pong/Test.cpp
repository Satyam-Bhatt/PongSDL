#include <stdio.h>
#include <functional>
#include <math.h>

typedef void(*FunctionPointer)(int a);

typedef unsigned long lg_Un;

using FuncPoint = void(*)(int);
using lg_Un2 = unsigned long long;

class MyClass
{
public:
	MyClass* GetMyClass()
	{
		return this;
	}
	void DoSomethin(int a) 
	{
		printf("Something Print %d\n", a);
	}

};

class SecondClass
{
public:
	void GetMehodFromOtherClass(std::function<void(int)> func)
	{
		func(2);
	}
};

void Heloo(int a)
{
	printf("Heloo %d\n", a);
}

void Heloo2(int a, int b)
{
	printf("Heloo %d\n", a + b);
}

class matrix2x2
{
public:
    float m[2][2];

    matrix2x2()
    {
        m[0][0] = 1; m[0][1] = 0;
        m[1][0] = 0; m[1][1] = 1;
    }
};

//Function Pointer
//int main() {
//
//	lg_Un a = 2;
//	FunctionPointer f = Heloo;
//	f(1);
//
//	MyClass myClass;
//	SecondClass secondClass;
//
//	secondClass.GetMehodFromOtherClass([&myClass](int a) {myClass.DoSomethin(a);});
//
//	return 0;
//}

class Base
{
public:
	virtual ~Base() {}
};

class Derived : public Base
{
public:
	~Derived() {}
};

class Derived2 : public Base
{
public:
	~Derived2() {}
};

//int main() {
//
//	Derived* d = new Derived();
//	Base* b = d;
//
//	Derived * d2 = dynamic_cast<Derived*>(d);
//	if (d2 == NULL)
//	{
//		printf("NULL not possible\n");
//	}
//	else
//	{
//		printf("Success\n");
//	}
//
//	return 0;
//}