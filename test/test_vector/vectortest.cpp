#include <iostream>
#include "vectortest.h"
#include "VectorException.h"

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


void vectortest::testVectorIsBuiltBasedOnDefaultConstructor(){
    Vector v;    
    CPPUNIT_ASSERT(v.getSize() == 0);
}


void vectortest::testVectorIsBuiltBasedOnAnUnsignedInt(){
    unsigned int vectorSize = 501;
    Vector v(vectorSize);
    CPPUNIT_ASSERT(v.getSize() == vectorSize);
}


void vectortest::testVectorIsBuiltBasedOnAnArrayAndAnUnsignedInt() 
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


void vectortest::testVectorIsBuiltBasedOnOtherVector() 
{
    double* baseArray = myArray_;
    unsigned int baseSize = nMyArray_;
    Vector baseVector(baseArray, baseSize);
    
    Vector testVector(baseVector);
    
    double* testArray = new double [baseSize];
    testArray = getArrayAux(testVector);
    
    bool ans = true;
    for (unsigned int i = 0; i < baseSize; i++){
        ans = ans && (baseArray[i] == testArray[i]);
    }
    
    // delete the array just created
    delete [] testArray;
    
    CPPUNIT_ASSERT(ans);
}


void vectortest::testAddition() 
{
    Vector v(myArray_, nMyArray_);
    Vector w(mySecondArray_, nMyArray_);
    double* array = new double [nMyArray_];
    Vector vector = v + w;
    array = getArrayAux(vector);

    bool ans = true;
    for (unsigned int i = 0; i < nMyArray_; i++){
        ans = ans && (myArray_[i] + mySecondArray_[i] == array[i]);
    }
    
    // delete the array just created
    delete [] array;
    
    CPPUNIT_ASSERT(ans);
}


void vectortest::testAdditionFailsWhenDifferentVectorLenghts() 
{
    double singleArray [] = {1};
    unsigned int nSingleArray = 1;
    Vector v(singleArray, nSingleArray);
    
    Vector w(mySecondArray_, nMyArray_);
    
    bool exceptionCaught = false;
    try{
        v + w;
    }
    catch (VectorException){
        exceptionCaught = true;
    }
    catch(std::exception){
        exceptionCaught = false;
    }
    
    CPPUNIT_ASSERT(exceptionCaught);
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


void vectortest::testDotProductFailsWhenDifferentVectorLenghts() 
{
    double singleArray [] = {1};
    unsigned int nSingleArray = 1;
    Vector v(singleArray, nSingleArray);
    
    Vector w(mySecondArray_, nMyArray_);
    
    bool exceptionCaught = false;
    try{
        dotProduct(v,w);
    }
    catch (VectorException){
        exceptionCaught = true;
    }
    catch(std::exception){
        exceptionCaught = false;
    }
    
    CPPUNIT_ASSERT(exceptionCaught);
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


void vectortest::testSetElementModifiesTheCorrectVectorElement(){
    Vector v(myArray_, nMyArray_);
    
    for (unsigned int i = 0; i < nMyArray_; i++){
        v.set(mySecondArray_[i], i);
    }    
    
    double* array = new double [nMyArray_];
    array = getArrayAux(v);    
    
    bool ans = true;
    for (unsigned int i = 0; i < nMyArray_; i++){
        ans = ans && (mySecondArray_[i] == array[i]);
    }
    delete [] array;
    
    CPPUNIT_ASSERT(ans);
}

void vectortest::testSetElementFailsWhenIndexOutOfRange(){
    Vector v(myArray_, nMyArray_);
    const double newValue = 35.65;
    
    bool exceptionCaught = false;
    try{
        v.set(nMyArray_, newValue);
    }
    catch (VectorException){
        exceptionCaught = true;
    }
    catch(std::exception){
        exceptionCaught = false;
    }
    
    CPPUNIT_ASSERT(exceptionCaught);
}


void vectortest::testGetElementReturnsTheCorrectElement(){
    Vector v(myArray_, nMyArray_);
    
    bool ans = true;
    for (unsigned int i = 0; i < nMyArray_; i++){
        ans = ans && (myArray_[i] == v.get(i));
    }
    
    CPPUNIT_ASSERT(ans);
}

void vectortest::testGetElementFailsWhenIndexOutOfRange(){
    Vector v(myArray_, nMyArray_);
    
    bool exceptionCaught = false;
    try{
        v.get(nMyArray_);
    }
    catch (VectorException){
        exceptionCaught = true;
    }
    catch(std::exception){
        exceptionCaught = false;
    }
    
    CPPUNIT_ASSERT(exceptionCaught);
}