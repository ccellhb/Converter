#ifndef PARSER_FACTORY_H_
#define PARSER_FACTORY_H_

#include "parser.h"

typedef shared_ptr<Parser> (*ParserCreator)();

/*  
Factory class of parsers 
*/
class ParserFactory {
private: 
    ParserFactory(){};
    unordered_map<string, ParserCreator> parserRigistry;        //registry of parsers. key=type, value=function pointer

public:
    virtual ~ParserFactory(){};
    virtual shared_ptr<Parser> create(string typeName);         //create parser objects
    static ParserFactory& getInstance();                        //get factory instance
    void Register(string typeName, ParserCreator creator);      //register parser based on type
};

/* 
Reflector class of parsers. 
Used for registering Parser, so factory can create different objects accordingly
*/
class ParserReflector
{
public:
    ParserReflector(string typeName, ParserCreator creator)
    {
        ParserFactory::getInstance().Register(typeName, creator);
    }
    virtual ~ParserReflector(){}

};

/* 
macro for subclass registration 
*/
#define REGISTER_PARSER(typeName, className) \
    shared_ptr<Parser> createor##className() \
    { \
        return shared_ptr<Parser>(new className); \
    } \
    ParserReflector ParserReflector##className(#typeName, createor##className); \


#endif