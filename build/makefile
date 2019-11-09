CC = g++
SDL = -I ..\SDL\include\SDL2 -L ..\SDL\lib -lmingw32 -lSDL2main -lSDL2
SRC = $(wildcard ../src/*.cpp)
OBJ = $(SRC:.cpp=.o)

%.o : %.cpp
	@$(CC) -o $@ -c $< -I ..\headers $(SDL) -std=c++11

ngame: $(OBJ)
	@$(CC) -o $@ $(OBJ) $(SDL) -lws2_32

clean:
	del ..\src\*.o