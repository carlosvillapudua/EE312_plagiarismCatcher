//
// Created by Carlos Villapudua on 12/5/2018.
//

#include "hashTable.h"

hashTable::hashTable(){

    for (int n = 0; n < hashSize; n++){
        hashArray[n].index = -1;
    }
}

unsigned long long hashTable::hashFunction(string chunk){
    unsigned long long retVal =0;
    for (int i = 0; i < chunk.size()-1; i++){
        retVal += chunk[chunk.size() - i - 1] * (31 * exp(i));
        retVal = retVal % hashSize;
    }
    retVal = retVal % hashSize;
    return retVal;
}

void hashTable::insert(unsigned long keyID, int fileID){

    if(hashArray[keyID].index == -1){
        hashArray[keyID].index  = fileID;
        hashArray[keyID].next = NULL;
    }else{
        node* temp = new node;
        temp->index = fileID;
        if(hashArray[keyID].next == NULL){
            temp->next = NULL;
            hashArray[keyID].next = temp;
        }
        else{
            temp->next = hashArray[keyID].next;
            hashArray[keyID].next = temp;
        }

    }
}