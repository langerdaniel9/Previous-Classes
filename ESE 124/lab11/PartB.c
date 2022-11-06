#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//set up the struct
typedef struct person
{
    char * firstName;
    char * lastName;
    int zipCode;
    int age;
    float GPA;
} person;


void _display(person *array, int n) {
    int i;
    
    //print
    for(i=0; i<n; i++) {
        printf("%s %s %i %i %.1f", array[i].firstName, array[i].lastName, array[i].zipCode, array[i].age, array[i].GPA);
        printf("\n");
    }
    printf("\n");
}

void _GPASort(person *array, int n) {
    int i;
    person temp;
    bool sorted = false;

    //bubble sort GPA 
    while(!sorted) {
        sorted = true;
        for(i=0; i<n-1; i++) {
            if(array[i].GPA < array[i+1].GPA) {
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
                sorted = false;
            }
        }
    }

    //use display function to print results
    _display(array, n);
}

void _lastNameSort(person *array, int n) {
    int i, j;
    person temp;
    bool sorted = false;

    //bubble sort last names 
    while(!sorted) {
        sorted = true;
        for(i=0; i<n-1; i++) {
            if(strcmp(array[i].lastName, array[i+1].lastName) > 0) {
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
                sorted = false;
            } 
        }
    }

    //use display function to print results
    _display(array, n);
}

void _zipFilter(person *array, int n, int inputZip) {
    int i, printed;

    //if ZipCode matches user input, print those that match
    for(i=0; i<n; i++) {
        if(array[i].zipCode == inputZip) {
            printf("%s %s %i %i %.1f", array[i].firstName, array[i].lastName, array[i].zipCode, array[i].age, array[i].GPA);
            printf("\n");
            printed++;
        }
    }

    //if no matches
    if(printed == 0) {
        printf("No matching entries\n");
    }
    printf("\n");
}

int main() {
    int i;

    //open input file
    FILE *input;

	if ((input = fopen("input.txt", "r")) == NULL){
		printf("error: file cannot be opened\n");
		exit(1);
	}

    //get the first row (number of rows)
    int n = 0;
    fscanf(input, "%d", &n);

    //set up dynamically created array
    person* array = malloc(n*sizeof *array);
    for(i=0; i<n; i++) {
        array[i].firstName = (char*)malloc(sizeof(char*));
        array[i].lastName = (char*)malloc(sizeof(char*));
    }
    if(array == NULL) {
        printf("memory allocation failed\n");
        exit(1);
    }
    //loop through the file getting information into the array

    for(i=0; i<n; i++) {
        fscanf(input, "%s %s %i %i %f", array[i].firstName, array[i].lastName, &array[i].zipCode, &array[i].age, &array[i].GPA);
    }


    //loop and do the functions that the user tells it to
    while(true) {
        char inputChar;
        printf("what function to execute?(D, O, A, or Z)\n");
        inputChar = getchar();
        getchar();
        switch(inputChar) {
            case 'D': {
                _display(array, n);
                break;
            };
            case 'O': {
                _GPASort(array, n);
                break;
            };
            case 'A': {
                _lastNameSort(array, n);
                break;
            };
            case 'Z': {
                int inputZip;
                printf("Enter the zip code:");
                scanf("%i", &inputZip);
                getchar();
                _zipFilter(array, n, inputZip);
                break;
            };
            default : {
                printf("thats not a function, try again.\n");
                break;
            }
        }
    }

}