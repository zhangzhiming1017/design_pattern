#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
//状态模式:当一个对象的内在状态改变时，允许改变其行为，这个对象看起来改变了类

//解决问题：当控制一个对象状态转换的条件表达式过于复杂时，把状态的判断逻辑转移到表示不同状态的一系列类中，可以把复杂的判断逻辑简单化。
//1.将与特点状态的行为局部化，并且将不同状态的行为分割开。
//2.当一个对象的行为取决于它的状态时，并且它必须在运行时根据它的状态改变其行为，这个时候就得考虑用状态模式了。
//抽象状态类
class state {
public:
	virtual void stateshow() = 0;

};

class sleep : public state {
public:
	void stateshow() override {
		std::cout << "我在睡觉" << std::endl;
	}
};


class  work: public state {
public:
	void stateshow() override {
		std::cout << "我在工作" << std::endl;
	}
};


class eatFood : public state {
public:
	void stateshow() override {
		std::cout << "我在吃饭" << std::endl;
	}
};

class sports : public state {
public:
	void stateshow() override {
		std::cout << "我在运动" << std::endl;
	}
};

class context {
private:
	state * _state;
public:
	void setstate(state * ptr) {
		_state = ptr;
	}

	void show() {
		if (_state) {
			_state->stateshow();
		}
	}

	
};
int main() {
	sleep * _sleep = new sleep();
	work * _work = new work();
	eatFood * eatfood = new eatFood();

	context * _context = new context();
	_context->setstate(_sleep);
	_context->show();
	_context->setstate(_work);
	_context->show();
	_context->setstate(eatfood);
	_context->show();
	sports * _sport = new sports();
	_context->setstate(_sport);
	_context->show();
	return 0;
}