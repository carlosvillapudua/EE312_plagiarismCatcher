/*
 *
 * Created by Jaime Tan Leon (jt39777) & Carlos Villapudua (civ298)
 * Last Edited: 12/7/18
 *
 * */
#include "file.h"
#include "directory.h"
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include "hashTable.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define hashSize 200003         //size of hashTable

using namespace std;

void readFile(string& file);
vector<string> processNWords(vector<string> &word, int n);
void strdFormat(vector<string> &chunk);
unsigned long hashFunction(string chunk);

int main(int argc, char *argv[]){
    int numSim = 200;
    hashTable hashTable1;
//    string dir = string("sm_doc_set");
    string dir = string(argv[1]);
    vector<string> files = vector<string>();                //create a vector for names of files
    directory set;
    set.getdir(dir, files);                                 //place text file names into address "files" points to

    files.erase(files.begin(), files.begin()+2);

    string essay = "";
    string x;
    ifstream inFile;
    vector<string> word;

    for (unsigned int i = 0; i < files.size();i++) {
        string fileName = dir + "/" + files[i];
        inFile.open(fileName.c_str());
        if (!inFile) {
            cout << "error opening file :(";
        }

        while (inFile >> x) {
            word.push_back(x);
        }

        inFile.close();

        vector<string> chunk;
        int n = atoi(argv[2]);
        chunk = processNWords(word, n);                             //chunk is vector of all possible chunks in individual file

        strdFormat(chunk);

        for (int j = 0; j < chunk.size(); j++) {
            unsigned long long keyID = hashTable1.hashFunction(chunk[j]);
            hashTable1.insert(keyID, i);
        }

        word.clear();
    }

    int *cheat[files.size()];                   //create 2D array of files to add instances of similarities to

    for (int k = 0; k < files.size(); k++) {
        cheat[k] = new int[files.size()];       //create rows (however many files there are)
    }

    for (int k = 0; k < files.size(); k++){
        for (int m = 0; m < files.size(); m++){     //initialize each cell in the grid of similarity instances to be zero
            cheat[k][m] = 0;
           //cout << cheat[k][m];
        }
    }

    hashTable1.countCheaters(cheat);                //returns populated grid of how many times each of the files returned same hash key

    vector<string> resultsList;
    for (int k = 0; k < files.size(); k++){
        for (int m = 0; m < files.size(); m++) {
            if(cheat[k][m] >= atoi(argv[3])){
                cout << cheat[k][m] << ":" << files[k] << "," << files[m] << endl;      //prints out possible cheaters
            }
        }
    }


//   hashTable1.deleteNodes();
    for (int k = 0; k < files.size(); k++) {
            delete cheat[k];                                                            //deletes the grid of possible cheaters
    }

    return 0;
}

vector<string> processNWords(vector<string> &word, int n){
    vector<string> retString;
    string chunk = "";

    for(int i = 0; i < word.size()-(n-1); i++){                         //with a moving frame of n size, this places chunks of n size into a vector
        for (int j = 0; j < n; j++){
            chunk += word[i+j];
        }
        retString.push_back(chunk);                                     //add to vector
        chunk="";                                                       //clear chunk to start with new frame
    }
    return retString;
}

void strdFormat(vector<string> &chunk){
    string::iterator iter;
    string indChunk;
    int k;
    bool punctDone = false;


    for (int i = 0; i < chunk.size(); i++){                             //go through each string in vector
        indChunk = chunk[i];
        for (int j = 0; j < indChunk.size(); j++){                      //go through all of char in single string component of vector
                if (punctDone){
                    j--;                                                //since punctuation was erased, go back and check that same index
                    punctDone = false;                                  //set flag to false again
                }

                if ( indChunk[j] >= 'A' && indChunk[j] <= 'Z' ) {       //make uppercase values lowercase
                    k = int(indChunk[j]) + 32;
                    indChunk[j] = (char) k;
                }

                if (((indChunk[j] >= '!' && indChunk[j] <= '/') || (indChunk[j] >= ':' && indChunk[j] <= '@')
                || (indChunk[j] >= '[' && indChunk[j] < 'a') || (indChunk[j] >= '{' && indChunk[j] <= '~')) && indChunk[j]!= string::npos){

                                           //set flag to go back on current index

                }
            }
        chunk[i] = indChunk;                                        //place newly formatted string into actual vector
    }
}
