#include <iostream>
using namespace std;

//I want a declaration of a new data type.We use the class keyword Rat to make the declaration.
class Rat{
private:
 int n;
 int d;
 //Now we wiil build the public interface.
public:
 // constructors
//These are constructors . Constructors are another way of saying initializing object. I am gonnna define my own initilization. Eveb though it has a default constructor um gonna define. Every constructer
//or intilization has same class name.Theres no return type. It's a default constructor by empty bracket= Rat ().So if we say Rat x, its ginna look for Rat().In the machine, its gonna say x.Rat()
//meaning got to x object and get to numerator and put a 0 and put a 1 in denominator.

 // default constructor
 Rat(){
 n=0;
 d=1;
 }

 // 2 parameter constructor
 //If I say Rat x(1,2).The first arguement is going to be i and the second arguement going to be j. then i would be 1 and j would be 2.

 Rat(int i, int j){
 n=i;
 d=j;
 }

 //We wanna be able to convert our integers to Rats.We nedd conversion constructor. It will convert innteger to rat by putting 1 in the denominator.
 // conversion constructor
 Rat(int i){
 n=i;
 d=1;
 }
 //Now we are gonna teach how to get the value . The member functions has data members. We're giving access to the data members. Way of calling is getN()

 //accessor functions (usually called get() and set(...) )
 int getN(){ return n;}
 int getD(){ return d;}
 //Now I wanna set the numerators..vo
 void setN(int i){ n=i;}
 void setD(int i){ d=i;}

 //arithmetic operators
 //In c++, x+y means x.opoerator +y. so y is coming in as an arguement. We're defining operator+ which tells the compiler how to add these rational numbers.how does the "+' work taking one arguement.
 //if '+' is a binary operator , it takes only one.If i call a member funcyion = x.getN() its gonnna look like this- RAT. F()= object. member function(arguement) meaning x.operator +(y).Syntactic sugar
 //gives me new way of doing things. So when i say x+y, the complier automatically convertsit to x.operator +(y). Here the parameter name is r so we call r.n and r.d to get access to the numeratiors and denominators
 //Im gonna declare Rat t cause im gonna cpnstruct the Rat that im gonna return as the value of dding x and y. 
 //In Rat (r) there are two arguements . One is invisible called "This" = C++ convert it like = x. operator + (This, Rat r) ''This " is the adrees of x . The complier pick up the address of x and store ot in


 Rat operator+(Rat r){
 Rat t;
 t.n=n*r.d+d*r.n;// "This" is a pointer whats happening over here is in the r.n , n is equivalent to *This.n
 t.d=d*r.d;
 return t;
 }


 // 2 overloaded i/o operators
 //friend is a fn in c++ that is not a memebr fn but we can truct to give access to the internal fn. In order to priny i am gonna overload the left shift operator . here im passing ostream and the 
 //the name of the string i wanna write on - the ostream &is work like cout . If i say cout<<x = cout is going to be os and x is r 
 friend ostream& operator<<(ostream& os, Rat r);
 friend istream& operator>>(istream& is, Rat& r);
}; //end Rat
// operator<<() is NOT a member function but since it was declared a friend of Rat
// it has access to its private parts.

//if we wanna do 5+x
//why it works bcz its a regular fn not a member fn. So x gooes to conversion constructer
//Rat operator+(Rat a, Rat b){
//Rat t;
//t.setN(a.getN()* b.getD() + a.getD() * b.getN());
//t.setD(a.getD()* b.getD());
//return t;
//}
ostream& operator<<(ostream& os, Rat r){
 os<<r.n<<" / "<<r.d<<endl;
 return os;}
// operator>>() is NOT a member function but since it was declared a friend of Rat
// it has access to its provate parts.
istream& operator>>(istream& is, Rat& r){
 is>>r.n>>r.d;
 return is;
}
int main() {
	Rat x(1, 2), y, z;
	cout << x.getN() << endl;
	cout << x.getD() << endl;
	y.setN(3);
	y.setD(5);
	cout << y.getN() << endl;
	cout << y.getD() << endl;
	z = x + y;
	cout << z.getN() << "/" << z.getD() << endl;
	return 0;
}