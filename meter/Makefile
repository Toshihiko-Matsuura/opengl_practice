design: design.o seven_segment.o
	g++ -o design design.o seven_segment.o -framework GLUT -framework OpenGL


design.o: design.cpp
	g++ -c design.cpp -framework GLUT -framework OpenGL

seven_segment.o: seven_segment.cpp
	g++ -c seven_segment.cpp  -framework GLUT -framework OpenGL
