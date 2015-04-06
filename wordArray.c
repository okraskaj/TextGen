#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wordArray.h"

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
	
int printWordArray(word_t *wordArray, int arraySize){
	int i;
	for(i=0;i<arraySize;i++){
		word_t newWord = wordArray[i]; 
		printf("%s\t\t%d\n",newWord.text,newWord.numberOfOccurences);
	}

}
