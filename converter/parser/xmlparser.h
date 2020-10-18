#ifndef XMLPARSER_H_
#define XMLPARSER_H_

#include "../global.h"
#include "../lib/tinyxml2.h"
#include "../util/container.h"
#include "../product/cd.h"
#include "parser.h"
#include "parserfactory.h"

/*
XMLParser: parse xml files
*/
class XMLParser: public Parser {
private: 
    tinyxml2::XMLDocument m_xmldoc;     //tinyxml2 object

public:
    XMLParser();      
    ~XMLParser(){};
    bool doParse(Container<shared_ptr<Product>>&) override;     //Parser::doParse implementation
};

#endif