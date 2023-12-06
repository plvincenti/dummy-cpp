#ifndef INPUTDTO_HH_
#define INPUTDTO_HH_

#include <string>

#include "Data.hh"

namespace dummy
{

class InputDTO
{

public:
    InputDTO(const std::string& inputFilePath_p) : inputFilePath_m(inputFilePath_p){};
    virtual ~InputDTO(){};

    virtual void fillData(Data&) = 0;

protected:

    std::string inputFilePath_m;

};

class CsvInputDTO : public InputDTO
{

public:
    CsvInputDTO(const std::string& inputFilePath_p, const char& sep_p) : 
        InputDTO(inputFilePath_p), csvSeparator_m(sep_p){};
    
    virtual ~CsvInputDTO(){};

    void fillData(Data&);

private:

    char csvSeparator_m;

};

}

#endif 