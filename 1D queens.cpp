#include <iostream>
using namespace std;

int main() {
   int q[8][8] = {1}, r, c = 0;
   
nextCol:
   c++;// everytime i move to next col 
   if (c == 8)
      goto print;//by filling all the columns which is upto 8 as the board consists max 8 we print the solution
   r = -1;// we want to start from the top of the board thats why we inistilize row to -1 
   
nextRow:
   r++;// beacuse after adding 1 we can go to row 0
   if (r == 8)//After filling col by col there will be a col where no test wiil pass then we do backtracking when row is 8 the max rows on board it will go to backtrack to eliminate a queen 
      goto backtrack;
   
   // weneed a for loop 
   for (int i = 0; i < c; i++)                    // row test //the active col is c , we are checking 0 upto c if there's any queen  
      if (q[r][i] == 1)                            //if the box [row] [col] im looking at equals 1  // as i travel from col o to c-1 if i find a quuen its problem so we move down to next row 
         goto nextRow;
   for (int i = 1; r - i >= 0 && c - i >= 0; i++) // up-diagonal test // going up daigonal the row and col has is becoming smaller and we keep doing this as long as we are on board 
      if (q[r-i][c-i] == 1)                         // if the diff between row and col equals 1 means thers a queen we have conflict we go tonext row 
         goto nextRow;
   for (int i = 1; r + i < 8 && c - i >= 0; i++)  // down-diagonal test  // if we go down daigonal the row increment the col decrease when summation of row and diff of cols equals 1 meeans diagonlly down thereq queen we move nextrow
      if (q[r+i][c-i] == 1)   //we are adding orsubtracting i to row and col as row and col are constant // we start adding i to r that gonna move row 1 box down 2 boxes down.....
         goto nextRow;
   // after passing 3 tests we will puta queen in the desired box 
   q[r][c] = 1;//
   goto nextCol;// now once i succeesfully placea queen we goto next cloumn 
   // after going col bycol therewill be col where no test will pass then we do backtracking 
backtrack:
   c--;                 // move back to prev col
   if (c < 0)
      return 0;
   for (r = 0; q[r][c] != 1; r++); // didnt find the queen trying next row r++
   q[r][c] = 0;           // when it finds it;s gonna eliminate the queen and set it to 0 
   goto nextRow;    // now we're contuning if we have any more quuen in the column we go tp next row 

print:
   static int numSolutions = 0;
   cout << "Solution #" << ++numSolutions << ":\n";
   for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 8; ++j)
         cout << q[i][j];
      cout << "\n";
   }
   goto backtrack;
}
// when we know we find a sol when I successfully place a queen to the column the program says go to next column when i find c==8 it means I filled up 
// when going to print it gonna backtrack and once were out of the board if (c== -1) it's gonna stop backtracking