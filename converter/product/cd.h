
#ifndef CD_H_
#define CD_H_
#include "../global.h"
#include "product.h"
#include "productfactory.h"

using namespace std;

class CD : public Product{
private:
    string m_title;
    string m_artist;
    string m_country;
    string m_company;
    string m_price;
    string m_year;
    typedef void (CD::*setfunc_ptr)(string str);
    typedef string (CD::*getfunc_ptr)();
    unordered_map<string, setfunc_ptr> setFuncMap;                    //registry of fields. key=fieldName, value=setter pointer
    unordered_map<string, getfunc_ptr> getFuncMap;                    //registry of fields. key=fieldName, value=getter pointer
    vector<string> FIELDS= {"TITLE", "ARTIST", "COUNTRY", "COMPANY", "PRICE", "YEAR"};

public:
    CD ();
    ~CD(){};
    vector<string> getFields() override;                        //get all registered fields
    string getFieldValue(string &field) override;               //get value of a field
    bool setValues(string &field, string &value) override;      //set value for each registered field
    void registerFields() override;                             //register all fields of object, set function call for each field

    string getTitle();
    string getArtist();
    string getCountry();
    string getCompany();
    string getPrice();
    string getYear();
    void setTitle(string);
    void setArtist(string);
    void setCountry(string);
    void setCompany(string);
    void setPrice(string);
    void setYear(string);
};

#endif