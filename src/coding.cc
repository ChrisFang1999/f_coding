#include "coding.h"

int main(){
    vector<int> vec{1,5,2,7,2,9,5,1,4,9,6,3,2};
    vector<int> result = maxSlidingWindow(vec,4);
    for (int res:result)
    {
        cout<<res<<endl;
    }
    
    return 0;
}