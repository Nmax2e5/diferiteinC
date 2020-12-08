#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

int main()
{

    FILE* in  = fopen("input.txt",  "r");
	FILE* out = fopen("output.txt", "w");

	int a,b;
	fscanf(in, "%d %d", &a, &b);

	fprintf(out,"%d", a+b);

	fclose(in);
	fclose(out);

    return 0;
}
