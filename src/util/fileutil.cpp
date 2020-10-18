#include "fileutil.h"

/*
get extension of given file
input: file_name
output: file extension, or "Unknown" if extension doesn't exist
*/
string FileUtil::getType(string filename){
    int pos=filename.find_last_of(".");
    if(pos==string::npos) {
        return "Unknown";
    }
    string type=filename.substr(pos+1);
    transform(type.begin(),type.end(),type.begin(),::toupper);
    return type;
}