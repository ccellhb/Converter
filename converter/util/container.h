#ifndef CONTAINER_H_
#define CONTAINER_H_

#include "../global.h"

/*
a template clase, to store products
*/
template <typename T> class Container {
private:
    string m_type;
    vector<T> m_items;

public:
    void insert(const T&);
    int getSize();
    string getType();
    void setType(string type);
    vector<T> getItems();
};

template<typename T> void Container<T>::setType(string type){
    m_type=type;
}

template<typename T> void Container<T>::insert(const T &obj){
    m_items.push_back(obj);
}

template<typename T> string Container<T>::getType(){
    return m_type;
}

template<typename T> int Container<T>::getSize(){
    return m_items.size();
}

template<typename T> vector<T> Container<T>::getItems(){
    return m_items;
}
#endif