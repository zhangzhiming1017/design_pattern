#include <iostream>
//����ģʽ�������㷨���壬���ֱ��װ������������֮����Ի����滻��ʹ�㷨�ı仯����Ӱ��Ŀͻ���ʹ�á�
//��򵥹���ģʽ�ṹ�����ƣ�����򵥹���ģʽ���������룬����ģʽ�ȽϹ�ע���ض���Ĵ�����������ģʽ�Ͼ���ע�㷨���Ի���������������㷨������Ҫ�Ķ�ԭ���롣
enum class strategyType:int { NORMAL = 0, DISCOUNT=1,REBATE =2};
class strategy {
public:
	virtual void shell() = 0;
};

class normalStrategy : public strategy { // �����շ�
public:
	void shell() override {
		std::cout << "ʵ�������շ� " << std::endl;

	}
};

class discountStrategy : public strategy { // �����շ�
public:
	void shell() override {
		std::cout << "ʵ�ִ����շ� " << std::endl;
	}
};

class rebateStrategy : public strategy {//�����շ�
public:
	void shell() override {
		std::cout << "ʵ�ַ����շ� " << std::endl;
	}
};

class context {
private:
	strategy * pp = NULL;
public:
	 context(strategy * ee) {
		this->pp = ee;
		
	 }

	 void show() {
		 if (pp) {
			 pp->shell();
		 }
	 }

};




	
int main() {
	context * a = new context(new normalStrategy());
	a->show();
	context * b = new context(new discountStrategy());
	b->show();
	context * c = new context(new rebateStrategy());
	c->show();
	
	
	return 0;
}