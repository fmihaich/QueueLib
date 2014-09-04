#ifndef QUEUE_H
#define	QUEUE_H

#include "Vector.h"

const int vector_getter_defined = 3; //this is just to be used for unit testing.


/**
 * Queue class
 * Representation of a Queue as in "http://en.wikipedia.org/wiki/Queue_(data_structure)"
 */
class Queue
{
public:

    /**
     * Constructor. Empty queue
     */
    Queue();

    /**
     * Constructor
     * @param length is the size of the queue
     * @warning does this method have any sense?
     * [Flor] I don't consider necessary to implement this constructor
     * [Flor] I'll implement it just for testing. It's a way to set maxSize_
     */
    Queue(unsigned int length);
    
    /**
     * Constructor (copy)
     * @param q queue to be copied
     */
    Queue(const Queue &q);
    
    /**
     * Destructor.
     * @warning should it be virtual?
     */
    ~Queue();

    /**
     * Enqueue an element (append it to the end of the queue)
     * @param element to be enqueued
     */
    void enqueue(const double element);

    /**
     * Dequeue an element (extract it from the front of the queue)
     * @return first element in the queue
     */
    double dequeue();

    /**
     * Getter of the inner structure to store de queue
     * @param ??
     * @return ??
     * @warning CHOOSE ONE AND ONLY ONE OF THE DEFINITIONS BELOW
     * 
     * [Flor] I chose this in order to make the prototype independient of vector
     */
    double* getArray();
    //or
    //void getArray(double *array);
    //or
    //Vector getArray();

    //add here whatever you want
    
private:

    Vector *queue_;
    //add here whatever you want
    unsigned int size_;
    unsigned int maxSize_;
    int first_;
    int next_;
    
    bool isEmpty();
    bool isFull();
    void reallocate();
};

#endif	/* QUEUE_H */

