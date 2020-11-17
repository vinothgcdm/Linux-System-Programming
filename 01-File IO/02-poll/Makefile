# Download Images Challenge Makefile
CXX		 = gcc
CXXFLAGS = -Wall
TARGET	 = main
SRC		 = main.c
LDLIBS	 =

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) $(LDLIBS) -o $(TARGET)

.PHONY: clean
clean:
	rm -f $(TARGET)