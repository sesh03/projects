#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

void reverse(string& str)
{
   int start = 0;
   int end = str.length()-1;
   while(start<end)     
   {  
       char temp = str[start];
       str[start]=str[end];
       str[end]=temp;
       start++;
       end--;
   }
}


string add( string a, string b ) {
string answer;
int len1 = a.length();                 
int len2 = b.length();
int temp;
int carry = 0;
int i,j;
for(i=len1-1,j=len2-1;i>=0 && j>=0;i--,j--)   
{
  
   temp = (a[i]-48) + (b[j] - 48) + carry;   
   answer.push_back((temp%10)+48);          
   temp = temp/10;                   
   carry = temp;             
}

while(i>=0)
{
   temp = (a[i]-48) + carry;
   answer.push_back((temp%10)+48);
   temp = temp/10;
   carry = temp;
   i--;
}
while(j>=0)
{
   temp = (b[j] - 48) + carry;
   answer.push_back((temp%10)+48);
   temp = temp/10;
   carry = temp;
   j--;
}

if(carry!=0) 
answer.push_back(carry+48); 
reverse(answer);         
return answer;          
}


int main() {
string x, y;
for ( ;; ) {
cout << "Enter two numbers a and b as string: " << "\t";
cin >> x >> y;
if ( x == "done" || y == "done" )
{
cout << "normal termination of the program" << endl;
exit(1);
}
cout << x << " + " << y << " = " << add( x, y ) << endl;
}

return 0;
}