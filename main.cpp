#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>
#include <vector>
#include <algorithm> 
#include <bits/stdc++.h>
#include <Windows.h>
using namespace std;


void gotoXY(int x, int y) 	//function to decide location of the screem
{
	//A "handle" is a generic identifier (typically a pointer) used to represent something
	//Retrieves a handle to the specified standard device (standard input, standard output).
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); 		 
	COORD CursorPosition; 
	CursorPosition.X = x; // Locates column
	CursorPosition.Y = y; // Locates Row
	//Sets the cursor position in the specified console screen buffer.
	//A COORD structure that specifies the new cursor position, in characters. The coordinates are 
	//the column and row of a screen buffer character cell. The coordinates must be within the 
	//boundaries of the console screen buffer.
	SetConsoleCursorPosition(console,CursorPosition); // Sets position for next thing to be printed 
}


void mainMenu () //Display Main Menu
{
		gotoXY(50,12);
    cout << "=====Select Following Option=====\n\n";
		gotoXY(50,15);
    cout << "    [1] Start Game\n";
		gotoXY(50,16);
    cout << "    [2] Quit Game\n";
		gotoXY(47,19);
		cout << "  Select: ";
}
	

void subjectMenu () // Display Subject Menu
{   
		gotoXY(50,5);
    cout << "[1] English\n";
		gotoXY(50,6);
    cout << "[2] Introduction to Programming\n";
		gotoXY(50,7);
		cout << "[3] Back to Menu";
		gotoXY(47,9);
    cout << "Select: ";
}


 int resultScreen(string inputtedUserName, int score)
 {	
		cout << "Name ====>" << inputtedUserName << "\n";
		cout << "Total Score ====> " << "10\n";
		cout << "Your Score ====> " << score;
 }

//What this function does is ask the user to continue or not before proceeding answering the quiz
int subAskBeforeBegin(string inputtedUserName)
{
	//Asking user if he/she want to continue the quiz
	cout<< "Are you ready to start the quiz, " << inputtedUserName << "? (Y/N)\n";
	cout << "\n";
	string inputtedUserResponse{ };
	cin >> inputtedUserResponse;

	//What this does is get the user input then conver it on lowercase
	for (int i=0;i<inputtedUserResponse.length();i++) // Get the input of the string using length() function
		{ 
      inputtedUserResponse[i]=tolower(inputtedUserResponse[i]); //converting every character into lower case
    }
	
	if (inputtedUserResponse == "y") {
        cout << "\n";
        cout << "Good luck!\n";
        cout << "\n";
        cout << "Press enter to continue.";
        cin.get();
        cin.ignore();
				system("cls");
    }else{
        cout << "\n";
        cout << "Goodbye!\n";
        cin.ignore();
        cin.get();
        exit(0);
				system("cls");
    }//Else, quiz ends.
}


//This subject is English
int englishQuiz(string inputtedUserName)
{
		//calling this function before the quiz begin
		subAskBeforeBegin(inputtedUserName);

    //A string full of question and their options
   string
		question01 = "\nThis is a part of speech that shows the relationship of a noun or pronoun to another word. They can indicate time, place, or relationship.\n"
		 " a) noun\n"
		 " b) pronoun\n"
		 " c) adjective\n"
		 " d) preposition\n\n",
		question02 = "\nWhich word indicates correct spelling?\n"
		 " a) belive\n"
		 " b) believe \n"
		 " c) bilieve\n"
		 " d) beleive\n\n",
		question03 = "\n'The wind whisper to the trees as it creeps in the night' this is an example of what figure of speech?\n" 
		" a) smile\n" 
		" b) personification\n" 
		" c) metaphor\n" 
		" d) hyperbole\n\n",
    question04 = "\nThis is en element of poetry that pertain to the series of lines grouped together and separated by an empty line from other stanzas. They are the equivalent of a paragraph in an essay.\n"
		 " a) rhyme\n"
		 " b) stanza\n"
		 " c) form\n"
		 " d) meter\n\n",
		question05 = "\nA kind of sentence that makes a statement\n"
		" a) declarative\n" 
		" b) interrogative\n" 
		" c) imperative\n" 
		" d) exclamatory\n\n",
		question06 = "\nThis pertains to the prosodic feature of speech that is the relative emphasis or prominence given to a certain syllable in a word, or to a certain word in a phrase or sentence\n" 
		" a) pause\n" 
		" b) stress\n" 
		" c) intonation\n" 
		" d) pitch\n\n",
    question07 = "\nthe most important element of a story; they were the ones who play certain roles and acts in the story itself.\n" 
		" a) plot\n" 
		" b) settings\n" 
		" c) characters\n" 
		" d) theme\n\n",
    question08 = "\nWhat _______ when I called?\n"
		 " a) Was you doing\n"
		 " b) Was you do\n"
		 " c) Were you doing\n"
		 " d) You were doing\n\n",
		question09 = "\nWhat is the study of languages?\n"
		" a) Phonetics\n" 
		" b) Syntax\n" 
		" c) Linguistics\n" 
		" d) Semantics\n\n",
		question10 = "\nPhonetics is the study of the sounds of language. What do we call these sounds?\n" 
		" a) Morphemes\n" 
		" b) Syntax\n" 
		" c) Lexicology\n" 
		" d) Phonemes\n\n",
    question11 = "\nA word opposite in meaning to another?\n"
		 " a) synonym\n"
		 " b) antonym\n"
		 " c) contranym\n"
		 " d) preposition\n\n",
		question12 = "\nA pair or group of words that usually go together (e.g. fish and chips)\n"
		 " a) collocation\n"
		 " b) idiom \n"
		 " c) conjunction\n"
		 " d) metaphor\n\n",
		question13 = "\nA group of words that includes a subject and a finite verb.\n" 
		" a) clauses\n" 
		" b) phrasal verb\n" 
		" c) noun phrase\n" 
		" d) predicate\n\n",
    question14 = "\nA verb that has a subject but no object.\n"
		 " a) transitive verb\n"
		 " b) intransitive verb\n"
		 " c) reflexive verb\n"
		 " d) Meme verb\n\n",
		question15 = "\nVerb form in which the action is done to the subject rather than the object.\n"
		" a) active voice\n" 
		" b) passive voice\n" 
		" c) reflective voice\n" 
		" d) Yo mama voice\n\n",
		question16 = "\nA short phrase added to a statement to make it a question.\n" 
		" a) question phrase\n" 
		" b) question tag\n" 
		" c) question mark\n" 
		" d) question\n\n",
    question17 = "\nVery informal words and expressions that are more common in spoken language, especially used by a particular group o f people, e.g., teenagers. They often go in and out of fashion very quickly. They can sometimes cause offense.\n" 
		" a) slang\n" 
		" b) metaphor\n" 
		" c) synonym\n" 
		" d) smile\n\n",
    question18 = "\nWords and phrases used in conversation or writing to friends but not in formal speech or writing.\n"
		 " a) collocation\n"
		 " b) slang\n"
		 " c) colloquial\n"
		 " d) smile\n\n",
		question19 = "\nGROW UP is......\n"
		" a) phrasal verb\n" 
		" b) metaphor\n" 
		" c) idiom\n" 
		" d) slang\n\n",
		question20 = "\nIt's raining cats and dogs , is a example of...\n" 
		" a) sland\n" 
		" b) idiom\n" 
		" c) callocation\n" 
		" d) metaphor\n\n";


    vector <string> englishSubQuestions;
		englishSubQuestions.push_back(question01);
		englishSubQuestions.push_back(question02);
		englishSubQuestions.push_back(question03);
    englishSubQuestions.push_back(question04);
		englishSubQuestions.push_back(question05);
		englishSubQuestions.push_back(question06);
    englishSubQuestions.push_back(question07);
		englishSubQuestions.push_back(question08);
		englishSubQuestions.push_back(question09);
    englishSubQuestions.push_back(question10);
		englishSubQuestions.push_back(question11);
		englishSubQuestions.push_back(question12);
    englishSubQuestions.push_back(question13);
		englishSubQuestions.push_back(question14);
		englishSubQuestions.push_back(question15);
    englishSubQuestions.push_back(question16);
		englishSubQuestions.push_back(question17);
		englishSubQuestions.push_back(question18);
    englishSubQuestions.push_back(question19);
		englishSubQuestions.push_back(question20);

    //Correct Option
    vector<string> englishSubCorrectAns;
    englishSubCorrectAns.push_back("d");
    englishSubCorrectAns.push_back("b");
    englishSubCorrectAns.push_back("b");
    englishSubCorrectAns.push_back("b");
    englishSubCorrectAns.push_back("a");
    englishSubCorrectAns.push_back("b");
    englishSubCorrectAns.push_back("c");
		englishSubCorrectAns.push_back("c");
    englishSubCorrectAns.push_back("c");
    englishSubCorrectAns.push_back("d");
    englishSubCorrectAns.push_back("b");
    englishSubCorrectAns.push_back("a");
    englishSubCorrectAns.push_back("a");
    englishSubCorrectAns.push_back("b");
		englishSubCorrectAns.push_back("a");
    englishSubCorrectAns.push_back("c");
    englishSubCorrectAns.push_back("a");
    englishSubCorrectAns.push_back("c");
    englishSubCorrectAns.push_back("a");
    englishSubCorrectAns.push_back("b");

    //This line of code pick a random question in the vector above
  	srand(static_cast<unsigned int>(time(0)));
		random_shuffle(englishSubQuestions.begin(), englishSubQuestions.end());

		//Don't remove this if you do the option is gonna mess up
		srand(static_cast<unsigned int>(time(0)));
		random_shuffle(englishSubCorrectAns.begin(), englishSubCorrectAns.end());
	
    int totalQS = 10;
		int score {0};

    for( int i=0; i<totalQS; i++ )
    {
        //This line of code allow us to display the question
		cout<<"\nQuestion # "<<(i+1)<<endl;
		cout << "\t" << englishSubQuestions[i];

		cout<<"Select Option (A-B) or Type (skip) to skip the question: ";
    string userInputtedAns{ };
		getline(cin,userInputtedAns);

		//Convert the user input into lowercase
    for (int i=0;i<userInputtedAns.length();i++) // Get the input of the string using length() function
				{ 
         userInputtedAns[i]=tolower(userInputtedAns[i]); //converting every character into lower case
        }

		if(userInputtedAns == englishSubCorrectAns[i])
		{
			cout << "Great job! you selected the Right Answer.\n";
			system("pause");
			score++;
		}
		else if(userInputtedAns != englishSubCorrectAns[i])
		{
			cout << "You selected the Wrong Answer\n";
			cout << "\n";
			cout << "Correct Answer is ====> " << englishSubCorrectAns[i] << "\n";
			system("pause");
		}

		system("cls");

		}
		
		resultScreen(inputtedUserName, score);

    cin.get();
    cin.ignore();
    return 0;

}

int introProgQuiz(string inputtedUserName)
{
		//calling this function before the quiz begin
		subAskBeforeBegin(inputtedUserName);

    //A string full of question and their options
   string
		question01 = "\nThis is a part of speech that shows the relationship of a noun or pronoun to another word. They can indicate time, place, or relationship.\n"
		 " a) noun\n"
		 " b) pronoun\n"
		 " c) adjective\n"
		 " d) preposition\n\n",
		question02 = "\nWhich word indicates correct spelling?\n"
		 " a) belive\n"
		 " b) believe \n"
		 " c) bilieve\n"
		 " d) beleive\n\n",
		question03 = "\n'The wind whisper to the trees as it creeps in the night' this is an example of what figure of speech?\n" 
		" a) smile\n" 
		" b) personification\n" 
		" c) metaphor\n" 
		" d) hyperbole\n\n",
    question04 = "\nThis is en element of poetry that pertain to the series of lines grouped together and separated by an empty line from other stanzas. They are the equivalent of a paragraph in an essay.\n"
		 " a) rhyme\n"
		 " b) stanza\n"
		 " c) form\n"
		 " d) meter\n\n",
		question05 = "\nA kind of sentence that makes a statement\n"
		" a) declarative\n" 
		" b) interrogative\n" 
		" c) imperative\n" 
		" d) exclamatory\n\n",
		question06 = "\nThis pertains to the prosodic feature of speech that is the relative emphasis or prominence given to a certain syllable in a word, or to a certain word in a phrase or sentence\n" 
		" a) pause\n" 
		" b) stress\n" 
		" c) intonation\n" 
		" d) pitch\n\n",
    question07 = "\nthe most important element of a story; they were the ones who play certain roles and acts in the story itself.\n" 
		" a) plot\n" 
		" b) settings\n" 
		" c) characters\n" 
		" d) theme\n\n",
    question08 = "\nWhat _______ when I called?\n"
		 " a) Was you doing\n"
		 " b) Was you do\n"
		 " c) Were you doing\n"
		 " d) You were doing\n\n",
		question09 = "\nWhat is the study of languages?\n"
		" a) Phonetics\n" 
		" b) Syntax\n" 
		" c) Linguistics\n" 
		" d) Semantics\n\n",
		question10 = "\nPhonetics is the study of the sounds of language. What do we call these sounds?\n" 
		" a) Morphemes\n" 
		" b) Syntax\n" 
		" c) Lexicology\n" 
		" d) Phonemes\n\n",
    question11 = "\nA word opposite in meaning to another?\n"
		 " a) synonym\n"
		 " b) antonym\n"
		 " c) contranym\n"
		 " d) preposition\n\n",
		question12 = "\nA pair or group of words that usually go together (e.g. fish and chips)\n"
		 " a) collocation\n"
		 " b) idiom \n"
		 " c) conjunction\n"
		 " d) metaphor\n\n",
		question13 = "\nA group of words that includes a subject and a finite verb.\n" 
		" a) clauses\n" 
		" b) phrasal verb\n" 
		" c) noun phrase\n" 
		" d) predicate\n\n",
    question14 = "\nA verb that has a subject but no object.\n"
		 " a) transitive verb\n"
		 " b) intransitive verb\n"
		 " c) reflexive verb\n"
		 " d) Meme verb\n\n",
		question15 = "\nVerb form in which the action is done to the subject rather than the object.\n"
		" a) active voice\n" 
		" b) passive voice\n" 
		" c) reflective voice\n" 
		" d) Yo mama voice\n\n",
		question16 = "\nA short phrase added to a statement to make it a question.\n" 
		" a) question phrase\n" 
		" b) question tag\n" 
		" c) question mark\n" 
		" d) question\n\n",
    question17 = "\nVery informal words and expressions that are more common in spoken language, especially used by a particular group o f people, e.g., teenagers. They often go in and out of fashion very quickly. They can sometimes cause offense.\n" 
		" a) slang\n" 
		" b) metaphor\n" 
		" c) synonym\n" 
		" d) smile\n\n",
    question18 = "\nWords and phrases used in conversation or writing to friends but not in formal speech or writing.\n"
		 " a) collocation\n"
		 " b) slang\n"
		 " c) colloquial\n"
		 " d) smile\n\n",
		question19 = "\nGROW UP is......\n"
		" a) phrasal verb\n" 
		" b) metaphor\n" 
		" c) idiom\n" 
		" d) slang\n\n",
		question20 = "\nIt's raining cats and dogs , is a example of...\n" 
		" a) sland\n" 
		" b) idiom\n" 
		" c) callocation\n" 
		" d) metaphor\n\n";

    vector <string> introProgSubQuestions;
		introProgSubQuestions.push_back(question01);
		introProgSubQuestions.push_back(question02);
		introProgSubQuestions.push_back(question03);
    introProgSubQuestions.push_back(question04);
		introProgSubQuestions.push_back(question05);
		introProgSubQuestions.push_back(question06);
    introProgSubQuestions.push_back(question07);
		introProgSubQuestions.push_back(question08);
		introProgSubQuestions.push_back(question09);
    introProgSubQuestions.push_back(question10);
		introProgSubQuestions.push_back(question11);
		introProgSubQuestions.push_back(question12);
    introProgSubQuestions.push_back(question13);
		introProgSubQuestions.push_back(question14);
		introProgSubQuestions.push_back(question15);
    introProgSubQuestions.push_back(question16);
		introProgSubQuestions.push_back(question17);
		introProgSubQuestions.push_back(question18);
    introProgSubQuestions.push_back(question19);
		introProgSubQuestions.push_back(question20);
		
    //Correct Option
    vector<string> introProgSubCorrectAns;
     introProgSubCorrectAns.push_back("d");
     introProgSubCorrectAns.push_back("b");
     introProgSubCorrectAns.push_back("b");
     introProgSubCorrectAns.push_back("b");
     introProgSubCorrectAns.push_back("a");
     introProgSubCorrectAns.push_back("b");
     introProgSubCorrectAns.push_back("c");
		 introProgSubCorrectAns.push_back("c");
     introProgSubCorrectAns.push_back("c");
     introProgSubCorrectAns.push_back("d");
     introProgSubCorrectAns.push_back("b");
     introProgSubCorrectAns.push_back("a");
     introProgSubCorrectAns.push_back("a");
     introProgSubCorrectAns.push_back("b");
		 introProgSubCorrectAns.push_back("a");
     introProgSubCorrectAns.push_back("c");
     introProgSubCorrectAns.push_back("a");
     introProgSubCorrectAns.push_back("c");
     introProgSubCorrectAns.push_back("a");
     introProgSubCorrectAns.push_back("b");

    //This line of code pick a random question in the vector above
  	srand(static_cast<unsigned int>(time(0)));
		random_shuffle(introProgSubQuestions.begin(), introProgSubQuestions.end());

		//Don't remove this if you do the option is gonna mess up
		srand(static_cast<unsigned int>(time(0)));
		random_shuffle( introProgSubCorrectAns.begin(),  introProgSubCorrectAns.end());
	
    int totalQS = 10;
		int score { 0 };
		

    for( int i=0; i<totalQS; i++ )
    {
        //This line of code display the question
		cout<<"\nQuestion # "<<(i+1)<<endl;
		cout << "\t" << introProgSubQuestions[i];

		cout<<"Select Option (A-B) or Type (skip) to skip the question: ";
    string userInputtedAns{ };
		getline(cin, userInputtedAns);

		//Convert the user input into lowercase
    for (int i=0;i<userInputtedAns.length();i++) // Get the input of the string using length() function
				{ 
         userInputtedAns[i]=tolower(userInputtedAns[i]); //converting every character into lower case
        }

		if(userInputtedAns ==  introProgSubCorrectAns[i])
		{
			cout << "Great job! you selected the Right Answer.\n";
			system("pause");
			score = score + 1;
		}
		else if(userInputtedAns != introProgSubCorrectAns[i])
		{
			cout << "You selected the Wrong Answer\n";
			cout << "\n";
			cout << "Correct Answer is ====> " <<  introProgSubCorrectAns[i] << "\n";
			system("pause");
		}
		system("cls");
		}
		
		resultScreen(inputtedUserName, score);

    cin.get();
    cin.ignore();
    return 0;

}

int startQuiz(int score)
{
	//Get the name of the user
	cout << "What is your name? ";
	string inputtedUsername{ };
	cin >> inputtedUsername;
	system("cls");

  bool active = true;

	while(active)
    {
				gotoXY(50,2);
				cout  << "====Select Subject to Proceed=====\n";
				cout << "\n";
        int menu{0};
        subjectMenu();
        cin >> menu;
        system("cls");
        switch(menu)
            {
        case 1:
                englishQuiz(inputtedUsername); 
                break;
                active = {false};
				case 2:
                introProgQuiz(inputtedUsername); 
                break;
                active = {false};

				case 3:
                system("cls");
								return 0; //Return to Menu
        default:
                cout << "Not an option! \n";
                system("pause");
                system("cls");
                break;
            }
		}				

}

  
int main(int score)
{
		system("CLS");

    // Main Menu Screen
    while(true)
    {
			//Program Title
			system("cls");
			gotoXY(16,0);
			cout << R"(
   ____   ____     ____          ___     _   _             _____        ____      _      __  __  U _____ u 
U /"___|U|  _"\ uU|  _"\ u      / " \ U |"|u| |   ___     |"_  /u    U /"___|uU  /"\  uU|' \/ '|u\| ___"|/ 
\| | u  \| |_) |/\| |_) |/     | |"| | \| |\| |  |_"_|    U / //     \| |  _ / \/ _ \/ \| |\/| |/ |  _|"   
 | |/__  |  __/   |  __/      /| |_| |\ | |_| |   | |     \/ /_       | |_| |  / ___ \  | |  | |  | |___   
  \____| |_|      |_|         U \__\_\u<<\___/  U/| |\u   /____|       \____| /_/   \_\ |_|  |_|  |_____|  
 _// \\  ||>>_    ||>>_          \\// (__) )(.-,_|___|_,-._//<<,-      _)(|_   \\    >><<,-,,-.   <<   >>  
(__)(__)(__)__)  (__)__)        (_(__)    (__)\_)-' '-(_/(__) (_/     (__)__) (__)  (__)(./  \.) (__) (__) 

---------------------------------------------------------------------------------by: Group 1           
			)";
	
        int mainMenuScreen{0};
        mainMenu();
        cin >> mainMenuScreen;
        system("cls");
        switch(mainMenuScreen)
            {
        case 1:
                startQuiz(score);
                break;
        case 2:
                return 0; // exit the program;
        default:
                cout << "Not an option! \n";
                system("pause");
                system("cls");
                break;
            }
    }
    return 0;
}