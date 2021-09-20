#include "ChatBox.h"
#include <algorithm>
#include <sstream>
#include <vector>

ChatBox::ChatBox()
{
	
}

ChatBox::~ChatBox()
{

}

int ChatBox::getDialogueSize()
{
	return dialogue.size();
}

std::string ChatBox::getDialogue(int dialogueIndex)
{
	return dialogue[dialogue.size()-(dialogueIndex+1)];
}

std::string ChatBox::getDialogue()
{
	std::string mDialogue = "";
	for (int i = 0; i < dialogue.size(); i++)
	{
		mDialogue += dialogue[dialogue.size() - (i + 1)] + "\n";
	}
	return mDialogue;
}

void ChatBox::addDialogue(std::string text)
{
	std::vector<std::string> formattedTxt = calculateSpacing(text);
	int count = 1;
	if (repeatedText && splitTextTotal <= 2)
	{
		for (int i = 0; i < formattedTxt.size(); i++)
		{
			dialogue.at(dialogue.size() - count) = formattedTxt[i];
			count++;
		}
	}
	else if (repeatedText && splitTextTotal > 2)
	{
		for (int i = 0; i < formattedTxt.size(); i++)
		{
			dialogue.at(dialogue.size() - count) = formattedTxt[i];
			count++;
		}
	}
	else 
	{
		if (splitTextTotal >= 2)
		{
			count = formattedTxt.size();
			for (int i = 0; i < formattedTxt.size(); i++)
			{
				count--;
				dialogue.push_back(formattedTxt[count]);
			}
		}
		else
		{
			dialogue.push_back(formattedTxt[0]);
		}
	}

	while (dialogue.size() > 11)
	{
		dialogue.erase(dialogue.begin());
		//dialogue.erase(std::next(dialogue.begin(), 0), std::next(dialogue.begin(), 2));
	}
}

void ChatBox::resetDialogue(void)
{
	dialogue.resize(12);
}

std::vector<std::string> ChatBox::calculateSpacing(std::string newTxt)
{
	std::ostringstream repeatTextCountString;
	std::string repeatAddedSpace = "";
	std::string addedSpace = "";
	std::string rtnTxt = "|";
	std::string rtnTxtComp;
	std::vector<std::string> splitText;

	int splitTextCount = 0;
	splitTextTotal = 1;

	int splitTextCountS = 0;
	int splitTextTotalS = 1;

	rtnTxt += newTxt;
	
	for (int i = 0; i < newTxt.size(); i++)
	{
		splitTextCount++;
		if (splitTextCount > dialogueBoxSize)
		{
			splitTextCount = 0;
			splitTextTotal++;
		}
	}

	splitText.resize(splitTextTotal);

	splitTextTotalS = 0;
	for (int i = 0; i < splitTextTotal; i++)
	{
		splitText[i] += "|";
	}
	for (int i = 0; i < newTxt.size(); i++)
	{
		splitText[splitTextTotalS] += newTxt[i];
		splitTextCountS++;
		if (splitTextCountS > dialogueBoxSize)
		{
			splitTextCountS = 0;
			splitTextTotalS++;
		}
	}

	if (!(prevDia.find(newTxt) != std::string::npos)) //Making sure the newTxt is fresh & not to be incremented
	{
		if (splitTextTotal < 2) //Scope for first time singe line
		{
			splitText[0] += std::string((dialogueBoxSize - newTxt.size()), ' ') + "|";
		}
		repeatTextCount = 1;
		repeatedText = false;
	}
	else //Increment the request 
	{
		if (splitTextTotal < 2)
		{
			//One Line Repeat
			repeatTextCount++;
			repeatTextCountString << repeatTextCount;
			repeatAddedSpace = " x" + repeatTextCountString.str();
			rtnTxt += repeatAddedSpace;
			rtnTxt += std::string((dialogueBoxSize - newTxt.size() - repeatAddedSpace.size()), ' ') + "|";
			splitText[splitText.size() - splitTextTotal] = rtnTxt;
		}
		else if (splitTextTotal >= 2)
		{
			//Multi Line Repeat
			repeatTextCount++;
			repeatTextCountString << repeatTextCount;
			repeatAddedSpace = " x" + repeatTextCountString.str();
			for (int i = 0; i < splitTextTotal; i++)
			{
				if (i == (splitTextTotal - 1))
				{
					splitText[i] += repeatAddedSpace;
				}
				int noSpacesRemove = splitText[i].size() - repeatAddedSpace.size();
				if (noSpacesRemove > dialogueBoxSize)
				{
					noSpacesRemove = dialogueBoxSize;
				}
				splitText[i] += std::string(noSpacesRemove, ' ') + "|";
			}
		}
		repeatedText = true;
	}

	if (splitTextTotal >= 2 && repeatedText == false)
	{
		int count = splitText.size();

		for (int i = 0; i < splitTextTotal; i++)
		{
			if (i == (splitTextTotal - 1))
			{
				splitText[i] += repeatAddedSpace;
			}
			int noSpacesRemove = splitText[i].size() - repeatAddedSpace.size();
			if (noSpacesRemove > dialogueBoxSize)
			{
				noSpacesRemove = dialogueBoxSize;
			}
			splitText[i] += std::string(noSpacesRemove, ' ') + "|";
		}

		for (int i = 0; i < splitTextTotal; i++)
		{
			std::string temp = "";
			temp = splitText[count-1]; //0+1, 1+1 etc.
			splitText[count-1] = splitText[i];
			splitText[i] = temp;
			count--;
		}
		prevDia = newTxt;
	}
	else
	{
		prevDia = newTxt;
	}
	return splitText;
}