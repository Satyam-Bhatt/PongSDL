#include <stdio.h>
#include <functional>

typedef void(*FunctionPointer)(int a);

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

//int main() {
//	MyClass myClass;
//	SecondClass secondClass;
//
//	secondClass.GetMehodFromOtherClass([&myClass](int a) {myClass.DoSomethin(a);});
//
//	return 0;
//}