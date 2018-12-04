//
// Created by Carlos Villapudua on 12/3/2018.
//

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
    void getdir (string dir, vector<string> &files);
private:
    vector <string> files;
    vector<string> getdir (string dir);


};


#endif //PLAGIARISMCATCHER_DIRECTORY_H
