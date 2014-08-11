/* sort.cpp */

#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

typedef int aType;		//  array type

const int MAX_ARRAY = 10500;
int counter = 0;

void Mergesort (aType a[], int first, int last);
void Merge (aType a[], int firstLeft, int lastLeft, int firstRight,
	    int lastRight);
void Swap (aType & v1, aType & v2);
void PrintArray (aType A[], int nElements);
void SelectionSort (aType A[], int nElements);
void Quicksort (aType a[], int first, int last);
int Pivot (aType a[], int first, int last);
int IndexOfSmallest (aType A[], int iStart, int iEnd);

int
main ()
{
  int choice, choice2;
  cout << "Which sorting method would you like to test? (1)Mergesort,";
  cout << "(2)Selection, or (3)Quicksort: ";
  cin >> choice;

  switch (choice)
    {
    case 1:			//Merge Sort
      cout <<
	"Which data set size would you like to test? (1)100, (2)1000, (3)10000: ";
      cin >> choice2;
      switch (choice2)
	{

	case 1:
	  {
	    //Random data set sort
	    cout << endl;
	    cout << "-----MERGE SORT-----" << endl;
	    aType testArray[100];
	    ifstream inFile ("Rand100.txt");
	    for (int i = 0; i < 100; i++)
	      {
		inFile >> testArray[i];
	      }
	    cout << "Random Data Set: " << endl;
	    int nA = sizeof (testArray) / sizeof (aType);
	    cout << "nA: " << nA << endl;
	    cout << "Initial array contents:" << endl;
	    PrintArray (testArray, nA);
	    Mergesort (testArray, 0, nA - 1);
	    cout << "\nFinal array contents:" << endl;
	    PrintArray (testArray, nA);
	    cout << endl;

	    //Low to High data set sort
	    aType testArray1[100];
	    ifstream inFile1 ("LowToHigh100.txt");
	    for (int i = 0; i < 100; i++)
	      {
		inFile1 >> testArray1[i];
	      }
	    cout << "Low To High Data Set: " << endl;
	    int nB = sizeof (testArray1) / sizeof (aType);
	    cout << "nA: " << nB << endl;
	    cout << "Initial array contents:" << endl;
	    PrintArray (testArray1, nB);
	    Mergesort (testArray1, 0, nB - 1);
	    cout << "\nFinal array contents:" << endl;
	    PrintArray (testArray1, nB);
	    cout << endl;

	    //High to Low data set sort
	    aType testArray2[100];
	    ifstream inFile2 ("HighToLow100.txt");
	    for (int i = 0; i < 100; i++)
	      {
		inFile2 >> testArray2[i];
	      }
	    cout << "High to Low Data Set: " << endl;
	    int nC = sizeof (testArray2) / sizeof (aType);
	    cout << "nA: " << nC << endl;
	    cout << "Initial array contents:" << endl;
	    PrintArray (testArray2, nC);
	    Mergesort (testArray2, 0, nC - 1);
	    cout << "\nFinal array contents:" << endl;
	    PrintArray (testArray2, nC);
	    cout << endl;
	    break;
	  }

	case 2:
	  {
	    //Random data set sort
	    cout << endl;
	    cout << "-----MERGE SORT-----" << endl;
	    aType testArray[1000];
	    ifstream inFile ("Rand1000.txt");
	    for (int i = 0; i < 1000; i++)
	      {
		inFile >> testArray[i];
	      }
	    cout << "Random Data Set: " << endl;
	    int nA = sizeof (testArray) / sizeof (aType);
	    cout << "nA: " << nA << endl;
	    cout << "Initial array contents:" << endl;
	    PrintArray (testArray, nA);
	    Mergesort (testArray, 0, nA - 1);
	    cout << "\nFinal array contents:" << endl;
	    PrintArray (testArray, nA);
	    cout << endl;

	    //Low to High data set sort
	    aType testArray1[1000];
	    ifstream inFile1 ("LowToHigh1000.txt");
	    for (int i = 0; i < 1000; i++)
	      {
		inFile1 >> testArray1[i];
	      }
	    cout << "Low To High Data Set: " << endl;
	    int nB = sizeof (testArray1) / sizeof (aType);
	    cout << "nA: " << nB << endl;
	    cout << "Initial array contents:" << endl;
	    PrintArray (testArray1, nB);
	    Mergesort (testArray1, 0, nB - 1);
	    cout << "\nFinal array contents:" << endl;
	    PrintArray (testArray1, nB);
	    cout << endl;

	    //High to Low data set sort
	    aType testArray2[1000];
	    ifstream inFile2 ("HighToLow1000.txt");
	    for (int i = 0; i < 1000; i++)
	      {
		inFile2 >> testArray2[i];
	      }
	    cout << "High to Low Data Set: " << endl;
	    int nC = sizeof (testArray2) / sizeof (aType);
	    cout << "nA: " << nC << endl;
	    cout << "Initial array contents:" << endl;
	    PrintArray (testArray2, nC);
	    Mergesort (testArray2, 0, nC - 1);
	    cout << "\nFinal array contents:" << endl;
	    PrintArray (testArray2, nC);
	    cout << endl;
	    break;
	  }

	case 3:
	  {
	    //Random data set sort
	    cout << endl;
	    cout << "-----MERGE SORT-----" << endl;
	    aType testArray[10000];
	    ifstream inFile ("Rand10000.txt");
	    for (int i = 0; i < 10000; i++)
	      {
		inFile >> testArray[i];
	      }
	    cout << "Random Data Set: " << endl;
	    int nA = sizeof (testArray) / sizeof (aType);
	    cout << "nA: " << nA << endl;
	    cout << "Initial array contents:" << endl;
	    PrintArray (testArray, nA);
	    Mergesort (testArray, 0, nA - 1);
	    cout << "\nFinal array contents:" << endl;
	    PrintArray (testArray, nA);
	    cout << endl;

	    //Low to High data set sort
	    aType testArray1[10000];
	    ifstream inFile1 ("LowToHigh10000.txt");
	    for (int i = 0; i < 10000; i++)
	      {
		inFile1 >> testArray1[i];
	      }
	    cout << "Low To High Data Set: " << endl;
	    int nB = sizeof (testArray1) / sizeof (aType);
	    cout << "nA: " << nB << endl;
	    cout << "Initial array contents:" << endl;
	    PrintArray (testArray1, nB);
	    Mergesort (testArray1, 0, nB - 1);
	    cout << "\nFinal array contents:" << endl;
	    PrintArray (testArray1, nB);
	    cout << endl;

	    //High to Low data set sort
	    aType testArray2[10000];
	    ifstream inFile2 ("HighToLow10000.txt");
	    for (int i = 0; i < 10000; i++)
	      {
		inFile2 >> testArray2[i];
	      }
	    cout << "High to Low Data Set: " << endl;
	    int nC = sizeof (testArray2) / sizeof (aType);
	    cout << "nA: " << nC << endl;
	    cout << "Initial array contents:" << endl;
	    PrintArray (testArray2, nC);
	    Mergesort (testArray2, 0, nC - 1);
	    cout << "\nFinal array contents:" << endl;
	    PrintArray (testArray2, nC);
	    cout << endl;
	    break;
	  }
	}
      break;


    case 2:			//Selection Sort
      cout <<
	"Which data set size would you like to test? (1)100, (2)1000, (3)10000: ";
      cin >> choice2;
      switch (choice2)
	{

	case 1:
	  {
	    //Random data set sort
	    cout << endl;
	    cout << "-----SELECTION SORT-----" << endl;
	    aType testArray[100];
	    ifstream inFile ("Rand100.txt");
	    for (int i = 0; i < 100; i++)
	      {
		inFile >> testArray[i];
	      }
	    cout << "Random Data Set: " << endl;
	    int nA = sizeof (testArray) / sizeof (aType);
	    cout << "nA: " << nA << endl;
	    cout << "Initial array contents:" << endl;
	    PrintArray (testArray, nA);
	    SelectionSort (testArray, nA);
	    cout << "\nFinal array contents:" << endl;
	    PrintArray (testArray, nA);
	    cout << endl;

	    //Low to High data set sort
	    aType testArray1[100];
	    ifstream inFile1 ("LowToHigh100.txt");
	    for (int i = 0; i < 100; i++)
	      {
		inFile1 >> testArray1[i];
	      }
	    cout << "Low To High Data Set: " << endl;
	    int nB = sizeof (testArray1) / sizeof (aType);
	    cout << "nA: " << nB << endl;
	    cout << "Initial array contents:" << endl;
	    PrintArray (testArray1, nB);
	    SelectionSort (testArray1, nB);
	    cout << "\nFinal array contents:" << endl;
	    PrintArray (testArray1, nB);
	    cout << endl;

	    //High to Low data set sort
	    aType testArray2[100];
	    ifstream inFile2 ("HighToLow100.txt");
	    for (int i = 0; i < 100; i++)
	      {
		inFile2 >> testArray2[i];
	      }
	    cout << "High to Low Data Set: " << endl;
	    int nC = sizeof (testArray2) / sizeof (aType);
	    cout << "nA: " << nC << endl;
	    cout << "Initial array contents:" << endl;
	    PrintArray (testArray2, nC);
	    SelectionSort (testArray2, nC);
	    cout << "\nFinal array contents:" << endl;
	    PrintArray (testArray2, nC);
	    cout << endl;
	    break;
	  }

	case 2:
	  {
	    //Random data set sort
	    cout << endl;
	    cout << "-----SELECTION SORT-----" << endl;
	    aType testArray[1000];
	    ifstream inFile ("Rand1000.txt");
	    for (int i = 0; i < 1000; i++)
	      {
		inFile >> testArray[i];
	      }
	    cout << "Random Data Set: " << endl;
	    int nA = sizeof (testArray) / sizeof (aType);
	    cout << "nA: " << nA << endl;
	    cout << "Initial array contents:" << endl;
	    PrintArray (testArray, nA);
	    SelectionSort (testArray, nA);
	    cout << "\nFinal array contents:" << endl;
	    PrintArray (testArray, nA);
	    cout << endl;

	    //Low to High data set sort
	    aType testArray1[1000];
	    ifstream inFile1 ("LowToHigh1000.txt");
	    for (int i = 0; i < 1000; i++)
	      {
		inFile1 >> testArray1[i];
	      }
	    cout << "Low To High Data Set: " << endl;
	    int nB = sizeof (testArray1) / sizeof (aType);
	    cout << "nA: " << nB << endl;
	    cout << "Initial array contents:" << endl;
	    PrintArray (testArray1, nB);
	    SelectionSort (testArray1, nB);
	    cout << "\nFinal array contents:" << endl;
	    PrintArray (testArray1, nB);
	    cout << endl;

	    //High to Low data set sort
	    aType testArray2[1000];
	    ifstream inFile2 ("HighToLow1000.txt");
	    for (int i = 0; i < 1000; i++)
	      {
		inFile2 >> testArray2[i];
	      }
	    cout << "High to Low Data Set: " << endl;
	    int nC = sizeof (testArray2) / sizeof (aType);
	    cout << "nA: " << nC << endl;
	    cout << "Initial array contents:" << endl;
	    PrintArray (testArray2, nC);
	    SelectionSort (testArray2, nC);
	    cout << "\nFinal array contents:" << endl;
	    PrintArray (testArray2, nC);
	    cout << endl;
	    break;
	  }

	case 3:
	  {
	    //Random data set sort
	    cout << endl;
	    cout << "-----SELECTION SORT-----" << endl;
	    aType testArray[10000];
	    ifstream inFile ("Rand10000.txt");
	    for (int i = 0; i < 10000; i++)
	      {
		inFile >> testArray[i];
	      }
	    cout << "Random Data Set: " << endl;
	    int nA = sizeof (testArray) / sizeof (aType);
	    cout << "nA: " << nA << endl;
	    cout << "Initial array contents:" << endl;
	    PrintArray (testArray, nA);
	    SelectionSort (testArray, nA);
	    cout << "\nFinal array contents:" << endl;
	    PrintArray (testArray, nA);
	    cout << endl;

	    //Low to High data set sort
	    aType testArray1[10000];
	    ifstream inFile1 ("LowToHigh10000.txt");
	    for (int i = 0; i < 10000; i++)
	      {
		inFile1 >> testArray1[i];
	      }
	    cout << "Low To High Data Set: " << endl;
	    int nB = sizeof (testArray1) / sizeof (aType);
	    cout << "nA: " << nB << endl;
	    cout << "Initial array contents:" << endl;
	    PrintArray (testArray1, nB);
	    SelectionSort (testArray1, nB);
	    cout << "\nFinal array contents:" << endl;
	    PrintArray (testArray1, nB);
	    cout << endl;

	    //High to Low data set sort
	    aType testArray2[10000];
	    ifstream inFile2 ("HighToLow10000.txt");
	    for (int i = 0; i < 10000; i++)
	      {
		inFile2 >> testArray2[i];
	      }
	    cout << "High to Low Data Set: " << endl;
	    int nC = sizeof (testArray2) / sizeof (aType);
	    cout << "nA: " << nC << endl;
	    cout << "Initial array contents:" << endl;
	    PrintArray (testArray2, nC);
	    SelectionSort (testArray2, nC);
	    cout << "\nFinal array contents:" << endl;
	    PrintArray (testArray2, nC);
	    cout << endl;
	    break;
	  }
	}
      break;

    case 3:			//Quicksort
      cout <<
	"Which data set size would you like to test? (1)100, (2)1000, (3)10000: ";
      cin >> choice2;
      switch (choice2)
	{

	case 1:
	  {
	    //Random data set sort
	    cout << endl;
	    cout << "-----QUICKSORT-----" << endl;
	    aType testArray[100];
	    ifstream inFile ("Rand100.txt");
	    for (int i = 0; i < 100; i++)
	      {
		inFile >> testArray[i];
	      }
	    cout << "Random Data Set: " << endl;
	    int nA = sizeof (testArray) / sizeof (aType);
	    cout << "nA: " << nA << endl;
	    cout << "Initial array contents:" << endl;
	    PrintArray (testArray, nA);
	    Quicksort (testArray, 0, nA - 1);
	    cout << "\nFinal array contents:" << endl;
	    PrintArray (testArray, nA);
	    cout << endl;

	    //Low to High data set sort
	    aType testArray1[100];
	    ifstream inFile1 ("LowToHigh100.txt");
	    for (int i = 0; i < 100; i++)
	      {
		inFile1 >> testArray1[i];
	      }
	    cout << "Low To High Data Set: " << endl;
	    int nB = sizeof (testArray1) / sizeof (aType);
	    cout << "nA: " << nB << endl;
	    cout << "Initial array contents:" << endl;
	    PrintArray (testArray1, nB);
	    Quicksort (testArray1, 0, nB - 1);
	    cout << "\nFinal array contents:" << endl;
	    PrintArray (testArray1, nB);
	    cout << endl;

	    //High to Low data set sort
	    aType testArray2[100];
	    ifstream inFile2 ("HighToLow100.txt");
	    for (int i = 0; i < 100; i++)
	      {
		inFile2 >> testArray2[i];
	      }
	    cout << "High to Low Data Set: " << endl;
	    int nC = sizeof (testArray2) / sizeof (aType);
	    cout << "nA: " << nC << endl;
	    cout << "Initial array contents:" << endl;
	    PrintArray (testArray2, nC);
	    Quicksort (testArray2, 0, nC - 1);
	    cout << "\nFinal array contents:" << endl;
	    PrintArray (testArray2, nC);
	    cout << endl;
	    break;
	  }

	case 2:
	  {
	    //Random data set sort
	    cout << endl;
	    cout << "-----QUICKSORT-----" << endl;
	    aType testArray[1000];
	    ifstream inFile ("Rand1000.txt");
	    for (int i = 0; i < 1000; i++)
	      {
		inFile >> testArray[i];
	      }
	    cout << "Random Data Set: " << endl;
	    int nA = sizeof (testArray) / sizeof (aType);
	    cout << "nA: " << nA << endl;
	    cout << "Initial array contents:" << endl;
	    PrintArray (testArray, nA);
	    Quicksort (testArray, 0, nA - 1);
	    cout << "\nFinal array contents:" << endl;
	    PrintArray (testArray, nA);
	    cout << endl;

	    //Low to High data set sort
	    aType testArray1[1000];
	    ifstream inFile1 ("LowToHigh1000.txt");
	    for (int i = 0; i < 1000; i++)
	      {
		inFile1 >> testArray1[i];
	      }
	    cout << "Low To High Data Set: " << endl;
	    int nB = sizeof (testArray1) / sizeof (aType);
	    cout << "nA: " << nB << endl;
	    cout << "Initial array contents:" << endl;
	    PrintArray (testArray1, nB);
	    Quicksort (testArray1, 0, nB - 1);
	    cout << "\nFinal array contents:" << endl;
	    PrintArray (testArray1, nB);
	    cout << endl;

	    //High to Low data set sort
	    aType testArray2[1000];
	    ifstream inFile2 ("HighToLow1000.txt");
	    for (int i = 0; i < 1000; i++)
	      {
		inFile2 >> testArray2[i];
	      }
	    cout << "High to Low Data Set: " << endl;
	    int nC = sizeof (testArray2) / sizeof (aType);
	    cout << "nA: " << nC << endl;
	    cout << "Initial array contents:" << endl;
	    PrintArray (testArray2, nC);
	    Quicksort (testArray2, 0, nC - 1);
	    cout << "\nFinal array contents:" << endl;
	    PrintArray (testArray2, nC);
	    cout << endl;
	    break;
	  }

	case 3:
	  {
	    //Random data set sort
	    cout << endl;
	    cout << "-----QUICKSORT-----" << endl;
	    aType testArray[10000];
	    ifstream inFile ("Rand10000.txt");
	    for (int i = 0; i < 10000; i++)
	      {
		inFile >> testArray[i];
	      }
	    cout << "Random Data Set: " << endl;
	    int nA = sizeof (testArray) / sizeof (aType);
	    cout << "nA: " << nA << endl;
	    cout << "Initial array contents:" << endl;
	    PrintArray (testArray, nA);
	    Quicksort (testArray, 0, nA - 1);
	    cout << "\nFinal array contents:" << endl;
	    PrintArray (testArray, nA);
	    cout << endl;

	    //Low to High data set sort
	    aType testArray1[10000];
	    ifstream inFile1 ("LowToHigh10000.txt");
	    for (int i = 0; i < 10000; i++)
	      {
		inFile1 >> testArray1[i];
	      }
	    cout << "Low To High Data Set: " << endl;
	    int nB = sizeof (testArray1) / sizeof (aType);
	    cout << "nA: " << nB << endl;
	    cout << "Initial array contents:" << endl;
	    PrintArray (testArray1, nB);
	    Quicksort (testArray1, 0, nB - 1);
	    cout << "\nFinal array contents:" << endl;
	    PrintArray (testArray1, nB);
	    cout << endl;

	    //High to Low data set sort
	    aType testArray2[10000];
	    ifstream inFile2 ("HighToLow10000.txt");
	    for (int i = 0; i < 10000; i++)
	      {
		inFile2 >> testArray2[i];
	      }
	    cout << "High to Low Data Set: " << endl;
	    int nC = sizeof (testArray2) / sizeof (aType);
	    cout << "nA: " << nC << endl;
	    cout << "Initial array contents:" << endl;
	    PrintArray (testArray2, nC);
	    Quicksort (testArray2, 0, nC - 1);
	    cout << "\nFinal array contents:" << endl;
	    PrintArray (testArray2, nC);
	    cout << endl;
	    break;
	  }
	}
      break;
    }

  return 0;

}



/*  Mergesort:  Do a mergesort on array a.  
 *  Note:  This is a recursive routine.
 */

void
Mergesort (aType a[], int first, int last)
{
  int middle;
  if (first < last)
    {
      middle = (first + last) / 2;
      Mergesort (a, first, middle);
      Mergesort (a, middle + 1, last);
      Merge (a, first, middle, middle + 1, last);
    }
}

/*  Merge:  Merge two segments of an array together.  
 */

void
Merge (aType a[], int firstLeft, int lastLeft, int firstRight, int lastRight)
{
  aType tempArray[MAX_ARRAY];
  int index = firstLeft;
  int firstSave = firstLeft;
  //  Merge segments (array subsets)
  while ((firstLeft <= lastLeft) && (firstRight <= lastRight))
    {
      counter++;
      if (a[firstLeft] < a[firstRight])
	{
	  tempArray[index] = a[firstLeft];
	  firstLeft++;
	}
      else
	{
	  tempArray[index] = a[firstRight];
	  firstRight++;
	}
      index++;
    }
  //  Copy remainder of left array into tempArray
  while (firstLeft <= lastLeft)
    {
      counter++;
      tempArray[index] = a[firstLeft];
      firstLeft++;
      index++;
    }

  //  Copy remainder of right array into tempArray
  while (firstRight <= lastRight)
    {
      counter++;
      tempArray[index] = a[firstRight];
      firstRight++;
      index++;
    }

  //  Copy back into original array
  for (index = firstSave; index <= lastRight; index++)
    {
      a[index] = tempArray[index];
    }
//cout << "Total Comparisons: " << counter << endl;
}


/*  SelectionSort:  Sort and array, A, using a selection
 *  sort algorithm.
 */

void
SelectionSort (aType A[], int nElements)
{
  int iSmallest;
  aType tmp;
  cout << endl;
  for (int i = 0; i < nElements; i++)
    {

      iSmallest = IndexOfSmallest (A, i, nElements - 1);
      //  swap
      if (iSmallest > i)
	{
	  tmp = A[i];
	  A[i] = A[iSmallest];
	  A[iSmallest] = tmp;
	  counter++;
	}
    }
  //cout << "Total Comparisons: " << counter << endl;
}

int
IndexOfSmallest (aType A[], int iStart, int iEnd)
{
  int index = -1;
  aType aMin = A[iStart];

  for (int i = iStart; i <= iEnd; i++)
    {
      if (A[i] < aMin)
	{
	  aMin = A[i];
	  index = i;
	}
    }

  return index;
}


/*  Quicksort:  Sort an array a, using the quicksort
 *  algorithm.
 */

void
Quicksort (aType a[], int first, int last)
{
  int pivot;

  if (first < last)
    {
      pivot = Pivot (a, first, last);
      Quicksort (a, first, pivot - 1);
      Quicksort (a, pivot + 1, last);
      counter++;
    }
//cout << "Total Comparisons: " << counter << endl;
}


/*  Pivot:  Find and return the index of pivot element.
 */

int
Pivot (aType a[], int first, int last)
{
  int p = first;
  aType pivot = a[first];

  for (int i = first + 1; i <= last; i++)
    {
      if (a[i] <= pivot)
	{
	  p++;
	  Swap (a[i], a[p]);
	}
    }
  Swap (a[p], a[first]);
  return p;
}


/*  Swap:  Swap two items (by reference).
 */
void
Swap (aType & v1, aType & v2)
{
  aType tmpVal;

  tmpVal = v1;
  v1 = v2;
  v2 = tmpVal;
}


/*  PrintArray:  Print contents of an array.
 */
void
PrintArray (aType A[], int nElements)
{
  cout << "Total Comparisons: " << counter << endl;
}
