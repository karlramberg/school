package q1;

/**
 * DecimalConversion is a class to hold utility functions for converting
 * decimal integers to there equivalents in other bases
 * @author Karl Ramberg
 */
public class DecimalConversion {
	/**
	 * decimalToBinary converts a decimal integer to a string
	 * representation of the binary equivalent
	 * @param num : the decimal number to convert
	 * @return a string representing the binary equivalent of num 
	 */
	public static String decimalToBinary(int num)
	{
		String binaryString = "";
		while(num > 0)
		{
			binaryString = (num % 2) + binaryString;
			num /= 2;
		}
		return binaryString;
	}

	/**
	 * decimalToOctal converts a decimal integer to a string
	 * representation of the octal equivalent
	 * @param num : the decimal number to convert
	 * @return a string representing the octal equivalent of num
	 */
	public static String decimalToOctal(int num)
	{
		String octalString = "";
		while(num > 0)
		{
			octalString = (num % 8) + octalString;
			num /= 8;
		}
		return octalString;
	}

	/**
	 * decimalToHexadecimal converts a decimal integer to a string
	 * representation of the hexadecimal equivalent
	 * @param num : the decimal number to convert
	 * @return a string representing the hexadecimal equivalent of num
	 */
	public static String decimalToHexadecimal(int num)
	{
		String hexadecimalString = "";
		while(num > 0)
		{
			int remainder = num % 16;
			if(remainder < 10)
			{
				hexadecimalString = remainder + hexadecimalString;
			}
			else if(remainder == 10)
			{
				hexadecimalString = "A" + hexadecimalString;
			}
			else if(remainder == 11)
			{
				hexadecimalString = "B" + hexadecimalString;
			}
			else if(remainder == 12)
			{
				hexadecimalString = "C" + hexadecimalString;
			}
			else if(remainder == 13)
			{
				hexadecimalString = "D" + hexadecimalString;
			}
			else if(remainder == 14)
			{
				hexadecimalString = "E" + hexadecimalString;
			}
			else // remainder is 15 
			{ 
				hexadecimalString = "F" + hexadecimalString;
			}
			num /= 16;
		}
		return hexadecimalString;
	}
	
	public static void main(String[] args)
	{
		// Print a table of binary, octal, and hex representations of the decimals 1 - 128
		System.out.printf("%7s  %8s  %5s  %10s\n", "Decimal", "Binary", "Octal", "Hexadecimal");
		System.out.printf("%7s  %8s  %5s  %10s\n", "-------", "------", "-----", "-----------");
		for(int num = 1; num <= 128; num++)
		{
			System.out.printf("%7d  %8s  %5s  %11s\n", num, decimalToBinary(num), decimalToOctal(num), decimalToHexadecimal(num));
		}
	}
}
