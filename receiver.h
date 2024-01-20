#ifndef RECEIVER_H
#define RECEIVER_H
#include <string>

class StereoReceiver {
    public:
    StereoReceiver();
    void setSerial();
    void setManufacturer();
    void setModel();
    void setName();
    void setChannels();
    void setPower();
    void setWattage();
    void setFrequency();
    void setVolume();
    void setBass();
    void setMid();
    void setTreble();
    void setBand();
    void DisplaySettings();
    void DisplayProperties();
    void SetProperties();
    void EQSettings();
    void SysSettings();
    private:
    std::string manufacturer; 
    std::string model; 
    std::string name;
    std::string serial;
    int channels;
    int volume;
    int bass;
    int mid;
    int treble;
    double wattage;
    double frequency;
    bool band; 
    bool power;
} ;

#endif