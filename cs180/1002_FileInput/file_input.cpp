// Karl Ramberg
// Creates a grade_report.txt file based on a score file input

#include <iostream>
#include<fstream>
#include<iomanip>

using namespace std;

int main()
{
    const unsigned int NAME_COLUMN = 25;
    const unsigned int SCORE_COLUMN = 4;
    const unsigned int AVERAGE_COLUMN = 7;
    const unsigned int LETTER_GRADE_COLUMN = 3;

    const unsigned int MAX_SCORE = 100;
    const unsigned int MIN_SCORE = 0;

    const unsigned int A_CUTOFF = 90;
    const unsigned int B_CUTOFF = 80;
    const unsigned int C_CUTOFF = 70;
    const unsigned int D_CUTOFF = 60;

    ifstream score_table("scores.txt");
    ofstream grade_report("grade_report.txt");

    unsigned int num_of_scores;
    score_table >> num_of_scores;

    string dummy;
    getline(score_table, dummy); // consumes newline

    string name;
    while (getline(score_table, name))
    {
      unsigned int largest_score = MIN_SCORE;
      unsigned int smallest_score = MAX_SCORE;
      unsigned int running_total = 0;

      for (unsigned int count = 0; count < num_of_scores; count++)
      {
        unsigned int score;
        score_table >> score;

        largest_score = score > largest_score ? score : largest_score;

        smallest_score = score < smallest_score ? score : smallest_score;

        running_total += score;
      }

      double average = static_cast<double>(running_total) / num_of_scores;

      char letter_grade;
      if (average >= A_CUTOFF)
      {
        letter_grade = 'A';
      }
      else if (average >= B_CUTOFF)
      {
        letter_grade = 'B';
      }
      else if (average >= C_CUTOFF)
      {
        letter_grade = 'C';
      }
      else if (average >= D_CUTOFF)
      {
        letter_grade = 'D';
      }
      else // must be F
      {
        letter_grade = 'F';
      }

      grade_report << setw(NAME_COLUMN) << left << name
                  << setw(SCORE_COLUMN) << right << smallest_score
                  << setw(SCORE_COLUMN) << right << largest_score
                  << setw(AVERAGE_COLUMN) << right
                  << fixed << setprecision(2) << average
                  << setw(LETTER_GRADE_COLUMN) << right
                  << letter_grade << endl;

      getline(score_table, dummy); //consumes newline
    }

    score_table.close();
    grade_report.close();

    return 0;
}
