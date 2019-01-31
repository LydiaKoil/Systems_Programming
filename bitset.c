#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include "bitset.h"



// create a new, empty bit vector set with a universe of 'size' items
struct bitset * bitset_new(int size)
{

  struct bitset *myBitset =malloc(sizeof(struct bitset));
  myBitset->size_in_bits= size;
  myBitset->bits_in_word=sizeof(unsigned)*8;
  myBitset->size_in_words=myBitset->size_in_bits/myBitset->bits_in_word;
  if(myBitset->size_in_bits%myBitset->bits_in_word>0){
	myBitset->size_in_words++;
  }
  // calloc() allocate the memory for x words and 
  // set 0 to all of them 
  myBitset->data=(unsigned*)calloc(myBitset->size_in_words, sizeof(unsigned)); 
  
  return(myBitset); 

}

// get the size of the universe of items that could be stored in the set

int bitset_size(struct bitset * this)
{  
  return this->size_in_bits;

}

// check to see if an item is in the set
int bitset_lookup(struct bitset * this, int item)
{
  int index= item/this->bits_in_word;  // i = array index (use: A[i])
  int offset= item%this->bits_in_word;  // pos = bit position in A[i]
      
  unsigned int flag = 1;   // flag = 0000.....00001

  flag = flag << offset;      // flag = 0000...010...000   (shifted k positions)



  if(( this->data[index] & flag)==0){
   return 0;
  }

  else{
   return 1;
  }
     

}

// get the number of items that are stored in the set
int bitset_cardinality(struct bitset * this)
{
 
  int count=0; 	
  for(int i=0; i<this-> size_in_bits ;i++){
	if(bitset_lookup(this,i)==1){
		count++;
	}
	
  }

  return count;
}



// add an item, with number 'item' to the set
// has no effect if the item is already in the set
void bitset_add(struct bitset * this, int item){

  int index= item / this->bits_in_word;  // i = array index (use: A[i])
  int offset= item % this->bits_in_word;  // pos = bit position in A[i
  unsigned int flag = 1;   // flag = 0000.....00001
  flag = flag << offset;      // flag = 0000...010...000   (shifted k positions)
  this->data[index] = this->data[index] | flag;      // Set the bit at the k-th position in this[i]   

}

// remove an item with number 'item' from the set
void bitset_remove(struct bitset * this, int item)
{
  int index= item/this->bits_in_word;  // i = array index (use: A[i])
  int offset= item%this->bits_in_word;  // pos = bit position in A[i
  unsigned int flag = 1;   // flag = 0000.....00001

  flag = flag << offset;      // flag = 0000...010...000   (shifted k positions)
  flag=~flag;				    // flag = 1111...101...111

  this->data[index] = this->data[index] & flag;      // Set the bit at the k-th position in this[i]  

}

// place the union of src1 and src2 into dest;
// all of src1, src2, and dest must have the same size universe
void bitset_union(struct bitset * dest, struct bitset * src1, struct bitset * src2)
{
  if(src1->size_in_words== src2->size_in_words && dest->size_in_words== src2->size_in_words ){
	for(int i=0; i<src1-> size_in_words;i++){
	dest->data[i]= src1->data[i]|src2->data[i];

	}
	
  }
  else{
    
	return;// bitsets dont have same size universe
  }
}

// place the intersection of src1 and src2 into dest
// all of src1, src2, and dest must have the same size universe
void bitset_intersect(struct bitset * dest, struct bitset * src1,
		      struct bitset * src2)
{
if(src1->size_in_words== src2->size_in_words && dest->size_in_words== src2->size_in_words ){
	for(int i=0; i<src1-> size_in_words;i++){
	dest->data[i]= src1->data[i]&src2->data[i];

	}
	
  }
  else{
    
	return;// bitsets dont have same size universe
  }

}


// print the contents of the bitset
void bitset_print(struct bitset * this)
{
  int i;
  int size = bitset_size(this);
  for ( i = 0; i < size; i++ ) {
    if ( bitset_lookup(this, i) == 1 ) {
      printf("%d ", i);
    }
  }
  printf("\n");
}

// add the characters from a string to a bitset
/*void add_chars_to_set(struct bitset * this, char * s)
{
  int i;
  for ( i = 0; s[i] != 0; i++ ) {
    unsigned char temp = s[i];
    bitset_add(this, temp);
  }
}

// small routine to test a bitset
void test_bitset(char * string1, char * string2)
{
  struct bitset * a = bitset_new(256);
  struct bitset * b = bitset_new(256);
  struct bitset * c = bitset_new(256);

  
  add_chars_to_set(a, string1);
  add_chars_to_set(b, string2);

  // print the contents of the sets
  printf("%s ", "Set A:");	
  bitset_print(a);
  printf("%s ", "Set B:");	
  bitset_print(b);

  // compute and print the union of sets
 printf("%s ", "Union:");	
 bitset_union(c, a, b);
 bitset_print(c);

  // compute and print the intersection of sets
  printf("%s ", "Intersection:");	
  bitset_intersect(c, a, b);
  bitset_print(c);



}

int main(){
  test_bitset("what","who");
  return 0;
}
*/
