#include "freeList.h"

freeList::freeList( long int*inRAM, int size ) {
head=inRAM; //create a pointer to an array's element that is size
head[0]=size-2; //create the first element of head that is size but have to substract 2 because that's the size of the header itself
*next=NULL; //create the second element of head which is pointer to the next element in the free list
head[1]=next;
}

long int*
freeList::reserve_space( int size ) {
  long int* loc = NULL;
  loc = head+4; //to return address of the allocation space
  return loc;
}

void
freeList::free_space( long int* location ) {
  head[1]=location-2; //setting next of the head to input location (2 before to start from metadata header)
}

void
freeList::coalesce_forward() {
if head[0]==0:
}

// print() is given to you. It traverses the free list and prints out what is there.
void freeList::print() {
  long int * printHead = head;
  
  while( printHead != NULL ) {
    cout << "at " << printHead << "("<< dec <<printHead[0] << " : 0x" << hex << printHead[1] <<  ")\n";
    printHead = (long int *)printHead[1];
  }
}

