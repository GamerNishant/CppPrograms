#include <iostream>
#include <cmath>

using namespace std;

//Class DM and DB

class DB; //forward declaration.

class DM
{
    int meters;
    int centimeters;

public:
    void inValue()
    {
        cout << "Enter the meters:";
        cin >> meters;
        cout << "Enter the centimeters:";
        cin >> centimeters;
    }

    int Meter()
    {
        return meters;
    }

    int centiMeter()
    {
        return centimeters;
    }

    void assign(int m , int cm)
    {
        meters = m;
        centimeters = cm;
    }

    void display()
    {
        cout << meters << " m " << centimeters << " cm" << endl;
    }

    friend void add(DM m, DB b);
};

class DB
{
    int feet;
    int inches;

public:
    void inValue()
    {
        cout << "Enter the feet:";
        cin >> feet;
        cout << "Enter the inches:";
        cin >> inches;
    }

    int fiit()
    {
        return feet;
    }

    float enches()
    {
        return inches;
    }

    void assign(int ft , int in)
    {
        feet = ft;
        inches = in;
    }

    void display()
    {
        cout << feet << " ft. "
             << inches << " in" << endl;
    }
    friend void add(DM m, DB b);
};

void add(DM m, DB b, int choice)
{
    if (choice == 1)
    {
        DM temp;
        int mtr;
        float cmt;
        mtr = (m.Meter() + (b.fiit()) / 3.28084);
        float f = mtr - floor(mtr);
        cmt = (m.centiMeter() + (b.enches()) * 2.54 + f * 100);

        while (cmt >= 100)
        {
            mtr++;
            cmt -= 100;
        }

        temp.assign(mtr, cmt);

        temp.display();
    }

    else
    {
        DB temp;
        int ft ;
        float in;
        ft = ((m.Meter()) * 3.28084 + (b.fiit()));
        float f = ft - floor(ft);
        in = ((m.centiMeter()) / 2.54 + (b.enches()) + f * 12);

        while (in >= 12)
        {
            ft++;
            in -= 12;
        }

        temp.assign(ft , in);
        temp.display();
    }
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);
    //     cout.setf(std::ios::boolalpha);

    DM m;
    DB b;

    cout << "Enter Values for DM:" << endl;
    m.inValue();

    cout << "Enter Values for DB:" << endl;
    b.inValue();

    cout << "Enter your choice"
         << endl
         << "1. In Meters."
         << endl
         << "2. In Feet." << endl;

    while (true)
    {
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            add(m, b, 1);
            break;

        case 2:
            add(m, b, 2);

        default:
            exit(0);
        }
    }
    return 0;
}
