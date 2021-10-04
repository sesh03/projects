import javax.swing.*;
public class Lab4Program03 {

	public static void main(String[] args) {
		String[] wordArray = { "hello", "goodbye", "cat", "dog", "red", "green", "sun", "moon" };
		String isOrIsNot, inputWord;
			
		// This line asks the user for input by popping out a single window
		// with text input
		inputWord = JOptionPane.showInputDialog(null, "Enter a word in all lower case:");
		String stop="STOP";
		while (!inputword.equals(stop)) {
		
		// if the inputWord is contained within wordArray return true
		if (wordIsThere(inputWord, wordArray)) 
			isOrIsNot = "is"; // set to is if the word is on the list
		else
			isOrIsNot = "is not"; // set to is not if the word is not on the list
		
		// Output to a JOptionPane window whether the word is on the list or not
		JOptionPane.showMessageDialog(null, "The word " + inputWord + " " + isOrIsNot + " on the list.");
	}  System.exit(0);
	}
	//main

	public static boolean wordIsThere(String findMe, String[] theList) {
		for (int i ; i < theList.length ; i ++) {
			String current = theList [i];
			if (findMe.equals(current)) {
				return true;
				
			}
			else continue; 
			
		}
		return false;

	} // wordIsThere
 // class Lab4Program03

	}


