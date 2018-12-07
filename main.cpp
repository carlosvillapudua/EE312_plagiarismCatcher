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

#define hashSize 200003


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
    vector<string> files = vector<string>();
    directory set;
    set.getdir(dir, files);                             //place text file names into address "files" points to

    files.erase(files.begin(), files.begin()+2);

    for (unsigned int i = 0;i < files.size();i++) {
        cout << i << files[i] << endl;
    }




    string essay = "";
    string x;
    ifstream inFile;
    vector<string> word;

    for (unsigned int i = 0; i < files.size();i++) {
        string fileName = dir + files[i];
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
        chunk = processNWords(word, n);                 //chunk is vector of all possible chunks in individual file


        strdFormat(chunk);

        for (int j = 0; j < chunk.size(); j++) {
            unsigned long long keyID = hashTable1.hashFunction(chunk[j]);
            hashTable1.insert(keyID, i);
            //cout << keyID << endl;
        }



//        for (int m = 0; m < chunk.size(); m++) {
//            cout << chunk[m] << endl;
//        }
        word.clear();
    //cout << "------------------------------------------";
    }
    //int *cheat[files.size()][files.size()];

    int *cheat[files.size()];

    for (int k = 0; k < files.size(); k++) {
        cheat[k] = new int[files.size()];
    }


    for (int k = 0; k < files.size(); k++){
        for (int m = 0; m < files.size(); m++){
            cheat[k][m] = 0;
           //cout << cheat[k][m];
        }
    }



    hashTable1.countCheaters(cheat);

//    for (int k = 0; k < files.size(); k++){
//        for (int m = 0; m < files.size(); m++){
//
//            cout << cheat[k][m] << " ";
//        }
//        cout << endl;
//    }

    for (int k = 0; k < files.size(); k++){
        for (int m = 0; m < files.size(); m++) {
            if(cheat[k][m] >= atoi(argv[3])){
                cout << cheat[k][m] << ":" << files[k] << "," << files[m] << endl;
            }
        }
    }

    hashTable1.deleteNodes();
    for (int k = 0; k < files.size(); k++) {
        for (int m = 0; m < files.size(); m++) {
            delete cheat[k];
        }
    }

    return 0;
}

vector<string> processNWords(vector<string> &word, int n){
    vector<string> retString;
    string chunk = "";
    //vector<string>::const_iterator iter;

    for(int i = 0; i < word.size()-(n-1); i++){
        for (int j = 0; j < n; j++){
            chunk += word[i+j];
        }
        retString.push_back(chunk);
        chunk="";
    }


    return retString;
}

void strdFormat(vector<string> &chunk){
    string::iterator iter;
    string indChunk;
    int k;
    bool punctDone = false;


    for (int i = 0; i < chunk.size(); i++){
        indChunk = chunk[i];
        for (int j = 0; j < indChunk.size(); j++){
                if (punctDone){
                    j--;
                    punctDone = false;
                }

                if ( indChunk[j] >= 'A' && indChunk[j] <= 'Z' ) {
                    k = int(indChunk[j]) + 32;
                    indChunk[j] = (char) k;
                }

                if ((indChunk[j] >= '!' && indChunk[j] <= '/') || (indChunk[j] >= ':' && indChunk[j] <= '@')
                || (indChunk[j] >= '[' && indChunk[j] < 'a') || (indChunk[j] >= '{' && indChunk[j] <= '~')){

                  //indChunk.erase(j, 1);
                  //punctDone = true;

                }
            }
        chunk[i] = indChunk;
    }
}
