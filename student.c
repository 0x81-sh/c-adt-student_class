#include "student.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define STR 60

int rollingId = 0;
struct Student {
    char firstName[STR];
    char lastName[STR];
    int id;
};

PStudent Student_create(char *first, char *last) {
    PStudent generated = (PStudent) malloc(sizeof(struct Student));

    generated->id = rollingId++;
    strcpy(generated->firstName, first);
    strcpy(generated->lastName, last);

    return generated;
}

char *Student_getFirstName(PStudent _this) {
    return _this->firstName;
}

char *Student_getLastName(PStudent _this) {
    return _this->lastName;
}

int Student_getId(PStudent _this) {
    return _this->id;
}

void Student_setFirstName(PStudent _this, char *newName) {
    strcpy(_this->firstName, newName);
}

void Student_setLastName(PStudent _this, char *newName) {
    strcpy(_this->lastName, newName);
}

void Student_print(PStudent _this, int showId) {
    if (showId) {
        printf("%d: [%s, %s]", _this->id, _this->lastName, _this->firstName);
    } else {
        printf("[%s, %s]", _this->lastName, _this->firstName);
    }
}

void Student_delete(PStudent _this) {
    free(_this);
}

int Student_cmp(PStudent a, PStudent b) {
    int failed = 0;

    failed += strcmp(a->firstName, b->firstName) != 0;
    failed += strcmp(a->lastName, b->lastName) != 0;
    failed += a->id != b->id;

    return failed;
}