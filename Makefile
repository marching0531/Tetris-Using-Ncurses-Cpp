CC = g++
TARGET = playTetris
SOURCES = Tetris.cpp \
	  Pane.cpp \
	  BoardPane.cpp \
	  InfoPane.cpp \
	  HelpPane.cpp \
    	  StatPane.cpp \
	  NextPane.cpp \
	  main.cpp \
	  Block.cpp

LDFLAGS = -lncurses

OPTION = -lrt

all:
	$(CC) -o $(TARGET) $(SOURCES) $(LDFLAGS) $(OPTION)

clean:
	rm -rf *.o $(TARGET)
