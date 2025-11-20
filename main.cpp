#include <iostream>
#include <cassert>

void test_compute_median()
{
    // 奇数要素
    {
        std::vector<float> v = {3.0f, 1.0f, 2.0f};
        assert(compute_median(v) == 2.0f);
    }

    // 偶数要素
    {
        std::vector<float> v = {4.0f, 1.0f, 3.0f, 2.0f};
        assert(compute_median(v) == 2.5f);
    }

    // 負の値を含む
    {
        std::vector<float> v = {-5.0f, 2.0f, -3.0f};
        assert(compute_median(v) == -3.0f);
    }

    // 逆順の入力
    {
        std::vector<float> v = {9.0f, 7.0f, 5.0f, 3.0f};
        assert(compute_median(v) == 6.0f); 
    }

    // 1要素のみ
    {
        std::vector<float> v = {42.0f};
        assert(compute_median(v) == 42.0f);
    }

    std::cout << "All tests passed!\n";
}

int main() {
    test_compute_median();
}
