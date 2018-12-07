/*
 *
 * Created by Jaime Tan Leon (jt39777) & Carlos Villapudua (civ298)
 * Last Edited: 12/7/18
 *
 * */

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
    //function hashTable();
    //creates a hashMap of hashSize size
    //input: none
    //output: none
        hashTable();


    //function unsigned long long hashFunction(string chunk);
    //takes key (string) and returns an index within range of size of hashTable
    //input: string of n-words(key)
    //output: unsigned long long keyID
        unsigned long long hashFunction(string chunk);


    //function: insert(unsigned long long keyID, int fileID);
    //places index of file into hashTable @ hashTable index of keyID
    //input: unsigned long long keyID (index for hashTable), int (index of file in file vector)
    //output: none
        void insert(unsigned long long keyID, int fileID);


    //function: countCheaters(int* cheat[]);
    //counts similarities between files and places at intersection of file indexes (within pre-created array)
    //input: address of 2D array
    //output: none (changes 2D array from function)
        void countCheaters(int* cheat[]);


    //function: deleteNodes()
    //deletes all nodes in each index of hashArray
    //input: none
    //output: none
        void deleteNodes();


    //function: ~hashTable()
    //calls deleteNodes
    //input: none
    //output: none
        ~hashTable();
    private:
        node* hashArray[hashSize];
};


#endif //PLAGIARISMCATCHER_NEW_HASHTABLE_H
