#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace fonctionsModelesTests
{		
	TEST_CLASS(fonctionsModelesCompterElement)
	{
	public:
		
    	//Question 3

		TEST_METHOD(CompterElement_DansUnTableauDeFloat_DevraitRetournerLeNombreDelementsDansLeTableau)
		{
			float tabFloat[5] = { 22.2f, 11.1f, -33.1f, 11.1f, 11.1f };

			Assert::AreEqual(unsigned int(3), CompterElement(11.1f, tabFloat, 5));
		}

		TEST_METHOD(CompterElement_DansUnTableauDeInt_DevraitRetournerLeNombreDelementsDansLeTableau)
		{
			int tabInt[5] = { 21, 2, 21, 21, -1 };

			Assert::AreEqual(unsigned int(3), CompterElement(21, tabInt, 5));
		}

		TEST_METHOD(CompterElement_DansUnTableauDeString_DevraitRetournerLeNombreDelementsDansLeTableau)
		{
			string tabString[5] = { "Huit", "Cinq", "Deux", "Trois", "Deux" };

			Assert::AreEqual(unsigned int(2), CompterElement(string("Deux"), tabString, 5));
		}

	};
}