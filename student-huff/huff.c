// code for a huffman coder


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

#include "huff.h"


// create a new huffcoder structure
struct huffcoder *  huffcoder_new()
{
	struct huffcoder my_huff=malloc (sizeof(struct huffcoder));
	//my_huff->tree=malloc(sizeof(struct huffchar);
	return  my_huff;
}

// count the frequency of characters in a file; set chars with zero
// frequency to one
void huffcoder_count(struct huffcoder * this, char * filename)
{ 
	
	unsigned char c;  // we need the character to be
                    // unsigned to use it as an index
	File * file;
	file = fopen(filename, "r");
	assert( file != NULL );
	c = fgetc(file);	// attempt to read a byte
	while( !feof(file) ) {
		this->freqs[c]++;   //add to frequency of 
		
		printf("%c", c);
		c = fgetc(file);
		
		
	}
	for(int i=0; i<NUM_CHARS ; i++){
		if this->freqs[i]==0{
			this->freqs[i]==1;
		}
		printf("Frequency: ");
		printf("i", freqs[i]);
	}
	
	
	fclose(file);
			
		
		
	

}


// using the character frequencies build the tree of compound
// and simple characters that are used to compute the Huffman codes
void huffcoder_build_tree(struct huffcoder * this)
{

}


// recursive function to convert the Huffman tree into a table of
// Huffman codes
void tree2table_recursive(struct huffcoder * this, struct huffchar * node,
		 int * path, int depth)
{

}

// using the Huffman tree, build a table of the Huffman codes
// with the huffcoder object
void huffcoder_tree2table(struct huffcoder * this)
{

}


// print the Huffman codes for each character in order
void huffcoder_print_codes(struct huffcoder * this)
{
  int i, j;
  char buffer[NUM_CHARS];

  for ( i = 0; i < NUM_CHARS; i++ ) {
    // put the code into a string
    for ( j = this->code_lengths[i]-1; j >= 0; j--) {
      buffer[j] = (this->codes[i] >> j) & 1 + '0';
    }
    // don't forget to add a zero to end of string
    buffer[this->code_lengths[i]] = '\0';

    // print the code
    printf("char: %d, freq: %d, code: %s\n", i, this->freqs[i], buffer);;
  }
}
