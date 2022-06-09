#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std ;

void printDuplicatesUsingMap(string &str)
{
    unordered_map<char , int> memo ;

    for(int i = 0 ; i < str.size() ; i++)
    {
        char ch = str[i] ;
        memo[ch]++ ;
    }

    for(auto it : memo)
    {
        char duplicate = it.first ;
        int count = it.second ;

        if(count > 1)
        cout << "Character: " << duplicate << " " << "Count: " << count << endl ;
    }

    return ;
}

void printDuplicatesUsingHashing(string &str)
{
    vector<int> map(125 , 0) ;

    for(int i = 0 ; i < str.size() ; i++)
    {
        char ch = str[i] ;
        int index = ch ;

        map[index]++ ;
    }

    for(int i = 1 ; i < 125 ; i++)
    {
        char duplicate = (char) i ;
        int count = map[i] ;

        if(count > 1)
        cout << "Character: " << duplicate << " " << "Count: " << count << endl ;
    }

    return ;
}

int main()
{
    string str = "aaabacdeffcbiIBghlAAACI" ;

    // printDuplicatesUsingMap(str) ;
    printDuplicatesUsingHashing(str) ;

    return 0 ;
}