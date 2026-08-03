#include<iostream>

using namespace std;
class Box
{
private:
    int length;
    int breadth;
    int height;

public:
    // Default Constructor
    Box()
    {
        length = 0;
        breadth = 0;
        height = 0;
    }

    // Parameterized Constructor
    Box(int l, int b, int h)
    {
        length = l;
        breadth = b;
        height = h;
    }

    // Copy Constructor
    Box(Box &B)
    {
        length = B.length;
        breadth = B.breadth;
        height = B.height;
    }

    // Getters
    int getLength()
    {
        return length;
    }

    int getBreadth()
    {
        return breadth;
    }

    int getHeight()
    {
        return height;
    }

    // Volume
    long long CalculateVolume()
    {
        return 1LL * length * breadth * height;
    }

    // < operator
    bool operator<(Box &B)
    {
        if (length < B.length)
            return true;

        if (length == B.length && breadth < B.breadth)
            return true;

        if (length == B.length &&
            breadth == B.breadth &&
            height < B.height)
            return true;

        return false;
    }

    // << operator
    friend ostream &operator<<(ostream &out, Box &B)
    {
        out << B.length << " " << B.breadth << " " << B.height;
        return out;
    }
};

void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}