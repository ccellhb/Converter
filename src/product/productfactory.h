µ#ifndef PRODUCT_FACTORY_H_
#define PRODUCT_FACTORY_H_

#include "product.h"

typedef shared_ptr<Product> (*ProductCreator)();

/*  
Factory class of products 
*/
class ProductFactory {
private: 
    ProductFactory(){};
    unordered_map<string, ProductCreator> productRigistry;      //registry of products. key=type, value=function pointer

public:
    virtual ~ProductFactory(){};
    virtual shared_ptr<Product> create(string typeName);        //create sub objects
    static ProductFactory& getInstance();                       //get factory instance
    void Register(string typeName, ProductCreator creator);     //register product based on type
};

/* 
Reflector class of products. 
Used for registering Product, so factory can create different objects accordingly
*/
class ProductReflector
{
public:
    ProductReflector(string typeName, ProductCreator creator)
    {
        ProductFactory::getInstance().Register(typeName, creator);
    }
    virtual ~ProductReflector(){}

};

/* 
macro for subclass registration 
*/
#define REGISTER_PRODUCT(typeName, className) \
    shared_ptr<Product> createor##className() \
    { \
        return shared_ptr<Product>(new className); \
    } \
    ProductReflector ProductReflector##className(#typeName, createor##className); \


#endif
