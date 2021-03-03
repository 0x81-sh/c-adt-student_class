#include <stdio.h>
#include <limits.h>
#include "class.h"

int genericErrored = 0;
void testAddStudent(PClass instance, PStudent toAdd);
void testRemoveStudent(PClass instance, int index);

int main() {
    PClass testClass = Class_create("test");
    printf("WARNING: Validation will NOT validate all aspects, rather it is an assistive tool to verify some generic properties. Check output manually.\n\n");

    testAddStudent(testClass, Student_create("First1", "Second1"));
    testAddStudent(testClass, Student_create("First2", "Second2"));

    testRemoveStudent(testClass, 0);
    testRemoveStudent(testClass, 15);

    if (genericErrored) {
        printf("\nSOME TESTS ERRORED (EC %d).\n", genericErrored);
    } else {
        printf("\nAll tests passed validation.\n");
    }

    Class_delete(testClass);
    return 0;
}

void testAddStudent(PClass instance, PStudent toAdd) {
    printf("Test: adding student to an class (at end): ");
    Student_print(toAdd, 0);

    printf("\n\tClass before:\n");
    Class_print(instance, 2);
    int sizeBefore = Class_getNumberOfStudents(instance);

    Class_addStudent(instance, toAdd);

    printf("\tClass afterwards:\n");
    Class_print(instance, 2);
    printf("\n");

    //validate
    if (sizeBefore + 1 != Class_getNumberOfStudents(instance)) genericErrored++;
    if (Student_cmp(toAdd, Class_getStudent(instance, INT_MAX)) > 0) genericErrored++;
}

void testRemoveStudent(PClass instance, int index) {
    printf("Test: removing student from class at index %d: ", index);

    printf("\n\tClass before:\n");
    Class_print(instance, 2);
    int sizeBefore = Class_getNumberOfStudents(instance);

    Class_deleteStudent(instance, index);

    printf("\tClass afterwards:\n");
    Class_print(instance, 2);
    printf("\n");

    //validate
    if (sizeBefore - 1 != Class_getNumberOfStudents(instance) && Class_getNumberOfStudents(instance) != 0) genericErrored++;
}