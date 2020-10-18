#include <fstream> 
#include "generator.h"

void Generator::setType(string type){
    m_type=type;
}

void Generator::setFile(string output_file){
    m_output_file=output_file;
}

string Generator::getFile(){
    return m_output_file;
}

