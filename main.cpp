#include "file.h"
#include "directory.h"
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>


using namespace std;
void readFile(string& file);
vector<string> processNWords(vector<string> &word, int n);
void strdFormat(vector<string> &chunk);

int main()
{
    string dir = string("sm_doc_set");
    vector<string> files = vector<string>();
    directory set;
    set.getdir(dir, files);                             //place text file names into address "files" points to

    for (unsigned int i = 0;i < files.size();i++) {
        cout << i << files[i] << endl;
    }
//    readFile(files[0]);



    string essay = "";
    string x;
    ifstream inFile;
    vector<string> word;

    for (unsigned int i = 0; i < files.size();i++) {
        string fileName ="sm_doc_set/" + files[i];
        inFile.open(fileName);
        if (!inFile) {
            cout << "error opening file :(";
            //exit(1); // terminate with error
        }

        while (inFile >> x) {
//            essay = essay + x + "\n";
            word.push_back(x);

        }

        inFile.close();
        //cout << "Essay = " << essay << endl;
    }

    vector <string> chunk;
    int n = 2;
    chunk = processNWords(word, n);                 //chunk is vector of all possible chunks in individual file
//    for(int j = 0; j < word.size()-5; j++){
//        for(int k = 0; k < 6; k++) {
//            cout << word[j+k] << " ";
//        }
//        cout << "\n";
//    }
//    cout << word.size() << endl;
    // word.erase(&word);

    for (int m = 0; m < chunk.size(); m++){
        cout << chunk[m] << endl;
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

//
//void strdFormat(vector<string> &chunk){
//    string::iterator iter;
//    string& indChunk;
//
//
//    for (int i = 0; i < chunk.size(); i++){
//        indChunk = chunk[i];
//        char* Letter = indChunk.c_str();
//
//
//    }
//}


/*function... might want it in some class?*/
//int getdir (string dir, vector<string> &files)
//{
//    DIR *dp;
//    struct dirent *dirp;
//    if((dp  = opendir(dir.c_str())) == NULL) {
//        cout << "Error(" << errno << ") opening " << dir << endl;
//        return errno;
//    }
//
//    while ((dirp = readdir(dp)) != NULL) {
//        files.push_back(string(dirp->d_name));
//    }
//    closedir(dp);
//    return 0;
//}







//void readFile(string& file){
//    string sum = "";
//    string x;
//    ifstream inFile;
//
//    inFile.open(file);
//    if (!inFile) {
//        cout << "Unable to open file";
//        exit(1); // terminate with error
//    }
//
//    while (inFile >> x) {
//        sum = sum + x;
//    }
//
//    inFile.close();
//    cout << "Sum = " << sum << endl;
//
//}









