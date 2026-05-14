# Algorithm Sample Builder 算法竞赛数据生成器

这是一个轻量级、跨平台的算法竞赛测试数据生成模板项目，适用于快速为题目生成标准的 `.in` 和 `.out` 测试用例。本项目包含数据生成器模板、标准程序模板以及跨平台的自动化脚本。

## 📁 目录结构

```text
捏数据/
├── makedata.cpp    # 数据生成器，负责根据传入的序号生成 .in 文件的数据
├── std.cpp         # 题目标准程序，通过读取 .in 文件计算输出，生成 .out 文件
├── loop.sh         # macOS/Linux 环境下的一键生成脚本
├── loop.bat        # Windows 环境下的一键生成脚本
└── cases/          # 自动生成的测试用例输出目录 (1.in, 1.out, ...)
```

## 🛠️ 环境准备

- C++ 编译器（支持 C++17 或以上），如 `g++` 或 `clang++`。
- macOS 环境推荐通过 Homebrew 安装 `gcc`。

## 🚀 使用指南

### macOS / Linux 平台

1. 打开终端，进入 `捏数据` 目录：
   ```bash
   cd 捏数据
   ```
2. 给予脚本执行权限（仅首次需要）：
   ```bash
   chmod +x loop.sh
   ```
3. 编译并生成测试数据：
   ```bash
   # 手动编译
   g++ -std=gnu++17 -O2 makedata.cpp -o makedata
   g++ -std=gnu++17 -O2 std.cpp -o std
   
   # 执行自动化生成
   ./loop.sh
   ```

### Windows 平台

1. 在 `捏数据` 目录下编译源码为 `.exe` 文件：
   ```cmd
   g++ -std=gnu++17 -O2 makedata.cpp -o makedata.exe
   g++ -std=gnu++17 -O2 std.cpp -o std.exe
   ```
2. 双击运行 `loop.bat`，或者在 CMD/PowerShell 中运行：
   ```cmd
   loop.bat
   ```

## 🧠 核心逻辑

1. **`makedata.cpp`**
   - 接收命令行参数作为“当前用例序号（`idx`）”。
   - 采用时间戳 + 序号的哈希作为随机数种子，保证生成的随机性。
   - 通过 `idx` 在代码里设置分支（if-else），可以构造：**极小值**、**最大值边界**、**特殊样例**以及常规的大规模随机数据。
   
2. **`std.cpp`**
   - 标准解程序。采用标准输入/输出流 (`cin/cout`)，**无需在此处写重定向**。读取输入并计算正确答案。

3. **自动化脚本 (`loop.sh` & `loop.bat`)**
   - 内部包含一个 for 循环，从 `1` 迭代到 `COUNT`（默认 15 组）。
   - 工作流：执行生成器输出到 `i.in` $\rightarrow$ 执行标准程序读取 `i.in` $\rightarrow$ 标准程序答案输出到 `i.out`。
