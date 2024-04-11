#include <stdio.h>

/*
  Coding Requirements:

  Starting from an empty project, you must:

  In a hash.c file, write a function that creates and fills a hash table. The function prototype should be as follows:
   hashInit(int* hashTable, int* input, int M, int R);

   In this prototype:

  hashTable is an array used to store the hashed values
  input is an array of integers
  M is the length of the hash table and the input array (they are always the same)
  R is the value used in the double hash
  Your implementation will use double hashes to handle collisions.

  Your implementation will use the following hashes:

  h(k) = (h1(k) + h2(k)*i) mod M, where i=1:M, or i=0:M (depending on how you use it)

  h1(k) = k mod M

  h2(k) = R - (k mod R)

  Write a main.c file which calls the hashInit function using the following input parameters:
  input = {764, 35954, 8683, 41, 11004, 1362, 77, 1, 448, 118, 5507}
  M = 11
  R = 7
  Once the hash table has been filled, print the contents of the hash table from 0 to M-1
     */

// HashInit function is in hash.c

void hashInit(int* hashTable, int* input, int M, int R);

int main() {
    int hashTable[11];
    int input[] = {764, 35954, 8683, 41, 11004, 1362, 77, 1, 448, 118, 5507};
    int M = 11;    //length of hash table and input array
    int R = 7;     //value used in double hash

    hashInit(hashTable, input, M, R);  //fill hash table

    printf("Hash Table Below: \n");
    for (int i = 0; i < M; i++) {
        printf("%d = %d\n", i, hashTable[i]);
    }

    return 0;
}
