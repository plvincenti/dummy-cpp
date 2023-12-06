#include "OutputDTO.hh"

#include <iostream>
#include <fstream>
#include <sstream>

namespace dummy
{

const void CsvOutputDTO::dumpData(const Data& data_p)
{

   // Open output file
  std::ofstream outputFile_l(outputFilePath_m);

  // Check file opening
  if (!outputFile_l.is_open()) {
    throw std::runtime_error("Impossible to write the outut file");
  }

  std::cout << "[INFO] Start Writting " << outputFilePath_m << std::endl;
  
  // Writting data into output file

  for (const auto& line_l : data_p.getData()){
    for (const auto& value_l : line_l){
      outputFile_l << value_l << ";";   
    }
    outputFile_l << std::endl;
  }

  // Closing output file
  outputFile_l.close();
  std::cout << "[INFO] End Writting " << outputFilePath_m << std::endl;
}

}