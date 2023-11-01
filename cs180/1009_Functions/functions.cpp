// Karl Ramberg
// Creates a grade_report.txt based on a score file input

#include <iostream>
#include<fstream>
#include<iomanip>


using namespace std;
// opens and validates an input file
// parameter: the filename on the computer
// parameter: a stream for reading the file
void get_input_file(string &filename, ifstream &file);

// computes average of a set of numbers
// parameter: total of a set of numbers
// parameter: number of values in a set
// return: average of the number set
double compute_average(unsigned total, unsigned number_of_values);

// gives a letter grade based on an average score
// parameter: average number of a set of scores
// return: letter grade character (A, B, C, D, or F)
char get_grade(double average);

int main()
{
    const unsigned NAME_COLUMN = 24;
    const unsigned AVERAGE_COLUMN = 8;
    const unsigned LETTER_GRADE_COLUMN = 3;

    const unsigned AVERAGE_PRECISION = 2;

    const double MIN_AVERAGE = 0.0;

    string filename;
    ifstream score_table;
    get_input_file(filename, score_table);
    cout << "Reading " << filename << endl;

    ofstream grade_report("grade_report.txt");
    grade_report << fixed << setprecision(AVERAGE_PRECISION);

    unsigned number_of_scores;
    score_table >> number_of_scores;

    string dummy;
    getline(score_table, dummy); // consumes newline

    string best_student;
    double highest_average = MIN_AVERAGE;
    unsigned number_of_students_read = 0;

    string name;
    while (getline(score_table, name))
    {
      unsigned running_total = 0;

      for (unsigned count = 0; count < number_of_scores; count++)
      {
        unsigned score;
        score_table >> score;
        running_total += score;
      }

      double average = compute_average(running_total, number_of_scores);

      if (average > highest_average)
      {
        highest_average = average;
        best_student = name;
      }

      char letter_grade = get_grade(average);

      grade_report << setw(NAME_COLUMN) << left << name
        << setw(AVERAGE_COLUMN) << right << average
        << setw(LETTER_GRADE_COLUMN) << right << letter_grade
        << endl;

      number_of_students_read++;

      getline(score_table, dummy); //consumes newline
    }

    cout << number_of_students_read << " student records were read from "
      << filename << endl;

    grade_report << "The highest average was " << best_student
      << " with an average of " << highest_average << endl;

    score_table.close();
    grade_report.close();

    return 0;
}

void get_input_file(string &filename, ifstream &file)
{
  cout << "Enter a data filename: ";
  cin >> filename;

  file.open(filename);

  while(file.fail())
  {
    cout << "Cannot read that file" << endl;
    cout << "Enter a data filename: ";
    cin >> filename;
    file.open(filename);
  }
}

double compute_average(unsigned total, unsigned number_of_values)
{
  return static_cast<double>(total) / number_of_values;
}

char get_grade(double average)
{
  const double A_CUTOFF = 90.0;
  const double B_CUTOFF = 80.0;
  const double C_CUTOFF = 70.0;
  const double D_CUTOFF = 60.0;

  if (average >= A_CUTOFF)
  {
    return 'A';
  }
  else if (average >= B_CUTOFF)
  {
    return 'B';
  }
  else if (average >= C_CUTOFF)
  {
    return 'C';
  }
  else if (average >= D_CUTOFF)
  {
    return 'D';
  }
  else // must be F
  {
    return 'F';
  }
}
