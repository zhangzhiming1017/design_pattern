#include <iostream>
#include <string>
//����¼ģʽ:�ڲ��ƻ���װ�Ե�����£�����һ��������ڲ�״̬�����ڶ���֮�Ᵽ�����״̬�������Ϳ��Խ�����ָ���ԭ�ȱ����״̬��
class memory;
class Originator;
class caretake;

class memory {//����¼��
public:
	memory(std::string sate) :state(sate) {

	}
	std::string getState() {
		return state;
	}
private:
	std::string  state;
};
class Originator {//������
public:
	Originator(std::string tate) :state(tate) {

	}
	memory *CreateMemory() {//��������¼
		return new memory(state);
	}
	void setMemory(memory memen) {//�ָ�����¼���������������
		state = memen.getState();
	}

	void setState(std::string e) {
		state = e;
	}

	void show() {
		std::cout <<"state = "<< state << std::endl;
	}

private:
	std::string state; //��Ҫ�����״̬

};

class caretake{ //������
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
	pp->show();//��ʼ��״̬

	caretake * care = new caretake();
	care->setMemory(pp->CreateMemory());//����״̬

	pp->setState("OFF");
	pp->show();//����״̬

	std::cout << care->getMemory().getState() << std::endl;//�����ֵ

	pp->setMemory(care->getMemory());
	pp->show();//�ָ�״̬

	


	
	return 0;
}