package q3;

import java.security.SecureRandom;

/**
 * Craps is an application for simulating games of craps
 * and calculating statistics for the games
 * @author Karl Ramberg
 */
public class Craps
{
	private static final SecureRandom randomNumbers = new SecureRandom();
	
	// some possible dice rolls in craps
	private static final int SNAKE_EYES = 2;
	private static final int TREY = 3;
	private static final int SEVEN = 7;
	private static final int YO_LEVEN = 11;
	private static final int BOX_CARS = 12;

	// number of games to simulate
	private static final int NUMBER_OF_GAMES = 1000000;

	// if the last game played was won
	private static boolean won;
	// the number of rolls the last game played took
	private static int rolls;
	
	/**
	 * playGame() plays one game of craps and will modify two variables
	 * a won boolean and the number of rolls it took to play.
	 */
	public static void playGame()
	{
		int myPoint = 0;
		rolls = 0;
		won = false;
		
		int sumOfDice = rollDice();
		rolls++;
		
		switch(sumOfDice)
		{
			case SEVEN:
			case YO_LEVEN:
				won = true;
				break;
			case SNAKE_EYES:
			case TREY:
			case BOX_CARS:
				return; // game lost
			default:
				myPoint = sumOfDice;
				break;
		}
		
		while(!won)
		{
			sumOfDice = rollDice();
			rolls++;
			
			if(sumOfDice == myPoint)
			{
				won = true;
			}
			else if(sumOfDice == SEVEN)
			{
				return; // game lost
			}
		}
	}

	/**
	 * rollDice() simulates rolling two dices
	 * @return the sum of the two dice
	 */
	public static int rollDice()
	{
		int die1 = 1 + randomNumbers.nextInt(6);
		int die2 = 1 + randomNumbers.nextInt(6);
		return die1 + die2;
	}
	
	public static void main(String[] args)
	{
		int[] results = new int[NUMBER_OF_GAMES];
		for(int i = 0; i < NUMBER_OF_GAMES; i++)
		{
			playGame();
			if(won)
			{
				results[i] = rolls;
			}
			else
			{
				results[i] = -rolls; // negative rolls signals the player lost
			}
		}
	
		// A
		// find the number of wins for each number of rolls up to 20
		for(int numberOfRolls = 1; numberOfRolls < 21; numberOfRolls++)
		{
			int wins = 0;
			for(int index = 0; index < results.length; index++)
			{
				if(results[index] == numberOfRolls)
				{
					wins++;
				}
			}
			System.out.printf("%d games won on roll %d\n", wins, numberOfRolls);
		}
		// find the number of wins of games that go above twenty rolls
		int winsPastTwentyRolls = 0;
		for(int index = 0; index < results.length; index++)
		{
			if(results[index] > 20)
			{
				winsPastTwentyRolls++;
			}
		}
		System.out.printf("%d games won after 20 rolls\n", winsPastTwentyRolls);
		System.out.println();

		// B
		// find the number of losses for each number of rolls up to 20
		for(int numberOfRolls = 1; numberOfRolls < 21; numberOfRolls++)
		{
			int losses = 0;
			for(int index = 0; index < results.length; index++) 
			{
				if(results[index] == -numberOfRolls)
				{
					losses++;
				}
			}
			System.out.printf("%d games lost on roll %d\n", losses, numberOfRolls);
		}
		// find the number of losses of games that go past twenty rolls
		int lossesPastTwentyRolls = 0;
		for(int index = 0; index < results.length; index++)
		{
			if(results[index] < -20)
			{
				lossesPastTwentyRolls++;
			}
		}
		System.out.printf("%d games lost after 20 rolls\n", lossesPastTwentyRolls);	
		System.out.println();
	
		// C
		// find the chances of winning at craps by counting the number of won games
		int wins = 0;
		for(int index = 0; index < results.length; index++)
		{
			if(results[index] > 0)
			{
				wins++;
			}
		}
		System.out.printf("%f%% chance to win craps\n", (((double)wins) / NUMBER_OF_GAMES) * 100.0);
		System.out.println();
	
		// D
		// find the average game length in number of dice rolls
		int totalRolls = 0;
		for(int index = 0; index < results.length; index++)
		{
			totalRolls += Math.abs(results[index]);
		}
		System.out.printf("It takes an average of %d rolls to play\n", totalRolls / NUMBER_OF_GAMES);
		System.out.println();
	
		// E
		// find the difference in games won one the first roll and past twenty
		// this will show if chances improve the longer the game goes on
		int winsOnFirstRoll = 0;
		for(int index = 0; index < results.length; index++)
		{
			if(results[index] == 1)
			{
				winsOnFirstRoll++;
			}
		}
		
		if(winsOnFirstRoll > winsPastTwentyRolls)
		{
			System.out.println("Chances do not improve as you play longer");
		}
		else if(winsPastTwentyRolls > winsOnFirstRoll) {
			System.out.println("Chances improve as you play longer");
		}
		else
		{
			System.out.println("Chances do not change as you play longer");
		}
	}
}
