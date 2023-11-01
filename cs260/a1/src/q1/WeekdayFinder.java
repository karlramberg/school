package q1;

import java.util.Scanner;

/**
 * WeekdayFinder is an executable class for finding the day 
 * of the week a date falls on (Monday, Tuesday, etc.)
 * @author karl
 */
public class WeekdayFinder
{
	static final int DAYSINJANUARY = 31;
	static final int DAYSINFEBRUARY = 28;
	static final int DAYSINFEBRUARYLEAPYEAR = 29;
	static final int DAYSINMARCH = 31;
	static final int DAYSINAPRIL = 30;
	static final int DAYSINMAY = 31;
	static final int DAYSINJUNE = 30;
	static final int DAYSINJULY = 31;
	static final int DAYSINAUGUST = 31;
	static final int DAYSINSEPTEMBER = 30;
	static final int DAYSINOCTOBER = 31;
	static final int DAYSINNOVEMBER = 30;
	static final int DAYSINDECEMBER = 31;
	
	public static void main(String[] args)
	{
		Scanner scanner = new Scanner(System.in);
		
		// Get a year from the user
		System.out.print("Enter a year (YYYY): ");
		int year = scanner.nextInt();

		// Get a month from the user
		System.out.print("Enter a month (MM): ");
		int month = scanner.nextInt();
		
		// Get a day from the user
		System.out.print("Enter a day (DD): ");
		int day = scanner.nextInt();
		
		scanner.close();
		
		System.out.print(month + "/" + day + "/" + year + " was a ");

		// Find the total number of days passed since 1/1/1
		int totalDays = 0;
		
		// Add days from every completed year
		// 365 per year, plus leap days, minus the turns of century's leap days, plus every 4th turn of a century's leap day
		totalDays += (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
		
		// Add days from every completed month in the current year
		while(month > 1)
		{
			month--;
			totalDays += daysInMonth(month, year);
		}
		
		// Add completed days from the current month
		totalDays += day;
		
		// Find the weekday using modulus
		switch(totalDays % 7)
		{
			case 1:
				System.out.print("Monday.\n");
				break;
			case 2:
				System.out.print("Tuesday.\n");
				break;
			case 3:
				System.out.print("Wednesday.\n");
				break;
			case 4:
				System.out.print("Thursday.\n");
				break;
			case 5:
				System.out.print("Friday.\n");
				break;
			case 6:
				System.out.print("Saturday.\n");
				break;
			case 0:
				System.out.print("Sunday.\n");
				break;
		}
	}
	
	/**
	 * daysInMonth() reads in a month and a year, and give the number of days in that month
	 * @param month - an int from 1 to 12 representing a month
	 * @param year  - an int for the current year, used for Febuary's special leap year cases
	 * @return an int for the number of days in the month passed
	 */
	private static int daysInMonth(int month, int year)
	{
		if(month == 1) // month is January
		{
			return DAYSINJANUARY;
		} 
		else if(month == 2) // month is February
		{
			// Check if it is a leap year
	        if(year % 4 == 0)
	        {
	            if( year % 100 == 0) // is a century year
	            {
	                if ( year % 400 == 0) // is every 4th century year
	                {
	                    return DAYSINFEBRUARYLEAPYEAR;
	                }
	                else
	                {
	                    return DAYSINFEBRUARY;
	                }
	            }
	            else
	            {
	                return DAYSINFEBRUARYLEAPYEAR;
	            }
	        }
			return DAYSINFEBRUARY;
		}
		else if(month == 3) // month is March
		{
			return DAYSINMARCH;
		}
		else if(month == 4) // month is April
		{
			return DAYSINAPRIL;
		}
		else if(month == 5) // month is May
		{
			return DAYSINMAY;
		}
		else if(month == 6) // month is June
		{
			return DAYSINJUNE;
		}
		else if(month == 7) // month is July
		{
			return DAYSINJULY;
		}
		else if(month == 8) // month is August
		{
			return DAYSINAUGUST;
		}
		else if(month == 9) // month is September
		{
			return DAYSINSEPTEMBER;
		}
		else if(month == 10) // month is October
		{
			return DAYSINOCTOBER;
		}
		else if(month == 11) // month is November
		{
			return DAYSINNOVEMBER;
		}
		else // month is December
		{
			return DAYSINDECEMBER;
		}
	}
}
