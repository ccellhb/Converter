#include "generatorfactory.h"

GeneratorFactory& GeneratorFactory::getInstance()
{
    static GeneratorFactory generatorFactory;
    return generatorFactory;
}

void GeneratorFactory::Register(string typeName, GeneratorCreator creator)
{
    if (creator)
    {
        generatorRigistry[typeName]=creator;
    }
}

shared_ptr<Generator> GeneratorFactory::create(string typeName)
{
    //if it's a registered type, call the function to generate object, otherwise return null pointer
    if(generatorRigistry.count(typeName)!=0) {
        return generatorRigistry[typeName]();
    }
    return nullptr;
}

