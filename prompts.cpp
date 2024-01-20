#include "Prompts.h"

//ProgramPrompts
const std::string Prompts::InitialPrompt =  "Welcome to the Band-Wide-Reciever\nFollow the onscreen prompts to enter the properties of your Reciever\n\n";
const std::string Prompts::EndPrompt = "\nBand-Wide Reciever shutting down...\nProgram Complete.";

//User Confirmation Prompt (Honestly it was more work to code this than it will be to use it)
const std::string Prompts::EnterToContinue = "\nPress 'Enter' to continue...";

//Error Text
const std::string Prompts::InvalidInEmpty = "Invalid input. Please enter a non-empty string.\n";

//Main Menu Text
const std::string Prompts::MainMenuPrompt = 
    "\nMain Menu"
    "\n1 - Change Station"
    "\n2 - Set Volume"
    "\n3 - Switch Bands (AM/FM)"
    "\n4 - Power (On/Off)"
    "\n5 - Equalizer Settings"
    "\n6 - System Settings"
    "\n7 - Quit Program"
    "\nSelect a menu option: ";
//EQ Menu Text
const std::string Prompts::EQMenuPrompt = 
    "\nEqualizer Menu"
    "\n1 - Bass Level"
    "\n2 - Mid Level"
    "\n3 - Treble Level"
    "\n4 - Cancel"
    "\nSelect a menu option: ";
//Settings Menu Text
const std::string Prompts::SettingsMenuPrompt = 
    "\nSystem Settings"
    "\n1 - Display Device Properties"
    "\n2 - Change Device Nickname"
    "\n3 - Factory Reset"
    "\n4 - Cancel"
    "\nSelect a menu option: ";