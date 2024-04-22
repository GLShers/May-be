#include <iostream>

using namespace std;
struct person
{
    char *name;
    int age;
};

int main()
{
    setlocale(LC_ALL, "Russian");
    int size;
    cout << "Input value puple";
    cin >> size;
    person *arr = new person[size];
    for (int i = 0; i < size; i++)
    {
        arr[i].name = new char[25];
        cout << "name: ";
        cin >> arr[i].name;
        cout << "age: ";
        cin >> arr[i].age;
    }

    for (int i = 0; i < size; i++)
    {
        cout << "Person " << i + 1 << ":\n";
        cout << "Name: " << arr[i].name << "\n";
        cout << "Age: " << arr[i].age << "\n";
        cout << endl;
    }
    cout << "--------------------------------------------------------------------------------------------------------------------\n";
    person *arr2 = new person[size];
    for (int i = 0; i < size; i++)
    {
        arr2[i].name = new char[25];
    }
    int j;
    int o = 0;
    for (j = 0; j < size; j++)
    {
        if (((arr[j].name[0] == 'C') or (arr[j].name[0] == 'c')) and (arr[j].age >= 25))
        {
            arr2[j].name = arr[j].name;
            arr2[j].age = arr[j].age;
            o = +1;
        }

        else
            continue;
    }
    for (int i = 0; i < o; i++)
    {
        cout << "Person " << i + 1 << ":\n";
        cout << "Name: " << arr2[i].name << "\n";
        cout << "Age: " << arr2[i].age << "\n";
        cout << endl;
    }
}
