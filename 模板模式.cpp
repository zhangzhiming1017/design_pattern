#include <iostream>
//ģ��ģʽ:����һ�������ֵ��㷨�ĹǼܣ���һ���ֲ����ʵ���ӳٵ����ࡣģ�巽��ʹ��������Բ��ı��㷨�Ľṹ�������¶�����㷨ĳЩ�ض��Ĳ���


class abrastrClass {
public:
	virtual void operatation1() = 0;//������Ϊ�ŵ�����ʵ��
	virtual void operatation2() = 0;

	void TemplateMethod() {//ģ�巽�����������߼��ĹǼܣ������ʵ����������
		operatation1();
		operatation2();
		std::cout << "ģ�巽�����������㷨ִ�еĹǼ�" << std::endl;
	}
};

class specificClass1: public abrastrClass {
public:
	void operatation1() override {
		std::cout << "������1ʵ�ַ���1" << std::endl;
	}
	void operatation2() override {
		std::cout << "������1ʵ�ַ���2" << std::endl;
	}

};

class specificClass2: public abrastrClass {
public:
	void operatation1() override {
		std::cout << "������2ʵ�ַ���1" << std::endl;
	}
	void operatation2() override {
		std::cout << "������2ʵ�ַ���2" << std::endl;
	}

};




	
int main() {
	abrastrClass * pp = new specificClass1();
	pp->TemplateMethod();

	abrastrClass * pa = new specificClass2();
	pa->TemplateMethod();
	
	return 0;
}