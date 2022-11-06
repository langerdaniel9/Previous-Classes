#include <stdio.h>
#include <stdlib.h>

int main() {
	
	FILE *input;
	float array[5][5];
	int i, j;
	char line[500];

	if ((input = fopen("input.txt", "r")) == NULL){
		printf("error: file cannot be opened\n");
		exit(1);
	}
	
	
	//while (fgets(line, 100, input) != NULL)
	

	
	printf("The inputted array is:\n");
	for(i=0; i<=4; i++) {
		char temp1 [100], temp2 [100], temp3 [100], temp4 [100], temp5 [100];		
		fscanf(input, "%s %s %s %s %s", &temp1, &temp2, &temp3, &temp4, &temp5);
		//printf("--%s %s %s %s %s\n", temp1, temp2, temp3, temp4, temp5);
		array[i][0] = atof(temp1);
		array[i][1] = atof(temp2);
		array[i][2] = atof(temp3);
		array[i][3] = atof(temp4);
		array[i][4] = atof(temp5);
		
		for(j=0; j<5; j++) {
			printf("%f ", array[i][j]);
		}
		printf("\n");
		
	}
	printf("\n");
	
	// Part 1
	/*
	int rows[4];
	
	printf("Enter 3 rows to add (space separated):\n");
	scanf("%i %i %i", &rows[0], &rows[1], &rows[2]);
	
	float sum = 0;
	
	for(i=0; i<3; i++) {
		for(j=0; j<5; j++) {
			sum += array[rows[i-1]][j];
		}
	}
	
	printf("The total sum of rows %i, %i, %i is %f\n", rows[0], rows[1], rows[2], sum);
	*/
	//End of Part 1
	
	//Part 2
	/*
	float sum2 = 0;
	
	for(j=0; j<5; j++) {
		printf("%f ", array[0][j]);
		sum2+=array[0][j];
	}
	printf("\n");
	
	for(j=0; j<5; j++) {
		if(j<1) {
			printf("[       ] ");
		} else {
			printf("%f ", array[1][j]);
			sum2+=array[1][j];
		}
	}
	printf("\n");
	
	for(j=0; j<5; j++) {
		if(j<2) {
			printf("[       ] ");
		} else {
			printf("%f ", array[2][j]);
			sum2+=array[2][j];
		}
	}
	printf("\n");
	
	for(j=0; j<5; j++) {
		if(j<3) {
			printf("[       ] ");
		}else {
			printf("%f ", array[3][j]);
			sum2+=array[3][j];
		}
	}
	printf("\n");
	
	for(j=0; j<5; j++) {
		if(j<4) {
			printf("[       ] ");
		} else {
			printf("%f ", array[4][j]);
			sum2+=array[4][j];
		}
	}
	printf("\n");
	printf("The total sum of of the upper triangular matrix is %f\n", sum2);
	*/
	//End of Part 2
	
	//Part 3
	/*
	int rows[2];
	float holder[5];
	
	printf("Enter the rows to swap (space separated):\n");
	scanf("%i %i", &rows[0], &rows[1]);
	printf("\nThe row swapped result is:\n");
	
	for(i=0; i<5; i++) {
		holder[i] = array[rows[0]][i];
	}
	
	for(i=0; i<5; i++) {
		array[rows[0]][i] = array[rows[1]][i];
	}
	
	for(i=0; i<5; i++) {
		array[rows[1]][i] = holder[i];
	}
	
	for(j=0; j<5; j++) {
		for(i=0; i<5; i++) {
			printf("%f ", array[j][i]);
		}
		printf("\n");
	}
	printf("\n");
	*/
	//End of Part 3
	
	
	//Part 4
	float arrayT[5][5];
	for(j=0; j<5; j++) {
		for(i=0; i<5; i++) {
			arrayT[i][j] = array[j][i];
		}
		printf("\n");
	}
	printf("\nThe result of the matrix times its transpose is:\n");
	
	for(j=0; j<5; j++) {
		for(i=0; i<5; i++) {
			//printf("A (%f) | AT (%f) | ATA (%f)\n", array[i][j], arrayT[i][j], array[i][j]*arrayT[i][j]);
			printf("%f ", array[i][j]*arrayT[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	//End of Part 4
	return 0;
}









































