//
// Created by tryggve on 3/2/19.
//
// Simple file writer class representing a dataset.
// Functionality
//
//

#ifndef CMAKETUT_DATASET_H
#define CMAKETUT_DATASET_H

#include <string>
#include <cstdio>                   // C stdio.h standard IO library

class DataSet {
private:
    FILE *dsFile;                       // File stream handler reference

    // The persistFileName will change to reflect the dataset name.
    std::string persistFileName = "dataset.txt";
    std::string dsName = "";
public:
    const std::string &getDsName() const;
    // Dataset name
public:
    const std::string &getDataSetBuffer() const;

    void setDataSetBuffer(std::string dataSetBuffer);

private:
    // File where to store the data set.
    std::string dataSetBuffer;         // Dataset buffer - simple example a string array

public:
    DataSet();                              // Default constructor
    explicit DataSet(std::string datasetName); // Dataset with custom name
    void printDataset();                    // Create a nice output of the dataset.

    // Save dataset
    // Parameters:
    //      in: None
    //      out: int    The number of bytes written to the dataset file.
    //                  If error a negative value is returned.
    int saveDataset();              // Persist dataset to file

    // Read dataset
    // This method reads the dataset from persistent storage and populates the internal buffer
    // Parameters:
    //      in: string  Name of the dataset.
    //      out: int    The number of bytes read from the dataset file.
    //                  If error a negative value is returned, for example if the file does not exist.
    //                  This is a case that should be handled by the caller of the method.
    int readDataset();

};


#endif //CMAKETUT_DATASET_H
