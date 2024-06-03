COMPILER ?= g++
DEBUGGER = gdb
CFLAGS = -std=c++14 -Wall -Wno-missing-braces
LIBINCLUDE = 

ifeq ($(OS),Windows_NT)
        PLATFORM_OS = WINDOWS
        ifndef PLATFORM_SHELL
            PLATFORM_SHELL = cmd
        endif
            CFLAGS += -O1
			LIBINCLUDE += -L lib/ -I include/
			LIBS += -lraylib -lopengl32 -lgdi32 -lwinmm
			TARGET = smarciopoly.exe
    else
        UNAMEOS = $(shell uname)
        ifeq ($(UNAMEOS),Linux)
            PLATFORM_OS = LINUX
        endif
        ifeq ($(UNAMEOS),Darwin)
            PLATFORM_OS = OSX
			COMPILER = clang++
			DEBUGGER = lldb
			LIBS += -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL 
			LIBS += $(shell pkg-config raylib --cflags --libs)
			LIBS += $(shell pkg-config nlohmann_json --cflags)

			TARGET = smarciopoly
        endif
        ifndef PLATFORM_SHELL
            PLATFORM_SHELL = sh
        endif
    endif

SRCS := $(wildcard src/*.cpp)
OBJS := $(SRCS:.cpp=.o)

all: $(TARGET) run clean
debug: $(TARGET) rungdb clean

# Link the executable
$(TARGET): $(OBJS)
	$(COMPILER) $(OBJS) -o $(TARGET) $(LIBINCLUDE) $(LIBS) $(CFLAGS)

# Compile .c files to .o files
src/%.o: src/%.cpp
	$(COMPILER) $(LIBINCLUDE) $(LIBS) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run:
	./$(TARGET)

rungdb:
	$(DEBUGGER) ./$(TARGET)

ifeq ($(PLATFORM_OS), OSX)
setup:
	brew install raylib
	brew install nlohmann-json
endif
