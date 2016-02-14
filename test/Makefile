INCLUDEDIR=../include/
CXXOPTS=-g -std=c++11
xrange_test: xrange_test.cpp $(INCLUDEDIR)/xrange.hpp
	$(CXX) $(CXXOPTS) -I$(INCLUDEDIR) -o xrange_test xrange_test.cpp

all: xrange_test
.PHONY: all clean

clean:
	rm -vf xrange_test
