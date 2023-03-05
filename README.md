# External Memory Sorting
The main objective of this program is to process a series of entities (URLs and visit numbers) and organize them into tapes, which are blocks of entities that will be merged later. This organization allows for a more efficient sorting of data in secondary memory, as it is not necessary to load all the data at once in RAM.

After dividing into tapes, the program sorts the tapes in decreasing order of visits, and in alphabetical order in case of a tie. This process is performed for each of the generated tapes with QuickSort.

Finally, the sorted tapes are merged through a Heap, resulting in a single sorted file of entities, again following the same sorting criteria.

The ultimate goal of the program is therefore to generate a sorted file containing all input entities, efficiently in terms of memory usage and processing time.

All data structures were implemented without using the STL or similar libraries.

## Compilation:
To compile the program, navigate to the directory containing the source code and run the following command:

    make all
## Usage:
To use the program, run the following command:
    
    ./bin/main <input_file> <output_file> <tape_size>
    
    <input_file>: The name of the input file containing the list of entities to be sorted.
    <output_file>: The name of the output file to be generated after the sorting operation.
    <tape_size>: The size of each tape to be used in the sorting operation.

## Example:
Suppose we have a file named entities.txt containing the following entities:
    
    https://www.google.com 100
    https://www.yahoo.com 50
    https://www.amazon.com 75
    https://www.facebook.com 80
    
To sort these entities using a tape size of 2, we would run the following command:

    ./bin/main ./entities.txt ./sorted_entities.txt 2
    
The resulting sorted_entities.txt file would contain the following entities in descending order of visit count:

    https://www.google.com 100
    https://www.facebook.com 80
    https://www.amazon.com 75
    https://www.yahoo.com 50
