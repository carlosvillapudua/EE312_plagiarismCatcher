//
// Created by Carlos Villapudua on 12/5/2018.
//

#include "hashTable.h"
#include <math.h>

hashTable::hashTable(){

    for (int n = 0; n < hashSize; n++){
        hashArray[n] = NULL;
    }
}

unsigned long long hashTable::hashFunction(string chunk){
    unsigned long retVal =0;
    unsigned long retValSum = 0;
    for (int i = 0; i < chunk.size()-1; i++){
       /* retVal += chunk[chunk.size() - i - 1] * (pow(3,i));
        retVal = retVal % hashSize;*/

       retVal = chunk[chunk.size() - i -1];
       retVal = retVal * pow(3,i);
       retValSum = retValSum + retVal;
    }
    retValSum = retValSum % hashSize;
    return retValSum;
}

void hashTable::insert(unsigned long long keyID, int fileID){

//    if(hashArray[keyID].index == -1){
//        hashArray[keyID].index  = fileID;
//        hashArray[keyID].next = NULL;
//    }
    node* temp = new node;
    temp->index = fileID;

    if(hashArray[keyID] == NULL){
        temp->next = NULL;
    }
    else{
        temp->next = hashArray[keyID];
    }
    hashArray[keyID] = temp;
}

void hashTable::countCheaters(int* cheat[]){
    node* ptr;
    node* ptr2;

    for (int i = 0; i < hashSize; i ++) {
        if (hashArray[i] == NULL || hashArray[i]->next == NULL) {}              //do nothing because there is only one entry or no entries at all
        else {
            ptr = hashArray[i];
            ptr2 = hashArray[i]->next;
            while (ptr != NULL) {
                 while (ptr2 != NULL) {
                     if (ptr2->index != ptr->index) {
                         cheat[ptr2->index][ptr->index]++;
                     }
                     ptr2 = ptr2->next;
                 }
                 ptr = ptr->next;
                 ptr2 = ptr;
            }
        }
    }
}

void hashTable::deleteNodes(){

    for (int k = 0; k < hashSize; k++){
        node* ptr = hashArray[k];
        node* temp = ptr;
        while (ptr != NULL){
            ptr = ptr->next;
            delete temp;
            temp = ptr;
        }
        delete temp;
    }
}