#include "InputDTO.hh"

#include <iostream>
#include <fstream>
#include <sstream>

namespace dummy
{

    void CsvInputDTO::fillData(Data& data_p)
    {
        // open input file
        std::ifstream inputFile_l(inputFilePath_m);

        // check file opening
        if (!inputFile_l.is_open()) {
            throw std::runtime_error("Impossible to read the input file");
        }

        std::cout << "[INFO] Start Reading " << inputFilePath_m << std::endl;

        // Reading file line by line
        std::string line_l;
        
        while (getline(inputFile_l, line_l)) {
            
            // Extracting values on line
            std::stringstream stream_l(line_l);
            std::vector<std::string> values_l;
            std::string value_l;
            
            while (getline(stream_l, value_l, csvSeparator_m)) {
            values_l.push_back(value_l);
            }

            // Add line to Data object
            data_p.addLineToData(values_l);
        }

        // Close input file
        inputFile_l.close();
        std::cout << "[INFO] End Reading " << inputFilePath_m << std::endl;

    }
}