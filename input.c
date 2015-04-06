#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"
#include "wordArray.h"
//#include "ngramArray.h"

int countWordsInText( char *fileName){
	FILE *textFile;
	char slowo[255];
	int wordNumber = 0;

	textFile = fopen(fileName,"r");
	
	while(fscanf(textFile,"%s",slowo)!= EOF)
		wordNumber++;
	
	printf("Liczba slow to: %d\n", wordNumber);
	return wordNumber;
}




int readWordsFromTextFiles( char **fileName, int fileNumber, word_t *wordArray){
	int i,j,ind;
	j = 0;//takie i dla niepowtarzalnych slow
	int totalWordNumber = 0; 
	int newTotalWordNumber = 0; 
	
	
	//wstepne liczenie slow we wszystkich plikach
	for(i=0; i<fileNumber; i++){
		totalWordNumber += countWordsInText(fileName[i]);
	}
	printf("totalWordNumber = %d",totalWordNumber);
	//tworzenie tablicy word_t
	//wordArray = malloc(totalWordNumber*sizeof(word_t));
	//wczytywanie slow do tablicyc i ustalenie nowej liczby slow- teraz bez powtorzen
	
	
	for(i=0; i<fileNumber; i++){
		FILE *textFile;
		textFile = fopen(fileName[i],"r");
		word_t newWord;
		printf("findWord\n");
		while(fscanf(textFile,"%s",newWord.text)!= EOF){	
		
			if((ind=findWord(wordArray,j-1,newWord.text))&&(ind!=(-1))){			
				wordArray[ind].numberOfOccurences++;
			}
			else{
				newWord.numberOfOccurences = 1;
				wordArray[j] = newWord;
				j++;
			}
		}
	}
	
	return j;
	
}



//TODO obsluga bledow

/*
newTotalWordNumber = readWordsFromTextFiles(argv,argc,totalWordNumber,wordArray);
	int error = printWordArray(wordArray, newTotalWordNumber);
*/
//ngramElem *readDataFromBaseFile( char *fileName);

