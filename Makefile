COMPILER ?= gcc
CFLAGS = -std=c2x
LIBINCLUDE = -L lib/ -I include/

ifeq ($(OS),Windows_NT)
        PLATFORM_OS = WINDOWS
        ifndef PLATFORM_SHELL
            PLATFORM_SHELL = cmd
        endif
            CFLAGS += -O1 -Wall -std=c99 -Wno-missing-braces
			LIBS += -lraylib -lopengl32 -lgdi32 -lwinmm
			TARGET = smarciopoly.exe
    else
        UNAMEOS = $(shell uname)
        ifeq ($(UNAMEOS),Linux)
            PLATFORM_OS = LINUX
        endif
        ifeq ($(UNAMEOS),Darwin)
            PLATFORM_OS = OSX
			COMPILER = clang
			LIBS += -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL lib/libraylib.a
			TARGET = smarciopoly
        endif
        ifndef PLATFORM_SHELL
            PLATFORM_SHELL = sh
        endif
    endif

SRCS := $(wildcard src/*.c)
OBJS := $(SRCS:.c=.o)

all: $(TARGET) run clean

# Link the executable
$(TARGET): $(OBJS)
	echo link sbrognolo
	$(COMPILER) $(OBJS) -o $(TARGET) $(LIBINCLUDE) $(LIBS) $(CFLAGS)

# Compile .c files to .o files
src/%.o: src/%.c
	echo compiling sbrognolo
	$(COMPILER) $(LIBINCLUDE) $(LIBS) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run:
	./$(TARGET)

ifeq ($(PLATFORM_OS), OSX)
setup:
	export MACOSX_DEPLOYMENT_TARGET=10.9
	git clone https://github.com/raysan5/raylib.git
	cd raylib/src
	make
	cd ../..
	mkdir lib
	cp raylib/src/libraylib.a lib
	mkdir include
	cp raylib/src/raylib.h include
	cp raylib/src/raymath.h include
	cp raylib/src/rcamera.h include
	cp raylib/src/rgestures.h include
	cp raylib/src/utils.h include
endif
