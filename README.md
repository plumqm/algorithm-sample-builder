# Algorithm Sample Builder

This repository stores competitive programming sample/testcase generation code for both Windows and macOS. It includes a generator (`makedata.cpp`), a reference solution (`std.cpp`), and helper scripts to produce `.in` and `.out` files.

## Structure

- `makedata.cpp`: input generator. Takes an optional index argument to vary the case.
- `std.cpp`: reference solution used to produce correct outputs.
- `cases/`: generated testcases (`*.in` and `*.out`).
- `loop.sh`: macOS/Linux script that builds and generates cases.
- `loop.command`: macOS double-click wrapper that runs `loop.sh`.
- `loop.bat`: Windows batch script that generates cases (expects `makedata.exe` and `std.exe`).

## Usage

### macOS / Linux

```bash
./loop.sh
```

This script:

1. Compiles `makedata.cpp` and `std.cpp` into `makedata` and `std`.
2. Runs the generator for each index and saves inputs to `cases/<i>.in`.
3. Pipes each input into the reference solution to produce `cases/<i>.out`.

If you prefer double-click on macOS, run `loop.command`.

### Windows

1. Compile the executables:

```bat
g++ -std=gnu++17 -O2 -o makedata.exe makedata.cpp
g++ -std=gnu++17 -O2 -o std.exe std.cpp
```

2. Run:

```bat
loop.bat
```

The batch script generates `cases/<i>.in` and `cases/<i>.out` the same way.

## Logic Overview

- `makedata.cpp` generates input data for a specific index. It uses a mixed seed (time + index) so each case is different, while keeping special indices as fixed edge cases.
- `std.cpp` computes the correct answer for each input using a bottom-up DP approach on the pyramid array and outputs the final result.
- The scripts iterate from `i = 1` to `COUNT` (default 15), generating one `.in` and one `.out` per index.

## Customization

- Change `COUNT` or `OUT_DIR` in `loop.sh` and `loop.bat` to control how many cases to generate and where to place them.
