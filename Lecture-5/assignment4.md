Problem 4.1
Consider the insertion sort algorithm described in Lecture 5 In this problem, you will re-implement the algorithm using pointers and pointer arithmetic.
(a) The function shift_element() takes as input the index of an array element that has been determined to be out of order. The function shifts the element towards the front of the array,
repeatedly swapping the preceding element until the out-of-order element is in the proper location. The implementation using array indexing is provided below for your reference:
```
/∗ move previous elements down until in sertion point reached ∗/
void shift_element(unsigned int i)
{
	int ivalue;
	/* guard against going outside array */
	for (ivalue = arr[i]; i&&arr[i-1]>ivalue; i--)
		arr[i] = arr[i-1]; /* move element down */
	arr[i] = ivalue;   /* insert element */
}
```

Re-implement this function using pointers and pointer arighmetic instead of array indexing.

```
/* int *pElement - pointer to the element
	int arr(type int[]) that is out-of-place*/
void shift_element(int *pElement)
/* insert code here*/
{
	int ivalue;

	for(ivalue = *pElement;pElement>arr && *(pElement-1)>ivalue; pElement-- )
		*pElement = *(pElement-1);
	*pElement = ivalue;
}
```
(b) The function insertion_sort() contains the main loop of the algorithm. It iterates through elements of the array, from the beginning, until it reaches an element that is out-of-order. It calls shift_element() to shift the offending element to its proper location earlier in the array and resumes iterating until the end is reached. The code from lecture is provided below:
```
/* iterate until out-of-oder element found;
	shift the element, and continue iterating */
void insertion_sort(void)
{
	unsigned int i, len = array_length(arr);

	for (i=1; i<len; i++)
		if (arr[i]<arr[i-1])
			shift_element(i);
}
```
Re-implement this function using pointers and pointer arithmetic instead of array indexing.
Use the shift_element() function you implemented in part(a).
```
void insertion_sort(void)
{
	int *pElement = NULL;
	int *pEnd = arr + array_length(arr);

	for (pElement=arr+1; pElement<pEnd; pElement++)
		if (*pElement < *(pElement-1))
			shift_element(pElement);
}
```
Problem 4.2
In this problem, we will use our knowledge of strings to duplicate the functionality of the C standard library's strtok() function, which extracts "tokens"from a string. 
The string is split using a set of delimiters, such as whitespace and punctuation. Each piece of the string, without its surrounding delimiters, is a token.
The process of extracting a token can be split into two parts: finding the beginning of the token (the first character that is not a delimiter), and finding the end of the token (the next character that is a delimiter). 
The first call of strtok() looks like this:
```
char *strtok (char *str; const char *delims);
```
The string str is the string to be tokenized, delims is a string containing all the single characters to use as delimiters (e.g. " \t\r\n"), and the return value is the first token in str.
Additional tokens can be obtained by calling strtok() with NULL passed for the str argument:
```
char *strtok(NULL, const char *delims);
```
Because strtok() uses a static variable to store the pointer to the beginning of the next token, calls to strtok() for different strings cannot be interleaved. The code for strtok() is provided below:
```
char *strtok(char *text, const char *delims)
{
	/* initialize */
	if (!text)
		text = pnexttoken;

	/* find start of token in text */
	text += strspn(text, delims);
	if (*text == '\0')
		return NULL;
	/*find end of token in text */
	pnexttoken = text +strspn(text, delims);
	/*insert null-terminator at end */
	if (*pnexttokent != '\0')
		*pnexttoken++ = '\0';
	return text;
}
```
(a) In the context of our string tokenizer, the function strspn() conputes the index of the first non-delimiter character in our string. Using pointers or array indexing (your choice), implement the strspn() function. In order to locate a character in another string, you may use the function strpos(), which is declared below:
```
int strpos(const char *str, const char ch);
``` 
This function returns the index of the first occurrence of the character ch in the string str, or -1 if ch is not found. The declaration of strspn() is provided below:
Here, delims is a string containing the set of delimiters, and the return value is the index of the first non-delimiter character in the string str. For instance, strspn(" . This", ".") == 3. If the string contains only delimiters, strspn() should return the index of the null-terminator ('\0'). Assume '\0' is not a delimiter.
```
unsigned int strspn(const char *str, const char *delims)
{
	int index;
	for (index=0; *(str+index)!=NULL; index++)
	{
		for (int i=0; *(delims+i)!=NULL; i++)
		{
			if (-1 == strpos(str+index, *(delims+i))
				return index;
		}
	}

	return index;
}
```
(b) The function strcspn() computes the index of the first delimiter character in our string. Here's the declaration of strcspn():
```
unsigned int strcspn(const char *str, const char *delims)
{
	int index;
	
	for (index=0; *(str+index)!=NULL; index++)
	{
		for (int i=0; *(delims+i)!=NULL; i++)
		{
			if (-1 != strpos(str+index, *(delims+i))
				return index;
		}
	}

	return index;
}


```
if the string contains no delimiters, return the idex of the null-terminator ('\0'). IMplement this function using either pointers or array indexing.

Problem 4.3
In this problem, you will be implementing the shell sort. This sort is built upon the insertion sort, but attains a speed increase by comparing far-away elements against each other before comparing closer-together elements. This distance between elements is called the "gap". In this shell sort, the array is sorted by sorting gap sub-arrays, and then repeating with a smaller gap size.
	As written here, the algorithm sorts in O(n^2) time. However, by adjusting the sequence of gap sizes used, it is possible to improve the performance to O(n^3/2), O(n^4/3), or even O(n(logn)^2) time. You can read about a method for performing the shell sort in O(n(log n)^2) time on Robert Sedgewick's page at Princeton:
	http://www.cs.princeton.edu/~rs/shell/paperF.pdf
Note that you can find complete C code for the shell sort at the beginning of the paper, so please wait until you have finished this exercise to read it.
(a) First, we will modify the shift_element() function from the insertion sort code for the shell sort. The new function, started for you below, should start at index i and shift by intervals of size gap. Write the new function, using array indexing or pointers. Assume that i>=gap.
```
void shift_element_by_gap(unsigned int i, unsigned int gap)
{
	


}




























