#ifndef COMM_H
#define COMM_H

#include <unordered_map>
#include <unordered_set>
#include <set>
#include <iostream>
#include <list>
#include <queue>
#include <array>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <limits>
#include <array>
#include <bitset>

template<typename T>
void print(const std::vector<T> &arr){
    for(auto const & a : arr){
        std::cout << a << " " ;
    }
    std::cout << std::endl;
}

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

#endif