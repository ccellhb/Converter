#include "parserfactory.h"

ParserFactory& ParserFactory::getInstance()
{
    static ParserFactory parserFactory;
    return parserFactory;
}

void ParserFactory::Register(string typeName, ParserCreator creator)
{
    if (creator)
    {
        parserRigistry[typeName]=creator;
    }
}

shared_ptr<Parser> ParserFactory::create(string typeName)
{
    //if it's a registered type, call the function to create object, otherwise return null pointer
    if(parserRigistry.count(typeName)!=0) {
        return parserRigistry[typeName]();
    }
    return nullptr;
}

