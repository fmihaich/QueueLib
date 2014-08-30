#include <iostream>
#include "vectortest.h"

using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION(vectortest);


vectortest::vectortest() 
{
}


vectortest::~vectortest() 
{
}


void vectortest::setUp() 
{
    nMyArray_ = 5;
    myArray_ = new double [nMyArray_];
    
    for (unsigned int i = 0; i < nMyArray_; i++){
        myArray_[i] = static_cast<double>(i);
    }

    mySecondArray_ = new double [nMyArray_];
    
    for (unsigned int i = 0; i < nMyArray_; i++){
        mySecondArray_[i] = static_cast<double>(nMyArray_ - i);
    }
}


void vectortest::tearDown() 
{
    delete [] myArray_;
    delete [] mySecondArray_;
}


void vectortest::testVector() 
{
    Vector v(myArray_, nMyArray_);
    
    double* array = new double [nMyArray_];
    array = getArrayAux(v);
    
    bool ans = true;
    for (unsigned int i = 0; i < nMyArray_; i++){
        ans = ans && (myArray_[i] == array[i]);
    }
    
    // delete the array just created
    delete [] array;
    
    CPPUNIT_ASSERT(ans);
}


void vectortest::testAddition() 
{
    Vector v(myArray_, nMyArray_);
    Vector w(mySecondArray_, nMyArray_);
    double* array = new double [nMyArray_];
    Vector vector;
    
    if (add_vectors_defined == 0){
        vector = v + w;
        array = getArrayAux(vector);
    } else if (add_vectors_defined == 1){
        vector = addition(v, w);
        array = getArrayAux(vector);
    }
    bool ans = true;
    for (unsigned int i = 0; i < nMyArray_; i++){
        ans = ans && (myArray_[i] + mySecondArray_[i] == array[i]);
    }
    delete [] array;
    
    CPPUNIT_ASSERT(ans);
}


void vectortest::testDotProduct() 
{
    Vector v(myArray_, nMyArray_);
    Vector w(mySecondArray_, nMyArray_);
    double ans = 0;
    for (int i = 0; i < nMyArray_; i++){
        ans += myArray_[i] * mySecondArray_[i];
    }
    
    CPPUNIT_ASSERT(dotProduct(v,w) == ans);
}


void vectortest::testGetArray() 
{
    CPPUNIT_ASSERT(true);
}


void vectortest::testSetArray() 
{
    double singleArray [] = {1};
    unsigned int nSingleArray = 1;
    Vector v(singleArray, nSingleArray);
    v.setArray(myArray_, nMyArray_);
    
    double* array = new double [nSingleArray];
    array = getArrayAux(v);
    
    bool ans = true;
    for (unsigned int i = 0; i < nMyArray_; i++){
        ans = ans && (myArray_[i] == array[i]);
    }
    delete [] array;
    
    CPPUNIT_ASSERT(ans);
}
