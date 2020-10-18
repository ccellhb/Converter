#include "global.h"
#include "test/test.h"

int main(int argc, char **argv) {

    if(argc!=2) {
        cout<<"Usage: converter input_file_name"<<endl;
    }
    if(argc>2) {
        cout<<"Only one input file supported"<<endl;
    }
    if(argc!=2) return -1;

    cout<<"---- Conversion started ----"<<endl;

    string input_file=string(argv[1]);
    string output_file="result.html";
    
    try{
        testXML2HTML(input_file, output_file);
    }
    catch(exception &e) {
        cerr<<e.what()<<endl;
        cout<<"---- Conversion completed with error----"<<endl;
        return -2;
    }

    cout<<"---- Conversion completed ----"<<endl;
    return 0;
}