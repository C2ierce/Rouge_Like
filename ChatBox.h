#pragma once
#include <iostream>
#include <vector>

class ChatBox
{
public:
	ChatBox();
	~ChatBox();
	std::vector<std::string> dialogue;
	int getDialogueSize();
	std::string getDialogue(int dialogueIndex);
	std::string getDialogue();
	void addDialogue(std::string text);
	void resetDialogue();
	std::vector<std::string> calculateSpacing(std::string getSpacing);
	int count = 1;
	int dialogueBoxSize = 32;
	int splitTextTotal = 1;
	std::string prevDia;
	std::string lastText = "*";
	std::string lastRepeatedText = "*";
	std::string lastWrappedText = "*";
	int repeatTextCount = 0;
	bool repeatedText = false;
	bool repeat = false;
};


