TextGen: main.c attributes.c input.c output.c statystyka.c wordArray.c ./ngramTree/tree.c gener.c
	cc -o TextGen main.c attributes.c input.c output.c statystyka.c wordArray.c ./ngramTree/tree.c gener.c
	
clean:
	rm -f *.o
	


