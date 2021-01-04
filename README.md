# Matrix-Manipulation
This is a program I developed in my first year of university while taking a linear algebra course. It has some interesting matrix manipulation algorithms.


## Quick Start
Run on linux without installing boost library

0. ```cd/tmp``` [OPTIONAL]
1. ```git clone git@github.com:xalhs/Matrix-Manipulation.git``` (clone repo)  
    - ```cd Matrix-Manipulation```
2. ```wget https://dl.bintray.com/boostorg/release/1.75.0/source/boost_1_75_0.tar.gz``` (download boost library)
3. ```tar -zxvf boost_1_75_0``` (untar downloaded file)
4. ```g++ Row_operations.cpp -I boost_1_75_0/ -std=c++11```  (compile)
5. ```./a.out```  (run executable file)

## Example 

## Requirements
boost multiprecision c++ library
c++ 11

## Theory
This program follows more or less the Gaussian Elimination algorithm.
By doing row operations such as adding a row to another row and multiplying a row by a nonzero value it attempts to create an upper triangular form of the matrix (form where all the elements below the diagonal is 0).
Continuing in a similar manner a invertible matrix can be turned into an identity matrix. If you perform the same set of operations on an identity matrix it turns into the inverse of the initial matrix. 

This process can give a lot of insight into the initial matrix such as its rank, (as stated above) if it exists: its inverse and its determinant.  
