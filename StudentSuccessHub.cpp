#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

// Helper function for input stream cleanup
void clearInputStream() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Helper function to print a formatted box
void printBox(const string& title, const string& msg) {
    cout << "\n+------------------------------------------+\n";
    cout << "| " << title << "\n";
    cout << "| " << msg << "\n";
    cout << "+------------------------------------------+\n";
}

class StudentSuccessHub {
public:
    void careerGuidance() const {
        int choice;
        cout << "\n--- Career Guidance System ---\n";
        cout << "1. Placement Paths\n";
        cout << "2. Higher Studies\n";
        cout << "3. Government Exams\n";
        cout << "4. Entrepreneurship\n";
        cout << "Choice: ";
        
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            clearInputStream();
            return;
        }

        switch (choice) {
            case 1:
                cout << "\n[Placement Paths]\n- Data Analyst\n- Software Developer\n- Cyber Security Expert\n";
                break;
            case 2:
                cout << "\n[Higher Studies Options]\n- MBA (Master of Business Administration)\n- MCA (Master of Computer Applications)\n- M.Sc IT (Master of Science in Information Technology)\n";
                break;
            case 3:
                cout << "\n[Government Exams]\n- UPSC Civil Services\n- State PSC (e.g., TNPSC)\n- Staff Selection Commission (SSC)\n- Banking Exams (IBPS/SBI PO)\n";
                break;
            case 4:
                cout << "\n[Entrepreneurship Roadmap]\n- Step 1: Identify a core problem\n- Step 2: Create a scalable solution\n- Step 3: Design a sustainable business model\n";
                break;
            default:
                cout << "Invalid option selected.\n";
        }
    }

    void calculateCGPA() const {
        int semesters;
        float gpa, sum = 0.0f;
        
        cout << "Enter number of semesters completed: ";
        if (!(cin >> semesters) || semesters <= 0) {
            cout << "Invalid number of semesters.\n";
            clearInputStream();
            return;
        }

        for (int i = 1; i <= semesters; i++) {
            while (true) {
                cout << "Enter GPA for Semester " << i << " (0.0 to 10.0): ";
                if (cin >> gpa && gpa >= 0.0f && gpa <= 10.0f) {
                    sum += gpa;
                    break;
                }
                cout << "Invalid input. GPA must be a number between 0.0 and 10.0.\n";
                clearInputStream();
            }
        }
        float cgpa = sum / semesters;
        cout << fixed << setprecision(2);
        cout << "\n+------------------------------------------+\n";
        cout << "|              CGPA REPORT                 |\n";
        cout << "+------------------------------------------+\n";
        cout << "| CGPA : " << cgpa << " / 10.00\n";
        cout << "+------------------------------------------+\n";
    }

    void trackAttendance() const {
        float attended, total;
        cout << "Enter classes attended: ";
        if (!(cin >> attended) || attended < 0) {
            cout << "Invalid entry.\n";
            clearInputStream();
            return;
        }
        cout << "Enter total classes conducted: ";
        if (!(cin >> total) || total <= 0 || attended > total) {
            cout << "Invalid entries. Total classes must be greater than 0 and attended cannot exceed total.\n";
            clearInputStream();
            return;
        }

        float percentage = (attended / total) * 100.0f;
        cout << fixed << setprecision(2);
        cout << "Current Attendance: " << percentage << "%\n";

        if (percentage >= 75.0f) {
            printBox("STATUS : ELIGIBLE FOR EXAMS", "ACTION : KEEP CONSISTENT ATTENDANCE");
        } else {
            printBox("STATUS : ATTENDANCE SHORTAGE", "ACTION : ATTEND MORE CLASSES IMMEDIATELY");
        }
    }

    void addStudyTask() const {
        int n;
        clearInputStream();
        cout << "\nNumber of Tasks: ";
        cin >> n;
        clearInputStream();

        vector<string> tasks(n);

        ofstream file("study_tasks.txt", ios::app);
        if (!file) {
            cout << "Error opening file to save study tasks.\n";
            return;
        }

        for (int i = 0; i < n; i++) {
            cout << "Task " << i + 1 << ": ";
            getline(cin, tasks[i]);
            file << tasks[i] << endl;
        }
        file.close();
        cout << "\nTasks saved successfully!\n";
    }

    void viewStudyTasks() const {
        ifstream file("study_tasks.txt");
        if (!file) {
            cout << "No study tasks found or error opening file.\n";
            return;
        }

        string task;
        cout << "\n========== SAVED STUDY TASKS ==========\n";
        while (getline(file, task)) {
            cout << "- " << task << endl;
        }
        file.close();
    }

    void addExam() const {
        string subject, date;
        clearInputStream(); // Ensure no leftover input

        cout << "Subject Name: ";
        getline(cin, subject);
        cout << "Exam Date (DD/MM/YYYY): ";
        getline(cin, date);

        ofstream file("exam_schedule.txt", ios::app);
        if (!file) {
            cout << "Error opening file to save exam schedule.\n";
            return;
        }

        file << subject << " | " << date << endl;
        file.close();
        cout << "\nExam saved successfully!\n";
    }

    void viewExams() const {
        ifstream file("exam_schedule.txt");
        if (!file) {
            cout << "No exams found or error opening file.\n";
            return;
        }

        string line;
        cout << "\n========== SAVED EXAM SCHEDULE ==========\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }

    void placementReadiness() const {
        float cgpa;
        int projects, aptitude, communication;

        cout << "Enter current CGPA (0-10 scale): ";
        if (!(cin >> cgpa) || cgpa < 0 || cgpa > 10) {
            cout << "Invalid CGPA.\n";
            clearInputStream();
            return;
        }

        cout << "Enter number of technical projects completed: ";
        if (!(cin >> projects) || projects < 0) {
            cout << "Invalid entry.\n";
            clearInputStream();
            return;
        }

        cout << "Enter aptitude score (0-10): ";
        if (!(cin >> aptitude) || aptitude < 0 || aptitude > 10) {
            cout << "Invalid entry.\n";
            clearInputStream();
            return;
        }

        cout << "Enter communication score (0-10): ";
        if (!(cin >> communication) || communication < 0 || communication > 10) {
            cout << "Invalid entry.\n";
            clearInputStream();
            return;
        }

        // Weight distribution: 40% academics, 30% domain skill, 15% aptitude, 15% communication
        float score = (cgpa * 4.0f) + (min(projects, 3) * 10.0f) + (aptitude * 1.5f) + (communication * 1.5f);
        if (score > 100.0f) score = 100.0f;

        cout << fixed << setprecision(1);
        cout << "\n+------------------------------------------+\n";
        cout << "|      PLACEMENT READINESS REPORT          |\n";
        cout << "+------------------------------------------+\n";
        cout << "| Score : " << score << "%\n";

        if (score >= 80.0f)
            printBox("STATUS", "HIGHLY EMPLOYABLE");
        else if (score >= 50.0f)
            printBox("STATUS", "MODERATELY READY");
        else
            printBox("STATUS", "NEEDS IMPROVEMENT");
    }

    void performancePredictor() const {
        float internal, attendance, assignment;

        cout << "Enter internal marks (out of 50): ";
        if (!(cin >> internal) || internal < 0 || internal > 50) {
            cout << "Out of bounds value.\n";
            clearInputStream();
            return;
        }

        cout << "Enter attendance percentage (0-100): ";
        if (!(cin >> attendance) || attendance < 0 || attendance > 100) {
            cout << "Out of bounds value.\n";
            clearInputStream();
            return;
        }

        cout << "Enter assignment marks (out of 10): ";
        if (!(cin >> assignment) || assignment < 0 || assignment > 10) {
            cout << "Out of bounds value.\n";
            clearInputStream();
            return;
        }

        // Final score calculation: internal (50%), attendance (20%), assignments (30%)
        float predictedScore = internal + (attendance * 0.2f) + (assignment * 3.0f);
        if (predictedScore > 100.0f) predictedScore = 100.0f;

        string grade;
        if (predictedScore >= 80)
            grade = "A";
        else if (predictedScore >= 60)
            grade = "B";
        else if (predictedScore >= 40)
            grade = "C";
        else
            grade = "F";

        cout << "\n+------------------------------------------+\n";
        cout << "|       PERFORMANCE PREDICTION             |\n";
        cout << "+------------------------------------------+\n";
        cout << "| Predicted Score : " << predictedScore << "\n";
        cout << "| Expected Grade : " << grade << "\n";
        cout << "+------------------------------------------+\n";
    }
};

int main() {
    StudentSuccessHub hub;
    int selection;

    do {
        cout << "\n=====================================";
        cout << "\n         STUDENT SUCCESS HUB         ";
        cout << "\n=====================================";
        cout << "\n1. Career Guidance";
        cout << "\n2. CGPA Calculator";
        cout << "\n3. Attendance Tracker";
        cout << "\n4. Add Study Task";
        cout << "\n5. View Study Tasks";
        cout << "\n6. Add Exam Schedule";
        cout << "\n7. View Exam Schedule";
        cout << "\n8. Placement Readiness";
        cout << "\n9. Performance Predictor";
        cout << "\n10. Exit Hub Application";
        cout << "\n=====================================";
        cout << "\nEnter Choice Action: ";

        if (!(cin >> selection)) {
            cout << "Fatal: Menu options require numerical entries only.\n";
            clearInputStream();
            continue;
        }

        switch (selection) {
            case 1: hub.careerGuidance(); break;
            case 2: hub.calculateCGPA(); break;
            case 3: hub.trackAttendance(); break;
            case 4: hub.addStudyTask(); break;
            case 5: hub.viewStudyTasks(); break;
            case 6: hub.addExam(); break;
            case 7: hub.viewExams(); break;
            case 8: hub.placementReadiness(); break;
            case 9: hub.performancePredictor(); break;
            case 10: cout << "\nThank you for using Student Success Hub. Good luck!\n"; break;
            default: cout << "Selection index not found. Try a value between 1 and 10.\n";
        }
    } while (selection != 10);

    return 0;
}