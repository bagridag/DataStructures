A double ended priority queue is implemented using min-max heap structure. There is a class called Heap, and it has 10 methods in it. By creating an object of the class and using the methods, a min-max heap is created from an array and printed out to a text file. After the deleteMin() and deleteMax() operations, resulting heap is again printed out to a seperate text file. 
Inputs from the user were taken as build(argv[1]), print(argv[2]) and print(argv[3]) in the main method. 

Building the heap in linear time : First the strings from the text file is put in to the array by callind the add method in the build function: 
  
  void Heap :: add( string item ) {
        int hole =++size;
        array [hole] = item;
    }

After that the indexes starting from the array’s current size/2 to array 0, the element is percolated down. Percolate down method is created from the Atkinson’s algorithm to work in linear time. 

I stored the first and second strings from the text file in the strings called “a” and “b”. Then i iterated through the array and compared all the elements using “compare” method to find the ones that are greater than b (for deleteMax) and less than a (for deleteMin). Then to maintain the heap structure i percolatedDown the items that i put at the end of the array. And these were the smaller ones than “a” and greater ones than “b”.  Here’s the code that i’ve used for that. It’s the deleteMin, and deleteMax is only differed in  if condition which is if((array[x].compare(b) > 0)) .   

for(int x= size; x> 0; x--)
        {
             if((array[x].compare(a)< 0))
            {
                array[x]= array[size--];
                percolateDown(x);
            }
         }
