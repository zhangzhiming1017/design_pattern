#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
//״̬ģʽ:��һ�����������״̬�ı�ʱ������ı�����Ϊ��������������ı�����

//������⣺������һ������״̬ת�����������ʽ���ڸ���ʱ����״̬���ж��߼�ת�Ƶ���ʾ��ͬ״̬��һϵ�����У����԰Ѹ��ӵ��ж��߼��򵥻���
//1.�����ص�״̬����Ϊ�ֲ��������ҽ���ͬ״̬����Ϊ�ָ��
//2.��һ���������Ϊȡ��������״̬ʱ������������������ʱ��������״̬�ı�����Ϊ�����ʱ��͵ÿ�����״̬ģʽ�ˡ�
//����״̬��
class state {
public:
	virtual void stateshow() = 0;

};

class sleep : public state {
public:
	void stateshow() override {
		std::cout << "����˯��" << std::endl;
	}
};


class  work: public state {
public:
	void stateshow() override {
		std::cout << "���ڹ���" << std::endl;
	}
};


class eatFood : public state {
public:
	void stateshow() override {
		std::cout << "���ڳԷ�" << std::endl;
	}
};

class sports : public state {
public:
	void stateshow() override {
		std::cout << "�����˶�" << std::endl;
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