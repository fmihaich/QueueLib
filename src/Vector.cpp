#include "Vector.h"
#include <iostream>
#include <stdlib.h>
#include "VectorException.h"


const unsigned int DEFAULT_SIZE = 0;
const unsigned int DEFAULT_MAX_SIZE = 100;


void copyArray(const double* const inputArray, 
               double* const outputArray, const unsigned int arraySize){
    for (unsigned int i = 0; i < arraySize; i++){
        outputArray[i] = inputArray[i];
    } 
}


Vector::Vector(){
    new (this) Vector(0);
}


Vector::Vector(unsigned int n): size_(n), maxSize_(DEFAULT_MAX_SIZE){
    maxSize_ = (1 + n / DEFAULT_MAX_SIZE) * DEFAULT_MAX_SIZE;
    array_ = (double*) calloc (maxSize_, sizeof(double));
    if (!array_){
        throw VectorException(std::string("Not enought memory"));
    }
}


Vector::Vector(const double* const array, const unsigned int nArray) {
    new (this) Vector(nArray);
    copyArray(array, array_, nArray);
}


Vector::Vector(const Vector& v){
    new (this) Vector(v.array_, v.size_);
}


Vector::~Vector(){
    size_ = 0;
    free(array_);
    array_ = NULL;
}


double* Vector::getArray() const{
    double* array = (double*) calloc (this->size_, sizeof(double));
    if (!array){
        throw VectorException(std::string("Not enought memory"));
    }
    copyArray(this->array_, array, this->size_);
    return array;
}


Vector operator+(const Vector& v, const Vector& w){
    if (v.size_ != w.size_){
        throw VectorException(std::string("Not equal vector lenght"));
    }
    
    Vector result(v);
    for (unsigned int i = 0; i < v.size_; i++){
        result.array_[i] += w.array_[i];
    }
    
    return result;
}


double dotProduct(const Vector& v, const Vector& w){
    if (v.size_ != w.size_){
        throw VectorException(std::string("Not equal vector lenght"));
    }
    
    double result = 0.0;
    for (int i = 0; i < v.size_; i++){
        result += v.array_[i] * w.array_[i];
    }
    
    return result;
}


void Vector::setArray(const double* const array, const unsigned int nArray){
    unsigned int newSize = (1 + nArray / DEFAULT_MAX_SIZE) * DEFAULT_MAX_SIZE;
    double* aux = (double*) realloc (this->array_, newSize * sizeof(double));
    if (!aux){
        throw VectorException(std::string("Not enought memory"));
    }
    
    this->maxSize_ = newSize;
    this->size_ = nArray;
    copyArray(array, this->array_, nArray);
}


unsigned int Vector::getSize() const{
    return this->size_;
}


void Vector::set(double elem, unsigned int pos){
    if (pos >= this->size_){
        throw VectorException(std::string("Index out of range"));
    }
    
    this->array_[pos] = elem;
}

double Vector::get(unsigned int pos){
    if (pos >= this->size_){
        throw VectorException(std::string("Index out of range"));
    }
    
    return this->array_[pos];
}

