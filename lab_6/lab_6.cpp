/*
 * Name        : lab_6.cpp
 * Author      : Noah Pineda
 * Description : Working with Arrays
 */

#include "lab_6.h"

// CODE HERE (FUNCTION DEFINITIONS)
/*
 * Create a string containing the contents of an array, each element separated
 * by a specified character. For example, if the array contents
 * are {1, 2, 3} and the separator character is ':', the string returned
 * will be "1:2:3".
 * @uses stringstream
 * @param int values[] - An array of integers
 * @param int size - The size of the integer array
 * @param char separator - The separator character to use in the returned
 *                         string.
  *                        Defaults to ','
 * @return string - A string containing the contents of values separated by the
 *                  specified separator character
 */
string PrepareForDisplay(int values[], int size, char separator){
    stringstream ss;
    int temp = size - 1;
    for(int i = 0; i < size; i++){
        if(i == (size - 1))
            ss << values[i];
        else
            ss << values[i] << separator;
    }
    return ss.str();
}

/*
 * Test to see if an array contains a specified value.
 * @param int values -  An array of integers
 * @param int size - The size of the integer array
 * @param int value - The value to search for within the array
 * @return bool - true if value is found in the array, otherwise false
 */
bool HasValue(int values[], int size, int value){
    stringstream ss;
     int count;
    bool found(false);
   for(int i = 0; i < size; i++){
        count ++;
        if(i == (size - 1))
            ss << values[i];
        else
            ss << values[i] << " ";
    }
    cout << ss.str() << endl;
    int check;
    for(int i = 0; i < count; i++){
        ss >> check;
        if(check == value){
            found = true;
        }
    }
    return found;
}

/*
 * Return the value from an array at a specified index.
 * @param int values -  An array of integers
 * @param int size - The size of the integer array
 * @param int index - The position in the array from which to return a value
 * @param bool &error - A flag that will be set to true if index is invalid for
 *                      the array, else it will be set to false
 * @return int - The value at the specified index in the array when error is set
 *               to false. if index is invalid, returns 0 and sets error to true
 */
int ValueAt(int values[], int size, int index, bool &error){
    if(index >= size){
        index = 0;
        error = true;
        return 0;
    }
    else{
        error = false;
        return values[index];
    }
}

/*
 * Return the sum of the values in an integer array.
 * @param int values - An array of integers
 * @param int size - The size of the integer array
 * @return int - The sum of the values in the array
 */
int Sum(int values[], int size){
    int sum = 0;
    for(int i = 0;i < size;i++){
        sum = sum + values[i];
    }
    return sum;
}

/*
 * Swap the positions of two values in an integer array. The two
 * index values must be valid for the array.
 * @param int values - An array of integers
 * @param int size - The size of the integer array
 * @param int index1 - The position of the first value to be swapped
 * @param int index2 - The position of the second value to be swapped
 * @return bool - true if the swap was successful, otherwise false
 */
bool SwapValues(int values[], int size, int index1, int index2){
    bool success = false;
    int temp1,temp2;
    if(index1 < size && index1 >= 0 && index2 < size && index2 >= 0){
        temp1 = values[index1];
        temp2 = values[index2];
        values[index1] = temp2;
        values[index2] = temp1;
        success = true;
    }
    return success;
}
