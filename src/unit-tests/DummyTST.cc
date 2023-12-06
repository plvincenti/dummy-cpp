#include <boost/test/unit_test.hpp>

struct DummyFixture
{
    DummyFixture(){}
    ~DummyFixture(){}

};

BOOST_FIXTURE_TEST_SUITE(DummyTestSuite,DummyFixture)

BOOST_AUTO_TEST_CASE(DummyTestCase)
{
    BOOST_CHECK_EQUAL(1,1);
}

BOOST_AUTO_TEST_SUITE_END()