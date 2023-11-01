package q5;

/**
 * PiCalculator is an executable class for calculating Pi
 * to a specified number of terms in an infinite series
 * @author karl
 */
public class PiCalculator
{

	public static void main(String[] args)
	{
		// Approximate pi to 200000 terms
		System.out.println("Term\t\tPi");
		System.out.println("200000\t\t" + approximatePi(200000));
		
		// Find the first term where Pi is correct to 5 decimal places
		for(int numberOfTerms = 0; numberOfTerms < 200000; numberOfTerms++)
		{
			if(equalToFivePlaces(approximatePi(numberOfTerms), 3.14159))
			{
				System.out.println(numberOfTerms + "\t\t" + approximatePi(numberOfTerms));
				break;
			}
		}
	}
	
	/**
	 * approximatePi() calculates an approximation of Pi using an infinite series
	 * pi = 4 - (4/3) + (4/5) - (4/7) + (4/9) - (4/11) + ...
	 * @param numberOfTerms - an int for the number of terms to calculate
	 * @return the approximation of pi
	 */
	private static double approximatePi(int numberOfTerms)
	{
		double pi = 0.0;
		
		int denominator = 1;
		for(int term = 0; term < numberOfTerms; term++)
		{
			// add if the term is even
			if(term % 2 == 0)
			{
				pi += 4 / (double)denominator;
			}
			else // subtract if the term is odd
			{
				pi -= 4 / (double)denominator;
			}
			denominator += 2;
		}
		return pi;
	}
	
	/**
	 * equalToFivePlaces() checks if two doubles are equal up to five decimal places
	 * @param x - the first double
	 * @param y - the second double
	 * @return - a boolean for if the two doubles are found to be equal
	 */
	private static boolean equalToFivePlaces(double x, double y)
	{
		// shift the significant digits up 5 places by multiplying
		x *= 100000;
		y *= 100000;
		
		// cast to integers to truncate the insignificant decimal places
		return ((int)x == (int)y);
	}
}
