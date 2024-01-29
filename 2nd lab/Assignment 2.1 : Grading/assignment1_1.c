// Kamin Jittapassorn 66070503409

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    // 1st line get number of students
    int n;
    scanf("%d", &n);

    // struct scores
    // {
    //     char name[100];
    //     float score;
    // };

    // struct scores student[n];
    float SumOfScore = 0;
    float SumOfScoreSquare = 0;
    float MeanScore = 0;
    float StandardDeviation = 0;
    float highestScore = 0;
    char HighestScoreStudent[100];
    float lowestScore = 0;
    char LowestScoreStudent[100];
    char name[100];
    float score;
    
    // 2nd line get name and score of each student
    // for (int i = 0; i < n; i++)
    // {
        
    //     scanf("%s %f", student[i].name, &student[i].score);
    //     // sum scores
    //     SumOfScore += student[i].score;
    //     // sum scores square
    //     SumOfScoreSquare += pow(student[i].score, 2);
    //     // Find highest score student
    //     if (student[i].score > highestScore)
    //     {
    //         highestScore = student[i].score;
    //         strcpy(HighestScoreStudent, student[i].name);
    //     }
    //     // Find lowest score student
    //     if (student[i].score < lowestScore || i == 0)
    //     {
    //         lowestScore = student[i].score;
    //         strcpy(LowestScoreStudent, student[i].name);
    //     }
    // }

    for (int i = 0; i < n; i++)
    {
        
        scanf("%s %f", name, &score);
        // sum scores
        SumOfScore += score;
        // sum scores square
        SumOfScoreSquare += pow(score, 2);
        // Find highest score student
        if (score > highestScore)
        {
            highestScore = score;
            strcpy(HighestScoreStudent, name);
        }
        // Find lowest score student
        if (score < lowestScore || i == 0)
        {
            lowestScore = score;
            strcpy(LowestScoreStudent, name);
        }
    }

    // calculate mean score
    MeanScore = SumOfScore / n;
    // calculate standard deviation
    StandardDeviation = sqrt((SumOfScoreSquare / n) - pow(MeanScore, 2));
    if (fabs(StandardDeviation) < 0.01) {
        StandardDeviation = 0;
    }
    // debug 
    // printf("SumOfScore %d\n", SumOfScore);
    // printf("MeanScore %d\n", MeanScore);
    // printf("SumOfScoreSquare %d\n", SumOfScoreSquare);

    // print output
    printf("%.2f %.2f %s %s\n", MeanScore, StandardDeviation, HighestScoreStudent, LowestScoreStudent);
    return 0;
}