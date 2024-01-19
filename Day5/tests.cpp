/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_MyTestSuite_init = false;
#include "TestSuite.hpp"

static MyTestSuite suite_MyTestSuite;

static CxxTest::List Tests_MyTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite( "TestSuite.hpp", 7, "MyTestSuite", suite_MyTestSuite, Tests_MyTestSuite );

static class TestDescription_suite_MyTestSuite_TestReadInput : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_TestReadInput() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 11, "TestReadInput" ) {}
 void runTest() { suite_MyTestSuite.TestReadInput(); }
} testDescription_suite_MyTestSuite_TestReadInput;

static class TestDescription_suite_MyTestSuite_TestMap : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_TestMap() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 61, "TestMap" ) {}
 void runTest() { suite_MyTestSuite.TestMap(); }
} testDescription_suite_MyTestSuite_TestMap;

static class TestDescription_suite_MyTestSuite_TestGetLocation : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_TestGetLocation() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 79, "TestGetLocation" ) {}
 void runTest() { suite_MyTestSuite.TestGetLocation(); }
} testDescription_suite_MyTestSuite_TestGetLocation;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
