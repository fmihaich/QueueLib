#include "Queue.h"
#include "VectorException.h"
#include "QueueException.h"



const unsigned int DEFAULT_SIZE = 0;
const unsigned int DEFAULT_MAX_SIZE = 100;

/*
 * QUICK NOTES: 
 * first_: shall always point to the first element of the queue
 * next_: shall always point to the possition for an incoming element.
 */


Queue::Queue(): size_(DEFAULT_SIZE), maxSize_(DEFAULT_MAX_SIZE),
                first_(0), next_(0){
    queue_ = new Vector(maxSize_);
}

Queue::Queue(unsigned int length): size_(DEFAULT_SIZE), maxSize_(length),
                                   first_(0), next_(0){
    queue_ = new Vector(maxSize_);
}



Queue::~Queue(){
}


void Queue::enqueue(const double element){
    if (this->isFull()){
        this->reallocate();
    }
    
    this->queue_->set(element, this->next_);
    this->size_ += 1;
    this->next_ = (this->next_ + 1) % this->maxSize_;
}


double Queue::dequeue(){
    if(this->isEmpty()){
        throw QueueException("Dequeuing and empty queue");
    }
    
    double currentElement = this->queue_->get(this->first_);
    
    this->size_ -= 1;
    this->first_ = (this->first_ + 1) % this->maxSize_;
    
    return currentElement;
}


double* Queue::getArray(){
    double* array = new double [this->size_];
    for (unsigned int i = 0; i < this->size_; i++){
        array[i] = this->queue_->get((this->first_ + i) % this->maxSize_);
    }
    return array;
}


bool Queue::isEmpty(){
    return this->size_ == 0;
}


bool Queue::isFull(){
    return this->size_ == this->maxSize_;
}


void Queue::reallocate(){
    unsigned int newSize = 2*this->maxSize_;
    Vector* newQueue = NULL;
    try{
        newQueue = new Vector(newSize);
    }
    catch (VectorException){
        throw QueueException("Queue rellocation error");
    }
    
    for(unsigned int i = 0; i < this->size_; i++){
        newQueue->set(this->queue_->get((this->first_+i)%this->maxSize_),i);
    }
    
    delete this->queue_;
    this->queue_ = newQueue;
    
    this->first_ = 0;
    this->next_ = this->size_;
    this->maxSize_ = newSize;
}