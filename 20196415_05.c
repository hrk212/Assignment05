#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int sumNumbers(int* pNumbers, int nIndex)
{
	// basis step
	if (nIndex <= 0)
	{
		return pNumbers[0];
	}
	// recursive step
	else
	{

		return pNumbers[nIndex-1] + sumNumbers(pNumbers, nIndex-1);

	}
}


int main(int argc, char* argv[]) {

	FILE* fp1, * fp2;
	char str[64];   // change the number appropriately to your program
	// read_file = argv[1]
	// write_file = argv[2]

	// see the usage of r, rt, w, wt, r+, w+
	if ((fp1 = fopen(argv[1], "r")) == NULL) { //fail to open file for read
		printf("fale to open file.");
		return 0;
	}
	if ((fp2 = fopen(argv[2], "wt")) == NULL) { //fail to open file for write
		printf("fail to create file for write.");
		return 0;
	}
	/*
	while (fgets(str, sizeof(str), fp1)) {   // read a file and write to another file line by line
		printf("%s\n", str);
		fputs(str, fp2);
	}

	*/
	// recursive sum
	fgets(str, sizeof(str), fp1);

	int     nNumber = atoi(str);   // read from the input file
	int* pNumbers = (int*)calloc(nNumber, sizeof(int));

	for (int i = 0; i < nNumber; i++)
	{
		fgets(str, sizeof(str), fp1);
		pNumbers[i] = atoi(str);        // assign numbers from the input file 
	}
	/*
	printf("%d\n", pNumbers[0]);
	printf("%d\n", pNumbers[1]);
	printf("%d\n", pNumbers[2]);
	printf("%d\n", pNumbers[3]);
	printf("%d\n", pNumbers[4]);
	printf("%d\n", pNumbers[5]);
	printf("%d\n", pNumbers[6]);
	printf("%d\n", pNumbers[7]);
	printf("%d\n", pNumbers[8]);
	printf("%d\n", pNumbers[9]);
	printf("%d\n", pNumbers[10]);
	*/

	int    nSum = sumNumbers(pNumbers, nNumber);

//	printf("%d", nSum);
	sprintf(str,"%d\n", nSum);
	fputs(str, fp2);

	free(pNumbers);
	//


	fclose(fp1);
	fclose(fp2);
	return 0;
}
