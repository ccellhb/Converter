#ifndef PRODUCT_H_
#define PRODUCT_H_

#include "../global.h"

/*
base class of products
*/
class Product {
private:
    string m_category;
public:
    void setCategory(string category);
    string getCategory();
    virtual ~Product() {}
    virtual void registerFields()=0;                            //register all fields of object, set function call for each field
    virtual bool setValues(string &field, string &value)=0;     //set value for each registered field
    virtual vector<string> getFields()=0;                       //get all registered fields
    virtual string getFieldValue(string &field)=0;              //get value of a field
};

#endif