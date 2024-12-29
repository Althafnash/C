#include <Python.h>
#include <stdio.h>

int main() {
    char filename[] = "C.py";
    FILE* fp;

    Py_Initialize();

    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Could not open file: %s\n", filename);
        Py_Finalize();
        return 1;
    }

    PyRun_SimpleFile(fp, filename);

    fclose(fp);

    Py_Finalize();

    return 0;
}
