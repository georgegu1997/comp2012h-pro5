all: Register
Register: main.o records.o registermanager.o htmlgenerator.o utility.o doublylinkedlist.h
	g++ -o Register main.o records.o registermanager.o htmlgenerator.o utility.o
main.o: main.cpp htmlgenerator.h registermanager.h
	g++ -c main.cpp
records.o: records.h records.cpp constants.h
	g++ -c records.cpp -std=c++11
registermanager.o: registermanager.h registermanager.cpp doublylinkedlist.h hashtable.h htmlgenerator.h constants.h utility.h
	g++ -c registermanager.cpp
htmlgenerator.o: htmlgenerator.h htmlgenerator.cpp constants.h doublylinkedlist.h records.h
	g++ -c htmlgenerator.cpp
utility.o: utility.h utility.cpp constants.h records.h
	g++ -c utility.cpp


clean:
	rm -f *.o Register *.html
