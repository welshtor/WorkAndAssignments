import json
import os, sys

# with open('ResourceID.txt','w') as outfile:
#     json.dump(data,outfile,indent=2)

# List all of the Files and types in a path
path = ""
dirs = os.listdir(path)

for file in dirs:
    print(file)
