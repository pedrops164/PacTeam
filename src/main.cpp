#include <iostream>
#include <chrono>
#include <thread>
#include "../libs/Game.h"
#include "../libs/PacmanKeyBoardAgent.h"
#include "../libs/PacmanMiniMaxAgent.h"
#include "../libs/EvaluationFunction.h"

int main() {
	using namespace std::this_thread; // sleep_for, sleep_until
	using namespace std::chrono; // nanoseconds, system_clock, seconds
	int ticksPerSecond = 5;
	milliseconds timeout((int)((1.0 / ticksPerSecond) * 1000));
	//Game game = Game("maps/0.txt", ticksPerSecond, 1, 2,
	//	new PacmanMiniMaxAgent(new EvaluationFunction()));
	Game game = Game("maps/0.txt", ticksPerSecond, 1, 2, new PacmanMiniMaxAgent(new EvaluationFunction()));
	/*
	Current solution only works for windows! (the GetAsyncKeyState function)
	We should find an alternative to work on linux too.
	*/
	game.printBoard();
	while (1) {
		sleep_for(timeout); //sleep interval
		game.update();
		system("cls");
		game.printBoard();
		
	}
	
	return 0;
}