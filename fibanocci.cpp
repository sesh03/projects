#include <iostream>
using namespace std;
static int fib (int n){
  int memo [100]{0};
  //I put a one d array called memo and everyithng in the memo is initialzed as 0. If i wanna calc f4 = n=4
  if( (n==1)|| (n==2))// doesnt apply here 
  return 1;
  if (memo [n]>0)
  return memo [n];
  return memo [n]=fib(n-1)+fib (n-2);// here f3+f2 now n=3 then n=2 when its f2 we know f2=1 now in stead of returning im gonna put it into memo[3] so i will say goto memo 3 write down the value
  //2 as f3=f2+f1=1+1 now the memo is changed and i return 2 , so now we goback to f4 and sahre it to the memo before return to 3 when f4 therefore when i call f5 .insted of recursion its ognna got 

  // to the line 
  //if (memo[n] > 0) so each time the table below has been filled andits gonna go fast

  //memo is  a loacl variable.so even though i put a 3 in memo[n] the next time i call it it's a different memo , it doesnt stay one call to fn to the next bcz it goes out of the run time stack .
  //one it goes out of the rts, anytihng i put in memo is gone . So if i say static = mean that the value is gonna stay in lication in location by saying stattic in the mmeory its not gonaa store the value
  // in RTS rather store it in static 
}
int main(){
  for (int i =1; i<101;i++)
  cout <<i <<'\t'<< fib(i)<<endl;
  return 0;
}

//Dynamic Programminng 

