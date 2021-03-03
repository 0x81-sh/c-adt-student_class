#pragma once
#include "student.h"

typedef struct Class *PClass;

PClass Class_create(char *name);
void Class_print(PClass _this, int indent);
void Class_setName (PClass _this, char * newName);
char * Class_getName (PClass _this);
int Class_getNumberOfStudents(PClass _this);
PStudent Class_getStudent(PClass _this, int index);
void Class_addStudent(PClass _this, PStudent toAdd);
void Class_deleteStudent(PClass _this, int index);
void Class_delete(PClass _this);
