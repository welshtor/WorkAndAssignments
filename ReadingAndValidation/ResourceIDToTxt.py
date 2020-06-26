import json
import os





path_dict = { "IN HERE ADD the file names, and folder names you're expecting in your search as key and values"
              }


# Path to the Folder You Want to read through
folder_path = ""

# Folder Path Line By Line
root_read_folder = os.listdir(folder_path)

# Optional to turn this into a function, I never got around to it.
def Json_To_TxtFile(file, parent_org):
    pass


# For creating a text File by reading information from folders within a directory, nested for loops for reading of each file within in sub folder
# Add or Remove FOR loops depending on amount of nested folders
# Function: Reads information out of a json file and formats them to a text file.
with open('SarahResourceID V7.txt', 'w') as outfile:
    for folder in root_read_folder:
        # exclude file types for search
        if ".py" or ".txt" not in folder:
            organizations = os.listdir(folder_path + "\\" + folder )

            for folders in organizations:
                resource_types_fldr = os.listdir(folder_path + "\\" + folder + "\\" + folders)

                for file in resource_types_fldr:
                    #Json_To_TxtFile(file, folders)
                    json_dict = open(folder_path + "\\" + folder + "\\" + folders + "\\" + file, 'r', encoding='utf8').read()

                    try:
                        if ".json" in file:
                            json_dict = json.loads(json_dict)
                            #outfile.write(str(parent_org) + " " + json_dict['resourceType'] + " " + json_dict['id'])
                            outfile.write(path_dict[folder] + " " + json_dict['resourceType'] + " " + json_dict['id'])
                            outfile.write('\n')
                    except Exception as e:
                        print("Invalid Jason File,  Filename:  ", file, e)