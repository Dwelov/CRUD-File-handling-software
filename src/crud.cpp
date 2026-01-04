
#include "crud.h"

//daniyal add your functions here


// function to add the students in the file.csv
void addStudents(const string &filename, const string &rollNumber, const string &newName,
                 const vector<int> &newMarks, float newAverage)
{
    ofstream file(filename, ios::app); // append mode
    if (!file)
    {
        cerr << "Error: file not found." << endl;
        return;
    }
    // Write the new record in CSV format
    file << rollNumber << "," << newName;
    for (int mark : newMarks)
    {
        file << "," << mark;
    }
    file << "," << newAverage << "\n";
    file.close();
    cout << "Student record added successfully!" << endl;
}

void updateRecord(const string &filename, const string &rollNumber, const string &newName,
                  const vector<int> &newMarks, float newAverage)

{
    // first declare the variables that are going to use in that block of the code

    ifstream file(filename);
    vector<string> lines;
    string line;
    bool found = false;

    if (!file)
    {
        cerr << "Error opening the file" << endl;
        return;
    }

    // read and update the line of the code
    while (getline(file, line))
    {
        if (line.rfind(rollNumber, 0) == 0)
        {
            cout << "line to update: " << line << endl;
            ostringstream updated; // stringstring writes in string just liek fstream in files
            updated << rollNumber << "," << newName;
            for (int mark : newMarks)
            {
                updated << "," << mark;
            }
            updated << "," << newAverage << endl;
            lines.push_back(updated.str());
            found = true;
        }
        else
        {
            lines.push_back(line);
        }
    }
    file.close();

    // displaying a error message in case the roll number not found
    if (!found)
    {
        cerr << "error updating the file because " << rollNumber << " not found" << endl;
        return;
    }

    // rewriting the updated file
    ofstream updatedFile(filename);
    for (const string &l : lines)
    {
        updatedFile << l << endl;
    }
    updatedFile.close();

    cout << "Student data for the " << rollNumber << " Updated Successfully" << endl;
}

void deleteRecord(const string &filename, const string &rollNumber)
{
    vector<string> lines;
    ifstream file(filename);
    if (!file)
    {
        cerr << "Error opening the file" << endl;
        return;
    }

    bool found = false;
    string line;

    while (getline(file, line))
    {
        if (line.rfind(rollNumber, 0) == 0)
        {
            found = true;
            cout << "Line to delete: " << line << endl;
            continue;
        }
        lines.push_back(line);
    }
    file.close();

    if (!found)
    {
        cerr << "Error: roll number " << rollNumber << " not found in file." << endl;
        return;
    }

    ofstream updatedData(filename, ios::trunc);
    if (!updatedData)
    {
        cerr << "Error opening file for writing" << endl;
        return;
    }

    for (const string &l : lines)
    {
        updatedData << l << endl;
    }
    updatedData.close();

    cout << "Record for roll number " << rollNumber << " deleted successfully." << endl;
}