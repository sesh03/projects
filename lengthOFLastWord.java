/* Given a string s consisting of some words separated by some number of spaces, return the length of the last word in the string.*/
 
class Solution {
    public int lengthOfLastWord(String s) {
      s= s.trim();
    int lastIndex = s.lastIndexOf(' ') +1;
        return s.length() - lastIndex;
    }
}