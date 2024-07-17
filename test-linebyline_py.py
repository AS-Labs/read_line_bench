import os

def main():
    try:
        with open("data.txt", "r") as file:
            line_count = 0
            byte_count = 0

            for line in file:
                line_count += 1
                byte_count += len(line)

            print(f"{line_count} lines, {byte_count} bytes")

    except OSError as e:
        print(f"Error opening file: {e}")

if __name__ == "__main__":
    main()

