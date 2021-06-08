#include <iostream>
#include <string>
//备忘录模式:在不破坏封装性的情况下，捕获一个对象的内部状态，并在对象之外保存这个状态。这样就可以将对象恢复到原先保存的状态的
class memory;
class Originator;
class caretake;

class memory {//备忘录类
public:
	memory(std::string sate) :state(sate) {

	}
	std::string getState() {
		return state;
	}
private:
	std::string  state;
};
class Originator {//发起类
public:
	Originator(std::string tate) :state(tate) {

	}
	memory *CreateMemory() {//创建备忘录
		return new memory(state);
	}
	void setMemory(memory memen) {//恢复备忘录，并导入相关数据
		state = memen.getState();
	}

	void setState(std::string e) {
		state = e;
	}

	void show() {
		std::cout <<"state = "<< state << std::endl;
	}

private:
	std::string state; //需要保存的状态

};

class caretake{ //管理备份
private:
	memory * memento;
public:
	caretake() {

	}
	void setMemory( memory *  e) {
		memento = e;

	}
	memory getMemory() {
		return *memento;
	}
};





	
int main() {
	Originator * pp = new Originator("ON");
	pp->show();//初始化状态

	caretake * care = new caretake();
	care->setMemory(pp->CreateMemory());//保存状态

	pp->setState("OFF");
	pp->show();//更改状态

	std::cout << care->getMemory().getState() << std::endl;//保存的值

	pp->setMemory(care->getMemory());
	pp->show();//恢复状态

	


	
	return 0;
}