#pragma once

typedef struct Student *PStudent;

PStudent Student_create(char *first, char *last);
char *Student_getFirstName(PStudent _this);
char *Student_getLastName(PStudent _this);
int Student_getId(PStudent _this);
void Student_setFirstName(PStudent _this, char *newName);
void Student_setLastName(PStudent _this, char *newName);
void Student_print(PStudent _this, int showId);
void Student_delete(PStudent _this);
int Student_cmp(PStudent a, PStudent b);