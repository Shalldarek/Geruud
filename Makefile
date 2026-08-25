CXX ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra -Iinclude -Isrc -Idatabase -Imodules
LDLIBS ?= -lsqlite3

SRC_DIRS := src database modules
SOURCES := $(shell find $(SRC_DIRS) -type f -name '*.cpp')
HEADERS := $(shell find $(SRC_DIRS) -type f -name '*.h')
OBJECTS := $(SOURCES:.cpp=.o)

TARGET ?= geruud

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ $(LDLIBS) -o $@

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean
