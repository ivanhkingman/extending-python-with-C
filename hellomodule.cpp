#define PY_SSIZE_T_CLEAN
#include <Python.h>

static PyObject*
say_hello(PyObject* self, PyObject* args)
{
    const char* name;

    if (!PyArg_ParseTuple(args, "s", &name))
        return NULL;

    printf("Hello %s!\n", name);

    Py_RETURN_NONE;
}

static PyObject*
say_goodbye(PyObject* self, PyObject* args)
{
    const char* name;

    if (!PyArg_ParseTuple(args, "s", &name))
        return NULL;
    
    printf("Goodbye %s!\n", name);

    Py_RETURN_NONE;
}

static PyObject*
return_something(PyObject* self, PyObject* args)
{
    int n;

    if (!PyArg_ParseTuple(args, "i", &n))
        return NULL;

    return Py_BuildValue("i", n);
}

static PyObject*
add_two_numbers(PyObject* self, PyObject* args)
{
    int x;
    int y;
    bool parsedCorrectly;

    parsedCorrectly = PyArg_ParseTuple(args, "ii", &x, &y);
    if (!parsedCorrectly)
        return NULL;

    return Py_BuildValue("i", x+y);
}

static PyMethodDef HelloMethods[] =
{
     {"say_hello", say_hello, METH_VARARGS, "Greet somebody."},
     {"say_goodbye", say_goodbye, METH_VARARGS, "Say goodbye to somebody."},
     {"return_something", return_something, METH_VARARGS, "Return a value."},
     {"add_two_numbers", add_two_numbers, METH_VARARGS, "Adds two numbers."},
     {NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC
inithello(void)
{
     (void) Py_InitModule("hello", HelloMethods);
}