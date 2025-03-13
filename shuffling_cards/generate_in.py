from random import randint

N_UPPER = int(1e5)

def generate_inputs(
    first_tc_no,
    last_tc_no,
    n_lower,
    n_upper,
    time_intensive=False
):
    for i in range(first_tc_no, last_tc_no + 1):
        with open(f"./in/input{i}.txt", 'w') as file:
            n = randint(n_lower, n_upper)
            i = randint(1, 1 if time_intensive else 2 * n)
            j = randint(2 * n if time_intensive else 1, 2 * n)
            file.write(f"{n} {i} {j}\n")


def main():
    generate_inputs(
        first_tc_no = 1,
        last_tc_no = 5,
        n_lower = 1,
        n_upper = int(0.8 * N_UPPER),
    )

    generate_inputs(
        first_tc_no = 6,
        last_tc_no = 15,
        n_lower = int(0.8 * N_UPPER),
        n_upper = N_UPPER,
        time_intensive = True
    )

    generate_inputs(
        first_tc_no = 16,
        last_tc_no = 20,
        n_lower = int(0.95 * N_UPPER),
        n_upper = N_UPPER,
        time_intensive = True
    )

if __name__ == "__main__": main()
