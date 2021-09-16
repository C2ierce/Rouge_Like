#include "DialogueBox.h"
#include <algorithm>
#include <sstream>
#include <vector>

DialogueBox::DialogueBox()
{
	//dialogue.resize(11);
}

DialogueBox::~DialogueBox()
{

}

void DialogueBox::addDialogue(std::string eText)
{
	std::string text = "|";
	text += eText;
	int textSize = text.size();
	std::string addedSpace = "";
	std::string repeatAddedSpace = "";
	std::string splitText = "|";
	std::string newText = "";
	int newTextSize = 0;
	int splitTextSize = 0;
	int testCount = 0;
	std::vector<std::string> multipleSplitText;
	multipleSplitText.resize(1);
	multipleSplitText[0] = "|";

	if (textSize <= dialogueBoxSize || text.size() <= dialogueBoxSize)
	{
		if (text.find(lastText) != std::string::npos)
		{
			dialogue.push_front(calculateSpacing(text));
			checkSize(dialogue);
		}
		else
		{
			dialogue.push_front(calculateSpacing(text));
			checkSize(dialogue);
			lastText = text;
		}
	}

	if (textSize >= dialogueBoxSize)
	{
		//If this code block is used before the normal one
		//if sizeText is 35 then take the last character and remove it from text and put it in splitText, push both with the right spacing
		for (int i = 0; i < text.size(); i++)
		{
			if (i >= dialogueBoxSize - 6 && text[i] == ' ')
			{
				delimitter = true;
			}
			
			if (delimitter)
			{
				multipleSplitText[longText] += text[i];
				if (multipleSplitText[longText].size() >= dialogueBoxSize - 6 && text[i] == ' ')
				{
					longText++;
					multipleSplitText.resize(longText+1);
					multipleSplitText[longText] += "|";
				}
			}
			else if (delimitter == false)
			{
				newText += text[i];
			}
		}
		for (int i = 0; i < multipleSplitText.size(); i++)
		{
			std::string extra = "";
			extra = multipleSplitText[i];
			multipleSplitText[i] = multipleSplitText[multipleSplitText.size()-1];
			multipleSplitText[multipleSplitText.size() - 1] = extra;
			
			multipleSplitText[i] = calculateSpacing(multipleSplitText[i]);
			dialogue.push_front(multipleSplitText[i]);
			checkSize(dialogue);
			checkSize(dialogue);
		}
		newText = calculateSpacing(newText);
		dialogue.push_front(newText);
		delimitter = false;
		lastText = multipleSplitText[longText];
		longText = 0;
		lastWrappedText = newText;
	}
	while (dialogue.size() > 10 && repeatedText == false)
	{
		dialogue.pop_back();
	}
}

std::string DialogueBox::calculateSpacing(std::string getSpacing)
{
	std::ostringstream repeatTextCountString;
	std::string repeatAddedSpace = "";
	std::string addedSpace = "";

	if(lastText.find(getSpacing) != std::string::npos || lastWrappedText.find(getSpacing) != std::string::npos)
	{
		if (lastText.find(getSpacing) != std::string::npos)
		{
			repeatTextCount++;
			repeatTextCountString << repeatTextCount;
			repeatAddedSpace = " x" + repeatTextCountString.str();
			repeatedText = true;
		}
	}
	else
	{
		repeatTextCount = 1;
		repeatedText = false;
	}
	addedSpace += std::string((dialogueBoxSize - getSpacing.size()) - (repeatAddedSpace.size()), ' ') + "|";
	repeatAddedSpace += addedSpace;
	getSpacing += repeatAddedSpace;
	return getSpacing;
}

bool DialogueBox::checkSize(std::deque<std::string> checkDia)
{
	if (dialogue[0].find(lastWrappedText) != std::string::npos)
	{
		dialogue.pop_front();
		dialogue.pop_front();
	}
	if (repeatedText == true)
	{
		if (dialogue.size() > 2)
		{
			//[2]Northx1, [1]Eastx1, [0]Eastx2,  
			for (int i = 0; i < dialogue.size(); i++)
			{
				if (dialogue[dialogue.size() - 1].empty())
				{
					break;
				}
				dialogue[i + 1] = dialogue[i + 2]; //changed from dialogue[i+1] = checkDia[i+2];
				dialogue[i + 2].erase();
				dialogue[i + 2].resize(0);
			}
			dialogue.resize(dialogue.size() - 1);

			return true;
		}
		else if (dialogue.size() >= 2)
		{
			dialogue.pop_back();
			return true;
		}
	}
	else if (repeatedText == false)
	{
		return true;
	}
	return false;
}

int DialogueBox::getDialogueSize(void)
{
	return dialogue.size();
}

std::string DialogueBox::getDialogue(int dialogueIndex)
{
	return dialogue.at(dialogueIndex);
}

void DialogueBox::resetDialogue(void)
{
	dialogue.resize(12);
}
