#include <iostream>
#include <chrono>
#include <thread>
#include <windows.h>
#include <conio.h> //_getch()
#include <future>
#include "../libs/Game.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

/*
* static char getKeyPress() {
	char c = getch();
	return c;
}
*/

int main() {
	using namespace std::this_thread; // sleep_for, sleep_until
	using namespace std::chrono; // nanoseconds, system_clock, seconds
	float ticksPerSecond = 3;
	milliseconds timeout((int)((1 / ticksPerSecond) * 1000));
	//std::future<char> keyPress = std::async(getKeyPress);
	Game game = Game("../maps/0.txt", ticksPerSecond);

	//sleep_for(seconds(3));
	/*
	Current solution only works for windows! (the GetAsyncKeyState function)
	We should find an alternative to work on linux too.
	*/
	while (1) {
		/*
		* if (keyPress.wait_for(timeout1) == std::future_status::ready) {
			char key = keyPress.get();
			switch (key) {
			case KEY_UP:
				game.movePlayer(Direction::Up);
				break;
			case KEY_DOWN:
				game.movePlayer(Direction::Down);
				break;
			case KEY_LEFT:
				game.movePlayer(Direction::Left);
				break;
			case KEY_RIGHT:
				game.movePlayer(Direction::Right);
				break;
			}
		}
		else {
			game.movePlayer();
		}
		*/
		sleep_for(timeout);
		if (GetAsyncKeyState(VK_UP) & 1) {
			//Up arrow was clicked since last time
			game.movePlayer(Direction::Up);
		} else if (GetAsyncKeyState(VK_DOWN) & 1) {
			game.movePlayer(Direction::Down);
		} else if (GetAsyncKeyState(VK_RIGHT) & 1) {
			game.movePlayer(Direction::Right);
		} else if (GetAsyncKeyState(VK_LEFT) & 1) {
			game.movePlayer(Direction::Left);
		} else {
			game.movePlayer();
		}
		game.printBoard();
	}
	
	return 0;
}