 #include <iostream>
//版本一 适用于单线程
 class sington
{
private:
	sington() {};
	~sington() {};
	static sington* Pinstance;

public:
	static sington* GetInstance() {
		if (Pinstance == NULL) {
			Pinstance = new sington();
		}
		return Pinstance;
	}

	static void destorysington() {
		if (Pinstance) {
			delete Pinstance;
			Pinstance = NULL;
		}
	}

};
 sington*   sington::Pinstance = NULL;


 //	版本2
 class sington2{
 private:
	 sington2() {};
 public:
	 static sington2* instance() {
		 static sington2 Pinstance;
		 return &Pinstance;
	 }
 };


 //版本3
 class sington3 {
 private:
	 sington3() {};
	 sington3(const sington3& orig) {};
	 sington3& operator=(const sington3& orig) {};
 public:
	 static sington3* instance() {
		 static sington3 Pinstance;
		 return &Pinstance;
	 }
 };


 