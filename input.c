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




int readWordsFromTextFiles( char **fileName, int fileNumber, int totalWordNumber, word_t* wordArray){
	//word_t wordArray[totalWordNumber];
	//wordArray = malloc(totalWordNumber*sizeof(word_t));
	int i,j,ind;
	j=0;
	
	
	for(i=1; i<fileNumber; i++){
		FILE *textFile;
		textFile = fopen(fileName[i],"r");
		word_t newWord;
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


int findWord(word_t *wordArray, int arraySize, char *soughtWord){
	int  i = 0;
	int sought =-1;
	
	while((i<arraySize)&&(sought==(-1))){
		word_t newWord=wordArray[i];
		
		if(strcmp(newWord.text,soughtWord)==0)
			sought = i;
		i++;
	}
	
	return(sought);	
}


int main(int argc, char **argv){
	int i,j;
	int totalWordNumber = 0; 
	int newTotalWordNumber = 0; 
	
	for(i=1; i<argc; i++){
		totalWordNumber += countWordsInText(argv[i]);
	}
	
	printf("calkowita liczba slow we wszystkich plikach to: %d\n",totalWordNumber);
	word_t *wordArray;
	wordArray = malloc(totalWordNumber*sizeof(word_t));
	
	
	newTotalWordNumber = readWordsFromTextFiles(argv,argc,totalWordNumber,wordArray);
	
	for(i=0;i<newTotalWordNumber;i++){
		word_t newWord = wordArray[i]; 
		printf("%s----%d\n",newWord.text,newWord.numberOfOccurences);
	}
		
}




//ngramElem *readDataFromBaseFile( char *fileName);

