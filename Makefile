CXX=g++
CXXFLAGS = -g -Wall

TARGET=bwa

all: $(TARGET)

$(TARGET): main.cpp match.o LF_map.o bwt.o
	${CXX} ${CXXFLAGS} $^ -o $@

LF_map.o: LF_map.cpp LF_map.h
	${CXX} ${CXXFLAGS} -c $< -o $@

bwt.o: bwt.cpp bwt.h LF_map.o
	${CXX} ${CXXFLAGS} -c $< -o $@

match.o: match.cpp match.h bwt.o
	${CXX} ${CXXFLAGS} -c $< -o $@
	
clean:
	rm -f *.o 