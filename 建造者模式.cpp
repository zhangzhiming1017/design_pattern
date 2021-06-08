#include <iostream>
//建造者模式，抽象不应该依赖于细节，细节应该依赖于抽象


//产品类，产品可能由多个类组成，描述产品的属性
class head {
public:
	void show() {
		std::cout << " head " << std::endl;
	}

};
class body {
public:
	void show() {
		std::cout << " body " << std::endl;
	}
};
class hand {
public:
	virtual void show() = 0;

};
class leftHand : public hand {
public:
	void show() override {
		std::cout << " leftHand " << std::endl;
	}

};
class rihgtHand : public hand {
public:
	void show()override {
		std::cout << " rihgtHand " << std::endl;
	}

};

class foot {
public:
	virtual void show() = 0;
};

class leftfoot : public foot {
public:
	void show() override {
		std::cout << " rihgtHand " << std::endl;
	}
};
class rightfoot : public foot {
public:
	void show() override {
		std::cout << " rihgtHand " << std::endl;
	}
};

class person {
public:
	person() {
		m_head = nullptr;
		m_body = nullptr;
		m_lefthand = nullptr;
		m_righthand = nullptr;
		m_leftfoot = nullptr;
		m_rightfoot = nullptr;
	}


	void show() {
		if (m_head) {
			std::cout << " I have head " << std::endl;
		}
		if (m_body) {
			std::cout << " I have body " << std::endl;
		}
		if (m_lefthand) {
			std::cout << " I have lefthand " << std::endl;
		}
		if (m_righthand) {
			std::cout << " I have righthand " << std::endl;
		}
		if (m_leftfoot) {
			std::cout << " I have leftfoot " << std::endl;
		}
		if (m_rightfoot) {
			std::cout << " I have rightfoot " << std::endl;
		}
	}

	head* m_head;
	body* m_body;
	hand* m_lefthand;
	hand* m_righthand;
	foot* m_leftfoot;
	foot* m_rightfoot;

};


//抽象建造类，具体建造类，描述建造产品的过程
class abstraBuiler {
public:
	virtual void createHead() = 0;
	virtual void createbody() = 0;
	virtual void createhand() = 0;
	virtual void createfoot() = 0;
	virtual person  getResult() = 0;
};

class personBuiler : public abstraBuiler {
private:
	person m_person;
public:
	
	 void createHead() override {
		 m_person.m_head = new head();
	}
	 void createbody() override {
		 m_person.m_body = new body();
	}
	 void createhand() override {
		 m_person.m_righthand = new rihgtHand();
		 m_person.m_lefthand = new leftHand();
	}
	 void createfoot() override {
		 m_person.m_rightfoot = new rightfoot();
		 m_person.m_leftfoot = new leftfoot();
	}
	 person  getResult() override {
		 return m_person;
	}
};


//监督类,告诉建造类，该建造什么样的产品

class dirtory {
public:
	void construct(abstraBuiler* bulie) {
		bulie->createHead();
		bulie->createbody();
		bulie->createhand();
		bulie->createfoot();
	}
};


	
int main() {

	dirtory * m_dirtory = new dirtory();
	personBuiler * A = new personBuiler();
	personBuiler * B = new personBuiler();
	m_dirtory->construct(A);
	m_dirtory->construct(B);
	person  aperson =  A->getResult();
	aperson.show();
	person  bperson = B->getResult();
	bperson.show();
	
	
	return 0;
}