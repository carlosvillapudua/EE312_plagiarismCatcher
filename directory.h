/*
 *
 * Created by Jaime Tan Leon (jt39777) & Carlos Villapudua (civ298)
 * Last Edited: 12/7/18
 *
 * */

#ifndef PLAGIARISMCATCHER_DIRECTORY_H
#define PLAGIARISMCATCHER_DIRECTORY_H

#include "file.h"
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
class directory {
public:
    directory();

    //function getdir(string dir, vector<string> &files);
    //places names of files (string) from directory into a vector
    //input: directory path, empty vector
    //output: none (file vector is modified from function)
    void getdir (string dir, vector<string> &files);
private:
    vector <string> files;
    vector<string> getdir (string dir);



};


#endif //PLAGIARISMCATCHER_DIRECTORY_H
