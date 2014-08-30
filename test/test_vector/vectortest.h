#ifndef VECTORTESTCLASS_H
#define VECTORTESTCLASS_H

#include <iostream>
#include <cppunit/extensions/HelperMacros.h>
#include "Vector.h"

class vectortest : public CPPUNIT_NS::TestFixture 
{
    CPPUNIT_TEST_SUITE(vectortest);

    CPPUNIT_TEST(testVector);
    CPPUNIT_TEST(testAddition);
    CPPUNIT_TEST(testDotProduct);
    CPPUNIT_TEST(testGetArray);
    CPPUNIT_TEST(testSetArray);

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
                v.getArray(array);
                break;
            case 1: 
                array = v.getArray();
                break;
        }
        return array;
    }

private:
    void testVector();
    void testAddition();
    void testDotProduct();
    void testGetArray();
    void testSetArray(); 
    
    double* myArray_;
    unsigned int nMyArray_;
    double* mySecondArray_;
};

#endif	/* VECTORTESTCLASS_H */

