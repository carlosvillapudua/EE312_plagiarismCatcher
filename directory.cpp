/*
 *
 * Created by Jaime Tan Leon (jt39777) & Carlos Villapudua (civ298)
 * Last Edited: 12/7/18
 *
 * */
#include "directory.h"


directory::directory() {

    vector <string> files;
}

void directory::getdir (string dir, vector<string> &files){
    files = getdir(dir);
}



vector <string> directory::getdir (string dir) {
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return files;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return files;
}