#include <iostream>
#include <string>
//�Ž�ģʽ�������󲿷�������ʵ�ֲ��ַ��룬ʹ���Ƕ����Զ����ر仯.

//Ӧ�ó�����
//1�����һ��ϵͳ��Ҫ�ڹ����ĳ��󻯽�ɫ�;��廯��ɫ֮�����Ӹ��������ԣ��������������֮�佨����̬����ϵ��
//2�����Ҫ��ʵ�ֻ���ɫ���κθı䲻Ӧ��Ӱ��ͻ��ˣ�����˵ʵ�ֻ���ɫ�ĸı�Կͻ�������ȫ͸���ġ�
//3��һ�������ж���һ���ĳ��󻯽�ɫ��ʵ�ֻ���ɫ��ϵͳ��Ҫ����֮����ж�̬��ϡ�
//·��
class road {
public:
	virtual void Run() = 0;
};

class heightWalk : public road {
public:
	void Run() override {
		std::cout << "�ڸ��ٹ�·��ʻ" << std::endl;
	}
};

class commonWalk : public road {
public:
	void Run() override {
		std::cout << "��������·��ʻ" << std::endl;
	}
};
//����
class car {
protected:
	road * m_road;
public:
	void setRoad(road * ptr) {
		m_road = ptr;

	}
	virtual void Run() = 0;
};

class bus : public car {
public:
	void Run() override {
		if (m_road) {
			std::cout << "��������";
			m_road->Run();
		}
		

	}
};

class saloon_car : public car {
public:
	void Run() override {
		if (m_road) {
			std::cout << "С�γ�";
			m_road->Run();
		}
	}
};

//����
class people {
protected:
	car *m_car;
public:
	void setCar(car * ptr) {
		m_car = ptr;

	}
	virtual void Run() = 0;
};

class youngMan : public people {
public:
	void Run() override {
		if (m_car) {
			std::cout << "���������ˣ��ҿ���";
			m_car->Run();
		}

	}
};

class wrinkly : public people {
private:

public:
	void Run() override {
		if (m_car) {
			std::cout << "���������ˣ��ҿ���";
			m_car->Run();
		}
	}
};

	
int main() {

	road * hightwalk = new heightWalk();
	road * commonrod = new commonWalk();


	car * _bus = new bus();
	car * saloon = new saloon_car();
	//�����Ž�
	_bus->setRoad(hightwalk);
	saloon->setRoad(hightwalk);
	_bus->Run();
	saloon->Run();

	_bus->setRoad(commonrod);
	saloon->setRoad(commonrod);
	_bus->Run();
	saloon->Run();
	//�����Ž�
	people * young = new youngMan();
	people * wrink = new wrinkly();
	//��������·
	young->setCar(_bus);
	wrink->setCar(_bus);
	young->Run();
	wrink->Run();

	young->setCar(saloon);
	wrink->setCar(saloon);
	young->Run();
	wrink->Run();
	//�ڸ��ٹ�·
	_bus->setRoad(hightwalk);
	saloon->setRoad(hightwalk);
	young->setCar(_bus);
	wrink->setCar(_bus);
	young->Run();
	wrink->Run();

	young->setCar(saloon);
	wrink->setCar(saloon);
	young->Run();
	wrink->Run();


	
	return 0;
}