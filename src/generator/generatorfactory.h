#ifndef GENERATOR_FACTORY_H_
#define GENERATOR_FACTORY_H_
#include "generator.h"

typedef shared_ptr<Generator> (*GeneratorCreator)();

/*  
Factory class of generators 
*/
class GeneratorFactory {
private: 
    GeneratorFactory(){};
    unordered_map<string, GeneratorCreator> generatorRigistry;      //registry of subclass. key=type, value=function pointer

public:
    virtual ~GeneratorFactory(){};
    virtual shared_ptr<Generator> create(string typeName);          //create generator objects
    static GeneratorFactory& getInstance();                         //get factory instance
    void Register(string typeName, GeneratorCreator creator);       //register generator based on type
};

/* 
Reflector class of generators. 
Used for registering Generator, so factory can create different objects accordingly
*/
class GeneratorReflector
{
public:
    GeneratorReflector(string typeName, GeneratorCreator creator)
    {
        GeneratorFactory::getInstance().Register(typeName, creator);
    }
    virtual ~GeneratorReflector(){}

};

/* 
macro for subclass registration 
*/
#define REGISTER_GENERATER(typeName, className) \
    shared_ptr<Generator> createor##className() \
    { \
        return shared_ptr<Generator>(new className); \
    } \
    GeneratorReflector GeneratorReflector##className(#typeName, createor##className); \


#endif