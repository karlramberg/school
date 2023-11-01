package q5;

import java.util.ArrayList;

/**
 * ArrayListReverserDriver is a executable class to test
 * the functionality of ArrayListReverser
 * @author Karl Ramberg
 */
public class ArrayListReverserDriver
{
	public static void main(String[] args)
	{
		// create a new ArrayList with numbers 1-10
		ArrayList<Integer> list = new ArrayList<Integer>();
		for(int num = 1; num <= 10; num++)
		{
			list.add(list.size(), new Integer(num));
		}
		
		// print the normal list
		System.out.println(list.toString());
		
		// reverse the list order
		ArrayListReverser.reverse(list);
		
		// print the reversed list
		System.out.println(list.toString());
	}
}
