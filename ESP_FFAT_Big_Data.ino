#include "Arduino.h"
#include "FFat.h"

String MainString = "";
String ParsedString = "";
int userEmployeeID;
int EndCount = 0;
String TempString;

void setup() {
  Serial.begin(115200);
  Serial.println("Enter number to find ID: ");
}

void loop() {
  if (Serial.available() > 0) {
    int ID = Serial.parseInt();
    FindString(ID);
    //FindDataNum = 0;
  }
}

void FindString(int RequiredID) {
  Serial.println("\nFinding entered ID.....");

  if (!FFat.begin(true)) {
    Serial.println("An Error has occurred while mounting FFat");
    return;
  }

  File file = FFat.open(F("/data750.txt"), "r");
  if (!file) {
    Serial.println("Failed to open file for reading");
    return;
  }
  String NumString;
  int NullIndex;
  int NumInt;
  char inChar;

  while (file.available()) {
    inChar = file.read();
    MainString += inChar;
    if (inChar == '"') {
      inChar = file.read();
      MainString += inChar;
      if (isDigit(inChar)) {
        NumString += inChar;
        inChar = file.read();
        MainString += inChar;
        if (isDigit(inChar)) {
          NumString += inChar;
          inChar = file.read();
          MainString += inChar;
          if (isDigit(inChar)) {
            NumString += inChar;
            inChar = file.read();
            MainString += inChar;
          }
        }
        NumInt = NumString.toInt();
        if (inChar == '"') {
          Serial.print(NumInt);
          Serial.print(", ");
          if (NumInt == RequiredID) {
            Serial.print("\nFound ID number ");
            Serial.print(" : ");
            Serial.println(NumInt);
            NumString = "";
            while (file.available()) {
              inChar = file.read();
              MainString += inChar;
              NullIndex = MainString.indexOf("NULL");
              if (inChar == '}') {
                processString(MainString);
                MainString = "";
                return;
              }

              if (NullIndex > 0) {
                Serial.println("");
                Serial.println("NULL");
                NullIndex = 0;
                MainString = "";
                return;
              }
            }
          }
        }
      }
    }
    MainString = "";
    NumString = "";
  }

  file.close();
  FFat.end();
}

void processString(String NextString) {
  Serial.println("Processing the string...");
  Serial.println("");
  int firstQuote = NextString.indexOf('"');
  int secondQuote = NextString.indexOf('"', firstQuote + 1);

  String ParsedStringNum = "";
  ParsedStringNum = NextString.substring(firstQuote + 1, secondQuote);
  int DataNum =  ParsedStringNum.toInt();

  int FirstColon = NextString.indexOf(':');
  int Comma = NextString.indexOf(',', NextString.indexOf(',') + 1);

  String ID_One = NextString.substring(FirstColon + 4, Comma - 2);
  Serial.print("First ID : ");
  Serial.println(ID_One);

  int SecondColon = NextString.indexOf(':', NextString.indexOf(':') + 1 );
  int EndMark = NextString.lastIndexOf('n');

  String ID_Two = NextString.substring(SecondColon + 4, EndMark + 1);
  Serial.print("Second ID : ");
  Serial.println(ID_One);
  Serial.println("");
}
