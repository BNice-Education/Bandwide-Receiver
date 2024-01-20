#include "receiver.h"
#include "validation.h"
#include "prompts.h"

#include <iostream>
#include <iomanip>
#include <string>

//Constructor Class
StereoReceiver::StereoReceiver() {
    StereoReceiver::SetProperties();
}

//Function that initializes user-specific device properties
void StereoReceiver::SetProperties(){
    setManufacturer(); setModel(); setSerial(); setWattage(); setChannels(); setName();
    band = false;   //AM by default
    power = true;   //Power ON by default
    frequency = 540;
    volume = bass = mid = treble = 5;
}

//Function to toggle power state
void StereoReceiver::setPower(){
    std::string toggleName = "Power";
    std::string startState, endState;
    if (power == false) {std::string startState = "Off", endState = "On";} else {std::string startState = "On", endState = "Off";}
    power = !power;
}

//User Input Functions (Named for Changed Property/Setting)
void StereoReceiver::setManufacturer(){
    std::string prompt = "Enter the Manufacturer of your receiver: ";
    manufacturer = ValidateStringDef(prompt); 
} 
void StereoReceiver::setModel(){
    std::string prompt = "Enter the Model Name of your receiver: ";
    model = ValidateStringDef(prompt); 
} 
void StereoReceiver::setName(){
    std::string prompt = "Enter a nickname for your device: ";
    name = ValidateStringDef(prompt); 
}
void StereoReceiver::setSerial(){
    std::string prompt = "Enter the Serial Number for your receiver: ";
    serial = ValidateStringDef(prompt);   //string, as serial numbers are commonly made up of a combination of alphanumeric characters
}
void StereoReceiver::setWattage(){
    std::string prompt = "Enter the Wattage on your Receiver: ";
    wattage = ValidateDoubleDef(prompt, 1, 250);   //Relatively reasonable wattage range
}
void StereoReceiver::setChannels(){
    std::string prompt = "Enter the number of channels: "; 
    channels = ValidateIntDef(prompt, 0, 20);
}
void StereoReceiver::setFrequency() {
    if (band == false) { // Check Band to Determine Appropriate Frequency Range
        std::string prompt = "Currently your Receiver is set to AM (selectable range 540-1700 kHz)\nSet a Frequency for your Receiver: ";
        frequency = ValidateDoubleDef(prompt, 540, 1700);   //AM Frequency Range
    } else {       
        std::string prompt = "Currently your Receiver is set to FM (selectable range 80.1-108.1 MHz)\nSet a Frequency for your Receiver: ";        
        frequency = ValidateDoubleDef(prompt, 88.1, 108.1); //FM Frequency Range
    }
}
void StereoReceiver::setVolume(){
    std::string prompt = "Set a volume level between 0 and 10: "; 
    volume = ValidateIntDef(prompt, 0, 10);
}
void StereoReceiver::setBass(){
    std::string prompt = "Set a bass equalizer level between 1 and 10: "; 
    bass = ValidateIntDef(prompt, 1, 10);
}
void StereoReceiver::setMid(){
    std::string prompt = "Set a mid equalizer level between 1 and 10: "; 
    mid = ValidateIntDef(prompt, 1, 10);
}
void StereoReceiver::setTreble(){
    std::string prompt = "Set a treble equalizer level between 1 and 10: "; 
    treble = ValidateIntDef(prompt, 1, 10);
}

void StereoReceiver::setBand(){
    std::string toggleName = "AM/FM Band";
    std::string startState, endState;
    if (band == false) {startState = "AM", endState = "FM"; frequency = 88.1;} else {startState = "FM", endState = "AM"; frequency = 540; }
    band = !band;
    BoolToggleOut(toggleName, startState, endState);
    std::cout << "\nFrequency has defaulted to " << frequency << std::endl;
}


// Funcion to Display Properties
void StereoReceiver::DisplayProperties() {
    int colWidth = 18;
    std::cout << "\nYour Stereo Receiver Details\n";
    // Header
    std::cout << std::left << std::setw(colWidth) << "Property";
    std::cout << std::setw(colWidth) << "Manufacturer";
    std::cout << std::setw(colWidth) << "Model #";
    std::cout << std::setw(colWidth) << "Serial #";
    std::cout << std::setw(colWidth) << "Wattage";
    std::cout << std::setw(colWidth) << "Channels";
    std::cout << std::setw(colWidth) << "Device Name" << std::endl;
    // Values
    std::cout << std::left << std::setw(colWidth) << "Value";
    std::cout << std::setw(colWidth) << manufacturer;
    std::cout << std::setw(colWidth) << model;
    std::cout << std::setw(colWidth) << serial;
    std::cout << std::setw(colWidth) << wattage;
    std::cout << std::setw(colWidth) << channels;
    std::cout << std::setw(colWidth) << name << std::endl;
    
}


//Function to Display Audio and Frequency Settings (if Power is Turned On)
void StereoReceiver::DisplaySettings() {
    int colWidth = 15; 
    std::string bandStr; 
    if (band == false) {bandStr = "AM";} else {bandStr = "FM";} 
    if (power == true) {
            std::cout <<"\n" + name +" is currently powered on with the following settings..\n";
    // Header
    std::cout << std::left << std::setw(colWidth) << "Setting";
    std::cout << std::setw(colWidth) << "Band";
    std::cout << std::setw(colWidth) << "Frequency";
    std::cout << std::setw(colWidth) << "Volume";
    std::cout << std::setw(colWidth) << "Bass";
    std::cout << std::setw(colWidth) << "Mid";
    std::cout << std::setw(colWidth) << "Treble" << std::endl;
    // Values
    std::cout << std::left << std::setw(colWidth) << "Value";
    std::cout << std::setw(colWidth) << bandStr;
    std::cout << std::setw(colWidth) << frequency;
    std::cout << std::setw(colWidth) << volume;
    std::cout << std::setw(colWidth) << bass;
    std::cout << std::setw(colWidth) << mid;
    std::cout << std::setw(colWidth) << treble << std::endl;
    } else {std::cout <<"\n" + name +" is currently powered Off.\n";}
}

//Function to bring up EQ Menu
void StereoReceiver::EQSettings() {
        int menuOption = UserMenuSelection(Prompts::EQMenuPrompt,1,4);
        switch (menuOption){
            case 1:
                setBass();
                break;
            case 2:
                setMid();
                break;
            case 3:
                setTreble();
                break;
            default:
                break;
        }
}

//Function to Bring up System Settings Menu
void StereoReceiver::SysSettings() {
        int menuOption = UserMenuSelection(Prompts::SettingsMenuPrompt,1,4);
        switch (menuOption){
            case 1:
                DisplayProperties();
                break;
            case 2:
                setName();
                break;
            case 3:
                std::cout << "\n...\nSystem Reset Complete.\n" << Prompts::InitialPrompt<< std::endl;
                StereoReceiver();
                break;
            default:
                break;
        }
}