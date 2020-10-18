#include <fstream> 
#include "htmlgenerator.h"

//register HTMLGenerator
REGISTER_GENERATER(HTML, HTMLGenerator);

HTMLGenerator::HTMLGenerator(){
    setType("HTML");
};

bool HTMLGenerator::gen(Container<shared_ptr<Product>> &container){
    ofstream targetFile;
    targetFile.open (this->getFile());
    if(!targetFile){
        throw std::runtime_error(std::string("Open file error") + this->getFile());
        return false;
    }
    writeHead(targetFile, container);
    writeContent(targetFile, container);
    writeTail(targetFile);
    targetFile.close();
    cout<<"HTML file ("<< this->getFile()<<") generated, "<<container.getSize()<<" records."<<endl;
    return true;
}

void HTMLGenerator::writeHead(ofstream &targetFile, Container<shared_ptr<Product>> &container)
{
    targetFile << "<!DOCTYPE html><html><head></head><body><table>"; //starting html
    targetFile << "<tr>";
    targetFile << "<th colspan='100%'>"<<container.getType()<<"</th>"; 
    targetFile << "</tr>";
    targetFile << "<tr>"; 

    shared_ptr<Product> product=container.getItems()[0]; 
    for(string field : product->getFields()){
        targetFile<<"<th>"<<field<<"</th>";
    }
    targetFile << "</tr>"; 
}

void HTMLGenerator::writeTail(ofstream &targetFile) 
{
    targetFile << "</table></body></html>";
}

void HTMLGenerator::writeContent(ofstream &targetFile,Container<shared_ptr<Product>> &container)
{
    for (int i=0; i< container.getSize(); i++)
    {
        targetFile << "<tr>";
        shared_ptr<Product> product=container.getItems()[i]; 
        for(string field : product->getFields()){
            targetFile<<"<td>"<<product->getFieldValue(field)<<"</td>";
        }
        targetFile << "</tr>";
    }
}
