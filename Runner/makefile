main : main.o platform.o obstacle.o runner.o vector2.o liste.o rectangle.o
	g++ -o main main.o platform.o obstacle.o runner.o vector2.o liste.o rectangle.o
	
main.o : main.cpp platform.h obstacle.h runner.h vector2.h
	g++ main.cpp -g -c
	
platform.o : platform.cpp platform.h liste.h rectangle.h
	g++ platform.cpp -g -c
	
obstacle.o : obstacle.cpp obstacle.h
	g++ obstacle.cpp -g -c
	
runner.o : runner.cpp runner.h
	g++ runner.cpp -g -c
	
vector2.o : vector2.cpp vector2.h
	g++ vector2.cpp -g -c

liste.o: liste.cpp liste.h obstacle.h
	g++ liste.cpp -g -c
	
rectangle.o: rectangle.cpp rectangle.h vector2.h
	g++ rectangle.cpp -g -c
	
clean :
	rm -f *.o
