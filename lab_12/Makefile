lab_12: food_item.o item.o magic_item.o lab_12_unit_test.o
	g++ food_item.o item.o magic_item.o lab_12_unit_test.o
food_item.o: food_item.cpp food_item.h
	g++ -std=c++11 food_item.cpp
item.o: item.cpp item.h
	g++ -std=c++11 item.cpp
magic_item.o: magic_item.cpp magic_item.h
	g++ -std=c++11 magic_item.cpp
lab_12_unit_test.o: lab_12_unit_test.cpp catch.hpp
	g++ -std=c++11 lab_12_unit_test.cpp
	
clean:
	rm *.o a.out