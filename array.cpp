#include "comm.h"

using namespace std;
//134. Gas Station
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int remain = 0, start = 0, lack = 0;
    for(int i = 0; i < gas.size(); i++){
        remain += gas[i] - cost[i];
        if(remain < 0){
            //if remained power less than 0, one need to restart from i
            //  and make up the lack in future (next loop)
            start = i;
            lack += remain;
            remain = 0; //start with 0 power left
        }
    }

    return remain + lack >= 0 ? start : -1;
}
