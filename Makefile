

bin/prog: obj/main.o obj/Position.o obj/Board.o obj/Entity.o obj/Game.o obj/Ghost.o
	g++ -g -o bin/prog obj/main.o obj/Position.o obj/Board.o obj/Entity.o obj/Game.o obj/Ghost.o

obj/Board.o: src/Board.cpp libs/Board.h
	g++ -Wall -g -c src/Board.cpp -o obj/Board.o

obj/Entity.o: src/Entity.cpp libs/Entity.h
	g++ -Wall -g -c src/Entity.cpp -o obj/Entity.o

obj/Ghost.o: src/Ghost.cpp libs/Ghost.h
	g++ -Wall -g -c src/Ghost.cpp -o obj/Ghost.o

obj/Position.o: src/Position.cpp libs/Position.h
	g++ -Wall -g -c src/Position.cpp -o obj/Position.o

obj/Game.o: src/Game.cpp libs/Game.h
	g++ -Wall -g -c src/Game.cpp -o obj/Game.o

obj/main.o: src/main.cpp
	g++ -Wall -g -c src/main.cpp -o obj/main.o

#clean:
#	rm -f obg/*.o -> this is linux command