//#include "input.h"
//#include "output.h"
//#include "ngramArray.h"
//#include "wordArray.h"
#include "attributes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main(int argc, char **argv){

	attributes_t attributes;
	attributes = readAttributes(argc, argv);
	
	if (attributes.error == 0){
		printAttributes(attributes);
		
		
		
		
		
		
			
	}
	else 
		return 0; 
	
}
