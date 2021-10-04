#include <iostream>
using namespace std;

bool ok(int q[], int c) {
   static int mp[3][3] = { {0,2,1},  // 0  Men's preferences
                           {0,2,1},  // 1
                           {1,2,0}}; // 2
   static int wp[3][3] = { {2,1,0},  // 0  Women's preferences
                           {0,1,2},  // 1
                           {2,0,1}}; // 2
                     
   // Check for conflicts between man#c's marriage and previous marriages.
   for (int i = 0; i < c; ++i) {                                    // For each previous man#i, if
      if(q[i]==q[c]) return false;
        if((mp[i][q[c]] <mp[i][q[i]])&&(wp[q[c]][i]<wp[q[c]][c])) return false;// i =m q[i] = woman assigned to man i    col indicates new man q[c] new woman proposed 
        if((mp[c][q[i]]<mp[c][q[c]])&&(wp[q[i]][c]<wp[q[i]][i])) return false;
                                           // return false.
   }
   return true;
}

void print(int q[]) {
   static int solution = 0;
   cout << "Solution #" << ++solution << ":\nMan\tWoman\n";
   for (int i = 0; i < 3; ++i)
      cout << i << "\t" << q[i] << "\n";
   cout << "\n";
}

int main() {
   int q[3] = {};
   int c = 0;
   while (c >= 0) {// NEXT COL:
       c++; // Move to the next column
      if (c == 2) {//If you have passed the last column, a solution is found
         print(q);//Call the print function and backtrack
         --c;
      }
      else
         q[c] = -1;//set to -1 so in inner loop you can start q[c] from 0
      while (c >= 0) {// next row 
         ++q[c];// Move to the next row
         if (q[c] == 3) // If you have passed the last row, backtrack
            --c;
         else if (ok(q, c))//Else call ok function if ok (returns true), a queen is filled in the row // cecks the pair is stable 
            break;
      }
   }
   return 0;
}
// the last pair with previous 2 pairs
//the woman with the previous 2 men, and the man with the previous two women
// if instabiltiy backtrack
//if youre backtracking the previous two should be stable the time you get to the last pair
//For man 0, woman 0, there is no need to check for instabilities because that is the first pair, and there are no previous men for woman 0 to cause instabilities with, and there are no previous women for man 0 to cause instabilities with.
//For man 1, woman 1, man 1 will not cause any instabilities with woman 0 because man 1's preference for woman 1 given by mp[1][1] is 0, meaning that woman 1 is man 1's most preferred woman, and man 1 will not leave her.The same goes for woman 1, with wp[1][1] returning 0, and telling us that woman 1 prefers man 1 over all other men, and will not leave him.
//For  man 2 woman 2, the same applies as for man 1 woman 1. Man 2's ranking of woman 2 given by mp[2][2] is 0, meaning that man 2's most preferred woman is woman 2, and man 2 will not leave her, and woman 2's preference for man 2 given by wp[2][2] is 0, meaning that woman 2's most preferred man is man 2, and she will not leave him.


