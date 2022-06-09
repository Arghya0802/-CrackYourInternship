#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

void printCombinations(int currentIndex , vector<int> &subset , int r , vector<int> &nums , vector<vector<int>> &ans)
{
    if(subset.size() == r)
    {
        ans.push_back(subset) ;
        return ;
    }

    // Pick Element at currentIndex
    int currentVal = nums[currentIndex] ;
    subset.push_back(currentVal) ;

    printCombinations(currentIndex + 1 , subset , r , nums , ans) ;

    // Back-track and undo the change
    subset.pop_back() ;

    //To avoid duplicate subsets , we ignore all other occurrences of nums[currentIndex]
    while (currentIndex + 1 < nums.size() && nums[currentIndex] == nums[currentIndex + 1] )
    {
        currentIndex++ ;
    }
    
    // Don't pick the Element at currentIndex
    printCombinations(currentIndex + 1 , subset , r , nums , ans) ;

    return ;
}

vector<vector<int>> generateCombinations(vector<int> &nums , int R)
{
    vector<vector<int>> ans ;
    vector<int> subset ;

    sort(nums.begin() , nums.end() ) ;

    printCombinations(0 , subset , R , nums , ans) ;

    return ans ;
}

int main()
{
    vector<int> nums = {1,2,3,4,5} ;
    int r = 3 ;
    vector<vector<int>> ans = generateCombinations(nums , r) ;
    int m = ans.size() ;
    cout << m << endl ;
    for(int currentRow = 0 ; currentRow < m ; currentRow++)
    {
        for(int currentCol = 0 ; currentCol < ans[currentRow].size() ; currentCol++)
        {
            cout << ans[currentRow][currentCol]<< " ," ;
        }

        cout << endl ;
    }

    return 0 ;
}