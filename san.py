import os

def replace_in_cpp_file():
    changes = [
        ('[', '{'),
        (']', '}'),
        ('\"', '\'')
    ]
    parents = ["easy", "medium", "hard"]
    folder_num = input("Enter the folder number: ")
    target_path = os.path.join(folder_num, "x.cpp")
    for parent in parents:
        potential_path = os.path.join(parent, folder_num, "x.cpp")
        print(potential_path)
        if os.path.exists(potential_path):
            target_path = potential_path
            print(f"Located file at: {target_path}")
            break
    if not target_path:
        print(f"Error: Folder '{folder_num}' not found.")
        return

    try:
        with open(target_path, 'r') as file:
            lines = file.readlines()
        with open(target_path, 'w') as file:
            for line in lines:
                if "tokens.push_back" in line:
                    for (search, rep) in changes:
                            line = line.replace(search, rep)
                file.write(line)
        
        print(f"Successfully updated {target_path}")

    except Exception as e:
        print(f"An unexpected error occurred: {e}")

if __name__ == "__main__":
    replace_in_cpp_file()