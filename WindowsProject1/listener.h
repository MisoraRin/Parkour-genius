#pragma once
#include"stdafx.h"
#include"barrier.h"
#include"graphic.h"
class listener {
private:
public:
	listener() = default;
	~listener() = default;
	bool death_listener(graphic b,vector<barrier>a) {
		for (int i = 0; i < a.size; i++) {
			if (a[i].x_get < 50)
				if (b.y_get - a[i].height_get < 40)
					game_over();
		}
	}
};