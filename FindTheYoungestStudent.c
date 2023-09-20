#include "FindTheYoungestStudent.h"
#include <string.h>
#include <stdlib.h>

int compareAgeSmaller(char date1[], char date2[]){
    char date1Copy[100], date2Copy[100];
    strcpy(date1Copy, date1);
    strcpy(date2Copy, date2);

    replaceCharsWithSpace(date1Copy);
    replaceCharsWithSpace(date2Copy);

    char *d1 = strtok(date1Copy, " ");
    int tmp1[3];
    int n1 = 0;
    while(d1 != NULL){
        int date = atoi(d1);
        tmp1[n1] = date;
        n1++;
        d1 = strtok(NULL, " ");
    }

    char *d2 = strtok(date2Copy, " ");
    int tmp2[3];
    int n2 = 0;
    while(d2 != NULL){
        int date = atoi(d2);
        tmp2[n2] = date;
        n2++;
        d2 = strtok(NULL, " ");
    }

    //Y tuong: dua het so vao 1 mang char, tu cuoi ve dau xong dung strcmp

    for(int i = 2; i >= 0; i--){
        if(tmp1[i] <= tmp2[i]){
            return 0;
        }
    }
    return 1;
}

Student findYoungestStudent(Student arr[], int num){
    Student youngestStudent = arr[0];

    for(int i = 1; i < num; i++){
        if(compareAgeSmaller(arr[i].birthdate, youngestStudent.birthdate) > 0){
            youngestStudent = arr[i];
        }
    }
    return youngestStudent;
}