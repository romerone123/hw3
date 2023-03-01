CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes



#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------

llrec-test: llrec-test.cpp llrec.h 
	$(CXX) $(CXXFLAGS) llrec-test.cpp llrec.cpp -o llrec-test

stack-test:
	$(CXX) $(CXXFLAGS) stack-test.cpp -o stack-test

llrec: llrec-test
	./llrec-test

stack: stack-test
	./stack-test

clean:
	rm -f *.o rh llrec-test *~
	rm -f *.o rh stack-test *~


.PHONY: clean llrec-test
.PHONY: clean stack-test