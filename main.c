#include "input.h"
//#include "output.h"
//#include "ngramArray.h"
#include "wordArray.h"
#include "attributes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
word_t wordArray[25]; 



int main(int argc, char **argv){
	attributes_t attributes;
	attributes = readAttributes(argc, argv);
	
	if (attributes.error == 0){
		//printAttributes(attributes);
		
			
		int wordNumber=readWordsFromTextFiles( attributes.inFile,attributes.inFileNumber+1, wordArray);
		word_t newWord;
		
		newWord = wordArray[0];
		printf("Jestem tutaj, a 1 element tablicy to: %s",newWord.text);
		if(wordNumber > 0){
			int error = printWordArray(wordArray, wordNumber);
		
		
		
		}
		else return 0;
					
	}
	else 
		return 0; 
	
}
