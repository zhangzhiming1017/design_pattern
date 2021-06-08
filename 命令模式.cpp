#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
//����ģʽ:��һ�������װΪһ�����󣬴Ӷ�ʹ����ò�ͬ������Կͻ����в��������������Ŷӻ��¼������־���Լ�֧�ֿɳ����Ĳ���

//����ģʽ������:
//1.�ܹ��������һ���������
//2.����Ҫ������£����Խ����׵ؽ����������־
//3.������������һ�������Ƿ�Ҫ�������
//4.�������׵�ʵ�ֶ�����ĳ���������
//5.���ڼӽ��µľ��������಻Ӱ���������࣬��������µľ��������������

//����ģʽ������һ�������Ķ�����֪����ôִ��һ�������Ķ���ָ
//���ݿ���ԭ�򣺲�ҪΪ������ӻ��ڲ²�ġ�ʵ�ʲ���Ҫ�Ĺ��ܡ�

class Recevier { //���������
public:
	void Action() {
		std::cout << "ִ������" << std::endl;
	}

};

class Command {//����������
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
		std::cout << "������";
		m_recevier->Action();
	}

};
class kaoyangrou : public Command {
public:
	kaoyangrou(Recevier * ptr) :Command(ptr) {

	}

	void Execute() override {
		std::cout << "������";
		m_recevier->Action();
	}
};

class kaojitui : public Command {
public:
	kaojitui(Recevier * ptr) :Command(ptr) {

	}

	void Execute() override {
		std::cout << "������";
		m_recevier->Action();
	}
};

class Invoker { //ִ��������
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