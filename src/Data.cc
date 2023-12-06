#include "Data.hh"

#include <algorithm>

namespace dummy
{

Data::Data() : 
    data_m()
{

}

Data::~Data()
{

}

const std::vector<std::vector<std::string>>& Data::getData() const
{
    return data_m;
}

void Data::addLineToData(std::vector<std::string> line_p)
{
    return data_m.push_back(line_p);
}

void Data::reverseData()
{
  // Reverse columns of data
  for (int i = 0; i < data_m.size(); i++) {
    std::reverse(data_m[i].begin(), data_m[i].end());
  }
}

}