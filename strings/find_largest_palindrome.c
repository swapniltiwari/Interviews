/*
 * Array.c
 *
 *  Created on: May 6, 2012
 *      Author: Swapnil
 */


// Find the longest palindrome in a string
// Returns the length of the maximum palindrome and stores the position in pointer

int find_largest_palindrome(char *str, int *pos)
{
	int length = 1, max = 1;
	char *p,*q,*r;
	p=str;
	*pos = 1;
	int count = 0;
	while(*p)
	{
		q=p-1;
		r=p+1;
		length = 1;
		while(p >= str && ((*p) == (*q)))
		{
				q--;
				length++;
		}

		while(*r && ((*r) == (*p)))
		{
			r++;
			length++;
		}

		while(q >= str && *r &&  ((*r) == (*q)))
		{
			q--;r++;
			length += 2;
		}
		if(length > max)
		{
			*pos = q + 1 - str;
			max = length;
		}
		p++;
	}
	return max;
}


int main()
{
	char *str = "dddwas";//aswapnillinpawsiuqe";
	int pos;
	int length = find_largest_palindrome(str, &pos);
	printf("The lenght of the largest palindrome is : %d starting at %d",length,pos);
	return 0;
}
