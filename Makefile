main: main.c attributes.c 
	cc -o main main.c attributes.c
	
clean:
	rm -f *.o
	


