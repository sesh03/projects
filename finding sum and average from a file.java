import javax.swing.*;
public class Lab06Program1 {
	
	public static void main (String[] args) {
		TextFileInput in = new TextFileInput (args[0]);
		int myArraySize= 0;
		int count =0;
		
		int [] myArray = new int [myArraySize];
		while (count < myArraySize) {
			myArray[count]=Integer.parseInt(in.readLine());
			count++;
			
		}
		
		int s = sum (myArray,myArraySize);
		String s_value = String.valueOf(s); //Convert int s to string s_value
		//output to a JOptionPne window the sum 
		JOptionPane.showMessageDialog(null,"The sum is " +  s_value);
		
		
		int a = average(myArray, myArraySize);
		String a_value= String.valueOf(a);
		JOptionPane.showMessageDialog(null, "The averge is"  + a_value);
	}
	public static int sum (int [] myArray, int myArraySize) {
		int i = 0;
		int s= 0;
		while (i < myArraySize) {
			s+= myArray[i];
			i++;
		}
		return s;
	}
	public static int average  (int [] myArray, int myArraySize) {
		int s = sum(myArray, myArraySize);
		int a = s/myArraySize;
		return a;
				
	}

}