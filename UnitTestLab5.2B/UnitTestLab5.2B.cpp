#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab5.2.B//Lab5.2.B.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab52B
{
	TEST_CLASS(UnitTestLab52B)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char f[6] = "f.dat";
			int t = goodMathPhys(f);
			Assert::AreEqual(t, 0);
		}
	};
}
