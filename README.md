# ESP Data Processing Project

This project is designed to process data uploaded to the FATFS of the 16MB ESP board and search for specific IDs within the data. The program searches through a data file, extracts relevant information, and processes it accordingly.

In details, this method involves storing a sizable 3MB data on Flash, enabling the processing and parsing of each character and string. The termination of each string occurs upon the appearance of a curly bracket. Notably, each string consists of three parts, including two sections of random data and one part denoting the string number. This approach has proven effective for an attendance system, accommodating the pairing of two fingerprints with a single individual, where the numerical value signifies their unique ID. Moreover, the use of additional separators like commas and colons offers flexibility for handling various data types, such as sensor readings. In this context, the system accommodates 750 distinct IDs, with each ID occupying an approximate space of 4KB.

## Process Setup

### Hardware Requirements

- 16MB ESP board
- Serial interface

### Software Requirements

- Arduino IDE (**Lagacy version must,** The Arduino IDE 2.0 will not work, 2.0 Doesn't supports any file upload tool)
- FFat library

## How to Use

1. **Upload the provided code** to your 16MB ESP board using the Arduino IDE.
2. Place the `esp32fs.jar` file in the following path on your machine: `C:\Users\LC-124-145\Documents\Arduino\tools\ESP32FS\tool`.
3. Store the `data750.txt` file in this directory on your machine: `C:\Users\LC-124-145\Documents\Arduino\YourCode\data`.
4. Place the `mkfatfs.exe` file in the following path on your machine: `C:\Users\LC-124-145[Your Machine name]\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.13[Your ESP32 core version]\tools`.
5. **Restart the Arduino IDE**, go to `tools`, and select the new option named **ESP32 sketch data upload**. Choose `fatfs` from the popup menu.
6. **Run the ESP32**, open the serial monitor, and input the required ID. Your testing phase completes after this step.


## Code Explanation

The provided code performs the following tasks:

- Initializes the program and sets up the serial communication.
- Searches for a specific ID within the data file.
- Processes the extracted data and outputs relevant information.

The code includes functions such as `setup()`, `loop()`, `FindString(int RequiredID)`, and `processString(String NextString)`, which are responsible for different aspects of data processing and analysis.

### Detailed code explaination  
This ESP32 code is designed to read a text file and parse specific data based on user input. The program reads the contents of a file named "data750.txt" stored in the FFat file system. It searches for a specific ID provided by the user and then processes the relevant data associated with that ID.

Here is a brief overview of the code:

1. The script initializes required variables and sets up the serial communication.

2. The `loop()` function continuously checks for any available data from the serial input. If data is available, it calls the `FindString` function to search for the entered ID.

3. The `FindString` function reads the content of the "data750.txt" file, identifies the required ID, and then processes the associated data. It makes use of various string manipulation functions to extract the required information.

4. The FindString function scans for numbers enclosed within two inverted commas like ```"526"```. If the number entered via the serial input matches the number in the file, the function proceeds to read the data until it encounters an ending curly bracket ```}```. Subsequently, it stores the string starting from the identified number up to the closing curly bracket and passes this string to the processString function.

5. The processString function is responsible for parsing Data1 and Data2 from the provided string and displays them on the Serial monitor. You can manipulate the data as required, performing tasks beyond the scope of mere display.

## File Description

The data file (`data750.txt`) should be stored in the FATFS of the ESP board. Ensure that the file is properly formatted to guarantee the correct functioning of the program.  

### Data foamat  

The data format is as given below,  
```
"1",{"ID_one" : "Data1", "ID_two" : "Data2"}  
"2",{"ID_one" : "Data3", "ID_two" : "Data4"}  
"3",{"ID_one" : "Data5", "ID_two" : "Data6"}
```

## Important Notes

- This program is designed for 16MB ESP boards and utilizes the FFat library for file handling.
- Ensure that the hardware and software requirements are met before running the program.
- Follow the provided instructions for a successful data search and processing.

## Author

[Mohammed Yasar Dudhwala]
