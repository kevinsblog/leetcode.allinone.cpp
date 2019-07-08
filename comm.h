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
#include <stack>
#include <sstream>
#include <fstream>
#include <mutex>

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

class Node {
public:
    int val;
    std::vector<Node*> neighbors;

    Node() {}

    Node(int _val, std::vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

#endif