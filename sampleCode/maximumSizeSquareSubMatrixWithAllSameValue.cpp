#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <assert.h>

using namespace std;

typedef std::vector<int> listOfInt;
typedef std::vector<listOfInt> arrayOfInt;

bool hasDataCorrectValues(const arrayOfInt& originalData)
{
    bool bRetVal = true;
    for (const listOfInt rowVec : originalData)
    {
        for (const int dataValue : rowVec)
        {
            if(0 != dataValue && 1 != dataValue)
            {
                bRetVal = false;
                break;
            }
        }
        if(false == bRetVal)
        {
            break;
        }
    }
    return bRetVal;
}

bool isDataSquare(const arrayOfInt& originalData)
{
    bool bRetVal = true;
    size_t numOfRows = originalData.size();
    for (const listOfInt rowVec : originalData)
    {
        if(numOfRows != rowVec.size())
        {
            bRetVal = false;
            break;
        }
    }
    return bRetVal;
}

bool checkSquare(const arrayOfInt& originalData, const int testVal, const int rowNum, const int colNum, const int intermediateSizeOfSquare)
{
    bool bRetVal = true;
    size_t sizeOfSquare = originalData.size();
    for(int rowCount = 0; rowCount < intermediateSizeOfSquare; ++rowCount)
    {
        if(sizeOfSquare > (rowNum + rowCount))
        {
            listOfInt list = originalData[rowNum + rowCount];
            for(int colCount = 0; colCount < intermediateSizeOfSquare; ++colCount)
            {
                if(sizeOfSquare > (colNum + colCount))
                {
                    int testData = list[colNum + colCount];
                    if(testVal != testData)
                    {
                        bRetVal = false;
                        break;
                    }
                }
            }
            if(false == bRetVal)
            {
                break;
            }
        }
    }
    return bRetVal;
}

void checkBiggestSquare(const arrayOfInt& originalData, const int testVal, int& biggestSquareStartingRowNum, int& biggestSquareStartingColNum, int& biggestSquareSize)
{
    if(false == isDataSquare(originalData) || false == hasDataCorrectValues(originalData))
        return;
    
    biggestSquareSize = 0;
    size_t sizeOfSquare = originalData.size();
    for (int rowNum = 0; rowNum < sizeOfSquare; ++rowNum)
    {
        if(sizeOfSquare > rowNum)
        {
            listOfInt list = originalData[rowNum];
            for (int colNum = 0; colNum < sizeOfSquare; ++colNum)
            {
                if(biggestSquareSize < (sizeOfSquare - rowNum) && biggestSquareSize < (sizeOfSquare - colNum) && sizeOfSquare > colNum)
                {
                    if(testVal != list[colNum])
                    {
                        continue;
                    }
                    int intermediateSizeOfSquare = 2;
                    bool bFoundValue = false;
                    while((true == checkSquare(originalData, testVal, rowNum, colNum, intermediateSizeOfSquare)) && (sizeOfSquare >= (colNum + intermediateSizeOfSquare)) && (sizeOfSquare >= (rowNum + intermediateSizeOfSquare)))
                    {
                        bFoundValue = true;
                        ++intermediateSizeOfSquare;
                    }
                    if(true == bFoundValue)
                    {
                        --intermediateSizeOfSquare;
                        if(intermediateSizeOfSquare > biggestSquareSize)
                        {
                            biggestSquareStartingRowNum = rowNum;
                            biggestSquareStartingColNum = colNum;
                            biggestSquareSize = intermediateSizeOfSquare;
                        }
                    }
                }
            }
        }
    }
}

void findAndDumpOutput(const arrayOfInt& matrix, const int testVal)
{
    int biggestSquareStartingRowNum = 0, biggestSquareStartingColNum = 0, biggestSquareSize = 0;
    checkBiggestSquare(matrix, testVal, biggestSquareStartingRowNum, biggestSquareStartingColNum, biggestSquareSize);
    
    std::cout << "biggestSquareStartingRowNum: " << biggestSquareStartingRowNum << std::endl;
    std::cout << "biggestSquareStartingColNum: " << biggestSquareStartingColNum << std::endl;
    std::cout << "biggestSquareSize: " << biggestSquareSize << std::endl;
}

void testCase1()
{
    std::cout << "**********************TEST CASE 1**********************" << std::endl;
    listOfInt row1 = {0,1,0,1,1,1,0,0,0,1};
    listOfInt row2 = {1,1,0,0,0,0,0,0,0,1};
    listOfInt row3 = {0,1,0,1,1,1,0,0,1,1};
    listOfInt row4 = {0,1,1,1,0,1,1,1,0,1};
    listOfInt row5 = {1,1,1,1,1,1,0,0,0,1};
    listOfInt row6 = {1,1,0,1,1,1,0,1,0,1};
    listOfInt row7 = {0,1,0,1,1,1,1,1,1,1};
    listOfInt row8 = {1,1,1,1,1,1,1,1,0,1};
    listOfInt row9 = {0,1,0,1,1,1,1,1,1,1};
    listOfInt row10 = {1,1,1,1,1,1,1,1,1,1};
    arrayOfInt matrix = {row1, row2, row3, row4, row5, row6, row7, row8, row9, row10};
    
    int testVal = 1;
    
    findAndDumpOutput(matrix, testVal);
}

void testCase2()
{
    std::cout << "**********************TEST CASE 2**********************" << std::endl;
    listOfInt row1 = {0,1,0,1,1};
    listOfInt row2 = {1,1,1,1,1};
    listOfInt row3 = {1,1,0,1,1};
    listOfInt row4 = {0,1,1,1,1};
    listOfInt row5 = {0,0,1,0,0};
    arrayOfInt matrix = {row1, row2, row3, row4, row5};
    
    int testVal = 1;
    
    findAndDumpOutput(matrix, testVal);
}

int main()
{
    testCase1();
    testCase2();
    
    return 1;
}
