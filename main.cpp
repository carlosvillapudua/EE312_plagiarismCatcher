#include "file.h"
#include "directory.h"
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

typedef struct node{
    int index;
    node* next;
}node;
#define hashSize 200003


using namespace std;
void readFile(string& file);
vector<string> processNWords(vector<string> &word, int n);
void strdFormat(vector<string> &chunk);
unsigned long hashFunction(string chunk);

int main(){

    node hashTable[hashSize];


    string dir = string("sm_doc_set");
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
        string fileName ="sm_doc_set/" + files[i];
        inFile.open(fileName);
        if (!inFile) {
            cout << "error opening file :(";
        }

        while (inFile >> x) {
            word.push_back(x);
        }

        inFile.close();
    }

    vector <string> chunk;
    int n = 6;
    chunk = processNWords(word, n);                 //chunk is vector of all possible chunks in individual file


    strdFormat(chunk);

    unsigned long test = hashFunction("hellooWorldhello");
    cout << test;

//    for (int m = 0; m < chunk.size(); m++){
//        cout << chunk[m] << endl;
//    }


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

                  indChunk.erase(j, 1);
                  punctDone = true;

                }
            }
        chunk[i] = indChunk;
    }
}

unsigned long hashFunction(string chunk){
     unsigned long retVal =0;
     for (int i = 0; i < chunk.size()-1; i++){
         retVal += chunk[chunk.size() - i - 1] * (31 * exp(i));
     }
     retVal = retVal % hashSize;
     return retVal;

}
