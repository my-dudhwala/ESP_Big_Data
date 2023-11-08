import random
import string

def generate_random_string(length):
    letters = string.ascii_letters
    return ''.join(random.choice(letters) for _ in range(length))

def generate_data_file(file_name, num_entries):
    with open(file_name, 'w') as file:
        for i in range(1, num_entries + 1):
            id_one = generate_random_string(2120)
            id_two = generate_random_string(2120)
            line = f'"{i}",{{"ID_one" : "{id_one}", "ID_two" : "{id_two}"}}\n'
            file.write(line)

if __name__ == "__main__":
    file_name = "data750.txt"  # Change the file name as needed
    num_entries = 750  # Change the number of entries as needed
    generate_data_file(file_name, num_entries)
    print(f"Random string data file '{file_name}' generated successfully.")
