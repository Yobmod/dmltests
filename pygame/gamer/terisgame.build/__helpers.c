// This file contains helper functions that are automatically created from
// templates.

#include "nuitka/prelude.h"

extern PyObject *callPythonFunction( PyObject *func, PyObject **args, int count );


PyObject *CALL_FUNCTION_WITH_ARGS1( PyObject *called, PyObject **args )
{
    CHECK_OBJECT( called );

    // Check if arguments are valid objects in debug mode.
#ifndef __NUITKA_NO_ASSERT__
    for( size_t i = 0; i < 1; i++ )
    {
        CHECK_OBJECT( args[ i ] );
    }
#endif

    if ( Nuitka_Function_Check( called ) )
    {
        if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
        {
            return NULL;
        }

        struct Nuitka_FunctionObject *function = (struct Nuitka_FunctionObject *)called;
        PyObject *result;

        if ( function->m_args_simple && 1 == function->m_args_positional_count )
        {
            for( Py_ssize_t i = 0; i < 1; i++ )
            {
                Py_INCREF( args[ i ] );
            }

            result = function->m_c_code( function, args );
        }
        else if ( function->m_args_simple && 1 + function->m_defaults_given == function->m_args_positional_count )
        {
#ifdef _MSC_VER
            PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_positional_count );
#else
            PyObject *python_pars[ function->m_args_positional_count ];
#endif
            memcpy( python_pars, args, 1 * sizeof(PyObject *) );
            memcpy( python_pars + 1, &PyTuple_GET_ITEM( function->m_defaults, 0 ), function->m_defaults_given * sizeof(PyObject *) );

            for( Py_ssize_t i = 0; i < function->m_args_positional_count; i++ )
            {
                Py_INCREF( python_pars[ i ] );
            }

            result = function->m_c_code( function, python_pars );
        }
        else
        {
#ifdef _MSC_VER
            PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_overall_count );
#else
            PyObject *python_pars[ function->m_args_overall_count ];
#endif
            memset( python_pars, 0, function->m_args_overall_count * sizeof(PyObject *) );

            if ( parseArgumentsPos( function, python_pars, args, 1 ))
            {
                result = function->m_c_code( function, python_pars );
            }
            else
            {
                result = NULL;
            }
        }

        Py_LeaveRecursiveCall();

        return result;
    }
    else if ( Nuitka_Method_Check( called ) )
    {
        struct Nuitka_MethodObject *method = (struct Nuitka_MethodObject *)called;

        // Unbound method without arguments, let the error path be slow.
        if ( method->m_object != NULL )
        {
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }

            struct Nuitka_FunctionObject *function = method->m_function;

            PyObject *result;

            if ( function->m_args_simple && 1 + 1 == function->m_args_positional_count )
            {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_positional_count );
#else
                PyObject *python_pars[ function->m_args_positional_count ];
#endif
                python_pars[ 0 ] = method->m_object;
                Py_INCREF( method->m_object );

                for( Py_ssize_t i = 0; i < 1; i++ )
                {
                    python_pars[ i + 1 ] = args[ i ];
                    Py_INCREF( args[ i ] );
                }

                result = function->m_c_code( function, python_pars );
            }
            else if ( function->m_args_simple && 1 + 1 + function->m_defaults_given == function->m_args_positional_count )
            {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_positional_count );
#else
                PyObject *python_pars[ function->m_args_positional_count ];
#endif
                python_pars[ 0 ] = method->m_object;
                Py_INCREF( method->m_object );

                memcpy( python_pars+1, args, 1 * sizeof(PyObject *) );
                memcpy( python_pars+1 + 1, &PyTuple_GET_ITEM( function->m_defaults, 0 ), function->m_defaults_given * sizeof(PyObject *) );

                for( Py_ssize_t i = 1; i < function->m_args_overall_count; i++ )
                {
                    Py_INCREF( python_pars[ i ] );
                }

                result = function->m_c_code( function, python_pars );
            }
            else
            {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_overall_count );
#else
                PyObject *python_pars[ function->m_args_overall_count ];
#endif
                memset( python_pars, 0, function->m_args_overall_count * sizeof(PyObject *) );

                if ( parseArgumentsMethodPos( function, python_pars, method->m_object, args, 1 ) )
                {
                    result = function->m_c_code( function, python_pars );
                }
                else
                {
                    result = NULL;
                }
            }

            Py_LeaveRecursiveCall();

            return result;
        }
    }
    else if ( PyCFunction_Check( called ) )
    {
        // Try to be fast about wrapping the arguments.
        int flags = PyCFunction_GET_FLAGS( called ) & ~(METH_CLASS | METH_STATIC | METH_COEXIST);

        if ( flags & METH_NOARGS )
        {
#if 1 == 0
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

            PyObject *result = (*method)( self, NULL );

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if ( result != NULL )
            {
            // Some buggy C functions do set an error, but do not indicate it
            // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                return result;
            }
            else
            {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely( !ERROR_OCCURRED() ))
                {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                return NULL;
            }
#else
            PyErr_Format(
                PyExc_TypeError,
                "%s() takes no arguments (1 given)",
                ((PyCFunctionObject *)called)->m_ml->ml_name
            );
            return NULL;
#endif
        }
        else if ( flags & METH_O )
        {
#if 1 == 1
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

            PyObject *result = (*method)( self, args[0] );

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if ( result != NULL )
            {
            // Some buggy C functions do set an error, but do not indicate it
            // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                return result;
            }
            else
            {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely( !ERROR_OCCURRED() ))
                {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                return NULL;
            }
#else
            PyErr_Format(PyExc_TypeError,
                "%s() takes exactly one argument (1 given)",
                 ((PyCFunctionObject *)called)->m_ml->ml_name
            );
            return NULL;
#endif
        }
        else if ( flags & METH_VARARGS )
        {
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            PyObject *pos_args = MAKE_TUPLE( args, 1 );

            PyObject *result;

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

#if PYTHON_VERSION < 360
            if ( flags & METH_KEYWORDS )
            {
                result = (*(PyCFunctionWithKeywords)method)( self, pos_args, NULL );
            }
            else
            {
                result = (*method)( self, pos_args );
            }
#else
            if ( flags == ( METH_VARARGS | METH_KEYWORDS ) )
            {
                result = (*(PyCFunctionWithKeywords)method)( self, pos_args, NULL );
            }
            else if ( flags == METH_FASTCALL )
            {
#if PYTHON_VERSION < 370
                result = (*(_PyCFunctionFast)method)( self, &PyTuple_GET_ITEM( pos_args, 0 ), 1, NULL );;
#else
                result = (*(_PyCFunctionFast)method)( self, &pos_args, 1 );;
#endif
            }
            else
            {
                result = (*method)( self, pos_args );
            }
#endif

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if ( result != NULL )
            {
                // Some buggy C functions do set an error, but do not indicate it
                // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                Py_DECREF( pos_args );
                return result;
            }
            else
            {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely( !ERROR_OCCURRED() ))
                {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                Py_DECREF( pos_args );
                return NULL;
            }
        }
    }
    else if ( PyFunction_Check( called ) )
    {
        return callPythonFunction(
            called,
            args,
            1
        );
    }

    PyObject *pos_args = MAKE_TUPLE( args, 1 );

    PyObject *result = CALL_FUNCTION(
        called,
        pos_args,
        NULL
    );

    Py_DECREF( pos_args );

    return result;
}

PyObject *CALL_FUNCTION_WITH_ARGS2( PyObject *called, PyObject **args )
{
    CHECK_OBJECT( called );

    // Check if arguments are valid objects in debug mode.
#ifndef __NUITKA_NO_ASSERT__
    for( size_t i = 0; i < 2; i++ )
    {
        CHECK_OBJECT( args[ i ] );
    }
#endif

    if ( Nuitka_Function_Check( called ) )
    {
        if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
        {
            return NULL;
        }

        struct Nuitka_FunctionObject *function = (struct Nuitka_FunctionObject *)called;
        PyObject *result;

        if ( function->m_args_simple && 2 == function->m_args_positional_count )
        {
            for( Py_ssize_t i = 0; i < 2; i++ )
            {
                Py_INCREF( args[ i ] );
            }

            result = function->m_c_code( function, args );
        }
        else if ( function->m_args_simple && 2 + function->m_defaults_given == function->m_args_positional_count )
        {
#ifdef _MSC_VER
            PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_positional_count );
#else
            PyObject *python_pars[ function->m_args_positional_count ];
#endif
            memcpy( python_pars, args, 2 * sizeof(PyObject *) );
            memcpy( python_pars + 2, &PyTuple_GET_ITEM( function->m_defaults, 0 ), function->m_defaults_given * sizeof(PyObject *) );

            for( Py_ssize_t i = 0; i < function->m_args_positional_count; i++ )
            {
                Py_INCREF( python_pars[ i ] );
            }

            result = function->m_c_code( function, python_pars );
        }
        else
        {
#ifdef _MSC_VER
            PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_overall_count );
#else
            PyObject *python_pars[ function->m_args_overall_count ];
#endif
            memset( python_pars, 0, function->m_args_overall_count * sizeof(PyObject *) );

            if ( parseArgumentsPos( function, python_pars, args, 2 ))
            {
                result = function->m_c_code( function, python_pars );
            }
            else
            {
                result = NULL;
            }
        }

        Py_LeaveRecursiveCall();

        return result;
    }
    else if ( Nuitka_Method_Check( called ) )
    {
        struct Nuitka_MethodObject *method = (struct Nuitka_MethodObject *)called;

        // Unbound method without arguments, let the error path be slow.
        if ( method->m_object != NULL )
        {
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }

            struct Nuitka_FunctionObject *function = method->m_function;

            PyObject *result;

            if ( function->m_args_simple && 2 + 1 == function->m_args_positional_count )
            {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_positional_count );
#else
                PyObject *python_pars[ function->m_args_positional_count ];
#endif
                python_pars[ 0 ] = method->m_object;
                Py_INCREF( method->m_object );

                for( Py_ssize_t i = 0; i < 2; i++ )
                {
                    python_pars[ i + 1 ] = args[ i ];
                    Py_INCREF( args[ i ] );
                }

                result = function->m_c_code( function, python_pars );
            }
            else if ( function->m_args_simple && 2 + 1 + function->m_defaults_given == function->m_args_positional_count )
            {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_positional_count );
#else
                PyObject *python_pars[ function->m_args_positional_count ];
#endif
                python_pars[ 0 ] = method->m_object;
                Py_INCREF( method->m_object );

                memcpy( python_pars+1, args, 2 * sizeof(PyObject *) );
                memcpy( python_pars+1 + 2, &PyTuple_GET_ITEM( function->m_defaults, 0 ), function->m_defaults_given * sizeof(PyObject *) );

                for( Py_ssize_t i = 1; i < function->m_args_overall_count; i++ )
                {
                    Py_INCREF( python_pars[ i ] );
                }

                result = function->m_c_code( function, python_pars );
            }
            else
            {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_overall_count );
#else
                PyObject *python_pars[ function->m_args_overall_count ];
#endif
                memset( python_pars, 0, function->m_args_overall_count * sizeof(PyObject *) );

                if ( parseArgumentsMethodPos( function, python_pars, method->m_object, args, 2 ) )
                {
                    result = function->m_c_code( function, python_pars );
                }
                else
                {
                    result = NULL;
                }
            }

            Py_LeaveRecursiveCall();

            return result;
        }
    }
    else if ( PyCFunction_Check( called ) )
    {
        // Try to be fast about wrapping the arguments.
        int flags = PyCFunction_GET_FLAGS( called ) & ~(METH_CLASS | METH_STATIC | METH_COEXIST);

        if ( flags & METH_NOARGS )
        {
#if 2 == 0
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

            PyObject *result = (*method)( self, NULL );

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if ( result != NULL )
            {
            // Some buggy C functions do set an error, but do not indicate it
            // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                return result;
            }
            else
            {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely( !ERROR_OCCURRED() ))
                {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                return NULL;
            }
#else
            PyErr_Format(
                PyExc_TypeError,
                "%s() takes no arguments (2 given)",
                ((PyCFunctionObject *)called)->m_ml->ml_name
            );
            return NULL;
#endif
        }
        else if ( flags & METH_O )
        {
#if 2 == 1
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

            PyObject *result = (*method)( self, args[0] );

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if ( result != NULL )
            {
            // Some buggy C functions do set an error, but do not indicate it
            // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                return result;
            }
            else
            {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely( !ERROR_OCCURRED() ))
                {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                return NULL;
            }
#else
            PyErr_Format(PyExc_TypeError,
                "%s() takes exactly one argument (2 given)",
                 ((PyCFunctionObject *)called)->m_ml->ml_name
            );
            return NULL;
#endif
        }
        else if ( flags & METH_VARARGS )
        {
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            PyObject *pos_args = MAKE_TUPLE( args, 2 );

            PyObject *result;

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

#if PYTHON_VERSION < 360
            if ( flags & METH_KEYWORDS )
            {
                result = (*(PyCFunctionWithKeywords)method)( self, pos_args, NULL );
            }
            else
            {
                result = (*method)( self, pos_args );
            }
#else
            if ( flags == ( METH_VARARGS | METH_KEYWORDS ) )
            {
                result = (*(PyCFunctionWithKeywords)method)( self, pos_args, NULL );
            }
            else if ( flags == METH_FASTCALL )
            {
#if PYTHON_VERSION < 370
                result = (*(_PyCFunctionFast)method)( self, &PyTuple_GET_ITEM( pos_args, 0 ), 2, NULL );;
#else
                result = (*(_PyCFunctionFast)method)( self, &pos_args, 2 );;
#endif
            }
            else
            {
                result = (*method)( self, pos_args );
            }
#endif

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if ( result != NULL )
            {
                // Some buggy C functions do set an error, but do not indicate it
                // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                Py_DECREF( pos_args );
                return result;
            }
            else
            {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely( !ERROR_OCCURRED() ))
                {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                Py_DECREF( pos_args );
                return NULL;
            }
        }
    }
    else if ( PyFunction_Check( called ) )
    {
        return callPythonFunction(
            called,
            args,
            2
        );
    }

    PyObject *pos_args = MAKE_TUPLE( args, 2 );

    PyObject *result = CALL_FUNCTION(
        called,
        pos_args,
        NULL
    );

    Py_DECREF( pos_args );

    return result;
}

PyObject *CALL_FUNCTION_WITH_ARGS3( PyObject *called, PyObject **args )
{
    CHECK_OBJECT( called );

    // Check if arguments are valid objects in debug mode.
#ifndef __NUITKA_NO_ASSERT__
    for( size_t i = 0; i < 3; i++ )
    {
        CHECK_OBJECT( args[ i ] );
    }
#endif

    if ( Nuitka_Function_Check( called ) )
    {
        if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
        {
            return NULL;
        }

        struct Nuitka_FunctionObject *function = (struct Nuitka_FunctionObject *)called;
        PyObject *result;

        if ( function->m_args_simple && 3 == function->m_args_positional_count )
        {
            for( Py_ssize_t i = 0; i < 3; i++ )
            {
                Py_INCREF( args[ i ] );
            }

            result = function->m_c_code( function, args );
        }
        else if ( function->m_args_simple && 3 + function->m_defaults_given == function->m_args_positional_count )
        {
#ifdef _MSC_VER
            PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_positional_count );
#else
            PyObject *python_pars[ function->m_args_positional_count ];
#endif
            memcpy( python_pars, args, 3 * sizeof(PyObject *) );
            memcpy( python_pars + 3, &PyTuple_GET_ITEM( function->m_defaults, 0 ), function->m_defaults_given * sizeof(PyObject *) );

            for( Py_ssize_t i = 0; i < function->m_args_positional_count; i++ )
            {
                Py_INCREF( python_pars[ i ] );
            }

            result = function->m_c_code( function, python_pars );
        }
        else
        {
#ifdef _MSC_VER
            PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_overall_count );
#else
            PyObject *python_pars[ function->m_args_overall_count ];
#endif
            memset( python_pars, 0, function->m_args_overall_count * sizeof(PyObject *) );

            if ( parseArgumentsPos( function, python_pars, args, 3 ))
            {
                result = function->m_c_code( function, python_pars );
            }
            else
            {
                result = NULL;
            }
        }

        Py_LeaveRecursiveCall();

        return result;
    }
    else if ( Nuitka_Method_Check( called ) )
    {
        struct Nuitka_MethodObject *method = (struct Nuitka_MethodObject *)called;

        // Unbound method without arguments, let the error path be slow.
        if ( method->m_object != NULL )
        {
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }

            struct Nuitka_FunctionObject *function = method->m_function;

            PyObject *result;

            if ( function->m_args_simple && 3 + 1 == function->m_args_positional_count )
            {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_positional_count );
#else
                PyObject *python_pars[ function->m_args_positional_count ];
#endif
                python_pars[ 0 ] = method->m_object;
                Py_INCREF( method->m_object );

                for( Py_ssize_t i = 0; i < 3; i++ )
                {
                    python_pars[ i + 1 ] = args[ i ];
                    Py_INCREF( args[ i ] );
                }

                result = function->m_c_code( function, python_pars );
            }
            else if ( function->m_args_simple && 3 + 1 + function->m_defaults_given == function->m_args_positional_count )
            {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_positional_count );
#else
                PyObject *python_pars[ function->m_args_positional_count ];
#endif
                python_pars[ 0 ] = method->m_object;
                Py_INCREF( method->m_object );

                memcpy( python_pars+1, args, 3 * sizeof(PyObject *) );
                memcpy( python_pars+1 + 3, &PyTuple_GET_ITEM( function->m_defaults, 0 ), function->m_defaults_given * sizeof(PyObject *) );

                for( Py_ssize_t i = 1; i < function->m_args_overall_count; i++ )
                {
                    Py_INCREF( python_pars[ i ] );
                }

                result = function->m_c_code( function, python_pars );
            }
            else
            {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_overall_count );
#else
                PyObject *python_pars[ function->m_args_overall_count ];
#endif
                memset( python_pars, 0, function->m_args_overall_count * sizeof(PyObject *) );

                if ( parseArgumentsMethodPos( function, python_pars, method->m_object, args, 3 ) )
                {
                    result = function->m_c_code( function, python_pars );
                }
                else
                {
                    result = NULL;
                }
            }

            Py_LeaveRecursiveCall();

            return result;
        }
    }
    else if ( PyCFunction_Check( called ) )
    {
        // Try to be fast about wrapping the arguments.
        int flags = PyCFunction_GET_FLAGS( called ) & ~(METH_CLASS | METH_STATIC | METH_COEXIST);

        if ( flags & METH_NOARGS )
        {
#if 3 == 0
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

            PyObject *result = (*method)( self, NULL );

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if ( result != NULL )
            {
            // Some buggy C functions do set an error, but do not indicate it
            // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                return result;
            }
            else
            {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely( !ERROR_OCCURRED() ))
                {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                return NULL;
            }
#else
            PyErr_Format(
                PyExc_TypeError,
                "%s() takes no arguments (3 given)",
                ((PyCFunctionObject *)called)->m_ml->ml_name
            );
            return NULL;
#endif
        }
        else if ( flags & METH_O )
        {
#if 3 == 1
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

            PyObject *result = (*method)( self, args[0] );

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if ( result != NULL )
            {
            // Some buggy C functions do set an error, but do not indicate it
            // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                return result;
            }
            else
            {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely( !ERROR_OCCURRED() ))
                {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                return NULL;
            }
#else
            PyErr_Format(PyExc_TypeError,
                "%s() takes exactly one argument (3 given)",
                 ((PyCFunctionObject *)called)->m_ml->ml_name
            );
            return NULL;
#endif
        }
        else if ( flags & METH_VARARGS )
        {
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            PyObject *pos_args = MAKE_TUPLE( args, 3 );

            PyObject *result;

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

#if PYTHON_VERSION < 360
            if ( flags & METH_KEYWORDS )
            {
                result = (*(PyCFunctionWithKeywords)method)( self, pos_args, NULL );
            }
            else
            {
                result = (*method)( self, pos_args );
            }
#else
            if ( flags == ( METH_VARARGS | METH_KEYWORDS ) )
            {
                result = (*(PyCFunctionWithKeywords)method)( self, pos_args, NULL );
            }
            else if ( flags == METH_FASTCALL )
            {
#if PYTHON_VERSION < 370
                result = (*(_PyCFunctionFast)method)( self, &PyTuple_GET_ITEM( pos_args, 0 ), 3, NULL );;
#else
                result = (*(_PyCFunctionFast)method)( self, &pos_args, 3 );;
#endif
            }
            else
            {
                result = (*method)( self, pos_args );
            }
#endif

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if ( result != NULL )
            {
                // Some buggy C functions do set an error, but do not indicate it
                // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                Py_DECREF( pos_args );
                return result;
            }
            else
            {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely( !ERROR_OCCURRED() ))
                {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                Py_DECREF( pos_args );
                return NULL;
            }
        }
    }
    else if ( PyFunction_Check( called ) )
    {
        return callPythonFunction(
            called,
            args,
            3
        );
    }

    PyObject *pos_args = MAKE_TUPLE( args, 3 );

    PyObject *result = CALL_FUNCTION(
        called,
        pos_args,
        NULL
    );

    Py_DECREF( pos_args );

    return result;
}

PyObject *CALL_FUNCTION_WITH_ARGS4( PyObject *called, PyObject **args )
{
    CHECK_OBJECT( called );

    // Check if arguments are valid objects in debug mode.
#ifndef __NUITKA_NO_ASSERT__
    for( size_t i = 0; i < 4; i++ )
    {
        CHECK_OBJECT( args[ i ] );
    }
#endif

    if ( Nuitka_Function_Check( called ) )
    {
        if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
        {
            return NULL;
        }

        struct Nuitka_FunctionObject *function = (struct Nuitka_FunctionObject *)called;
        PyObject *result;

        if ( function->m_args_simple && 4 == function->m_args_positional_count )
        {
            for( Py_ssize_t i = 0; i < 4; i++ )
            {
                Py_INCREF( args[ i ] );
            }

            result = function->m_c_code( function, args );
        }
        else if ( function->m_args_simple && 4 + function->m_defaults_given == function->m_args_positional_count )
        {
#ifdef _MSC_VER
            PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_positional_count );
#else
            PyObject *python_pars[ function->m_args_positional_count ];
#endif
            memcpy( python_pars, args, 4 * sizeof(PyObject *) );
            memcpy( python_pars + 4, &PyTuple_GET_ITEM( function->m_defaults, 0 ), function->m_defaults_given * sizeof(PyObject *) );

            for( Py_ssize_t i = 0; i < function->m_args_positional_count; i++ )
            {
                Py_INCREF( python_pars[ i ] );
            }

            result = function->m_c_code( function, python_pars );
        }
        else
        {
#ifdef _MSC_VER
            PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_overall_count );
#else
            PyObject *python_pars[ function->m_args_overall_count ];
#endif
            memset( python_pars, 0, function->m_args_overall_count * sizeof(PyObject *) );

            if ( parseArgumentsPos( function, python_pars, args, 4 ))
            {
                result = function->m_c_code( function, python_pars );
            }
            else
            {
                result = NULL;
            }
        }

        Py_LeaveRecursiveCall();

        return result;
    }
    else if ( Nuitka_Method_Check( called ) )
    {
        struct Nuitka_MethodObject *method = (struct Nuitka_MethodObject *)called;

        // Unbound method without arguments, let the error path be slow.
        if ( method->m_object != NULL )
        {
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }

            struct Nuitka_FunctionObject *function = method->m_function;

            PyObject *result;

            if ( function->m_args_simple && 4 + 1 == function->m_args_positional_count )
            {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_positional_count );
#else
                PyObject *python_pars[ function->m_args_positional_count ];
#endif
                python_pars[ 0 ] = method->m_object;
                Py_INCREF( method->m_object );

                for( Py_ssize_t i = 0; i < 4; i++ )
                {
                    python_pars[ i + 1 ] = args[ i ];
                    Py_INCREF( args[ i ] );
                }

                result = function->m_c_code( function, python_pars );
            }
            else if ( function->m_args_simple && 4 + 1 + function->m_defaults_given == function->m_args_positional_count )
            {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_positional_count );
#else
                PyObject *python_pars[ function->m_args_positional_count ];
#endif
                python_pars[ 0 ] = method->m_object;
                Py_INCREF( method->m_object );

                memcpy( python_pars+1, args, 4 * sizeof(PyObject *) );
                memcpy( python_pars+1 + 4, &PyTuple_GET_ITEM( function->m_defaults, 0 ), function->m_defaults_given * sizeof(PyObject *) );

                for( Py_ssize_t i = 1; i < function->m_args_overall_count; i++ )
                {
                    Py_INCREF( python_pars[ i ] );
                }

                result = function->m_c_code( function, python_pars );
            }
            else
            {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_overall_count );
#else
                PyObject *python_pars[ function->m_args_overall_count ];
#endif
                memset( python_pars, 0, function->m_args_overall_count * sizeof(PyObject *) );

                if ( parseArgumentsMethodPos( function, python_pars, method->m_object, args, 4 ) )
                {
                    result = function->m_c_code( function, python_pars );
                }
                else
                {
                    result = NULL;
                }
            }

            Py_LeaveRecursiveCall();

            return result;
        }
    }
    else if ( PyCFunction_Check( called ) )
    {
        // Try to be fast about wrapping the arguments.
        int flags = PyCFunction_GET_FLAGS( called ) & ~(METH_CLASS | METH_STATIC | METH_COEXIST);

        if ( flags & METH_NOARGS )
        {
#if 4 == 0
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

            PyObject *result = (*method)( self, NULL );

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if ( result != NULL )
            {
            // Some buggy C functions do set an error, but do not indicate it
            // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                return result;
            }
            else
            {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely( !ERROR_OCCURRED() ))
                {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                return NULL;
            }
#else
            PyErr_Format(
                PyExc_TypeError,
                "%s() takes no arguments (4 given)",
                ((PyCFunctionObject *)called)->m_ml->ml_name
            );
            return NULL;
#endif
        }
        else if ( flags & METH_O )
        {
#if 4 == 1
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

            PyObject *result = (*method)( self, args[0] );

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if ( result != NULL )
            {
            // Some buggy C functions do set an error, but do not indicate it
            // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                return result;
            }
            else
            {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely( !ERROR_OCCURRED() ))
                {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                return NULL;
            }
#else
            PyErr_Format(PyExc_TypeError,
                "%s() takes exactly one argument (4 given)",
                 ((PyCFunctionObject *)called)->m_ml->ml_name
            );
            return NULL;
#endif
        }
        else if ( flags & METH_VARARGS )
        {
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            PyObject *pos_args = MAKE_TUPLE( args, 4 );

            PyObject *result;

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

#if PYTHON_VERSION < 360
            if ( flags & METH_KEYWORDS )
            {
                result = (*(PyCFunctionWithKeywords)method)( self, pos_args, NULL );
            }
            else
            {
                result = (*method)( self, pos_args );
            }
#else
            if ( flags == ( METH_VARARGS | METH_KEYWORDS ) )
            {
                result = (*(PyCFunctionWithKeywords)method)( self, pos_args, NULL );
            }
            else if ( flags == METH_FASTCALL )
            {
#if PYTHON_VERSION < 370
                result = (*(_PyCFunctionFast)method)( self, &PyTuple_GET_ITEM( pos_args, 0 ), 4, NULL );;
#else
                result = (*(_PyCFunctionFast)method)( self, &pos_args, 4 );;
#endif
            }
            else
            {
                result = (*method)( self, pos_args );
            }
#endif

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if ( result != NULL )
            {
                // Some buggy C functions do set an error, but do not indicate it
                // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                Py_DECREF( pos_args );
                return result;
            }
            else
            {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely( !ERROR_OCCURRED() ))
                {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                Py_DECREF( pos_args );
                return NULL;
            }
        }
    }
    else if ( PyFunction_Check( called ) )
    {
        return callPythonFunction(
            called,
            args,
            4
        );
    }

    PyObject *pos_args = MAKE_TUPLE( args, 4 );

    PyObject *result = CALL_FUNCTION(
        called,
        pos_args,
        NULL
    );

    Py_DECREF( pos_args );

    return result;
}

PyObject *CALL_FUNCTION_WITH_ARGS5( PyObject *called, PyObject **args )
{
    CHECK_OBJECT( called );

    // Check if arguments are valid objects in debug mode.
#ifndef __NUITKA_NO_ASSERT__
    for( size_t i = 0; i < 5; i++ )
    {
        CHECK_OBJECT( args[ i ] );
    }
#endif

    if ( Nuitka_Function_Check( called ) )
    {
        if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
        {
            return NULL;
        }

        struct Nuitka_FunctionObject *function = (struct Nuitka_FunctionObject *)called;
        PyObject *result;

        if ( function->m_args_simple && 5 == function->m_args_positional_count )
        {
            for( Py_ssize_t i = 0; i < 5; i++ )
            {
                Py_INCREF( args[ i ] );
            }

            result = function->m_c_code( function, args );
        }
        else if ( function->m_args_simple && 5 + function->m_defaults_given == function->m_args_positional_count )
        {
#ifdef _MSC_VER
            PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_positional_count );
#else
            PyObject *python_pars[ function->m_args_positional_count ];
#endif
            memcpy( python_pars, args, 5 * sizeof(PyObject *) );
            memcpy( python_pars + 5, &PyTuple_GET_ITEM( function->m_defaults, 0 ), function->m_defaults_given * sizeof(PyObject *) );

            for( Py_ssize_t i = 0; i < function->m_args_positional_count; i++ )
            {
                Py_INCREF( python_pars[ i ] );
            }

            result = function->m_c_code( function, python_pars );
        }
        else
        {
#ifdef _MSC_VER
            PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_overall_count );
#else
            PyObject *python_pars[ function->m_args_overall_count ];
#endif
            memset( python_pars, 0, function->m_args_overall_count * sizeof(PyObject *) );

            if ( parseArgumentsPos( function, python_pars, args, 5 ))
            {
                result = function->m_c_code( function, python_pars );
            }
            else
            {
                result = NULL;
            }
        }

        Py_LeaveRecursiveCall();

        return result;
    }
    else if ( Nuitka_Method_Check( called ) )
    {
        struct Nuitka_MethodObject *method = (struct Nuitka_MethodObject *)called;

        // Unbound method without arguments, let the error path be slow.
        if ( method->m_object != NULL )
        {
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }

            struct Nuitka_FunctionObject *function = method->m_function;

            PyObject *result;

            if ( function->m_args_simple && 5 + 1 == function->m_args_positional_count )
            {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_positional_count );
#else
                PyObject *python_pars[ function->m_args_positional_count ];
#endif
                python_pars[ 0 ] = method->m_object;
                Py_INCREF( method->m_object );

                for( Py_ssize_t i = 0; i < 5; i++ )
                {
                    python_pars[ i + 1 ] = args[ i ];
                    Py_INCREF( args[ i ] );
                }

                result = function->m_c_code( function, python_pars );
            }
            else if ( function->m_args_simple && 5 + 1 + function->m_defaults_given == function->m_args_positional_count )
            {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_positional_count );
#else
                PyObject *python_pars[ function->m_args_positional_count ];
#endif
                python_pars[ 0 ] = method->m_object;
                Py_INCREF( method->m_object );

                memcpy( python_pars+1, args, 5 * sizeof(PyObject *) );
                memcpy( python_pars+1 + 5, &PyTuple_GET_ITEM( function->m_defaults, 0 ), function->m_defaults_given * sizeof(PyObject *) );

                for( Py_ssize_t i = 1; i < function->m_args_overall_count; i++ )
                {
                    Py_INCREF( python_pars[ i ] );
                }

                result = function->m_c_code( function, python_pars );
            }
            else
            {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_overall_count );
#else
                PyObject *python_pars[ function->m_args_overall_count ];
#endif
                memset( python_pars, 0, function->m_args_overall_count * sizeof(PyObject *) );

                if ( parseArgumentsMethodPos( function, python_pars, method->m_object, args, 5 ) )
                {
                    result = function->m_c_code( function, python_pars );
                }
                else
                {
                    result = NULL;
                }
            }

            Py_LeaveRecursiveCall();

            return result;
        }
    }
    else if ( PyCFunction_Check( called ) )
    {
        // Try to be fast about wrapping the arguments.
        int flags = PyCFunction_GET_FLAGS( called ) & ~(METH_CLASS | METH_STATIC | METH_COEXIST);

        if ( flags & METH_NOARGS )
        {
#if 5 == 0
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

            PyObject *result = (*method)( self, NULL );

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if ( result != NULL )
            {
            // Some buggy C functions do set an error, but do not indicate it
            // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                return result;
            }
            else
            {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely( !ERROR_OCCURRED() ))
                {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                return NULL;
            }
#else
            PyErr_Format(
                PyExc_TypeError,
                "%s() takes no arguments (5 given)",
                ((PyCFunctionObject *)called)->m_ml->ml_name
            );
            return NULL;
#endif
        }
        else if ( flags & METH_O )
        {
#if 5 == 1
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

            PyObject *result = (*method)( self, args[0] );

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if ( result != NULL )
            {
            // Some buggy C functions do set an error, but do not indicate it
            // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                return result;
            }
            else
            {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely( !ERROR_OCCURRED() ))
                {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                return NULL;
            }
#else
            PyErr_Format(PyExc_TypeError,
                "%s() takes exactly one argument (5 given)",
                 ((PyCFunctionObject *)called)->m_ml->ml_name
            );
            return NULL;
#endif
        }
        else if ( flags & METH_VARARGS )
        {
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            PyObject *pos_args = MAKE_TUPLE( args, 5 );

            PyObject *result;

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

#if PYTHON_VERSION < 360
            if ( flags & METH_KEYWORDS )
            {
                result = (*(PyCFunctionWithKeywords)method)( self, pos_args, NULL );
            }
            else
            {
                result = (*method)( self, pos_args );
            }
#else
            if ( flags == ( METH_VARARGS | METH_KEYWORDS ) )
            {
                result = (*(PyCFunctionWithKeywords)method)( self, pos_args, NULL );
            }
            else if ( flags == METH_FASTCALL )
            {
#if PYTHON_VERSION < 370
                result = (*(_PyCFunctionFast)method)( self, &PyTuple_GET_ITEM( pos_args, 0 ), 5, NULL );;
#else
                result = (*(_PyCFunctionFast)method)( self, &pos_args, 5 );;
#endif
            }
            else
            {
                result = (*method)( self, pos_args );
            }
#endif

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if ( result != NULL )
            {
                // Some buggy C functions do set an error, but do not indicate it
                // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                Py_DECREF( pos_args );
                return result;
            }
            else
            {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely( !ERROR_OCCURRED() ))
                {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                Py_DECREF( pos_args );
                return NULL;
            }
        }
    }
    else if ( PyFunction_Check( called ) )
    {
        return callPythonFunction(
            called,
            args,
            5
        );
    }

    PyObject *pos_args = MAKE_TUPLE( args, 5 );

    PyObject *result = CALL_FUNCTION(
        called,
        pos_args,
        NULL
    );

    Py_DECREF( pos_args );

    return result;
}

PyObject *CALL_METHOD_WITH_ARGS1( PyObject *source, PyObject *attr_name, PyObject **args )
{
    CHECK_OBJECT( source );
    CHECK_OBJECT( attr_name );

    // Check if arguments are valid objects in debug mode.
#ifndef __NUITKA_NO_ASSERT__
    for( size_t i = 0; i < 1; i++ )
    {
        CHECK_OBJECT( args[ i ] );
    }
#endif

    PyTypeObject *type = Py_TYPE( source );

    if ( type->tp_getattro == PyObject_GenericGetAttr )
    {
        // Unfortunately this is required, although of cause rarely necessary.
        if (unlikely( type->tp_dict == NULL ))
        {
            if (unlikely( PyType_Ready( type ) < 0 ))
            {
                return NULL;
            }
        }

        PyObject *descr = _PyType_Lookup( type, attr_name );
        descrgetfunc func = NULL;

        if ( descr != NULL )
        {
            Py_INCREF( descr );

#if PYTHON_VERSION < 300
            if ( PyType_HasFeature( Py_TYPE( descr ), Py_TPFLAGS_HAVE_CLASS ) )
            {
#endif
                func = Py_TYPE( descr )->tp_descr_get;

                if ( func != NULL && PyDescr_IsData( descr ) )
                {
                    PyObject *called_object = func( descr, source, (PyObject *)type );
                    Py_DECREF( descr );

                    PyObject *result = CALL_FUNCTION_WITH_ARGS1(
                        called_object,
                        args
                    );
                    Py_DECREF( called_object );
                    return result;
                }
#if PYTHON_VERSION < 300
            }
#endif
        }

        Py_ssize_t dictoffset = type->tp_dictoffset;
        PyObject *dict = NULL;

        if ( dictoffset != 0 )
        {
            // Negative dictionary offsets have special meaning.
            if ( dictoffset < 0 )
            {
                Py_ssize_t tsize;
                size_t size;

                tsize = ((PyVarObject *)source)->ob_size;
                if (tsize < 0)
                    tsize = -tsize;
                size = _PyObject_VAR_SIZE( type, tsize );

                dictoffset += (long)size;
            }

            PyObject **dictptr = (PyObject **) ((char *)source + dictoffset);
            dict = *dictptr;
        }

        if ( dict != NULL )
        {
            CHECK_OBJECT( dict );

            Py_INCREF( dict );

            PyObject *called_object = PyDict_GetItem( dict, attr_name );

            if ( called_object != NULL )
            {
                Py_INCREF( called_object );
                Py_XDECREF( descr );
                Py_DECREF( dict );

                PyObject *result = CALL_FUNCTION_WITH_ARGS1(
                    called_object,
                    args
                );
                Py_DECREF( called_object );
                return result;
            }

            Py_DECREF( dict );
        }

        if ( func != NULL )
        {
            if ( func == Nuitka_Function_Type.tp_descr_get )
            {
                PyObject *result = Nuitka_CallMethodFunctionPosArgs(
                    (struct Nuitka_FunctionObject const *)descr,
                    source,
                    args,
                    1
                );

                Py_DECREF( descr );

                return result;
            }
            else
            {
                PyObject *called_object = func( descr, source, (PyObject *)type );
                CHECK_OBJECT( called_object );

                Py_DECREF( descr );

                PyObject *result = CALL_FUNCTION_WITH_ARGS1(
                    called_object,
                    args
                );
                Py_DECREF( called_object );

                return result;
            }
        }

        if ( descr != NULL )
        {
            CHECK_OBJECT( descr );

            PyObject *result = CALL_FUNCTION_WITH_ARGS1(
                descr,
                args
            );
            Py_DECREF( descr );

            return result;
        }

#if PYTHON_VERSION < 300
        PyErr_Format(
            PyExc_AttributeError,
            "'%s' object has no attribute '%s'",
            type->tp_name,
            PyString_AS_STRING( attr_name )
        );
#else
        PyErr_Format(
            PyExc_AttributeError,
            "'%s' object has no attribute '%U'",
            type->tp_name,
            attr_name
        );
#endif
        return NULL;
    }
#if PYTHON_VERSION < 300
    else if ( type == &PyInstance_Type )
    {
        PyInstanceObject *source_instance = (PyInstanceObject *)source;

        // The special cases have their own variant on the code generation level
        // as we are called with constants only.
        assert( attr_name != const_str_plain___dict__ );
        assert( attr_name != const_str_plain___class__ );

        // Try the instance dict first.
        PyObject *called_object = GET_STRING_DICT_VALUE(
            (PyDictObject *)source_instance->in_dict,
            (PyStringObject *)attr_name
        );

        // Note: The "called_object" was found without taking a reference,
        // so we need not release it in this branch.
        if ( called_object != NULL )
        {
            return CALL_FUNCTION_WITH_ARGS1( called_object, args );
        }

        // Then check the class dictionaries.
        called_object = FIND_ATTRIBUTE_IN_CLASS(
            source_instance->in_class,
            attr_name
        );

        // Note: The "called_object" was found without taking a reference,
        // so we need not release it in this branch.
        if ( called_object != NULL )
        {
            descrgetfunc descr_get = Py_TYPE( called_object )->tp_descr_get;

            if ( descr_get == Nuitka_Function_Type.tp_descr_get )
            {
                return Nuitka_CallMethodFunctionPosArgs(
                    (struct Nuitka_FunctionObject const *)called_object,
                    source,
                    args,
                    1
                );
            }
            else if ( descr_get != NULL )
            {
                PyObject *method = descr_get(
                    called_object,
                    source,
                    (PyObject *)source_instance->in_class
                );

                if (unlikely( method == NULL ))
                {
                    return NULL;
                }

                PyObject *result = CALL_FUNCTION_WITH_ARGS1( method, args );
                Py_DECREF( method );
                return result;
            }
            else
            {
                return CALL_FUNCTION_WITH_ARGS1( called_object, args );
            }

        }
        else if (unlikely( source_instance->in_class->cl_getattr == NULL ))
        {
            PyErr_Format(
                PyExc_AttributeError,
                "%s instance has no attribute '%s'",
                PyString_AS_STRING( source_instance->in_class->cl_name ),
                PyString_AS_STRING( attr_name )
            );

            return NULL;
        }
        else
        {
            // Finally allow the "__getattr__" override to provide it or else
            // it's an error.

            PyObject *args2[] = {
                source,
                attr_name
            };

            called_object = CALL_FUNCTION_WITH_ARGS2(
                source_instance->in_class->cl_getattr,
                args2
            );

            if (unlikely( called_object == NULL ))
            {
                return NULL;
            }

            PyObject *result = CALL_FUNCTION_WITH_ARGS1(
                called_object,
                args
            );
            Py_DECREF( called_object );
            return result;
        }
    }
#endif
    else if ( type->tp_getattro != NULL )
    {
        PyObject *called_object = (*type->tp_getattro)(
            source,
            attr_name
        );

        if (unlikely( called_object == NULL ))
        {
            return NULL;
        }

        PyObject *result = CALL_FUNCTION_WITH_ARGS1(
            called_object,
            args
        );
        Py_DECREF( called_object );
        return result;
    }
    else if ( type->tp_getattr != NULL )
    {
        PyObject *called_object = (*type->tp_getattr)(
            source,
            (char *)Nuitka_String_AsString_Unchecked( attr_name )
        );

        if (unlikely( called_object == NULL ))
        {
            return NULL;
        }

        PyObject *result = CALL_FUNCTION_WITH_ARGS1(
            called_object,
            args
        );
        Py_DECREF( called_object );
        return result;
    }
    else
    {
        PyErr_Format(
            PyExc_AttributeError,
            "'%s' object has no attribute '%s'",
            type->tp_name,
            Nuitka_String_AsString_Unchecked( attr_name )
        );

        return NULL;
    }
}

PyObject *CALL_METHOD_WITH_ARGS2( PyObject *source, PyObject *attr_name, PyObject **args )
{
    CHECK_OBJECT( source );
    CHECK_OBJECT( attr_name );

    // Check if arguments are valid objects in debug mode.
#ifndef __NUITKA_NO_ASSERT__
    for( size_t i = 0; i < 2; i++ )
    {
        CHECK_OBJECT( args[ i ] );
    }
#endif

    PyTypeObject *type = Py_TYPE( source );

    if ( type->tp_getattro == PyObject_GenericGetAttr )
    {
        // Unfortunately this is required, although of cause rarely necessary.
        if (unlikely( type->tp_dict == NULL ))
        {
            if (unlikely( PyType_Ready( type ) < 0 ))
            {
                return NULL;
            }
        }

        PyObject *descr = _PyType_Lookup( type, attr_name );
        descrgetfunc func = NULL;

        if ( descr != NULL )
        {
            Py_INCREF( descr );

#if PYTHON_VERSION < 300
            if ( PyType_HasFeature( Py_TYPE( descr ), Py_TPFLAGS_HAVE_CLASS ) )
            {
#endif
                func = Py_TYPE( descr )->tp_descr_get;

                if ( func != NULL && PyDescr_IsData( descr ) )
                {
                    PyObject *called_object = func( descr, source, (PyObject *)type );
                    Py_DECREF( descr );

                    PyObject *result = CALL_FUNCTION_WITH_ARGS2(
                        called_object,
                        args
                    );
                    Py_DECREF( called_object );
                    return result;
                }
#if PYTHON_VERSION < 300
            }
#endif
        }

        Py_ssize_t dictoffset = type->tp_dictoffset;
        PyObject *dict = NULL;

        if ( dictoffset != 0 )
        {
            // Negative dictionary offsets have special meaning.
            if ( dictoffset < 0 )
            {
                Py_ssize_t tsize;
                size_t size;

                tsize = ((PyVarObject *)source)->ob_size;
                if (tsize < 0)
                    tsize = -tsize;
                size = _PyObject_VAR_SIZE( type, tsize );

                dictoffset += (long)size;
            }

            PyObject **dictptr = (PyObject **) ((char *)source + dictoffset);
            dict = *dictptr;
        }

        if ( dict != NULL )
        {
            CHECK_OBJECT( dict );

            Py_INCREF( dict );

            PyObject *called_object = PyDict_GetItem( dict, attr_name );

            if ( called_object != NULL )
            {
                Py_INCREF( called_object );
                Py_XDECREF( descr );
                Py_DECREF( dict );

                PyObject *result = CALL_FUNCTION_WITH_ARGS2(
                    called_object,
                    args
                );
                Py_DECREF( called_object );
                return result;
            }

            Py_DECREF( dict );
        }

        if ( func != NULL )
        {
            if ( func == Nuitka_Function_Type.tp_descr_get )
            {
                PyObject *result = Nuitka_CallMethodFunctionPosArgs(
                    (struct Nuitka_FunctionObject const *)descr,
                    source,
                    args,
                    2
                );

                Py_DECREF( descr );

                return result;
            }
            else
            {
                PyObject *called_object = func( descr, source, (PyObject *)type );
                CHECK_OBJECT( called_object );

                Py_DECREF( descr );

                PyObject *result = CALL_FUNCTION_WITH_ARGS2(
                    called_object,
                    args
                );
                Py_DECREF( called_object );

                return result;
            }
        }

        if ( descr != NULL )
        {
            CHECK_OBJECT( descr );

            PyObject *result = CALL_FUNCTION_WITH_ARGS2(
                descr,
                args
            );
            Py_DECREF( descr );

            return result;
        }

#if PYTHON_VERSION < 300
        PyErr_Format(
            PyExc_AttributeError,
            "'%s' object has no attribute '%s'",
            type->tp_name,
            PyString_AS_STRING( attr_name )
        );
#else
        PyErr_Format(
            PyExc_AttributeError,
            "'%s' object has no attribute '%U'",
            type->tp_name,
            attr_name
        );
#endif
        return NULL;
    }
#if PYTHON_VERSION < 300
    else if ( type == &PyInstance_Type )
    {
        PyInstanceObject *source_instance = (PyInstanceObject *)source;

        // The special cases have their own variant on the code generation level
        // as we are called with constants only.
        assert( attr_name != const_str_plain___dict__ );
        assert( attr_name != const_str_plain___class__ );

        // Try the instance dict first.
        PyObject *called_object = GET_STRING_DICT_VALUE(
            (PyDictObject *)source_instance->in_dict,
            (PyStringObject *)attr_name
        );

        // Note: The "called_object" was found without taking a reference,
        // so we need not release it in this branch.
        if ( called_object != NULL )
        {
            return CALL_FUNCTION_WITH_ARGS2( called_object, args );
        }

        // Then check the class dictionaries.
        called_object = FIND_ATTRIBUTE_IN_CLASS(
            source_instance->in_class,
            attr_name
        );

        // Note: The "called_object" was found without taking a reference,
        // so we need not release it in this branch.
        if ( called_object != NULL )
        {
            descrgetfunc descr_get = Py_TYPE( called_object )->tp_descr_get;

            if ( descr_get == Nuitka_Function_Type.tp_descr_get )
            {
                return Nuitka_CallMethodFunctionPosArgs(
                    (struct Nuitka_FunctionObject const *)called_object,
                    source,
                    args,
                    2
                );
            }
            else if ( descr_get != NULL )
            {
                PyObject *method = descr_get(
                    called_object,
                    source,
                    (PyObject *)source_instance->in_class
                );

                if (unlikely( method == NULL ))
                {
                    return NULL;
                }

                PyObject *result = CALL_FUNCTION_WITH_ARGS2( method, args );
                Py_DECREF( method );
                return result;
            }
            else
            {
                return CALL_FUNCTION_WITH_ARGS2( called_object, args );
            }

        }
        else if (unlikely( source_instance->in_class->cl_getattr == NULL ))
        {
            PyErr_Format(
                PyExc_AttributeError,
                "%s instance has no attribute '%s'",
                PyString_AS_STRING( source_instance->in_class->cl_name ),
                PyString_AS_STRING( attr_name )
            );

            return NULL;
        }
        else
        {
            // Finally allow the "__getattr__" override to provide it or else
            // it's an error.

            PyObject *args2[] = {
                source,
                attr_name
            };

            called_object = CALL_FUNCTION_WITH_ARGS2(
                source_instance->in_class->cl_getattr,
                args2
            );

            if (unlikely( called_object == NULL ))
            {
                return NULL;
            }

            PyObject *result = CALL_FUNCTION_WITH_ARGS2(
                called_object,
                args
            );
            Py_DECREF( called_object );
            return result;
        }
    }
#endif
    else if ( type->tp_getattro != NULL )
    {
        PyObject *called_object = (*type->tp_getattro)(
            source,
            attr_name
        );

        if (unlikely( called_object == NULL ))
        {
            return NULL;
        }

        PyObject *result = CALL_FUNCTION_WITH_ARGS2(
            called_object,
            args
        );
        Py_DECREF( called_object );
        return result;
    }
    else if ( type->tp_getattr != NULL )
    {
        PyObject *called_object = (*type->tp_getattr)(
            source,
            (char *)Nuitka_String_AsString_Unchecked( attr_name )
        );

        if (unlikely( called_object == NULL ))
        {
            return NULL;
        }

        PyObject *result = CALL_FUNCTION_WITH_ARGS2(
            called_object,
            args
        );
        Py_DECREF( called_object );
        return result;
    }
    else
    {
        PyErr_Format(
            PyExc_AttributeError,
            "'%s' object has no attribute '%s'",
            type->tp_name,
            Nuitka_String_AsString_Unchecked( attr_name )
        );

        return NULL;
    }
}

PyObject *CALL_METHOD_WITH_ARGS3( PyObject *source, PyObject *attr_name, PyObject **args )
{
    CHECK_OBJECT( source );
    CHECK_OBJECT( attr_name );

    // Check if arguments are valid objects in debug mode.
#ifndef __NUITKA_NO_ASSERT__
    for( size_t i = 0; i < 3; i++ )
    {
        CHECK_OBJECT( args[ i ] );
    }
#endif

    PyTypeObject *type = Py_TYPE( source );

    if ( type->tp_getattro == PyObject_GenericGetAttr )
    {
        // Unfortunately this is required, although of cause rarely necessary.
        if (unlikely( type->tp_dict == NULL ))
        {
            if (unlikely( PyType_Ready( type ) < 0 ))
            {
                return NULL;
            }
        }

        PyObject *descr = _PyType_Lookup( type, attr_name );
        descrgetfunc func = NULL;

        if ( descr != NULL )
        {
            Py_INCREF( descr );

#if PYTHON_VERSION < 300
            if ( PyType_HasFeature( Py_TYPE( descr ), Py_TPFLAGS_HAVE_CLASS ) )
            {
#endif
                func = Py_TYPE( descr )->tp_descr_get;

                if ( func != NULL && PyDescr_IsData( descr ) )
                {
                    PyObject *called_object = func( descr, source, (PyObject *)type );
                    Py_DECREF( descr );

                    PyObject *result = CALL_FUNCTION_WITH_ARGS3(
                        called_object,
                        args
                    );
                    Py_DECREF( called_object );
                    return result;
                }
#if PYTHON_VERSION < 300
            }
#endif
        }

        Py_ssize_t dictoffset = type->tp_dictoffset;
        PyObject *dict = NULL;

        if ( dictoffset != 0 )
        {
            // Negative dictionary offsets have special meaning.
            if ( dictoffset < 0 )
            {
                Py_ssize_t tsize;
                size_t size;

                tsize = ((PyVarObject *)source)->ob_size;
                if (tsize < 0)
                    tsize = -tsize;
                size = _PyObject_VAR_SIZE( type, tsize );

                dictoffset += (long)size;
            }

            PyObject **dictptr = (PyObject **) ((char *)source + dictoffset);
            dict = *dictptr;
        }

        if ( dict != NULL )
        {
            CHECK_OBJECT( dict );

            Py_INCREF( dict );

            PyObject *called_object = PyDict_GetItem( dict, attr_name );

            if ( called_object != NULL )
            {
                Py_INCREF( called_object );
                Py_XDECREF( descr );
                Py_DECREF( dict );

                PyObject *result = CALL_FUNCTION_WITH_ARGS3(
                    called_object,
                    args
                );
                Py_DECREF( called_object );
                return result;
            }

            Py_DECREF( dict );
        }

        if ( func != NULL )
        {
            if ( func == Nuitka_Function_Type.tp_descr_get )
            {
                PyObject *result = Nuitka_CallMethodFunctionPosArgs(
                    (struct Nuitka_FunctionObject const *)descr,
                    source,
                    args,
                    3
                );

                Py_DECREF( descr );

                return result;
            }
            else
            {
                PyObject *called_object = func( descr, source, (PyObject *)type );
                CHECK_OBJECT( called_object );

                Py_DECREF( descr );

                PyObject *result = CALL_FUNCTION_WITH_ARGS3(
                    called_object,
                    args
                );
                Py_DECREF( called_object );

                return result;
            }
        }

        if ( descr != NULL )
        {
            CHECK_OBJECT( descr );

            PyObject *result = CALL_FUNCTION_WITH_ARGS3(
                descr,
                args
            );
            Py_DECREF( descr );

            return result;
        }

#if PYTHON_VERSION < 300
        PyErr_Format(
            PyExc_AttributeError,
            "'%s' object has no attribute '%s'",
            type->tp_name,
            PyString_AS_STRING( attr_name )
        );
#else
        PyErr_Format(
            PyExc_AttributeError,
            "'%s' object has no attribute '%U'",
            type->tp_name,
            attr_name
        );
#endif
        return NULL;
    }
#if PYTHON_VERSION < 300
    else if ( type == &PyInstance_Type )
    {
        PyInstanceObject *source_instance = (PyInstanceObject *)source;

        // The special cases have their own variant on the code generation level
        // as we are called with constants only.
        assert( attr_name != const_str_plain___dict__ );
        assert( attr_name != const_str_plain___class__ );

        // Try the instance dict first.
        PyObject *called_object = GET_STRING_DICT_VALUE(
            (PyDictObject *)source_instance->in_dict,
            (PyStringObject *)attr_name
        );

        // Note: The "called_object" was found without taking a reference,
        // so we need not release it in this branch.
        if ( called_object != NULL )
        {
            return CALL_FUNCTION_WITH_ARGS3( called_object, args );
        }

        // Then check the class dictionaries.
        called_object = FIND_ATTRIBUTE_IN_CLASS(
            source_instance->in_class,
            attr_name
        );

        // Note: The "called_object" was found without taking a reference,
        // so we need not release it in this branch.
        if ( called_object != NULL )
        {
            descrgetfunc descr_get = Py_TYPE( called_object )->tp_descr_get;

            if ( descr_get == Nuitka_Function_Type.tp_descr_get )
            {
                return Nuitka_CallMethodFunctionPosArgs(
                    (struct Nuitka_FunctionObject const *)called_object,
                    source,
                    args,
                    3
                );
            }
            else if ( descr_get != NULL )
            {
                PyObject *method = descr_get(
                    called_object,
                    source,
                    (PyObject *)source_instance->in_class
                );

                if (unlikely( method == NULL ))
                {
                    return NULL;
                }

                PyObject *result = CALL_FUNCTION_WITH_ARGS3( method, args );
                Py_DECREF( method );
                return result;
            }
            else
            {
                return CALL_FUNCTION_WITH_ARGS3( called_object, args );
            }

        }
        else if (unlikely( source_instance->in_class->cl_getattr == NULL ))
        {
            PyErr_Format(
                PyExc_AttributeError,
                "%s instance has no attribute '%s'",
                PyString_AS_STRING( source_instance->in_class->cl_name ),
                PyString_AS_STRING( attr_name )
            );

            return NULL;
        }
        else
        {
            // Finally allow the "__getattr__" override to provide it or else
            // it's an error.

            PyObject *args2[] = {
                source,
                attr_name
            };

            called_object = CALL_FUNCTION_WITH_ARGS2(
                source_instance->in_class->cl_getattr,
                args2
            );

            if (unlikely( called_object == NULL ))
            {
                return NULL;
            }

            PyObject *result = CALL_FUNCTION_WITH_ARGS3(
                called_object,
                args
            );
            Py_DECREF( called_object );
            return result;
        }
    }
#endif
    else if ( type->tp_getattro != NULL )
    {
        PyObject *called_object = (*type->tp_getattro)(
            source,
            attr_name
        );

        if (unlikely( called_object == NULL ))
        {
            return NULL;
        }

        PyObject *result = CALL_FUNCTION_WITH_ARGS3(
            called_object,
            args
        );
        Py_DECREF( called_object );
        return result;
    }
    else if ( type->tp_getattr != NULL )
    {
        PyObject *called_object = (*type->tp_getattr)(
            source,
            (char *)Nuitka_String_AsString_Unchecked( attr_name )
        );

        if (unlikely( called_object == NULL ))
        {
            return NULL;
        }

        PyObject *result = CALL_FUNCTION_WITH_ARGS3(
            called_object,
            args
        );
        Py_DECREF( called_object );
        return result;
    }
    else
    {
        PyErr_Format(
            PyExc_AttributeError,
            "'%s' object has no attribute '%s'",
            type->tp_name,
            Nuitka_String_AsString_Unchecked( attr_name )
        );

        return NULL;
    }
}
/* Code to register embedded modules for meta path based loading if any. */

#include "nuitka/unfreezing.h"

/* Table for lookup to find compiled or bytecode modules included in this
 * binary or module, or put along this binary as extension modules. We do
 * our own loading for each of these.
 */
MOD_INIT_DECL( __main__ );
MOD_INIT_DECL( mypy_extensions );
MOD_INIT_DECL( pygame );
MOD_INIT_DECL( pygame$_numpysndarray );
MOD_INIT_DECL( pygame$_numpysurfarray );
MOD_INIT_DECL( pygame$colordict );
MOD_INIT_DECL( pygame$compat );
MOD_INIT_DECL( pygame$cursors );
MOD_INIT_DECL( pygame$ftfont );
MOD_INIT_DECL( pygame$locals );
MOD_INIT_DECL( pygame$macosx );
MOD_INIT_DECL( pygame$pkgdata );
MOD_INIT_DECL( pygame$sndarray );
MOD_INIT_DECL( pygame$sprite );
MOD_INIT_DECL( pygame$surfarray );
MOD_INIT_DECL( pygame$sysfont );
MOD_INIT_DECL( pygame$threads );
MOD_INIT_DECL( pygame$version );
MOD_INIT_DECL( pythoncom );
MOD_INIT_DECL( pywintypes );
MOD_INIT_DECL( six );
MOD_INIT_DECL( win32com );
MOD_INIT_DECL( win32com$shell );
static struct Nuitka_MetaPathBasedLoaderEntry meta_path_loader_entries[] =
{
    { "__main__", MOD_INIT_NAME( __main__ ), 0, 0, NUITKA_COMPILED_MODULE },
    { "_asyncio", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "_bz2", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "_contextvars", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "_ctypes", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "_decimal", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "_elementtree", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "_hashlib", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "_lzma", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "_msi", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "_multiprocessing", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "_overlapped", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "_queue", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "_socket", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "_sqlite3", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "_ssl", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "_tkinter", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "_win32sysloader", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "mypy_extensions", MOD_INIT_NAME( mypy_extensions ), 0, 0, NUITKA_COMPILED_MODULE },
    { "pkg_resources", NULL, 97982, 96042, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "pkg_resources._vendor", NULL, 194024, 168, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "pkg_resources._vendor.appdirs", NULL, 194192, 20656, NUITKA_BYTECODE_FLAG },
    { "pkg_resources._vendor.packaging", NULL, 214848, 542, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "pkg_resources._vendor.packaging.__about__", NULL, 215390, 704, NUITKA_BYTECODE_FLAG },
    { "pkg_resources._vendor.packaging._compat", NULL, 216094, 994, NUITKA_BYTECODE_FLAG },
    { "pkg_resources._vendor.packaging._structures", NULL, 217088, 2846, NUITKA_BYTECODE_FLAG },
    { "pkg_resources._vendor.packaging.markers", NULL, 219934, 8854, NUITKA_BYTECODE_FLAG },
    { "pkg_resources._vendor.packaging.requirements", NULL, 228788, 3859, NUITKA_BYTECODE_FLAG },
    { "pkg_resources._vendor.packaging.specifiers", NULL, 232647, 19772, NUITKA_BYTECODE_FLAG },
    { "pkg_resources._vendor.packaging.version", NULL, 252419, 10539, NUITKA_BYTECODE_FLAG },
    { "pkg_resources._vendor.pyparsing", NULL, 262958, 203011, NUITKA_BYTECODE_FLAG },
    { "pkg_resources._vendor.six", NULL, 465969, 24369, NUITKA_BYTECODE_FLAG },
    { "pkg_resources.extern", NULL, 490338, 2387, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "pkg_resources.py31compat", NULL, 492725, 605, NUITKA_BYTECODE_FLAG },
    { "pyexpat", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "pygame", MOD_INIT_NAME( pygame ), 0, 0, NUITKA_PACKAGE_FLAG },
    { "pygame._freetype", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "pygame._numpysndarray", MOD_INIT_NAME( pygame$_numpysndarray ), 0, 0, NUITKA_COMPILED_MODULE },
    { "pygame._numpysurfarray", MOD_INIT_NAME( pygame$_numpysurfarray ), 0, 0, NUITKA_COMPILED_MODULE },
    { "pygame.base", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "pygame.bufferproxy", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "pygame.cdrom", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "pygame.color", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "pygame.colordict", MOD_INIT_NAME( pygame$colordict ), 0, 0, NUITKA_COMPILED_MODULE },
    { "pygame.compat", MOD_INIT_NAME( pygame$compat ), 0, 0, NUITKA_COMPILED_MODULE },
    { "pygame.constants", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "pygame.cursors", MOD_INIT_NAME( pygame$cursors ), 0, 0, NUITKA_COMPILED_MODULE },
    { "pygame.display", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "pygame.draw", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "pygame.event", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "pygame.fastevent", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "pygame.font", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "pygame.ftfont", MOD_INIT_NAME( pygame$ftfont ), 0, 0, NUITKA_COMPILED_MODULE },
    { "pygame.image", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "pygame.imageext", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "pygame.joystick", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "pygame.key", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "pygame.locals", MOD_INIT_NAME( pygame$locals ), 0, 0, NUITKA_COMPILED_MODULE },
    { "pygame.macosx", MOD_INIT_NAME( pygame$macosx ), 0, 0, NUITKA_COMPILED_MODULE },
    { "pygame.mask", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "pygame.math", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "pygame.mixer", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "pygame.mixer_music", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "pygame.mouse", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "pygame.overlay", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "pygame.pixelarray", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "pygame.pixelcopy", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "pygame.pkgdata", MOD_INIT_NAME( pygame$pkgdata ), 0, 0, NUITKA_COMPILED_MODULE },
    { "pygame.rect", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "pygame.rwobject", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "pygame.scrap", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "pygame.sndarray", MOD_INIT_NAME( pygame$sndarray ), 0, 0, NUITKA_COMPILED_MODULE },
    { "pygame.sprite", MOD_INIT_NAME( pygame$sprite ), 0, 0, NUITKA_COMPILED_MODULE },
    { "pygame.surface", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "pygame.surfarray", MOD_INIT_NAME( pygame$surfarray ), 0, 0, NUITKA_COMPILED_MODULE },
    { "pygame.surflock", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "pygame.sysfont", MOD_INIT_NAME( pygame$sysfont ), 0, 0, NUITKA_COMPILED_MODULE },
    { "pygame.threads", MOD_INIT_NAME( pygame$threads ), 0, 0, NUITKA_PACKAGE_FLAG },
    { "pygame.time", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "pygame.transform", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "pygame.version", MOD_INIT_NAME( pygame$version ), 0, 0, NUITKA_COMPILED_MODULE },
    { "pythoncom", MOD_INIT_NAME( pythoncom ), 0, 0, NUITKA_COMPILED_MODULE },
    { "pywintypes", MOD_INIT_NAME( pywintypes ), 0, 0, NUITKA_COMPILED_MODULE },
    { "select", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "six", MOD_INIT_NAME( six ), 0, 0, NUITKA_COMPILED_MODULE },
    { "unicodedata", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "win32api", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "win32com", MOD_INIT_NAME( win32com ), 0, 0, NUITKA_PACKAGE_FLAG },
    { "win32com.shell", MOD_INIT_NAME( win32com$shell ), 0, 0, NUITKA_PACKAGE_FLAG },
    { "__future__", NULL, 493330, 4129, NUITKA_BYTECODE_FLAG },
    { "_bootlocale", NULL, 497459, 1246, NUITKA_BYTECODE_FLAG },
    { "_compat_pickle", NULL, 498705, 5770, NUITKA_BYTECODE_FLAG },
    { "_dummy_thread", NULL, 504475, 4850, NUITKA_BYTECODE_FLAG },
    { "_markupbase", NULL, 509325, 7747, NUITKA_BYTECODE_FLAG },
    { "_osx_support", NULL, 517072, 9540, NUITKA_BYTECODE_FLAG },
    { "_py_abc", NULL, 526612, 4616, NUITKA_BYTECODE_FLAG },
    { "_pyio", NULL, 531228, 72758, NUITKA_BYTECODE_FLAG },
    { "_sitebuiltins", NULL, 603986, 3427, NUITKA_BYTECODE_FLAG },
    { "_strptime", NULL, 607413, 16066, NUITKA_BYTECODE_FLAG },
    { "_threading_local", NULL, 623479, 6374, NUITKA_BYTECODE_FLAG },
    { "_virtualenv_distutils", NULL, 629853, 360, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "aifc", NULL, 630213, 26105, NUITKA_BYTECODE_FLAG },
    { "argparse", NULL, 656318, 61875, NUITKA_BYTECODE_FLAG },
    { "ast", NULL, 718193, 12042, NUITKA_BYTECODE_FLAG },
    { "asynchat", NULL, 730235, 6796, NUITKA_BYTECODE_FLAG },
    { "asyncio", NULL, 737031, 652, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "asyncio.base_events", NULL, 737683, 47629, NUITKA_BYTECODE_FLAG },
    { "asyncio.base_futures", NULL, 785312, 2064, NUITKA_BYTECODE_FLAG },
    { "asyncio.base_subprocess", NULL, 787376, 9153, NUITKA_BYTECODE_FLAG },
    { "asyncio.base_tasks", NULL, 796529, 1828, NUITKA_BYTECODE_FLAG },
    { "asyncio.constants", NULL, 798357, 553, NUITKA_BYTECODE_FLAG },
    { "asyncio.coroutines", NULL, 798910, 6340, NUITKA_BYTECODE_FLAG },
    { "asyncio.events", NULL, 805250, 27817, NUITKA_BYTECODE_FLAG },
    { "asyncio.format_helpers", NULL, 833067, 2279, NUITKA_BYTECODE_FLAG },
    { "asyncio.futures", NULL, 835346, 10707, NUITKA_BYTECODE_FLAG },
    { "asyncio.locks", NULL, 846053, 15875, NUITKA_BYTECODE_FLAG },
    { "asyncio.log", NULL, 861928, 202, NUITKA_BYTECODE_FLAG },
    { "asyncio.proactor_events", NULL, 862130, 19641, NUITKA_BYTECODE_FLAG },
    { "asyncio.protocols", NULL, 881771, 8690, NUITKA_BYTECODE_FLAG },
    { "asyncio.queues", NULL, 890461, 8135, NUITKA_BYTECODE_FLAG },
    { "asyncio.runners", NULL, 898596, 1876, NUITKA_BYTECODE_FLAG },
    { "asyncio.selector_events", NULL, 900472, 28442, NUITKA_BYTECODE_FLAG },
    { "asyncio.sslproto", NULL, 928914, 21173, NUITKA_BYTECODE_FLAG },
    { "asyncio.streams", NULL, 950087, 20250, NUITKA_BYTECODE_FLAG },
    { "asyncio.subprocess", NULL, 970337, 6714, NUITKA_BYTECODE_FLAG },
    { "asyncio.tasks", NULL, 977051, 21809, NUITKA_BYTECODE_FLAG },
    { "asyncio.transports", NULL, 998860, 12173, NUITKA_BYTECODE_FLAG },
    { "asyncio.windows_events", NULL, 1011033, 22571, NUITKA_BYTECODE_FLAG },
    { "asyncio.windows_utils", NULL, 1033604, 4363, NUITKA_BYTECODE_FLAG },
    { "asyncore", NULL, 1037967, 15806, NUITKA_BYTECODE_FLAG },
    { "bdb", NULL, 1053773, 24355, NUITKA_BYTECODE_FLAG },
    { "binhex", NULL, 1078128, 12021, NUITKA_BYTECODE_FLAG },
    { "bisect", NULL, 1090149, 2695, NUITKA_BYTECODE_FLAG },
    { "cProfile", NULL, 1092844, 4428, NUITKA_BYTECODE_FLAG },
    { "calendar", NULL, 1097272, 27386, NUITKA_BYTECODE_FLAG },
    { "cgi", NULL, 1124658, 26547, NUITKA_BYTECODE_FLAG },
    { "cgitb", NULL, 1151205, 10074, NUITKA_BYTECODE_FLAG },
    { "chunk", NULL, 1161279, 4881, NUITKA_BYTECODE_FLAG },
    { "cmd", NULL, 1166160, 12552, NUITKA_BYTECODE_FLAG },
    { "code", NULL, 1178712, 9820, NUITKA_BYTECODE_FLAG },
    { "codeop", NULL, 1188532, 6252, NUITKA_BYTECODE_FLAG },
    { "colorsys", NULL, 1194784, 3259, NUITKA_BYTECODE_FLAG },
    { "compileall", NULL, 1198043, 8961, NUITKA_BYTECODE_FLAG },
    { "concurrent", NULL, 1207004, 108, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "concurrent.futures", NULL, 1207112, 1048, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "concurrent.futures._base", NULL, 1208160, 20824, NUITKA_BYTECODE_FLAG },
    { "concurrent.futures.process", NULL, 1228984, 19523, NUITKA_BYTECODE_FLAG },
    { "concurrent.futures.thread", NULL, 1248507, 5135, NUITKA_BYTECODE_FLAG },
    { "configparser", NULL, 1253642, 45824, NUITKA_BYTECODE_FLAG },
    { "contextlib", NULL, 1299466, 19862, NUITKA_BYTECODE_FLAG },
    { "contextvars", NULL, 1319328, 219, NUITKA_BYTECODE_FLAG },
    { "copy", NULL, 1319547, 7098, NUITKA_BYTECODE_FLAG },
    { "csv", NULL, 1326645, 11794, NUITKA_BYTECODE_FLAG },
    { "ctypes", NULL, 1338439, 16111, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "ctypes._aix", NULL, 1354550, 9783, NUITKA_BYTECODE_FLAG },
    { "ctypes._endian", NULL, 1364333, 1918, NUITKA_BYTECODE_FLAG },
    { "ctypes.macholib", NULL, 1366251, 275, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "ctypes.macholib.dyld", NULL, 1366526, 4308, NUITKA_BYTECODE_FLAG },
    { "ctypes.macholib.dylib", NULL, 1370834, 1902, NUITKA_BYTECODE_FLAG },
    { "ctypes.macholib.framework", NULL, 1372736, 2182, NUITKA_BYTECODE_FLAG },
    { "ctypes.util", NULL, 1374918, 7711, NUITKA_BYTECODE_FLAG },
    { "ctypes.wintypes", NULL, 1382629, 5079, NUITKA_BYTECODE_FLAG },
    { "dataclasses", NULL, 1387708, 21390, NUITKA_BYTECODE_FLAG },
    { "datetime", NULL, 1409098, 56433, NUITKA_BYTECODE_FLAG },
    { "dbm", NULL, 1465531, 4128, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "dbm.dumb", NULL, 1469659, 8362, NUITKA_BYTECODE_FLAG },
    { "decimal", NULL, 1478021, 162134, NUITKA_BYTECODE_FLAG },
    { "difflib", NULL, 1640155, 59400, NUITKA_BYTECODE_FLAG },
    { "distutils", NULL, 1699555, 2828, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "distutils._msvccompiler", NULL, 1702383, 13484, NUITKA_BYTECODE_FLAG },
    { "distutils.archive_util", NULL, 1715867, 6340, NUITKA_BYTECODE_FLAG },
    { "distutils.bcppcompiler", NULL, 1722207, 6463, NUITKA_BYTECODE_FLAG },
    { "distutils.ccompiler", NULL, 1728670, 33178, NUITKA_BYTECODE_FLAG },
    { "distutils.cmd", NULL, 1761848, 13870, NUITKA_BYTECODE_FLAG },
    { "distutils.command", NULL, 1775718, 517, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "distutils.command.bdist", NULL, 1776235, 3616, NUITKA_BYTECODE_FLAG },
    { "distutils.command.bdist_dumb", NULL, 1779851, 3530, NUITKA_BYTECODE_FLAG },
    { "distutils.command.bdist_msi", NULL, 1783381, 19361, NUITKA_BYTECODE_FLAG },
    { "distutils.command.bdist_rpm", NULL, 1802742, 12455, NUITKA_BYTECODE_FLAG },
    { "distutils.command.bdist_wininst", NULL, 1815197, 7969, NUITKA_BYTECODE_FLAG },
    { "distutils.command.build", NULL, 1823166, 3797, NUITKA_BYTECODE_FLAG },
    { "distutils.command.build_clib", NULL, 1826963, 4847, NUITKA_BYTECODE_FLAG },
    { "distutils.command.build_ext", NULL, 1831810, 15724, NUITKA_BYTECODE_FLAG },
    { "distutils.command.build_py", NULL, 1847534, 10353, NUITKA_BYTECODE_FLAG },
    { "distutils.command.build_scripts", NULL, 1857887, 4252, NUITKA_BYTECODE_FLAG },
    { "distutils.command.check", NULL, 1862139, 4772, NUITKA_BYTECODE_FLAG },
    { "distutils.command.clean", NULL, 1866911, 2054, NUITKA_BYTECODE_FLAG },
    { "distutils.command.config", NULL, 1868965, 10158, NUITKA_BYTECODE_FLAG },
    { "distutils.command.install", NULL, 1879123, 13481, NUITKA_BYTECODE_FLAG },
    { "distutils.command.install_data", NULL, 1892604, 2247, NUITKA_BYTECODE_FLAG },
    { "distutils.command.install_egg_info", NULL, 1894851, 2945, NUITKA_BYTECODE_FLAG },
    { "distutils.command.install_headers", NULL, 1897796, 1662, NUITKA_BYTECODE_FLAG },
    { "distutils.command.install_lib", NULL, 1899458, 5040, NUITKA_BYTECODE_FLAG },
    { "distutils.command.install_scripts", NULL, 1904498, 2104, NUITKA_BYTECODE_FLAG },
    { "distutils.command.register", NULL, 1906602, 8439, NUITKA_BYTECODE_FLAG },
    { "distutils.command.sdist", NULL, 1915041, 14470, NUITKA_BYTECODE_FLAG },
    { "distutils.command.upload", NULL, 1929511, 5052, NUITKA_BYTECODE_FLAG },
    { "distutils.config", NULL, 1934563, 3447, NUITKA_BYTECODE_FLAG },
    { "distutils.core", NULL, 1938010, 6572, NUITKA_BYTECODE_FLAG },
    { "distutils.cygwinccompiler", NULL, 1944582, 8490, NUITKA_BYTECODE_FLAG },
    { "distutils.debug", NULL, 1953072, 170, NUITKA_BYTECODE_FLAG },
    { "distutils.dep_util", NULL, 1953242, 2686, NUITKA_BYTECODE_FLAG },
    { "distutils.dir_util", NULL, 1955928, 5780, NUITKA_BYTECODE_FLAG },
    { "distutils.dist", NULL, 1961708, 34401, NUITKA_BYTECODE_FLAG },
    { "distutils.errors", NULL, 1996109, 5456, NUITKA_BYTECODE_FLAG },
    { "distutils.extension", NULL, 2001565, 6867, NUITKA_BYTECODE_FLAG },
    { "distutils.fancy_getopt", NULL, 2008432, 10579, NUITKA_BYTECODE_FLAG },
    { "distutils.file_util", NULL, 2019011, 5865, NUITKA_BYTECODE_FLAG },
    { "distutils.filelist", NULL, 2024876, 9800, NUITKA_BYTECODE_FLAG },
    { "distutils.log", NULL, 2034676, 2243, NUITKA_BYTECODE_FLAG },
    { "distutils.msvc9compiler", NULL, 2036919, 17345, NUITKA_BYTECODE_FLAG },
    { "distutils.msvccompiler", NULL, 2054264, 14533, NUITKA_BYTECODE_FLAG },
    { "distutils.spawn", NULL, 2068797, 4951, NUITKA_BYTECODE_FLAG },
    { "distutils.sysconfig", NULL, 2073748, 11820, NUITKA_BYTECODE_FLAG },
    { "distutils.text_file", NULL, 2085568, 8407, NUITKA_BYTECODE_FLAG },
    { "distutils.unixccompiler", NULL, 2093975, 6441, NUITKA_BYTECODE_FLAG },
    { "distutils.util", NULL, 2100416, 15017, NUITKA_BYTECODE_FLAG },
    { "distutils.version", NULL, 2115433, 7318, NUITKA_BYTECODE_FLAG },
    { "distutils.versionpredicate", NULL, 2122751, 5065, NUITKA_BYTECODE_FLAG },
    { "doctest", NULL, 2127816, 75572, NUITKA_BYTECODE_FLAG },
    { "dummy_threading", NULL, 2203388, 1086, NUITKA_BYTECODE_FLAG },
    { "email", NULL, 2204474, 1653, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "email._encoded_words", NULL, 2206127, 5615, NUITKA_BYTECODE_FLAG },
    { "email._header_value_parser", NULL, 2211742, 75587, NUITKA_BYTECODE_FLAG },
    { "email._parseaddr", NULL, 2287329, 12310, NUITKA_BYTECODE_FLAG },
    { "email._policybase", NULL, 2299639, 14812, NUITKA_BYTECODE_FLAG },
    { "email.base64mime", NULL, 2314451, 3197, NUITKA_BYTECODE_FLAG },
    { "email.charset", NULL, 2317648, 11491, NUITKA_BYTECODE_FLAG },
    { "email.contentmanager", NULL, 2329139, 7257, NUITKA_BYTECODE_FLAG },
    { "email.encoders", NULL, 2336396, 1626, NUITKA_BYTECODE_FLAG },
    { "email.errors", NULL, 2338022, 5941, NUITKA_BYTECODE_FLAG },
    { "email.feedparser", NULL, 2343963, 10587, NUITKA_BYTECODE_FLAG },
    { "email.generator", NULL, 2354550, 12462, NUITKA_BYTECODE_FLAG },
    { "email.header", NULL, 2367012, 16342, NUITKA_BYTECODE_FLAG },
    { "email.headerregistry", NULL, 2383354, 21259, NUITKA_BYTECODE_FLAG },
    { "email.iterators", NULL, 2404613, 1894, NUITKA_BYTECODE_FLAG },
    { "email.message", NULL, 2406507, 37902, NUITKA_BYTECODE_FLAG },
    { "email.mime", NULL, 2444409, 108, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "email.mime.application", NULL, 2444517, 1419, NUITKA_BYTECODE_FLAG },
    { "email.mime.audio", NULL, 2445936, 2578, NUITKA_BYTECODE_FLAG },
    { "email.mime.base", NULL, 2448514, 1044, NUITKA_BYTECODE_FLAG },
    { "email.mime.image", NULL, 2449558, 1864, NUITKA_BYTECODE_FLAG },
    { "email.mime.message", NULL, 2451422, 1293, NUITKA_BYTECODE_FLAG },
    { "email.mime.multipart", NULL, 2452715, 1515, NUITKA_BYTECODE_FLAG },
    { "email.mime.nonmultipart", NULL, 2454230, 730, NUITKA_BYTECODE_FLAG },
    { "email.mime.text", NULL, 2454960, 1277, NUITKA_BYTECODE_FLAG },
    { "email.parser", NULL, 2456237, 5709, NUITKA_BYTECODE_FLAG },
    { "email.policy", NULL, 2461946, 9602, NUITKA_BYTECODE_FLAG },
    { "email.quoprimime", NULL, 2471548, 7626, NUITKA_BYTECODE_FLAG },
    { "email.utils", NULL, 2479174, 9429, NUITKA_BYTECODE_FLAG },
    { "filecmp", NULL, 2488603, 8269, NUITKA_BYTECODE_FLAG },
    { "fileinput", NULL, 2496872, 13160, NUITKA_BYTECODE_FLAG },
    { "fnmatch", NULL, 2510032, 3334, NUITKA_BYTECODE_FLAG },
    { "formatter", NULL, 2513366, 17515, NUITKA_BYTECODE_FLAG },
    { "fractions", NULL, 2530881, 18390, NUITKA_BYTECODE_FLAG },
    { "ftplib", NULL, 2549271, 28028, NUITKA_BYTECODE_FLAG },
    { "getopt", NULL, 2577299, 6201, NUITKA_BYTECODE_FLAG },
    { "getpass", NULL, 2583500, 4126, NUITKA_BYTECODE_FLAG },
    { "gettext", NULL, 2587626, 14130, NUITKA_BYTECODE_FLAG },
    { "glob", NULL, 2601756, 4221, NUITKA_BYTECODE_FLAG },
    { "gzip", NULL, 2605977, 17147, NUITKA_BYTECODE_FLAG },
    { "hashlib", NULL, 2623124, 6532, NUITKA_BYTECODE_FLAG },
    { "hmac", NULL, 2629656, 6110, NUITKA_BYTECODE_FLAG },
    { "html", NULL, 2635766, 3359, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "html.entities", NULL, 2639125, 50431, NUITKA_BYTECODE_FLAG },
    { "html.parser", NULL, 2689556, 11069, NUITKA_BYTECODE_FLAG },
    { "http", NULL, 2700625, 5884, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "http.client", NULL, 2706509, 34005, NUITKA_BYTECODE_FLAG },
    { "http.cookiejar", NULL, 2740514, 53369, NUITKA_BYTECODE_FLAG },
    { "http.cookies", NULL, 2793883, 15206, NUITKA_BYTECODE_FLAG },
    { "http.server", NULL, 2809089, 33329, NUITKA_BYTECODE_FLAG },
    { "imaplib", NULL, 2842418, 41360, NUITKA_BYTECODE_FLAG },
    { "imghdr", NULL, 2883778, 4104, NUITKA_BYTECODE_FLAG },
    { "imp", NULL, 2887882, 9703, NUITKA_BYTECODE_FLAG },
    { "importlib.abc", NULL, 2897585, 13483, NUITKA_BYTECODE_FLAG },
    { "importlib.resources", NULL, 2911068, 8336, NUITKA_BYTECODE_FLAG },
    { "importlib.util", NULL, 2919404, 9353, NUITKA_BYTECODE_FLAG },
    { "ipaddress", NULL, 2928757, 62956, NUITKA_BYTECODE_FLAG },
    { "json", NULL, 2991713, 12300, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "json.decoder", NULL, 3004013, 9786, NUITKA_BYTECODE_FLAG },
    { "json.encoder", NULL, 3013799, 11268, NUITKA_BYTECODE_FLAG },
    { "json.scanner", NULL, 3025067, 1958, NUITKA_BYTECODE_FLAG },
    { "json.tool", NULL, 3027025, 1439, NUITKA_BYTECODE_FLAG },
    { "lib2to3", NULL, 3028464, 105, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "lib2to3.btm_matcher", NULL, 3028569, 4855, NUITKA_BYTECODE_FLAG },
    { "lib2to3.btm_utils", NULL, 3033424, 6105, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixer_base", NULL, 3039529, 6197, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixer_util", NULL, 3045726, 12020, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes", NULL, 3057746, 111, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "lib2to3.fixes.fix_apply", NULL, 3057857, 1649, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_asserts", NULL, 3059506, 1234, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_basestring", NULL, 3060740, 624, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_buffer", NULL, 3061364, 769, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_dict", NULL, 3062133, 3281, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_except", NULL, 3065414, 2779, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_exec", NULL, 3068193, 1110, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_execfile", NULL, 3069303, 1634, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_exitfunc", NULL, 3070937, 2257, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_filter", NULL, 3073194, 2322, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_funcattrs", NULL, 3075516, 935, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_future", NULL, 3076451, 745, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_getcwdu", NULL, 3077196, 749, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_has_key", NULL, 3077945, 2879, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_idioms", NULL, 3080824, 3864, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_import", NULL, 3084688, 2746, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_imports", NULL, 3087434, 4310, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_imports2", NULL, 3091744, 509, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_input", NULL, 3092253, 911, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_intern", NULL, 3093164, 1118, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_isinstance", NULL, 3094282, 1516, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_itertools", NULL, 3095798, 1505, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_itertools_imports", NULL, 3097303, 1541, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_long", NULL, 3098844, 666, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_map", NULL, 3099510, 3054, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_metaclass", NULL, 3102564, 5307, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_methodattrs", NULL, 3107871, 897, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_ne", NULL, 3108768, 768, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_next", NULL, 3109536, 3021, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_nonzero", NULL, 3112557, 884, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_numliterals", NULL, 3113441, 980, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_operator", NULL, 3114421, 4197, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_paren", NULL, 3118618, 1359, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_print", NULL, 3119977, 2286, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_raise", NULL, 3122263, 2210, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_raw_input", NULL, 3124473, 756, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_reduce", NULL, 3125229, 1091, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_reload", NULL, 3126320, 1118, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_renames", NULL, 3127438, 1954, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_repr", NULL, 3129392, 806, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_set_literal", NULL, 3130198, 1638, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_standarderror", NULL, 3131836, 681, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_sys_exc", NULL, 3132517, 1362, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_throw", NULL, 3133879, 1763, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_tuple_params", NULL, 3135642, 4557, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_types", NULL, 3140199, 1790, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_unicode", NULL, 3141989, 1502, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_urllib", NULL, 3143491, 5922, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_ws_comma", NULL, 3149413, 1084, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_xrange", NULL, 3150497, 2501, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_xreadlines", NULL, 3152998, 1078, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_zip", NULL, 3154076, 1542, NUITKA_BYTECODE_FLAG },
    { "lib2to3.main", NULL, 3155618, 8498, NUITKA_BYTECODE_FLAG },
    { "lib2to3.patcomp", NULL, 3164116, 5573, NUITKA_BYTECODE_FLAG },
    { "lib2to3.pgen2", NULL, 3169689, 141, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "lib2to3.pgen2.driver", NULL, 3169830, 5102, NUITKA_BYTECODE_FLAG },
    { "lib2to3.pgen2.grammar", NULL, 3174932, 6978, NUITKA_BYTECODE_FLAG },
    { "lib2to3.pgen2.literals", NULL, 3181910, 1520, NUITKA_BYTECODE_FLAG },
    { "lib2to3.pgen2.parse", NULL, 3183430, 6266, NUITKA_BYTECODE_FLAG },
    { "lib2to3.pgen2.pgen", NULL, 3189696, 9742, NUITKA_BYTECODE_FLAG },
    { "lib2to3.pgen2.token", NULL, 3199438, 1834, NUITKA_BYTECODE_FLAG },
    { "lib2to3.pgen2.tokenize", NULL, 3201272, 15168, NUITKA_BYTECODE_FLAG },
    { "lib2to3.pygram", NULL, 3216440, 1160, NUITKA_BYTECODE_FLAG },
    { "lib2to3.pytree", NULL, 3217600, 24965, NUITKA_BYTECODE_FLAG },
    { "lib2to3.refactor", NULL, 3242565, 20354, NUITKA_BYTECODE_FLAG },
    { "logging", NULL, 3262919, 61457, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "logging.config", NULL, 3324376, 22807, NUITKA_BYTECODE_FLAG },
    { "logging.handlers", NULL, 3347183, 42927, NUITKA_BYTECODE_FLAG },
    { "lzma", NULL, 3390110, 11901, NUITKA_BYTECODE_FLAG },
    { "macpath", NULL, 3402011, 5769, NUITKA_BYTECODE_FLAG },
    { "mailbox", NULL, 3407780, 63610, NUITKA_BYTECODE_FLAG },
    { "mailcap", NULL, 3471390, 6446, NUITKA_BYTECODE_FLAG },
    { "mimetypes", NULL, 3477836, 15430, NUITKA_BYTECODE_FLAG },
    { "modulefinder", NULL, 3493266, 15314, NUITKA_BYTECODE_FLAG },
    { "msilib", NULL, 3508580, 15795, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "msilib.schema", NULL, 3524375, 56931, NUITKA_BYTECODE_FLAG },
    { "msilib.sequence", NULL, 3581306, 2586, NUITKA_BYTECODE_FLAG },
    { "msilib.text", NULL, 3583892, 8943, NUITKA_BYTECODE_FLAG },
    { "multiprocessing", NULL, 3592835, 489, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "multiprocessing.connection", NULL, 3593324, 24873, NUITKA_BYTECODE_FLAG },
    { "multiprocessing.context", NULL, 3618197, 13075, NUITKA_BYTECODE_FLAG },
    { "multiprocessing.dummy", NULL, 3631272, 3767, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "multiprocessing.dummy.connection", NULL, 3635039, 2475, NUITKA_BYTECODE_FLAG },
    { "multiprocessing.forkserver", NULL, 3637514, 7726, NUITKA_BYTECODE_FLAG },
    { "multiprocessing.heap", NULL, 3645240, 6386, NUITKA_BYTECODE_FLAG },
    { "multiprocessing.managers", NULL, 3651626, 33956, NUITKA_BYTECODE_FLAG },
    { "multiprocessing.pool", NULL, 3685582, 21198, NUITKA_BYTECODE_FLAG },
    { "multiprocessing.popen_spawn_win32", NULL, 3706780, 2883, NUITKA_BYTECODE_FLAG },
    { "multiprocessing.process", NULL, 3709663, 9388, NUITKA_BYTECODE_FLAG },
    { "multiprocessing.queues", NULL, 3719051, 9388, NUITKA_BYTECODE_FLAG },
    { "multiprocessing.reduction", NULL, 3728439, 7973, NUITKA_BYTECODE_FLAG },
    { "multiprocessing.resource_sharer", NULL, 3736412, 5165, NUITKA_BYTECODE_FLAG },
    { "multiprocessing.semaphore_tracker", NULL, 3741577, 3702, NUITKA_BYTECODE_FLAG },
    { "multiprocessing.sharedctypes", NULL, 3745279, 6879, NUITKA_BYTECODE_FLAG },
    { "multiprocessing.spawn", NULL, 3752158, 6440, NUITKA_BYTECODE_FLAG },
    { "multiprocessing.synchronize", NULL, 3758598, 11148, NUITKA_BYTECODE_FLAG },
    { "multiprocessing.util", NULL, 3769746, 9909, NUITKA_BYTECODE_FLAG },
    { "netrc", NULL, 3779655, 3725, NUITKA_BYTECODE_FLAG },
    { "nntplib", NULL, 3783380, 33713, NUITKA_BYTECODE_FLAG },
    { "nturl2path", NULL, 3817093, 1577, NUITKA_BYTECODE_FLAG },
    { "numbers", NULL, 3818670, 12154, NUITKA_BYTECODE_FLAG },
    { "optparse", NULL, 3830824, 47855, NUITKA_BYTECODE_FLAG },
    { "pathlib", NULL, 3878679, 41219, NUITKA_BYTECODE_FLAG },
    { "pdb", NULL, 3919898, 46724, NUITKA_BYTECODE_FLAG },
    { "pickle", NULL, 3966622, 42928, NUITKA_BYTECODE_FLAG },
    { "pickletools", NULL, 4009550, 65319, NUITKA_BYTECODE_FLAG },
    { "pipes", NULL, 4074869, 7765, NUITKA_BYTECODE_FLAG },
    { "pkgutil", NULL, 4082634, 16322, NUITKA_BYTECODE_FLAG },
    { "platform", NULL, 4098956, 27536, NUITKA_BYTECODE_FLAG },
    { "plistlib", NULL, 4126492, 25057, NUITKA_BYTECODE_FLAG },
    { "poplib", NULL, 4151549, 13297, NUITKA_BYTECODE_FLAG },
    { "posixpath", NULL, 4164846, 10393, NUITKA_BYTECODE_FLAG },
    { "pprint", NULL, 4175239, 15781, NUITKA_BYTECODE_FLAG },
    { "profile", NULL, 4191020, 13803, NUITKA_BYTECODE_FLAG },
    { "pstats", NULL, 4204823, 22256, NUITKA_BYTECODE_FLAG },
    { "py_compile", NULL, 4227079, 6992, NUITKA_BYTECODE_FLAG },
    { "pyclbr", NULL, 4234071, 10335, NUITKA_BYTECODE_FLAG },
    { "pydoc", NULL, 4244406, 84385, NUITKA_BYTECODE_FLAG },
    { "pydoc_data", NULL, 4328791, 108, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "pydoc_data.topics", NULL, 4328899, 411358, NUITKA_BYTECODE_FLAG },
    { "queue", NULL, 4740257, 11434, NUITKA_BYTECODE_FLAG },
    { "random", NULL, 4751691, 19353, NUITKA_BYTECODE_FLAG },
    { "rlcompleter", NULL, 4771044, 5744, NUITKA_BYTECODE_FLAG },
    { "runpy", NULL, 4776788, 7907, NUITKA_BYTECODE_FLAG },
    { "sched", NULL, 4784695, 6483, NUITKA_BYTECODE_FLAG },
    { "secrets", NULL, 4791178, 2146, NUITKA_BYTECODE_FLAG },
    { "selectors", NULL, 4793324, 16910, NUITKA_BYTECODE_FLAG },
    { "shelve", NULL, 4810234, 9468, NUITKA_BYTECODE_FLAG },
    { "shlex", NULL, 4819702, 6952, NUITKA_BYTECODE_FLAG },
    { "shutil", NULL, 4826654, 30542, NUITKA_BYTECODE_FLAG },
    { "signal", NULL, 4857196, 2474, NUITKA_BYTECODE_FLAG },
    { "site", NULL, 4859670, 17464, NUITKA_BYTECODE_FLAG },
    { "smtpd", NULL, 4877134, 26566, NUITKA_BYTECODE_FLAG },
    { "smtplib", NULL, 4903700, 35268, NUITKA_BYTECODE_FLAG },
    { "sndhdr", NULL, 4938968, 6865, NUITKA_BYTECODE_FLAG },
    { "socket", NULL, 4945833, 21983, NUITKA_BYTECODE_FLAG },
    { "socketserver", NULL, 4967816, 24148, NUITKA_BYTECODE_FLAG },
    { "sqlite3", NULL, 4991964, 136, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "sqlite3.dbapi2", NULL, 4992100, 2455, NUITKA_BYTECODE_FLAG },
    { "sqlite3.dump", NULL, 4994555, 1898, NUITKA_BYTECODE_FLAG },
    { "ssl", NULL, 4996453, 39366, NUITKA_BYTECODE_FLAG },
    { "statistics", NULL, 5035819, 18126, NUITKA_BYTECODE_FLAG },
    { "string", NULL, 5053945, 7797, NUITKA_BYTECODE_FLAG },
    { "subprocess", NULL, 5061742, 38341, NUITKA_BYTECODE_FLAG },
    { "sunau", NULL, 5100083, 17173, NUITKA_BYTECODE_FLAG },
    { "symbol", NULL, 5117256, 2527, NUITKA_BYTECODE_FLAG },
    { "symtable", NULL, 5119783, 10407, NUITKA_BYTECODE_FLAG },
    { "sysconfig", NULL, 5130190, 15236, NUITKA_BYTECODE_FLAG },
    { "tabnanny", NULL, 5145426, 6940, NUITKA_BYTECODE_FLAG },
    { "tarfile", NULL, 5152366, 61782, NUITKA_BYTECODE_FLAG },
    { "telnetlib", NULL, 5214148, 18064, NUITKA_BYTECODE_FLAG },
    { "tempfile", NULL, 5232212, 22142, NUITKA_BYTECODE_FLAG },
    { "textwrap", NULL, 5254354, 13574, NUITKA_BYTECODE_FLAG },
    { "this", NULL, 5267928, 1239, NUITKA_BYTECODE_FLAG },
    { "timeit", NULL, 5269167, 11609, NUITKA_BYTECODE_FLAG },
    { "tkinter", NULL, 5280776, 179115, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "tkinter.colorchooser", NULL, 5459891, 1097, NUITKA_BYTECODE_FLAG },
    { "tkinter.commondialog", NULL, 5460988, 1078, NUITKA_BYTECODE_FLAG },
    { "tkinter.constants", NULL, 5462066, 1630, NUITKA_BYTECODE_FLAG },
    { "tkinter.dialog", NULL, 5463696, 1406, NUITKA_BYTECODE_FLAG },
    { "tkinter.dnd", NULL, 5465102, 11148, NUITKA_BYTECODE_FLAG },
    { "tkinter.filedialog", NULL, 5476250, 12232, NUITKA_BYTECODE_FLAG },
    { "tkinter.font", NULL, 5488482, 6149, NUITKA_BYTECODE_FLAG },
    { "tkinter.messagebox", NULL, 5494631, 3014, NUITKA_BYTECODE_FLAG },
    { "tkinter.scrolledtext", NULL, 5497645, 2141, NUITKA_BYTECODE_FLAG },
    { "tkinter.simpledialog", NULL, 5499786, 10508, NUITKA_BYTECODE_FLAG },
    { "tkinter.tix", NULL, 5510294, 83628, NUITKA_BYTECODE_FLAG },
    { "tkinter.ttk", NULL, 5593922, 57812, NUITKA_BYTECODE_FLAG },
    { "trace", NULL, 5651734, 19342, NUITKA_BYTECODE_FLAG },
    { "tracemalloc", NULL, 5671076, 17238, NUITKA_BYTECODE_FLAG },
    { "turtle", NULL, 5688314, 130753, NUITKA_BYTECODE_FLAG },
    { "typing", NULL, 5819067, 49890, NUITKA_BYTECODE_FLAG },
    { "unittest", NULL, 5868957, 2973, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "unittest.case", NULL, 5871930, 48035, NUITKA_BYTECODE_FLAG },
    { "unittest.loader", NULL, 5919965, 14231, NUITKA_BYTECODE_FLAG },
    { "unittest.main", NULL, 5934196, 7400, NUITKA_BYTECODE_FLAG },
    { "unittest.mock", NULL, 5941596, 62784, NUITKA_BYTECODE_FLAG },
    { "unittest.result", NULL, 6004380, 7214, NUITKA_BYTECODE_FLAG },
    { "unittest.runner", NULL, 6011594, 6943, NUITKA_BYTECODE_FLAG },
    { "unittest.signals", NULL, 6018537, 2156, NUITKA_BYTECODE_FLAG },
    { "unittest.suite", NULL, 6020693, 9165, NUITKA_BYTECODE_FLAG },
    { "unittest.util", NULL, 6029858, 4483, NUITKA_BYTECODE_FLAG },
    { "urllib", NULL, 6034341, 104, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "urllib.error", NULL, 6034445, 2738, NUITKA_BYTECODE_FLAG },
    { "urllib.parse", NULL, 6037183, 29581, NUITKA_BYTECODE_FLAG },
    { "urllib.request", NULL, 6066764, 72265, NUITKA_BYTECODE_FLAG },
    { "urllib.response", NULL, 6139029, 3211, NUITKA_BYTECODE_FLAG },
    { "urllib.robotparser", NULL, 6142240, 7023, NUITKA_BYTECODE_FLAG },
    { "uu", NULL, 6149263, 3575, NUITKA_BYTECODE_FLAG },
    { "uuid", NULL, 6152838, 22761, NUITKA_BYTECODE_FLAG },
    { "venv", NULL, 6175599, 13590, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "wave", NULL, 6189189, 18250, NUITKA_BYTECODE_FLAG },
    { "weakref", NULL, 6207439, 19107, NUITKA_BYTECODE_FLAG },
    { "webbrowser", NULL, 6226546, 16396, NUITKA_BYTECODE_FLAG },
    { "wsgiref", NULL, 6242942, 700, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "wsgiref.handlers", NULL, 6243642, 16109, NUITKA_BYTECODE_FLAG },
    { "wsgiref.headers", NULL, 6259751, 7721, NUITKA_BYTECODE_FLAG },
    { "wsgiref.simple_server", NULL, 6267472, 5167, NUITKA_BYTECODE_FLAG },
    { "wsgiref.util", NULL, 6272639, 5142, NUITKA_BYTECODE_FLAG },
    { "wsgiref.validate", NULL, 6277781, 14638, NUITKA_BYTECODE_FLAG },
    { "xdrlib", NULL, 6292419, 8286, NUITKA_BYTECODE_FLAG },
    { "xml", NULL, 6300705, 668, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "xml.dom", NULL, 6301373, 5420, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "xml.dom.NodeFilter", NULL, 6306793, 935, NUITKA_BYTECODE_FLAG },
    { "xml.dom.domreg", NULL, 6307728, 2752, NUITKA_BYTECODE_FLAG },
    { "xml.dom.expatbuilder", NULL, 6310480, 26982, NUITKA_BYTECODE_FLAG },
    { "xml.dom.minicompat", NULL, 6337462, 2781, NUITKA_BYTECODE_FLAG },
    { "xml.dom.minidom", NULL, 6340243, 55581, NUITKA_BYTECODE_FLAG },
    { "xml.dom.pulldom", NULL, 6395824, 10454, NUITKA_BYTECODE_FLAG },
    { "xml.dom.xmlbuilder", NULL, 6406278, 12401, NUITKA_BYTECODE_FLAG },
    { "xml.etree", NULL, 6418679, 107, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "xml.etree.ElementInclude", NULL, 6418786, 1543, NUITKA_BYTECODE_FLAG },
    { "xml.etree.ElementPath", NULL, 6420329, 6311, NUITKA_BYTECODE_FLAG },
    { "xml.etree.ElementTree", NULL, 6426640, 44775, NUITKA_BYTECODE_FLAG },
    { "xml.etree.cElementTree", NULL, 6471415, 149, NUITKA_BYTECODE_FLAG },
    { "xml.parsers", NULL, 6471564, 281, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "xml.parsers.expat", NULL, 6471845, 310, NUITKA_BYTECODE_FLAG },
    { "xml.sax", NULL, 6472155, 3105, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "xml.sax._exceptions", NULL, 6475260, 5449, NUITKA_BYTECODE_FLAG },
    { "xml.sax.expatreader", NULL, 6480709, 12357, NUITKA_BYTECODE_FLAG },
    { "xml.sax.handler", NULL, 6493066, 12325, NUITKA_BYTECODE_FLAG },
    { "xml.sax.saxutils", NULL, 6505391, 12778, NUITKA_BYTECODE_FLAG },
    { "xml.sax.xmlreader", NULL, 6518169, 16886, NUITKA_BYTECODE_FLAG },
    { "xmlrpc", NULL, 6535055, 104, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "xmlrpc.client", NULL, 6535159, 34510, NUITKA_BYTECODE_FLAG },
    { "xmlrpc.server", NULL, 6569669, 29575, NUITKA_BYTECODE_FLAG },
    { "zipapp", NULL, 6599244, 5765, NUITKA_BYTECODE_FLAG },
    { "zipfile", NULL, 6605009, 49379, NUITKA_BYTECODE_FLAG },
    { NULL, NULL, 0, 0, 0 }
};

void setupMetaPathBasedLoader( void )
{
    static bool init_done = false;

    if ( init_done == false )
    {
        registerMetaPathBasedUnfreezer( meta_path_loader_entries );
        init_done = true;
    }
}
