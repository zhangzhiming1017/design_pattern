#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
//命令模式:将一个请求封装为一个对象，从而使你可用不同的请求对客户进行参数化；对请求排队或记录请求日志，以及支持可撤消的操作

//命令模式的作用:
//1.能够容易设计一个命令队列
//2.在需要的情况下，可以较容易地将命令记入日志
//3.允许接收请求的一方决定是否要否决请求
//4.可以容易地实现对请求的撤销和重做
//5.由于加进新的具体命令类不影响其他的类，因此增加新的具体命令类很容易

//命令模式把请求一个操作的对象与知道怎么执行一个操作的对象分割开
//敏捷开发原则：不要为代码添加基于猜测的、实际不需要的功能。

class Recevier { //命令接收者
public:
	void Action() {
		std::cout << "执行请求" << std::endl;
	}

};

class Command {//抽象命令类
protected:
	Recevier * m_recevier = NULL;

public:
	Command(Recevier * ptr = NULL) {
		m_recevier = ptr;
	}

	virtual void Execute() = 0;

	
};

class kaojichi : public Command {
public:
	kaojichi(Recevier * ptr) :Command(ptr) {

	}

	void Execute() override {
		std::cout << "烤鸡翅";
		m_recevier->Action();
	}

};
class kaoyangrou : public Command {
public:
	kaoyangrou(Recevier * ptr) :Command(ptr) {

	}

	void Execute() override {
		std::cout << "烤羊肉";
		m_recevier->Action();
	}
};

class kaojitui : public Command {
public:
	kaojitui(Recevier * ptr) :Command(ptr) {

	}

	void Execute() override {
		std::cout << "烤鸡腿";
		m_recevier->Action();
	}
};

class Invoker { //执行命令类
private:
	Command* command = NULL;
public:
	void setComman(Command* ptr) {
		command = ptr;
	}
	 void ExecuteCommand() {
		command->Execute();
	}
};



	
int main() {
	Invoker* _invoker = new Invoker();
	Recevier * _recevier = new Recevier();

	kaojichi * _kaojichi = new kaojichi(_recevier);
	kaojitui * _kaojitui = new kaojitui(_recevier);
	kaoyangrou * _kaoyangrou = new kaoyangrou(_recevier);

	_invoker->setComman(_kaojichi);
	_invoker->ExecuteCommand();
	
	_invoker->setComman(_kaojitui);
	_invoker->ExecuteCommand();

	_invoker->setComman(_kaoyangrou);
	_invoker->ExecuteCommand();
	return 0;
}