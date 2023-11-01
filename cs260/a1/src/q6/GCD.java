package q6;

import java.util.Scanner;

/**
 * GCD is an executable class for calculating the greatest
 * common divisor of the specified integers
 * @author karl
 */
public class GCD
{
	public static void main(String[] args)
	{
		// Ask the user for the two integers to use
		Scanner scanner = new Scanner(System.in);
		System.out.print("Enter an integer: ");
		int num1 = scanner.nextInt();
		System.out.print("Enter another integer: ");
		int num2 = scanner.nextInt();
		
		System.out.println();
		System.out.println("GCD of " + num1 + " and " + num2 + " is " + gcd(num1, num2));
	}
	
	/**
	 * gcd() is an implementation of Euclid's algorithm
	 * for calculating the greatest common divisor of a pair of integers
	 * @param a - the first integer of the pair
	 * @param b - the second integer of the pair
	 * @return the greatest common divisor of the specified integer pair
	 */
	private static int gcd(int a, int b)
	{
		while(b != 0)
		{
			int t = b;
			b = a % b;
			a = t;
		}
		return a;
	}
}
