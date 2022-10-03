// Given two strings, write a method to decide if one is a permutation of the 
other.

boolean permutation(String s, String t) { 
if (s.length() != t.length()) { 
return false; 
  } 
} 
int[] letters = new int[128]; 
char[] s_array = s.toCharArray(); 
for (char c : s_array) { //II count number of each char in s. 
letters[c]++; 
} 
for (int i= 0; i < t.length(); i++) { 
int c = (int) t.charAt(i); 
letters[c]--; 
if (letters[c] < 0) { 
return false; 
} 
} 
return true;