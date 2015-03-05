#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace DynamicArrayTests
{
	TEST_CLASS(DynamicArrayTests)
	{
	public:

		TEST_METHOD(la_capacite_par_defaut_d_un_dynamicArray_est_de_100)
		{
			//Arrange
			const int CAPACITE_DEFAUT = 100;
			DynamicArray<string> tableau;

			//Action
			int capacite = tableau.getCapacite();

			//Assert
			Assert::AreEqual(CAPACITE_DEFAUT, capacite);
		}

		TEST_METHOD(la_valeur_par_defaut_des_elements_d_un_dyanmicArray_est_0)
		{
			//Action
			DynamicArray<string> tableau;

			//Assert
			for (int i = 0; i < tableau.getCapacite(); i++)
			{
				Assert::AreEqual(string(""), tableau.getElement(i));
			}
		}


		TEST_METHOD(setElement_devrait_initialiser_un_element_du_dynamicArray)
		{
			//Arrange
			const string NOUVELLE_VALEUR_ELEMENT = "abc";
			const int INDEX_ELEMENT = 1;
			DynamicArray<string> tableau;

			//Action
			tableau.setElement(INDEX_ELEMENT, NOUVELLE_VALEUR_ELEMENT);

			//Assert
			Assert::AreEqual(NOUVELLE_VALEUR_ELEMENT, tableau.getElement(INDEX_ELEMENT));
		}

		TEST_METHOD(augumenter_la_capacite_d_un_dynamicArray_devrait_preserver_le_contenu_deja_present)
		{
			//Arrange
			const int CAPACITE_DEPART = 3;
			const int NOUVELLE_CAPACITE = 5;

			DynamicArray<float> tableau(CAPACITE_DEPART);

			for (unsigned int i = 0; i < CAPACITE_DEPART; ++i)
			{
				tableau.setElement(i, float(i*i));
			}

			//Action
			tableau.setCapacite(NOUVELLE_CAPACITE);

			//Assert
			for (unsigned int i = 0; i < CAPACITE_DEPART; ++i)
			{
				Assert::AreEqual(float(i*i), tableau.getElement(i));
			}
			for (unsigned int i = CAPACITE_DEPART; i < NOUVELLE_CAPACITE; ++i)
			{
				Assert::AreEqual(0.0f, tableau.getElement(i));
			}
		}

		TEST_METHOD(diminuer_la_capacite_d_un_dynamicArray_devrait_modifier_sa_capacite)
		{
			//Arrange
			const int CAPACITE_DEPART = 5;
			const int NOUVELLE_CAPACITE = 3;

			DynamicArray<float> tableau(CAPACITE_DEPART);

			for (unsigned int i = 0; i < CAPACITE_DEPART; ++i)
			{
				tableau.setElement(i, float(i*i));
			}

			//Action
			tableau.setCapacite(NOUVELLE_CAPACITE);

			//Assert
			Assert::AreEqual(NOUVELLE_CAPACITE, tableau.getCapacite());
			for (unsigned int i = 0; i < NOUVELLE_CAPACITE; ++i)
			{
				Assert::AreEqual(float(i*i), tableau.getElement(i));
			}
		}

		TEST_METHOD(ajouter_un_element_au_dela_de_la_capacite_devrait_auto_agrandir_le_dynamicArray)
		{
			//Arrange
			const int CAPACITE_DEPART = 5;
			const int NOUVELLE_ELEMENT = 99;
			const int INDEX_NOUVEL_ELEMENT = 10;
			DynamicArray<int> tableau(CAPACITE_DEPART);

			for (unsigned int i = 0; i < CAPACITE_DEPART; ++i)
			{
				tableau.setElement(i, i*i);
			}

			//Action
			tableau.setElement(INDEX_NOUVEL_ELEMENT, NOUVELLE_ELEMENT);

			//Assert
			// Est-ce que les anciens éléments sont conservés ?
			for (unsigned int i = 0; i < CAPACITE_DEPART; ++i)
			{
				Assert::AreEqual(int(i*i), tableau.getElement(i));
			}
			// Est-ce que les éléments vides sont initialisés à 0 ?
			for (unsigned int i = CAPACITE_DEPART; i < tableau.getCapacite() - 1; ++i)
			{
				Assert::AreEqual(0, tableau.getElement(i));
			}
			// Est-ce que le nouvel élément a été ajouté
			Assert::AreEqual(NOUVELLE_ELEMENT, tableau.getElement(INDEX_NOUVEL_ELEMENT));
		}


		TEST_METHOD(creer_un_dynamicArray_d_une_capacite_inferieure_a_1_devrait_lancer_une_excpetion)
		{
			//Arrange
			bool exceptionThrown = false;

			//Action
			try
			{
				DynamicArray<string> tableau(0);
			}
			catch (std::invalid_argument ex)
			{
				exceptionThrown = true;
			}

			//Assert
			Assert::IsTrue(exceptionThrown);
		}


		TEST_METHOD(acceder_a_un_element_hors_du_tableau_devrait_lancer_une_excpetion)
		{
			//Arrange
			bool exceptionThrown = false;
			const int CAPACITE = 5;

			DynamicArray<string> tableau(CAPACITE);

			//Action
			try
			{
				string element = tableau.getElement(CAPACITE + 1);
			}
			catch (std::out_of_range ex)
			{
				exceptionThrown = true;
			}

			//Assert
			Assert::IsTrue(exceptionThrown);
		}

		TEST_METHOD(modifier_la_capacite_d_un_dynamicArray_avec_une_valeur_inferieure_a_1_devrait_lancer_une_excpetion)
		{
			//Arrange
			bool exceptionThrown = false;
			DynamicArray<string> tableau;

			//Action
			try
			{
				tableau.setCapacite(0);
			}
			catch (std::invalid_argument ex)
			{
				exceptionThrown = true;
			}

			//Assert
			Assert::IsTrue(exceptionThrown);
		}

	};
}