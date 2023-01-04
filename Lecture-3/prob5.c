#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STATE_NUM (50)
#define MAX_STATE_CHARACTER_COUNT (20)

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
	char tempStr[MAX_STATE_CHARACTER_COUNT];
	bool findFlag=false;
	int stateCount = 0;
	int endFlag = EOF;
	int tempCnt = 0;
	int total = 0;
	for (int count=0; count<1000; count++)
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
				if (strcmp(tempStr,"25"))
				{
					findFlag = true;
				}
				continue;
			}
			if (findFlag && (5==count%9))
			{
				fscanf(fp, "%s", tempStr);
				for (int i=0; i<=stateCount; i++)
				{
					if (!strcmp(tempStr, withMassaInfo[stateCount].stateName)&&(i==stateCount))
					{
						stateCount++;
						tempCnt = stateCount;
						memset(withMassaInfo[stateCount].stateName, '\0', MAX_STATE_CHARACTER_COUNT);
						strcpy(withMassaInfo[stateCount].stateName,tempStr);
					}
					else if (strcmp(tempStr, withMassaInfo[stateCount].stateName))
					{
						tempCnt = i;
						memset(withMassaInfo[stateCount].stateName, '\0', MAX_STATE_CHARACTER_COUNT);
						strcpy(withMassaInfo[stateCount].stateName,tempStr);
						break;
					}
				}
				continue;
			}
			if (findFlag && (8==count%9))
			{
				fscanf(fp, "%d", &withMassaInfo[tempCnt].aggrNum);
				findFlag = false;
				continue;
			}
			
			fscanf(fp, "%s", tempStr);
		}

	}
	
	printf("STATE\t\t\tTOTAL\n");
	printf("-------------------------\n");

	for (int i=0; i<stateCount; i++)
	{
		printf("%s\t\t\t%d\n", withMassaInfo[i].stateName, withMassaInfo[i].aggrNum);
		total += withMassaInfo[i].aggrNum;
	}
	printf("-------------------------\n");
	printf("Total\t\t\t%d\n", total);
// first we need to get the state code of Massachusetts





}
