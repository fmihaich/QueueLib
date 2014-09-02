#ifndef VECTORTESTCLASS_H
#define VECTORTESTCLASS_H

#include <iostream>
#include <cppunit/extensions/HelperMacros.h>
#include "Vector.h"

class vectortest : public CPPUNIT_NS::TestFixture 
{
    CPPUNIT_TEST_SUITE(vectortest);

    CPPUNIT_TEST(testVectorIsBuiltBasedOnDefaultConstructor);
    CPPUNIT_TEST(testVectorIsBuiltBasedOnAnUnsignedInt);
    CPPUNIT_TEST(testVectorIsBuiltBasedOnAnArrayAndAnUnsignedInt);
    CPPUNIT_TEST(testVectorIsBuiltBasedOnOtherVector);
    CPPUNIT_TEST(testAddition);
    CPPUNIT_TEST(testAdditionFailsWhenDifferentVectorLenghts);
    CPPUNIT_TEST(testDotProduct);
    CPPUNIT_TEST(testDotProductFailsWhenDifferentVectorLenghts);
    CPPUNIT_TEST(testGetArray);
    CPPUNIT_TEST(testSetArray);
    CPPUNIT_TEST(testSetElementModifiesTheCorrectVectorElement);
    CPPUNIT_TEST(testSetElementFailsWhenIndexOutOfRange);
    CPPUNIT_TEST(testGetElementReturnsTheCorrectElement);
    CPPUNIT_TEST(testGetElementFailsWhenIndexOutOfRange);

    CPPUNIT_TEST_SUITE_END();

public:
    vectortest();
    virtual ~vectortest();
    void setUp();
    void tearDown();
    static double* getArrayAux(Vector &v)
    {
        double* array;
        switch(array_getter_defined){
            case 0:
                // [Flor] This implementation was not choosen.
                //v.getArray(array);
                break;
            case 1: 
                array = v.getArray();
                break;
        }
        return array;
    }

private:
    void testVectorIsBuiltBasedOnDefaultConstructor();
    void testVectorIsBuiltBasedOnAnUnsignedInt();
    void testVectorIsBuiltBasedOnAnArrayAndAnUnsignedInt();
    void testVectorIsBuiltBasedOnOtherVector();
    void testAddition();
    void testAdditionFailsWhenDifferentVectorLenghts();
    void testDotProduct();
    void testDotProductFailsWhenDifferentVectorLenghts();
    void testGetArray();
    void testSetArray();
    void testSetElementModifiesTheCorrectVectorElement();
    void testSetElementFailsWhenIndexOutOfRange();
    void testGetElementReturnsTheCorrectElement();
    void testGetElementFailsWhenIndexOutOfRange();

    double* myArray_;
    unsigned int nMyArray_;
    double* mySecondArray_;
};

#endif	/* VECTORTESTCLASS_H */

