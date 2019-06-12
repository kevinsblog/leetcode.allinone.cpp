#ifndef COMM_H
#define COMM_H

#include <unordered_map>
#include <set>
#include <iostream>
#include <list>
#include <queue>
#include <array>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

template<typename T>
void print(const std::vector<T> &arr){
    for(auto const & a : arr){
        std::cout << a << " " ;
    }
    std::cout << std::endl;
}

#endif