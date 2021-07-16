//
// Created by peilin on 2021/7/16.
//

#ifndef ALGORITHMCPP_DATA_H
#define ALGORITHMCPP_DATA_H

#include <iostream>
#include <string>

using namespace std;

struct CellPhone{
    string brand;
    float price;

    bool operator<(const CellPhone &other){
        return price<other.price;
    }

    bool operator>(const CellPhone &other){
        return price>other.price;
    }

    friend ostream& operator<<(ostream& os,const CellPhone phone){
        os<<"Brand: "<<phone.brand<<" Price:"<<phone.price<<endl;
        return os;
    }
};

#endif //ALGORITHMCPP_DATA_H
