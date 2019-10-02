// Jonah Bardos, Divya Kapoor
// 10/4/2019
// TCES203
// Project #1
//
//
//

#include <iostream>
#include <stdio.h>
using namespace std;

//*******************************   GLOBAL VARIABLES    *******************************
int SatOrActToken, SatMath, SatVerbal;
int ActMath, ActReading, ActScience, ActEnglish;
float GPA, maxGPA;
float satApplicant, actApplicant;
float GPAScore;
float applicantscore1, applicantscore2;
int tokenSecond;


void admitMessage();
void displayScores(float, float);
float calcSatScore(int, int);
float calcActScore(int, int, int, int);
float getSatScore();
float getActScore();
float getGpaScore();
float getOverallScore();
float calcGpaScore(float, float);
int getExamType();

int main(int argc, const char * argv[]) {
    admitMessage();
    admitMessage();
    displayScores(applicantscore1, applicantscore2);
    
    return 0;
}

/*
Prints the first two lines of the message
*/
void admitMessage()
{
    if (tokenSecond == 2){
        printf("Information for the second applicant: \n");
    }
    else{
        printf("Information for the first applicant: \n");
    }
    printf("\t do you have 1) SAT scores or 2) ACT scores? ");
    getExamType();
    if (SatOrActToken == 1)
    {
        getSatScore();
        getGpaScore();
        getOverallScore();
    }
    else
    {
        getActScore();
        getGpaScore();
        getOverallScore();
    }
    tokenSecond = 2;
}

/*
This gets exam Type returns 1 or 2
*/
int getExamType(){
    cin >> SatOrActToken;
    return SatOrActToken;
}


/*
Returns the total overall score for each applicant
*/
float getOverallScore()
{
    if (tokenSecond == 2){
        if (SatOrActToken == 1) {
            applicantscore2 = (satApplicant + GPAScore);
            return applicantscore2;
        }
        applicantscore2 = (actApplicant + GPAScore);
        return applicantscore2;
    }
    else{
    if (SatOrActToken == 1) {
        applicantscore1 = (satApplicant + GPAScore);
        return applicantscore1;
    }
    applicantscore1 = (actApplicant + GPAScore);
    return applicantscore1;
    }
}


/*
Asks for user input for SAT scores and returns the calculated SAT score
*/
float getSatScore()
{
    printf("\t SAT math? ");
    cin >> SatMath;
    printf("\t SAT verbal? ");
    cin >> SatVerbal;
    satApplicant = calcSatScore(SatMath, SatVerbal);
    return satApplicant;
}

//float calcSatScore(int, int); Calculates the SAT score based on the
//input scores
float calcSatScore(int math, int verbal)
{
    float satScore = ((2.0 * verbal) + math) / 24.0;
    return satScore;
}

//Gets user input for GPA score and
//returns the calculated GPA score
float getGpaScore()
{
    printf("\t actual GPA? ");
    cin >> GPA;
    printf("\t max GPA? ");
    cin >> maxGPA;
    GPAScore = calcGpaScore(GPA, maxGPA);
    return GPAScore;
}

//float calcGpaScore(float, float); Calculates the GPA score given the actual
//and max GPA
float calcGpaScore(float gpa, float maxgpa)
{
    return (gpa / maxgpa) * 100.0;
}

//; Gets user input for ACT score and returns
//the calculated ACT score
//float calcActScore(int, int, int,
//                   int);
float getActScore()
{
    printf("\t ACT English? ");
    cin >> ActEnglish;
    printf("\t ACT math? ");
    cin >> ActMath;
    printf("\t ACT reading? ");
    cin >> ActReading;
    printf("\t ACT science? ");
    cin >> ActScience;
    actApplicant = calcActScore(ActEnglish, ActMath, ActReading, ActScience);
    return actApplicant;
}

float calcActScore(int ActEnglish, int ActMath, int ActReading, int ActScience)
{
    return (2.0 * ActReading + (ActEnglish + ActMath + ActScience)) / 1.8;
}


//void displayScores(float, float); Displays the two applicant scores and the
//comparison
void displayScores(float applicant1, float applicant2)
{
    printf("First applicant overall score = %.3f \n", applicantscore1);
    printf("Second applicant overall score = %.3f \n", applicantscore2);
    if (applicantscore1 > applicantscore2){
        printf("The first applicant seems to be better \n");
    }
    else if (applicantscore1 < applicantscore2){
        printf("The second applicant seems to be better \n");
    }
    else{
        printf("The two applicants seem to be equal \n");
    }
}

