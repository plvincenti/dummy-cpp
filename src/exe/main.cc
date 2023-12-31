#include "Data.hh"
#include "InputDTO.hh"
#include "OutputDTO.hh"

#include <vector>
#include <iostream>

#include <boost/program_options.hpp>

std::pair<std::string, std::string> processCommandLine(int argc, char* argv[]){
  
  std::vector<std::string> vArg_l;
  for (int index_l = 0 ; index_l != argc ; ++index_l){
    std::cout << "[DEBUG] command line parsing : index " << index_l << " == " << argv[index_l] << '\n';
    vArg_l.push_back(argv[index_l]);
  }

  std::string inputFilePath_l; 
  std::string outputFilePath_l;

  boost::program_options::options_description config_l("Configurations");
	config_l.add_options()
				("input,i", boost::program_options::value<std::string>(&inputFilePath_l)->default_value("input.csv"), "specify the path of the input data file")
				("output,o", boost::program_options::value<std::string>(&outputFilePath_l)->default_value("output.csv"), "specify the path of the output data file");

  boost::program_options::variables_map variableMap_l;
  boost::program_options::options_description cmdLineOptions_l;
	cmdLineOptions_l.add(config_l);

	/* Lecture de la ligne de commande. */
	store(boost::program_options::command_line_parser(vArg_l).options(cmdLineOptions_l).run(),variableMap_l);
	notify(variableMap_l);


  return std::make_pair(inputFilePath_l, outputFilePath_l);
}

int main(int argc, char* argv[]) {

  std::cout << "[INFO] Start Application" << std::endl;

  std::cout << "[INFO] Parse Command Line" << std::endl;
  std::pair<std::string, std::string> pairInputOutputFilePaths_l = processCommandLine(argc, argv);
  std::string inputFilePath_l = pairInputOutputFilePaths_l.first; 
  std::string outputFilePath_l = pairInputOutputFilePaths_l.second;
  
  dummy::Data data_l;
  dummy::CsvInputDTO csvInput_l(inputFilePath_l, ';');

  try{  

    std::cout << "[INFO] Read Input File" << std::endl;
    csvInput_l.fillData(data_l);

    std::cout << "[INFO] Transform Data" << std::endl;
    data_l.reverseData();

    std::cout << "[INFO] Write Output File" << std::endl;
    dummy::CsvOutputDTO csvOutput_l(outputFilePath_l, ';');
    csvOutput_l.dumpData(data_l);

  }
  catch(std::exception& exp_l){
    std::cerr << "[ERROR]: " << exp_l.what() << std::endl;
    std::cout << "[INFO] End Application in Status ERROR" << std::endl;
    return 1;
  }

  std::cout << "[INFO] End Application in Status SUCCESS" << std::endl;
  return 0;
}

