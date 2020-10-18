#include "test.h"

bool testXML2HTML(string input_file, string output_file){
    //create parser based on input file name
    shared_ptr<Parser> parser=ParserFactory::getInstance().create(FileUtil::getType(input_file));
    if(!parser){
        cerr<<"File format not supported."<<endl;
        return false;
    }
    parser->setFile(input_file);

    //create container to store products
    Container<shared_ptr<Product>> container;
    parser->doParse(container);

    //create generator based on output file name
    shared_ptr<Generator> generator=GeneratorFactory::getInstance().create(FileUtil::getType(output_file)); 
    if(!generator){
        cerr<<"File format not supported."<<endl;
        return false;
    }
    generator->setFile(output_file);
    generator->gen(container);
    return true;
}