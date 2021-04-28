# Copyright 2021 Tyler Julian Herman

all: typingtrainer

typingtrainer: maincode.cpp
	g++ -std=c++17 maincode.cpp -o typingtrainer -lsfml-graphics -lsfml-window -lsfml-system
