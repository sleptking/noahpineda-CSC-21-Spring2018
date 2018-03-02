Credit_Card_B: Credit_Card_B.o Card.o Bad_Card.o
	g++ Credit_Card_B.o Card.o Bad_Card.o
	
Credit_Card_B.o: Credit_Card_B.cpp
	g++ -c Credit_Card_B.cpp
	
Card.o: Card.cpp Card.h
	g++ -c Card.cpp

Bad_Card.o: Bad_Card.cpp Bad_Card.h
	g++ -c Bad_Card.cpp
	
clean:
	rm *.o a.out