# Matrix-Manipulation
This is a program I developed in my first year of university while taking a linear algebra course. It has some interesting matrix manipulation algorithms.


## Quick Start

## Example 

## Requirements
boost multiprecision c++ library
c++ 11

## Theory
This program follows more or less the Gaussian Elimination algorithm.
By doing row operations such as adding a row to another row and multiplying a row by a nonzero value it attempts to create an upper triangular form of the matrix (form where all the elements below the diagonal is 0).
Continuing in a similar manner a invertible matrix can be turned into an identity matrix. If you perform the same set of operations on an identity matrix it turns into the inverse of the initial matrix. 

This process can give a lot of insight into the initial matrix such as its rank, (as stated above) if it exists: its inverse and its determinant.  
