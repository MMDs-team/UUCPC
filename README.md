# UUCPC Problem Setting Repository

This repository contains the problem sets and associated files for the **UUCPC (University-Level Contest Preparation Competition)**, an ICPC-style programming contest organized by our ACM group of Urmia University. The goal of this repository is to facilitate the creation, testing, and management of problems for the contest.

## Table of Contents

1. [Repository Overview](#repository-overview)
2. [Directory Structure](#directory-structure)
3. [Problem Components](#problem-components)
4. [How to Contribute](#how-to-contribute)
5. [Testing Problems](#testing-problems)
6. [Useful Scripts](#useful-scripts)
7. [License](#license)

---

## Repository Overview

The UUCPC repository is organized into individual directories for each problem. Each directory contains all the necessary files for defining, generating inputs/outputs, and solving the problem. This structure ensures consistency and makes it easy to manage multiple problems.

---

## Directory Structure

The repository follows a hierarchical structure:

```
UUCPC
├── README.md                # General instructions for the repository
├── <problem_name>           # Directory for each problem
│   ├── build.sh             # Script to compile solutions
│   ├── generate_in*.py      # Scripts to generate input files
│   ├── generate_out.py      # Script to generate output files
│   ├── in/                  # Input test cases
│   ├── out/                 # Expected output files
│   ├── problem_description.txt # Problem statement or description
│   ├── solution.cpp         # Reference solution
│   └── solver.exe           # Compiled solver (optional)
└── ...                      # Additional problems
```

Each problem has its own directory, named after the problem (e.g., `3Dspace`, `asphalt`, `cardboard_for_pictures`, etc.). These directories contain all the files needed for that specific problem.

---

## Problem Components

Each problem directory typically includes the following components:

1. **Problem Description (`problem_description.txt`)**:
   - A detailed explanation of the problem, including the problem statement, constraints, input/output format, and examples.

2. **Input Files (`in/`)**:
   - A collection of test cases stored as `.txt` files (e.g., `input1.txt`, `input2.txt`).

3. **Output Files (`out/`)**:
   - Expected outputs corresponding to the input files, generated using the reference solution.

4. **Reference Solution (`solution.cpp`)**:
   - A correct implementation of the problem's solution, used to generate output files.

5. **Input/Output Generation Scripts**:
   - Python scripts (`generate_in*.py`, `generate_out.py`) to automate the creation of test cases and expected outputs.

6. **Build Script (`build.sh`)**:
   - A shell script to compile the reference solution and any other necessary files.

7. **Optional Files**:
   - Additional files such as `problem.zip`, `solver.exe`, or `test.sh` may be included for convenience or specific use cases.

---

## How to Contribute

Contributors are welcome to add new problems, improve existing ones, or enhance the repository's structure. Follow these steps to contribute:

1. **Fork the Repository**:
   - Create a fork of this repository to your GitHub account.

2. **Clone the Repository**:
   ```bash
   git clone https://github.com/MMDs-team/UUCPC.git
   cd UUCPC
   ```

3. **Add a New Problem**:
   - Create a new directory under `UUCPC/` with the problem name.
   - Add the required files: `problem_description.txt`, `solution.cpp`, `generate_in*.py`, `generate_out.py`, `build.sh`, and others as needed.

4. **Test Your Problem**:
   - Use the provided scripts (`build.sh`, `test.sh`) to verify that your problem works correctly.

5. **Submit a Pull Request**:
   - Push your changes to your fork and submit a pull request to the main repository.

---

## Testing Problems

To ensure the correctness of a problem, follow these steps:

1. **Compile the Solution**:
   ```bash
   ./build.sh
   ```

2. **Generate Inputs and Outputs**:
   - Run the input generation scripts:
     ```bash
     python3 generate_in1.py > in/input1.txt
     ```
   - Generate outputs using the reference solution:
     ```bash
     ./solver.exe < in/input1.txt > out/output1.txt
     ```

3. **Run Tests**:
   - Use the `test.sh` script (if available) to validate all test cases:
     ```bash
     ./test.sh
     ```

---

## Useful Scripts

- **`build.sh`**: Compiles the reference solution (`solution.cpp`) into an executable.
- **`generate_in*.py`**: Generates input test cases based on problem constraints.
- **`generate_out.py`**: Runs the reference solution on input files to produce expected outputs.
- **`test.sh`**: Automates the testing process for all input/output pairs.

---

## License

This repository is licensed under the [MIT License](LICENSE). Feel free to use, modify, and distribute the contents as per the terms of the license.

---

If you have any questions or need further clarification, feel free to open an issue or contact the repository maintainers.

Happy problem-solving! 🚀
