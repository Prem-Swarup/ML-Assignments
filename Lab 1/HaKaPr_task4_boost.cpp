// The macro BOOST_BIND_GLOBAL_PLACEHOLDERS is used in the Boost C++ libraries to enable the use of
// C++11 placeholder features in the Boost.Bind and Boost.Function libraries
#define BOOST_BIND_GLOBAL_PLACEHOLDERS
#include <boost/python/numpy.hpp>
#include <boost/python.hpp>
#include <bits/stdc++.h>
namespace np = boost::python::numpy;
namespace p = boost::python;

// This function takes two numpy 2d-arrays as input parameters, cast them in native c++ abstract data types, perform matrix multiplication, then recast result into numpy 2d-array and return the result
np::ndarray matrmul(np::ndarray const &a, np::ndarray const &b)
{
    // check if the shapes of the matrices are compatible for matrix multiplication
    if (a.shape(1) != b.shape(0))
        throw std::runtime_error("Incompatible shapes for matrix multiplication");

    // storing rows and columns of both matrices
    int a_rows = a.shape(0), a_cols = a.shape(1), b_cols = b.shape(1);

    // casting both matrices into c++ array for fast calculations
    int *m1 = reinterpret_cast<int *>(a.get_data());
    int *m2 = reinterpret_cast<int *>(b.get_data());

    // intialising matrix to store result
    int c[a_rows][b_cols];

    // perform the matrix multiplication
    for (int i = 0; i < a_rows; i++)
    {
        for (int j = 0; j < b_cols; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < a_cols; k++)
            {
                c[i][j] += m1[2 * (i * a_rows + k)] * m2[2 * (k * a_cols + j)];
            }
        }
    }

    // initialising and assigning ndarray to return the result to python code
    np::ndarray res = np::zeros(p::make_tuple(a_rows, b_cols), np::dtype::get_builtin<int>());
    for (int i = 0; i < a_rows; ++i)
    {
        for (int j = 0; j < b_cols; ++j)
        {
            res[i][j] = c[i][j];
        }
    }
    return res;
}

// Deciding what to expose in the library python can import
BOOST_PYTHON_MODULE(HaKaPr_task4_boost)
{ // Thing in brackets should match output library name

    // Py_Initialize() is a function from the Python C API that initializes the Python interpreter
    Py_Initialize();
    np::initialize();
    p::def("matrmul", matrmul); // defining that can be called by importing module
}
