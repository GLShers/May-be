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
    cout<<"--------------------------------------------------------------------------------------------------------------------\n";
    for(int i=0; i<size;i++)
        if (((arr[i].name[0]=='C') or (arr[i].name[0]=='c')) and (arr[i].age>=25))
            cout<<"good";
        else continue;
    cout<<arr[0].name[0];
}
