package q2;

import java.util.Scanner;

/**
 * ArrayQuestions answers basic questions about a 2D array
 * with simple executions
 * @author Karl Ramberg 
 */
public class ArrayQuestions
{
	public static void main(String[] args)
	{
		// a) Write a statement that declares and creates t.
		int[][] t = new int[2][3];
		
		// b) How many rows does t have?
		// t.length
		
		// c) How many columns does t have?
		// t[0].length
		
		// d) How many elements does t have?
		// t.length * t[0].length
		
		// e) Write access expressions for all the elements in row 1 of t.
		// t[1][0]
		// t[1][1]
		// t[1][2]
				
		// f) Write access expressions for all the elements in column 2 of t.
		// t[0][2]
		// t[1][2]
				
		// g) Write a single statement that sets the element of t in row 0 and column 1 to zero.
		t[0][1] = 0;
		
		// h) Write individual statements to initialize each element of t to zero.
		t[0][0] = 0;
		t[0][1] = 0;
		t[0][2] = 0;
		t[1][0] = 0;
		t[1][1] = 0;
		t[1][2] = 0;
		
		// i) Write a nested for statement that initializes each element of t to zero.
		for(int row = 0; row < t.length; row++)
		{
			for(int column = 0; column < t[row].length; column++)
			{
				t[row][column] = 0;
			}
		}
		
		// j) Write a nested for statement that inputs the values for the elements of t from the user.
		Scanner scanner = new Scanner(System.in);
		for(int row = 0; row < t.length; row++)
		{
			for(int column = 0; column < t[row].length; column++)
			{
				System.out.print("Enter a value for element at (" + row + "," + column + "): ");
				t[row][column] = scanner.nextInt();
			}
		}
		
		// k) Write a series of statements that determines and displays the smallest value in t.
		int smallestValue = t[0][0];
		for(int row = 0; row < t.length; row++)
		{
			for(int column = 0; column < t[row].length; column++)
			{
				if(t[row][column] < smallestValue)
				{
					smallestValue = t[row][column];
				}
			}
		}
		System.out.println("Smallest Value: " + smallestValue);
		
		// l) Write a single printf statement that displays the elements of the first row of t.
		System.out.printf("First row of t: %d %d %d\n\n", t[0][0], t[0][1], t[0][2]);
		
		// m) Write a statement that totals the elements of the third column of t. Do not use repetition.
		int total = t[0][2] + t[1][2];
		
		// n) Write a series of statements that displays the contents of t in tabular format.
		//    List the column indices as headings across the top, and list the row indices at the left of each row.
		System.out.println(" \t0\t1\t2");
		for(int row = 0; row < t.length; row++)
		{
			System.out.print(row+"\t");
			for(int column = 0; column < t[row].length; column++)
			{
				System.out.print(t[row][column] + "\t");
			}
			System.out.println();
		}
	}
}
