#include <iostream>
using namespace std;

bool ok( int q[] , int c ) {
   for (int i = 0; i < c; i++ ) 
    if ( q[c] == q[i] || ( c-i ) == abs(q[c] - q[i]) )
        return false;
   return true;
}
void backtrack ( int &c ) {
   c--; 
   if ( c == -1 ) { 
    cout << "Normal termination of program" << endl;
    exit(1);
   }
}
void printBox(char x[][7])
{
	for (int i = 0; i < 5; i++ ) {
		for ( int j = 0; j < 7; j++)
			cout << x[i][j];
		cout << endl;
	}
}

void printBorder( char x ){
	//cout << "   ";
	for ( int i = 0; i < 7*8; i++ )
		cout << x;
}

void rasterPrint( char c ) {
	cout << c;
}
void printBoard(int q[])
{
        static int count = 0;
        cout << "Solution: " << ++count << endl;
	int i,j,k,l;
	typedef char box[5][7];
	box bb,wb,*board[8][8];
        box wq,bq;
	for ( i = 0; i < 5; i++ ) // fill in the boxes
		for ( j=0; j<7; j++)  {
			bb[i][j] = ' ';
                        bq[i][j] = ' ';
			wb[i][j] = char(219);
                        wq[i][j] = char(219);
		}
        // set up the queens
        wq[1][1] = 'W';
        wq[1][2] = 'h';
        wq[1][3] = 'i';
        wq[1][4] = 't';
        wq[1][5] = 'e';
        wq[2][1] = 'Q';
        wq[2][2] = 'u';
        wq[2][3] = 'e';
        wq[2][4] = 'e';
        wq[2][5] = 'n';
        bq[1][1] = 'B';
        bq[1][2] = 'l';
        bq[1][3] = 'a';
        bq[1][4] = 'c';
        bq[1][5] = 'k';
        bq[2][1] = 'Q';
        bq[2][2] = 'u';
        bq[2][3] = 'e';
        bq[2][4] = 'e';
        bq[2][5] = 'n';
//        printBox(wq);
//        printBox(bq);
	// fill board with the pointers
	for ( i = 0 ; i < 8; i++ )
		for ( j = 0 ; j < 8; j++ ) 
		  if ( (i+j)%2 == 0 ) {
                    if ( i == q[j] ) board[i][j] = &wq;
		      else board[i][j] = &wb;
                  }
		     else   {
                       if ( i == q[j] ) board[i][j] = &bq;
		        else board[i][j] = &bb;
                     }
	printBorder(char(196));
	cout << endl;
	for ( i = 0; i < 8; i++ ) // print the board
	  for ( k = 0; k < 5; k++) {
	  	for ( j = 0; j < 8; j++)
	  		for ( l = 0; l < 7; l++) {
	  		    char x = (*board[i][j])[k][l];
	  	            rasterPrint(x);
                        }
	  	cout << endl;
	  }
	  printBorder(char(196));
	  cout << endl;
}

int main() {
  // Eight queens backtracking code that uses the printBoard()
  // that is defined above.
  int q[8], c = 0;
  bool fromBT = false;
  q[0] = 0;
  while ( true ) {
    while ( c < 8 ) {
        if ( fromBT == false )
                q[c] = -1;
        fromBT = true;
        while ( q[c] < 8 )  {
                q[c]++;
                if ( q[c] == 8 ) {
                        backtrack(c);
                        fromBT = true;
                        break;;
                }
                if ( ok ( q , c ) == true ) {
                        c++;
                        fromBT = false;
                        break;
                }
        } // while ( q[c] < 8
    } // while (c < 8)
        printBoard ( q );
        backtrack(c);
        fromBT = true;
   } // while (true...
   return 0;
}
//we are going pixel by pixel we are gonna have 4 loops wehn i= 0 its gonna brint band 0 if (i+j ) gives me even nuber then its black otherwise it white 
//we are gonna have some chaarcter c . c is either black character char(219). if i+j is odd its gonna be the dot chacarter c=. The board is gonn be 5 acroos 7 
//we have variable k. k is gonna tell me what line in the band imprinting , when k =o im printing the upper most of the band . k goes from 0 to 4 .
//everytime i changes the band chnges and k gets reset to  0.
// i is the slowest moving . i is controlling the whole band. the next slow one is k = the ine withinh the band
//when j end up being 7 im gonn print the secind line of the band . the next fastes moving one is l . l tells the horizontal direction of the pronting.
//so we start at i=0 and j= 0 means im printong black char now i have k. k stats at 0 . then  ive l=o . im done printong the upper most corner then l becimes 1 but everything i j k remain 0
//l goes from 0 to 6 now j becomes 1 
// i+j is now odd so blank char . im gonn reset lto 0. now l agian goes from 0 to 6 and then j becomes 2. 
//by saying typedef , box becomes a new type where i can create variables 
//wb and bb are the arrays of white characters and black chars 
// we are look at wb bb to see what character to print 
//another array board 8*8 whereelement is a pointer *board[8][8] = a pointer to black box or white box 
// the big pic is we have variables i j k l . i represents the band horizontally, j moves vetically , l is gonna fill on the char whatever ine we re moving throgh. l is gonn cjange colors. l is gonna
// get a new value every time j chabges 
// we are gonna use i+j to look for eother wb or bb 
// so if (i+j) %2==0 we are gonna put the address of a wb it its odd then we are gonna put adress of bb in the board[8][8[\]
//if i=0, j=0 thrn borad [0][0]  has the derence that gonna be an alias for where borad[i][j] points 
//(*borad[i]i[j])[k][l] 
//i can use an array q to get the info whwere are the queens and the color of queen 
// if i+j is even then its gonna be a wb and wq and vice versa 
// i take the array by usung q we are gonna chnage the box to being a pointer of wq and bq .if i is row q[i] is col and thier addition is ebven then i am gonna put a wq in that posirtion 