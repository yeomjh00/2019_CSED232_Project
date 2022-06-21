#include "bomb.h"

bomb::bomb():dir(-1){}

bomb::bomb(int direction):dir(direction) {}

void bomb::changedir() {
	dir = (++dir) % 4;
}

int bomb::direction() {
	return dir;
}
