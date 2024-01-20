// # Program name: bandwidereceiver.cpp v1.05
// # Author: Bruce Nebergall
// # Date last updated: 1/20/2024
// # Purpose: To collect properties of a stereo receiver, and allow the user to change values for stereo receiver controls

#include "receiver.h"
#include "validation.h"
#include "prompts.h"

#include <iostream>
#include <string>

int main(){   
    std::cout << Prompts::InitialPrompt; 
    StereoReceiver activeReceiver;          //Constructor Class prompts users for device properties
    activeReceiver.DisplayProperties();     //Device PROPERTIES are Displayed to User
    while (true) {
        activeReceiver.DisplaySettings();   //Receiver SETTINGS are Displayed at the beginning of each iteration of the main loop
        int menuOption = UserMenuSelection(Prompts::MainMenuPrompt,1,7);
        switch (menuOption){                //Switch Case on User Input at Main Menu
            case 1://Change Station
                activeReceiver.setFrequency();
                break;
            case 2://Set Volume
                activeReceiver.setVolume();
                break;
            case 3://Change Band
                activeReceiver.setBand();
                break;
            case 4://Power Off/ON
                activeReceiver.setPower();
                break;
            case 5://EQ Menu (Edit Bass, Mid, Treble)
                activeReceiver.EQSettings();
                break;
            case 6://System Menu (View/Reset Properties, Change Nickname)
                activeReceiver.SysSettings();
                break;
            case 7://End Program
            std::cout << Prompts::EndPrompt;
            UserConfirm();
            return 0;
            default:
                break;
        }
    }
    return 1;
}



