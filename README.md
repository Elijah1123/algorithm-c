
1. Library Imports
C
#include <stdio.h>
#include <stdlib.h>
stdio.h: Required for printf to display the sorted data.

stdlib.h: This is the "engine room" for algorithms in C. It contains qsort (Quick Sort), which is the standard way to sort data without writing an algorithm from scratch.

2. Defining the Data Structure
C
typedef struct {
    int id;
    float score;
} Student;
In C, we use a struct to group related data. Here, we create a Student type that holds both an integer (id) and a floating-point number (score).

typedef: This allows us to use the word Student directly instead of having to type struct Student every time.

3. The Comparator Function (The Logic)
C
int compareStudents(const void *a, const void *b) {
    Student *studentA = (Student *)a;
    Student *studentB = (Student *)b;
    
    return (studentA->score > studentB->score) - (studentA->score < studentB->score);
}
const void *a: qsort is "generic," meaning it can sort anything. It uses void pointers to handle any data type.

Casting: We "cast" (convert) the generic pointers back into Student pointers so the code knows we are looking at student scores.

Return Values:

Negative: a comes before b.

Zero: They are equal.

Positive: a comes after b.

4. Calculating Array Size
C
int n = sizeof(list) / sizeof(list[0]);
This is a common C trick. sizeof(list) gives the total bytes of the array, and sizeof(list[0]) gives the bytes of one item. Dividing them gives the total number of elements (n).

5. Executing the Algorithm (qsort)
C
qsort(list, n, sizeof(Student), compareStudents);
This function requires four specific arguments:

list: The array to be sorted.

n: How many items are in the array.

sizeof(Student): How big each item is (so the computer knows how many bytes to jump).

compareStudents: The name of the function containing our sorting logic.

6. The Output Loop
C
for(int i = 0; i < n; i++) {
    printf("ID: %d | Score: %.1f\n", list[i].id, list[i].score);
}
Finally, we loop through the now-sorted array and print the ID and Score. %.1f ensures we only see one decimal point.

🛠 Compilation Note
Unlike <math.h>, you do not need a special flag like -lm for <stdlib.h>. You can compile this normally:

Bash
gcc index.c -o index
./index
gcc index.c -o index
./index