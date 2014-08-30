#ifndef VECTOR_H
#define	VECTOR_H

#include <string>
#include <cassert>

const int add_vectors_defined = 0; //this is just to be used for unitary test.
const int array_getter_defined = 1; //this is just to be used for unitary test.

/**
 * Vector class
 * Representation of a vector and its operations
 */
class Vector
{
  public:

    /**
     * Costructor. Default constructor.
     */
    Vector();

    /**
     * Costructor. Copy vector v.
     * @param v vector to be copied
     */
    Vector(const Vector &v);

    /**
     * Constructor. Initializes size and memory allocation
     * @param n is the size of the vector
     */
    Vector(unsigned int n);

    /**
     * Constructor. nArray-dimensional array
     * @param array to be copied in the current object
     * @param nArray size of the array
     */
    Vector(const double* const array, const unsigned int nArray);

    /**
     * Destructor.
     * @warning this destructor MUST be virtual. Why???
     */
    virtual ~Vector();

    /** @name Operations */
    //@{
    /**
     * Addition of vectors
     * @param v the first vector to be added
     * @param w the second vector to be added
     * @return the vector v + w
     * @warning CHOOSE ONE AND ONLY ONE OF THE DEFINITIONS BELOW
     */
    friend Vector operator+(const Vector& v, const Vector& w);
    //or
    Vector& operator+(const Vector& v);
    //or
    friend Vector addition(const Vector& v, const Vector& w);

    /**
     * Addition of matrices
     * @param A the first matrix to be added
     * @param B the second matrix to be added
     * @returns the matrix A + B
     */
    friend double dotProduct(const Vector& v, const Vector& w);
    //@}

    /**
     * Getter of the array
     * @param ??
     * @return ??
     * @warning CHOOSE ONE AND ONLY ONE OF THE DEFINITIONS BELOW
     */
    void getArray(double* array /*in this pointer the inner array is stored*/) const;
    //or
    double* getArray() const;

    /**
     * Setter of the array
     * @param array to be copied in the current object
     * @param nArray size of the array
     */
    void setArray(const double* const array, const unsigned int nArray);

    /**
     * Get the number of elements of the vector
     * @return size of vector
     */
    unsigned int getSize() const;

    /**
     * Get the vector as a string
     * @return a string that represents the vector
     */
    std::string toString();

    /**
     * Set an element in a given position of vector
     * @param (elem) element to set in
     * @param (pos) position in array
     */
    void set(double elem, unsigned int pos);

    /**
     * Get an element at position
     * @param (pos) position in array
     * @return vector[pos]
     */
    double get(unsigned int pos);

    //add here whatever you want
    
private:

    double* array_;
    unsigned int size_;
    //add here whatever you want
};

#endif	/* VECTOR_H */

