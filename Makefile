OBJS	= main.o
SOURCE	= src/main.cpp
HEADER	= 
OUT	= poker
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = -lpthread -lm

GRAPHICSDIR = src/graphics

SOURCES := $(shell find $(GRAPHICSDIR) -name '*.cpp')
HEADER := $(shell find $(GRAPHICSDIR) -name '*.h')
#OBJS := $(SOURCES:%.cpp=%.o)

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: src/main.cpp
	$(CC) $(FLAGS) src/main.cpp -lcppunit


clean:
	rm -f $(OBJS) $(OUT)
