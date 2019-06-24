#include "comm.h"

using namespace std;
//133. Clone Graph
Node* getPtr(unordered_map<Node*, Node*> &mpPtr, Node * const oldPtr){
    if(oldPtr == nullptr){
        return nullptr;
    }
    if(mpPtr.count(oldPtr) == 0){
        mpPtr[oldPtr] = new Node();
        mpPtr[oldPtr]->val = oldPtr->val;
        for(auto nh : oldPtr->neighbors){
            mpPtr[oldPtr]->neighbors.push_back(getPtr(mpPtr,nh));
        }
    }
    return mpPtr[oldPtr];
}

Node* cloneGraph(Node* node) {
    unordered_map<Node*, Node*> mpPtr;
    Node *nnode = getPtr(mpPtr, node);
    return nnode;
}