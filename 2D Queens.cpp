#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int q[8], c=0, i, j; // we will call array q to represent the board 
    q[0]=0; //first queen top corner placing the queen in the upper rightcorner 
nc: c++;   // Everytime I put successfully a queen I move to next col 
    if(c==8) goto print;           // by filling all the columns which is upto 8 as the board consists max 8 we print the solution
    q[c]=-1;            // we want to start from the top of the board thats why we inistilize row to -1
nr: q[c]++;               // beacuse after adding 1 we can go to row 0
    if(q[c]==8) goto backtrack;       // After filling col by col there will be a col where no test wiil pass then we do backtracking when row is 8 the max rows on board it will go to backtrack to eliminate a queen 
    
    for(i=0;i<c;i++){                 // the active col is c , we are checking 0 upto c if there's any queen  
        if((q[i]==q[c])||(c-i==abs(q[c]-q[i]))) goto nr;         //q[i]==q[c] row test for every i upto c the number in q[i] is equal to the nymber in q[c] 
                                                                  // goto nrmeans i can'y put anything here so i move down to the next row
    }
    goto nc;                                 // after checking a colum we move to the next col
backtrack: c--;                         // its gonna move back to prev col
    if (c == -1)return 0;                  // if  all column passes 0 after filling all cols its gonna stopbacktacking
    goto nr;                  // checking the column its gonna move to next row to see if there's any queen 
print: 
static int numSolutions = 0;
   cout << "Solution #" << ++numSolutions << ":\n";
for(i=0;i<8;i++){
    for(j=0;j<8;j++){
        if(q[i]==j){ // if row= j =0,1,2,3,4,5,6,7 // if row value equals to col 
            cout<<1;// print 1 
        } else {
            cout<<0;// otherwise it will print 0
        }
    }
    cout<<endl;
    }
    goto backtrack;// if conflict happens it goes to label backtrack to move to prev col
}