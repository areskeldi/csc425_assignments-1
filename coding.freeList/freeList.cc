#include "freeList.h"

freeList::freeList( long int*inRAM, int size ) {
head=inRAM; //create a pointer to an array's element that is size
head[0]=size-2; //create the first element of head that is size but have to substract 2 because that's the size of the header itself
head[1]=0; //create the second element of head which is pointer to the next element in the free list
}

long int*
freeList::reserve_space( int size ) {
  long int* loc = NULL;
  loc = head; //to return address of the allocation space
  head = loc+size;
  head[0]=loc[0]-size;
  loc[0]=size;
  return loc;
}

void
freeList::free_space( long int* location ) {
  long int *next = head;
  head = location;
  head[1] = (long int)next;
}

void
freeList::coalesce_forward() {
  while(head[1] != NULL) {
    long int *next = NULL;
    next = (long int*)head[1];
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

