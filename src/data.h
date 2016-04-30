// -*- C++ -*-
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Written (W) 2010 Amir Saffari, amir@ymer.org
 * Copyright (C) 2010 Amir Saffari, 
 *                    Institute for Computer Graphics and Vision, 
 *                    Graz University of Technology, Austria
 */

#ifndef DATA_H_
#define DATA_H_

#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <set>
#include <string>
//#define EIGEN2_SUPPORT
#include <Eigen/Core>
//#include <Eigen/Array>

// DATA CLASSES
class Sample {
public:
    Eigen::VectorXd x;
    int y;
    double w;
    int id;
};

class DataSet {
 public:
    void findFeatRange();

    void load(const std::string& x_filename, const std::string& y_filename);

    std::vector<Sample> m_samples;
    int m_numSamples;
    int m_numFeatures;
    int m_numClasses;

    Eigen::VectorXd m_minFeatRange;
    Eigen::VectorXd m_maxFeatRange;
};

class Result {
 public:
    Result();
    Result(const int& numClasses);

    Eigen::VectorXd confidence;
    int prediction;
};

class Cache {
public:
    Cache();
    Cache(const Sample& sample, const int& numBases, const int& numClasses);

    Sample cacheSample;
    double margin;
    int yPrime; // Class with closest margin to the sample
};

#endif /* DATA_H_ */
