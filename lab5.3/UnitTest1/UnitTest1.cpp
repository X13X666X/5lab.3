#include "pch.h"
#include "CppUnitTest.h"
#include "../5.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestPFunctionLargeX)
        {
            double x = 2.0;
            double expected = (sin(x) + cos(x)) / (1 + exp(-x));
            double actual = p(x);
            Assert::AreEqual(expected, actual, 0.001);
        }

        TEST_METHOD(TestPFunctionSmallX)
        {
            double x = 0.5;
            double expected = 1 - x * x / 2 + pow(x, 4) / 24 - pow(x, 6) / 720;
            double actual = p(x);
            Assert::AreEqual(expected, actual, 0.001);
        }

        TEST_METHOD(TestMainCalculation)
        {
            double q = 1.0;
            double expectedZ = p(2 * q + 1) + pow(p(q * q - 1), 2) + sqrt(p(q));
            double actualZ = p(2 * q + 1) + pow(p(q * q - 1), 2) + sqrt(p(q));
            Assert::AreEqual(expectedZ, actualZ, 0.001);
        }
    };
}
