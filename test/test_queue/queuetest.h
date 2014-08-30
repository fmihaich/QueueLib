#ifndef QUEUETEST_H
#define	QUEUETEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "Queue.h"
#include "../test_vector/vectortest.h"

class queuetest : public CPPUNIT_NS::TestFixture 
{
    CPPUNIT_TEST_SUITE(queuetest);

    CPPUNIT_TEST(testQueue);
    CPPUNIT_TEST(testEnqueue);
    CPPUNIT_TEST(testFullEnqueue);    
    CPPUNIT_TEST(testDequeue);
    CPPUNIT_TEST(testGetArray);

    CPPUNIT_TEST_SUITE_END();

public:
    queuetest();
    virtual ~queuetest();
    void setUp();
    void tearDown();
    static double* getArrayAux(Queue& queue);

private:
    void testQueue();
    void testEnqueue();
    void testFullEnqueue();    
    void testDequeue();
    void testGetArray();
    
    double* myArray_;
    unsigned int nMyArray_;
};

#endif	/* QUEUETEST_H */

