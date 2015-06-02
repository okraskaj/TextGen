#include "input.h"
//#include "output.h"
#include "./ngramTree/tree.h"
#include "wordArray.h"
#include "attributes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
word_t *wordArray;

int rng; 



int main(int argc, char **argv){
	int i;
	attributes_t attributes;
	attributes = readAttributes(argc, argv);
	//printAttributes(attributes);
	rng=attributes.ngramLevel;
	
	
	if (attributes.error == 0){
		node *root; // sadzenie drzewa na ngramy
		root = NULL;				
		readNgramsFromTextFiles( attributes.inFile, attributes.inFileNumber, &root, attributes.ngramLevel);		
		//printout(root,attributes.ngramLevel,0);		
		gener(root, attributes.ngramLevel, attributes.wordNumber);
		//printConnections(root,attributes.ngramLevel,0);
		free(root);
		//}
		//else return 0;
					
	}
	else 
		return 0; 
	
}
