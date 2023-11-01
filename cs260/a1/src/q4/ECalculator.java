package q4;

import java.util.Scanner;

/**
 * ECalculator is an executable class for calculating e or e^x
 * to a specified number of terms in an infinite series
 * @author karl
 */
public class ECalculator
{
	public static void main(String[] args)
	{
		Scanner scanner = new Scanner(System.in);
		
		// Demonstrate the approximateE() function
		System.out.print("Enter a number of terms: ");
		int n = scanner.nextInt();		
		System.out.println("e to term " + n + " is " + approximateE(n));
		
		// Demonstrate the approximateEX() function
		System.out.print("Enter a number of terms: ");
		n = scanner.nextInt();
		System.out.print("Enter an exponent: ");
		int x = scanner.nextInt();
		System.out.println("e^" + x + " to term " + n + " is " + approximateEX(n , x));
		
		// Demonstrate approximateEX() with a different exponent
		System.out.print("Enter a different exponent: ");
		x = scanner.nextInt();
		System.out.println("e^" + x + " to term " + n + " is " + approximateEX(n , x));
		
		// Close the scanner
		scanner.close();
	}
	
	/**
	 * approximateE() calculates an approximation of e to the specified number of terms
	 * of an infinite series e = 1 + 1/1! + 1/2! + 1/3! + 1/4! + ...
	 * @param n - an int for the number of terms to calculate
	 * @return the approximation of e
	 */
	private static double approximateE(int n) 
	{
		if(n <= 0) // if we have reaches the last term
		{
			return 1;
		}
		
		// add the previous term to this one
		return approximateE(n-1) + 1/factorial(n);
	}

	/**
	 * approximateEX() calculates an approximation of e raised to a power using a specified
	 * number of terms of the infinite series e^x = 1 + (x^1)/1! + (x^2)/2! + (x^3)/3! + ...
	 * @param n - an int for the number of terms to calculate
	 * @param x - and int for the power e will be raised to
	 * @return the approximation of e^x
	 */
	private static double approximateEX(int n, int x) 
	{
		if(n <= 0) // if we have reached the first term
		{
			return 1;
		}
		
		// add the previous term to this one
		return approximateEX(n-1, x) + (Math.pow(x,  n) / factorial(n));
	}
	
	/**
	 * factorial() calculates n! using recursion
	 * @param n - an int to find the factorial of
	 * @return the factorial of n
	 */
	private static double factorial(int n)
	{
		if(n <= 0) // if we have reached the first term
		{
			return 1;
		}
		
		// add the previous term to this one
		return n * factorial(n-1);
	}
}
