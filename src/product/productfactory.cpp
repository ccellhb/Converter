#include "productfactory.h"

ProductFactory& ProductFactory::getInstance()
{
    static ProductFactory productFactory;
    return productFactory;
}

void ProductFactory::Register(string typeName, ProductCreator creator)
{
    if (creator)
    {
        productRigistry[typeName]=creator;
    }
}

shared_ptr<Product> ProductFactory::create(string typeName)
{
    //if it's a registered type, call the function to generate object, otherwise return null pointer
    if(productRigistry.count(typeName)!=0) {
        return productRigistry[typeName]();
    }
    return nullptr;
}

