#include <iostream>
#include <string>
//װ����ģʽ:��̬�ظ�һ���������һЩ�����ְ�𡣾͹�����˵��װ����ģʽ�������������������

//�����ڶ�̬��Ӷ���
//װ�κͱ�װ�εĳ�����
//����һ������ı�װ���࣬װ��ģʽ��Ŀ�ľ���Ϊ�˸��������̬�����ְ���ȶ���һЩͨ�õĽӿ�
class Compoent {
public:
	virtual void operation() = 0;
};

//����ı�װ����

class Dog : public Compoent { //����װ��
public:
	void operation() override {
		std::cout << "����һ����" << std::endl;
	}
};
class Cat : public Compoent { //��èװ��
public:
	void operation() override {//�Ծ������Ĳ���
		std::cout << "����һֻè" << std::endl;
	}
};


//װ�γ�����

class decorator : public Compoent {
protected:
	Compoent * m_Compoent;

public:
	void setCompoent(Compoent * ptr) {
		m_Compoent = ptr;
	}
	void operation() override {
		if (m_Compoent) {
			m_Compoent->operation();
		}
	}

};

//װ�ξ�����

class clothesA : public decorator {
private:
	std::string state;//װ�ξ�����A���еĹ���
public:

	void operation() override{
		
		m_Compoent->operation();//��ִ�б�װ����Ĺ���
		//��ִ��װ����Ĺ���
		std::cout << "������clothesA" << std::endl;


	}
};

class clothesB : public decorator {
private:
	std::string state;//װ�ξ�����B���еĹ���
public:

	void operation() override {
		m_Compoent->operation();//��ִ�б�װ����Ĺ���
		//��ִ��װ����Ĺ���
		std::cout << "������clothesB" << std::endl;


	}
};







	
int main() {
	Compoent * dog = new Dog();
	Compoent * cat = new Cat();

	clothesA * _clothesA = new clothesA();
	clothesB * _clothesB = new clothesB();

	_clothesA->setCompoent(dog);
	_clothesB->setCompoent(dog);
	_clothesA->operation();
	_clothesB->operation();

	_clothesA->setCompoent(cat);
	_clothesB->setCompoent(cat);

	_clothesA->operation();
	_clothesB->operation();
	


	
	return 0;
}