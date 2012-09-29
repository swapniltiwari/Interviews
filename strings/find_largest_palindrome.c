/*
 * Largest Palindrome in the String
 *
 *  Created on: September 28, 2012
 *      Author: Swapnil
 */


// Find the longest palindrome in a string
// Returns the length of the maximum palindrome and stores the position in pointer

int find_largest_palindrome(char *str, int *pos)
{
	int length = 1, max = 1;
	//
	char *left,*current,*right;
	current = str;
	*pos = 1;

	while(*current)
	{
		left  = current - 1;
		right = current + 1;
		length = 1;
		while(current >= str && ((*current) == (*left)))
		{
				left--;
				length++;
		}

		while(*right && ((*right) == (*current)))
		{
			right++;
			length++;
		}

		while(left >= str && *right &&  ((*right) == (*left)))
		{
			left--;right++;
			length += 2;
		}
		if(length > max)
		{
			*pos = left + 1 - str;
			max = length;
		}
		current++;
	}
	return max;
}


