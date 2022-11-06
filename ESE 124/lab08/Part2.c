#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int my_strcmp(char * str1, char * str2) {
	int str1len = strlen(str1), str2len = strlen(str2), i;
	if(str1len >= str2len) {
		for(i=0; i<str1len; i++) {
			if(str1[i] != str2[i]) {
				return 1;
			}
		}
		return 0;
	} else {
		for(i=0; i<str2len; i++) {
			if(str1[i] != str2[i]) {
				return 1;
			}
		}
		return 0;
	}
}

int my_strncmp(char * str1, char * str2, int n) {
	int i;
	for(i=0; i<n; i++) {
		if(str1[i] != str2[i]) {
			return 1;
		}
	}
	return 0;
}

char * my_strcpy(char * str1, char * str2) {
	str1 = str2;
	//printf("%s %i\n", str1, str1);
	return str1;
}

char * my_strncpy(char * str1, char * str2, int n) {
	int i;
	for(i=0; i<n; i++) {
		str1[i] = str2[i];
	}
	//printf("%s %i\n", str1, str1);
	return str1;
}

char * my_strcat(char * str1, char * str2) {
	int str1len = strlen(str1);
	int str2len = strlen(str2);
	int i;
	for(i=0; i<str2len; i++) {
		str1[i+str1len] = str2[i];
	}
	str1[str1len+str2len] = '\0';
	return str1;
}

char * my_reverse(char * str1) {
	int str1len = strlen(str1);
	char temp[30];
	int i;
	for(i=0; i<str1len; i++) {
		temp[i] = str1[str1len-i-1];  
	}
	temp[str1len] = '\0';
	for(i=0; i<str1len; i++) {
		str1[i] = temp[i];
	}
	//printf("string - %s", output);
	return str1;
}

int main() {
	//string compare
	char strCmpStr1[30] = "Hello", strCmpStr2[30] = "Hi";
	printf("my_strcmp(%s, %s) returns %i\n", strCmpStr1, strCmpStr2, my_strcmp(strCmpStr1, strCmpStr2));
	
	char strCmpStr1_2[30] = "Hello", strCmpStr2_2[30] = "Hello";
	printf("my_strcmp(%s, %s) returns %i\n\n", strCmpStr1_2, strCmpStr2_2, my_strcmp(strCmpStr1_2, strCmpStr2_2));
	
	//n string compare
	char strNCmpStr1[30] = "Hello", strNCmpStr2[30] = "Hi";
	int strNCmpN = 3;
	printf("my_strncmp(%s, %s, %i) returns %i\n", strNCmpStr1, strNCmpStr2, strNCmpN, my_strncmp(strNCmpStr1, strNCmpStr2, strNCmpN));	
	
	char strNCmpStr1_2[30] = "Hello", strNCmpStr2_2[30] = "Hi";
	int strNCmpN_2 = 1;
	printf("my_strncmp(%s, %s, %i) returns %i\n\n", strNCmpStr1_2, strNCmpStr2_2, strNCmpN_2, my_strncmp(strNCmpStr1_2, strNCmpStr2_2, strNCmpN_2));	
	
	//string copy
	char strCpyStr1[30] = "Hello", strCpyStr2[30] = "Hi";
	printf("my_strcpy(string1, \"%s\") returns %i\n", strCpyStr2, my_strcpy(strCpyStr1, strCpyStr2));
	
	char strCpyStr1_2[30] = "Test", strCpyStr2_2[30] = "Replace";
	printf("my_strcpy(string1, \"%s\") returns %i\n\n", strCpyStr2_2, my_strcpy(strCpyStr1_2, strCpyStr2_2));
	
	//n string copy
	char strNCpyStr1[30] = "Hello", strNCpyStr2[30] = "Hi";
	int strNCpyN = 3;
	printf("my_strncpy(string1, \"%s\", %i) returns %i\n", strNCpyStr2, strNCpyN, my_strncpy(strNCpyStr1, strNCpyStr2, strNCpyN));
	
	char strNCpyStr1_2[30] = "Testing", strNCpyStr2_2[30] = "bananas";
	int strNCpyN_2 = 3;
	printf("my_strncpy(string1, \"%s\", %i) returns %i\n\n", strNCpyStr2_2, strNCpyN_2, my_strncpy(strNCpyStr1_2, strNCpyStr2_2, strNCpyN_2));
	
	//string concatenate 
	char strCatStr1[30], strCatStr2_1[30] = "hi";
	printf("my_strcat(string1, \"%s\") creates %s and returns %i\n", strCatStr2_1, strCatStr1, my_strcat(strCatStr1, strCatStr2_1));
	char strCatStr2_2[30] = "newyork";
	printf("my_strcat(string1, \"%s\") creates %s and returns %i\n\n", strCatStr2_2, strCatStr1, my_strcat(strCatStr1, strCatStr2_2));
	
	//string reverse
	//this changes the original, so make a copy to show the original
	char strRevStr1[30] = "Hellow", strRevStr1Cpy[30] = "Hellow";
	printf("my_reverse(%s) creates %s and returns %i\n", strRevStr1Cpy, strRevStr1, my_reverse(strRevStr1));
	
	char strRevStr1_2[30] = "reverse", strRevStr1Cpy_2[30] = "reverse";
	printf("my_reverse(%s) creates %s and returns %i\n\n", strRevStr1Cpy_2, strRevStr1_2, my_reverse(strRevStr1_2));
	return 0;
}
