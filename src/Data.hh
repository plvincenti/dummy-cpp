#ifndef DATA_HH_
#define DATA_HH_

#include <string>
#include <vector>

namespace dummy
{

class Data
{

public:
    Data();
    virtual ~Data();

    const std::vector<std::vector<std::string>>& getData();
    void addLineToData(std::vector<std::string> line_p);

    void reverseData();

private:

    std::vector<std::vector<std::string>> data_m;

};

}

#endif