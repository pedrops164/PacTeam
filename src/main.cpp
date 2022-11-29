#include <iostream>
#include <chrono>
#include <thread>
#include "../libs/Game.h"

int main() {
	using namespace std::this_thread; // sleep_for, sleep_until
	using namespace std::chrono; // nanoseconds, system_clock, seconds
	float ticksPerSecond = 5;
	milliseconds timeout((int)((1 / ticksPerSecond) * 1000));
	Game game = Game("../maps/0.txt", ticksPerSecond, 1, 3);
	/*
	Current solution only works for windows! (the GetAsyncKeyState function)
	We should find an alternative to work on linux too.
	*/
	while (1) {
		sleep_for(timeout); //sleep interval
		game.update();
		game.printBoard();
	}
	
	return 0;
}