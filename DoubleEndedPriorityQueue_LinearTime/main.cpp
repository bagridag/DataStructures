/*
Student Name: Burcak AGRIDAG
Student Number: 2011400330
Project Number: 2
Operating System: {Windows[7]}
Compile Status: {Compiling}
Program Status: {Working}

*/


#include <iostream>
#include <fstream>
#include <string>
#include <cmath>



using namespace std;
class Heap
{

string *array;
    public:
    static int size; // current size of the array[]
    static string a, b; // static string variables to hold first and second strings from the input files
   //heap constructor
    Heap(int c){
      array = new string[c+1];//create an array of initial capacity "c"
        }

        void build(const char*); // builds the min max heap
        void add(string); //adds the given strings into the array
        void deleteMin(); // deletes the elements smaller than "string a"
        void deleteMax(); //deletes the lements greater than "string b"
        void percolateDown(int );// percolates down the given number of array
        void percolateDownMax(int );
        void percolateDownMin(int );
        int findMin(int, int);// to percolate down, finds the minimum of the child and the grandchild if exists
        int findMax(int, int); // to percolate down, finds the maximum of the child and the grandchild if exists
        void print(const char*); //prints the heap to an output file
};
  int Heap::size=0; //initially assign size to zero
  string Heap:: a= " " ; //initially assign string a
  string Heap :: b = " " ; //initially assign string b

/*
Builds the heap, takes the input file as a parameter. Calls the "add" method
to put the words in the array. Stores the first to lines in "string a" and "string b"

*/
 void Heap:: build(const char* inputFile)
{
 ifstream inFile(inputFile);
   string word;

   while (inFile >> word)
   {
        add(word);
       }
        a= array[1];
        b= array[2];


       for(int x= size/2; x> 0; x--)
       {
           percolateDown(x);
       }
   }
   //adds the strings sent from the build method.
    void Heap :: add( string item ) {
        int hole =++size;
        array [hole] = item;
    }
    /*deletes the strings that are lexicographically smaller than "string a" and percolates down */
    void Heap:: deleteMin(){

        for(int x= size; x> 0; x--)
        {
             if((array[x].compare(a)< 0))
            {
                array[x]= array[size--];
                percolateDown(x);
            }
         }
    }

/*Deletes the strings that are greater than "string b" and percolates them down */
 void Heap:: deleteMax()
     {
        for(int x= size; x> 0; x--)
        {
            if((array[x].compare(b)) > 0 )
            {
                array[x]=array[size--];
                percolateDown(x);
            }
        }
     }

//prints the current heap to an output file
    void Heap:: print(const char* outputFile)
    {
        ofstream oFile(outputFile);
        if(oFile.is_open())
        {
        for(int x= 1; x<=size ; x++)
        {
            oFile<<array[x]<<endl;
        cout<<array[x]<<endl;
        }
        }
         cout<< "   " <<endl;
    }
   /* Maintains the heap order after deletion. Used to construct heap structure also.
      Calls percolateDownMax function for max levels- percolateDownMin for min levels.
   */
   void Heap::percolateDown(int hole)
   {
      int level= floor(log2(hole)); //determines the level of the element
      if(level%2 == 0) // element is on the min level
      {
          percolateDownMin(hole);
      }
      else{ // element is on max level
      percolateDownMax(hole);
      }
   }


   void Heap:: percolateDownMin(int hole)
   {
        // hole * 2 = index of first child if  exists
        // hole * 4 = index of first grandchild if exists

        int m = findMin (hole*2, hole*4); //finds the minimum of child and grandchild
        if(m > 0) //if array[hole] has a children
    {
        int parent= floor(m/2);//finds the parent's index
           if( m >= hole * 4 ) // array[m] is a grandchild of array[hole]
             {

           if( array[ m ].compare(array[hole]) < 0)// if array[m] is less than array[grandparent]
                {
                    swap( array[hole], array[m] );

                    if( array[ m ].compare(array[parent]) >0) //if array[m] is greater than array[grandparent]
                    {

                        swap( array[m],array[ parent] );
                    }

                    percolateDownMin( m );
                 }
             }
            else if(m>= hole*2 )
            {
                if(array[m].compare(array[hole])< 0 ) //if array[m] is less than its parent
                {
                    swap(array[hole], array[m]);
                }
            }
        }
   }

void Heap:: percolateDownMax(int hole)
{
    //finds the  maximum of children and grandchildren
        // hole * 2 = index of first child if  exists
        // hole * 4 = index of first grandchild if exists

    int maxIn= findMax(hole*2, hole*4);
    if(maxIn> 0)
  {
    int parent = floor(maxIn/2); //finds parent's index
    if(maxIn>= hole*4)
    {
        if(array[maxIn].compare(array[hole])> 0 )
        {
            swap(array[hole], array[maxIn]);
            if(array[maxIn].compare(array[parent])<0 )
            {
                swap(array[maxIn], array[parent]);

            }
            percolateDownMax(maxIn);
        }
    }
    else
    {
    if( array [maxIn].compare(array[hole])>0  )
      {
        swap(array[hole], array[maxIn]);
      }
    }
  }
}
/*Finds the minimum of the childeren and grandchildren(if any) and returns its index */
int Heap:: findMin(int child, int grandchild)//takes the first child and grandchild's index as a parameter
{
    int m= 0;
    int minChild= child;
    int minGrandChild = grandchild;
    if(child<=size)
    {
        if(child!= size && array[child+1].compare(array[minChild])<0)
        {
            minChild=child+1;
        }
        m= minChild;
    }
    if(grandchild <= size)
    {
        for(int i= 1; grandchild< size && i< 4; i++ , grandchild++)
        {
            if( array[grandchild+1].compare(array[minGrandChild]) < 0 )
            {
                minGrandChild= grandchild+1;
            }
        }
        if(array[minGrandChild].compare(array[minChild])<0)
        {
            m= minGrandChild;
        }
    }
    return m;
}
/*Finds the maximum of the childeren and grandchildren(if any) and returns its index */
int Heap::findMax(int child, int grandchild)
{
     int maxIn = 0;
        int maxChild = child;
        int maxGrandchild = grandchild;
        if( child <= size) {
            if( child != size && array[ child + 1 ].compare(array[maxChild]) > 0) {
                maxChild = child + 1;
            }

            maxIn = maxChild;

            if( grandchild <= size ) {
                for( int i = 1; grandchild < size && i < 4; i++, grandchild++ ) {
                    if( array[ grandchild + 1 ].compare(array[maxGrandchild]) >0)  {
                        maxGrandchild = grandchild + 1;
                    }
                }

                if( array[ maxGrandchild ].compare(array[maxChild]) >0) {
                    maxIn = maxGrandchild;
                }
            }
        }
        return maxIn;
    }

int main()
{
Heap hip(200); // create the heap with initial capacity 200.
hip.build(argv[1]); // takes the input text parameter and builds the min-max heap
hip.print(argv[2]); // creates the output 1 file
hip.deleteMin();
hip.deleteMax();
hip.print(argv[3]); // creates the output 2 file


}
