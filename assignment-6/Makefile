all:	life-nonblocking 

CXX = mpicxx
CXXFLAGS = -std=c++11 -g

life-nonblocking:	life-nonblocking.C
	$(CXX) $(CXXFLAGS) -o life-nonblocking $<


clean:
	rm -f life-nonblocking.o life-nonblocking


