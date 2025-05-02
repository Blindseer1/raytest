
default:
	g++ Entity.cpp Attacks.cpp Prompt.cpp game.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
