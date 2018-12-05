//
// Created by Carlos Villapudua on 12/5/2018.
//

#ifndef PLAGIARISMCATCHER_NEW_HASHTABLE_H
#define PLAGIARISMCATCHER_NEW_HASHTABLE_H
#define hashSize 200003

#include <string>
#include <bits/stdc++.h>

using namespace std;

typedef struct node{
    int index;
    node* next;
}node;

class hashTable {


    public:
        hashTable();
        unsigned long long hashFunction(string chunk);
        void insert(unsigned long keyID, int fileID);
    private:
        node hashArray[hashSize];






};


#endif //PLAGIARISMCATCHER_NEW_HASHTABLE_H
