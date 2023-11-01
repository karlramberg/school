package q4;

import java.security.SecureRandom;

/**
 * TortoiseAndHare is a simulation of the classic race between the
 * slow-and-steady tortoise and the fast-moving hare
 * @author Karl Ramberg
 */
public class TortoiseAndHare {
	private static final SecureRandom random = new SecureRandom();
	
	// track limits
	private static final int STARTINGGATE = 1;
	private static final int FINISHLINE = 70;

	// tortoise movements
	private static final int FASTPLOD = 3;
	private static final int SLIP = -6;
	private static final int SLOWPLOD = 1;

	// hare movements
	private static final int SLEEP = 0;
	private static final int BIGHOP = 9;
	private static final int BIGSLIP = -12;
	private static final int SMALLHOP = 1;
	private static final int SMALLSLIP = -2;

	/**
	 * limitToRange() keeps and integer within a given maximum and minimum
	 * @param num : the number to limit
	 * @param min : the minimum the number can be
	 * @param max : the maximum the number can be
	 * @return the limited number
	 */
	private static int limitToRange(int num, int min, int max)
	{
		if(num < min)
		{
			return min;
		}
		else if(num > max)
		{
			return max;
		}
		return num;
	}

	/**
	 * printRace() shows the current positions of the racers
	 * @param tortoise
	 * @param hare
	 */
	private static void printRace(int tortoise, int hare)
	{
		// print the tortoise
		for(int position = STARTINGGATE; position <= FINISHLINE; position++)
		{
			if(position != tortoise)
			{
				System.out.print('-');
			}
			else 
			{
				System.out.print('T');
			}
		}
		System.out.println();
		
		// print the hare
		for(int position = STARTINGGATE; position <= FINISHLINE; position++)
		{
			if(position != hare)
			{
				System.out.print('-');
			}
			else 
			{
				System.out.print('H');
			}
		}
		System.out.println();
		
		System.out.println();
	}
	
	public static void main(String[] args)
	{
		int tortoise = STARTINGGATE;
		int hare = STARTINGGATE;
	
		// print out the race start
		System.out.println("BANG!");
		System.out.println("AND THEY'RE OFF!");
		System.out.println();
		printRace(tortoise, hare);
		
		while(tortoise != FINISHLINE && hare != FINISHLINE)
		{
			// sleep for one second to add suspense
			try
			{
				Thread.sleep(1000);
			}
			catch (InterruptedException e)
			{
				e.printStackTrace();
			}
			
			// choose a random move for the tortoise
			switch(1 + random.nextInt(10))
			{
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
				tortoise += FASTPLOD;
				break;
			case 6:
			case 7:
				tortoise += SLIP;
				break;
			case 8:
			case 9:
			case 10:
				tortoise += SLOWPLOD;
				break;
			}
			
			// choose a random move for the hare
			switch(1 + random.nextInt(10))
			{
			case 1:
			case 2:
				hare += SLEEP;
				break;
			case 3:
			case 4:
				hare += BIGHOP;
				break;
			case 5:
				hare += BIGSLIP;
				break;
			case 6:
			case 7:
			case 8:
				hare += SMALLHOP;
				break;
			case 9:
			case 10:
				hare += SMALLSLIP;
				break;
			}
			
			// keep the racers on the track
			tortoise = limitToRange(tortoise, STARTINGGATE, FINISHLINE);
			hare = limitToRange(hare, STARTINGGATE, FINISHLINE);
			
			// print the racers positions 
			printRace(tortoise, hare);
		}
	
		// print the winner
		if(tortoise == FINISHLINE && hare == FINISHLINE)
		{
			System.out.println("IT'S A TIE!");
		}
		else if(tortoise == FINISHLINE)
		{
			System.out.println("TORTOISE WINS!");
		}
		else
		{
			System.out.println("HARE WINS!");
		}
	}
}
