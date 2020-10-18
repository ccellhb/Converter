#ifndef GENERATOR_H_
#define GENERATOR_H_

#include <fstream> 
#include "../global.h"
#include "../util/container.h"
#include "../product/product.h"

/* 
* Base class of generators
*/

class Generator {
private: 
    string m_type;                 //generator type
    string m_output_file;          //file name to be generated

public:
    Generator(): m_type("UNKNOWN"){};
    virtual ~Generator(){};
    virtual void setType(string);
    virtual void setFile(string);
    virtual string getFile();
    virtual bool gen(Container<shared_ptr<Product>> &container)=0;  //pure virtual func, core logic of generating file/content.
};

#endif