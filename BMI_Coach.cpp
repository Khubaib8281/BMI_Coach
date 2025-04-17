#include <iostream>
#include <string>
#include <fstream>
#include <limits>
using namespace std;

class BMI_coach
{
private:
    float weight, BMI;
    float height, age;
    int height_unit;
    float m_height, inches, cm_height;
    string name;
    int gender, feet;

public:
    void display_record();
    void suggestion();
    // Takes input and also converts to height meters if in c or feet & inches
    void input()
    {
        cout << "\n\t\t\t\t********************BMI COACH********************\n\n"
             << endl;
        cout << "Enter your name: ";
        getline(cin, name);

        cout << "\nEnter your Gender:\n1. Male(1)\n2. Female(2)\nEnter here: ";
        while (!(cin >> gender) || (gender != 1 && gender != 2))
        {
            cout << "Invalid input. Please enter a valid integer(1(Male) / 2(Female)): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Enter your age: ";
        while (!(cin >> age) || age <= 0)
        {
            cout << "Invalid input. Please enter a valid age: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Enter your weight in kgs: ";
        while (!(cin >> weight) || weight <= 0)
        {
            cout << "Invalid input. Please enter a valid integer weight: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Heigth Measurement Unit:\n1. Meters(Enter 1)\n2. Centimeters(Enter 2)\n3. Feet and inches(Enter 3) ";
        while (!(cin >> height_unit) || (height_unit != 1 && height_unit != 2 && height_unit != 3))
        {
            cout << "Invalid input. Please enter a valid case: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (height_unit)
        {
        case 1:

            cout << "Enter height in meters: ";
            while (!(cin >> height) || height <= 0)
            {
                cout << "Invalid input. Please enter a valid height: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            m_height = height;
            break;

        case 2:

            cout << "Enter height in Centimeters: ";
            while (!(cin >> cm_height) || cm_height <= 0)
            {
                cout << "Invalid input. Please enter a valid height: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            m_height = cm_height * .01;
            cout << name << "'s height in meters is: " << m_height << endl;
            break;

        case 3:

            cout << "Enter Feet: ";
            while (!(cin >> feet) || feet <= 0)
            {
                cout << "Invalid input. Please enter a valid feet input: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            cout << "Enter Inches: ";
            while (!(cin >> inches) || inches < 0)
            {
                cout << "Invalid input. Please enter a valid inches input: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            m_height = (feet * 0.3048) + (inches * 0.0254);
            break;

        default:
            cout << "Choose a valid case...";
            break;
        }
    }

    float bmi_cal()
    {
        return weight / (m_height * m_height);
    }

    void user_record()
    {
        ofstream outfile("BMI_records.txt", ios::app);

        outfile << "=====BMI Report=====\n";
        outfile << "Name: " << name << endl;
        outfile << "Age: " << age << endl;
        outfile << "Gender: " << gender << endl;
        outfile << "Weight: " << weight << endl;
        outfile << "Height: " << m_height << " meters" << endl;
        outfile << "BMI: " << bmi_cal() << endl;
        outfile << "\n=====================\n"
                << endl;
    }
};

// Display user record

void BMI_coach::display_record()
{
    cout << "\n\t\t\t\t=============BMI Coach results=============\n";
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Gender: " << gender << endl;
    cout << "Weight: " << weight << endl;
    cout << "Height: " << m_height << " meters" << endl;
    cout << "BMI: " << bmi_cal() << endl;
    cout << "\n=====================\n"
         << endl;
}

// Suggestion based on BMI
void BMI_coach::suggestion()
{
    float fetch_bmi = bmi_cal();

    if (fetch_bmi < 10 || fetch_bmi > 50)
    {
        cout << "BMI seems incorrect. Please check your height and weight input." << endl;
    }
    else if (fetch_bmi < 18.5)
    {
        cout << "Category: Underweight\n"
             << "Diet: High-calorie foods like nuts, cheese, rice, bananas\n"
             << "Exercise: Light strength training, yoga, bodyweight squats\n"
             << "Tip: Eat frequently, don't skip meals, ensure protein intake\n";
    }
    else if (fetch_bmi < 25)
    {
        cout << "Category: Normal\n"
             << "Diet: Balanced (protein, whole grains, fruits, vegetables)\n"
             << "Exercise: Running, cycling, HIIT, push-ups, gym workouts\n"
             << "Tip: Maintain daily activity, drink 8-10 glasses of water, track sleep\n";
    }
    else if (fetch_bmi < 30)
    {
        cout << "Category: Overweight\n"
             << "Diet: Calorie deficit, high protein, low sugar, fiber-rich foods\n"
             << "Exercise: Brisk walking, swimming, resistance bands, elliptical\n"
             << "Tip: Avoid junk food, drink water before meals, sleep 7-9 hours\n";
    }
    else
    {
        cout << "Category: Obese\n"
             << "Diet: Strict portion control, fiber-rich meals, avoid sugary drinks\n"
             << "Exercise: Walking, chair exercises, aqua aerobics\n"
             << "Tip: Consult doctor, manage stress, avoid long sitting periods\n";
    }

    // Extra general tips
    cout << "\nGeneral Health Tips:\n"
         << "- Drink 8-10 glasses of water daily\n"
         << "- Get 7-9 hours of quality sleep\n"
         << "- Avoid long sitting, take movement breaks\n"
         << "- Focus on whole, unprocessed foods\n"
         << "- Use fitness apps (MyFitnessPal, Google Fit)\n"
         << "- Practice deep breathing or meditation for stress\n";
}

int main()
{
    BMI_coach b1;
    b1.input();
    b1.user_record();
    b1.display_record();
    b1.suggestion();
    return 0;
}