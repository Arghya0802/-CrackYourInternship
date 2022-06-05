#include<vector>
using namespace std ;

// The Optimal Solution can be acheived using Dutch Nation Flag Algorithm 
void sortColors(vector<int>& nums) {
        
    int n = nums.size() ;
        
    int low = 0 , mid = 0 , high = n - 1 ;    
    
    while(mid <= high)
    {
        if(nums[mid] == 0)
        {
            swap(nums[low] , nums[mid]) ;
            
            low++ ;
            mid++ ;
        }
        
        else if(nums[mid] == 2)
        {
            swap(nums[mid] , nums[high]) ;
            
            high-- ;
            
        }
        
        else
        mid++ ;
    }
        
    return ;
}