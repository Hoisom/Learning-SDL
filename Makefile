SOURCES = main.cpp Game.cpp
OUT = game

all : $(SOURCES)
	g++ $(SOURCES) -lSDL2 -lSDL2_image -o $(OUT)
