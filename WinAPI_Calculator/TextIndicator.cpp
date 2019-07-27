#pragma once
#include "TextIndicator.h"

bool TextIndicator::outputFlag = false;

string TextIndicator::inputStr = "";
string TextIndicator::outputStr = "";

RECT TextIndicator::inputTextRange = { 
	left,
	top - 10,
	right - 20, 
	bottom 
};

RECT TextIndicator::outputTextRange = { 
	left, 
	top + 10,
	right - 20, 
	bottom + 30 
};