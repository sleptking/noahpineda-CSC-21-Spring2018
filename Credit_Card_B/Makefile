Credit_Card_B: Credit_Card_B.o Card.o 
	g++ Credit_Card_B.o Card.o
food_item.o: Credit_Card_B.cpp
	g++ -c Credit_Card_B.cpp
item.o: Card.cpp Card.h
	g++ -c Card.cpp

	
clean:
	rm *.o a.out