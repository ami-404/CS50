while True:
    try:
        height = int(input("Enter the height(0-8): "))
        if 1 <= height <= 8:
            break
    except  ValueError:
        pass

k = 1

for i in range(height):
    for j in range(height - k):
        print(" ", end="")

    for j in range(k):
        print("#", end="")

    print("  ", end="")

    for j in range(k):
        print("#", end="")

    print("")
    k += 1
