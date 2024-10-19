SOURCES = main.cpp Game.cpp
OUT = game

all : $(SOURCES)
	g++ $(SOURCES) -lSDL2 -o $(OUT)
