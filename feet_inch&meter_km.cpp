#include <iostream>
using namespace std;
class meter;
class inch
{
 float feet, inches;
public:
 float total;
 float convert;
 void getdata()
 {
 cout << "Enter the Distance in Feet and Inches: " << endl;
 cin >> feet, inches;
 total = feet * 12 + inches;
 convert = total * 2.54;
 }
 friend void com(meter, inch);
};
class meter
{
 float m, cm;
public:
 float total;
 void getdata()
 {
 cout << "Enter the istance in Metres and centimetres: " << endl;
 cin >> m, cm;
 total = m * 100 + cm;
 }
 friend void com(meter, inch);
};
void com(meter m, inch i)
{
 if (m.total > i.convert)
 {
 cout << "The larger distance is " << m.m << " metres and " << m.cm << " centimetres." << endl;
 }
 else
 {
 cout << "The larger distance is " << i.feet << " feet and " << i.inches << " inches." << endl;
 }
}
int main()
{
 meter m;
 inch i;
 i.getdata();
 m.getdata();
 com(m, i);
 return 0;
}
