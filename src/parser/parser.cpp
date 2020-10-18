#include "parser.h"

void Parser::setType(string type){
    m_type=type;
}

void Parser::setFile(string file){
    m_input_file=file;
}

string Parser::getFile(){
    return m_input_file;
}
