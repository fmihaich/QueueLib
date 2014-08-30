====================================================
=C++ training project in Ascentio Technologies S.A.=
====================================================

The main idea of this project is to define a library in C++ (without using STL libraries) to model a queue (http://en.wikipedia.org/wiki/Queue_(data_structure)). The queue being defined have to be "based" on a vector. Being "based on" means that a vector could be an attribute of queue class, or queue could inherit from a vector, or whatever...

The interfaces are defined (partially) in Vector.h and Queue.h. Some signatures like "friend Vector operator+(const Vector& v, const Vector& w);", "Vector& operator+(const Vector& v);" or "friend Vector addition(const Vector& v, const Vector& w);" are optional. The idea is that the programmer chooses the one s/he considers the best.

The developer is asked to implement Queue.cpp and Vector.cpp to be able to model the abstract data type queue, and run its unitary tests. The tests implemented in test/test_* may be modified to accept the interface defined.


To compile the project:

$ cmake .
$ make

To run unitary tests: 

$make test


NOTES: 
1) The unit tests may fail due to the definition of the optional tests defined. Some lines should be commented.
2) You can add any method or attribute you want (or need) to.
3) Be aware that these classes can be implemented in multiple ways. The main idea of this project is to discuss why you have chosen "that way" to implement it.
4) Please, notify us in case you find any error.

