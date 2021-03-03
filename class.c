#include "class.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define STR 60

struct Class {
    char name[60];
    PStudent *list;
    int size;
};

PClass Class_create(char *name) {
    PClass generated = (PClass) malloc(sizeof (struct Class));

    strcpy(generated->name, name);
    generated->size = 0;
    generated->list = NULL;

    return generated;
}

void Class_print(PClass _this, int indent) {
    for (int i = 0; i < indent; i++) printf("\t");
    printf("Class %s (%d students): \n", _this->name, _this->size);

    if (!_this->size) {
        for (int i = 0; i <= indent; i++) printf("\t");
        printf("No students.\n");
    }

    for (int i = 0; i < _this->size; i++) {
        for (int x = 0; x <= indent; x++) printf("\t");
        Student_print(*(_this->list + i), 0);
        printf("\n");
    }
}

void Class_setName (PClass _this, char * newName) {
    strcpy(_this->name, newName);
}

char * Class_getName (PClass _this) {
    return _this->name;
}

int Class_getNumberOfStudents(PClass _this) {
    return _this->size;
}

PStudent Class_getStudent(PClass _this, int index) {
    if (index >= _this->size) index = _this->size - 1;
    return *(_this->list + index);
}

void Class_addStudent(PClass _this, PStudent toAdd) {
    if (_this->size == 0) {
        _this->list = (PStudent *) malloc(sizeof (PStudent));
    } else {
        _this->list = (PStudent *) realloc(_this->list, sizeof (PStudent) * _this->size);
    }
    _this->size += 1;

    *(_this->list + (_this->size - 1)) = toAdd;
}

void Class_deleteStudent(PClass _this, int index) {
    if (_this->size <= 0) return;
    _this->size -= 1;

    if (_this->size == 0) {
        Student_delete(*(_this->list));
        free(_this->list);
        _this->list = NULL;

        return;
    }

    if (index >= _this->size) index = _this->size - 1;
    Student_delete(*(_this->list + index));

    for (int i = index; i < _this->size; i++) {
        _this->list[i] = _this->list[i + 1];
    }
    _this->list = (PStudent *) realloc(_this->list, sizeof(PStudent) * _this->size);
}

void Class_delete(PClass _this) {
    for (int i = 0; i < _this->size; i++) {
        Student_delete(_this->list[i]);
    }

    free(_this);
}