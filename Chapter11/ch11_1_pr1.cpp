#include <iostream>
#include <cstring>
using namespace std;

class Gun
{
private:
	int bullet;    
public:
	Gun(int bnum) : bullet(bnum)
	{ }
	void Shut()
	{
		cout<<"BBANG!"<<endl;
		bullet--;
	}
};

class Police
{
private:
	int handcuffs;    
	Gun * pistol;     
public:
	Police(int bnum, int bcuff)
		: handcuffs(bcuff)
	{
		if(bnum>0)
			pistol=new Gun(bnum);
		else
			pistol=NULL;
	}
    Police(const Police& copy)
        : handcuffs(copy.handcuffs)
    {
        if(copy.pistol != NULL)
        {
            pistol = new Gun(*(copy.pistol));
        }
        else
        {
            pistol = NULL;
        }
        
        
    }

    Police& operator=(const Police& ref)
    {
        if(pistol != NULL)
            delete pistol;
        if(ref.pistol != NULL)
            pistol = new Gun(*(ref.pistol));
        else
            pistol = NULL;
        
        
        handcuffs = ref.handcuffs;
        return *this;
    }

	void PutHandcuff() 
	{
		cout<<"SNAP!"<<endl;
		handcuffs--;
	}
	void Shut()
	{
		if(pistol==NULL)
			cout<<"Hut BBANG!"<<endl;
		else
			pistol->Shut();
	}
	~Police()
	{
		if(pistol!=NULL)
			delete pistol;
	}
};

int main(void)
{
    Police pman1(5,3);
    Police pman2 = pman1;
    pman2.PutHandcuff();
    pman2.Shut();

    Police pman3(2,4);
    pman3 = pman1;
    pman3.PutHandcuff();
    pman3.Shut();
	return 0;
}