#include <iostream>
#include <vector>
using namespace std;

int main() {
   vector<int> t[3];
   int n;
   cout << "Please enter the number of rings to move: ";
   cin >> n;
   cout << endl;
   // The initial value of to depends on whether n is odd or even
   int from = 0, to = 0, candidate = 1, move = 0;

   // Initializing the towers
   for(int i = n + 1; i >= 1; --i)
   t[0].push_back(i);
   t[1].push_back(n+1);
   t[2].push_back(n+1);

   if(n%2 == 1){
        to = 1;
   while (t[1].size() < n+1) { // while t[1] does not contain all of the rings
      cout << "Move #" << ++move << ": Transfer ring " << candidate << " from tower " << char(from+'A') << " to tower " << char(to+'A') << "\n";

      // Moving the ring from the "from tower" to the "to tower" (first copy it, then delete it from the "from tower")
      t[to].push_back(t[from].back());
      t[from].pop_back();

      // from = the index of the tower with the smallest ring that has not just been moved: (to+1)%3 or (to+2)%3
      if (t[(to+1)%3].back() < t[(to+2)%3].back())
         from = (to+1)%3;
      else
         from = (to+2)%3;

      // candidate = the ring on top of the t[from] tower
      candidate = t[from].back();

      // to = the index of the closest tower on which the candidate can be placed: (from+1)%3 or (from+2)%3
      // (comparing the candidate with the ring on the closer tower; which tower is "closer" depends on whether n is odd or even)
      if (t[from].back() < t[(from+1)%3].back())
         to = (from+1)%3;
      else
         to = (from+2)%3;
   }
   }

   if(n%2 == 0){
        to = 2;
   while (t[1].size() < n+1) { // while t[1] does not contain all of the rings
      cout << "Move #" << ++move << ": Transfer ring " << candidate << " from tower " << char(from+'A') << " to tower " << char(to+'A') << "\n";

      // Moving the ring from the "from tower" to the "to tower" (first copy it, then delete it from the "from tower")
      t[to].push_back(t[from].back());
      t[from].pop_back();

      // from = the index of the tower with the smallest ring that has not just been moved: (to+1)%3 or (to+2)%3
      if (t[(to+2)%3].back() < t[(to+1)%3].back())
         from = (to+2)%3;
      else
         from = (to+1)%3;

      // candidate = the ring on top of the t[from] tower
      candidate = t[from].back();

      // to = the index of the closest tower on which the candidate can be placed: (from+1)%3 or (from+2)%3
      // (comparing the candidate with the ring on the closer tower; which tower is "closer" depends on whether n is odd or even)
      if (t[(from+2)%3].back() < t[from].back())
         to = (from+1)%3;
      else
         to = (from+2)%3;
   }
   }

   return 0;
}//step 0 would be to cjeck in n is even or odd 
// step 3woukd be moving to right in terms of odd and left in trerm of even 
// we are gonna represent as vectors  the top ring of the tower is the back of vector. If i wanna the value the vaue of top i simply say back i wann get rid if it i say pop back 
// vetor<int> t[3]= here we have array t of 3 elements every element is a vetor of integers 
//After initializing my 3 towers if n=3 then i starts at 4 . I did push back 4 and then 4,3, 2, 1..Then it says goto t[1] and push back a 4 .Since evrything stats at tower 0, t1, t2
//.intilizing towersand candidtes
//im statring to t[0] im gonna move to t[1]
//move no initialized to 0 as move++ makes it 1 
//now it s say tranfer ring and canddiate 1 as initialized from tower char (from +65)/ (0+65) = A to tower char (To +65)/ (1+65)=66=B 
//Move #1 transfer ring  form Tpwer A to Tpwer B 
// I am moingthe candidate form tpwer A to tower B taing it forn the op of from tower and push it to the top of the tower 
//So I am trying to find whos on the top pf the from tower by doing back()= T[from] .back()
//then i push the top ring to tower b= T[to].push_back(T [from].back())
// then i popback() the ring  which will remove the ring from tower a = T[from].pop_back()
//now i find my next tower and candidate i can find the candidate by fn back()
// the next move tower would be one of the other either To+1/ B or To+2/c 
// as we re going in a circular way so we use  (To+2)%3 (To+1)%3 to move to the towers
// after looking to the towers i compare which tower has the smallest one on top = if (t[from].back() < t[(from+1)%3].back())
