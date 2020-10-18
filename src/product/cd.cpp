#include "cd.h"

//register CD to Product registry
REGISTER_PRODUCT(CD, CD);

//CD::FIELDS = {"TITLE", "ARTIST", "COUNTRY", "COMPANY", "PRICE", "YEAR"};

CD::CD ():m_title("UNKNOWN"), m_artist("UNKNOWN"), m_country("UNKNOWN"), m_company("UNKNOWN"), m_price("UNKNOWN"), m_year("UNKNOWN") {
    setCategory("CD");
    registerFields();
}

vector<string> CD::getFields(){
    return FIELDS;
}
string CD::getFieldValue(string &filedName) {
    if(getFuncMap.count(filedName)) {
        return (this->*getFuncMap[filedName])();
    }
    else {
        cout<<"WARNING: Field ("<<filedName<<") is not registered."<<endl;
        return "Unknown";
    }
}

//register all fields of object, setter/getter function call for each field
void CD::registerFields () {
    setFuncMap[FIELDS[0]]=&CD::setTitle;
    setFuncMap[FIELDS[1]]=&CD::setArtist;
    setFuncMap[FIELDS[2]]=&CD::setCountry;
    setFuncMap[FIELDS[3]]=&CD::setCompany;
    setFuncMap[FIELDS[4]]=&CD::setPrice;
    setFuncMap[FIELDS[5]]=&CD::setYear;

    getFuncMap[FIELDS[0]]=&CD::getTitle;
    getFuncMap[FIELDS[1]]=&CD::getArtist;
    getFuncMap[FIELDS[2]]=&CD::getCountry;
    getFuncMap[FIELDS[3]]=&CD::getCompany;
    getFuncMap[FIELDS[4]]=&CD::getPrice;
    getFuncMap[FIELDS[5]]=&CD::getYear;
}

//set value for each registered field
bool CD::setValues(string &filedName, string &value){
    transform(filedName.begin(),filedName.end(),filedName.begin(),::toupper);
    if(setFuncMap.count(filedName)) {
        (this->*setFuncMap[filedName])(value);
        return true;
    }
    else {
        cout<<"WARNING: Field ("<<filedName<<") is not registered."<<endl;
        return false;
    }
}

void CD::setTitle(string title) {
    m_title=title;
}

void CD::setArtist(string artist) {
    m_artist=artist;
}

void CD::setCountry(string country) {
    m_country=country;
}

void CD::setCompany(string company) {
    m_company=company;
}

void CD::setPrice(string price) {
    m_price=price;
}

void CD::setYear(string year) {
    m_year=year;
}

string CD::getTitle(){
    return m_title;
}

string CD::getArtist(){
    return m_artist;
}

string CD::getCountry(){
    return m_country;
}

string CD::getCompany(){
    return m_company;
}

string CD::getPrice(){
    return m_price;
}

string CD::getYear(){
    return m_year;
}
    

