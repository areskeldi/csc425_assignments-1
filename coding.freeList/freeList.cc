#include "freeList.h"

freeList::freeList( long int*inRAM, int size ) {
head=inRAM; //create a pointer to an array's element that is size
head[0]=size-2; //create the first element of head that is size but have to substract 2 because that's the size of the header itself
head[1]=0; //create the second element of head which is pointer to the next element in the free list
}

long int*
freeList::reserve_space( int size ) {
  long int* loc = NULL;
  loc = head + 2; //to return address of the allocation space
  loc[0] = size; // saves the size of the space for future use based on input to the function, we need this when we free this space
  head = loc+size; //updates the head pointer to now be where the reserved chunk ends!
  head[0]=loc[0]-size; //makes the space of the updated free chunk to reflect that we just reserved space, so now the chunk has to be starting at the place where the inputted size ends
  return loc;
}

void
freeList::free_space( long int* location ) {
  long int *next = head; //temporary variable to make sure we save the pointer of the current head for future use when declaring next for the head
  head = location-2; //now we have a new head because we freed space
  head[1] = (long int)next; // the header needs to point to the previous head
}

void
freeList::coalesce_forward() {
  while(head[1] != 0) {
    long int* ref2 = head + 2 + head[0];//temporary variable we need for future comparison to coalesce
    long int* next = (long int*)head[1];//temp variable for the chunk that will be joined to the chunk behind it

   if(ref2 == next) {
        head[0] = head[0] + 2 + next[0]; //updates the size of the newly coalesced chunk
        head[1] = next[1]; //updates the next to be the next of the chunk ahead
      }
  }
}
// print() is given to you. It traverses the free list and prints out what is there.
void freeList::print() {
  long int * printHead = head;
  
  while( printHead != NULL ) {
    cout << "at " << printHead << "("<< dec <<printHead[0] << " : 0x" << hex << printHead[1] <<  ")\n";
    printHead = (long int *)printHead[1];
  }
}

