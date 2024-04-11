void hashInit(int* hashTable, int* input, int M, int R) {
    for (int i = 0; i < M; i++) {
        hashTable[i] = -1; // init hash table with -1 as default
    }

    for (int j = 0; j < M; j++) {  //iterate through input array
        int key = input[j];        //get curr key
        int index = key % M;        //get index
        if (hashTable[index] == -1) {      //checking if index is empty
            hashTable[index] = key;          //if empty, insert key
        } else {                              //if not empty use double hashing
            int h1 = key % M;
            int h2 = R - (key % R);          //method to calculate h2
            int i = 1;
            while (hashTable[(h1 + h2 * i) % M] != -1) {  //while index is not empty
                i++;
            }
            hashTable[(h1 + h2 * i) % M] = key;    //inserting key
        }
    }
}
