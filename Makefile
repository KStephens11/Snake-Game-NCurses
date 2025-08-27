all:
	g++ -c src/*.cpp -std=c++20 -m64 -g -Wall -I include -I /usr/include && g++ *.o -o bin/main -l ncurses
rel:
	g++ -c src/*.cpp -std=c++20 -m64 -O3 -g -Wall -I include -I /usr/include && g++ *.o -o bin/msnake -l ncurses