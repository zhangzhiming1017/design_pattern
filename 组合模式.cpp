#include <iostream>
#include <vector>
//组合模式:将对象组合成树形结构以表示“部分-整体”的层次结构。组合模式使得用户对单个对象和组合对象的使用具有一致性

//何时使用组合模式：
//1.当发现需求中是体现部分和整体层次的结构时，希望用户可以忽略组合对象与单个对象的不同，统一地使用组合结构中所有对象时，应该考虑组合模式。
//好处：
//1.基本对象可以组合成更复杂的的组合对象，而这些组合对象又可以被组合，可以不断地递归下去，客户代码中，任何用到基本对象的地方都可以用组合对象代替。
//2.组合模式让客户可以一致地使用组合结构和单个对象
//组合对象抽象
class absCompany {
protected:
	std::string name = "";
public:
	absCompany(std::string _name) {
		name = _name;
	}
	virtual void Add(absCompany* ptr) = 0;
	virtual void Remove(std::string name) = 0;
	virtual void Dispaly() = 0;
	std::string getName() {
		return name;
	}
};

//基本对象
class finance : public absCompany {//财政部
public:
	finance(std::string _name) :absCompany(_name) {

	}

	void Add(absCompany* ptr) override {
		std::cout << "已达到基础部门，不能增加子部门" << std::endl;
	}

	void Remove(std::string name) override {
		std::cout << "已达到基础部门，无子部门可移除" << std::endl;
	}
	void Dispaly() override {
		std::cout << name << std::endl;
	}

};

class adminitroy : public absCompany {//行政部
public:
	adminitroy(std::string _name) :absCompany(_name) {

	}

	void Add(absCompany* ptr) override {
		std::cout << "已达到基础部门，不能增加子部门" << std::endl;
	}

	void Remove(std::string name) override {
		std::cout << "已达到基础部门，无子部门可移除" << std::endl;
	}
	void Dispaly() override {
		std::cout << name << std::endl;
	}
};

class research : public absCompany {//研发部
public:
	research(std::string _name) :absCompany(_name) {

	}

	void Add(absCompany* ptr) override {
		std::cout << "已达到基础部门，不能增加子部门" << std::endl;
	}

	void Remove(std::string name) override {
		std::cout << "已达到基础部门，无子部门可移除" << std::endl;
	}
	void Dispaly() override {
		std::cout << name << std::endl;
	}
};

//组合对象具体

class Company : public absCompany {
private:
	std::vector<absCompany*> Chilerend;
	int indep = 0;

public:
	Company(std::string _name, int indpe) :absCompany(_name), indep(indpe) {

	}

	void Add(absCompany* ptr) override {
		if (ptr)
		{
			Chilerend.push_back(ptr);
		}
	}

	void Remove(std::string name) override {
		for (auto iter = Chilerend.begin(); iter != Chilerend.end(); iter++) {
			if ((*iter)->getName() == name) {
				iter = Chilerend.erase(iter);
				break;
			}
		}

	}
	void Dispaly() override {
		std::cout << std::string("-", indep) << name << std::endl;
		for (auto iter = Chilerend.begin(); iter != Chilerend.end(); iter++) {
			//std::cout << std::string("-", indep) << name;
			(*iter)->Dispaly();
			std::cout << std::endl;
		}
	}
};


int main() {
	absCompany* dazu = new Company("大族", 1);
	dazu->Add(new finance("财务部"));
	dazu->Add(new adminitroy("行政部"));
	dazu->Add(new research("研发部"));

	absCompany* dazushijue = new Company("大族视觉", 2);
	dazu->Add(dazushijue);
	dazushijue->Add(new finance("财务部"));
	dazushijue->Add(new adminitroy("行政部"));
	dazushijue->Add(new research("研发部"));

	absCompany* dazuguangdian = new Company("大族光电", 3);
	dazushijue->Add(dazuguangdian);
	dazuguangdian->Add(new finance("财务部"));
	dazuguangdian->Add(new adminitroy("行政部"));
	dazuguangdian->Add(new research("研发部"));
	dazu->Dispaly();

	return 0;
}
