#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STATE_NUM (50)
#define MAX_STATE_CHARACTER_COUNT (20)

// declaration of functions
int getStateCode(char stateName);

struct STATEINFO
{
	char stateName[MAX_STATE_CHARACTER_COUNT];
	int aggrNum;
};

int main(void)
{
// variables for file read
	FILE* fp;
	fp = fopen("stateoutflow0708.txt", "r");
	struct STATEINFO withMassaInfo[MAX_STATE_NUM];
	char tempStr[20];
	bool findFlag=false;

	int endFlag = EOF;
	for (int count=0; count<20; count++)
	{
		if (count<9)
		{
			fscanf(fp, "%s", tempStr);
			continue;
		}
		else
		{
			if (0==count%9)
			{
				fscanf(fp, "%s", tempStr);
				if (strcmp(tempStr,"01"))
				{
					findFlag = true;
				}
				continue;
			}
			if (findFlag && (5==count%9))
			{
				fscanf(fp, "%s", withMassaInfo[0].stateName);
				continue;
			}
			if (findFlag && (8==count%9))
			{
				fscanf(fp, "%d", &withMassaInfo[0].aggrNum);
				findFlag = false;
			}
			
			fscanf(fp, "%s", tempStr);
		}

	}
	printf("test string %s", withMassaInfo[0].stateName);
// first we need to get the state code of Massachusetts





}

int getStateCode(char stateName)
{

	return 0;

}
