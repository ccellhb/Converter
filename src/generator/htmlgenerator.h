#ifndef HTMLGENERATOR_H_
#define HTMLGENERATOR_H_

#include <fstream> 
#include "../global.h"
#include "generator.h"
#include "../product/cd.h"
#include "generatorfactory.h"

/*
HTMLGenerator: generate HTML files
*/
class HTMLGenerator: public Generator {

public:
    HTMLGenerator();
    ~HTMLGenerator(){};
    bool gen(Container<shared_ptr<Product>> &container) override;                        //Generator::gen implementation
    void writeHead(ofstream& targetFile,Container<shared_ptr<Product>> &container);      //generate HTML elements before content 
    void writeTail(ofstream& targetFile);                                                //generate HTML elements after content 
    void writeContent(ofstream& targetFile,Container<shared_ptr<Product>> &container);   //generate content 
};

#endif