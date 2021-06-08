#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
//�۲���ģʽ:������һ��һ�Զ�Ĺ�ϵ���ö���۲��߶���ͬʱ����ĳһ���������������������״̬�����ı�ʱ����֪ͨ���й۲��߶���ʹ���Ǹ����Լ���
//�۲���ģʽ�����Ĺ�����ʵ�����ڽ���ϣ�����ϵĸ����������ڳ��󣬶����������ھ��壬�Ӷ�ʹ�ø��Եı仯����Ӱ�쵽������
//Ӧ�ó���:��һ������ı���Ҫͬʱ�ı������󣬶��Ҳ�֪���ж��ٶ�����Ҫ�ı�ʱ��Ӧ�ÿ����ù۲���ģʽ
//����۲���
//���۲��߳�����
class observeder {
public:
	virtual void show1() = 0;
	virtual void show2() = 0;
};


class zhangzhiming : public observeder {
public:
	void show1() override {
		std::cout << "����Ϸ" << std::endl;
	}
	void show2() override {
		std::cout << "����" << std::endl;
	}


};

class huangxiaojuan : public observeder {
public:

	void show1() override {
		std::cout << "������" << std::endl;
	}
	void show2() override {
		std::cout << "����" << std::endl;
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
		std::cout << "�ϰ�û����" << std::endl;
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
		std::cout << "�ϰ������" << std::endl;
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