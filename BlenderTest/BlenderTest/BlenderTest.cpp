#include "Python.h"

static PyObject *
ex_foo(PyObject *self, PyObject *args)
{
	printf("Hello, world\n");
	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
ex_bar(PyObject *self, PyObject *args)
{
	int x, result;
	if (!PyArg_ParseTuple(args, "i", &x)) {
		return NULL;
	}
	result = x * x;
	return Py_BuildValue("i", result);
}

static PyMethodDef BlenderTest_methods[] = {
	{ "foo", ex_foo, METH_VARARGS, "foo() doc string" },
	{ "bar", ex_bar, METH_VARARGS, "bar(i) doc string" },
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