from random import randint

N_UPPER = 18
P_UPPER = int(1e9)

def generate_inputs(
    first_tc_no,
    last_tc_no,
    n_lower,
    n_upper,
    p_upper,
    time_intensive=True
):
    for i in range(first_tc_no, last_tc_no + 1):
        with open(f"./in/input{i}.txt", 'w') as file:
            n = randint(n_lower, n_upper)
            k = randint(int(0.8 * n) if time_intensive else 1, n)
            file.write(f"{n} {k}\n")

            for _ in range(1 << n): file.write(f"{randint(1, p_upper)} ")
            file.write("\n")

def main():
    generate_inputs(
        first_tc_no = 1,
        last_tc_no = 5,
        n_lower = 1,
        n_upper = int(0.8 * N_UPPER),
        p_upper = P_UPPER,
        time_intensive = False
    )

    generate_inputs(
        first_tc_no = 6,
        last_tc_no = 15,
        n_lower = int(0.8 * N_UPPER),
        n_upper = N_UPPER,
        p_upper = P_UPPER
    )

    generate_inputs(
        first_tc_no = 16,
        last_tc_no = 20,
        n_lower = N_UPPER,
        n_upper = N_UPPER,
        p_upper = P_UPPER
    )


if __name__ == "__main__": main()
