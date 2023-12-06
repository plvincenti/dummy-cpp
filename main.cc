#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

#include <boost/program_options.hpp>

using namespace std;

std::pair<std::string, std::string> processCommandLine(int argc, char* argv[]){
  
  std::vector<std::string> vArg_l;
  for (int index_l = 0 ; index_l != argc ; ++index_l){
    std::cout << "[DEBUG] command line parsing : index " << index_l << " == " << argv[index_l] << '\n';
    vArg_l.push_back(argv[index_l]);
  }

  string inputFilePath_l; 
  string outputFilePath_l;

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

std::vector<std::vector<std::string>> readInputFile(const std::string& inputFile_p){

  
  // Ouverture du fichier d'entrée
  ifstream infile(inputFile_p);

  // Vérification de l'ouverture du fichier
  if (!infile.is_open()) {
    throw std::runtime_error("Impossible to read the input file");
  }

  cout << "[INFO] Start Reading " << inputFile_p << endl;
  // Lecture du fichier d'entrée ligne par ligne
  string line;
  vector<vector<string>> data_l;
  while (getline(infile, line)) {
    // Extraction des valeurs de la ligne
    stringstream ss(line);
    vector<string> values;
    string value;
    while (getline(ss, value, ';')) {
      values.push_back(value);
    }
    // Ajout des valeurs à la matrice de données
    data_l.push_back(values);
  }

  // Fermeture du fichier d'entrée
  infile.close();
  cout << "[INFO] End Reading " << inputFile_p << endl;

  return data_l;
}

void transformData(std::vector<std::vector<std::string>>& data_p){
  
  // Reverse columns of data
  for (int i = 0; i < data_p.size(); i++) {
    reverse(data_p[i].begin(), data_p[i].end());
  }
}

const void writeOutput(const std::string& outputFile_p, const std::vector<std::vector<std::string>>& data_p){

   // Ouverture du fichier de sortie
  ofstream outfile(outputFile_p);

  // Vérification de l'ouverture du fichier
  if (!outfile.is_open()) {
    throw std::runtime_error("Impossible to write the outut file");
  }

  cout << "[INFO] Start Writting " << outputFile_p << endl;
  // Écriture des données dans le fichier de sortie
  for (int i = 0; i < data_p.size(); i++) {
    for (int j = 0; j < data_p[i].size(); j++) {
      outfile << data_p[i][j];
      if (j < data_p[i].size() - 1) {
        outfile << ";";
      }
    }
    outfile << endl;
  }

  // Fermeture du fichier de sortie
  outfile.close();
  cout << "[INFO] End Writting " << outputFile_p << endl;

}

int main(int argc, char* argv[]) {

  cout << "[INFO] Start Application" << endl;

  cout << "[INFO] Parse Command Line" << endl;
  std::pair<std::string, std::string> pairInputOutputFilePaths_l = processCommandLine(argc, argv);
  string inputFilePath_l = pairInputOutputFilePaths_l.first; 
  string outputFilePath_l = pairInputOutputFilePaths_l.second;
  
  try{  

    cout << "[INFO] Read Input File" << endl;
    std::vector<std::vector<std::string>> data_l = readInputFile(inputFilePath_l);

    cout << "[INFO] Transform Data" << endl;
    transformData(data_l);

    cout << "[INFO] Write Output File" << endl;
    writeOutput(outputFilePath_l, data_l);

  }
  catch(std::exception& exp_l){
    std::cerr << "[ERROR]: " << exp_l.what() << std::endl;
    cout << "[INFO] End Application in Status ERROR" << endl;
    return 1;
  }

  cout << "[INFO] End Application in Status SUCCESS" << endl;
  return 0;
}

