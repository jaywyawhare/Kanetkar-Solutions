# Path: utils/folderCreation.py
import os

for i in range(1, 23):
    os.mkdir(f"./Chapter-{str(i).zfill(2)}")
