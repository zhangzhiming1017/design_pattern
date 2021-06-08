#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
//外观模式:为子系统中的一组接口提供一个一致的界面，此模式定义了一个高层接口，这个接口使得这一子系统更加容易使用

//何时使用外观模式
//1.在设计初期阶段，应该要有意识地将不同的两个层分离
//2.在开发阶段，子系统因为不断重构演化变得越来越复杂，增加外观facede可以提供一个简单的接口，减少他们的依赖
//3.在维护一个遗留得大型系统时，可能这个系统已经变得难以维护和扩展了，为新系统开发一个外观facede类，让新系统与外观类交互，外观类与旧系统交互。

class subsystemOne { //子系统方法集合，不需要知道facade类的任何信息
public:
	void MethodOne() {
		std::cout << "子系统方法一" << std::endl;
	}
};

class subsystemTwo {
public:
	void MethodTwo() {
		std::cout << "子系统方法二" << std::endl;
	}
};


class subsystemThree {
public:
	void MethodThree() {
		std::cout << "子系统方法三" << std::endl;
	}
};


class subsystemFour {
public:
	void MethodFour() {
		std::cout << "子系统方法四" << std::endl;
	}
};

class Facade {//外观类，它需要知道所有子系统的方法或属性，进行组合，以备外界调用
private:
	subsystemOne* one = NULL;
	subsystemTwo *two = NULL;
	subsystemThree* three = NULL;
	subsystemFour *four = NULL;
public:
	Facade() {
		one = new subsystemOne();
		two = new subsystemTwo();
		three = new subsystemThree();
		four = new subsystemFour();
	}

	 void MethodA() { 
		 std::cout << "方法组A -------" << std::endl;
		 one->MethodOne();
		 three->MethodThree();

	}
	 void MethodB() {
		 std::cout << "方法组B --------" << std::endl;
		 two->MethodTwo();
		 four->MethodFour();

	 }
};
	
int main() {
	Facade* facede = new Facade();
	facede->MethodA();
	facede->MethodB();

	
	return 0;
}