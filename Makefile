CXX=g++
CXXFLAGS = -g -Wall

TARGET=bwt

all: $(TARGET)

$(TARGET): bwt.cpp LF_map.o
	${CXX} ${CXXFLAGS} $^ -o $@

LF_map.o: LF_map.cpp LF_map.h
	${CXX} ${CXXFLAGS} -c $< -o $@

clean:
	rm -f *.o 