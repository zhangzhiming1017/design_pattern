#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
//�н���ģʽ:��һ���н��������װһϵ�еĶ��󽻻����н���ʹ��������Ҫ��ʽ���໥���ã��Ӷ�ʹ�������ɢ�����ҿ��Զ����ظı�����֮��Ľ�����

//�ŵ�:�н�ĳ��ּ���������������Ľ��������ʹ����������Զ����仯
//ȱ��:�н�����˼��л����൱�ڰ���������ĸ��Ӷ�ת�Ƶ����н飬�����н�����⣬Ҳ��Ӱ����������Ľ���
enum class Country:int { CHINA=0,JANPAN,AMERICA};

class mediator { //������н�
public:
	virtual void declare(std::string message, Country From, Country to) = 0;
};

class country { //����Ľ�������
protected:
	mediator * med = NULL;
public:
	void setmediator(mediator * ptr) {
		med = ptr;
	}
	virtual void Declare(std::string message, Country to)= 0;
	virtual void Getmessage(std::string message,Country from) = 0;
};

class china : public country { //����Ķ���
public:
	void Declare(std::string message, Country to) override {
		if (med) {
			med->declare(message, Country::CHINA, to);
		}
	}
	void Getmessage(std::string message, Country from) override {

		std::cout << "�й��յ���";
		switch (from)
		{
		case Country::JANPAN:
			std::cout << "�ձ�";
			break;
		case Country::AMERICA:
			std::cout << "����";
			break;
		default:
			break;
		}
	    std::cout<<"����Ϣ: " << message << std::endl;
	}
};

class janpan : public country {
public:
	void Declare(std::string message, Country to) override {
		if (med) {
			med->declare(message, Country::JANPAN, to);
		}
	}
	void Getmessage(std::string message, Country from) override {
		std::cout << "�ձ��յ���";
		switch (from)
		{
		case Country::CHINA:
			std::cout << "�й�";
			break;
		case Country::AMERICA:
			std::cout << "����";
			break;
		default:
			break;
		}
		std::cout << "����Ϣ: " << message << std::endl;
	}
};

class america : public country {
public:
	void Declare(std::string message, Country to) override {
		if (med) {
			med->declare(message, Country::AMERICA, to);
		}
	}
	void Getmessage(std::string message, Country from) override {
		std::cout << "�����յ���";
		switch (from)
		{
		case Country::JANPAN:
			std::cout << "�ձ�";
			break;
		case Country::CHINA:
			std::cout << "�й�";
			break;
		default:
			break;
		}
		std::cout << "����Ϣ: " << message << std::endl;
	}
};



class concerateMediator : public mediator { //������н�,�н���˽����ԵĶ������ԡ�
private:
	china * _china = NULL;
	janpan * _janpan = NULL;
	america * _america = NULL;
public: 
	void setChina(china * ptr) {
		_china = ptr;
	}
	void setJanpan(janpan * ptr){
		_janpan = ptr;
	}
	void setAmerica(america * ptr){
		_america = ptr;
	}

	void declare(std::string message, Country From, Country to) override {
		if (!(_china && _janpan && _america)) return;
		switch (to)
		{
		case Country::CHINA:
			_china->Getmessage(message, From);
			break;
		case Country::JANPAN:
			_janpan->Getmessage(message, From);
			break;
		case Country::AMERICA:
			_america->Getmessage(message, From);
			break;
		default:
			break;
		}
		
	}
};


	
int main() {

	concerateMediator * UNSC = new concerateMediator();

	china * _china = new china();
	janpan * _janpan = new janpan();
	america * _america = new america();

	_china->setmediator(UNSC);
	_janpan->setmediator(UNSC);
	_america->setmediator(UNSC);

	UNSC->setChina(_china);
	UNSC->setJanpan(_janpan);
	UNSC->setAmerica(_america);

	
	_janpan->Declare("�Ҽƻ�Ҫ���˷��������", Country::CHINA);
	_janpan->Declare("�Ҽƻ�Ҫ���˷��������", Country::AMERICA);

	_america->Declare("��֧���ձ����˷��������", Country::JANPAN);
	_america->Declare("��֧���ձ����˷��������", Country::CHINA);

	_china->Declare("���ؿ����ձ����˷��������", Country::JANPAN);
	_china->Declare("���ؿ����ձ����˷��������", Country::AMERICA);
	
	return 0;
}