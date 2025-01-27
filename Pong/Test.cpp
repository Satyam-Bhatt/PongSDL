#include <stdio.h>
#include <functional>

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