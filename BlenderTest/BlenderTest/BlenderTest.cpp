#include "Python.h"

static PyObject *
ex_foo(PyObject *self, PyObject *args)
{
	printf("Hello, world\n");
	Py_INCREF(Py_None);
	return Py_None;
}

static PyMethodDef BlenderTest_methods[] = {
	{ "foo", ex_foo, METH_VARARGS, "foo() doc string" },
	{ NULL, NULL }
};

static struct PyModuleDef BlenderTestmodule = {
	PyModuleDef_HEAD_INIT,
	"BlenderTest",
	"BlenderTest module doc string",
	-1,
	BlenderTest_methods,
	NULL,
	NULL,
	NULL,
	NULL
};

PyMODINIT_FUNC
PyInit_BlenderTest(void)
{
	return PyModule_Create(&BlenderTestmodule);
}