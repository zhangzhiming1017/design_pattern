#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
//���ģʽ:Ϊ��ϵͳ�е�һ��ӿ��ṩһ��һ�µĽ��棬��ģʽ������һ���߲�ӿڣ�����ӿ�ʹ����һ��ϵͳ��������ʹ��

//��ʱʹ�����ģʽ
//1.����Ƴ��ڽ׶Σ�Ӧ��Ҫ����ʶ�ؽ���ͬ�����������
//2.�ڿ����׶Σ���ϵͳ��Ϊ�����ع��ݻ����Խ��Խ���ӣ��������facede�����ṩһ���򵥵Ľӿڣ��������ǵ�����
//3.��ά��һ�������ô���ϵͳʱ���������ϵͳ�Ѿ��������ά������չ�ˣ�Ϊ��ϵͳ����һ�����facede�࣬����ϵͳ������ཻ������������ϵͳ������

class subsystemOne { //��ϵͳ�������ϣ�����Ҫ֪��facade����κ���Ϣ
public:
	void MethodOne() {
		std::cout << "��ϵͳ����һ" << std::endl;
	}
};

class subsystemTwo {
public:
	void MethodTwo() {
		std::cout << "��ϵͳ������" << std::endl;
	}
};


class subsystemThree {
public:
	void MethodThree() {
		std::cout << "��ϵͳ������" << std::endl;
	}
};


class subsystemFour {
public:
	void MethodFour() {
		std::cout << "��ϵͳ������" << std::endl;
	}
};

class Facade {//����࣬����Ҫ֪��������ϵͳ�ķ��������ԣ�������ϣ��Ա�������
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
		 std::cout << "������A -------" << std::endl;
		 one->MethodOne();
		 three->MethodThree();

	}
	 void MethodB() {
		 std::cout << "������B --------" << std::endl;
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