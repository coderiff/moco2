#include <iostream>
#include <vector>

size_t find_rotated_count(const std::vector<int>& arr);

int main(int argc, char* argv[])
{
    // Assuming left-shift.
    std::vector<int> arr_rotated_3 = {4, 5, 1, 2, 3};
    std::vector<int> arr_rotated_4 = {5, 1, 2, 3, 4};
    std::vector<int> arr_rotated_5 = {6, 7, 8, 9, 10, 1, 2, 3, 4, 5};

    std::cout << find_rotated_count(arr_rotated_4) << std::endl;
}

size_t find_rotated_count(const std::vector<int>& arr)
{
    if (arr[0] < arr[arr.size()-1]) return 0; // not rotated

    size_t i = 0;
    size_t j = arr.size();

    while (1)
    {
        /**
         * find i which satisfies "arr[i] > arr[i+1]"
         * and return (arr.size() - (i + 1))
         */

        // if (i > j) return what??; // Can this be happened?

        if (arr[i] > arr[i+1]) return (arr.size() - (i + 1));

        size_t mid = (i + j) / 2;

        /**
         * 1st iteration
         *
         * [4, 5, 1, 2, 3]
         *  i    mid    j
         *
         * case 1) 1  <  3 : this is always true on sorted list.
         * case 2) 4  >  1 : something is wrong here. need to check this block
         */

        if (arr[i] > arr[mid]) j = mid;
        else                   i = mid;
    }
}
