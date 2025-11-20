#include <algorithm>
#include <vector>
#include <stdexcept>

/**
 * @brief ベクタ内の中央値を計算する
 *
 * 時間計算量:
 *   - nth_element は平均 O(N)
 *   - 偶数個の場合は2回 nth_element を呼ぶため 平均 O(2N) ≒ O(N)
 *
 * @param v 中央値を計算する対象の float ベクタ
 * @return float 中央値
 */
float compute_median(std::vector<float> v)
{
    if (v.empty()) {
        throw std::invalid_argument("compute_median: vector is empty");
    }

    size_t N = v.size();
    size_t mid1 = (N - 1) / 2;  // 奇数: middle, 偶数: lower middle
    size_t mid2 = N / 2;        // 奇数: same as mid1, 偶数: upper middle

    // mid1 番目の値を v[mid1] の位置に持ってくる
    std::nth_element(v.begin(), v.begin() + mid1, v.end());
    float a = v[mid1];

    if (mid1 == mid2) {
        // 奇数の場合はこれが中央値
        return a;
    }

    // 偶数の場合は mid2 も求める
    std::nth_element(v.begin(), v.begin() + mid2, v.end());
    float b = v[mid2];

    return (a + b) * 0.5f;
}
