

bin/prog: obj/main.o obj/Position.o obj/Board.o obj/Entity.o
	g++ -g -o bin/prog obj/main.o obj/Position.o obj/Board.o obj/Entity.o

obj/Board.o: src/Board.cpp libs/Board.h
	g++ -Wall -g -c src/Board.cpp -o obj/Board.o

obj/Entity.o: src/Entity.cpp libs/Entity.h
	g++ -Wall -g -c src/Entity.cpp -o obj/Entity.o

obj/Position.o: src/Position.cpp libs/Position.h
	g++ -Wall -g -c src/Position.cpp -o obj/Position.o

obj/main.o: src/main.cpp
	g++ -Wall -g -c src/main.cpp -o obj/main.o

#clean:
#	rm -f obg/*.o -> this is linux command