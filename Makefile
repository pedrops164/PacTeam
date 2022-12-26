

bin/prog: obj/main.o obj/Position.o obj/Board.o obj/Entity.o obj/Game.o obj/Ghost.o obj/PieceBoard.o obj/Astar.o obj/Direction.o obj/RedGhost.o obj/PinkGhost.o obj/BlueGhost.o obj/OrangeGhost.o obj/PacmanAgent.o obj/PacmanKeyBoardAgent.o obj/PacmanMiniMaxAgent.o obj/EvaluationFunction.o
	g++ -g -o bin/prog obj/main.o obj/Position.o obj/Board.o obj/Entity.o obj/Game.o obj/Ghost.o obj/PieceBoard.o obj/Astar.o obj/Direction.o obj/RedGhost.o obj/PinkGhost.o obj/BlueGhost.o obj/OrangeGhost.o obj/PacmanAgent.o obj/PacmanKeyBoardAgent.o obj/PacmanMiniMaxAgent.o obj/EvaluationFunction.o

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

obj/RedGhost.o: src/RedGhost.cpp libs/RedGhost.h
	g++ -Wall -g -c src/RedGhost.cpp -o obj/RedGhost.o

obj/PinkGhost.o: src/PinkGhost.cpp libs/PinkGhost.h
	g++ -Wall -g -c src/PinkGhost.cpp -o obj/PinkGhost.o

obj/BlueGhost.o: src/BlueGhost.cpp libs/BlueGhost.h
	g++ -Wall -g -c src/BlueGhost.cpp -o obj/BlueGhost.o

obj/OrangeGhost.o: src/OrangeGhost.cpp libs/OrangeGhost.h
	g++ -Wall -g -c src/OrangeGhost.cpp -o obj/OrangeGhost.o

obj/Position.o: src/Position.cpp libs/Position.h
	g++ -Wall -g -c src/Position.cpp -o obj/Position.o

obj/Game.o: src/Game.cpp libs/Game.h
	g++ -Wall -g -c src/Game.cpp -o obj/Game.o

obj/PacmanAgent.o: src/PacmanAgent.cpp libs/PacmanAgent.h
	g++ -Wall -g -c src/PacmanAgent.cpp -o obj/PacmanAgent.o

obj/PacmanKeyBoardAgent.o: src/PacmanKeyBoardAgent.cpp libs/PacmanKeyBoardAgent.h
	g++ -Wall -g -c src/PacmanKeyBoardAgent.cpp -o obj/PacmanKeyBoardAgent.o

obj/PacmanMiniMaxAgent.o: src/PacmanMiniMaxAgent.cpp libs/PacmanMiniMaxAgent.h
	g++ -Wall -g -c src/PacmanMiniMaxAgent.cpp -o obj/PacmanMiniMaxAgent.o

obj/EvaluationFunction.o: src/EvaluationFunction.cpp libs/EvaluationFunction.h
	g++ -Wall -g -c src/EvaluationFunction.cpp -o obj/EvaluationFunction.o

obj/main.o: src/main.cpp
	g++ -Wall -g -c src/main.cpp -o obj/main.o

#clean:
#	rm -f obg/*.o -> this is linux command