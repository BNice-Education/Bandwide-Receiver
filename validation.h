#ifndef VALIDATION_H
#define VALIDATION_H

#include "prompts.h"
#include <string>

void QuickClear();
std::string ValidateStringDef(const std::string& prompt);
double ValidateDoubleDef(const std::string& prompt, double minOption, double maxOption);
int ValidateIntDef(const std::string& prompt, int minOption, int maxOption);
void BoolToggleOut(std::string toggleName, std::string startVal, std::string endVal);
int UserMenuSelection(const std::string& menuText, int minOption, int maxOption);
void UserConfirm();

#endif // VALIDATION_H
