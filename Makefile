CC = g++
TARGET = tetris
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

all:
	$(CC) -o $(TARGET) $(SOURCES) $(LDFLAGS)

clean:
	rm -rf *.o $(TARGET)
