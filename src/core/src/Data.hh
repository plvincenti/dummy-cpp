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

    const std::vector<std::vector<std::string>>& getData() const;
    void addLineToData(std::vector<std::string> line_p);

    void reverseData();

    const std::string& getDataFromIndex(const int& idxCol_p, const int& idxLine_p) const;

private:

    std::vector<std::vector<std::string>> data_m;

};

}

#endif