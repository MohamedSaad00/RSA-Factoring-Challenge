import sys

def factorize(n):
    # Check if the number is divisible by 2 first
    if n % 2 == 0:
        print(f"{n}={n//2}*2")
        return
    
    # Start checking odd numbers from 3 upwards
    for p in range(3, int(n**0.5) + 1, 2):
        if n % p == 0:
            print(f"{n}={n//p}*{p}")
            return
    
    # If no factors are found, the number is prime or 1*n
    print(f"{n}={n}*1")

def main(filename):
    try:
        with open(filename, 'r') as file:
            for line in file:
                # Remove any trailing spaces/newlines and convert to integer
                n = int(line.strip())
                factorize(n)
    except FileNotFoundError:
        print(f"Error: File {filename} not found")
    except ValueError:
        print("Error: Invalid number in file")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python factors.py <file>")
        sys.exit(1)
    
    main(sys.argv[1])
