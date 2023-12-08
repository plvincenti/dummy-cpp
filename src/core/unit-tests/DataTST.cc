#include <boost/test/unit_test.hpp>

#include "Data.hh"

struct DataFixture
{
    DataFixture() : 
        data_m()
    {
        data_m.addLineToData(header_m);
        data_m.addLineToData(line1_m);
        data_m.addLineToData(line2_m);
    }
    ~DataFixture(){}

    dummy::Data data_m;

    std::vector<std::string> header_m = {"col1","col2"};
    std::vector<std::string> line1_m = {"toto","tata"};
    std::vector<std::string> line2_m = {"titi","tutu"};

};

BOOST_FIXTURE_TEST_SUITE(DataTestSuite,DataFixture)


BOOST_AUTO_TEST_CASE(GetDataFromIndex_TestCase)
{
    BOOST_CHECK_THROW(data_m.getDataFromIndex(56,0), std::runtime_error);
    BOOST_CHECK_THROW(data_m.getDataFromIndex(0,3), std::runtime_error);

    BOOST_CHECK_EQUAL(data_m.getDataFromIndex(0,0), "col1");
    BOOST_CHECK_EQUAL(data_m.getDataFromIndex(0,1), "col2");

    BOOST_CHECK_EQUAL(data_m.getDataFromIndex(1,0), "toto");
    BOOST_CHECK_EQUAL(data_m.getDataFromIndex(1,1), "tata");

    BOOST_CHECK_EQUAL(data_m.getDataFromIndex(2,0), "titi");
    BOOST_CHECK_EQUAL(data_m.getDataFromIndex(2,1), "tutu");
}

BOOST_AUTO_TEST_CASE(ReverseData_TestCase)
{
    data_m.reverseData();    

    BOOST_CHECK_EQUAL(data_m.getDataFromIndex(0,0), "col2");
    BOOST_CHECK_EQUAL(data_m.getDataFromIndex(0,1), "col1");

    BOOST_CHECK_EQUAL(data_m.getDataFromIndex(1,0), "tata");
    BOOST_CHECK_EQUAL(data_m.getDataFromIndex(1,1), "toto");

    BOOST_CHECK_EQUAL(data_m.getDataFromIndex(2,0), "tutu");
    BOOST_CHECK_EQUAL(data_m.getDataFromIndex(2,1), "titi");
}

BOOST_AUTO_TEST_SUITE_END()