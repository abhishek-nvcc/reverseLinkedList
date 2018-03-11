#define CATCH_INC

#define UTILS_INC

#include "dependency.h"
#include "..\include\testCommonDefinitions.h"

#ifdef RUN_UTILS_TESTS
SCENARIO("Check addition of new in correct order", "[utils]")
{
	GIVEN("Create a list of integers")
	{
		std::vector<int> listOfVals;
		GIVEN("test addition of value at the head of the list")
		{
			int valToAdd = 90;
			WHEN("the idx corresponding to the new value to be added is computed")
			{
				int idx = findIdxToAddItemToMaintainDescendingOrder(listOfVals, valToAdd);
				THEN("the index to add the new value should be equal to a predefined value")
				{
					REQUIRE(0 == idx);
					listOfVals.push_back(valToAdd);
					REQUIRE(listOfVals.at(idx) == 90);
				}
			}
		}
	}

	GIVEN("Create a list of integers")
	{
		std::vector<int> listOfVals = {90};
		GIVEN("test addition of value at the head of the list")
		{
			int valToAdd = 90;
			WHEN("the idx corresponding to the new value to be added is computed")
			{
				int idx = findIdxToAddItemToMaintainDescendingOrder(listOfVals, valToAdd);
				THEN("the index to add the new value should be equal to a predefined value")
				{
					REQUIRE(0 == idx);
					listOfVals.insert(listOfVals.begin() + idx, valToAdd);
					REQUIRE(listOfVals.at(idx) == 90);
				}
			}
		}
	}

	GIVEN("Create a list of integers")
	{
		std::vector<int> listOfVals = { 90 };
		GIVEN("test addition of value at the head of the list")
		{
			int valToAdd = 100;
			WHEN("the idx corresponding to the new value to be added is computed")
			{
				int idx = findIdxToAddItemToMaintainDescendingOrder(listOfVals, valToAdd);
				THEN("the index to add the new value should be equal to a predefined value")
				{
					REQUIRE(0 == idx);
					listOfVals.insert(listOfVals.begin() + idx, valToAdd);
					REQUIRE(listOfVals.at(idx) == 100);
				}
			}
		}
	}

	GIVEN("Create a list of integers")
	{
		std::vector<int> listOfVals = { 90 };
		GIVEN("test addition of value at the head of the list")
		{
			int valToAdd = 80;
			WHEN("the idx corresponding to the new value to be added is computed")
			{
				int idx = findIdxToAddItemToMaintainDescendingOrder(listOfVals, valToAdd);
				THEN("the index to add the new value should be equal to a predefined value")
				{
					REQUIRE(1 == idx);
					listOfVals.insert(listOfVals.begin() + idx, valToAdd);
					REQUIRE(listOfVals.at(idx) == 80);
				}
			}
		}
	}

	GIVEN("Create a list of integers")
	{
		std::vector<int> listOfVals = { 90, 85, 50, 34, 18, 10, 2 };
		GIVEN("test addition of value at the head of the list")
		{
			int valToAdd = 90;
			WHEN("the idx corresponding to the new value to be added is computed")
			{
				int idx = findIdxToAddItemToMaintainDescendingOrder(listOfVals, valToAdd);
				THEN("the index to add the new value should be equal to a predefined value")
				{
					REQUIRE(0 == idx);
					listOfVals.insert(listOfVals.begin() + idx, valToAdd);
					REQUIRE(listOfVals.at(idx) == 90);
				}
			}
		}
	}

	GIVEN("Create a list of integers")
	{
		std::vector<int> listOfVals = { 90, 85, 50, 34, 18, 10, 2 };
		GIVEN("test addition of value in between the list")
		{
			int valToAdd = 85;
			WHEN("the idx corresponding to the new value to be added is computed")
			{
				int idx = findIdxToAddItemToMaintainDescendingOrder(listOfVals, valToAdd);
				THEN("the index to add the new value should be equal to a predefined value")
				{
					REQUIRE(1 == idx);
					listOfVals.insert(listOfVals.begin() + idx, valToAdd);
					REQUIRE(listOfVals.at(idx) == 85);
				}
			}
		}
	}

	GIVEN("Create a list of integers")
	{
		std::vector<int> listOfVals = { 90, 85, 50, 34, 18, 10, 2 };
		GIVEN("test addition of value in between the list")
		{
			int valToAdd = 88;
			WHEN("the idx corresponding to the new value to be added is computed")
			{
				int idx = findIdxToAddItemToMaintainDescendingOrder(listOfVals, valToAdd);
				THEN("the index to add the new value should be equal to a predefined value")
				{
					REQUIRE(1 == idx);
					listOfVals.insert(listOfVals.begin() + idx, valToAdd);
					REQUIRE(listOfVals.at(idx) == 88);
				}
			}
		}
	}

	GIVEN("Create a list of integers")
	{
		std::vector<int> listOfVals = { 90, 85, 50, 34, 18, 10, 2 };
		GIVEN("test addition of value in between the list")
		{
			int valToAdd = 2;
			WHEN("the idx corresponding to the new value to be added is computed")
			{
				int idx = findIdxToAddItemToMaintainDescendingOrder(listOfVals, valToAdd);
				THEN("the index to add the new value should be equal to a predefined value")
				{
					REQUIRE(6 == idx);
					listOfVals.insert(listOfVals.begin() + idx, valToAdd);
					REQUIRE(listOfVals.at(idx) == 2);
				}
			}
		}
	}

	GIVEN("Create a list of integers")
	{
		std::vector<int> listOfVals = { 90, 85, 50, 34, 18, 10, 2 };
		GIVEN("test addition of value in between the list")
		{
			int valToAdd = 3;
			WHEN("the idx corresponding to the new value to be added is computed")
			{
				int idx = findIdxToAddItemToMaintainDescendingOrder(listOfVals, valToAdd);
				THEN("the index to add the new value should be equal to a predefined value")
				{
					REQUIRE(6 == idx);
					listOfVals.insert(listOfVals.begin() + idx, valToAdd);
					REQUIRE(listOfVals.at(idx) == 3);
				}
			}
		}
	}

	GIVEN("Create a list of integers")
	{
		std::vector<int> listOfVals = { 90, 85, 50, 34, 18, 10, 2 };
		GIVEN("test addition of value in between the list")
		{
			int valToAdd = 1;
			WHEN("the idx corresponding to the new value to be added is computed")
			{
				int idx = findIdxToAddItemToMaintainDescendingOrder(listOfVals, valToAdd);
				THEN("the index to add the new value should be equal to a predefined value")
				{
					REQUIRE(7 == idx);
					listOfVals.push_back(valToAdd);;
					REQUIRE(listOfVals.at(idx) == 1);
				}
			}
		}
	}

	GIVEN("Create a list of integers")
	{
		std::vector<int> listOfVals = { 90, 85, 50, 34, 18, 10, 2 };
		GIVEN("test addition of value in between the list")
		{
			int valToAdd = 15;
			WHEN("the idx corresponding to the new value to be added is computed")
			{
				int idx = findIdxToAddItemToMaintainDescendingOrder(listOfVals, valToAdd);
				THEN("the index to add the new value should be equal to a predefined value")
				{
					REQUIRE(5 == idx);
					listOfVals.insert(listOfVals.begin() + idx, valToAdd);
					REQUIRE(listOfVals.at(idx) == 15);
				}
			}
		}
	}

	GIVEN("Create a list of integers")
	{
		std::vector<int> listOfVals = { 90, 85, 50, 34, 18, 10, 2 };
		GIVEN("test addition of value in between the list")
		{
			int valToAdd = 150;
			WHEN("the idx corresponding to the new value to be added is computed")
			{
				int idx = findIdxToAddItemToMaintainDescendingOrder(listOfVals, valToAdd);
				THEN("the index to add the new value should be equal to a predefined value")
				{
					REQUIRE(0 == idx);
					listOfVals.insert(listOfVals.begin() + idx, valToAdd);
					REQUIRE(listOfVals.at(idx) == 150);
				}
			}
		}
	}
}
#endif
