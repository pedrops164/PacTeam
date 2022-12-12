

bin/prog: obj/main.o obj/Position.o obj/Board.o obj/Entity.o obj/Game.o obj/Ghost.o obj/PieceBoard.o obj/Astar.o obj/Direction.o obj/DefaultGhost.o
	g++ -g -o bin/prog obj/main.o obj/Position.o obj/Board.o obj/Entity.o obj/Game.o obj/Ghost.o obj/PieceBoard.o obj/Astar.o obj/Direction.o obj/DefaultGhost.o

obj/Board.o: src/Board.cpp libs/Board.h
	g++ -Wall -g -c src/Board.cpp -o obj/Board.o

obj/Astar.o: src/Astar.cpp libs/Astar.h
	g++ -Wall -g -c src/Astar.cpp -o obj/Astar.o

obj/PieceBoard.o: src/PieceBoard.cpp libs/PieceBoard.h
	g++ -Wall -g -c src/PieceBoard.cpp -o obj/PieceBoard.o

obj/Direction.o: src/Direction.cpp libs/Direction.h
	g++ -Wall -g -c src/Direction.cpp -o obj/Direction.o

obj/Entity.o: src/Entity.cpp libs/Entity.h
	g++ -Wall -g -c src/Entity.cpp -o obj/Entity.o

obj/Ghost.o: src/Ghost.cpp libs/Ghost.h
	g++ -Wall -g -c src/Ghost.cpp -o obj/Ghost.o

obj/DefaultGhost.o: src/DefaultGhost.cpp libs/DefaultGhost.h
	g++ -Wall -g -c src/DefaultGhost.cpp -o obj/DefaultGhost.o

obj/Position.o: src/Position.cpp libs/Position.h
	g++ -Wall -g -c src/Position.cpp -o obj/Position.o

obj/Game.o: src/Game.cpp libs/Game.h
	g++ -Wall -g -c src/Game.cpp -o obj/Game.o

obj/main.o: src/main.cpp
	g++ -Wall -g -c src/main.cpp -o obj/main.o

#clean:
#	rm -f obg/*.o -> this is linux command