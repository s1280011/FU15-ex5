#include <algorithm>
#include <vector>
#include <stdexcept>

//time complexity
 N = odd number: O(N)
 N = even number:
If there are even numbers, nth_element is called twice, so average is O(2N) ≒ O(N)
//

float compute_median(std::vector<float> v)
{
    if (v.empty()) {
        throw std::invalid_argument("compute_median: vector is empty");
    }

    size_t N = v.size();
    size_t mid1 = (N - 1) / 2;  
    size_t mid2 = N / 2;       

    std::nth_element(v.begin(), v.begin() + mid1, v.end());
    float a = v[mid1];

    if (mid1 == mid2) { // N = odd number
        return a;
    }

    std::nth_element(v.begin(), v.begin() + mid2, v.end()); // N = even number
    float b = v[mid2];
    return (a + b) * 0.5f;
}
