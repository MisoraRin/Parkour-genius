#pragma once
#include"barrier.h"
class barriers {
private:
	bool tag_exist;
	deque<barrier> setsb;
public:
	barriers();
	void flash();
	virtual void build() = 0;
};