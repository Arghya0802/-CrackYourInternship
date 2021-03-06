#include <vector>
#include<iostream>
using namespace std ;

int findDuplicate(vector<int>& nums) {
        
    int n = nums.size() ;
        
    for(int i = 0 ; i < n ; i++)
    {
        int currentNum = nums[i] ;
        int index = abs(currentNum) - 1;
        
        nums[index] = - nums[index] ;
        
        if(nums[index] > 0)
        return abs(currentNum) ;
        
    }
        
    return -1 ;
}