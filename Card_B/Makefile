Credit_Card_B: Credit_Card_B.o Card.o Gold.o Platinum.o Corporate.o
	g++ Credit_Card_B.o Card.o Gold.o Platinum.o Corporate.o
	
Credit_Card_B.o: Credit_Card_B.cpp
	g++ -c Credit_Card_B.cpp
	
Card.o: Card.cpp Card.h
	g++ -c Card.cpp

Gold.o: Gold.cpp Gold.h
	g++ -c Gold.cpp

Platinum.o: Platinum.cpp Platinum.h
	g++ -c Platinum.cpp

Corporate.o: Corporate.cpp Corporate.h
	g++ -c Corporate.cpp
	
clean:
	rm *.o a.out