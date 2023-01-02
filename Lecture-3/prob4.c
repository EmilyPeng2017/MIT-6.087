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
