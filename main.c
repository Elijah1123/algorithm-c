#include <stdio.h>
#include <stdlib.h>

//1. Define a Data Structure
typedef struct {
    int id;
    float score;
}Student;

// 2.The "Algorithm" Logic (Comparator function)
// This tells C how to compare two 'Student' structures

int compareStudents(const void *a, const void *b){
    Student *studentA = (Student *)a;
    Student *studentB = (Student *)b;

    return (studentA->score > studentB->score) - (studentA->score  < studentB->score);
}

int main(){

    // 3. create an arry of our data strucure

    Student list[] = {
        {101, 88.5},
        {102, 95.0},
        {103, 72.1}


    };

    int n = sizeof(list) / sizeof(list[0]);

    qsort(list, n, sizeof(Student), compareStudents);

    printf("Sorted Students by Score:\n");
    for(int i = 0; i <n; i++) {
        printf("ID: %d | Score: %.1f\n", list[i].id, list[i].score);

    }



    return 0;
}