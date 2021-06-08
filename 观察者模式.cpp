#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
//观察者模式:定义了一种一对多的关系，让多个观察者对象同时监听某一个主题对象。这个主题对象在状态发生改变时，会通知所有观察者对象，使他们更新自己。
//观察者模式所做的工作其实就是在解耦合，让耦合的各方都依赖于抽象，而不是依赖于具体，从而使得各自的变化不会影响到其他。
//应用场景:当一个对象改变需要同时改变多个对象，而且不知道有多少对象需要改变时，应该考虑用观察者模式
//抽象观察类
//被观察者抽象类
class observeder {
public:
	virtual void show1() = 0;
	virtual void show2() = 0;
};


class zhangzhiming : public observeder {
public:
	void show1() override {
		std::cout << "玩游戏" << std::endl;
	}
	void show2() override {
		std::cout << "工作" << std::endl;
	}


};

class huangxiaojuan : public observeder {
public:

	void show1() override {
		std::cout << "看抖音" << std::endl;
	}
	void show2() override {
		std::cout << "工作" << std::endl;
	}

};


class observer {
public:
	virtual void addObserver(observeder * ptr) = 0;

	virtual void deatch(observeder * ptr) = 0;

	virtual void notify() = 0; 

};


class Friend : public observer {
private:
	std::vector<observeder * > m_ptrobser;
public:
	void addObserver(observeder * ptr) override{
		m_ptrobser.push_back(ptr);
	}

	void deatch(observeder * ptr) override {

	}
	void notify() override {
		std::cout << "老板没回来" << std::endl;
		for (int i = 0; i < m_ptrobser.size(); i++) {
			m_ptrobser[i]->show1();
		}
	}

};

class boss : public observer {
private:
	std::vector<observeder * > m_ptrobser;
public:
	void addObserver(observeder * ptr) override {
		m_ptrobser.push_back(ptr);
	}

	void deatch(observeder * ptr) override {

	}
	void notify() override {
		std::cout << "老板回来了" << std::endl;
		for (int i = 0; i < m_ptrobser.size(); i++) {
			m_ptrobser[i]->show2();
		}
	}

};



int main() {
	observer * obser = new Friend();
	obser->addObserver(new zhangzhiming());
	obser->addObserver(new huangxiaojuan());
	obser->notify();

	observer * obserd = new boss();
	obserd->addObserver(new zhangzhiming());
	obserd->addObserver(new huangxiaojuan());
	obserd->notify();


	return 0;

	
}