from random import randint

N_UPPER = M_UPPER = int(1e12)

def generate_inputs(
    first_tc_no,
    last_tc_no,
    n_lower,
    n_upper,
    m_lower,
    m_upper,
    time_intensive=False
):
    for i in range(first_tc_no, last_tc_no + 1):
        with open(f"./in/input{i}.txt", 'w') as file:
            n = randint(n_lower, n_upper)
            if time_intensive: m = n - 1
            else: m = randint(m_lower, m_upper)

            file.write(f"{n} {m}\n")


def main():
    generate_inputs(
        first_tc_no = 1,
        last_tc_no = 10,
        n_lower = 1,
        n_upper = int(0.8 * N_UPPER),
        m_lower = 1,
        m_upper = int(0.8 * M_UPPER),
    )

    generate_inputs(
        first_tc_no = 11,
        last_tc_no = 20,
        n_lower = int(0.8 * N_UPPER),
        n_upper = N_UPPER,
        m_lower = int(0.8 * M_UPPER),
        m_upper = M_UPPER,
        time_intensive = True
    )


if __name__ == "__main__": main()

