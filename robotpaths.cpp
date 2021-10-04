#include <iostream>
using namespace std;
int paths (int i ,int j) {
  if (i==0 or j==0)
    return 1;
    return paths (i,j-1)+paths (i-1,j);
  
  }
  int main(){
    cout<<paths(4,4)<<endl;
    return 0;
  }
//I wanna write  a fn called path that tells me the no of ways to get to i, j.Instead of going top down , whe can do thing in bottom up way as in top down way it takes a lot of computation 
//i is row , j is column,
// its recursive as the no of paths is gonna be the sum of the function i,j-1+ i,j-1. we have the same function but diff corordintes.
//the base case gonna be if i=0, j=0 the no of paths gonna be 1 . the bottom is (4,4). Hence we've to calculate a lot of times .If i keep a memo , it would be less complicated. We can start filling up the box from up . we're ognna work our way across to the rows. so we can work from the bottom (0,0) to top (4,4)