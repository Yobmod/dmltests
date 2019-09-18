/* Generated code for Python source for module 'pygame.surfarray'
 * created by Nuitka version 0.6.0.3
 *
 * This code is in part copyright 2018 Kay Hayen.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "nuitka/prelude.h"

#include "__helpers.h"

/* The _module_pygame$surfarray is a Python object pointer of module type. */

/* Note: For full compatibility with CPython, every module variable access
 * needs to go through it except for cases where the module cannot possibly
 * have changed in the mean time.
 */

PyObject *module_pygame$surfarray;
PyDictObject *moduledict_pygame$surfarray;

/* The module constants used, if any. */
extern PyObject *const_str_digest_b010b74deac075981c5003854bdfd1a6;
static PyObject *const_str_digest_64ba1d9daa9a21b88fa9c020389c39a5;
extern PyObject *const_str_plain_array2d;
extern PyObject *const_str_digest_7b06e36aa54006877c6dbd4046f3d7da;
extern PyObject *const_str_plain_array_colorkey;
extern PyObject *const_tuple_str_plain_surface_tuple;
static PyObject *const_str_plain_numpysf;
static PyObject *const_str_digest_f5fb89ef9cbc2e38324e94c947589e7f;
extern PyObject *const_str_plain_pixels_red;
extern PyObject *const_str_plain_make_surface;
extern PyObject *const_str_plain_get_arraytypes;
extern PyObject *const_tuple_str_plain_surface_str_plain_array_tuple;
extern PyObject *const_str_plain_numpy;
extern PyObject *const_str_plain_array;
extern PyObject *const_str_plain___file__;
static PyObject *const_str_digest_844be27206d42c980bbf45effffc54d0;
extern PyObject *const_str_digest_e420c3319159a1e6d3a583b2fbaf6bd0;
static PyObject *const_str_digest_f62791549a87bf84dc2e9770b515c976;
extern PyObject *const_str_digest_be0c58c5fcf712145ccaf4e61ea24ef9;
extern PyObject *const_int_0;
extern PyObject *const_str_plain_pixels2d;
extern PyObject *const_str_plain_array_alpha;
static PyObject *const_str_digest_6f59b8e61555e52228c092be946919db;
static PyObject *const_str_digest_f47e5181f8ff99bd781fe5fff92946cd;
extern PyObject *const_str_plain_pixels_alpha;
static PyObject *const_str_digest_c92c95c39b2cf9b2e24921a1f3c63ddc;
extern PyObject *const_str_plain___doc__;
extern PyObject *const_str_plain_arraytype;
static PyObject *const_str_digest_a0402477ac8af52e8662ff2140c23920;
extern PyObject *const_str_plain_array3d;
static PyObject *const_str_plain__numpysurfarray;
static PyObject *const_str_plain_pc_make_surface;
static PyObject *const_str_digest_8ca8da321043894061b54c5cea0460be;
extern PyObject *const_str_plain_use_arraytype;
static PyObject *const_str_digest_ebf86469c0fa5f0970063f5a149aec8b;
static PyObject *const_str_digest_1ac1d405f1bb3292837d70f7b383c1b5;
static PyObject *const_str_digest_234bd90e4f9b032503f52634992c6616;
extern PyObject *const_tuple_empty;
extern PyObject *const_str_plain_pixels_green;
extern PyObject *const_tuple_str_plain_arraytype_tuple;
extern PyObject *const_str_plain_get_arraytype;
extern PyObject *const_str_plain_pixels3d;
extern PyObject *const_str_plain_map_array;
static PyObject *const_str_digest_d70c9c687dcc59de67a45493a9d8f05b;
static PyObject *const_tuple_str_plain_array_to_surface_str_plain_make_surface_tuple;
extern PyObject *const_str_digest_d174e39ef12748481d2d13702313aa6c;
extern PyObject *const_str_plain_blit_array;
extern PyObject *const_str_plain_pixels_blue;
extern PyObject *const_str_plain_array_to_surface;
static PyObject *const_str_digest_b80073d3143f23dee8fe8f20cfbaa10a;
extern PyObject *const_tuple_str_plain_array_tuple;
static PyObject *const_str_digest_6ac266e5293ca92b654b8df41d5c990c;
extern PyObject *const_str_plain_surface;
static PyObject *const_str_digest_e7d9148c038f14a4d743a7ebc269c709;
extern PyObject *const_tuple_str_plain_numpy_tuple;
extern PyObject *const_str_plain___cached__;
extern PyObject *const_str_digest_390dcb68817636bbd0641245b5f96e70;
extern PyObject *const_str_plain_lower;
static PyObject *const_str_digest_4a7809fd9a8eca656ef67a591dca6116;
static PyObject *module_filename_obj;

static bool constants_created = false;

static void createModuleConstants( void )
{
    const_str_digest_64ba1d9daa9a21b88fa9c020389c39a5 = UNSTREAM_STRING( &constant_bin[ 73187 ], 422, 0 );
    const_str_plain_numpysf = UNSTREAM_STRING( &constant_bin[ 73609 ], 7, 1 );
    const_str_digest_f5fb89ef9cbc2e38324e94c947589e7f = UNSTREAM_STRING( &constant_bin[ 73616 ], 478, 0 );
    const_str_digest_844be27206d42c980bbf45effffc54d0 = UNSTREAM_STRING( &constant_bin[ 74094 ], 581, 0 );
    const_str_digest_f62791549a87bf84dc2e9770b515c976 = UNSTREAM_STRING( &constant_bin[ 74675 ], 261, 0 );
    const_str_digest_6f59b8e61555e52228c092be946919db = UNSTREAM_STRING( &constant_bin[ 74936 ], 451, 0 );
    const_str_digest_f47e5181f8ff99bd781fe5fff92946cd = UNSTREAM_STRING( &constant_bin[ 75387 ], 422, 0 );
    const_str_digest_c92c95c39b2cf9b2e24921a1f3c63ddc = UNSTREAM_STRING( &constant_bin[ 75809 ], 503, 0 );
    const_str_digest_a0402477ac8af52e8662ff2140c23920 = UNSTREAM_STRING( &constant_bin[ 76312 ], 105, 0 );
    const_str_plain__numpysurfarray = UNSTREAM_STRING( &constant_bin[ 8978 ], 15, 1 );
    const_str_plain_pc_make_surface = UNSTREAM_STRING( &constant_bin[ 76417 ], 15, 1 );
    const_str_digest_8ca8da321043894061b54c5cea0460be = UNSTREAM_STRING( &constant_bin[ 76432 ], 493, 0 );
    const_str_digest_ebf86469c0fa5f0970063f5a149aec8b = UNSTREAM_STRING( &constant_bin[ 76925 ], 564, 0 );
    const_str_digest_1ac1d405f1bb3292837d70f7b383c1b5 = UNSTREAM_STRING( &constant_bin[ 77489 ], 448, 0 );
    const_str_digest_234bd90e4f9b032503f52634992c6616 = UNSTREAM_STRING( &constant_bin[ 77937 ], 108, 0 );
    const_str_digest_d70c9c687dcc59de67a45493a9d8f05b = UNSTREAM_STRING( &constant_bin[ 78045 ], 454, 0 );
    const_tuple_str_plain_array_to_surface_str_plain_make_surface_tuple = PyTuple_New( 2 );
    PyTuple_SET_ITEM( const_tuple_str_plain_array_to_surface_str_plain_make_surface_tuple, 0, const_str_plain_array_to_surface ); Py_INCREF( const_str_plain_array_to_surface );
    PyTuple_SET_ITEM( const_tuple_str_plain_array_to_surface_str_plain_make_surface_tuple, 1, const_str_plain_make_surface ); Py_INCREF( const_str_plain_make_surface );
    const_str_digest_b80073d3143f23dee8fe8f20cfbaa10a = UNSTREAM_STRING( &constant_bin[ 78499 ], 1766, 0 );
    const_str_digest_6ac266e5293ca92b654b8df41d5c990c = UNSTREAM_STRING( &constant_bin[ 80265 ], 25, 0 );
    const_str_digest_e7d9148c038f14a4d743a7ebc269c709 = UNSTREAM_STRING( &constant_bin[ 80290 ], 83, 0 );
    const_str_digest_4a7809fd9a8eca656ef67a591dca6116 = UNSTREAM_STRING( &constant_bin[ 80373 ], 115, 0 );

    constants_created = true;
}

#ifndef __NUITKA_NO_ASSERT__
void checkModuleConstants_pygame$surfarray( void )
{
    // The module may not have been used at all.
    if (constants_created == false) return;


}
#endif

// The module code objects.
static PyCodeObject *codeobj_a3fa1e2ffd1f1ed02d04d999e0ffedef;
static PyCodeObject *codeobj_a464259c76bad626f05125f9795b517e;
static PyCodeObject *codeobj_86b8590f1e9c3500c1c998ab54033a0d;
static PyCodeObject *codeobj_6ad94c3dcaae1d69441b6cc8d24523d0;
static PyCodeObject *codeobj_4e08ff20991cf0ef1947d0fb59c67c14;
static PyCodeObject *codeobj_ef7a6007beb77a7b4a84f226cf8d4e80;
static PyCodeObject *codeobj_75666833fcb6cd762771f4291c739d83;
static PyCodeObject *codeobj_31aee54930432c9353839843daf51ff8;
static PyCodeObject *codeobj_366e09b8b35f1a6e294dda7e1d08c22a;
static PyCodeObject *codeobj_6292c829e978558e5715e82c7ef284fe;
static PyCodeObject *codeobj_59862c546439e91b4925a076a28ff026;
static PyCodeObject *codeobj_055d8778bfc74345d855452a5cb7e0aa;
static PyCodeObject *codeobj_ab27c7c14fc06287d5e3ea38c0c549c0;
static PyCodeObject *codeobj_0afb19d095572143270fdb9c59c61639;
static PyCodeObject *codeobj_b7c936f7e2db2b9c6067d91d4fcf9af7;
static PyCodeObject *codeobj_b60ed5b95dac8b10895da61c20ad1028;
static PyCodeObject *codeobj_bbb6f3c9a10033b300b0fe9de42d78b7;

static void createModuleCodeObjects(void)
{
    module_filename_obj = const_str_digest_e7d9148c038f14a4d743a7ebc269c709;
    codeobj_a3fa1e2ffd1f1ed02d04d999e0ffedef = MAKE_CODEOBJ( module_filename_obj, const_str_digest_6ac266e5293ca92b654b8df41d5c990c, 1, const_tuple_empty, 0, 0, CO_NOFREE );
    codeobj_a464259c76bad626f05125f9795b517e = MAKE_CODEOBJ( module_filename_obj, const_str_plain_array2d, 83, const_tuple_str_plain_surface_tuple, 1, 0, CO_OPTIMIZED | CO_NEWLOCALS | CO_NOFREE );
    codeobj_86b8590f1e9c3500c1c998ab54033a0d = MAKE_CODEOBJ( module_filename_obj, const_str_plain_array3d, 116, const_tuple_str_plain_surface_tuple, 1, 0, CO_OPTIMIZED | CO_NEWLOCALS | CO_NOFREE );
    codeobj_6ad94c3dcaae1d69441b6cc8d24523d0 = MAKE_CODEOBJ( module_filename_obj, const_str_plain_array_alpha, 149, const_tuple_str_plain_surface_tuple, 1, 0, CO_OPTIMIZED | CO_NEWLOCALS | CO_NOFREE );
    codeobj_4e08ff20991cf0ef1947d0fb59c67c14 = MAKE_CODEOBJ( module_filename_obj, const_str_plain_array_colorkey, 230, const_tuple_str_plain_surface_tuple, 1, 0, CO_OPTIMIZED | CO_NEWLOCALS | CO_NOFREE );
    codeobj_ef7a6007beb77a7b4a84f226cf8d4e80 = MAKE_CODEOBJ( module_filename_obj, const_str_plain_blit_array, 68, const_tuple_str_plain_surface_str_plain_array_tuple, 2, 0, CO_OPTIMIZED | CO_NEWLOCALS | CO_NOFREE );
    codeobj_75666833fcb6cd762771f4291c739d83 = MAKE_CODEOBJ( module_filename_obj, const_str_plain_get_arraytype, 277, const_tuple_empty, 0, 0, CO_OPTIMIZED | CO_NEWLOCALS | CO_NOFREE );
    codeobj_31aee54930432c9353839843daf51ff8 = MAKE_CODEOBJ( module_filename_obj, const_str_plain_get_arraytypes, 284, const_tuple_empty, 0, 0, CO_OPTIMIZED | CO_NEWLOCALS | CO_NOFREE );
    codeobj_366e09b8b35f1a6e294dda7e1d08c22a = MAKE_CODEOBJ( module_filename_obj, const_str_plain_make_surface, 247, const_tuple_str_plain_array_tuple, 1, 0, CO_OPTIMIZED | CO_NEWLOCALS | CO_NOFREE );
    codeobj_6292c829e978558e5715e82c7ef284fe = MAKE_CODEOBJ( module_filename_obj, const_str_plain_map_array, 257, const_tuple_str_plain_surface_str_plain_array_tuple, 2, 0, CO_OPTIMIZED | CO_NEWLOCALS | CO_NOFREE );
    codeobj_59862c546439e91b4925a076a28ff026 = MAKE_CODEOBJ( module_filename_obj, const_str_plain_pixels2d, 98, const_tuple_str_plain_surface_tuple, 1, 0, CO_OPTIMIZED | CO_NEWLOCALS | CO_NOFREE );
    codeobj_055d8778bfc74345d855452a5cb7e0aa = MAKE_CODEOBJ( module_filename_obj, const_str_plain_pixels3d, 131, const_tuple_str_plain_surface_tuple, 1, 0, CO_OPTIMIZED | CO_NEWLOCALS | CO_NOFREE );
    codeobj_ab27c7c14fc06287d5e3ea38c0c549c0 = MAKE_CODEOBJ( module_filename_obj, const_str_plain_pixels_alpha, 165, const_tuple_str_plain_surface_tuple, 1, 0, CO_OPTIMIZED | CO_NEWLOCALS | CO_NOFREE );
    codeobj_0afb19d095572143270fdb9c59c61639 = MAKE_CODEOBJ( module_filename_obj, const_str_plain_pixels_blue, 214, const_tuple_str_plain_surface_tuple, 1, 0, CO_OPTIMIZED | CO_NEWLOCALS | CO_NOFREE );
    codeobj_b7c936f7e2db2b9c6067d91d4fcf9af7 = MAKE_CODEOBJ( module_filename_obj, const_str_plain_pixels_green, 198, const_tuple_str_plain_surface_tuple, 1, 0, CO_OPTIMIZED | CO_NEWLOCALS | CO_NOFREE );
    codeobj_b60ed5b95dac8b10895da61c20ad1028 = MAKE_CODEOBJ( module_filename_obj, const_str_plain_pixels_red, 182, const_tuple_str_plain_surface_tuple, 1, 0, CO_OPTIMIZED | CO_NEWLOCALS | CO_NOFREE );
    codeobj_bbb6f3c9a10033b300b0fe9de42d78b7 = MAKE_CODEOBJ( module_filename_obj, const_str_plain_use_arraytype, 268, const_tuple_str_plain_arraytype_tuple, 1, 0, CO_OPTIMIZED | CO_NEWLOCALS | CO_NOFREE );
}

// The module function declarations.
static PyObject *MAKE_FUNCTION_pygame$surfarray$$$function_10_pixels_blue(  );


static PyObject *MAKE_FUNCTION_pygame$surfarray$$$function_11_array_colorkey(  );


static PyObject *MAKE_FUNCTION_pygame$surfarray$$$function_12_make_surface(  );


static PyObject *MAKE_FUNCTION_pygame$surfarray$$$function_13_map_array(  );


static PyObject *MAKE_FUNCTION_pygame$surfarray$$$function_14_use_arraytype(  );


static PyObject *MAKE_FUNCTION_pygame$surfarray$$$function_15_get_arraytype(  );


static PyObject *MAKE_FUNCTION_pygame$surfarray$$$function_16_get_arraytypes(  );


static PyObject *MAKE_FUNCTION_pygame$surfarray$$$function_1_blit_array(  );


static PyObject *MAKE_FUNCTION_pygame$surfarray$$$function_2_array2d(  );


static PyObject *MAKE_FUNCTION_pygame$surfarray$$$function_3_pixels2d(  );


static PyObject *MAKE_FUNCTION_pygame$surfarray$$$function_4_array3d(  );


static PyObject *MAKE_FUNCTION_pygame$surfarray$$$function_5_pixels3d(  );


static PyObject *MAKE_FUNCTION_pygame$surfarray$$$function_6_array_alpha(  );


static PyObject *MAKE_FUNCTION_pygame$surfarray$$$function_7_pixels_alpha(  );


static PyObject *MAKE_FUNCTION_pygame$surfarray$$$function_8_pixels_red(  );


static PyObject *MAKE_FUNCTION_pygame$surfarray$$$function_9_pixels_green(  );


// The module function definitions.
static PyObject *impl_pygame$surfarray$$$function_1_blit_array( struct Nuitka_FunctionObject const *self, PyObject **python_pars )
{
    // Preserve error status for checks
#ifndef __NUITKA_NO_ASSERT__
    NUITKA_MAY_BE_UNUSED bool had_error = ERROR_OCCURRED();
#endif

    // Local variable declarations.
    PyObject *par_surface = python_pars[ 0 ];
    PyObject *par_array = python_pars[ 1 ];
    struct Nuitka_FrameObject *frame_ef7a6007beb77a7b4a84f226cf8d4e80;
    NUITKA_MAY_BE_UNUSED char const *type_description_1 = NULL;
    PyObject *tmp_return_value = NULL;
    PyObject *exception_type = NULL;
    PyObject *exception_value = NULL;
    PyTracebackObject *exception_tb = NULL;
    NUITKA_MAY_BE_UNUSED int exception_lineno = 0;
    static struct Nuitka_FrameObject *cache_frame_ef7a6007beb77a7b4a84f226cf8d4e80 = NULL;
    PyObject *exception_keeper_type_1;
    PyObject *exception_keeper_value_1;
    PyTracebackObject *exception_keeper_tb_1;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_1;

    // Actual function code.
    {
    // Tried code:
    MAKE_OR_REUSE_FRAME( cache_frame_ef7a6007beb77a7b4a84f226cf8d4e80, codeobj_ef7a6007beb77a7b4a84f226cf8d4e80, module_pygame$surfarray, sizeof(void *)+sizeof(void *) );
    frame_ef7a6007beb77a7b4a84f226cf8d4e80 = cache_frame_ef7a6007beb77a7b4a84f226cf8d4e80;

    // Push the new frame as the currently active one.
    pushFrameStack( frame_ef7a6007beb77a7b4a84f226cf8d4e80 );

    // Mark the frame object as in use, ref count 1 will be up for reuse.
    assert( Py_REFCNT( frame_ef7a6007beb77a7b4a84f226cf8d4e80 ) == 2 ); // Frame stack

    // Framed code:
    {
    PyObject *tmp_called_name_1;
    PyObject *tmp_source_name_1;
    PyObject *tmp_mvar_value_1;
    PyObject *tmp_args_element_name_1;
    PyObject *tmp_args_element_name_2;
    tmp_mvar_value_1 = GET_STRING_DICT_VALUE( moduledict_pygame$surfarray, (Nuitka_StringObject *)const_str_plain_numpysf );

    if (unlikely( tmp_mvar_value_1 == NULL ))
    {
        tmp_mvar_value_1 = GET_STRING_DICT_VALUE( dict_builtin, (Nuitka_StringObject *)const_str_plain_numpysf );
    }

    if ( tmp_mvar_value_1 == NULL )
    {

        exception_type = PyExc_NameError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "name '%s' is not defined", "numpysf" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 81;
        type_description_1 = "oo";
        goto frame_exception_exit_1;
    }

    tmp_source_name_1 = tmp_mvar_value_1;
    tmp_called_name_1 = LOOKUP_ATTRIBUTE( tmp_source_name_1, const_str_plain_blit_array );
    if ( tmp_called_name_1 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 81;
        type_description_1 = "oo";
        goto frame_exception_exit_1;
    }
    if ( par_surface == NULL )
    {
        Py_DECREF( tmp_called_name_1 );
        exception_type = PyExc_UnboundLocalError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "local variable '%s' referenced before assignment", "surface" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 81;
        type_description_1 = "oo";
        goto frame_exception_exit_1;
    }

    tmp_args_element_name_1 = par_surface;
    if ( par_array == NULL )
    {
        Py_DECREF( tmp_called_name_1 );
        exception_type = PyExc_UnboundLocalError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "local variable '%s' referenced before assignment", "array" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 81;
        type_description_1 = "oo";
        goto frame_exception_exit_1;
    }

    tmp_args_element_name_2 = par_array;
    frame_ef7a6007beb77a7b4a84f226cf8d4e80->m_frame.f_lineno = 81;
    {
        PyObject *call_args[] = { tmp_args_element_name_1, tmp_args_element_name_2 };
        tmp_return_value = CALL_FUNCTION_WITH_ARGS2( tmp_called_name_1, call_args );
    }

    Py_DECREF( tmp_called_name_1 );
    if ( tmp_return_value == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 81;
        type_description_1 = "oo";
        goto frame_exception_exit_1;
    }
    goto frame_return_exit_1;
    }

#if 0
    RESTORE_FRAME_EXCEPTION( frame_ef7a6007beb77a7b4a84f226cf8d4e80 );
#endif

    // Put the previous frame back on top.
    popFrameStack();

    goto frame_no_exception_1;

    frame_return_exit_1:;
#if 0
    RESTORE_FRAME_EXCEPTION( frame_ef7a6007beb77a7b4a84f226cf8d4e80 );
#endif

    // Put the previous frame back on top.
    popFrameStack();

    goto try_return_handler_1;

    frame_exception_exit_1:;

#if 0
    RESTORE_FRAME_EXCEPTION( frame_ef7a6007beb77a7b4a84f226cf8d4e80 );
#endif

    if ( exception_tb == NULL )
    {
        exception_tb = MAKE_TRACEBACK( frame_ef7a6007beb77a7b4a84f226cf8d4e80, exception_lineno );
    }
    else if ( exception_tb->tb_frame != &frame_ef7a6007beb77a7b4a84f226cf8d4e80->m_frame )
    {
        exception_tb = ADD_TRACEBACK( exception_tb, frame_ef7a6007beb77a7b4a84f226cf8d4e80, exception_lineno );
    }

    // Attachs locals to frame if any.
    Nuitka_Frame_AttachLocals(
        (struct Nuitka_FrameObject *)frame_ef7a6007beb77a7b4a84f226cf8d4e80,
        type_description_1,
        par_surface,
        par_array
    );


    // Release cached frame.
    if ( frame_ef7a6007beb77a7b4a84f226cf8d4e80 == cache_frame_ef7a6007beb77a7b4a84f226cf8d4e80 )
    {
        Py_DECREF( frame_ef7a6007beb77a7b4a84f226cf8d4e80 );
    }
    cache_frame_ef7a6007beb77a7b4a84f226cf8d4e80 = NULL;

    assertFrameObject( frame_ef7a6007beb77a7b4a84f226cf8d4e80 );

    // Put the previous frame back on top.
    popFrameStack();

    // Return the error.
    goto try_except_handler_1;

    frame_no_exception_1:;
    // tried codes exits in all cases
    NUITKA_CANNOT_GET_HERE( pygame$surfarray$$$function_1_blit_array );
    return NULL;
    // Return handler code:
    try_return_handler_1:;
    {
    Py_XDECREF( par_surface );
    par_surface = NULL;

    }
    {
    Py_XDECREF( par_array );
    par_array = NULL;

    }
    {
    goto function_return_exit;
    }
    // Exception handler code:
    try_except_handler_1:;
    exception_keeper_type_1 = exception_type;
    exception_keeper_value_1 = exception_value;
    exception_keeper_tb_1 = exception_tb;
    exception_keeper_lineno_1 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = 0;

    {
    Py_XDECREF( par_surface );
    par_surface = NULL;

    }
    {
    Py_XDECREF( par_array );
    par_array = NULL;

    }
    {
    // Re-raise.
    exception_type = exception_keeper_type_1;
    exception_value = exception_keeper_value_1;
    exception_tb = exception_keeper_tb_1;
    exception_lineno = exception_keeper_lineno_1;

    goto function_exception_exit;
    }
    // End of try:
    }

    // Return statement must have exited already.
    NUITKA_CANNOT_GET_HERE( pygame$surfarray$$$function_1_blit_array );
    return NULL;

function_exception_exit:
    assert( exception_type );
    RESTORE_ERROR_OCCURRED( exception_type, exception_value, exception_tb );

    return NULL;
function_return_exit:

CHECK_OBJECT( tmp_return_value );
assert( had_error || !ERROR_OCCURRED() );
return tmp_return_value;

}


static PyObject *impl_pygame$surfarray$$$function_2_array2d( struct Nuitka_FunctionObject const *self, PyObject **python_pars )
{
    // Preserve error status for checks
#ifndef __NUITKA_NO_ASSERT__
    NUITKA_MAY_BE_UNUSED bool had_error = ERROR_OCCURRED();
#endif

    // Local variable declarations.
    PyObject *par_surface = python_pars[ 0 ];
    struct Nuitka_FrameObject *frame_a464259c76bad626f05125f9795b517e;
    NUITKA_MAY_BE_UNUSED char const *type_description_1 = NULL;
    PyObject *tmp_return_value = NULL;
    PyObject *exception_type = NULL;
    PyObject *exception_value = NULL;
    PyTracebackObject *exception_tb = NULL;
    NUITKA_MAY_BE_UNUSED int exception_lineno = 0;
    static struct Nuitka_FrameObject *cache_frame_a464259c76bad626f05125f9795b517e = NULL;
    PyObject *exception_keeper_type_1;
    PyObject *exception_keeper_value_1;
    PyTracebackObject *exception_keeper_tb_1;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_1;

    // Actual function code.
    {
    // Tried code:
    MAKE_OR_REUSE_FRAME( cache_frame_a464259c76bad626f05125f9795b517e, codeobj_a464259c76bad626f05125f9795b517e, module_pygame$surfarray, sizeof(void *) );
    frame_a464259c76bad626f05125f9795b517e = cache_frame_a464259c76bad626f05125f9795b517e;

    // Push the new frame as the currently active one.
    pushFrameStack( frame_a464259c76bad626f05125f9795b517e );

    // Mark the frame object as in use, ref count 1 will be up for reuse.
    assert( Py_REFCNT( frame_a464259c76bad626f05125f9795b517e ) == 2 ); // Frame stack

    // Framed code:
    {
    PyObject *tmp_called_name_1;
    PyObject *tmp_source_name_1;
    PyObject *tmp_mvar_value_1;
    PyObject *tmp_args_element_name_1;
    tmp_mvar_value_1 = GET_STRING_DICT_VALUE( moduledict_pygame$surfarray, (Nuitka_StringObject *)const_str_plain_numpysf );

    if (unlikely( tmp_mvar_value_1 == NULL ))
    {
        tmp_mvar_value_1 = GET_STRING_DICT_VALUE( dict_builtin, (Nuitka_StringObject *)const_str_plain_numpysf );
    }

    if ( tmp_mvar_value_1 == NULL )
    {

        exception_type = PyExc_NameError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "name '%s' is not defined", "numpysf" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 96;
        type_description_1 = "o";
        goto frame_exception_exit_1;
    }

    tmp_source_name_1 = tmp_mvar_value_1;
    tmp_called_name_1 = LOOKUP_ATTRIBUTE( tmp_source_name_1, const_str_plain_array2d );
    if ( tmp_called_name_1 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 96;
        type_description_1 = "o";
        goto frame_exception_exit_1;
    }
    if ( par_surface == NULL )
    {
        Py_DECREF( tmp_called_name_1 );
        exception_type = PyExc_UnboundLocalError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "local variable '%s' referenced before assignment", "surface" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 96;
        type_description_1 = "o";
        goto frame_exception_exit_1;
    }

    tmp_args_element_name_1 = par_surface;
    frame_a464259c76bad626f05125f9795b517e->m_frame.f_lineno = 96;
    {
        PyObject *call_args[] = { tmp_args_element_name_1 };
        tmp_return_value = CALL_FUNCTION_WITH_ARGS1( tmp_called_name_1, call_args );
    }

    Py_DECREF( tmp_called_name_1 );
    if ( tmp_return_value == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 96;
        type_description_1 = "o";
        goto frame_exception_exit_1;
    }
    goto frame_return_exit_1;
    }

#if 0
    RESTORE_FRAME_EXCEPTION( frame_a464259c76bad626f05125f9795b517e );
#endif

    // Put the previous frame back on top.
    popFrameStack();

    goto frame_no_exception_1;

    frame_return_exit_1:;
#if 0
    RESTORE_FRAME_EXCEPTION( frame_a464259c76bad626f05125f9795b517e );
#endif

    // Put the previous frame back on top.
    popFrameStack();

    goto try_return_handler_1;

    frame_exception_exit_1:;

#if 0
    RESTORE_FRAME_EXCEPTION( frame_a464259c76bad626f05125f9795b517e );
#endif

    if ( exception_tb == NULL )
    {
        exception_tb = MAKE_TRACEBACK( frame_a464259c76bad626f05125f9795b517e, exception_lineno );
    }
    else if ( exception_tb->tb_frame != &frame_a464259c76bad626f05125f9795b517e->m_frame )
    {
        exception_tb = ADD_TRACEBACK( exception_tb, frame_a464259c76bad626f05125f9795b517e, exception_lineno );
    }

    // Attachs locals to frame if any.
    Nuitka_Frame_AttachLocals(
        (struct Nuitka_FrameObject *)frame_a464259c76bad626f05125f9795b517e,
        type_description_1,
        par_surface
    );


    // Release cached frame.
    if ( frame_a464259c76bad626f05125f9795b517e == cache_frame_a464259c76bad626f05125f9795b517e )
    {
        Py_DECREF( frame_a464259c76bad626f05125f9795b517e );
    }
    cache_frame_a464259c76bad626f05125f9795b517e = NULL;

    assertFrameObject( frame_a464259c76bad626f05125f9795b517e );

    // Put the previous frame back on top.
    popFrameStack();

    // Return the error.
    goto try_except_handler_1;

    frame_no_exception_1:;
    // tried codes exits in all cases
    NUITKA_CANNOT_GET_HERE( pygame$surfarray$$$function_2_array2d );
    return NULL;
    // Return handler code:
    try_return_handler_1:;
    {
    Py_XDECREF( par_surface );
    par_surface = NULL;

    }
    {
    goto function_return_exit;
    }
    // Exception handler code:
    try_except_handler_1:;
    exception_keeper_type_1 = exception_type;
    exception_keeper_value_1 = exception_value;
    exception_keeper_tb_1 = exception_tb;
    exception_keeper_lineno_1 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = 0;

    {
    Py_XDECREF( par_surface );
    par_surface = NULL;

    }
    {
    // Re-raise.
    exception_type = exception_keeper_type_1;
    exception_value = exception_keeper_value_1;
    exception_tb = exception_keeper_tb_1;
    exception_lineno = exception_keeper_lineno_1;

    goto function_exception_exit;
    }
    // End of try:
    }

    // Return statement must have exited already.
    NUITKA_CANNOT_GET_HERE( pygame$surfarray$$$function_2_array2d );
    return NULL;

function_exception_exit:
    assert( exception_type );
    RESTORE_ERROR_OCCURRED( exception_type, exception_value, exception_tb );

    return NULL;
function_return_exit:

CHECK_OBJECT( tmp_return_value );
assert( had_error || !ERROR_OCCURRED() );
return tmp_return_value;

}


static PyObject *impl_pygame$surfarray$$$function_3_pixels2d( struct Nuitka_FunctionObject const *self, PyObject **python_pars )
{
    // Preserve error status for checks
#ifndef __NUITKA_NO_ASSERT__
    NUITKA_MAY_BE_UNUSED bool had_error = ERROR_OCCURRED();
#endif

    // Local variable declarations.
    PyObject *par_surface = python_pars[ 0 ];
    struct Nuitka_FrameObject *frame_59862c546439e91b4925a076a28ff026;
    NUITKA_MAY_BE_UNUSED char const *type_description_1 = NULL;
    PyObject *tmp_return_value = NULL;
    PyObject *exception_type = NULL;
    PyObject *exception_value = NULL;
    PyTracebackObject *exception_tb = NULL;
    NUITKA_MAY_BE_UNUSED int exception_lineno = 0;
    static struct Nuitka_FrameObject *cache_frame_59862c546439e91b4925a076a28ff026 = NULL;
    PyObject *exception_keeper_type_1;
    PyObject *exception_keeper_value_1;
    PyTracebackObject *exception_keeper_tb_1;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_1;

    // Actual function code.
    {
    // Tried code:
    MAKE_OR_REUSE_FRAME( cache_frame_59862c546439e91b4925a076a28ff026, codeobj_59862c546439e91b4925a076a28ff026, module_pygame$surfarray, sizeof(void *) );
    frame_59862c546439e91b4925a076a28ff026 = cache_frame_59862c546439e91b4925a076a28ff026;

    // Push the new frame as the currently active one.
    pushFrameStack( frame_59862c546439e91b4925a076a28ff026 );

    // Mark the frame object as in use, ref count 1 will be up for reuse.
    assert( Py_REFCNT( frame_59862c546439e91b4925a076a28ff026 ) == 2 ); // Frame stack

    // Framed code:
    {
    PyObject *tmp_called_name_1;
    PyObject *tmp_source_name_1;
    PyObject *tmp_mvar_value_1;
    PyObject *tmp_args_element_name_1;
    tmp_mvar_value_1 = GET_STRING_DICT_VALUE( moduledict_pygame$surfarray, (Nuitka_StringObject *)const_str_plain_numpysf );

    if (unlikely( tmp_mvar_value_1 == NULL ))
    {
        tmp_mvar_value_1 = GET_STRING_DICT_VALUE( dict_builtin, (Nuitka_StringObject *)const_str_plain_numpysf );
    }

    if ( tmp_mvar_value_1 == NULL )
    {

        exception_type = PyExc_NameError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "name '%s' is not defined", "numpysf" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 114;
        type_description_1 = "o";
        goto frame_exception_exit_1;
    }

    tmp_source_name_1 = tmp_mvar_value_1;
    tmp_called_name_1 = LOOKUP_ATTRIBUTE( tmp_source_name_1, const_str_plain_pixels2d );
    if ( tmp_called_name_1 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 114;
        type_description_1 = "o";
        goto frame_exception_exit_1;
    }
    if ( par_surface == NULL )
    {
        Py_DECREF( tmp_called_name_1 );
        exception_type = PyExc_UnboundLocalError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "local variable '%s' referenced before assignment", "surface" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 114;
        type_description_1 = "o";
        goto frame_exception_exit_1;
    }

    tmp_args_element_name_1 = par_surface;
    frame_59862c546439e91b4925a076a28ff026->m_frame.f_lineno = 114;
    {
        PyObject *call_args[] = { tmp_args_element_name_1 };
        tmp_return_value = CALL_FUNCTION_WITH_ARGS1( tmp_called_name_1, call_args );
    }

    Py_DECREF( tmp_called_name_1 );
    if ( tmp_return_value == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 114;
        type_description_1 = "o";
        goto frame_exception_exit_1;
    }
    goto frame_return_exit_1;
    }

#if 0
    RESTORE_FRAME_EXCEPTION( frame_59862c546439e91b4925a076a28ff026 );
#endif

    // Put the previous frame back on top.
    popFrameStack();

    goto frame_no_exception_1;

    frame_return_exit_1:;
#if 0
    RESTORE_FRAME_EXCEPTION( frame_59862c546439e91b4925a076a28ff026 );
#endif

    // Put the previous frame back on top.
    popFrameStack();

    goto try_return_handler_1;

    frame_exception_exit_1:;

#if 0
    RESTORE_FRAME_EXCEPTION( frame_59862c546439e91b4925a076a28ff026 );
#endif

    if ( exception_tb == NULL )
    {
        exception_tb = MAKE_TRACEBACK( frame_59862c546439e91b4925a076a28ff026, exception_lineno );
    }
    else if ( exception_tb->tb_frame != &frame_59862c546439e91b4925a076a28ff026->m_frame )
    {
        exception_tb = ADD_TRACEBACK( exception_tb, frame_59862c546439e91b4925a076a28ff026, exception_lineno );
    }

    // Attachs locals to frame if any.
    Nuitka_Frame_AttachLocals(
        (struct Nuitka_FrameObject *)frame_59862c546439e91b4925a076a28ff026,
        type_description_1,
        par_surface
    );


    // Release cached frame.
    if ( frame_59862c546439e91b4925a076a28ff026 == cache_frame_59862c546439e91b4925a076a28ff026 )
    {
        Py_DECREF( frame_59862c546439e91b4925a076a28ff026 );
    }
    cache_frame_59862c546439e91b4925a076a28ff026 = NULL;

    assertFrameObject( frame_59862c546439e91b4925a076a28ff026 );

    // Put the previous frame back on top.
    popFrameStack();

    // Return the error.
    goto try_except_handler_1;

    frame_no_exception_1:;
    // tried codes exits in all cases
    NUITKA_CANNOT_GET_HERE( pygame$surfarray$$$function_3_pixels2d );
    return NULL;
    // Return handler code:
    try_return_handler_1:;
    {
    Py_XDECREF( par_surface );
    par_surface = NULL;

    }
    {
    goto function_return_exit;
    }
    // Exception handler code:
    try_except_handler_1:;
    exception_keeper_type_1 = exception_type;
    exception_keeper_value_1 = exception_value;
    exception_keeper_tb_1 = exception_tb;
    exception_keeper_lineno_1 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = 0;

    {
    Py_XDECREF( par_surface );
    par_surface = NULL;

    }
    {
    // Re-raise.
    exception_type = exception_keeper_type_1;
    exception_value = exception_keeper_value_1;
    exception_tb = exception_keeper_tb_1;
    exception_lineno = exception_keeper_lineno_1;

    goto function_exception_exit;
    }
    // End of try:
    }

    // Return statement must have exited already.
    NUITKA_CANNOT_GET_HERE( pygame$surfarray$$$function_3_pixels2d );
    return NULL;

function_exception_exit:
    assert( exception_type );
    RESTORE_ERROR_OCCURRED( exception_type, exception_value, exception_tb );

    return NULL;
function_return_exit:

CHECK_OBJECT( tmp_return_value );
assert( had_error || !ERROR_OCCURRED() );
return tmp_return_value;

}


static PyObject *impl_pygame$surfarray$$$function_4_array3d( struct Nuitka_FunctionObject const *self, PyObject **python_pars )
{
    // Preserve error status for checks
#ifndef __NUITKA_NO_ASSERT__
    NUITKA_MAY_BE_UNUSED bool had_error = ERROR_OCCURRED();
#endif

    // Local variable declarations.
    PyObject *par_surface = python_pars[ 0 ];
    struct Nuitka_FrameObject *frame_86b8590f1e9c3500c1c998ab54033a0d;
    NUITKA_MAY_BE_UNUSED char const *type_description_1 = NULL;
    PyObject *tmp_return_value = NULL;
    PyObject *exception_type = NULL;
    PyObject *exception_value = NULL;
    PyTracebackObject *exception_tb = NULL;
    NUITKA_MAY_BE_UNUSED int exception_lineno = 0;
    static struct Nuitka_FrameObject *cache_frame_86b8590f1e9c3500c1c998ab54033a0d = NULL;
    PyObject *exception_keeper_type_1;
    PyObject *exception_keeper_value_1;
    PyTracebackObject *exception_keeper_tb_1;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_1;

    // Actual function code.
    {
    // Tried code:
    MAKE_OR_REUSE_FRAME( cache_frame_86b8590f1e9c3500c1c998ab54033a0d, codeobj_86b8590f1e9c3500c1c998ab54033a0d, module_pygame$surfarray, sizeof(void *) );
    frame_86b8590f1e9c3500c1c998ab54033a0d = cache_frame_86b8590f1e9c3500c1c998ab54033a0d;

    // Push the new frame as the currently active one.
    pushFrameStack( frame_86b8590f1e9c3500c1c998ab54033a0d );

    // Mark the frame object as in use, ref count 1 will be up for reuse.
    assert( Py_REFCNT( frame_86b8590f1e9c3500c1c998ab54033a0d ) == 2 ); // Frame stack

    // Framed code:
    {
    PyObject *tmp_called_name_1;
    PyObject *tmp_source_name_1;
    PyObject *tmp_mvar_value_1;
    PyObject *tmp_args_element_name_1;
    tmp_mvar_value_1 = GET_STRING_DICT_VALUE( moduledict_pygame$surfarray, (Nuitka_StringObject *)const_str_plain_numpysf );

    if (unlikely( tmp_mvar_value_1 == NULL ))
    {
        tmp_mvar_value_1 = GET_STRING_DICT_VALUE( dict_builtin, (Nuitka_StringObject *)const_str_plain_numpysf );
    }

    if ( tmp_mvar_value_1 == NULL )
    {

        exception_type = PyExc_NameError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "name '%s' is not defined", "numpysf" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 129;
        type_description_1 = "o";
        goto frame_exception_exit_1;
    }

    tmp_source_name_1 = tmp_mvar_value_1;
    tmp_called_name_1 = LOOKUP_ATTRIBUTE( tmp_source_name_1, const_str_plain_array3d );
    if ( tmp_called_name_1 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 129;
        type_description_1 = "o";
        goto frame_exception_exit_1;
    }
    if ( par_surface == NULL )
    {
        Py_DECREF( tmp_called_name_1 );
        exception_type = PyExc_UnboundLocalError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "local variable '%s' referenced before assignment", "surface" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 129;
        type_description_1 = "o";
        goto frame_exception_exit_1;
    }

    tmp_args_element_name_1 = par_surface;
    frame_86b8590f1e9c3500c1c998ab54033a0d->m_frame.f_lineno = 129;
    {
        PyObject *call_args[] = { tmp_args_element_name_1 };
        tmp_return_value = CALL_FUNCTION_WITH_ARGS1( tmp_called_name_1, call_args );
    }

    Py_DECREF( tmp_called_name_1 );
    if ( tmp_return_value == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 129;
        type_description_1 = "o";
        goto frame_exception_exit_1;
    }
    goto frame_return_exit_1;
    }

#if 0
    RESTORE_FRAME_EXCEPTION( frame_86b8590f1e9c3500c1c998ab54033a0d );
#endif

    // Put the previous frame back on top.
    popFrameStack();

    goto frame_no_exception_1;

    frame_return_exit_1:;
#if 0
    RESTORE_FRAME_EXCEPTION( frame_86b8590f1e9c3500c1c998ab54033a0d );
#endif

    // Put the previous frame back on top.
    popFrameStack();

    goto try_return_handler_1;

    frame_exception_exit_1:;

#if 0
    RESTORE_FRAME_EXCEPTION( frame_86b8590f1e9c3500c1c998ab54033a0d );
#endif

    if ( exception_tb == NULL )
    {
        exception_tb = MAKE_TRACEBACK( frame_86b8590f1e9c3500c1c998ab54033a0d, exception_lineno );
    }
    else if ( exception_tb->tb_frame != &frame_86b8590f1e9c3500c1c998ab54033a0d->m_frame )
    {
        exception_tb = ADD_TRACEBACK( exception_tb, frame_86b8590f1e9c3500c1c998ab54033a0d, exception_lineno );
    }

    // Attachs locals to frame if any.
    Nuitka_Frame_AttachLocals(
        (struct Nuitka_FrameObject *)frame_86b8590f1e9c3500c1c998ab54033a0d,
        type_description_1,
        par_surface
    );


    // Release cached frame.
    if ( frame_86b8590f1e9c3500c1c998ab54033a0d == cache_frame_86b8590f1e9c3500c1c998ab54033a0d )
    {
        Py_DECREF( frame_86b8590f1e9c3500c1c998ab54033a0d );
    }
    cache_frame_86b8590f1e9c3500c1c998ab54033a0d = NULL;

    assertFrameObject( frame_86b8590f1e9c3500c1c998ab54033a0d );

    // Put the previous frame back on top.
    popFrameStack();

    // Return the error.
    goto try_except_handler_1;

    frame_no_exception_1:;
    // tried codes exits in all cases
    NUITKA_CANNOT_GET_HERE( pygame$surfarray$$$function_4_array3d );
    return NULL;
    // Return handler code:
    try_return_handler_1:;
    {
    Py_XDECREF( par_surface );
    par_surface = NULL;

    }
    {
    goto function_return_exit;
    }
    // Exception handler code:
    try_except_handler_1:;
    exception_keeper_type_1 = exception_type;
    exception_keeper_value_1 = exception_value;
    exception_keeper_tb_1 = exception_tb;
    exception_keeper_lineno_1 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = 0;

    {
    Py_XDECREF( par_surface );
    par_surface = NULL;

    }
    {
    // Re-raise.
    exception_type = exception_keeper_type_1;
    exception_value = exception_keeper_value_1;
    exception_tb = exception_keeper_tb_1;
    exception_lineno = exception_keeper_lineno_1;

    goto function_exception_exit;
    }
    // End of try:
    }

    // Return statement must have exited already.
    NUITKA_CANNOT_GET_HERE( pygame$surfarray$$$function_4_array3d );
    return NULL;

function_exception_exit:
    assert( exception_type );
    RESTORE_ERROR_OCCURRED( exception_type, exception_value, exception_tb );

    return NULL;
function_return_exit:

CHECK_OBJECT( tmp_return_value );
assert( had_error || !ERROR_OCCURRED() );
return tmp_return_value;

}


static PyObject *impl_pygame$surfarray$$$function_5_pixels3d( struct Nuitka_FunctionObject const *self, PyObject **python_pars )
{
    // Preserve error status for checks
#ifndef __NUITKA_NO_ASSERT__
    NUITKA_MAY_BE_UNUSED bool had_error = ERROR_OCCURRED();
#endif

    // Local variable declarations.
    PyObject *par_surface = python_pars[ 0 ];
    struct Nuitka_FrameObject *frame_055d8778bfc74345d855452a5cb7e0aa;
    NUITKA_MAY_BE_UNUSED char const *type_description_1 = NULL;
    PyObject *tmp_return_value = NULL;
    PyObject *exception_type = NULL;
    PyObject *exception_value = NULL;
    PyTracebackObject *exception_tb = NULL;
    NUITKA_MAY_BE_UNUSED int exception_lineno = 0;
    static struct Nuitka_FrameObject *cache_frame_055d8778bfc74345d855452a5cb7e0aa = NULL;
    PyObject *exception_keeper_type_1;
    PyObject *exception_keeper_value_1;
    PyTracebackObject *exception_keeper_tb_1;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_1;

    // Actual function code.
    {
    // Tried code:
    MAKE_OR_REUSE_FRAME( cache_frame_055d8778bfc74345d855452a5cb7e0aa, codeobj_055d8778bfc74345d855452a5cb7e0aa, module_pygame$surfarray, sizeof(void *) );
    frame_055d8778bfc74345d855452a5cb7e0aa = cache_frame_055d8778bfc74345d855452a5cb7e0aa;

    // Push the new frame as the currently active one.
    pushFrameStack( frame_055d8778bfc74345d855452a5cb7e0aa );

    // Mark the frame object as in use, ref count 1 will be up for reuse.
    assert( Py_REFCNT( frame_055d8778bfc74345d855452a5cb7e0aa ) == 2 ); // Frame stack

    // Framed code:
    {
    PyObject *tmp_called_name_1;
    PyObject *tmp_source_name_1;
    PyObject *tmp_mvar_value_1;
    PyObject *tmp_args_element_name_1;
    tmp_mvar_value_1 = GET_STRING_DICT_VALUE( moduledict_pygame$surfarray, (Nuitka_StringObject *)const_str_plain_numpysf );

    if (unlikely( tmp_mvar_value_1 == NULL ))
    {
        tmp_mvar_value_1 = GET_STRING_DICT_VALUE( dict_builtin, (Nuitka_StringObject *)const_str_plain_numpysf );
    }

    if ( tmp_mvar_value_1 == NULL )
    {

        exception_type = PyExc_NameError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "name '%s' is not defined", "numpysf" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 147;
        type_description_1 = "o";
        goto frame_exception_exit_1;
    }

    tmp_source_name_1 = tmp_mvar_value_1;
    tmp_called_name_1 = LOOKUP_ATTRIBUTE( tmp_source_name_1, const_str_plain_pixels3d );
    if ( tmp_called_name_1 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 147;
        type_description_1 = "o";
        goto frame_exception_exit_1;
    }
    if ( par_surface == NULL )
    {
        Py_DECREF( tmp_called_name_1 );
        exception_type = PyExc_UnboundLocalError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "local variable '%s' referenced before assignment", "surface" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 147;
        type_description_1 = "o";
        goto frame_exception_exit_1;
    }

    tmp_args_element_name_1 = par_surface;
    frame_055d8778bfc74345d855452a5cb7e0aa->m_frame.f_lineno = 147;
    {
        PyObject *call_args[] = { tmp_args_element_name_1 };
        tmp_return_value = CALL_FUNCTION_WITH_ARGS1( tmp_called_name_1, call_args );
    }

    Py_DECREF( tmp_called_name_1 );
    if ( tmp_return_value == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 147;
        type_description_1 = "o";
        goto frame_exception_exit_1;
    }
    goto frame_return_exit_1;
    }

#if 0
    RESTORE_FRAME_EXCEPTION( frame_055d8778bfc74345d855452a5cb7e0aa );
#endif

    // Put the previous frame back on top.
    popFrameStack();

    goto frame_no_exception_1;

    frame_return_exit_1:;
#if 0
    RESTORE_FRAME_EXCEPTION( frame_055d8778bfc74345d855452a5cb7e0aa );
#endif

    // Put the previous frame back on top.
    popFrameStack();

    goto try_return_handler_1;

    frame_exception_exit_1:;

#if 0
    RESTORE_FRAME_EXCEPTION( frame_055d8778bfc74345d855452a5cb7e0aa );
#endif

    if ( exception_tb == NULL )
    {
        exception_tb = MAKE_TRACEBACK( frame_055d8778bfc74345d855452a5cb7e0aa, exception_lineno );
    }
    else if ( exception_tb->tb_frame != &frame_055d8778bfc74345d855452a5cb7e0aa->m_frame )
    {
        exception_tb = ADD_TRACEBACK( exception_tb, frame_055d8778bfc74345d855452a5cb7e0aa, exception_lineno );
    }

    // Attachs locals to frame if any.
    Nuitka_Frame_AttachLocals(
        (struct Nuitka_FrameObject *)frame_055d8778bfc74345d855452a5cb7e0aa,
        type_description_1,
        par_surface
    );


    // Release cached frame.
    if ( frame_055d8778bfc74345d855452a5cb7e0aa == cache_frame_055d8778bfc74345d855452a5cb7e0aa )
    {
        Py_DECREF( frame_055d8778bfc74345d855452a5cb7e0aa );
    }
    cache_frame_055d8778bfc74345d855452a5cb7e0aa = NULL;

    assertFrameObject( frame_055d8778bfc74345d855452a5cb7e0aa );

    // Put the previous frame back on top.
    popFrameStack();

    // Return the error.
    goto try_except_handler_1;

    frame_no_exception_1:;
    // tried codes exits in all cases
    NUITKA_CANNOT_GET_HERE( pygame$surfarray$$$function_5_pixels3d );
    return NULL;
    // Return handler code:
    try_return_handler_1:;
    {
    Py_XDECREF( par_surface );
    par_surface = NULL;

    }
    {
    goto function_return_exit;
    }
    // Exception handler code:
    try_except_handler_1:;
    exception_keeper_type_1 = exception_type;
    exception_keeper_value_1 = exception_value;
    exception_keeper_tb_1 = exception_tb;
    exception_keeper_lineno_1 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = 0;

    {
    Py_XDECREF( par_surface );
    par_surface = NULL;

    }
    {
    // Re-raise.
    exception_type = exception_keeper_type_1;
    exception_value = exception_keeper_value_1;
    exception_tb = exception_keeper_tb_1;
    exception_lineno = exception_keeper_lineno_1;

    goto function_exception_exit;
    }
    // End of try:
    }

    // Return statement must have exited already.
    NUITKA_CANNOT_GET_HERE( pygame$surfarray$$$function_5_pixels3d );
    return NULL;

function_exception_exit:
    assert( exception_type );
    RESTORE_ERROR_OCCURRED( exception_type, exception_value, exception_tb );

    return NULL;
function_return_exit:

CHECK_OBJECT( tmp_return_value );
assert( had_error || !ERROR_OCCURRED() );
return tmp_return_value;

}


static PyObject *impl_pygame$surfarray$$$function_6_array_alpha( struct Nuitka_FunctionObject const *self, PyObject **python_pars )
{
    // Preserve error status for checks
#ifndef __NUITKA_NO_ASSERT__
    NUITKA_MAY_BE_UNUSED bool had_error = ERROR_OCCURRED();
#endif

    // Local variable declarations.
    PyObject *par_surface = python_pars[ 0 ];
    struct Nuitka_FrameObject *frame_6ad94c3dcaae1d69441b6cc8d24523d0;
    NUITKA_MAY_BE_UNUSED char const *type_description_1 = NULL;
    PyObject *tmp_return_value = NULL;
    PyObject *exception_type = NULL;
    PyObject *exception_value = NULL;
    PyTracebackObject *exception_tb = NULL;
    NUITKA_MAY_BE_UNUSED int exception_lineno = 0;
    static struct Nuitka_FrameObject *cache_frame_6ad94c3dcaae1d69441b6cc8d24523d0 = NULL;
    PyObject *exception_keeper_type_1;
    PyObject *exception_keeper_value_1;
    PyTracebackObject *exception_keeper_tb_1;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_1;

    // Actual function code.
    {
    // Tried code:
    MAKE_OR_REUSE_FRAME( cache_frame_6ad94c3dcaae1d69441b6cc8d24523d0, codeobj_6ad94c3dcaae1d69441b6cc8d24523d0, module_pygame$surfarray, sizeof(void *) );
    frame_6ad94c3dcaae1d69441b6cc8d24523d0 = cache_frame_6ad94c3dcaae1d69441b6cc8d24523d0;

    // Push the new frame as the currently active one.
    pushFrameStack( frame_6ad94c3dcaae1d69441b6cc8d24523d0 );

    // Mark the frame object as in use, ref count 1 will be up for reuse.
    assert( Py_REFCNT( frame_6ad94c3dcaae1d69441b6cc8d24523d0 ) == 2 ); // Frame stack

    // Framed code:
    {
    PyObject *tmp_called_name_1;
    PyObject *tmp_source_name_1;
    PyObject *tmp_mvar_value_1;
    PyObject *tmp_args_element_name_1;
    tmp_mvar_value_1 = GET_STRING_DICT_VALUE( moduledict_pygame$surfarray, (Nuitka_StringObject *)const_str_plain_numpysf );

    if (unlikely( tmp_mvar_value_1 == NULL ))
    {
        tmp_mvar_value_1 = GET_STRING_DICT_VALUE( dict_builtin, (Nuitka_StringObject *)const_str_plain_numpysf );
    }

    if ( tmp_mvar_value_1 == NULL )
    {

        exception_type = PyExc_NameError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "name '%s' is not defined", "numpysf" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 163;
        type_description_1 = "o";
        goto frame_exception_exit_1;
    }

    tmp_source_name_1 = tmp_mvar_value_1;
    tmp_called_name_1 = LOOKUP_ATTRIBUTE( tmp_source_name_1, const_str_plain_array_alpha );
    if ( tmp_called_name_1 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 163;
        type_description_1 = "o";
        goto frame_exception_exit_1;
    }
    if ( par_surface == NULL )
    {
        Py_DECREF( tmp_called_name_1 );
        exception_type = PyExc_UnboundLocalError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "local variable '%s' referenced before assignment", "surface" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 163;
        type_description_1 = "o";
        goto frame_exception_exit_1;
    }

    tmp_args_element_name_1 = par_surface;
    frame_6ad94c3dcaae1d69441b6cc8d24523d0->m_frame.f_lineno = 163;
    {
        PyObject *call_args[] = { tmp_args_element_name_1 };
        tmp_return_value = CALL_FUNCTION_WITH_ARGS1( tmp_called_name_1, call_args );
    }

    Py_DECREF( tmp_called_name_1 );
    if ( tmp_return_value == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 163;
        type_description_1 = "o";
        goto frame_exception_exit_1;
    }
    goto frame_return_exit_1;
    }

#if 0
    RESTORE_FRAME_EXCEPTION( frame_6ad94c3dcaae1d69441b6cc8d24523d0 );
#endif

    // Put the previous frame back on top.
    popFrameStack();

    goto frame_no_exception_1;

    frame_return_exit_1:;
#if 0
    RESTORE_FRAME_EXCEPTION( frame_6ad94c3dcaae1d69441b6cc8d24523d0 );
#endif

    // Put the previous frame back on top.
    popFrameStack();

    goto try_return_handler_1;

    frame_exception_exit_1:;

#if 0
    RESTORE_FRAME_EXCEPTION( frame_6ad94c3dcaae1d69441b6cc8d24523d0 );
#endif

    if ( exception_tb == NULL )
    {
        exception_tb = MAKE_TRACEBACK( frame_6ad94c3dcaae1d69441b6cc8d24523d0, exception_lineno );
    }
    else if ( exception_tb->tb_frame != &frame_6ad94c3dcaae1d69441b6cc8d24523d0->m_frame )
    {
        exception_tb = ADD_TRACEBACK( exception_tb, frame_6ad94c3dcaae1d69441b6cc8d24523d0, exception_lineno );
    }

    // Attachs locals to frame if any.
    Nuitka_Frame_AttachLocals(
        (struct Nuitka_FrameObject *)frame_6ad94c3dcaae1d69441b6cc8d24523d0,
        type_description_1,
        par_surface
    );


    // Release cached frame.
    if ( frame_6ad94c3dcaae1d69441b6cc8d24523d0 == cache_frame_6ad94c3dcaae1d69441b6cc8d24523d0 )
    {
        Py_DECREF( frame_6ad94c3dcaae1d69441b6cc8d24523d0 );
    }
    cache_frame_6ad94c3dcaae1d69441b6cc8d24523d0 = NULL;

    assertFrameObject( frame_6ad94c3dcaae1d69441b6cc8d24523d0 );

    // Put the previous frame back on top.
    popFrameStack();

    // Return the error.
    goto try_except_handler_1;

    frame_no_exception_1:;
    // tried codes exits in all cases
    NUITKA_CANNOT_GET_HERE( pygame$surfarray$$$function_6_array_alpha );
    return NULL;
    // Return handler code:
    try_return_handler_1:;
    {
    Py_XDECREF( par_surface );
    par_surface = NULL;

    }
    {
    goto function_return_exit;
    }
    // Exception handler code:
    try_except_handler_1:;
    exception_keeper_type_1 = exception_type;
    exception_keeper_value_1 = exception_value;
    exception_keeper_tb_1 = exception_tb;
    exception_keeper_lineno_1 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = 0;

    {
    Py_XDECREF( par_surface );
    par_surface = NULL;

    }
    {
    // Re-raise.
    exception_type = exception_keeper_type_1;
    exception_value = exception_keeper_value_1;
    exception_tb = exception_keeper_tb_1;
    exception_lineno = exception_keeper_lineno_1;

    goto function_exception_exit;
    }
    // End of try:
    }

    // Return statement must have exited already.
    NUITKA_CANNOT_GET_HERE( pygame$surfarray$$$function_6_array_alpha );
    return NULL;

function_exception_exit:
    assert( exception_type );
    RESTORE_ERROR_OCCURRED( exception_type, exception_value, exception_tb );

    return NULL;
function_return_exit:

CHECK_OBJECT( tmp_return_value );
assert( had_error || !ERROR_OCCURRED() );
return tmp_return_value;

}


static PyObject *impl_pygame$surfarray$$$function_7_pixels_alpha( struct Nuitka_FunctionObject const *self, PyObject **python_pars )
{
    // Preserve error status for checks
#ifndef __NUITKA_NO_ASSERT__
    NUITKA_MAY_BE_UNUSED bool had_error = ERROR_OCCURRED();
#endif

    // Local variable declarations.
    PyObject *par_surface = python_pars[ 0 ];
    struct Nuitka_FrameObject *frame_ab27c7c14fc06287d5e3ea38c0c549c0;
    NUITKA_MAY_BE_UNUSED char const *type_description_1 = NULL;
    PyObject *tmp_return_value = NULL;
    PyObject *exception_type = NULL;
    PyObject *exception_value = NULL;
    PyTracebackObject *exception_tb = NULL;
    NUITKA_MAY_BE_UNUSED int exception_lineno = 0;
    static struct Nuitka_FrameObject *cache_frame_ab27c7c14fc06287d5e3ea38c0c549c0 = NULL;
    PyObject *exception_keeper_type_1;
    PyObject *exception_keeper_value_1;
    PyTracebackObject *exception_keeper_tb_1;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_1;

    // Actual function code.
    {
    // Tried code:
    MAKE_OR_REUSE_FRAME( cache_frame_ab27c7c14fc06287d5e3ea38c0c549c0, codeobj_ab27c7c14fc06287d5e3ea38c0c549c0, module_pygame$surfarray, sizeof(void *) );
    frame_ab27c7c14fc06287d5e3ea38c0c549c0 = cache_frame_ab27c7c14fc06287d5e3ea38c0c549c0;

    // Push the new frame as the currently active one.
    pushFrameStack( frame_ab27c7c14fc06287d5e3ea38c0c549c0 );

    // Mark the frame object as in use, ref count 1 will be up for reuse.
    assert( Py_REFCNT( frame_ab27c7c14fc06287d5e3ea38c0c549c0 ) == 2 ); // Frame stack

    // Framed code:
    {
    PyObject *tmp_called_name_1;
    PyObject *tmp_source_name_1;
    PyObject *tmp_mvar_value_1;
    PyObject *tmp_args_element_name_1;
    tmp_mvar_value_1 = GET_STRING_DICT_VALUE( moduledict_pygame$surfarray, (Nuitka_StringObject *)const_str_plain_numpysf );

    if (unlikely( tmp_mvar_value_1 == NULL ))
    {
        tmp_mvar_value_1 = GET_STRING_DICT_VALUE( dict_builtin, (Nuitka_StringObject *)const_str_plain_numpysf );
    }

    if ( tmp_mvar_value_1 == NULL )
    {

        exception_type = PyExc_NameError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "name '%s' is not defined", "numpysf" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 180;
        type_description_1 = "o";
        goto frame_exception_exit_1;
    }

    tmp_source_name_1 = tmp_mvar_value_1;
    tmp_called_name_1 = LOOKUP_ATTRIBUTE( tmp_source_name_1, const_str_plain_pixels_alpha );
    if ( tmp_called_name_1 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 180;
        type_description_1 = "o";
        goto frame_exception_exit_1;
    }
    if ( par_surface == NULL )
    {
        Py_DECREF( tmp_called_name_1 );
        exception_type = PyExc_UnboundLocalError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "local variable '%s' referenced before assignment", "surface" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 180;
        type_description_1 = "o";
        goto frame_exception_exit_1;
    }

    tmp_args_element_name_1 = par_surface;
    frame_ab27c7c14fc06287d5e3ea38c0c549c0->m_frame.f_lineno = 180;
    {
        PyObject *call_args[] = { tmp_args_element_name_1 };
        tmp_return_value = CALL_FUNCTION_WITH_ARGS1( tmp_called_name_1, call_args );
    }

    Py_DECREF( tmp_called_name_1 );
    if ( tmp_return_value == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 180;
        type_description_1 = "o";
        goto frame_exception_exit_1;
    }
    goto frame_return_exit_1;
    }

#if 0
    RESTORE_FRAME_EXCEPTION( frame_ab27c7c14fc06287d5e3ea38c0c549c0 );
#endif

    // Put the previous frame back on top.
    popFrameStack();

    goto frame_no_exception_1;

    frame_return_exit_1:;
#if 0
    RESTORE_FRAME_EXCEPTION( frame_ab27c7c14fc06287d5e3ea38c0c549c0 );
#endif

    // Put the previous frame back on top.
    popFrameStack();

    goto try_return_handler_1;

    frame_exception_exit_1:;

#if 0
    RESTORE_FRAME_EXCEPTION( frame_ab27c7c14fc06287d5e3ea38c0c549c0 );
#endif

    if ( exception_tb == NULL )
    {
        exception_tb = MAKE_TRACEBACK( frame_ab27c7c14fc06287d5e3ea38c0c549c0, exception_lineno );
    }
    else if ( exception_tb->tb_frame != &frame_ab27c7c14fc06287d5e3ea38c0c549c0->m_frame )
    {
        exception_tb = ADD_TRACEBACK( exception_tb, frame_ab27c7c14fc06287d5e3ea38c0c549c0, exception_lineno );
    }

    // Attachs locals to frame if any.
    Nuitka_Frame_AttachLocals(
        (struct Nuitka_FrameObject *)frame_ab27c7c14fc06287d5e3ea38c0c549c0,
        type_description_1,
        par_surface
    );


    // Release cached frame.
    if ( frame_ab27c7c14fc06287d5e3ea38c0c549c0 == cache_frame_ab27c7c14fc06287d5e3ea38c0c549c0 )
    {
        Py_DECREF( frame_ab27c7c14fc06287d5e3ea38c0c549c0 );
    }
    cache_frame_ab27c7c14fc06287d5e3ea38c0c549c0 = NULL;

    assertFrameObject( frame_ab27c7c14fc06287d5e3ea38c0c549c0 );

    // Put the previous frame back on top.
    popFrameStack();

    // Return the error.
    goto try_except_handler_1;

    frame_no_exception_1:;
    // tried codes exits in all cases
    NUITKA_CANNOT_GET_HERE( pygame$surfarray$$$function_7_pixels_alpha );
    return NULL;
    // Return handler code:
    try_return_handler_1:;
    {
    Py_XDECREF( par_surface );
    par_surface = NULL;

    }
    {
    goto function_return_exit;
    }
    // Exception handler code:
    try_except_handler_1:;
    exception_keeper_type_1 = exception_type;
    exception_keeper_value_1 = exception_value;
    exception_keeper_tb_1 = exception_tb;
    exception_keeper_lineno_1 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = 0;

    {
    Py_XDECREF( par_surface );
    par_surface = NULL;

    }
    {
    // Re-raise.
    exception_type = exception_keeper_type_1;
    exception_value = exception_keeper_value_1;
    exception_tb = exception_keeper_tb_1;
    exception_lineno = exception_keeper_lineno_1;

    goto function_exception_exit;
    }
    // End of try:
    }

    // Return statement must have exited already.
    NUITKA_CANNOT_GET_HERE( pygame$surfarray$$$function_7_pixels_alpha );
    return NULL;

function_exception_exit:
    assert( exception_type );
    RESTORE_ERROR_OCCURRED( exception_type, exception_value, exception_tb );

    return NULL;
function_return_exit:

CHECK_OBJECT( tmp_return_value );
assert( had_error || !ERROR_OCCURRED() );
return tmp_return_value;

}


static PyObject *impl_pygame$surfarray$$$function_8_pixels_red( struct Nuitka_FunctionObject const *self, PyObject **python_pars )
{
    // Preserve error status for checks
#ifndef __NUITKA_NO_ASSERT__
    NUITKA_MAY_BE_UNUSED bool had_error = ERROR_OCCURRED();
#endif

    // Local variable declarations.
    PyObject *par_surface = python_pars[ 0 ];
    struct Nuitka_FrameObject *frame_b60ed5b95dac8b10895da61c20ad1028;
    NUITKA_MAY_BE_UNUSED char const *type_description_1 = NULL;
    PyObject *tmp_return_value = NULL;
    PyObject *exception_type = NULL;
    PyObject *exception_value = NULL;
    PyTracebackObject *exception_tb = NULL;
    NUITKA_MAY_BE_UNUSED int exception_lineno = 0;
    static struct Nuitka_FrameObject *cache_frame_b60ed5b95dac8b10895da61c20ad1028 = NULL;
    PyObject *exception_keeper_type_1;
    PyObject *exception_keeper_value_1;
    PyTracebackObject *exception_keeper_tb_1;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_1;

    // Actual function code.
    {
    // Tried code:
    MAKE_OR_REUSE_FRAME( cache_frame_b60ed5b95dac8b10895da61c20ad1028, codeobj_b60ed5b95dac8b10895da61c20ad1028, module_pygame$surfarray, sizeof(void *) );
    frame_b60ed5b95dac8b10895da61c20ad1028 = cache_frame_b60ed5b95dac8b10895da61c20ad1028;

    // Push the new frame as the currently active one.
    pushFrameStack( frame_b60ed5b95dac8b10895da61c20ad1028 );

    // Mark the frame object as in use, ref count 1 will be up for reuse.
    assert( Py_REFCNT( frame_b60ed5b95dac8b10895da61c20ad1028 ) == 2 ); // Frame stack

    // Framed code:
    {
    PyObject *tmp_called_name_1;
    PyObject *tmp_source_name_1;
    PyObject *tmp_mvar_value_1;
    PyObject *tmp_args_element_name_1;
    tmp_mvar_value_1 = GET_STRING_DICT_VALUE( moduledict_pygame$surfarray, (Nuitka_StringObject *)const_str_plain_numpysf );

    if (unlikely( tmp_mvar_value_1 == NULL ))
    {
        tmp_mvar_value_1 = GET_STRING_DICT_VALUE( dict_builtin, (Nuitka_StringObject *)const_str_plain_numpysf );
    }

    if ( tmp_mvar_value_1 == NULL )
    {

        exception_type = PyExc_NameError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "name '%s' is not defined", "numpysf" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 196;
        type_description_1 = "o";
        goto frame_exception_exit_1;
    }

    tmp_source_name_1 = tmp_mvar_value_1;
    tmp_called_name_1 = LOOKUP_ATTRIBUTE( tmp_source_name_1, const_str_plain_pixels_red );
    if ( tmp_called_name_1 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 196;
        type_description_1 = "o";
        goto frame_exception_exit_1;
    }
    if ( par_surface == NULL )
    {
        Py_DECREF( tmp_called_name_1 );
        exception_type = PyExc_UnboundLocalError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "local variable '%s' referenced before assignment", "surface" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 196;
        type_description_1 = "o";
        goto frame_exception_exit_1;
    }

    tmp_args_element_name_1 = par_surface;
    frame_b60ed5b95dac8b10895da61c20ad1028->m_frame.f_lineno = 196;
    {
        PyObject *call_args[] = { tmp_args_element_name_1 };
        tmp_return_value = CALL_FUNCTION_WITH_ARGS1( tmp_called_name_1, call_args );
    }

    Py_DECREF( tmp_called_name_1 );
    if ( tmp_return_value == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 196;
        type_description_1 = "o";
        goto frame_exception_exit_1;
    }
    goto frame_return_exit_1;
    }

#if 0
    RESTORE_FRAME_EXCEPTION( frame_b60ed5b95dac8b10895da61c20ad1028 );
#endif

    // Put the previous frame back on top.
    popFrameStack();

    goto frame_no_exception_1;

    frame_return_exit_1:;
#if 0
    RESTORE_FRAME_EXCEPTION( frame_b60ed5b95dac8b10895da61c20ad1028 );
#endif

    // Put the previous frame back on top.
    popFrameStack();

    goto try_return_handler_1;

    frame_exception_exit_1:;

#if 0
    RESTORE_FRAME_EXCEPTION( frame_b60ed5b95dac8b10895da61c20ad1028 );
#endif

    if ( exception_tb == NULL )
    {
        exception_tb = MAKE_TRACEBACK( frame_b60ed5b95dac8b10895da61c20ad1028, exception_lineno );
    }
    else if ( exception_tb->tb_frame != &frame_b60ed5b95dac8b10895da61c20ad1028->m_frame )
    {
        exception_tb = ADD_TRACEBACK( exception_tb, frame_b60ed5b95dac8b10895da61c20ad1028, exception_lineno );
    }

    // Attachs locals to frame if any.
    Nuitka_Frame_AttachLocals(
        (struct Nuitka_FrameObject *)frame_b60ed5b95dac8b10895da61c20ad1028,
        type_description_1,
        par_surface
    );


    // Release cached frame.
    if ( frame_b60ed5b95dac8b10895da61c20ad1028 == cache_frame_b60ed5b95dac8b10895da61c20ad1028 )
    {
        Py_DECREF( frame_b60ed5b95dac8b10895da61c20ad1028 );
    }
    cache_frame_b60ed5b95dac8b10895da61c20ad1028 = NULL;

    assertFrameObject( frame_b60ed5b95dac8b10895da61c20ad1028 );

    // Put the previous frame back on top.
    popFrameStack();

    // Return the error.
    goto try_except_handler_1;

    frame_no_exception_1:;
    // tried codes exits in all cases
    NUITKA_CANNOT_GET_HERE( pygame$surfarray$$$function_8_pixels_red );
    return NULL;
    // Return handler code:
    try_return_handler_1:;
    {
    Py_XDECREF( par_surface );
    par_surface = NULL;

    }
    {
    goto function_return_exit;
    }
    // Exception handler code:
    try_except_handler_1:;
    exception_keeper_type_1 = exception_type;
    exception_keeper_value_1 = exception_value;
    exception_keeper_tb_1 = exception_tb;
    exception_keeper_lineno_1 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = 0;

    {
    Py_XDECREF( par_surface );
    par_surface = NULL;

    }
    {
    // Re-raise.
    exception_type = exception_keeper_type_1;
    exception_value = exception_keeper_value_1;
    exception_tb = exception_keeper_tb_1;
    exception_lineno = exception_keeper_lineno_1;

    goto function_exception_exit;
    }
    // End of try:
    }

    // Return statement must have exited already.
    NUITKA_CANNOT_GET_HERE( pygame$surfarray$$$function_8_pixels_red );
    return NULL;

function_exception_exit:
    assert( exception_type );
    RESTORE_ERROR_OCCURRED( exception_type, exception_value, exception_tb );

    return NULL;
function_return_exit:

CHECK_OBJECT( tmp_return_value );
assert( had_error || !ERROR_OCCURRED() );
return tmp_return_value;

}


static PyObject *impl_pygame$surfarray$$$function_9_pixels_green( struct Nuitka_FunctionObject const *self, PyObject **python_pars )
{
    // Preserve error status for checks
#ifndef __NUITKA_NO_ASSERT__
    NUITKA_MAY_BE_UNUSED bool had_error = ERROR_OCCURRED();
#endif

    // Local variable declarations.
    PyObject *par_surface = python_pars[ 0 ];
    struct Nuitka_FrameObject *frame_b7c936f7e2db2b9c6067d91d4fcf9af7;
    NUITKA_MAY_BE_UNUSED char const *type_description_1 = NULL;
    PyObject *tmp_return_value = NULL;
    PyObject *exception_type = NULL;
    PyObject *exception_value = NULL;
    PyTracebackObject *exception_tb = NULL;
    NUITKA_MAY_BE_UNUSED int exception_lineno = 0;
    static struct Nuitka_FrameObject *cache_frame_b7c936f7e2db2b9c6067d91d4fcf9af7 = NULL;
    PyObject *exception_keeper_type_1;
    PyObject *exception_keeper_value_1;
    PyTracebackObject *exception_keeper_tb_1;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_1;

    // Actual function code.
    {
    // Tried code:
    MAKE_OR_REUSE_FRAME( cache_frame_b7c936f7e2db2b9c6067d91d4fcf9af7, codeobj_b7c936f7e2db2b9c6067d91d4fcf9af7, module_pygame$surfarray, sizeof(void *) );
    frame_b7c936f7e2db2b9c6067d91d4fcf9af7 = cache_frame_b7c936f7e2db2b9c6067d91d4fcf9af7;

    // Push the new frame as the currently active one.
    pushFrameStack( frame_b7c936f7e2db2b9c6067d91d4fcf9af7 );

    // Mark the frame object as in use, ref count 1 will be up for reuse.
    assert( Py_REFCNT( frame_b7c936f7e2db2b9c6067d91d4fcf9af7 ) == 2 ); // Frame stack

    // Framed code:
    {
    PyObject *tmp_called_name_1;
    PyObject *tmp_source_name_1;
    PyObject *tmp_mvar_value_1;
    PyObject *tmp_args_element_name_1;
    tmp_mvar_value_1 = GET_STRING_DICT_VALUE( moduledict_pygame$surfarray, (Nuitka_StringObject *)const_str_plain_numpysf );

    if (unlikely( tmp_mvar_value_1 == NULL ))
    {
        tmp_mvar_value_1 = GET_STRING_DICT_VALUE( dict_builtin, (Nuitka_StringObject *)const_str_plain_numpysf );
    }

    if ( tmp_mvar_value_1 == NULL )
    {

        exception_type = PyExc_NameError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "name '%s' is not defined", "numpysf" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 212;
        type_description_1 = "o";
        goto frame_exception_exit_1;
    }

    tmp_source_name_1 = tmp_mvar_value_1;
    tmp_called_name_1 = LOOKUP_ATTRIBUTE( tmp_source_name_1, const_str_plain_pixels_green );
    if ( tmp_called_name_1 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 212;
        type_description_1 = "o";
        goto frame_exception_exit_1;
    }
    if ( par_surface == NULL )
    {
        Py_DECREF( tmp_called_name_1 );
        exception_type = PyExc_UnboundLocalError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "local variable '%s' referenced before assignment", "surface" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 212;
        type_description_1 = "o";
        goto frame_exception_exit_1;
    }

    tmp_args_element_name_1 = par_surface;
    frame_b7c936f7e2db2b9c6067d91d4fcf9af7->m_frame.f_lineno = 212;
    {
        PyObject *call_args[] = { tmp_args_element_name_1 };
        tmp_return_value = CALL_FUNCTION_WITH_ARGS1( tmp_called_name_1, call_args );
    }

    Py_DECREF( tmp_called_name_1 );
    if ( tmp_return_value == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 212;
        type_description_1 = "o";
        goto frame_exception_exit_1;
    }
    goto frame_return_exit_1;
    }

#if 0
    RESTORE_FRAME_EXCEPTION( frame_b7c936f7e2db2b9c6067d91d4fcf9af7 );
#endif

    // Put the previous frame back on top.
    popFrameStack();

    goto frame_no_exception_1;

    frame_return_exit_1:;
#if 0
    RESTORE_FRAME_EXCEPTION( frame_b7c936f7e2db2b9c6067d91d4fcf9af7 );
#endif

    // Put the previous frame back on top.
    popFrameStack();

    goto try_return_handler_1;

    frame_exception_exit_1:;

#if 0
    RESTORE_FRAME_EXCEPTION( frame_b7c936f7e2db2b9c6067d91d4fcf9af7 );
#endif

    if ( exception_tb == NULL )
    {
        exception_tb = MAKE_TRACEBACK( frame_b7c936f7e2db2b9c6067d91d4fcf9af7, exception_lineno );
    }
    else if ( exception_tb->tb_frame != &frame_b7c936f7e2db2b9c6067d91d4fcf9af7->m_frame )
    {
        exception_tb = ADD_TRACEBACK( exception_tb, frame_b7c936f7e2db2b9c6067d91d4fcf9af7, exception_lineno );
    }

    // Attachs locals to frame if any.
    Nuitka_Frame_AttachLocals(
        (struct Nuitka_FrameObject *)frame_b7c936f7e2db2b9c6067d91d4fcf9af7,
        type_description_1,
        par_surface
    );


    // Release cached frame.
    if ( frame_b7c936f7e2db2b9c6067d91d4fcf9af7 == cache_frame_b7c936f7e2db2b9c6067d91d4fcf9af7 )
    {
        Py_DECREF( frame_b7c936f7e2db2b9c6067d91d4fcf9af7 );
    }
    cache_frame_b7c936f7e2db2b9c6067d91d4fcf9af7 = NULL;

    assertFrameObject( frame_b7c936f7e2db2b9c6067d91d4fcf9af7 );

    // Put the previous frame back on top.
    popFrameStack();

    // Return the error.
    goto try_except_handler_1;

    frame_no_exception_1:;
    // tried codes exits in all cases
    NUITKA_CANNOT_GET_HERE( pygame$surfarray$$$function_9_pixels_green );
    return NULL;
    // Return handler code:
    try_return_handler_1:;
    {
    Py_XDECREF( par_surface );
    par_surface = NULL;

    }
    {
    goto function_return_exit;
    }
    // Exception handler code:
    try_except_handler_1:;
    exception_keeper_type_1 = exception_type;
    exception_keeper_value_1 = exception_value;
    exception_keeper_tb_1 = exception_tb;
    exception_keeper_lineno_1 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = 0;

    {
    Py_XDECREF( par_surface );
    par_surface = NULL;

    }
    {
    // Re-raise.
    exception_type = exception_keeper_type_1;
    exception_value = exception_keeper_value_1;
    exception_tb = exception_keeper_tb_1;
    exception_lineno = exception_keeper_lineno_1;

    goto function_exception_exit;
    }
    // End of try:
    }

    // Return statement must have exited already.
    NUITKA_CANNOT_GET_HERE( pygame$surfarray$$$function_9_pixels_green );
    return NULL;

function_exception_exit:
    assert( exception_type );
    RESTORE_ERROR_OCCURRED( exception_type, exception_value, exception_tb );

    return NULL;
function_return_exit:

CHECK_OBJECT( tmp_return_value );
assert( had_error || !ERROR_OCCURRED() );
return tmp_return_value;

}


static PyObject *impl_pygame$surfarray$$$function_10_pixels_blue( struct Nuitka_FunctionObject const *self, PyObject **python_pars )
{
    // Preserve error status for checks
#ifndef __NUITKA_NO_ASSERT__
    NUITKA_MAY_BE_UNUSED bool had_error = ERROR_OCCURRED();
#endif

    // Local variable declarations.
    PyObject *par_surface = python_pars[ 0 ];
    struct Nuitka_FrameObject *frame_0afb19d095572143270fdb9c59c61639;
    NUITKA_MAY_BE_UNUSED char const *type_description_1 = NULL;
    PyObject *tmp_return_value = NULL;
    PyObject *exception_type = NULL;
    PyObject *exception_value = NULL;
    PyTracebackObject *exception_tb = NULL;
    NUITKA_MAY_BE_UNUSED int exception_lineno = 0;
    static struct Nuitka_FrameObject *cache_frame_0afb19d095572143270fdb9c59c61639 = NULL;
    PyObject *exception_keeper_type_1;
    PyObject *exception_keeper_value_1;
    PyTracebackObject *exception_keeper_tb_1;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_1;

    // Actual function code.
    {
    // Tried code:
    MAKE_OR_REUSE_FRAME( cache_frame_0afb19d095572143270fdb9c59c61639, codeobj_0afb19d095572143270fdb9c59c61639, module_pygame$surfarray, sizeof(void *) );
    frame_0afb19d095572143270fdb9c59c61639 = cache_frame_0afb19d095572143270fdb9c59c61639;

    // Push the new frame as the currently active one.
    pushFrameStack( frame_0afb19d095572143270fdb9c59c61639 );

    // Mark the frame object as in use, ref count 1 will be up for reuse.
    assert( Py_REFCNT( frame_0afb19d095572143270fdb9c59c61639 ) == 2 ); // Frame stack

    // Framed code:
    {
    PyObject *tmp_called_name_1;
    PyObject *tmp_source_name_1;
    PyObject *tmp_mvar_value_1;
    PyObject *tmp_args_element_name_1;
    tmp_mvar_value_1 = GET_STRING_DICT_VALUE( moduledict_pygame$surfarray, (Nuitka_StringObject *)const_str_plain_numpysf );

    if (unlikely( tmp_mvar_value_1 == NULL ))
    {
        tmp_mvar_value_1 = GET_STRING_DICT_VALUE( dict_builtin, (Nuitka_StringObject *)const_str_plain_numpysf );
    }

    if ( tmp_mvar_value_1 == NULL )
    {

        exception_type = PyExc_NameError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "name '%s' is not defined", "numpysf" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 228;
        type_description_1 = "o";
        goto frame_exception_exit_1;
    }

    tmp_source_name_1 = tmp_mvar_value_1;
    tmp_called_name_1 = LOOKUP_ATTRIBUTE( tmp_source_name_1, const_str_plain_pixels_blue );
    if ( tmp_called_name_1 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 228;
        type_description_1 = "o";
        goto frame_exception_exit_1;
    }
    if ( par_surface == NULL )
    {
        Py_DECREF( tmp_called_name_1 );
        exception_type = PyExc_UnboundLocalError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "local variable '%s' referenced before assignment", "surface" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 228;
        type_description_1 = "o";
        goto frame_exception_exit_1;
    }

    tmp_args_element_name_1 = par_surface;
    frame_0afb19d095572143270fdb9c59c61639->m_frame.f_lineno = 228;
    {
        PyObject *call_args[] = { tmp_args_element_name_1 };
        tmp_return_value = CALL_FUNCTION_WITH_ARGS1( tmp_called_name_1, call_args );
    }

    Py_DECREF( tmp_called_name_1 );
    if ( tmp_return_value == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 228;
        type_description_1 = "o";
        goto frame_exception_exit_1;
    }
    goto frame_return_exit_1;
    }

#if 0
    RESTORE_FRAME_EXCEPTION( frame_0afb19d095572143270fdb9c59c61639 );
#endif

    // Put the previous frame back on top.
    popFrameStack();

    goto frame_no_exception_1;

    frame_return_exit_1:;
#if 0
    RESTORE_FRAME_EXCEPTION( frame_0afb19d095572143270fdb9c59c61639 );
#endif

    // Put the previous frame back on top.
    popFrameStack();

    goto try_return_handler_1;

    frame_exception_exit_1:;

#if 0
    RESTORE_FRAME_EXCEPTION( frame_0afb19d095572143270fdb9c59c61639 );
#endif

    if ( exception_tb == NULL )
    {
        exception_tb = MAKE_TRACEBACK( frame_0afb19d095572143270fdb9c59c61639, exception_lineno );
    }
    else if ( exception_tb->tb_frame != &frame_0afb19d095572143270fdb9c59c61639->m_frame )
    {
        exception_tb = ADD_TRACEBACK( exception_tb, frame_0afb19d095572143270fdb9c59c61639, exception_lineno );
    }

    // Attachs locals to frame if any.
    Nuitka_Frame_AttachLocals(
        (struct Nuitka_FrameObject *)frame_0afb19d095572143270fdb9c59c61639,
        type_description_1,
        par_surface
    );


    // Release cached frame.
    if ( frame_0afb19d095572143270fdb9c59c61639 == cache_frame_0afb19d095572143270fdb9c59c61639 )
    {
        Py_DECREF( frame_0afb19d095572143270fdb9c59c61639 );
    }
    cache_frame_0afb19d095572143270fdb9c59c61639 = NULL;

    assertFrameObject( frame_0afb19d095572143270fdb9c59c61639 );

    // Put the previous frame back on top.
    popFrameStack();

    // Return the error.
    goto try_except_handler_1;

    frame_no_exception_1:;
    // tried codes exits in all cases
    NUITKA_CANNOT_GET_HERE( pygame$surfarray$$$function_10_pixels_blue );
    return NULL;
    // Return handler code:
    try_return_handler_1:;
    {
    Py_XDECREF( par_surface );
    par_surface = NULL;

    }
    {
    goto function_return_exit;
    }
    // Exception handler code:
    try_except_handler_1:;
    exception_keeper_type_1 = exception_type;
    exception_keeper_value_1 = exception_value;
    exception_keeper_tb_1 = exception_tb;
    exception_keeper_lineno_1 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = 0;

    {
    Py_XDECREF( par_surface );
    par_surface = NULL;

    }
    {
    // Re-raise.
    exception_type = exception_keeper_type_1;
    exception_value = exception_keeper_value_1;
    exception_tb = exception_keeper_tb_1;
    exception_lineno = exception_keeper_lineno_1;

    goto function_exception_exit;
    }
    // End of try:
    }

    // Return statement must have exited already.
    NUITKA_CANNOT_GET_HERE( pygame$surfarray$$$function_10_pixels_blue );
    return NULL;

function_exception_exit:
    assert( exception_type );
    RESTORE_ERROR_OCCURRED( exception_type, exception_value, exception_tb );

    return NULL;
function_return_exit:

CHECK_OBJECT( tmp_return_value );
assert( had_error || !ERROR_OCCURRED() );
return tmp_return_value;

}


static PyObject *impl_pygame$surfarray$$$function_11_array_colorkey( struct Nuitka_FunctionObject const *self, PyObject **python_pars )
{
    // Preserve error status for checks
#ifndef __NUITKA_NO_ASSERT__
    NUITKA_MAY_BE_UNUSED bool had_error = ERROR_OCCURRED();
#endif

    // Local variable declarations.
    PyObject *par_surface = python_pars[ 0 ];
    struct Nuitka_FrameObject *frame_4e08ff20991cf0ef1947d0fb59c67c14;
    NUITKA_MAY_BE_UNUSED char const *type_description_1 = NULL;
    PyObject *tmp_return_value = NULL;
    PyObject *exception_type = NULL;
    PyObject *exception_value = NULL;
    PyTracebackObject *exception_tb = NULL;
    NUITKA_MAY_BE_UNUSED int exception_lineno = 0;
    static struct Nuitka_FrameObject *cache_frame_4e08ff20991cf0ef1947d0fb59c67c14 = NULL;
    PyObject *exception_keeper_type_1;
    PyObject *exception_keeper_value_1;
    PyTracebackObject *exception_keeper_tb_1;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_1;

    // Actual function code.
    {
    // Tried code:
    MAKE_OR_REUSE_FRAME( cache_frame_4e08ff20991cf0ef1947d0fb59c67c14, codeobj_4e08ff20991cf0ef1947d0fb59c67c14, module_pygame$surfarray, sizeof(void *) );
    frame_4e08ff20991cf0ef1947d0fb59c67c14 = cache_frame_4e08ff20991cf0ef1947d0fb59c67c14;

    // Push the new frame as the currently active one.
    pushFrameStack( frame_4e08ff20991cf0ef1947d0fb59c67c14 );

    // Mark the frame object as in use, ref count 1 will be up for reuse.
    assert( Py_REFCNT( frame_4e08ff20991cf0ef1947d0fb59c67c14 ) == 2 ); // Frame stack

    // Framed code:
    {
    PyObject *tmp_called_name_1;
    PyObject *tmp_source_name_1;
    PyObject *tmp_mvar_value_1;
    PyObject *tmp_args_element_name_1;
    tmp_mvar_value_1 = GET_STRING_DICT_VALUE( moduledict_pygame$surfarray, (Nuitka_StringObject *)const_str_plain_numpysf );

    if (unlikely( tmp_mvar_value_1 == NULL ))
    {
        tmp_mvar_value_1 = GET_STRING_DICT_VALUE( dict_builtin, (Nuitka_StringObject *)const_str_plain_numpysf );
    }

    if ( tmp_mvar_value_1 == NULL )
    {

        exception_type = PyExc_NameError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "name '%s' is not defined", "numpysf" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 245;
        type_description_1 = "o";
        goto frame_exception_exit_1;
    }

    tmp_source_name_1 = tmp_mvar_value_1;
    tmp_called_name_1 = LOOKUP_ATTRIBUTE( tmp_source_name_1, const_str_plain_array_colorkey );
    if ( tmp_called_name_1 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 245;
        type_description_1 = "o";
        goto frame_exception_exit_1;
    }
    if ( par_surface == NULL )
    {
        Py_DECREF( tmp_called_name_1 );
        exception_type = PyExc_UnboundLocalError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "local variable '%s' referenced before assignment", "surface" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 245;
        type_description_1 = "o";
        goto frame_exception_exit_1;
    }

    tmp_args_element_name_1 = par_surface;
    frame_4e08ff20991cf0ef1947d0fb59c67c14->m_frame.f_lineno = 245;
    {
        PyObject *call_args[] = { tmp_args_element_name_1 };
        tmp_return_value = CALL_FUNCTION_WITH_ARGS1( tmp_called_name_1, call_args );
    }

    Py_DECREF( tmp_called_name_1 );
    if ( tmp_return_value == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 245;
        type_description_1 = "o";
        goto frame_exception_exit_1;
    }
    goto frame_return_exit_1;
    }

#if 0
    RESTORE_FRAME_EXCEPTION( frame_4e08ff20991cf0ef1947d0fb59c67c14 );
#endif

    // Put the previous frame back on top.
    popFrameStack();

    goto frame_no_exception_1;

    frame_return_exit_1:;
#if 0
    RESTORE_FRAME_EXCEPTION( frame_4e08ff20991cf0ef1947d0fb59c67c14 );
#endif

    // Put the previous frame back on top.
    popFrameStack();

    goto try_return_handler_1;

    frame_exception_exit_1:;

#if 0
    RESTORE_FRAME_EXCEPTION( frame_4e08ff20991cf0ef1947d0fb59c67c14 );
#endif

    if ( exception_tb == NULL )
    {
        exception_tb = MAKE_TRACEBACK( frame_4e08ff20991cf0ef1947d0fb59c67c14, exception_lineno );
    }
    else if ( exception_tb->tb_frame != &frame_4e08ff20991cf0ef1947d0fb59c67c14->m_frame )
    {
        exception_tb = ADD_TRACEBACK( exception_tb, frame_4e08ff20991cf0ef1947d0fb59c67c14, exception_lineno );
    }

    // Attachs locals to frame if any.
    Nuitka_Frame_AttachLocals(
        (struct Nuitka_FrameObject *)frame_4e08ff20991cf0ef1947d0fb59c67c14,
        type_description_1,
        par_surface
    );


    // Release cached frame.
    if ( frame_4e08ff20991cf0ef1947d0fb59c67c14 == cache_frame_4e08ff20991cf0ef1947d0fb59c67c14 )
    {
        Py_DECREF( frame_4e08ff20991cf0ef1947d0fb59c67c14 );
    }
    cache_frame_4e08ff20991cf0ef1947d0fb59c67c14 = NULL;

    assertFrameObject( frame_4e08ff20991cf0ef1947d0fb59c67c14 );

    // Put the previous frame back on top.
    popFrameStack();

    // Return the error.
    goto try_except_handler_1;

    frame_no_exception_1:;
    // tried codes exits in all cases
    NUITKA_CANNOT_GET_HERE( pygame$surfarray$$$function_11_array_colorkey );
    return NULL;
    // Return handler code:
    try_return_handler_1:;
    {
    Py_XDECREF( par_surface );
    par_surface = NULL;

    }
    {
    goto function_return_exit;
    }
    // Exception handler code:
    try_except_handler_1:;
    exception_keeper_type_1 = exception_type;
    exception_keeper_value_1 = exception_value;
    exception_keeper_tb_1 = exception_tb;
    exception_keeper_lineno_1 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = 0;

    {
    Py_XDECREF( par_surface );
    par_surface = NULL;

    }
    {
    // Re-raise.
    exception_type = exception_keeper_type_1;
    exception_value = exception_keeper_value_1;
    exception_tb = exception_keeper_tb_1;
    exception_lineno = exception_keeper_lineno_1;

    goto function_exception_exit;
    }
    // End of try:
    }

    // Return statement must have exited already.
    NUITKA_CANNOT_GET_HERE( pygame$surfarray$$$function_11_array_colorkey );
    return NULL;

function_exception_exit:
    assert( exception_type );
    RESTORE_ERROR_OCCURRED( exception_type, exception_value, exception_tb );

    return NULL;
function_return_exit:

CHECK_OBJECT( tmp_return_value );
assert( had_error || !ERROR_OCCURRED() );
return tmp_return_value;

}


static PyObject *impl_pygame$surfarray$$$function_12_make_surface( struct Nuitka_FunctionObject const *self, PyObject **python_pars )
{
    // Preserve error status for checks
#ifndef __NUITKA_NO_ASSERT__
    NUITKA_MAY_BE_UNUSED bool had_error = ERROR_OCCURRED();
#endif

    // Local variable declarations.
    PyObject *par_array = python_pars[ 0 ];
    struct Nuitka_FrameObject *frame_366e09b8b35f1a6e294dda7e1d08c22a;
    NUITKA_MAY_BE_UNUSED char const *type_description_1 = NULL;
    PyObject *tmp_return_value = NULL;
    PyObject *exception_type = NULL;
    PyObject *exception_value = NULL;
    PyTracebackObject *exception_tb = NULL;
    NUITKA_MAY_BE_UNUSED int exception_lineno = 0;
    static struct Nuitka_FrameObject *cache_frame_366e09b8b35f1a6e294dda7e1d08c22a = NULL;
    PyObject *exception_keeper_type_1;
    PyObject *exception_keeper_value_1;
    PyTracebackObject *exception_keeper_tb_1;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_1;

    // Actual function code.
    {
    // Tried code:
    MAKE_OR_REUSE_FRAME( cache_frame_366e09b8b35f1a6e294dda7e1d08c22a, codeobj_366e09b8b35f1a6e294dda7e1d08c22a, module_pygame$surfarray, sizeof(void *) );
    frame_366e09b8b35f1a6e294dda7e1d08c22a = cache_frame_366e09b8b35f1a6e294dda7e1d08c22a;

    // Push the new frame as the currently active one.
    pushFrameStack( frame_366e09b8b35f1a6e294dda7e1d08c22a );

    // Mark the frame object as in use, ref count 1 will be up for reuse.
    assert( Py_REFCNT( frame_366e09b8b35f1a6e294dda7e1d08c22a ) == 2 ); // Frame stack

    // Framed code:
    {
    PyObject *tmp_called_name_1;
    PyObject *tmp_source_name_1;
    PyObject *tmp_mvar_value_1;
    PyObject *tmp_args_element_name_1;
    tmp_mvar_value_1 = GET_STRING_DICT_VALUE( moduledict_pygame$surfarray, (Nuitka_StringObject *)const_str_plain_numpysf );

    if (unlikely( tmp_mvar_value_1 == NULL ))
    {
        tmp_mvar_value_1 = GET_STRING_DICT_VALUE( dict_builtin, (Nuitka_StringObject *)const_str_plain_numpysf );
    }

    if ( tmp_mvar_value_1 == NULL )
    {

        exception_type = PyExc_NameError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "name '%s' is not defined", "numpysf" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 255;
        type_description_1 = "o";
        goto frame_exception_exit_1;
    }

    tmp_source_name_1 = tmp_mvar_value_1;
    tmp_called_name_1 = LOOKUP_ATTRIBUTE( tmp_source_name_1, const_str_plain_make_surface );
    if ( tmp_called_name_1 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 255;
        type_description_1 = "o";
        goto frame_exception_exit_1;
    }
    if ( par_array == NULL )
    {
        Py_DECREF( tmp_called_name_1 );
        exception_type = PyExc_UnboundLocalError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "local variable '%s' referenced before assignment", "array" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 255;
        type_description_1 = "o";
        goto frame_exception_exit_1;
    }

    tmp_args_element_name_1 = par_array;
    frame_366e09b8b35f1a6e294dda7e1d08c22a->m_frame.f_lineno = 255;
    {
        PyObject *call_args[] = { tmp_args_element_name_1 };
        tmp_return_value = CALL_FUNCTION_WITH_ARGS1( tmp_called_name_1, call_args );
    }

    Py_DECREF( tmp_called_name_1 );
    if ( tmp_return_value == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 255;
        type_description_1 = "o";
        goto frame_exception_exit_1;
    }
    goto frame_return_exit_1;
    }

#if 0
    RESTORE_FRAME_EXCEPTION( frame_366e09b8b35f1a6e294dda7e1d08c22a );
#endif

    // Put the previous frame back on top.
    popFrameStack();

    goto frame_no_exception_1;

    frame_return_exit_1:;
#if 0
    RESTORE_FRAME_EXCEPTION( frame_366e09b8b35f1a6e294dda7e1d08c22a );
#endif

    // Put the previous frame back on top.
    popFrameStack();

    goto try_return_handler_1;

    frame_exception_exit_1:;

#if 0
    RESTORE_FRAME_EXCEPTION( frame_366e09b8b35f1a6e294dda7e1d08c22a );
#endif

    if ( exception_tb == NULL )
    {
        exception_tb = MAKE_TRACEBACK( frame_366e09b8b35f1a6e294dda7e1d08c22a, exception_lineno );
    }
    else if ( exception_tb->tb_frame != &frame_366e09b8b35f1a6e294dda7e1d08c22a->m_frame )
    {
        exception_tb = ADD_TRACEBACK( exception_tb, frame_366e09b8b35f1a6e294dda7e1d08c22a, exception_lineno );
    }

    // Attachs locals to frame if any.
    Nuitka_Frame_AttachLocals(
        (struct Nuitka_FrameObject *)frame_366e09b8b35f1a6e294dda7e1d08c22a,
        type_description_1,
        par_array
    );


    // Release cached frame.
    if ( frame_366e09b8b35f1a6e294dda7e1d08c22a == cache_frame_366e09b8b35f1a6e294dda7e1d08c22a )
    {
        Py_DECREF( frame_366e09b8b35f1a6e294dda7e1d08c22a );
    }
    cache_frame_366e09b8b35f1a6e294dda7e1d08c22a = NULL;

    assertFrameObject( frame_366e09b8b35f1a6e294dda7e1d08c22a );

    // Put the previous frame back on top.
    popFrameStack();

    // Return the error.
    goto try_except_handler_1;

    frame_no_exception_1:;
    // tried codes exits in all cases
    NUITKA_CANNOT_GET_HERE( pygame$surfarray$$$function_12_make_surface );
    return NULL;
    // Return handler code:
    try_return_handler_1:;
    {
    Py_XDECREF( par_array );
    par_array = NULL;

    }
    {
    goto function_return_exit;
    }
    // Exception handler code:
    try_except_handler_1:;
    exception_keeper_type_1 = exception_type;
    exception_keeper_value_1 = exception_value;
    exception_keeper_tb_1 = exception_tb;
    exception_keeper_lineno_1 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = 0;

    {
    Py_XDECREF( par_array );
    par_array = NULL;

    }
    {
    // Re-raise.
    exception_type = exception_keeper_type_1;
    exception_value = exception_keeper_value_1;
    exception_tb = exception_keeper_tb_1;
    exception_lineno = exception_keeper_lineno_1;

    goto function_exception_exit;
    }
    // End of try:
    }

    // Return statement must have exited already.
    NUITKA_CANNOT_GET_HERE( pygame$surfarray$$$function_12_make_surface );
    return NULL;

function_exception_exit:
    assert( exception_type );
    RESTORE_ERROR_OCCURRED( exception_type, exception_value, exception_tb );

    return NULL;
function_return_exit:

CHECK_OBJECT( tmp_return_value );
assert( had_error || !ERROR_OCCURRED() );
return tmp_return_value;

}


static PyObject *impl_pygame$surfarray$$$function_13_map_array( struct Nuitka_FunctionObject const *self, PyObject **python_pars )
{
    // Preserve error status for checks
#ifndef __NUITKA_NO_ASSERT__
    NUITKA_MAY_BE_UNUSED bool had_error = ERROR_OCCURRED();
#endif

    // Local variable declarations.
    PyObject *par_surface = python_pars[ 0 ];
    PyObject *par_array = python_pars[ 1 ];
    struct Nuitka_FrameObject *frame_6292c829e978558e5715e82c7ef284fe;
    NUITKA_MAY_BE_UNUSED char const *type_description_1 = NULL;
    PyObject *tmp_return_value = NULL;
    PyObject *exception_type = NULL;
    PyObject *exception_value = NULL;
    PyTracebackObject *exception_tb = NULL;
    NUITKA_MAY_BE_UNUSED int exception_lineno = 0;
    static struct Nuitka_FrameObject *cache_frame_6292c829e978558e5715e82c7ef284fe = NULL;
    PyObject *exception_keeper_type_1;
    PyObject *exception_keeper_value_1;
    PyTracebackObject *exception_keeper_tb_1;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_1;

    // Actual function code.
    {
    // Tried code:
    MAKE_OR_REUSE_FRAME( cache_frame_6292c829e978558e5715e82c7ef284fe, codeobj_6292c829e978558e5715e82c7ef284fe, module_pygame$surfarray, sizeof(void *)+sizeof(void *) );
    frame_6292c829e978558e5715e82c7ef284fe = cache_frame_6292c829e978558e5715e82c7ef284fe;

    // Push the new frame as the currently active one.
    pushFrameStack( frame_6292c829e978558e5715e82c7ef284fe );

    // Mark the frame object as in use, ref count 1 will be up for reuse.
    assert( Py_REFCNT( frame_6292c829e978558e5715e82c7ef284fe ) == 2 ); // Frame stack

    // Framed code:
    {
    PyObject *tmp_called_name_1;
    PyObject *tmp_source_name_1;
    PyObject *tmp_mvar_value_1;
    PyObject *tmp_args_element_name_1;
    PyObject *tmp_args_element_name_2;
    tmp_mvar_value_1 = GET_STRING_DICT_VALUE( moduledict_pygame$surfarray, (Nuitka_StringObject *)const_str_plain_numpysf );

    if (unlikely( tmp_mvar_value_1 == NULL ))
    {
        tmp_mvar_value_1 = GET_STRING_DICT_VALUE( dict_builtin, (Nuitka_StringObject *)const_str_plain_numpysf );
    }

    if ( tmp_mvar_value_1 == NULL )
    {

        exception_type = PyExc_NameError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "name '%s' is not defined", "numpysf" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 266;
        type_description_1 = "oo";
        goto frame_exception_exit_1;
    }

    tmp_source_name_1 = tmp_mvar_value_1;
    tmp_called_name_1 = LOOKUP_ATTRIBUTE( tmp_source_name_1, const_str_plain_map_array );
    if ( tmp_called_name_1 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 266;
        type_description_1 = "oo";
        goto frame_exception_exit_1;
    }
    if ( par_surface == NULL )
    {
        Py_DECREF( tmp_called_name_1 );
        exception_type = PyExc_UnboundLocalError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "local variable '%s' referenced before assignment", "surface" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 266;
        type_description_1 = "oo";
        goto frame_exception_exit_1;
    }

    tmp_args_element_name_1 = par_surface;
    if ( par_array == NULL )
    {
        Py_DECREF( tmp_called_name_1 );
        exception_type = PyExc_UnboundLocalError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "local variable '%s' referenced before assignment", "array" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 266;
        type_description_1 = "oo";
        goto frame_exception_exit_1;
    }

    tmp_args_element_name_2 = par_array;
    frame_6292c829e978558e5715e82c7ef284fe->m_frame.f_lineno = 266;
    {
        PyObject *call_args[] = { tmp_args_element_name_1, tmp_args_element_name_2 };
        tmp_return_value = CALL_FUNCTION_WITH_ARGS2( tmp_called_name_1, call_args );
    }

    Py_DECREF( tmp_called_name_1 );
    if ( tmp_return_value == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 266;
        type_description_1 = "oo";
        goto frame_exception_exit_1;
    }
    goto frame_return_exit_1;
    }

#if 0
    RESTORE_FRAME_EXCEPTION( frame_6292c829e978558e5715e82c7ef284fe );
#endif

    // Put the previous frame back on top.
    popFrameStack();

    goto frame_no_exception_1;

    frame_return_exit_1:;
#if 0
    RESTORE_FRAME_EXCEPTION( frame_6292c829e978558e5715e82c7ef284fe );
#endif

    // Put the previous frame back on top.
    popFrameStack();

    goto try_return_handler_1;

    frame_exception_exit_1:;

#if 0
    RESTORE_FRAME_EXCEPTION( frame_6292c829e978558e5715e82c7ef284fe );
#endif

    if ( exception_tb == NULL )
    {
        exception_tb = MAKE_TRACEBACK( frame_6292c829e978558e5715e82c7ef284fe, exception_lineno );
    }
    else if ( exception_tb->tb_frame != &frame_6292c829e978558e5715e82c7ef284fe->m_frame )
    {
        exception_tb = ADD_TRACEBACK( exception_tb, frame_6292c829e978558e5715e82c7ef284fe, exception_lineno );
    }

    // Attachs locals to frame if any.
    Nuitka_Frame_AttachLocals(
        (struct Nuitka_FrameObject *)frame_6292c829e978558e5715e82c7ef284fe,
        type_description_1,
        par_surface,
        par_array
    );


    // Release cached frame.
    if ( frame_6292c829e978558e5715e82c7ef284fe == cache_frame_6292c829e978558e5715e82c7ef284fe )
    {
        Py_DECREF( frame_6292c829e978558e5715e82c7ef284fe );
    }
    cache_frame_6292c829e978558e5715e82c7ef284fe = NULL;

    assertFrameObject( frame_6292c829e978558e5715e82c7ef284fe );

    // Put the previous frame back on top.
    popFrameStack();

    // Return the error.
    goto try_except_handler_1;

    frame_no_exception_1:;
    // tried codes exits in all cases
    NUITKA_CANNOT_GET_HERE( pygame$surfarray$$$function_13_map_array );
    return NULL;
    // Return handler code:
    try_return_handler_1:;
    {
    Py_XDECREF( par_surface );
    par_surface = NULL;

    }
    {
    Py_XDECREF( par_array );
    par_array = NULL;

    }
    {
    goto function_return_exit;
    }
    // Exception handler code:
    try_except_handler_1:;
    exception_keeper_type_1 = exception_type;
    exception_keeper_value_1 = exception_value;
    exception_keeper_tb_1 = exception_tb;
    exception_keeper_lineno_1 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = 0;

    {
    Py_XDECREF( par_surface );
    par_surface = NULL;

    }
    {
    Py_XDECREF( par_array );
    par_array = NULL;

    }
    {
    // Re-raise.
    exception_type = exception_keeper_type_1;
    exception_value = exception_keeper_value_1;
    exception_tb = exception_keeper_tb_1;
    exception_lineno = exception_keeper_lineno_1;

    goto function_exception_exit;
    }
    // End of try:
    }

    // Return statement must have exited already.
    NUITKA_CANNOT_GET_HERE( pygame$surfarray$$$function_13_map_array );
    return NULL;

function_exception_exit:
    assert( exception_type );
    RESTORE_ERROR_OCCURRED( exception_type, exception_value, exception_tb );

    return NULL;
function_return_exit:

CHECK_OBJECT( tmp_return_value );
assert( had_error || !ERROR_OCCURRED() );
return tmp_return_value;

}


static PyObject *impl_pygame$surfarray$$$function_14_use_arraytype( struct Nuitka_FunctionObject const *self, PyObject **python_pars )
{
    // Preserve error status for checks
#ifndef __NUITKA_NO_ASSERT__
    NUITKA_MAY_BE_UNUSED bool had_error = ERROR_OCCURRED();
#endif

    // Local variable declarations.
    PyObject *par_arraytype = python_pars[ 0 ];
    struct Nuitka_FrameObject *frame_bbb6f3c9a10033b300b0fe9de42d78b7;
    NUITKA_MAY_BE_UNUSED char const *type_description_1 = NULL;
    PyObject *exception_type = NULL;
    PyObject *exception_value = NULL;
    PyTracebackObject *exception_tb = NULL;
    NUITKA_MAY_BE_UNUSED int exception_lineno = 0;
    int tmp_res;
    static struct Nuitka_FrameObject *cache_frame_bbb6f3c9a10033b300b0fe9de42d78b7 = NULL;
    PyObject *tmp_return_value = NULL;
    PyObject *exception_keeper_type_1;
    PyObject *exception_keeper_value_1;
    PyTracebackObject *exception_keeper_tb_1;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_1;

    // Actual function code.
    {
    // Tried code:
    MAKE_OR_REUSE_FRAME( cache_frame_bbb6f3c9a10033b300b0fe9de42d78b7, codeobj_bbb6f3c9a10033b300b0fe9de42d78b7, module_pygame$surfarray, sizeof(void *) );
    frame_bbb6f3c9a10033b300b0fe9de42d78b7 = cache_frame_bbb6f3c9a10033b300b0fe9de42d78b7;

    // Push the new frame as the currently active one.
    pushFrameStack( frame_bbb6f3c9a10033b300b0fe9de42d78b7 );

    // Mark the frame object as in use, ref count 1 will be up for reuse.
    assert( Py_REFCNT( frame_bbb6f3c9a10033b300b0fe9de42d78b7 ) == 2 ); // Frame stack

    // Framed code:
    {
    PyObject *tmp_assign_source_1;
    PyObject *tmp_called_instance_1;
    CHECK_OBJECT( par_arraytype );
    tmp_called_instance_1 = par_arraytype;
    frame_bbb6f3c9a10033b300b0fe9de42d78b7->m_frame.f_lineno = 273;
    tmp_assign_source_1 = CALL_METHOD_NO_ARGS( tmp_called_instance_1, const_str_plain_lower );
    if ( tmp_assign_source_1 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 273;
        type_description_1 = "o";
        goto frame_exception_exit_1;
    }
    {
        PyObject *old = par_arraytype;
        par_arraytype = tmp_assign_source_1;
        Py_XDECREF( old );
    }

    }
    {
    nuitka_bool tmp_condition_result_1;
    PyObject *tmp_compexpr_left_1;
    PyObject *tmp_compexpr_right_1;
    CHECK_OBJECT( par_arraytype );
    tmp_compexpr_left_1 = par_arraytype;
    tmp_compexpr_right_1 = const_str_plain_numpy;
    tmp_res = RICH_COMPARE_BOOL_NE( tmp_compexpr_left_1, tmp_compexpr_right_1 );
    if ( tmp_res == -1 )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 274;
        type_description_1 = "o";
        goto frame_exception_exit_1;
    }
    tmp_condition_result_1 = ( tmp_res != 0 ) ? NUITKA_BOOL_TRUE : NUITKA_BOOL_FALSE;
    if ( tmp_condition_result_1 == NUITKA_BOOL_TRUE )
    {
        goto branch_yes_1;
    }
    else
    {
        goto branch_no_1;
    }
    branch_yes_1:;
    {
    PyObject *tmp_raise_type_1;
    PyObject *tmp_make_exception_arg_1;
    tmp_make_exception_arg_1 = const_str_digest_390dcb68817636bbd0641245b5f96e70;
    frame_bbb6f3c9a10033b300b0fe9de42d78b7->m_frame.f_lineno = 275;
    {
        PyObject *call_args[] = { tmp_make_exception_arg_1 };
        tmp_raise_type_1 = CALL_FUNCTION_WITH_ARGS1( PyExc_ValueError, call_args );
    }

    assert( !(tmp_raise_type_1 == NULL) );
    exception_type = tmp_raise_type_1;
    exception_lineno = 275;
    RAISE_EXCEPTION_WITH_TYPE( &exception_type, &exception_value, &exception_tb );
    type_description_1 = "o";
    goto frame_exception_exit_1;
    }
    branch_no_1:;
    }

#if 0
    RESTORE_FRAME_EXCEPTION( frame_bbb6f3c9a10033b300b0fe9de42d78b7 );
#endif

    // Put the previous frame back on top.
    popFrameStack();

    goto frame_no_exception_1;

    frame_exception_exit_1:;

#if 0
    RESTORE_FRAME_EXCEPTION( frame_bbb6f3c9a10033b300b0fe9de42d78b7 );
#endif

    if ( exception_tb == NULL )
    {
        exception_tb = MAKE_TRACEBACK( frame_bbb6f3c9a10033b300b0fe9de42d78b7, exception_lineno );
    }
    else if ( exception_tb->tb_frame != &frame_bbb6f3c9a10033b300b0fe9de42d78b7->m_frame )
    {
        exception_tb = ADD_TRACEBACK( exception_tb, frame_bbb6f3c9a10033b300b0fe9de42d78b7, exception_lineno );
    }

    // Attachs locals to frame if any.
    Nuitka_Frame_AttachLocals(
        (struct Nuitka_FrameObject *)frame_bbb6f3c9a10033b300b0fe9de42d78b7,
        type_description_1,
        par_arraytype
    );


    // Release cached frame.
    if ( frame_bbb6f3c9a10033b300b0fe9de42d78b7 == cache_frame_bbb6f3c9a10033b300b0fe9de42d78b7 )
    {
        Py_DECREF( frame_bbb6f3c9a10033b300b0fe9de42d78b7 );
    }
    cache_frame_bbb6f3c9a10033b300b0fe9de42d78b7 = NULL;

    assertFrameObject( frame_bbb6f3c9a10033b300b0fe9de42d78b7 );

    // Put the previous frame back on top.
    popFrameStack();

    // Return the error.
    goto try_except_handler_1;

    frame_no_exception_1:;
    {
    tmp_return_value = Py_None;
    Py_INCREF( tmp_return_value );
    goto try_return_handler_1;
    }
    // tried codes exits in all cases
    NUITKA_CANNOT_GET_HERE( pygame$surfarray$$$function_14_use_arraytype );
    return NULL;
    // Return handler code:
    try_return_handler_1:;
    {
    Py_XDECREF( par_arraytype );
    par_arraytype = NULL;

    }
    {
    goto function_return_exit;
    }
    // Exception handler code:
    try_except_handler_1:;
    exception_keeper_type_1 = exception_type;
    exception_keeper_value_1 = exception_value;
    exception_keeper_tb_1 = exception_tb;
    exception_keeper_lineno_1 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = 0;

    {
    Py_XDECREF( par_arraytype );
    par_arraytype = NULL;

    }
    {
    // Re-raise.
    exception_type = exception_keeper_type_1;
    exception_value = exception_keeper_value_1;
    exception_tb = exception_keeper_tb_1;
    exception_lineno = exception_keeper_lineno_1;

    goto function_exception_exit;
    }
    // End of try:
    }

    // Return statement must have exited already.
    NUITKA_CANNOT_GET_HERE( pygame$surfarray$$$function_14_use_arraytype );
    return NULL;

function_exception_exit:
    assert( exception_type );
    RESTORE_ERROR_OCCURRED( exception_type, exception_value, exception_tb );

    return NULL;
function_return_exit:

CHECK_OBJECT( tmp_return_value );
assert( had_error || !ERROR_OCCURRED() );
return tmp_return_value;

}


static PyObject *impl_pygame$surfarray$$$function_15_get_arraytype( struct Nuitka_FunctionObject const *self, PyObject **python_pars )
{
    // Preserve error status for checks
#ifndef __NUITKA_NO_ASSERT__
    NUITKA_MAY_BE_UNUSED bool had_error = ERROR_OCCURRED();
#endif

    // Local variable declarations.
    PyObject *tmp_return_value = NULL;

    // Actual function code.
    {
    tmp_return_value = const_str_plain_numpy;
    Py_INCREF( tmp_return_value );
    goto function_return_exit;
    }

    // Return statement must have exited already.
    NUITKA_CANNOT_GET_HERE( pygame$surfarray$$$function_15_get_arraytype );
    return NULL;

function_return_exit:

CHECK_OBJECT( tmp_return_value );
assert( had_error || !ERROR_OCCURRED() );
return tmp_return_value;

}


static PyObject *impl_pygame$surfarray$$$function_16_get_arraytypes( struct Nuitka_FunctionObject const *self, PyObject **python_pars )
{
    // Preserve error status for checks
#ifndef __NUITKA_NO_ASSERT__
    NUITKA_MAY_BE_UNUSED bool had_error = ERROR_OCCURRED();
#endif

    // Local variable declarations.
    PyObject *tmp_return_value = NULL;

    // Actual function code.
    {
    tmp_return_value = const_tuple_str_plain_numpy_tuple;
    Py_INCREF( tmp_return_value );
    goto function_return_exit;
    }

    // Return statement must have exited already.
    NUITKA_CANNOT_GET_HERE( pygame$surfarray$$$function_16_get_arraytypes );
    return NULL;

function_return_exit:

CHECK_OBJECT( tmp_return_value );
assert( had_error || !ERROR_OCCURRED() );
return tmp_return_value;

}



static PyObject *MAKE_FUNCTION_pygame$surfarray$$$function_10_pixels_blue(  )
{
    struct Nuitka_FunctionObject *result = Nuitka_Function_New(
        impl_pygame$surfarray$$$function_10_pixels_blue,
        const_str_plain_pixels_blue,
#if PYTHON_VERSION >= 300
        NULL,
#endif
        codeobj_0afb19d095572143270fdb9c59c61639,
        NULL,
#if PYTHON_VERSION >= 300
        NULL,
        NULL,
#endif
        module_pygame$surfarray,
        const_str_digest_6f59b8e61555e52228c092be946919db,
        0
    );

    return (PyObject *)result;
}



static PyObject *MAKE_FUNCTION_pygame$surfarray$$$function_11_array_colorkey(  )
{
    struct Nuitka_FunctionObject *result = Nuitka_Function_New(
        impl_pygame$surfarray$$$function_11_array_colorkey,
        const_str_plain_array_colorkey,
#if PYTHON_VERSION >= 300
        NULL,
#endif
        codeobj_4e08ff20991cf0ef1947d0fb59c67c14,
        NULL,
#if PYTHON_VERSION >= 300
        NULL,
        NULL,
#endif
        module_pygame$surfarray,
        const_str_digest_8ca8da321043894061b54c5cea0460be,
        0
    );

    return (PyObject *)result;
}



static PyObject *MAKE_FUNCTION_pygame$surfarray$$$function_12_make_surface(  )
{
    struct Nuitka_FunctionObject *result = Nuitka_Function_New(
        impl_pygame$surfarray$$$function_12_make_surface,
        const_str_plain_make_surface,
#if PYTHON_VERSION >= 300
        NULL,
#endif
        codeobj_366e09b8b35f1a6e294dda7e1d08c22a,
        NULL,
#if PYTHON_VERSION >= 300
        NULL,
        NULL,
#endif
        module_pygame$surfarray,
        const_str_digest_be0c58c5fcf712145ccaf4e61ea24ef9,
        0
    );

    return (PyObject *)result;
}



static PyObject *MAKE_FUNCTION_pygame$surfarray$$$function_13_map_array(  )
{
    struct Nuitka_FunctionObject *result = Nuitka_Function_New(
        impl_pygame$surfarray$$$function_13_map_array,
        const_str_plain_map_array,
#if PYTHON_VERSION >= 300
        NULL,
#endif
        codeobj_6292c829e978558e5715e82c7ef284fe,
        NULL,
#if PYTHON_VERSION >= 300
        NULL,
        NULL,
#endif
        module_pygame$surfarray,
        const_str_digest_f62791549a87bf84dc2e9770b515c976,
        0
    );

    return (PyObject *)result;
}



static PyObject *MAKE_FUNCTION_pygame$surfarray$$$function_14_use_arraytype(  )
{
    struct Nuitka_FunctionObject *result = Nuitka_Function_New(
        impl_pygame$surfarray$$$function_14_use_arraytype,
        const_str_plain_use_arraytype,
#if PYTHON_VERSION >= 300
        NULL,
#endif
        codeobj_bbb6f3c9a10033b300b0fe9de42d78b7,
        NULL,
#if PYTHON_VERSION >= 300
        NULL,
        NULL,
#endif
        module_pygame$surfarray,
        const_str_digest_4a7809fd9a8eca656ef67a591dca6116,
        0
    );

    return (PyObject *)result;
}



static PyObject *MAKE_FUNCTION_pygame$surfarray$$$function_15_get_arraytype(  )
{
    struct Nuitka_FunctionObject *result = Nuitka_Function_New(
        impl_pygame$surfarray$$$function_15_get_arraytype,
        const_str_plain_get_arraytype,
#if PYTHON_VERSION >= 300
        NULL,
#endif
        codeobj_75666833fcb6cd762771f4291c739d83,
        NULL,
#if PYTHON_VERSION >= 300
        NULL,
        NULL,
#endif
        module_pygame$surfarray,
        const_str_digest_a0402477ac8af52e8662ff2140c23920,
        0
    );

    return (PyObject *)result;
}



static PyObject *MAKE_FUNCTION_pygame$surfarray$$$function_16_get_arraytypes(  )
{
    struct Nuitka_FunctionObject *result = Nuitka_Function_New(
        impl_pygame$surfarray$$$function_16_get_arraytypes,
        const_str_plain_get_arraytypes,
#if PYTHON_VERSION >= 300
        NULL,
#endif
        codeobj_31aee54930432c9353839843daf51ff8,
        NULL,
#if PYTHON_VERSION >= 300
        NULL,
        NULL,
#endif
        module_pygame$surfarray,
        const_str_digest_234bd90e4f9b032503f52634992c6616,
        0
    );

    return (PyObject *)result;
}



static PyObject *MAKE_FUNCTION_pygame$surfarray$$$function_1_blit_array(  )
{
    struct Nuitka_FunctionObject *result = Nuitka_Function_New(
        impl_pygame$surfarray$$$function_1_blit_array,
        const_str_plain_blit_array,
#if PYTHON_VERSION >= 300
        NULL,
#endif
        codeobj_ef7a6007beb77a7b4a84f226cf8d4e80,
        NULL,
#if PYTHON_VERSION >= 300
        NULL,
        NULL,
#endif
        module_pygame$surfarray,
        const_str_digest_7b06e36aa54006877c6dbd4046f3d7da,
        0
    );

    return (PyObject *)result;
}



static PyObject *MAKE_FUNCTION_pygame$surfarray$$$function_2_array2d(  )
{
    struct Nuitka_FunctionObject *result = Nuitka_Function_New(
        impl_pygame$surfarray$$$function_2_array2d,
        const_str_plain_array2d,
#if PYTHON_VERSION >= 300
        NULL,
#endif
        codeobj_a464259c76bad626f05125f9795b517e,
        NULL,
#if PYTHON_VERSION >= 300
        NULL,
        NULL,
#endif
        module_pygame$surfarray,
        const_str_digest_64ba1d9daa9a21b88fa9c020389c39a5,
        0
    );

    return (PyObject *)result;
}



static PyObject *MAKE_FUNCTION_pygame$surfarray$$$function_3_pixels2d(  )
{
    struct Nuitka_FunctionObject *result = Nuitka_Function_New(
        impl_pygame$surfarray$$$function_3_pixels2d,
        const_str_plain_pixels2d,
#if PYTHON_VERSION >= 300
        NULL,
#endif
        codeobj_59862c546439e91b4925a076a28ff026,
        NULL,
#if PYTHON_VERSION >= 300
        NULL,
        NULL,
#endif
        module_pygame$surfarray,
        const_str_digest_ebf86469c0fa5f0970063f5a149aec8b,
        0
    );

    return (PyObject *)result;
}



static PyObject *MAKE_FUNCTION_pygame$surfarray$$$function_4_array3d(  )
{
    struct Nuitka_FunctionObject *result = Nuitka_Function_New(
        impl_pygame$surfarray$$$function_4_array3d,
        const_str_plain_array3d,
#if PYTHON_VERSION >= 300
        NULL,
#endif
        codeobj_86b8590f1e9c3500c1c998ab54033a0d,
        NULL,
#if PYTHON_VERSION >= 300
        NULL,
        NULL,
#endif
        module_pygame$surfarray,
        const_str_digest_f47e5181f8ff99bd781fe5fff92946cd,
        0
    );

    return (PyObject *)result;
}



static PyObject *MAKE_FUNCTION_pygame$surfarray$$$function_5_pixels3d(  )
{
    struct Nuitka_FunctionObject *result = Nuitka_Function_New(
        impl_pygame$surfarray$$$function_5_pixels3d,
        const_str_plain_pixels3d,
#if PYTHON_VERSION >= 300
        NULL,
#endif
        codeobj_055d8778bfc74345d855452a5cb7e0aa,
        NULL,
#if PYTHON_VERSION >= 300
        NULL,
        NULL,
#endif
        module_pygame$surfarray,
        const_str_digest_844be27206d42c980bbf45effffc54d0,
        0
    );

    return (PyObject *)result;
}



static PyObject *MAKE_FUNCTION_pygame$surfarray$$$function_6_array_alpha(  )
{
    struct Nuitka_FunctionObject *result = Nuitka_Function_New(
        impl_pygame$surfarray$$$function_6_array_alpha,
        const_str_plain_array_alpha,
#if PYTHON_VERSION >= 300
        NULL,
#endif
        codeobj_6ad94c3dcaae1d69441b6cc8d24523d0,
        NULL,
#if PYTHON_VERSION >= 300
        NULL,
        NULL,
#endif
        module_pygame$surfarray,
        const_str_digest_f5fb89ef9cbc2e38324e94c947589e7f,
        0
    );

    return (PyObject *)result;
}



static PyObject *MAKE_FUNCTION_pygame$surfarray$$$function_7_pixels_alpha(  )
{
    struct Nuitka_FunctionObject *result = Nuitka_Function_New(
        impl_pygame$surfarray$$$function_7_pixels_alpha,
        const_str_plain_pixels_alpha,
#if PYTHON_VERSION >= 300
        NULL,
#endif
        codeobj_ab27c7c14fc06287d5e3ea38c0c549c0,
        NULL,
#if PYTHON_VERSION >= 300
        NULL,
        NULL,
#endif
        module_pygame$surfarray,
        const_str_digest_c92c95c39b2cf9b2e24921a1f3c63ddc,
        0
    );

    return (PyObject *)result;
}



static PyObject *MAKE_FUNCTION_pygame$surfarray$$$function_8_pixels_red(  )
{
    struct Nuitka_FunctionObject *result = Nuitka_Function_New(
        impl_pygame$surfarray$$$function_8_pixels_red,
        const_str_plain_pixels_red,
#if PYTHON_VERSION >= 300
        NULL,
#endif
        codeobj_b60ed5b95dac8b10895da61c20ad1028,
        NULL,
#if PYTHON_VERSION >= 300
        NULL,
        NULL,
#endif
        module_pygame$surfarray,
        const_str_digest_1ac1d405f1bb3292837d70f7b383c1b5,
        0
    );

    return (PyObject *)result;
}



static PyObject *MAKE_FUNCTION_pygame$surfarray$$$function_9_pixels_green(  )
{
    struct Nuitka_FunctionObject *result = Nuitka_Function_New(
        impl_pygame$surfarray$$$function_9_pixels_green,
        const_str_plain_pixels_green,
#if PYTHON_VERSION >= 300
        NULL,
#endif
        codeobj_b7c936f7e2db2b9c6067d91d4fcf9af7,
        NULL,
#if PYTHON_VERSION >= 300
        NULL,
        NULL,
#endif
        module_pygame$surfarray,
        const_str_digest_d70c9c687dcc59de67a45493a9d8f05b,
        0
    );

    return (PyObject *)result;
}



#if PYTHON_VERSION >= 300
static struct PyModuleDef mdef_pygame$surfarray =
{
    PyModuleDef_HEAD_INIT,
    "pygame.surfarray",   /* m_name */
    NULL,                /* m_doc */
    -1,                  /* m_size */
    NULL,                /* m_methods */
    NULL,                /* m_reload */
    NULL,                /* m_traverse */
    NULL,                /* m_clear */
    NULL,                /* m_free */
  };
#endif

extern PyObject *const_str_plain___package__;

#if PYTHON_VERSION >= 300
extern PyObject *const_str_dot;

extern PyObject *const_str_plain___loader__;
extern PyObject *metapath_based_loader;
#endif

#if PYTHON_VERSION >= 340
extern PyObject *const_str_plain___spec__;
extern PyObject *const_str_plain__initializing;
#endif

extern void _initCompiledCellType();
extern void _initCompiledGeneratorType();
extern void _initCompiledFunctionType();
extern void _initCompiledMethodType();
extern void _initCompiledFrameType();
#if PYTHON_VERSION >= 350
extern void _initCompiledCoroutineTypes();
#endif
#if PYTHON_VERSION >= 360
extern void _initCompiledAsyncgenTypes();
#endif

// The exported interface to CPython. On import of the module, this function
// gets called. It has to have an exact function name, in cases it's a shared
// library export. This is hidden behind the MOD_INIT_DECL.

MOD_INIT_DECL( pygame$surfarray )
{
#if defined(_NUITKA_EXE) || PYTHON_VERSION >= 300
    static bool _init_done = false;

    // Modules might be imported repeatedly, which is to be ignored.
    if ( _init_done )
    {
        return MOD_RETURN_VALUE( module_pygame$surfarray );
    }
    else
    {
        _init_done = true;
    }
#endif

#ifdef _NUITKA_MODULE
    // In case of a stand alone extension module, need to call initialization
    // the init here because that's the first and only time we are going to get
    // called here.

    // Initialize the constant values used.
    _initBuiltinModule();
    createGlobalConstants();

    /* Initialize the compiled types of Nuitka. */
    _initCompiledCellType();
    _initCompiledGeneratorType();
    _initCompiledFunctionType();
    _initCompiledMethodType();
    _initCompiledFrameType();
#if PYTHON_VERSION >= 350
    _initCompiledCoroutineTypes();
#endif
#if PYTHON_VERSION >= 360
    _initCompiledAsyncgenTypes();
#endif

#if PYTHON_VERSION < 300
    _initSlotCompare();
#endif
#if PYTHON_VERSION >= 270
    _initSlotIternext();
#endif

    patchBuiltinModule();
    patchTypeComparison();

    // Enable meta path based loader if not already done.
#ifdef _NUITKA_TRACE
    puts("pygame.surfarray: Calling setupMetaPathBasedLoader().");
#endif
    setupMetaPathBasedLoader();

#if PYTHON_VERSION >= 300
    patchInspectModule();
#endif

#endif

    /* The constants only used by this module are created now. */
#ifdef _NUITKA_TRACE
    puts("pygame.surfarray: Calling createModuleConstants().");
#endif
    createModuleConstants();

    /* The code objects used by this module are created now. */
#ifdef _NUITKA_TRACE
    puts("pygame.surfarray: Calling createModuleCodeObjects().");
#endif
    createModuleCodeObjects();

    // puts( "in initpygame$surfarray" );

    // Create the module object first. There are no methods initially, all are
    // added dynamically in actual code only.  Also no "__doc__" is initially
    // set at this time, as it could not contain NUL characters this way, they
    // are instead set in early module code.  No "self" for modules, we have no
    // use for it.
#if PYTHON_VERSION < 300
    module_pygame$surfarray = Py_InitModule4(
        "pygame.surfarray",       // Module Name
        NULL,                    // No methods initially, all are added
                                 // dynamically in actual module code only.
        NULL,                    // No "__doc__" is initially set, as it could
                                 // not contain NUL this way, added early in
                                 // actual code.
        NULL,                    // No self for modules, we don't use it.
        PYTHON_API_VERSION
    );
#else

    module_pygame$surfarray = PyModule_Create( &mdef_pygame$surfarray );
#endif

    moduledict_pygame$surfarray = MODULE_DICT( module_pygame$surfarray );

    // Update "__package__" value to what it ought to be.
    {
#if 0
        PyObject *module_name = GET_STRING_DICT_VALUE( moduledict_pygame$surfarray, (Nuitka_StringObject *)const_str_plain___name__ );

        UPDATE_STRING_DICT1(
            moduledict_pygame$surfarray,
            (Nuitka_StringObject *)const_str_plain___package__,
            module_name
        );

#else

#if PYTHON_VERSION < 300
        PyObject *module_name = GET_STRING_DICT_VALUE( moduledict_pygame$surfarray, (Nuitka_StringObject *)const_str_plain___name__ );
        char const *module_name_cstr = PyString_AS_STRING( module_name );

        char const *last_dot = strrchr( module_name_cstr, '.' );

        if ( last_dot != NULL )
        {
            UPDATE_STRING_DICT1(
                moduledict_pygame$surfarray,
                (Nuitka_StringObject *)const_str_plain___package__,
                PyString_FromStringAndSize( module_name_cstr, last_dot - module_name_cstr )
            );
        }
#else
        PyObject *module_name = GET_STRING_DICT_VALUE( moduledict_pygame$surfarray, (Nuitka_StringObject *)const_str_plain___name__ );
        Py_ssize_t dot_index = PyUnicode_Find( module_name, const_str_dot, 0, PyUnicode_GetLength( module_name ), -1 );

        if ( dot_index != -1 )
        {
            UPDATE_STRING_DICT1(
                moduledict_pygame$surfarray,
                (Nuitka_StringObject *)const_str_plain___package__,
                PyUnicode_Substring( module_name, 0, dot_index )
            );
        }
#endif
#endif
    }

    CHECK_OBJECT( module_pygame$surfarray );

// Seems to work for Python2.7 out of the box, but for Python3, the module
// doesn't automatically enter "sys.modules", so do it manually.
#if PYTHON_VERSION >= 300
    {
        int r = PyObject_SetItem( PySys_GetObject( (char *)"modules" ), const_str_digest_d174e39ef12748481d2d13702313aa6c, module_pygame$surfarray );

        assert( r != -1 );
    }
#endif

    // For deep importing of a module we need to have "__builtins__", so we set
    // it ourselves in the same way than CPython does. Note: This must be done
    // before the frame object is allocated, or else it may fail.

    if ( GET_STRING_DICT_VALUE( moduledict_pygame$surfarray, (Nuitka_StringObject *)const_str_plain___builtins__ ) == NULL )
    {
        PyObject *value = (PyObject *)builtin_module;

        // Check if main module, not a dict then but the module itself.
#if !defined(_NUITKA_EXE) || !0
        value = PyModule_GetDict( value );
#endif

        UPDATE_STRING_DICT0( moduledict_pygame$surfarray, (Nuitka_StringObject *)const_str_plain___builtins__, value );
    }

#if PYTHON_VERSION >= 300
    UPDATE_STRING_DICT0( moduledict_pygame$surfarray, (Nuitka_StringObject *)const_str_plain___loader__, metapath_based_loader );
#endif

#if PYTHON_VERSION >= 340
#if 0
    UPDATE_STRING_DICT0( moduledict_pygame$surfarray, (Nuitka_StringObject *)const_str_plain___spec__, Py_None );
#else
    {
        PyObject *bootstrap_module = PyImport_ImportModule("importlib._bootstrap");
        CHECK_OBJECT( bootstrap_module );
        PyObject *module_spec_class = PyObject_GetAttrString( bootstrap_module, "ModuleSpec" );
        Py_DECREF( bootstrap_module );

        PyObject *args[] = {
            GET_STRING_DICT_VALUE( moduledict_pygame$surfarray, (Nuitka_StringObject *)const_str_plain___name__ ),
            metapath_based_loader
        };

        PyObject *spec_value = CALL_FUNCTION_WITH_ARGS2(
            module_spec_class,
            args
        );

        SET_ATTRIBUTE( spec_value, const_str_plain__initializing, Py_True );

        UPDATE_STRING_DICT1( moduledict_pygame$surfarray, (Nuitka_StringObject *)const_str_plain___spec__, spec_value );

        Py_DECREF( module_spec_class );
    }
#endif
#endif


    // Temp variables if any
    PyObject *tmp_import_from_1__module = NULL;
    struct Nuitka_FrameObject *frame_a3fa1e2ffd1f1ed02d04d999e0ffedef;
    NUITKA_MAY_BE_UNUSED char const *type_description_1 = NULL;
    PyObject *exception_type = NULL;
    PyObject *exception_value = NULL;
    PyTracebackObject *exception_tb = NULL;
    NUITKA_MAY_BE_UNUSED int exception_lineno = 0;
    PyObject *exception_keeper_type_1;
    PyObject *exception_keeper_value_1;
    PyTracebackObject *exception_keeper_tb_1;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_1;

    // Module code.
    {
    PyObject *tmp_assign_source_1;
    tmp_assign_source_1 = const_str_digest_b80073d3143f23dee8fe8f20cfbaa10a;
    UPDATE_STRING_DICT0( moduledict_pygame$surfarray, (Nuitka_StringObject *)const_str_plain___doc__, tmp_assign_source_1 );
    }
    {
    PyObject *tmp_assign_source_2;
    tmp_assign_source_2 = const_str_digest_e7d9148c038f14a4d743a7ebc269c709;
    UPDATE_STRING_DICT0( moduledict_pygame$surfarray, (Nuitka_StringObject *)const_str_plain___file__, tmp_assign_source_2 );
    }
    {
    PyObject *tmp_assign_source_3;
    tmp_assign_source_3 = Py_None;
    UPDATE_STRING_DICT0( moduledict_pygame$surfarray, (Nuitka_StringObject *)const_str_plain___cached__, tmp_assign_source_3 );
    }
    // Frame without reuse.
    frame_a3fa1e2ffd1f1ed02d04d999e0ffedef = MAKE_MODULE_FRAME( codeobj_a3fa1e2ffd1f1ed02d04d999e0ffedef, module_pygame$surfarray );

    // Push the new frame as the currently active one, and we should be exclusively
    // owning it.
    pushFrameStack( frame_a3fa1e2ffd1f1ed02d04d999e0ffedef );
    assert( Py_REFCNT( frame_a3fa1e2ffd1f1ed02d04d999e0ffedef ) == 2 );

    // Framed code:
    {
    PyObject *tmp_assign_source_4;
    PyObject *tmp_import_name_from_1;
    PyObject *tmp_name_name_1;
    PyObject *tmp_globals_name_1;
    PyObject *tmp_locals_name_1;
    PyObject *tmp_fromlist_name_1;
    PyObject *tmp_level_name_1;
    tmp_name_name_1 = const_str_digest_b010b74deac075981c5003854bdfd1a6;
    tmp_globals_name_1 = (PyObject *)moduledict_pygame$surfarray;
    tmp_locals_name_1 = Py_None;
    tmp_fromlist_name_1 = Py_None;
    tmp_level_name_1 = const_int_0;
    frame_a3fa1e2ffd1f1ed02d04d999e0ffedef->m_frame.f_lineno = 64;
    tmp_import_name_from_1 = IMPORT_MODULE5( tmp_name_name_1, tmp_globals_name_1, tmp_locals_name_1, tmp_fromlist_name_1, tmp_level_name_1 );
    if ( tmp_import_name_from_1 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 64;

        goto frame_exception_exit_1;
    }
    tmp_assign_source_4 = IMPORT_NAME( tmp_import_name_from_1, const_str_plain__numpysurfarray );
    Py_DECREF( tmp_import_name_from_1 );
    if ( tmp_assign_source_4 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 64;

        goto frame_exception_exit_1;
    }
    UPDATE_STRING_DICT1( moduledict_pygame$surfarray, (Nuitka_StringObject *)const_str_plain_numpysf, tmp_assign_source_4 );
    }
    {
    PyObject *tmp_assign_source_5;
    PyObject *tmp_name_name_2;
    PyObject *tmp_globals_name_2;
    PyObject *tmp_locals_name_2;
    PyObject *tmp_fromlist_name_2;
    PyObject *tmp_level_name_2;
    tmp_name_name_2 = const_str_digest_e420c3319159a1e6d3a583b2fbaf6bd0;
    tmp_globals_name_2 = (PyObject *)moduledict_pygame$surfarray;
    tmp_locals_name_2 = Py_None;
    tmp_fromlist_name_2 = const_tuple_str_plain_array_to_surface_str_plain_make_surface_tuple;
    tmp_level_name_2 = const_int_0;
    frame_a3fa1e2ffd1f1ed02d04d999e0ffedef->m_frame.f_lineno = 66;
    tmp_assign_source_5 = IMPORT_MODULE5( tmp_name_name_2, tmp_globals_name_2, tmp_locals_name_2, tmp_fromlist_name_2, tmp_level_name_2 );
    if ( tmp_assign_source_5 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 66;

        goto frame_exception_exit_1;
    }
    assert( tmp_import_from_1__module == NULL );
    tmp_import_from_1__module = tmp_assign_source_5;

    }
    {
    // Tried code:
    {
    PyObject *tmp_assign_source_6;
    PyObject *tmp_import_name_from_2;
    CHECK_OBJECT( tmp_import_from_1__module );
    tmp_import_name_from_2 = tmp_import_from_1__module;
    tmp_assign_source_6 = IMPORT_NAME( tmp_import_name_from_2, const_str_plain_array_to_surface );
    if ( tmp_assign_source_6 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 66;

        goto try_except_handler_1;
    }
    UPDATE_STRING_DICT1( moduledict_pygame$surfarray, (Nuitka_StringObject *)const_str_plain_array_to_surface, tmp_assign_source_6 );
    }
    {
    PyObject *tmp_assign_source_7;
    PyObject *tmp_import_name_from_3;
    CHECK_OBJECT( tmp_import_from_1__module );
    tmp_import_name_from_3 = tmp_import_from_1__module;
    tmp_assign_source_7 = IMPORT_NAME( tmp_import_name_from_3, const_str_plain_make_surface );
    if ( tmp_assign_source_7 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 66;

        goto try_except_handler_1;
    }
    UPDATE_STRING_DICT1( moduledict_pygame$surfarray, (Nuitka_StringObject *)const_str_plain_pc_make_surface, tmp_assign_source_7 );
    }
    goto try_end_1;
    // Exception handler code:
    try_except_handler_1:;
    exception_keeper_type_1 = exception_type;
    exception_keeper_value_1 = exception_value;
    exception_keeper_tb_1 = exception_tb;
    exception_keeper_lineno_1 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = 0;

    {
    CHECK_OBJECT( (PyObject *)tmp_import_from_1__module );
    Py_DECREF( tmp_import_from_1__module );
    tmp_import_from_1__module = NULL;

    }
    {
    // Re-raise.
    exception_type = exception_keeper_type_1;
    exception_value = exception_keeper_value_1;
    exception_tb = exception_keeper_tb_1;
    exception_lineno = exception_keeper_lineno_1;

    goto frame_exception_exit_1;
    }
    // End of try:
    try_end_1:;
    }

    // Restore frame exception if necessary.
#if 0
    RESTORE_FRAME_EXCEPTION( frame_a3fa1e2ffd1f1ed02d04d999e0ffedef );
#endif
    popFrameStack();

    assertFrameObject( frame_a3fa1e2ffd1f1ed02d04d999e0ffedef );

    goto frame_no_exception_1;

    frame_exception_exit_1:;
#if 0
    RESTORE_FRAME_EXCEPTION( frame_a3fa1e2ffd1f1ed02d04d999e0ffedef );
#endif

    if ( exception_tb == NULL )
    {
        exception_tb = MAKE_TRACEBACK( frame_a3fa1e2ffd1f1ed02d04d999e0ffedef, exception_lineno );
    }
    else if ( exception_tb->tb_frame != &frame_a3fa1e2ffd1f1ed02d04d999e0ffedef->m_frame )
    {
        exception_tb = ADD_TRACEBACK( exception_tb, frame_a3fa1e2ffd1f1ed02d04d999e0ffedef, exception_lineno );
    }

    // Put the previous frame back on top.
    popFrameStack();

    // Return the error.
    goto module_exception_exit;

    frame_no_exception_1:;
    {
    CHECK_OBJECT( (PyObject *)tmp_import_from_1__module );
    Py_DECREF( tmp_import_from_1__module );
    tmp_import_from_1__module = NULL;

    }
    {
    PyObject *tmp_assign_source_8;
    tmp_assign_source_8 = MAKE_FUNCTION_pygame$surfarray$$$function_1_blit_array(  );



    UPDATE_STRING_DICT1( moduledict_pygame$surfarray, (Nuitka_StringObject *)const_str_plain_blit_array, tmp_assign_source_8 );
    }
    {
    PyObject *tmp_assign_source_9;
    tmp_assign_source_9 = MAKE_FUNCTION_pygame$surfarray$$$function_2_array2d(  );



    UPDATE_STRING_DICT1( moduledict_pygame$surfarray, (Nuitka_StringObject *)const_str_plain_array2d, tmp_assign_source_9 );
    }
    {
    PyObject *tmp_assign_source_10;
    tmp_assign_source_10 = MAKE_FUNCTION_pygame$surfarray$$$function_3_pixels2d(  );



    UPDATE_STRING_DICT1( moduledict_pygame$surfarray, (Nuitka_StringObject *)const_str_plain_pixels2d, tmp_assign_source_10 );
    }
    {
    PyObject *tmp_assign_source_11;
    tmp_assign_source_11 = MAKE_FUNCTION_pygame$surfarray$$$function_4_array3d(  );



    UPDATE_STRING_DICT1( moduledict_pygame$surfarray, (Nuitka_StringObject *)const_str_plain_array3d, tmp_assign_source_11 );
    }
    {
    PyObject *tmp_assign_source_12;
    tmp_assign_source_12 = MAKE_FUNCTION_pygame$surfarray$$$function_5_pixels3d(  );



    UPDATE_STRING_DICT1( moduledict_pygame$surfarray, (Nuitka_StringObject *)const_str_plain_pixels3d, tmp_assign_source_12 );
    }
    {
    PyObject *tmp_assign_source_13;
    tmp_assign_source_13 = MAKE_FUNCTION_pygame$surfarray$$$function_6_array_alpha(  );



    UPDATE_STRING_DICT1( moduledict_pygame$surfarray, (Nuitka_StringObject *)const_str_plain_array_alpha, tmp_assign_source_13 );
    }
    {
    PyObject *tmp_assign_source_14;
    tmp_assign_source_14 = MAKE_FUNCTION_pygame$surfarray$$$function_7_pixels_alpha(  );



    UPDATE_STRING_DICT1( moduledict_pygame$surfarray, (Nuitka_StringObject *)const_str_plain_pixels_alpha, tmp_assign_source_14 );
    }
    {
    PyObject *tmp_assign_source_15;
    tmp_assign_source_15 = MAKE_FUNCTION_pygame$surfarray$$$function_8_pixels_red(  );



    UPDATE_STRING_DICT1( moduledict_pygame$surfarray, (Nuitka_StringObject *)const_str_plain_pixels_red, tmp_assign_source_15 );
    }
    {
    PyObject *tmp_assign_source_16;
    tmp_assign_source_16 = MAKE_FUNCTION_pygame$surfarray$$$function_9_pixels_green(  );



    UPDATE_STRING_DICT1( moduledict_pygame$surfarray, (Nuitka_StringObject *)const_str_plain_pixels_green, tmp_assign_source_16 );
    }
    {
    PyObject *tmp_assign_source_17;
    tmp_assign_source_17 = MAKE_FUNCTION_pygame$surfarray$$$function_10_pixels_blue(  );



    UPDATE_STRING_DICT1( moduledict_pygame$surfarray, (Nuitka_StringObject *)const_str_plain_pixels_blue, tmp_assign_source_17 );
    }
    {
    PyObject *tmp_assign_source_18;
    tmp_assign_source_18 = MAKE_FUNCTION_pygame$surfarray$$$function_11_array_colorkey(  );



    UPDATE_STRING_DICT1( moduledict_pygame$surfarray, (Nuitka_StringObject *)const_str_plain_array_colorkey, tmp_assign_source_18 );
    }
    {
    PyObject *tmp_assign_source_19;
    tmp_assign_source_19 = MAKE_FUNCTION_pygame$surfarray$$$function_12_make_surface(  );



    UPDATE_STRING_DICT1( moduledict_pygame$surfarray, (Nuitka_StringObject *)const_str_plain_make_surface, tmp_assign_source_19 );
    }
    {
    PyObject *tmp_assign_source_20;
    tmp_assign_source_20 = MAKE_FUNCTION_pygame$surfarray$$$function_13_map_array(  );



    UPDATE_STRING_DICT1( moduledict_pygame$surfarray, (Nuitka_StringObject *)const_str_plain_map_array, tmp_assign_source_20 );
    }
    {
    PyObject *tmp_assign_source_21;
    tmp_assign_source_21 = MAKE_FUNCTION_pygame$surfarray$$$function_14_use_arraytype(  );



    UPDATE_STRING_DICT1( moduledict_pygame$surfarray, (Nuitka_StringObject *)const_str_plain_use_arraytype, tmp_assign_source_21 );
    }
    {
    PyObject *tmp_assign_source_22;
    tmp_assign_source_22 = MAKE_FUNCTION_pygame$surfarray$$$function_15_get_arraytype(  );



    UPDATE_STRING_DICT1( moduledict_pygame$surfarray, (Nuitka_StringObject *)const_str_plain_get_arraytype, tmp_assign_source_22 );
    }
    {
    PyObject *tmp_assign_source_23;
    tmp_assign_source_23 = MAKE_FUNCTION_pygame$surfarray$$$function_16_get_arraytypes(  );



    UPDATE_STRING_DICT1( moduledict_pygame$surfarray, (Nuitka_StringObject *)const_str_plain_get_arraytypes, tmp_assign_source_23 );
    }

    return MOD_RETURN_VALUE( module_pygame$surfarray );
    module_exception_exit:
    RESTORE_ERROR_OCCURRED( exception_type, exception_value, exception_tb );
    return MOD_RETURN_VALUE( NULL );
}
