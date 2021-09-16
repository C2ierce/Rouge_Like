#pragma once
#include <iostream>
#include <deque>

class DialogueBox
{
public:
	DialogueBox();
	~DialogueBox();

	std::string calculateSpacing(std::string getSpacing);
	bool checkSize(std::deque<std::string> checkDia);
	void addDialogue(std::string text);
	int getDialogueSize();
	int getDialogueElementOneSize() { return dialogue[0].size(); }
	void resetDialogue(void);
	bool popBack = true;
	bool repeatedText = false;
	bool switchText = false;
	bool firstText = true;
	bool delimitter = false;
	std::string lastText = "*";
	std::string lastRepeatedText = "*";
	std::string lastWrappedText = "*";
	std::string getDialogue(int dialogueIndex);
	std::string lastWords = "";
	std::deque<std::string> dialogue{ "|Welcome, to DungenTales.        |" };
	int repeatTextCount = 1;
	int dialogueBoxSize = 33;
	int longText = 0;
private:
	int listCount = 0;
};

