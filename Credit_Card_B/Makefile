Credit_Card_B: Credit_Card_B.o Card.o
	g++ -o Credit_Card_B.o Card.o
	
Credit_Card_B.o: Credit_Card_B.cpp
	g++ -std=c++0x Credit_Card_B.cpp
	
Card.o: Card.cpp Card.h
	g++ -std=c++0x Card.cpp

clean:
	rm *.o a.out