#ifndef PARSER_H_
#define PARSER_H_

#include "../global.h"
#include "../util/container.h"
#include "../product/product.h"

//Base class of parsers
class Parser {
private: 
    string m_type;           //type of parser
    string m_input_file;     //input file name

public:
    Parser(): m_type("UNKNOWN"){};
    virtual ~Parser(){};
    virtual bool doParse(Container<shared_ptr<Product>>&)=0;   //pure virtual function, core logic of parse
    virtual void setFile(string);
    virtual void setType(string);
    virtual string getFile();
};

#endif