#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "attributes.h"


/*
Wiadomosc o niepoprawnych danych- wraz z instrukcja.
*/

int help(){
	printf("Sposob uzycia: ./TextGen\n");
		printf("\t [-in = plik wejsciowy]\n");
		printf("\t [-ngin = plik wejsciowy bazowy]\n");
		printf("\t [-out = plik wyjsciowy]\n");
		printf("\t [-ngout = nazwa pliku do ktorego ma byc zapisana baza ]\n");
		printf("\t [-is = ilosc slow ktore program ma wygenerowac]");
		printf("\t [-rng = rzad n-gramow na podstawie ktorych ma byc generowany tekst ]");
		printf("\t [-stat = czy maja byc generowane statystyki slow]");

	return 1;
}


attributes_t readAttributes(int argc, char** argv){

	int i,a;					//i- przechodzenie po slowach wejscia a-aktualny index w tablicy nazw plikow
 	attributes_t attributes;	
 	
	char *outFileDefault;
	char *ngoutFileDefault;
	int wordNumberDefault;
	int paragraphNumberDefault;
	int ngramLevelDefault;
	int statisticsDefault;
	int errorDefault;
	
	outFileDefault = "output.txt"; attributes.outFile = outFileDefault; 
	ngoutFileDefault = "base.mlg"; attributes.ngoutFile = ngoutFileDefault;
	wordNumberDefault = 100; attributes.wordNumber = wordNumberDefault;
	paragraphNumberDefault = 3; attributes.paragraphNumber = paragraphNumberDefault;
	ngramLevelDefault = 3; attributes.ngramLevel = ngramLevelDefault;
	statisticsDefault = 0; attributes.statistics = statisticsDefault;						
	errorDefault = 0; attributes.error = errorDefault;
	
	for (i = 1; i < (argc -1); i++){				// pliki wejsciowe z tekstem - maksymalnie 15
		if (strcmp("-in", argv[i]) == 0) {
			a=0;
			while(argv[++i][0]!='-'){
				attributes.inFile[a]=argv[i];							
				a++;
			}
			if (a==0){
				attributes.inFileNumber = 0;
				attributes.inFile[a] = "brak";
			}	
			else attributes.inFileNumber = --a;
			i--;
			continue;
		}
		
		if (strcmp("-ngin", argv[i]) == 0) {		// pliki wejsciowe z danymi - maksymalnie 15
			a=0;
			while(argv[++i][0]!='-'){
				attributes.nginFile[a]=argv[i];
				a++;
			}
			if (a==0){
				attributes.nginFileNumber = 0;
				attributes.nginFile[a]="brak";
			}	
			else attributes.inFileNumber = --a;
			i--;
			continue;
		}
		
		if (strcmp("-out", argv[i]) == 0) {		// nazwa pliku do ktorego bedzie zapisywany tekst
			if (argv[++i][0]!='-')
				attributes.outFile = argv[i];
			i--;
			continue;
		}
		
		if (strcmp("-ngout", argv[i]) == 0) {		// nazwa pliku do ktorego beda zapisywane dane slow
			if (argv[++i][0]!='-')
				attributes.ngoutFile=argv[i];
			i--;
			continue;
		}
		
		if (strcmp("-is", argv[i]) == 0) {			// ilosc slow do wygenerowania
			attributes.wordNumber = atoi(argv[++i]);
			continue;
		}
		
		if (strcmp("-ia", argv[i]) == 0) {			//ilosc akapitow na ktore ma byc podzielony tekst
			attributes.paragraphNumber = atoi(argv[++i]);
			continue;
		}
		
		if (strcmp("-rng", argv[i]) == 0) {		//rzad ngramow 
			attributes.ngramLevel = atoi(argv[++i]);
			continue;
		}
		
		if (strcmp("-stat", argv[i]) == 0) {		//czy maja byc generowane statystyki
			i++;
			if(((strcmp(argv[i],"0"))==0)||((strcmp(argv[i],"false"))==0))	// beda generowane o ile po "-stat" nie zostanie napisane "0" lub "false"
				attributes.statistics=0;
			else attributes.statistics=1;
			i--;
			continue;
		}
		
		
	}
	if ((attributes.inFileNumber == 0)&&(attributes.nginFileNumber == 0)){
		printf("Nie zostaly podane wymagane dane wejsciowe. Prosze podac minimum jeden plik wejsciowy lub bazowy");
		attributes.error = 1;
	}
	return attributes;
}

int printAttributes(attributes_t attributes){
	int a;
	printf("1Atrybuty tego wejscia to: \n");
	
	printf("Pliki wejsciowe(inFile): ");	
	a=0;
	while(a<=attributes.inFileNumber){
		printf("--[ %s ]",attributes.inFile[a]);
		a++;
	}
	printf("\n");
	
	printf("Pliki wejsciowe bazy(nginFile): ");
	a=0;
	while(a<=attributes.nginFileNumber){
		printf("--[ %s ]",attributes.nginFile[a]);
		a++;
	}	
	printf("\n");
	
	printf("Plik wyjsciowy(outFile) = %s\n", attributes.outFile);
	printf("Plik wyjsciowy bazy(ngoutFile) = %s\n", attributes.ngoutFile);
	printf("Ilosc slow(wordNumber) = %d\n", attributes.wordNumber);
	printf("Ilosc paragrafow(paragraphNumber) = %d\n", attributes.paragraphNumber);
	printf("Rzad ngramow(ngramLevel) = %d\n", attributes.ngramLevel);
	printf("Statystyki 0/1 (statistics)= %d\n", attributes.statistics);
	
		
		
}
