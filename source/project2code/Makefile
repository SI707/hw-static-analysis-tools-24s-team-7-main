
CXX = g++
CXXFLAGS = -std=c++11 -Wall


TARGET = knights_tour


OBJS = knights_tour.o main.o


$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)


knights_tour.o: knights_tour.cpp knights_tour.h
	$(CXX) $(CXXFLAGS) -c knights_tour.cpp

main.o: main.cpp knights_tour.h
	$(CXX) $(CXXFLAGS) -c main.cpp

#cleaning up build artifacts
clean:
	rm -f $(TARGET) $(OBJS)
