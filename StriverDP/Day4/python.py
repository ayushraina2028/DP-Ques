# Python script to convert space-separated integers to comma-separated integers

def main():
    # Read a line of space-separated integers from the terminal
    input_line = input("Enter space-separated integers: ")
    
    # Split the input line into individual string numbers
    number_strings = input_line.split()
    
    # Convert the strings to integers
    numbers = [int(num) for num in number_strings]
    
    # Join the integers with commas and print the result
    output = ','.join(map(str, numbers))
    print(output)

if __name__ == "__main__":
    main()
