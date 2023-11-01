package q5;

import java.util.ArrayList;

/**
 * ArrayListReverser is a wrapper class for one method,
 * reverse() that reverses the order of elements in an ArrayList<E>
 * @author Karl Ramberg
 */
public class ArrayListReverser
{
	/**
	 * reverse() reverses the elements in the provided ArrayList<E> 
	 * @param <E> : any generic object
	 * @param list : the list of elements to reverse the order of
	 */
	public static <E> void reverse(ArrayList<E> list)
	{
		for(int index = list.size() - 1; index >= 0; index--)
		{
			list.add(list.remove(index));
		}
	}
}
