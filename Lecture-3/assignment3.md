Problem 3.1
Code profiling and registers. In this problem, we will use some basic code profiling to examine the effects of explicitly declaring variables as registers. Consider the fibonacci sequence generating function fibonacci in prob1.c, which is reproduced at the end of this problem set (and can be downloaded from Stellar). The main() function handles the code profiling, calling fibonacci() many times and measuring the average processor time. 

(a) First, to get a baseline (without any explicitly declared registers), compile and run prob1.c. Code profiling is one of the rare cases where using a debugger like gdb is discouraged, because the debugger’s overhead can impact the execution time. Also, we want to turn off compiler optimization. Please use the following commands to compile and run the program:
dweller@dwellerpc:~$ gcc -O0 -Wall prob1.c -o prob1.o
dweller@dwellerpc:~$ ./prob1.o
Avg. execution time: 0.000109 msec ← example output
dweller@dwellerpc:~$
How long does a single iteration take to execute (on average)?

ans:
emily@raspberrypi ~/D/M/Lecture-3 (main)> gcc -o0 -Wall prob1.c -o prob1.o
emily@raspberrypi ~/D/M/Lecture-3 (main)> ./prob1.o 
Avg. execution time: 0.000557398 msec

(b) Now, modify the fibonacci() function by making the variables a, b, and c register variables. Recompile and run the code. How long does a single iteration take now, on average? Turn in a printout of your modified code (the fibonacci() function itself would suffice).
ans:
emily@raspberrypi ~/D/M/Lecture-3 (main)> gcc -o0 -Wall prob1-b.c -o prob1-b.o
emily@raspberrypi ~/D/M/Lecture-3 (main)> ./prob1-b.o 
Avg. execution time: 0.000552282 msec

(c) Modify the fibonacci() function one more time by making the variable n also a register variable. Recompile and run the code once more. How long does a single iteration take with all four variables as register variables?
ans:
emily@raspberrypi ~/D/M/Lecture-3 (main)> gcc -o0 -Wall prob1-c.c -o prob1-c.o
emily@raspberrypi ~/D/M/Lecture-3 (main)> ./prob1-c.o 
Avg. execution time: 0.000134014 msec

(d) Comment on your observed results. What can you conclude about using registers in your code?
ans:
Using registers in code would make it quicker. And the result would be more obvious if the variable is frequently called.

Problem 3.2
We are writing a simple searchable dictionary using modular programming. First, the program reads a file containing words and their definitions into an easily searchable data structure. Then, the user can type a word, and the program will search the dictionary, and assuming the word is found, outputs the definition. The program proceeds until the user chooses to quit. We split the code into several files: main.c, dict.c, and dict.h. The contents of these files are described briefly below.

Answer the following questions based on the above program structure.
(a) In implementing this program, you want to access the global variable the dictionary from main.c, as well as from dict.c. However, due to the header file’s inclusion in both source documents, the variable gets declared in both places, creating an ambiguity. How would you resolve this ambiguity?
ans:
This is a good question!
I will declare the variable in dict.c, then extern it in dict.h. Then main.c could include the dict.h headfile.

(b) Now, suppose you want to restrict the dictionary data structure to be accessible only from functions in dict.c. You remove the declaration from dict.h. Is it still possible to directly access or modify the variable from main.c, even without the declaration in dict.h? If so, how would you ensure the data structure variable remains private?
ans:
using extern key word.

(c) Congratulations! You’re done and ready to compile your code. Write the command line that you should use to compile this code (using gcc). Let’s call the desired output program dictionary.o.
ans:
gcc -o0 -Wall main.c dict.c -o dictionary.o

Problem 3.3
Both the for loop and the do-while loop can be transformed into a simple while loop. For each of the following examples, write equivalent code using a while loop instead.
(a) 
```
int factorial(int n){
	int i, ret = 1;
	for ( i = 2 ; i <= n ; i++)
	ret ∗= i;

	return ret;
}
```
ans:
```
int factorial(int n){
	int i = 2, ret = 1;
	while (i <= n)
	{
		ret *= i;
		i++;
	}

	return ret;
```
(b)
```
#include <stdlib.h>

double rand_double(){
/∗ generate random number in [ 0 , 1 ) ∗/
	double ret = (double)rand();
	return ret /(RANDMAX+1);
}

int sample_geometric_rv(double p){
	double q;
	int n = 0;
	do{
		q = rand_double();
		n++;
	}while (q >= p);

	return n;
}
```
Note: you only need to modify the sample_geometric_rv() function.

ans:
```
int sample_geometric_rv(double p){
	double q;
	int n=1;
	while(q>=p)
	{
		q = rand_double();
		n++;
	}

	return n;
```

Problem 3.4
’wc’ is a unix utility that display the count of characters, words and lines present in a file. If no file is specified it reads from the standard input. If more than one file name is specified it displays the counts for each file along with the filename. In this problem, we will be implementing wc. 
One of the ways to build a complex program is to develop it iteratively, solving one problem at a time and testing it throroughly. For this problem, start with the following shell and then iteratively add the missing components.
ans:
```
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	FILE* fp = NULL;
	int nfiles = --argc;
	int argidx = 1;
	char* currfile = "";
	int c;

	/*count of words, lines, characters*/
	unsigned long nw=0, nl=0, nc=0;
	
	if(nfiles==0)
	{
		fp = stdin; /*standard input*/
		nfiles++;
		printf("debug1\n");
	}
	else
	{
		currfile=argv[argidx++];
		fp=fopen(currfile, "r");
		printf("debug2 %d %s\n", nfiles, currfile);
	}
	while(nfiles>0) /*files left>0*/
	{
		if(fp==NULL)
		{
			fprintf(stderr, "Unable to open input\n");
			exit(-1);
		}
		nc=nw=nl=0;
		char previousC;
		previousC = EOF;
		while((c=getc(fp))!=EOF)
		{
			if(c=='\n')
			{
				nl++;
			}
			else if(((previousC==' ')|(previousC=='\n')|(previousC=='\t'))&&((c!=' ')&&(c!='\n')&&(c!='\t')))
			{
				nw++;
			}
			previousC = c;
			nc++;
		}
		if (nl!=0)
		{
			nw++;
		}
		printf("word=%ld, line=%ld, character=%ld, currfile=%s\n", nw, nl, nc, currfile);
		nfiles--;
		if(nfiles>0)
		{
			currfile=argv[argidx++];
			fp=fopen(currfile, "r");
		}
	}
	
	return 0;
}

```

```
emily@raspberrypi ~/D/M/Lecture-3 (main)> gcc -o0 -Wall prob4.c -o prob4.o
emily@raspberrypi ~/D/M/Lecture-3 (main)> ./prob4.o stateoutflow0708.txt
debug2 1 stateoutflow0708.txt
word=23418, line=2602, character=158539, currfile=stateoutflow0708.txt
emily@raspberrypi ~/D/M/Lecture-3 (main)> wc stateoutflow0708.txt
  2602  23418 158539 stateoutflow0708.txt
emily@raspberrypi ~/D/M/Lecture-3 (main)> wc fileList.txt
 1  1 20 fileList.txt
emily@raspberrypi ~/D/M/Lecture-3 (main)> ./prob4.o fileList.txt 
debug2 1 fileList.txt
word=1, line=1, character=20, currfile=fileList.txt
```
Problem 3.5
In this problem, we will be reading in formatted data and generating a report. One of the common formats for interchange of formatted data is ’tab delimited’ where each line corresponds to a single record. The individual fields of the record are separated by tabs. For this problem, download the file stateoutflow0708.txt from Stellar. This contains the emigration of people from individual states. The first row of the file contains the column headings. There are eight self explanatory fields. Your task is to read the file using fscanf and generate a report outlining the migration of people from Massachusetts to all the other states. Use the field ”Aggr AGI” to report the numbers. Also, at the end, display a total and verify it is consistent with the one shown below. An example report should look like the following:
```
STATE			TOTAL
---------------------
"FLORIDA"		590800
"NEW HAMPSHIRE" 421986
..........
---------------------
Total			4609483
```

ans:
```

```

















