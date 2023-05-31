main: functions.o
	g++ -o3 -o main main.cpp functions.o
functions: 
	g++ -o3 -c functions.cpp
clean:
	del *.o main