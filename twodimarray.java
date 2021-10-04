public class twodimarray {

	public static int[][] myArray = {{1,2,3},{4,5,6},{7,8,9}};
	
	public static void main(String[] args) {
		printArray(myArray);
		printArrayEven(myArray);
		myArray = fillArray ("C:\\Users\\samia\\eclipse-workspace\\lab7\\src\\twodimension.txt");
		printArray(myArray);
	}
	private static void printArray (int[][] theArray) {
		for (int i=0; i<theArray.length; i++) {
			for (int j=0; j<theArray[i].length;j++)
				display(theArray[i][j]);
			System.out.println();
		}
	}
	private static void display (int num){
		System.out.print(num+" ");
	}
	private static void printArrayEven(int[][] theArray){
		for (int i=0;  i < theArray.length ; i++) {
			for (int j=0;  j< theArray[i].length ; j++) {
				if (theArray [i][j] % 2 == 0) {
					System.out.print(theArray [i][j]+ " ");
				
				} else {
					System.out.print("*");
					
				}
			}
			System.out.println();
		}
		
	}
	public static int [][] fillArray (String myFile){
		TextFileInput in = new TextFileInput (myFile);
		int row = Integer.parseInt (in.readLine());
		int col = Integer.parseInt (in.readLine());
	
	int [][] myArray = new int [row][col];
	for (int i=0;  i < row ; i++) {
		for (int j=0;  j < col ; j++) {
			myArray [i][j] = Integer.parseInt(in.readLine());
		}

	}
	return myArray;


	}
}
