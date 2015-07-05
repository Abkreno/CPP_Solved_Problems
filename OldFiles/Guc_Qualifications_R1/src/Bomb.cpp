#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	FILE *inputFile = fopen("bomb.in", "r");
	FILE *outputFile = fopen("bomb.out", "w");
	double x1, y1, x2, y2, x3, y3, d1, d2, d3, r1, r2, r3, d;
	while (fscanf(inputFile, " %lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2,
			&x3, &y3) == 6) {
		d1 = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
		d2 = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
		d3 = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
		d = (d1 + d2 + d3) / 2;
		r3 = d - d1;
		r1 = d - d2;
		r2 = d - d3;
		fprintf(outputFile, "%.9lf\n%.9lf\n%.9lf\n", r1, r2, r3);
	}
	fclose(inputFile);
	fclose(outputFile);
	return 0;
}
