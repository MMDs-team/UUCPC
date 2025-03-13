import os
import subprocess
import sys

def compile_and_run(src_code):
    if not os.path.isfile(src_code):
        print(f"Error: Source file '{src_code}' not found.")
        return

    _, ext = os.path.splitext(src_code)
    if ext == ".cpp":
        compile_command = ["g++", "-std=c++20", src_code, "-o", "solver"]
        run_command = "./solver"
    elif ext == ".c":
        compile_command = ["gcc", src_code, "-o", "solver"]
        run_command = "./solver"
    else:
        print(f"Error: Unsupported file type '{ext}'. Supported types: .c, .cpp, .py")
        return

    if compile_command:
        result = subprocess.run(compile_command, capture_output=True, text=True)
        if result.returncode != 0:
            print("Compilation failed:")
            print(result.stderr)
            return

    out_dir = "out"
    if not os.path.exists(out_dir):
        os.makedirs(out_dir)

    in_dir = "in"
    if not os.path.exists(in_dir):
        print(f"Error: Directory '{in_dir}' not found.")
        return

    for input_file in os.listdir(in_dir):
        if input_file.startswith("input") and input_file.endswith(".txt"):
            input_path = os.path.join(in_dir, input_file)
            output_file = f"output{input_file[5:-4]}.txt"
            output_path = os.path.join(out_dir, output_file)

            with open(input_path, "r") as infile, open(output_path, "w") as outfile:
                if compile_command:
                    process = subprocess.run(run_command, stdin=infile, stdout=outfile, stderr=subprocess.PIPE, text=True)
                else:
                    process = subprocess.run(run_command, stdin=infile, stdout=outfile, stderr=subprocess.PIPE, text=True)

                if process.returncode != 0:
                    print(f"Error running the program for {input_file}:")
                    print(process.stderr)

    print("All input files processed successfully.")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python script.py <source_code_file>")
    else:
        src_code = sys.argv[1]
        compile_and_run(src_code)
