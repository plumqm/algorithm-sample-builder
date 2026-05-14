#include <bits/stdc++.h>
using namespace std;

static int get_index(int argc, char **argv) {
    if (argc >= 2) {
        return atoi(argv[1]);
    }
    return 0;
}

static uint64_t make_seed(int idx) {
    uint64_t now = static_cast<uint64_t>(chrono::high_resolution_clock::now().time_since_epoch().count());
    uint64_t mix = static_cast<uint64_t>(idx) * 0x9e3779b97f4a7c15ULL;
    return now ^ (mix + (now << 1));
}

// 最大子段和问题：生成序列长度 n 和序列元素
static void generate_case(int idx) {
    int n;
    vector<int> arr;
    uint64_t seed = make_seed(idx);
    mt19937 rng(static_cast<uint32_t>(seed) ^ static_cast<uint32_t>(seed >> 32));
    
    if (idx == 1) {
        // 样例数据
        n = 7;
        arr = {2, -4, 3, -1, 2, -4, 3};
    } 
    else if (idx == 2) {
        // 全正数
        n = 10;
        arr.resize(n);
        uniform_int_distribution<int> dist(1, 100);
        for (int i = 0; i < n; i++) {
            arr[i] = dist(rng);
        }
    } 
    else if (idx == 3) {
        // 全负数
        n = 10;
        arr.resize(n);
        uniform_int_distribution<int> dist(-100, -1);
        for (int i = 0; i < n; i++) {
            arr[i] = dist(rng);
        }
    } 
    else if (idx == 4) {
        // 只有一个元素
        n = 1;
        arr = {5};
    } 
    else if (idx == 5) {
        // 只有一个负数元素
        n = 1;
        arr = {-5};
    } 
    else if (idx == 6) {
        // 正负交替
        n = 20;
        arr.resize(n);
        for (int i = 0; i < n; i++) {
            arr[i] = (i % 2 == 0) ? 10 : -5;
        }
    } 
    else if (idx == 7) {
        // 大规模数据：最大值边界
        n = 200000;
        arr.resize(n);
        uniform_int_distribution<int> dist(-10000, 10000);
        for (int i = 0; i < n; i++) {
            arr[i] = dist(rng);
        }
    } 
    else if (idx == 8) {
        // 大规模全正数
        n = 200000;
        arr.resize(n);
        uniform_int_distribution<int> dist(1, 10000);
        for (int i = 0; i < n; i++) {
            arr[i] = dist(rng);
        }
    } 
    else if (idx >= 9 && idx <= 13) {
        // 小规模随机数据
        uniform_int_distribution<int> dist_n(5, 20);
        n = dist_n(rng);
        arr.resize(n);
        uniform_int_distribution<int> dist_val(-50, 50);
        for (int i = 0; i < n; i++) {
            arr[i] = dist_val(rng);
        }
    } 
    else if (idx >= 14 && idx <= 18) {
        // 中等规模随机数据
        uniform_int_distribution<int> dist_n(100, 1000);
        n = dist_n(rng);
        arr.resize(n);
        uniform_int_distribution<int> dist_val(-1000, 1000);
        for (int i = 0; i < n; i++) {
            arr[i] = dist_val(rng);
        }
    } 
    else if (idx >= 19 && idx <= 23) {
        // 较大规模随机数据
        uniform_int_distribution<int> dist_n(10000, 200000);
        n = dist_n(rng);
        arr.resize(n);
        uniform_int_distribution<int> dist_val(-10000, 10000);
        for (int i = 0; i < n; i++) {
            arr[i] = dist_val(rng);
        }
    } 
    else {
        // 默认随机数据
        uniform_int_distribution<int> dist_n(1, 200000);
        n = dist_n(rng);
        arr.resize(n);
        uniform_int_distribution<int> dist_val(-10000, 10000);
        for (int i = 0; i < n; i++) {
            arr[i] = dist_val(rng);
        }
    }

    // 输出
    cout << n << '\n';
    for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cout << arr[i];
    }
    cout << '\n';
}

int main(int argc, char **argv) {
    int idx = get_index(argc, argv);
    generate_case(idx);
    return 0;
}