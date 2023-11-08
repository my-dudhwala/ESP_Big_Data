# ESP Data Processing Project

This project is designed to process data uploaded to the FATFS of the 16MB ESP board and search for specific IDs within the data. The program searches through a data file, extracts relevant information, and processes it accordingly.

## Process Setup

### Hardware Requirements

- 16MB ESP board
- Serial interface

### Software Requirements

- Arduino IDE
- FFat library

## How to Use

1. Upload the provided code to your 16MB ESP board using the Arduino IDE.
2. Connect the ESP board to the serial interface for input/output.
3. Run the program and input the desired ID to search for within the data.

## Code Explanation

The provided code performs the following tasks:

- Initializes the program and sets up the serial communication.
- Searches for a specific ID within the data file.
- Processes the extracted data and outputs relevant information.

The code includes functions such as `setup()`, `loop()`, `FindString(int RequiredID)`, and `processString(String NextString)`, which are responsible for different aspects of data processing and analysis.

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
