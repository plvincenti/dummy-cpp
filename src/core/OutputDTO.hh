#ifndef OUTPUTDTO_HH_
#define OUTPUTDTO_HH_

#include <string>

#include "Data.hh"

namespace dummy
{

class OutputDTO
{

public:
    OutputDTO(const std::string& outputFilePath_p) : outputFilePath_m(outputFilePath_p){};
    virtual ~OutputDTO(){};

    virtual const void dumpData(const Data&) = 0;

protected:

    std::string outputFilePath_m;

};

class CsvOutputDTO : public OutputDTO
{

public:
    CsvOutputDTO(const std::string& OutputFilePath_p, const char& sep_p) : 
        OutputDTO(OutputFilePath_p), csvSeparator_m(sep_p){};
    
    virtual ~CsvOutputDTO(){};

    const void dumpData(const Data&);

private:

    char csvSeparator_m;

};

}

#endif 