#include <iostream>
#include <vector>

//职责链模式:使多个对象都有机会处理请求，从而避免请求的发送者和接收者之间的耦合关系。将这个对象连成一条链，并沿着这条链传递该请求，直到有一个对象处理它为止。	 

//使用场景：多个对象可以处理一个请求，但是具体哪个对象处理需要在运行时判断
//可动态指定一组对象处理请求，或者添加新的处理者
//需要在不明确指定请求处理者的情况下，向多个处理者的其中一个发起请求。
//处理者处理请求的一部分，将剩余部分转移到下家
class Leader {
protected:
	Leader* succor;
public:
	void setLeader(Leader* ptr) {
		succor = ptr;
	}
	virtual void handleRequest(int request) = 0;
};

class ClassAdviser :public Leader {
public:
	void handleRequest(int request) override {
		if (0 < request && request < 3) {
			std::cout << "班主任同意了" << request << "天的请假" << std::endl;
		}
		else if (succor != nullptr) {
			succor->handleRequest(request);
		}
	}

};

class DepartmentHead :public Leader {
	void handleRequest(int request) override {
		if (3 <= request && request < 7) {
			std::cout << "系主任同意了" << request << "天的请假" << std::endl;
		}
		else if (succor != nullptr) {
			succor->handleRequest(request);
		}
	}
};

class Dean :public Leader {
	void handleRequest(int request) override {
		if (7 <= request && request < 14) {
			std::cout << "院长同意了" << request << "天的请假" << std::endl;
		}
		else {
			std::cout << "请假天数太多，不准假！" << std::endl;
		}
	}
};




int main() {
	Leader* _ClassAdviser = new ClassAdviser();
	Leader* _DepartmentHead = new DepartmentHead();
	Leader* _Dean = new Dean();
	_ClassAdviser->setLeader(_DepartmentHead);
	_DepartmentHead->setLeader(_Dean);

	std::vector<int> pp{ 1,5,3,7,16,10,2,6,19,8,6,4 };
	for (int i = 0; i < pp.size(); i++) {
		_ClassAdviser->handleRequest(pp[i]);
	}
	return 0;
}
