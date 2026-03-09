import random

def p_a(sample, N, age):
    appearences = [ages == age for ages in sample]
    p_a = sum(appearences) / N
    return p_a

def model_based(sample, N):
    s = 0
    ages_visited = []
    for age in sample:
        if age not in ages_visited:
            s += p_a(sample, N, age) * age
            ages_visited.append(age)
    return s

def model_free(sample, N):
    s = 0
    for age in sample:
        s += age
    return s/N

def main():
    N = 50
    sample = []
    for n in range(N):
        sample.append(random.randint(15, 30))

    print("Model Based Expected Age: ", model_based(sample, N))
    print()
    print("Model Free Expected Age: ", model_free(sample, N))

if __name__ == '__main__':
    main()
