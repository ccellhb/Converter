#include "xmlparser.h"

//register XMLParser
REGISTER_PARSER(XML, XMLParser);

XMLParser::XMLParser(){
    setType("XML");
};

bool XMLParser::doParse(Container<shared_ptr<Product>> &container)
{
    //load and check input file
    m_xmldoc.LoadFile(this->getFile().c_str());
    if(m_xmldoc.ErrorID()==tinyxml2::XML_ERROR_FILE_NOT_FOUND){
        throw std::runtime_error(std::string("File not found: ") + this->getFile());
        return false;
    }
    else if(m_xmldoc.ErrorID()==tinyxml2::XML_ERROR_FILE_READ_ERROR || m_xmldoc.ErrorID()==tinyxml2::XML_ERROR_MISMATCHED_ELEMENT){
        throw std::runtime_error(std::string("File Format Error: ") + this->getFile());
        return false;
    }
    else if(m_xmldoc.ErrorID()!=tinyxml2::XML_SUCCESS){
        throw std::runtime_error(std::string("Unknown Error ") + this->getFile());
        return false;
    }
    tinyxml2::XMLNode *root=m_xmldoc.FirstChildElement("CATALOG");
    if(!root){
        throw std::runtime_error(std::string("File Format Error: ") + this->getFile());
        return false;
    }

    //dynamically get category, and check if it's registered in Product
    string category="";
    tinyxml2::XMLElement *node=root->FirstChildElement();

    int count=0;
    int total=0;
    while(node!=nullptr){
        category=node->Name();
        transform(category.begin(), category.end(), category.begin(), ::toupper);

        //get object based on registered category
        shared_ptr<Product> product=ProductFactory::getInstance().create(category); 
        if(!product){         
            //if it's not registered, try to parse next record
            cout<<"WARNING: Catalog ("<<category<<") not supported."<<endl;
            node=node->NextSiblingElement();
            total++;
            continue;
        }
        tinyxml2::XMLElement *element=node->FirstChildElement();
        while(element!=nullptr)
        {  
            //initialize object with rigistered values
            string fieldName=element->Name();
            string fieldValue=element->GetText();
            product->setValues(fieldName,fieldValue);
            element=element->NextSiblingElement();
        }
        container.setType(product->getCategory());
        container.insert(product);
        count++;
        total++;
        
        node=node->NextSiblingElement();
    }
    cout<<"Loaded "<< count <<"/"<< total << " records from XML file (" << this->getFile() <<")."<<endl;
    
    return true;
}