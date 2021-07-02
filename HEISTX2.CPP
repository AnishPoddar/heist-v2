#include<iostream.h>
#include<math.h>
#include<conio.h>
#include<dos.h>
#include<process.h>
#include<fstream.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

const int maxlives=3, eh=10, mh=20, hh=50;

int maxbullets=4, maxammo = 4, arad = 8, lrad = 2, srange = 10, tdamage = 1, countimax = 20;
int utimer = 0;

ofstream f1;
ifstream f2;
int flag = 0;

int e1[1] = {1}, e2[2] = {1,1}, m1[3]={1,1,1}, m2[3]={1,1,1}, h1[7]={1,1,1,1,1,1,1}, h2[5]={1,1,1,1,1}, lives = maxlives;

int lifee[3] = {0,0,0}, lifem[6] = {0,0,0,0,0,0}, lifeh[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
long money = 0, totalmoney=0, bullets = 0, ammo = 0;
char m[20][20], e[12][12], h[24][24];
int num;
int nf = 0;
int i1 = 0, i2 = 0;
int se = 0, sm = 0, sh = 0; int killcount = 0;           //revolver
int ie = 0, im = 0, ih = 0; int fi = 0;                  //invisibility
int le = 0, lm = 0, lh = 0; int li = 0;                  //landmines
int ge = 0, gm = 0, gh = 0;                              //shotgun
int ae = 0, am = 0, ah = 0;                              //airstrike
int te = 0, tm = 0, th = 0; int ti = 0, stimer = 0;      //snare trap
int unlocked = 0;

char u1 = '0', u2 = '0', u3 = '0', u4 = '0', u5 = '0', u6 = '0';   
int counti = 0, countse = 0, countsm = 0, countsh = 0; //enemy AI variables

char achievement[5]={'0','0','0','0','0'};
int levelkills;
int complete[3]={0,0,0};
void menu();


//SOUNDS

void beep()
{sound(369); delay(100); nosound();}

void sound2()
{sound(261); delay(100); nosound();
 sound(523); delay(100); nosound();
}

void sound3()
{sound(220); delay(100); nosound();
 sound(110); delay(100); nosound();
 sound(440); delay(100); nosound();
}

void sound4()
{sound(261); delay(100); nosound();
 sound(330); delay(100); nosound();
 sound(392); delay(100); nosound();
 sound(523); delay(100); nosound();
}

void sound5()
{sound(196); delay(75); nosound();
 delay(25);
 sound(392); delay(75); nosound();
 delay(25);
 sound(392); delay(75); nosound();
 delay(25);
 sound(392); delay(100); nosound();
}

void sound8()
{ sound(440); delay(50); nosound();
  delay(25);
  sound(440); delay(50); nosound();
}

void winsound()
{sound(196); delay(50);  nosound();
 sound(262); delay(50);  nosound();
 sound(330); delay(50);  nosound();
 sound(392); delay(50);  nosound();
 sound(262); delay(50);  nosound();
 sound(330); delay(50);  nosound();
 sound(392); delay(50);  nosound();
 sound(523); delay(200); nosound();
}



//DATA CONTROL

void achieve()
{ textcolor(11);
clrscr(); beep();
cout<<"                           A C H I E V E M E N T S  \n\n\n\n";
for(int i=0;i<5;i++)
{if(achievement[i]=='0')cout<<"   ACHIEVEMENT HIDDEN ";
 else switch(i)
	  {case 0:{cout<<"   6H05T PR0T0C0L  : Complete a level without killing or being spotted";break;}
	   case 1:{cout<<"   3XT3RM1N4T0R    : Kill everyone in a level";break;}
	   case 2:{cout<<"   TR1PL3 5H0T     : Kill 3 enemies in 1 revolver shot";break;}
	   case 3:{cout<<"   B0MB5 AW@Y      : Kill more than six guards with a single airstrike";break;}
	   case 4:{cout<<"   C0MPL3T10N15T   : Complete all 3 levels";break;}
	   default:break;
	  }
	  cout<<endl<<endl;

}getch();
menu();
}


void save()
{ f1.open("savegame2.txt");  //saves upgrades & achievements


  f1.put(u1);
  f1.put(u2);
  f1.put(u3);
  f1.put(u4);
  f1.put(u5);
  f1.put(u6);

  for (int i=0;i<5;i++)

  f1.put(achievement[i]);

  f1.close();
  clrscr();
  cout<<"Game saved";
  sound2();
  getch();
  menu();
}

void resetdata()
{ clrscr();
  beep();
  cout<<" Are you sure? (Y/N)";
  char ch=getch();
  if (ch=='y'||ch=='Y')
  {totalmoney=0;
  u1='0';u2='0';u3='0';u4='0';u5='0';u6='0';
  for (int i=0;i<5;i++)
  achievement[i]='0';
  cout<<"\n\n Game Data Erased";
  beep();
  getch();}
  menu();
}

void retrieve()
{ f2.open("savegame2.txt");  //restores upgrades & achievements


	f2.get(u1);
	f2.get(u2);
	f2.get(u3);
	f2.get(u4);
	f2.get(u5);
	f2.get(u6);

	for (int i=0;i<5;i++)

  f2.get(achievement[i]);
  f2.close();
  clrscr();
  cout<<"Game loaded";
  sound2();
  getch();
  menu();
}



void egg1()
{ textcolor(11);
clrscr();
cout<<"                 BANK INTRANET - TRANSACTION ID LIST \n\n\n";
cout<<"      1. 74f86pc    \n\n";
cout<<"      2. mc74ac32n  \n\n";
cout<<"      3. dm74ls32   \n\n";
cout<<"      4. hef4011b   \n\n";
getch();
  textcolor(11);
}


void egg2()
{ textcolor(11);

char t1[10] = {'7','4','f','8','6','p','c','\0'};
char t2[10] = {'m','c','7','4','a','c','3','2','n','\0'};
char t3[10] = {'h','e','f','4','0','1','1','b','\0'};
char t4[10] = {'d','m','7','4','l','s','3','2','\0'};
char ex[10] = {'e','x','i','t','\0'};

x:
clrscr();
cout<<"                 BANK INTRANET - TRANSACTION RECORDS  \n\n";
cout<<"               (Enter 'exit' to leave at any time)  \n\n";
cout<<"      Enter transaction ID: ";
char id[10];
gets(id); int flag = 0;

if(strcmp(id, t1)==0)
{flag = 1;
 cout<<"\n\n";
 cout<<"\n   Customer name:       Arvin Sloane";
 cout<<"\n   Allied corporation:  SD-6";
 cout<<"\n   Item ordered:        Rambaldi solution";
 cout<<"\n   Comments:            To be delivered unseen";
 getch(); goto x;



}

if(strcmp(id, t2)==0)
{flag = 1;
 cout<<"\n\n";
 cout<<"\n   Customer name:       Richard Brook";
 cout<<"\n   Allied corporation:  None";
 cout<<"\n   Item ordered:        Rhododendron ponticum - extract";
 cout<<"\n   Comments:            To be sent to 221B Baker Street ";
 getch(); goto x;
}

if(strcmp(id, t3)==0)
{flag = 1;
 cout<<"\n\n";
 cout<<"\n   Customer name:       Alan Rikkin";
 cout<<"\n   Allied corporation:  Abstergo Industries";
 cout<<"\n   Item ordered:        NAVSAT imaging satellite blueprints";
 cout<<"\n   Comments:            To be made operational by 12.21.2016";
 getch(); goto x;
}





if(strcmp(id, t4)==0)
{flag = 1;
 cout<<"\n\n";
 cout<<"\n   Customer name:       Dr. Joe, N.H.";
 cout<<"\n   Allied corporation:  The Blake Association";
 cout<<"\n   Item ordered:        CBI Surveillance Tapes - Mar-Jun 2016";
 cout<<"\n   Comments:            None";
 getch(); goto x;
}

if(strcmp(id, ex)==0)
{flag = 1; cout<<"\n            Thank you for visiting"; getch(); textcolor(11);}

if(flag==0)
{cout<<"\n\n       INVALID ID. RE-ENTER"; getch(); goto x;}


}


void store()
{ beep();
  clrscr();
  cout<<"\n\n";
  cout<<"                      XXXXX  XXXXX  XXXXX  XXXX   XXXXX  \n";
  cout<<"                      X        X    X   X  X  X   X   X  \n";
  cout<<"                      XXXXX    X    X   X  XXX    XXXXX  \n";
  cout<<"                          X    X    X   X  X  X   X      \n";
  cout<<"                      XXXXX    X    XXXXX  X   X  XXXXX  \n";
  cout<<"\n\n\n              (Enter 0 at any time to return to the main menu)  \n\n";
  cout<<"                                 Funds: "<<totalmoney<<"\n\n";
  cout<<"\n                    1.Invisiblity           -    1000 $     ";
  if(::u1=='1') cout<<"Purchased";
  cout<<"\n                    2.Silenced Pistol       -    5000 $     ";
  if(::u2=='1') cout<<"Purchased";
  cout<<"\n                    3.Landmines             -    3000 $     ";
  if(::u3=='1') cout<<"Purchased";
  cout<<"\n                    4.Machine gun           -    8000 $     ";
  if(::u4=='1') cout<<"Purchased";
  cout<<"\n                    5.Airstrike             -   15000 $     ";
  if(::u5=='1') cout<<"Purchased";
  cout<<"\n                    6.Snare trap            -    7000 $     ";
  if(::u6=='1') cout<<"Purchased";

  int u = 0;
  cout<<"\n\n\n             Which upgrade would you like? (1/2/3/4/5/6): ";
  cin>>u;

  if(u<0||u>9) store();

	   if((u==1)&&(totalmoney>=1000))
	   {
		if(::u1=='0')
		{::u1 = '1';
		cout<<"\n          Upgrade gained - Invisibility";
		sound2();
		getch();
		::totalmoney = ::totalmoney - 1000;}
		else if(::u1=='1')
		cout<<"\n        Upgrade already purchased"; getch(); store();
	   }
  else if((u==1)&&(totalmoney<1000)&&(::u1=='0'))
  {cout<<"   Not enough money to buy this upgrade"; getch(); store();}

	   if((u==2)&&(totalmoney>=5000))
	   {
		if(::u2=='0')
		{::u2 = '1';
		cout<<"\n          Upgrade gained - Silenced Pistol";
		sound2();
		getch();
		::totalmoney = ::totalmoney - 5000;}
		else if(::u2=='1')
		cout<<"\n        Upgrade already purchased"; getch(); store();

	   }
  else if((u==2)&&(totalmoney<5000)&&(::u2=='0'))
  {cout<<"   Not enough money to buy this upgrade"; getch(); store();}

	   if((u==3)&&(totalmoney>=3000))
	   {
		if(::u3=='0')
		{::u3 = '1';
		cout<<"\n          Upgrade gained - Landmines";
		sound2();
		getch();
		::totalmoney = ::totalmoney - 3000;}
		else if(::u3=='1')
		cout<<"\n        Upgrade already purchased"; getch(); store();


	   }
  else if((u==3)&&(totalmoney<3000)&&(::u3=='0'))
  {cout<<"   Not enough money to buy this upgrade"; getch(); store();}

  if((u==4)&&(totalmoney>=8000))
	   {
		if(::u4=='0')
		{::u4 = '1';
		cout<<"\n          Upgrade gained - Machine gun";
		sound2();
		getch();
		::totalmoney = ::totalmoney - 8000;}
		else if(::u4=='1')
		cout<<"\n        Upgrade already purchased"; getch(); store();

	   }
  else if((u==4)&&(totalmoney<8000)&&(::u4=='0'))
  {cout<<"   Not enough money to buy this upgrade"; getch(); store();}

  if((u==5)&&(totalmoney>=15000))
	   {
		if(::u5=='0')
		{::u5 = '1';
		cout<<"\n          Upgrade gained - Airstrike";
		sound2();
		getch();
		::totalmoney = ::totalmoney - 15000;}
		else if(::u5=='1')
		cout<<"\n        Upgrade already purchased"; getch(); store();


	   }
  else if((u==5)&&(totalmoney<15000)&&(::u5=='0'))
  {cout<<"   Not enough money to buy this upgrade"; getch(); store();}

  if((u==6)&&(totalmoney>=7000))
	   {
		if(::u6=='0')
		{::u6 = '1';
		cout<<"\n          Upgrade gained - Snare trap";
		sound2();
		getch();
		::totalmoney = ::totalmoney - 7000;}
		else if(::u6=='1')
		cout<<"\n        Upgrade already purchased"; getch(); store();


	   }
  else if((u==6)&&(totalmoney<7000)&&(::u6=='0'))
  {cout<<"   Not enough money to buy this upgrade"; getch(); store();}

  if(u==0) menu();

  menu();


}



void gameover(int i)
{ textcolor(4);
  clrscr();
  if(i==2||i==3)
	{cout<<"\n\n\n\n";
	 cout<<"\n             X  X   XXX   XXXX    XXXX    XXXX   X       X   ";
	 cout<<"\n             X X   X   X  X   X  X    X  X    X  XX     XX   ";
	 cout<<"\n             XX    XXXXX  XXXX   X    X  X    X  X X   X X   ";
	 cout<<"\n             X X   X   X  X   X  X    X  X    X  X  X X  X   ";
	 cout<<"\n             X  X  X   X  XXXX    XXXX    XXXX   X   X   X   ";
	 getch();
	}


  clrscr();
  cout<<"\n\n\n\n\n";
  cout<<"                       ---<< G A M E   O V E R >>---";
  if(i==1) cout<<"\n\n                                  DEADSHOT  ";
  if(i==2) cout<<"\n\n                                  LANDMINED ";
  if(i==3) cout<<"\n\n                                  AIRBOMBED ";
  cout<<endl<<"\n\n\t       The money you stole in your heists is now halved \n\n\n";

  sound(311); delay(250); nosound();
  sound(277); delay(250); nosound();
  sound(262); delay(750); nosound();
  getch();

  totalmoney*=0.5;
  money=0;
  clrscr();
  menu();
}




void spotted()
{ if(lives==3) textcolor(14);
  if(lives==2) textcolor(6);
  clrscr();
cout<<"Spotted"<<endl; lives--; cout<<"\nThe number of lives left: "<<lives;
if(!lives) gameover(0);

sound(261); delay(75); nosound();
delay(25);
sound(261); delay(75); nosound();
delay(25);
sound(277); delay(75); nosound();
delay(25);
sound(277); delay(75); nosound();

getch();
  textcolor(11);
}






void assign(char lvl, char ch)
{ switch(lvl)

  {     case '1': if(ch=='1') {if(::u2=='1') se = 1; ie = 0; le = 0; ge = 0; ae = 0; te = 0;}

		  if(ch=='2') {se = 0; if(::u1=='1') ie = 1; le = 0; ge = 0; ae = 0; te = 0;}

		  if(ch=='3') {se = 0; ie = 0; if(::u3=='1') le = 1; ge = 0; ae = 0; te = 0;}

		  if(ch=='4') {se = 0; ie = 0; le = 0; if(::u4=='1') ge = 1; ae = 0; te = 0;}

		  if(ch=='5') {se = 0; ie = 0; le = 0; ge = 0; if(::u5=='1') ae = 1; te = 0;}

		  if(ch=='6') {se = 0; ie = 0; le = 0; ge = 0; ae = 0; if(::u6=='1') te = 1;}



	case '2': if(ch=='1') {if(::u2=='1') sm = 1; im = 0; lm = 0; gm = 0; am = 0; tm = 0;}

		  if(ch=='2') {sm = 0; if(::u1=='1') im = 1; lm = 0; gm = 0; am = 0; tm = 0;}

		  if(ch=='3') {sm = 0; im = 0; if(::u3=='1') lm = 1; gm = 0; am = 0; tm = 0;}

		  if(ch=='4') {sm = 0; im = 0; lm = 0; if(::u4=='1') gm = 1; am = 0; tm = 0;}

		  if(ch=='5') {sm = 0; im = 0; lm = 0; gm = 0; if(::u5=='1') am = 1; tm = 0;}

		  if(ch=='6') {sm = 0; im = 0; lm = 0; gm = 0; am = 0; if(::u6=='1') tm = 1;}



	case '3': if(ch=='1') {if(::u2=='1') sh = 1; ih = 0; lh = 0; gh = 0; ah = 0; th = 0;}

		  if(ch=='2') {sh = 0; if(::u1=='1') ih = 1; lh = 0; gh = 0; ah = 0; th = 0;}

		  if(ch=='3') {sh = 0; ih = 0; if(::u3=='1') lh = 1; gh = 0; ah = 0; th = 0;}

		  if(ch=='4') {sh = 0; ih = 0; lh = 0; if(::u4=='1') gh = 1; ah = 0; th = 0;}

		  if(ch=='5') {sh = 0; ih = 0; lh = 0; gh = 0; if(::u5=='1') ah = 1; th = 0;}

		  if(ch=='6') {sh = 0; ih = 0; lh = 0; gh = 0; ah = 0; if(::u6=='1') th = 1;}
}
}

// LEVEL MAP BUILDING FUNCTIONS

void builde(char e[12][12],int b, int a)   //reads and copies map from file to array
{ se = 0; ie = 0; le = 0; ge = 0; ae = 0; te = 0;
  char ch;
  f2.open("lvl1.txt");
  for(int i=0; i<12; i++)
  {for(int j=0;j<12; j++)
  { f2.get(ch); e[i][j] = ch;}
  }e[1][1]=' ';
  e[a][b]='A';
  f2.close();
}
void buildm(char m[20][20],int b, int a)   //reads and copies map from file to array
{ sm = 0; im = 0; lm = 0; gm = 0; am = 0; tm = 0;
  char ch;
  f2.open("lvl2.txt");
  for(int i=0; i<20; i++)
  {for(int j=0;j<20; j++)
  { f2.get(ch); m[i][j] = ch;}
  }e[2][2]=' ';
  e[a][b]='A';
  f2.close();
}
void buildh(char h[24][24],int b, int a)   //reads and copies map from file to array
{ sh = 0; ih = 0; lh = 0; gh = 0; ah = 0; th = 0;
  char ch;
  f2.open("lvl3.txt");
  for(int i=0; i<24; i++)
  {for(int j=0;j<24; j++)
  { f2.get(ch); h[i][j] = ch;}
  }e[1][3]=' ';
  e[a][b]='A';
  f2.close();
}




void repaire(char e[12][12])
{for(int i=0;i<12;i++)
 {e[i][0]='#';
  e[0][i]='#';
  e[11][i]='#';
  e[i][11]='#';
  for(int j=0;j<12;j++)if(e[i][j]=='=')e[i][j]=' ';}
  e[11][11]='T';
  e[11][10]='I';
  e[11][9]='X';
  e[11][8]='E';
 }
void repairm(char m[20][20])
{for(int i=0;i<20;i++)
 {m[i][0]='#';
  m[0][i]='#';
  m[19][i]='#';
  m[i][19]='#';
  for(int j=0;j<20;j++)if(m[i][j]=='=')m[i][j]=' ';}
  m[19][19]='T';
  m[19][18]='I';
  m[19][17]='X';
  m[19][16]='E';
 }
void repairh(char h[24][24])
{ for(int i=0; i<24; i++)
  {h[i][0]='#';
  h[0][i]='#';
  h[23][i]='#';
  h[i][23]='#';
  for(int j=0;j<24;j++)if(h[i][j]=='=')h[i][j]=' ';}
  h[23][23]='T';
  h[23][22]='I';
  h[23][21]='X';
  h[23][20]='E';
 }


void printe(char e[12][12])   //prints level
{ clrscr();
  repaire(e);

  textcolor(11);
  if(countse!=0 && counti==0) textcolor(14);
  if(counti!=0) textcolor(10);

  for(int i=0; i<12; i++)
  {for(int j=0;j<12; j++)
  { cout<<e[i][j]<<" ";
	if(i==0 && j==11) {cout<<"  ";if(se==0 && ie==0 && le==0 && ge==0 && ae==0 && te==0 && unlocked==1)
						cout<<"<    LOCKED    >";
				      if(se==1) cout<<"<   Revolver   >";
				      if(ie==1) cout<<"< Invisibility >";
				      if(le==1) cout<<"<  Landmines   >";
				      if(ge==1) cout<<"< Machine gun  >";
				      if(ae==1) cout<<"<  Airstrike   >";
				      if(te==1) cout<<"<  Snare trap  >";
			  }
	if(i==3 && j==11) cout<<"       "<<lifee[0];
	if(i==6 && j==11) cout<<"       "<<lifee[1];
	if(i==9 && j==11) cout<<"       "<<lifee[2];

	if(j==11) cout<<endl;}
  }
  cout<<"Loot:"<<money;

  if(stimer==2) {cout<<"\n     Snared"; getch();}
  if(utimer!=0) {cout<<"\n     TRAPPED"; getch();}
}

void printm(char m[20][20])   //prints level
{ clrscr();
  repairm(m);

  textcolor(11);
  if(countsm!=0 && counti==0) textcolor(14);
  if(counti!=0) textcolor(10);

  for(int i=0; i<20; i++)
  {for(int j=0;j<20; j++)
  { cout<<m[i][j]<<" ";
	if(i==0 && j==19) {cout<<"  ";if(sm==0 && im==0 && lm==0 && gm==0 && am==0 && tm==0 && unlocked==1)
						cout<<"<    LOCKED    >";
				      if(sm==1) cout<<"<   Revolver   >";
				      if(im==1) cout<<"< Invisibility >";
				      if(lm==1) cout<<"<  Landmines   >";
				      if(gm==1) cout<<"< Machine gun  >";
				      if(am==1) cout<<"<  Airstrike   >";
				      if(tm==1) cout<<"<  Snare trap  >";
			  }
	if(i==3 && j==19) cout<<"     "<<lifem[0];
	if(i==6 && j==19) cout<<"     "<<lifem[1];
	if(i==9 && j==19) cout<<"     "<<lifem[2];
	if(i==12 && j==19) cout<<"     "<<lifem[3];
	if(i==15 && j==19) cout<<"     "<<lifem[4];
	if(i==18 && j==19) cout<<"     "<<lifem[5];

	if(j==19) cout<<endl;}
  }
  cout<<"Loot:"<<money;

  if(stimer==2) {cout<<"\n     Snared"; getch();}
  if(utimer!=0) {cout<<"\n     TRAPPED"; getch();}
}

void printh(char h[24][24])   //prints level
{ clrscr();
  repairh(h);

  textcolor(11);
  if(countsh!=0 && counti==0) textcolor(14);
  if(counti!=0) textcolor(10);

  for(int i=0; i<24; i++)
  {for(int j=0;j<24; j++)
  { cout<<h[i][j]<<" ";

	if(i==1 && j==23) {cout<<"   "<<lifeh[0];
			   cout<<"   ";if(sh==0 && ih==0 && lh==0 && gh==0 && ah==0 && th==0 && unlocked==1)
						 cout<<"<    LOCKED    >";
				       if(sh==1) cout<<"<   Revolver   >";
				       if(ih==1) cout<<"< Invisibility >";
				       if(lh==1) cout<<"<  Landmines   >";
				       if(gh==1) cout<<"< Machine gun  >";
				       if(ah==1) cout<<"<  Airstrike   >";
				       if(th==1) cout<<"<  Snare trap  >";
			  }
	if(i==3 && j==23) cout<<"   "<<lifeh[1];
	if(i==5 && j==23) cout<<"   "<<lifeh[2];
	if(i==7 && j==23) cout<<"   "<<lifeh[3];
	if(i==9 && j==23) cout<<"   "<<lifeh[4];
	if(i==11 && j==23) cout<<"   "<<lifeh[5];
	if(i==13 && j==23) cout<<"   "<<lifeh[6];
	if(i==15 && j==23) cout<<"   "<<lifeh[7];
	if(i==17 && j==23) cout<<"   "<<lifeh[8];
	if(i==19 && j==23) cout<<"   "<<lifeh[9];
	if(i==21 && j==23) cout<<"   "<<lifeh[10];
	if(i==23 && j==23) cout<<"   "<<lifeh[11];

	if(j==23) cout<<endl;}
  }

  cout<<"Loot:"<<money;

  if(stimer==2) {cout<<"\n     Snared"; getch();}
  if(utimer!=0) {cout<<"\n     TRAPPED"; getch();}
}


//WEAPONS

void airstrike(int lvl)
{ r:
 clrscr();
 int y, x, flag = 0, speedkill = 0, flagn = 0, over = 0;
 cout<<"         Enter airstrike coordinates: \n";
 cout<<"\n            Y-coordinate: "; cin>>y;
 cout<<"\n            X-coordinate: "; cin>>x;
 cout<<"\n            Enter radius: "; cin>>arad;
 switch(lvl)
	{ case 1: {if(y<1 || y>10)
		  {flag = 1; cout<<"\n     INVALID Y-COORDINATE";
		  getch(); goto r;}

		  if(x<1 || x>10)
		  {flag = 1; cout<<"\n     INVALID X-COORDINATE";
		  getch(); goto r;}

		  if(arad<3)
		  {flag = 1; cout<<"\n     RADIUS TOO SMALL";
		   getch(); goto r;
		  }

		  if(flag==0)
			{ cout<<"          Commencing airstrike"; getch();

			  for(int i = y-arad; i<=y+arad; i++)
				{for(int j = x-arad; j<=x+arad; j++)
					{ if(e[i][j]=='A') over = 1;
					  if(e[i][j]=='x'||e[i][j]=='X')
						{++speedkill; flagn = 1;}
					  if(e[i][j]!='A') e[i][j] = '%';
					}
				}

			  printe(e); cout<<"     KABOOM";

			  if(flagn==1)
			  {cout<<"\n Kill count +"<<speedkill<<endl;
			  if(speedkill>1)
				{cout<<"\n Multiple fatality";
				 cout<<"\n Bonus +"<<speedkill-1<<"000 $";
				 money = money + (speedkill-1)*1000;
				 sound4();
				}
			  if(speedkill>6 && achievement[3]=='0')
			  {achievement[3] = '1'; nf = 1;}

			  }

			  if(over==1) gameover(3);

			  getch();
			  countse=1;
			}
			break;}

	  case 2:  {if(y<1 || y>18)
		  {flag = 1; cout<<"\n     INVALID Y-COORDINATE";
		  getch(); goto r;}

		  if(x<1 || x>18)
		  {flag = 1; cout<<"\n     INVALID X-COORDINATE";
		  getch(); goto r;}

		  if(arad<3)
		  {flag = 1; cout<<"\n     RADIUS TOO SMALL";
		   getch(); goto r;
		  }

		  if(flag==0)
			{ cout<<"          Commencing airstrike"; getch();

			  for(int i = y-arad; i<=y+arad; i++)
				{for(int j = x-arad; j<=x+arad; j++)
					{ if(m[i][j]=='A') over = 1;
					  if(m[i][j]=='x'||m[i][j]=='X')
						{++speedkill; flagn = 1;}
					  if(m[i][j]!='A') m[i][j] = '%';
					}
				}

			  printm(m); cout<<"     KABOOM";

			  if(flagn==1)
			  {cout<<"\n Kill count +"<<speedkill<<endl;
			  if(speedkill>1)
				{cout<<"\n Multiple fatality";
				 cout<<"\n Bonus +"<<speedkill-1<<"000 $";
				 money = money + (speedkill-1)*1000;
				 sound4();
				}
			  if(speedkill>6 && achievement[3]=='0')
			  {achievement[3] = '1'; nf = 1;}
			  }

			  if(over==1) gameover(3);

			  getch();
			  countsm=1 ;
			}
			break;}

	  case 3: {if(y<1 || y>22)
		  {flag = 1; cout<<"\n     INVALID Y-COORDINATE";
		  getch(); goto r;}

		  if(x<1 || x>22)
		  {flag = 1; cout<<"\n     INVALID X-COORDINATE";
		  getch(); goto r;}

		  if(arad<3)
		  {flag = 1; cout<<"\n     RADIUS TOO SMALL";
		   getch(); goto r;
		  }

		  if(flag==0)
			{ cout<<"          Commencing airstrike"; getch();

			  for(int i = y-arad; i<=y+arad; i++)
				{for(int j = x-arad; j<=x+arad; j++)
					{ if(h[i][j]=='A') over = 1;
					  if(h[i][j]=='x'||h[i][j]=='X')
						{++speedkill; flagn = 1;}
					  if(h[i][j]!='A') h[i][j] = '%';
					}
				}

			  printh(h); cout<<"     KABOOM";

			  if(flagn==1)
			  {cout<<"\n Kill count +"<<speedkill<<endl;
			  if(speedkill>1)
				{cout<<"\n Multiple fatality";
				 cout<<"\n Bonus +"<<speedkill-1<<"000 $";
				 money = money + (speedkill-1)*1000;
				 sound4();
				}
			  if(speedkill>6 && achievement[3]=='0')
			  {achievement[3] = '1'; nf = 1;}
			  }

			  if(over==1) gameover(3);

			  getch();
			  countsh=1;
			}
			break;}
	}

 getch();
}

void machinegun(int lvl, int I, int J, char ch)
{ int speedkill = 0, flagn = 0;
  switch(lvl)
	{ case 1: switch(ch)
			{ //up
			  case 'w': {

					if(ammo>0)
					{
					ammo--;
					for(int k = I-1; k>=I-srange; k--)
					{ if(e[k][J]=='x'||e[k][J]=='X')
					  {++speedkill; flagn=1;}
					  e[k][J] = '|';
					  if(e[k][J-1]=='x'||e[k][J-1]=='X')
					  {++speedkill; flagn=1;}
					  e[k][J-1] = '|';
					  if(e[k][J+1]=='x'||e[k][J+1]=='X')
					  {++speedkill; flagn=1;}
					  e[k][J+1] = '|';
					  countse=1;
					}
					}

					printe(e);
					if(ammo>=0) cout<<"     Ammo remaining: "<<ammo;

					if(flagn==1)
					{cout<<"\n Kill count +"<<speedkill;}
					if(speedkill>1)
					{cout<<"\n Multiple fatality";
					 cout<<"\n Bonus +"<<speedkill-1<<"000 $";
					 money = money + (speedkill-1)*1000;

					}
					sound5();
					getch();
					break;}

			  //down
			  case 's': {
					if(ammo>0)
					   { ammo--;
					   for(int k = I+1; k<=I+srange; k++)
					{ if(e[k][J]=='x'||e[k][J]=='X')
					  {++speedkill; flagn=1;}
					  e[k][J] = '|';
					  if(e[k][J-1]=='x'||e[k][J-1]=='X')
					  {++speedkill; flagn=1;}
					  e[k][J-1] = '|';
					  if(e[k][J+1]=='x'||e[k][J+1]=='X')
					  {++speedkill; flagn=1;}
					  e[k][J+1] = '|';
					  countse=1;
					}
					}

					printe(e);
					if(ammo>=0) cout<<"     Ammo remaining: "<<ammo;

					if(flagn==1)
					{cout<<"\n Kill count +"<<speedkill;}
					if(speedkill>1)
					{cout<<"\n Multiple fatality";
					 cout<<"\n Bonus +"<<speedkill-1<<"000 $";
					 money = money + (speedkill-1)*1000;

					}
					sound5();
					getch();
					break;}

			  //left
			  case 'a': { if(ammo>0)
					  { ammo--;
					  for(int k = J-1; k>=J-srange; k--)
					{ if(e[I][k]=='x'||e[I][k]=='X')
					  {++speedkill; flagn=1;}
					  e[I][k] = '-';
					  if(e[I-1][k]=='x'||e[I-1][k]=='X')
					  {++speedkill; flagn=1;}
					  e[I-1][k] = '-';
					  if(e[I+1][k]=='x'||e[I+1][k]=='X')
					  {++speedkill; flagn=1;}
					  e[I+1][k] = '-';
					  countse=1;
					}
					  }

					printe(e);
					if(ammo>=0) cout<<"     Ammo remaining: "<<ammo;

					if(flagn==1)
					{cout<<"\n Kill count +"<<speedkill;}
					if(speedkill>1)
					{cout<<"\n Multiple fatality";
					 cout<<"\n Bonus +"<<speedkill-1<<"000 $";
					 money = money + (speedkill-1)*1000;

					}
					sound5();
					getch();
					break;}

			  //right
			  case 'd': { if(ammo>0)
					  { ammo--;
					  for(int k = J+1; k<=J+srange; k++)
					{ if(e[I][k]=='x'||e[I][k]=='X')
					  {++speedkill; flagn=1;}
					  e[I][k] = '-';
					  if(e[I-1][k]=='x'||e[I-1][k]=='X')
					  {++speedkill; flagn=1;}
					  e[I-1][k] = '-';
					  if(e[I+1][k]=='x'||e[I+1][k]=='X')
					  {++speedkill; flagn=1;}
					  e[I+1][k] = '-';
					  countse=1;
					}
					  }

					printe(e);
					if(ammo>=0) cout<<"     Ammo remaining: "<<ammo;

					if(flagn==1)
					{cout<<"\n Kill count +"<<speedkill;}
					if(speedkill>1)
					{cout<<"\n Multiple fatality";
					 cout<<"\n Bonus +"<<speedkill-1<<"000 $";
					 money = money + (speedkill-1)*1000;

					}
					sound5();
					getch();
					break;}
			}
		  break;

	  case 2: switch(ch)
			{ //up
			  case 'w': { if(ammo>0)
					  { ammo--;
					  for(int k = I-1; k>=I-srange; k--)
					{ if(m[k][J]=='x'||m[k][J]=='X')
					  {++speedkill; flagn=1;}
					  m[k][J] = '|';
					  if(m[k][J-1]=='x'||m[k][J-1]=='X')
					  {++speedkill; flagn=1;}
					  m[k][J-1] = '|';
					  if(m[k][J+1]=='x'||m[k][J+1]=='X')
					  {++speedkill; flagn=1;}
					  m[k][J+1] = '|';
					  countsm=1;
					}
					  }
					printm(m);
					if(ammo>=0) cout<<"     Ammo remaining: "<<ammo;

					if(flagn==1)
					{cout<<"\n Kill count +"<<speedkill;}
					if(speedkill>1)
					{cout<<"\n Multiple fatality";
					 cout<<"\n Bonus +"<<speedkill-1<<"000 $";
					 money = money + (speedkill-1)*1000;

					}
					sound5();
					getch();
					break;}

			  //down
			  case 's': { if(ammo>0)
					  { ammo--;
					  for(int k = I+1; k<=I+srange; k++)
					{ if(m[k][J]=='x'||m[k][J]=='X')
					  {++speedkill; flagn=1;}
					  m[k][J] = '|';
					  if(m[k][J-1]=='x'||m[k][J-1]=='X')
					  {++speedkill; flagn=1;}
					  m[k][J-1] = '|';
					  if(m[k][J+1]=='x'||m[k][J+1]=='X')
					  {++speedkill; flagn=1;}
					  m[k][J+1] = '|';
					  countsm=1;
					}
					  }
					printm(m);
					if(ammo>=0) cout<<"     Ammo remaining: "<<ammo;

					if(flagn==1)
					{cout<<"\n Kill count +"<<speedkill;}
					if(speedkill>1)
					{cout<<"\n Multiple fatality";
					 cout<<"\n Bonus +"<<speedkill-1<<"000 $";
					 money = money + (speedkill-1)*1000;

					}
					sound5();
					getch();
					break;}

			  //left
			  case 'a': { if(ammo>0)
					  { ammo--;
					  for(int k = J-1; k>=J-srange; k--)
					{ if(m[I][k]=='x'|m[I][k]=='X')
					  {++speedkill; flagn=1;}
					  m[I][k] = '-';
					  if(m[I-1][k]=='x'|m[I-1][k]=='X')
					  {++speedkill; flagn=1;}
					  m[I-1][k] = '-';
					  if(m[I+1][k]=='x'|m[I+1][k]=='X')
					  {++speedkill; flagn=1;}
					  m[I+1][k] = '-';
					  countsm=1;
					}
					  }
					printm(m);
					if(ammo>=0) cout<<"     Ammo remaining: "<<ammo;

					if(flagn==1)
					{cout<<"\n Kill count +"<<speedkill;}
					if(speedkill>1)
					{cout<<"\n Multiple fatality";
					 cout<<"\n Bonus +"<<speedkill-1<<"000 $";
					 money = money + (speedkill-1)*1000;

					}
					sound5();
					getch();
					break;}

			  //right
			  case 'd': { if(ammo>0)
					  { ammo--;
					  for(int k = J+1; k<=J+srange; k++)
					{ if(m[I][k]=='x'||m[I][k]=='X')
					  {++speedkill; flagn=1;}
					  m[I][k] = '-';
					  if(m[I-1][k]=='x'|m[I-1][k]=='X')
					  {++speedkill; flagn=1;}
					  m[I-1][k] = '-';
					  if(m[I+1][k]=='x'|m[I+1][k]=='X')
					  {++speedkill; flagn=1;}
					  m[I+1][k] = '-';
					  countsm=1;
					}
					  }
					printm(m);

					if(ammo>=0) cout<<"     Ammo remaining: "<<ammo;

					if(flagn==1)
					{cout<<"\n Kill count +"<<speedkill;}
					if(speedkill>1)
					{cout<<"\n Multiple fatality";
					 cout<<"\n Bonus +"<<speedkill-1<<"000 $";
					 money = money + (speedkill-1)*1000;

					}
					sound5();
					getch();
					break;}


			}
		  break;


	  case 3: switch(ch)
			{ //up
			  case 'w': { if(ammo>0)
					  { ammo--;
					  for(int k = I-1; k>=I-srange; k--)
					{ if(h[k][J]=='x'||h[k][J]=='X')
					  {++speedkill; flagn=1;}
					  h[k][J] = '|';
					  if(h[k][J-1]=='x'||h[k][J-1]=='X')
					  {++speedkill; flagn=1;}
					  h[k][J-1] = '|';
					  if(h[k][J+1]=='x'||h[k][J+1]=='X')
					  {++speedkill; flagn=1;}
					  h[k][J+1] = '|';
					  countsh=1;
					}
					  }
					printh(h);
					if(ammo>=0) cout<<"     Ammo remaining: "<<ammo;

					if(flagn==1)
					{cout<<"\n Kill count +"<<speedkill;}
					if(speedkill>1)
					{cout<<"\n Multiple fatality";
					 cout<<"\n Bonus +"<<speedkill-1<<"000 $";
					 money = money + (speedkill-1)*1000;

					}
					sound5();
					getch();
					break;}

			  //down
			  case 's': { if(ammo>0)
					  { ammo--;
					  for(int k = I+1; k<=I+srange; k++)
					{ if(h[k][J]=='x'||h[k][J]=='X')
					  {++speedkill; flagn=1;}
					  h[k][J] = '|';
					  if(h[k][J-1]=='x'||h[k][J-1]=='X')
					  {++speedkill; flagn=1;}
					  h[k][J-1] = '|';
					  if(h[k][J+1]=='x'||h[k][J+1]=='X')
					  {++speedkill; flagn=1;}
					  h[k][J+1] = '|';
					  countsh=1;
					}
					  }
					printh(h);
					if(ammo>=0) cout<<"     Ammo remaining: "<<ammo;

					if(flagn==1)
					{cout<<"\n Kill count +"<<speedkill;}
					if(speedkill>1)
					{cout<<"\n Multiple fatality";
					 cout<<"\n Bonus +"<<speedkill-1<<"000 $";
					 money = money + (speedkill-1)*1000;

					}
					sound5();
					getch();
					break;}

			  //left
			  case 'a': { if(ammo>0)
					  { ammo--;
					  for(int k = J-1; k>=J-srange; k--)
					{ if(h[I][k]=='x'||h[I][k]=='X')
					  {++speedkill; flagn=1;}
					  h[I][k] = '-';
					  if(h[I-1][k]=='x'||h[I-1][k]=='X')
					  {++speedkill; flagn=1;}
					  h[I-1][k] = '-';
					  if(h[I+1][k]=='x'||h[I+1][k]=='X')
					  {++speedkill; flagn=1;}
					  h[I+1][k] = '-';
					  countsh=1;
					}
					  }
					printh(h);
					if(ammo>=0) cout<<"     Ammo remaining: "<<ammo;

					if(flagn==1)
					{cout<<"\n Kill count +"<<speedkill;}
					if(speedkill>1)
					{cout<<"\n Multiple fatality";
					 cout<<"\n Bonus +"<<speedkill-1<<"000 $";
					 money = money + (speedkill-1)*1000;

					}
					sound5();
					getch();
					break;}

			  //right
			  case 'd': { if(ammo>0)
					  { ammo--;
					  for(int k = J+1; k<=J+srange; k++)
					{ if(h[I][k]=='x'||h[I][k]=='X')
					  {++speedkill; flagn=1;}
					  h[I][k] = '-';
					  if(h[I-1][k]=='x'||h[I-1][k]=='X')
					  {++speedkill; flagn=1;}
					  h[I-1][k] = '-';
					  if(h[I+1][k]=='x'||h[I+1][k]=='X')
					  {++speedkill; flagn=1;}
					  h[I+1][k] = '-';
					  countsh=1;
					}
					  }
					printh(h);
					if(ammo>=0) cout<<"     Ammo remaining: "<<ammo;

					if(flagn==1)
					{cout<<"\n Kill count +"<<speedkill;}
					if(speedkill>1)
					{cout<<"\n Multiple fatality";
					 cout<<"\n Bonus +"<<speedkill-1<<"000 $";
					 money = money + (speedkill-1)*1000;

					}
					sound5();
					getch();
					break;}

			}
		  break;
	}
}


void revolver(int lvl, int I, int J, int num)
{ int f = 0;
  switch(lvl)
	{case 1:
	if(e[I][J-1]=='-'||e[I][J+1]=='-'||e[I-1][J]=='|'||e[I+1][J]=='|')
	f = 1;

	if(se==1&&bullets>0&&f==0)
		{if(num==97)  //left
			{
			bullets = bullets - 1;

			int flagn=0, speedkill=0;

			for(int g = J-1; e[I][g]!='#'; g--)
			{if(e[I][g]=='x'||e[I][g]=='X')
			{e[I][g] = '$'; ++::killcount;
			++speedkill; flagn = 1;}
			else e[I][g] = '-';
			}

			printe(e); cout<<"     Ammo remaining: "<<bullets<<"\n";

			if(flagn==1) cout<<"     Kill count +"<<speedkill;
			levelkills+=speedkill;
			if(speedkill>=2)
			{cout<<endl<<"Multiple fatality";
			cout<<"\n Bonus +"<<speedkill - 1<<"000 $";
			::money = ::money + (speedkill-1)*1000;

			if (speedkill>=3){achievement[2]='1';nf=1;}}

			sound8();
			getch();

			}

		if(num==100)  //right
			{
			bullets = bullets - 1;

			int flagn=0, speedkill=0;

			for(int g = J+1; e[I][g]!='#'; g++)
			{if(e[I][g]=='x'||e[I][g]=='X')
			{e[I][g] = '$'; ++::killcount;
			++speedkill; flagn = 1;}
			 else e[I][g] = '-';
			}

			printe(e);  cout<<"     Ammo remaining: "<<bullets<<"\n";

			if(flagn==1) cout<<"     Kill count +"<<speedkill;
			levelkills+=speedkill;
			if(speedkill>=2)
			{cout<<endl<<"Multiple fatality"<<endl<<"Bonus +"<<speedkill - 1<<"000 $";
			::money = ::money + (speedkill-1)*1000;

			if (speedkill>=3){achievement[2]='1';nf=1;}}

			sound8();
			getch();

			}

		if(num==119) //up
			{
			bullets = bullets - 1;

			int flagn=0, speedkill=0;

			for(int g = I-1; e[g][J]!='#'; g--)
			{if(e[g][J]=='x'||e[g][J]=='X')
			{e[g][J] = '$'; ++::killcount;
			++speedkill; flagn = 1;}
			else e[g][J] = '|';
			}

			printe(e); cout<<"     Ammo remaining: "<<bullets<<"\n";

			if(flagn==1) cout<<"     Kill count +"<<speedkill;
			levelkills+=speedkill;
			if(speedkill>=2)
			{cout<<endl<<"Multiple fatality"<<endl<<"Bonus +"<<speedkill - 1<<"000 $";
				 ::money = ::money + (speedkill-1)*1000;

				 if (speedkill>=3){achievement[2]='1';nf=1;}}

				sound8();
				getch();
			}

		if(num==115) //down
			{
			bullets = bullets - 1;

			int flagn=0, speedkill=0;
			  for(int g = I+1; e[g][J]!='#'; g++)
				{if(e[g][J]=='x'||e[g][J]=='X')
				{e[g][J] = '$'; ++::killcount;
				++speedkill; flagn = 1;}
				 else e[g][J] = '|'; }

				 printe(e); cout<<"     Ammo remaining: "<<bullets<<"\n";

				if(flagn==1) cout<<"     Kill count +"<<speedkill;
				levelkills+=speedkill;
				if(speedkill>=2)
				{cout<<endl<<"Multiple fatality"<<endl<<"Bonus +"<<speedkill - 1<<"000 $";
				 ::money = ::money + (speedkill-1)*1000;

				 if (speedkill>=3){achievement[2]='1';nf=1;}}

				sound8();
				getch();

			 }
			 break;

	 case 2:
	if(m[I][J-1]=='-'||m[I][J+1]=='-'||m[I-1][J]=='|'||m[I+1][J]=='|')
	f = 1;

	if(sm==1&&bullets>0&&f==0)
		{

		if(num==97)  //left
			{
			bullets = bullets - 1;

			int flagn=0, speedkill=0;

			for(int g = J-1; m[I][g]!='#'; g--)
			{if(m[I][g]=='x'||m[I][g]=='X')
			{m[I][g] = '$'; ++::killcount;
			++speedkill; flagn = 1;}
			else m[I][g] = '-'; }

			printm(m); cout<<"     Ammo remaining: "<<bullets<<"\n";

			if(flagn==1) cout<<"     Kill count +"<<speedkill;
			levelkills+=speedkill;
			if(speedkill>=2)
				{cout<<endl<<"Multiple fatality"<<endl<<"Bonus +"<<speedkill - 1<<"000 $";
				 ::money = ::money + (speedkill-1)*1000;if (speedkill>=3){achievement[2]='1';nf=1;}
				 }

				 sound8();
				 getch();
			}

		  if(num==100)  //right
			  {
			  bullets = bullets - 1;

			  int flagn=0, speedkill=0;

				for(int g = J+1; m[I][g]!='#'; g++)
				{if(m[I][g]=='x'||m[I][g]=='X')
				{m[I][g] = '$'; ++::killcount;
				++speedkill; flagn = 1;}
				 else m[I][g] = '-'; }

				printm(m); cout<<"     Ammo remaining: "<<bullets<<"\n";

				if(flagn==1) cout<<"     Kill count +"<<speedkill;
				levelkills+=speedkill;
				if(speedkill>=2)
				{cout<<endl<<"Multiple fatality"<<endl<<"Bonus +"<<speedkill - 1<<"000 $";
				 ::money = ::money + (speedkill-1)*1000;if (speedkill>=3){achievement[2]='1';nf=1;}}

				 sound8();
				 getch();
			  }

		if(num==119) //up
			{
			bullets = bullets - 1;

			int flagn=0, speedkill=0;

				for(int g = I-1; m[g][J]!='#'; g--)
				{if(m[g][J]=='x'||m[g][J]=='X')
				{m[g][J] = '$'; ++::killcount;
				++speedkill; flagn = 1;}
				 else m[g][J] = '|'; }

				printm(m); cout<<"     Ammo remaining: "<<bullets<<"\n";

				if(flagn==1) cout<<"     Kill count +"<<speedkill;
				levelkills+=speedkill;
				if(speedkill>=2)
				{cout<<endl<<"Multiple fatality"<<endl<<"Bonus +"<<speedkill - 1<<"000 $";
				 ::money = ::money + (speedkill-1)*1000;if (speedkill>=3){achievement[2]='1';nf=1;}}

				 sound8();
				 getch();
			}

			if(num==115) //down
				{
				bullets = bullets - 1;

				int flagn=0, speedkill=0;

				for(int g = I+1; m[g][J]!='#'; g++)
				{if(m[g][J]=='x'||m[g][J]=='X')
				{m[g][J] = '$'; ++::killcount;
				++speedkill; flagn = 1;}
				 else m[g][J] = '|'; }

				printm(m); cout<<"     Ammo remaining: "<<bullets<<"\n";

				if(flagn==1) cout<<"     Kill count +"<<speedkill;
				levelkills+=speedkill;
				if(speedkill>=2)
				{cout<<endl<<"Multiple fatality"<<endl<<"Bonus +"<<speedkill - 1<<"000 $";
				 ::money = ::money + (speedkill-1)*1000;if (speedkill>=3){achievement[2]='1';nf=1;}}

				 sound8();
				 getch();

				}

		  }
		  break;
	case 3:

	if(h[I][J-1]=='-'||h[I][J+1]=='-'||h[I-1][J]=='|'||h[I+1][J]=='|')
	f = 1;

	if(sh==1&&bullets>0&&f==0)

		{if(num==97)  //left
			{
			bullets = bullets - 1;

			int flagn=0, speedkill=0;

			for(int g = J-1; h[I][g]!='#'; g--)
			{if(h[I][g]=='x'||h[I][g]=='X')
			{h[I][g] = '$'; ++::killcount;
			++speedkill; flagn = 1;}
			else h[I][g] = '-';
			}

			printh(h); cout<<"     Ammo remaining: "<<bullets<<"\n";

			if(flagn==1) cout<<"     Kill count +"<<speedkill;
			levelkills+=speedkill;
			if(speedkill>=2)
			{cout<<endl<<"Multiple fatality"<<endl<<"Bonus +"<<speedkill - 1<<"000 $";
			::money = ::money + (speedkill-1)*1000;

			if (speedkill>=3){achievement[2]='1';nf=1;}}

			sound8();
			getch();

			}

		if(num==100)  //right
			{
			bullets = bullets - 1;

			int flagn=0, speedkill=0;

			for(int g = J+1; h[I][g]!='#'; g++)
			{if(h[I][g]=='x'||h[I][g]=='X')
			{h[I][g] = '$'; ++::killcount;
			++speedkill; flagn = 1;}
			 else h[I][g] = '-';
			}

			printh(h); cout<<"     Ammo remaining: "<<bullets<<"\n";

			if(flagn==1) cout<<"     Kill count +"<<speedkill;
			levelkills+=speedkill;
			if(speedkill>=2)
			{cout<<endl<<"Multiple fatality"<<endl<<"Bonus +"<<speedkill - 1<<"000 $";
			::money = ::money + (speedkill-1)*1000;

			if (speedkill>=3){achievement[2]='1';nf=1;}}

			sound8();
			getch();

			}

		if(num==119) //up
			{
			bullets = bullets - 1;

			int flagn=0, speedkill=0;

			for(int g = I-1; h[g][J]!='#'; g--)
			{if(h[g][J]=='x'||h[g][J]=='X')
			{h[g][J] = '$'; ++::killcount;
			++speedkill; flagn = 1;}
			else h[g][J] = '|';
			}

			printh(h); cout<<"     Ammo remaining: "<<bullets<<"\n";

			if(flagn==1) cout<<"     Kill count +"<<speedkill;
			levelkills+=speedkill;
			if(speedkill>=2)
			{cout<<endl<<"Multiple fatality"<<endl<<"Bonus +"<<speedkill - 1<<"000 $";
				 ::money = ::money + (speedkill-1)*1000;

				 if (speedkill>=3){achievement[2]='1';nf=1;}}

				sound8();
				getch();
			}

		if(num==115) //down
			{
			bullets = bullets - 1;

			int flagn=0, speedkill=0;
			  for(int g = I+1; h[g][J]!='#'; g++)
				{if(h[g][J]=='x'||h[g][J]=='X')
				{h[g][J] = '$'; ++::killcount;
				++speedkill; flagn = 1;}
				 else h[g][J] = '|'; }

				 printh(h); cout<<"     Ammo remaining: "<<bullets<<"\n";

				if(flagn==1) cout<<endl<<"     Kill count +"<<speedkill;
				levelkills+=speedkill;
				if(speedkill>=2)
				{cout<<endl<<"Multiple fatality"<<endl<<"Bonus +"<<speedkill - 1<<"000 $";
				 ::money = ::money + (speedkill-1)*1000;

				 if (speedkill>=3){achievement[2]='1';nf=1;}}

				sound8();
				getch();

			 }


		}

	}

}
}




void landmines(int lvl, int y, int x)
{ int speedkill=0;
  switch(lvl)
	{ case 1:{for(int i = y-lrad; i<=y+lrad; i++)
		  {for(int j = x-lrad;j<=x+lrad; j++)
		    {if(e[i][j]=='x'||e[i][j]=='X') ++speedkill;
		     if(e[i][j]!='#') e[i][j] = '%';
		    }
		  }
		  printe(e);cout<<"      BOOM";

		  if(speedkill>0)
		  cout<<"\n Kill count +"<<speedkill;

		  if(speedkill>1)
			{money = money + ((speedkill-1)*1000);
			 cout<<"\n Multiple fatality";
			 cout<<"\n Bonus +"<<speedkill - 1<<"000 $";
			}
		  sound4();
		  getch();
		  break;
		 }

	  case 2:{for(int i = y-lrad; i<=y+lrad; i++)
		  {for(int j = x-lrad; j<=x+lrad; j++)
		    {if(m[i][j]=='x'||m[i][j]=='X') ++speedkill;
		     if(m[i][j]!='#') m[i][j] = '%';
		    }
		  }
		  printm(m);cout<<"      BOOM";

		  if(speedkill>0)
		  cout<<"\n Kill count +"<<speedkill;

		  if(speedkill>1)
			{money = money + ((speedkill-1)*1000);
			 cout<<"\n Multiple fatality";
			 cout<<"\n Bonus +"<<speedkill - 1<<"000 $";
			}
		  sound4();
		  getch();
		  break;
		 }
	  case 3:{for(int i = y-lrad; i<=y+lrad; i++)
		  {for(int j = x-lrad; j<=x+lrad; j++)
		   {if(h[i][j]=='x'||h[i][j]=='X') ++speedkill;
		    if(h[i][j]!='#') h[i][j] = '%';}
		  }
		  printh(h);cout<<"      BOOM";

		  if(speedkill>0)
		  cout<<"\n Kill count +"<<speedkill;

		  if(speedkill>1)
			{money = money + ((speedkill-1)*1000);
			 cout<<"\n Multiple fatality";
			 cout<<"\n Bonus +"<<speedkill - 1<<"000 $";
			}
		  sound4();
		  getch();

		  break;
		 }
	}
}





void eshoot(int lvl, int I, int J, int y, int x)
{
  int k, l;
  switch(lvl)
	{ case 1:

 if(::countse==6)

 {::countse = 0;
  for(k = 0; k<12; k++)
 {for(l = 0; l<12; l++)
 { if(e[k][l]=='+') e[k][l] = ' ';}}
 }

 if(::countse!=0)
 {
  if(countse>2)
  {

  if((y>=I)&&(x>=J)&&(y-I>x-J))
  { for(int i=y-1; e[i][x]!='#'; i--)
  {if(e[i][x]!='A' && e[i][x]!='x' && e[i][x]!='X') e[i][x] = '+';} printe(e);}  //up1

  if((y>=I)&&(x<=J)&&(y-I>J-x))                  //up2
  { for(int i=y-1; e[i][x]!='#'; i--)
  {if(e[i][x]!='A' && e[i][x]!='x' && e[i][x]!='X') e[i][x] = '+';} printe(e);}

  if((y<=I)&&(x>=J)&&(I-y>x-J))
  { for(int i=y+1; e[i][x]!='#'; i++)
  {if(e[i][x]!='A' && e[i][x]!='x' && e[i][x]!='X') e[i][x] = '+';} printe(e);}  //down1

  if((y<=I)&&(x<=J)&&(I-y>J-x))
  { for(int i=y+1; e[i][x]!='#'; i++)
  {if(e[i][x]!='A' && e[i][x]!='x' && e[i][x]!='X') e[i][x] = '+';} printe(e);}  //down2

  if((y>=I)&&(x>=J)&&(y-I<x-J))
  { for(int i=x-1; e[y][i]!='#'; i--)
  {if(e[y][i]!='A' && e[y][i]!='x' && e[y][i]!='X') e[y][i] = '+';} printe(e);}  //left1

  if((y<=I)&&(x>=J)&&(I-y<x-J))
  { for(int i=x-1; e[y][i]!='#'; i--)
  {if(e[y][i]!='A' && e[y][i]!='x' && e[y][i]!='X') e[y][i] = '+';} printe(e);}  //left2

  if((y>=I)&&(x<=J)&&(y-I<J-x))
  { for(int i=x+1; e[y][i]!='#'; i++)
  {if(e[y][i]!='A' && e[y][i]!='x' && e[y][i]!='X') e[y][i] = '+';} printe(e);}  //right1

  if((y<=I)&&(x<=J)&&(I-y>J-x))
  { for(int i=x+1; e[y][i]!='#'; i++)
  {if(e[y][i]!='A' && e[y][i]!='x' && e[y][i]!='X') e[y][i] = '+';} printe(e);}  //right2


  }
 }


	  case 2:

 if(::countsm==11)

 {::countsm = 0;
  for(k = 0; k<20; k++)
 {for(l = 0; l<20; l++)
 { if(m[k][l]=='+') m[k][l] = ' ';}}
 }

 if(::countsm>2)
 {
  if((y>=I)&&(x>=J)&&(y-I>x-J))
  { for(int i=y-1; m[i][x]!='#'; i--)
  {if(m[i][x]!='A' && m[i][x]!='x' && m[i][x]!='X') m[i][x] = '+';} printm(m);}  //up1

  if((y>=I)&&(x<=J)&&(y-I>J-x))                                                      //up2
  { for(int i=y-1; m[i][x]!='#'; i--)
  {if(m[i][x]!='A' && m[i][x]!='x' && m[i][x]!='X') m[i][x] = '+';} printm(m);}

  if((y<=I)&&(x>=J)&&(I-y>x-J))
  { for(int i=y+1; m[i][x]!='#'; i++)
  {if(m[i][x]!='A' && m[i][x]!='x' && m[i][x]!='X') m[i][x] = '+';} printm(m);}  //down1

  if((y<=I)&&(x<=J)&&(I-y>J-x))
  { for(int i=y+1; m[i][x]!='#'; i++)
  {if(m[i][x]!='A' && m[i][x]!='x' && m[i][x]!='X') m[i][x] = '+';} printm(m);}  //down2

  if((y>=I)&&(x>=J)&&(y-I<x-J))
  { for(int i=x-1; m[y][i]!='#'; i--)
  {if(m[y][i]!='A' && m[y][i]!='x' && m[y][i]!='X') m[y][i] = '+';} printm(m);}  //left1

  if((y<=I)&&(x>=J)&&(I-y<x-J))
  { for(int i=x-1; m[y][i]!='#'; i--)
  {if(m[y][i]!='A' && m[y][i]!='x' && m[y][i]!='X') m[y][i] = '+';} printm(m);}  //left2

  if((y>=I)&&(x<=J)&&(y-I<J-x))
  { for(int i=x+1; m[y][i]!='#'; i++)
  {if(m[y][i]!='A' && m[y][i]!='x' && m[y][i]!='X') m[y][i] = '+';} printm(m);}  //right1

  if((y<=I)&&(x<=J)&&(I-y>J-x))
  { for(int i=x+1; m[y][i]!='#'; i++)
  {if(m[y][i]!='A' && m[y][i]!='x' && m[y][i]!='X') m[y][i] = '+';} printm(m);}  //right2



 }



	  case 3:

  if(::countsh==16)

  {::countsh = 0;
   for(k = 0; k<24; k++)
 {for(l = 0; l<24; l++)
 { if(h[k][l]=='+') h[k][l] = ' ';}}
  }

 if(::countsh>2)
 {
  if((y>=I)&&(x>=J)&&(y-I>x-J))
  { for(int i=y-1; h[i][x]!='#'; i--)
  {if(h[i][x]!='A' && h[i][x]!='x' && h[i][x]!='X') h[i][x] = '+';} printh(h);}  //up1

  if((y>=I)&&(x<=J)&&(y-I>J-x))                                                       //up2
  { for(int i=y-1; h[i][x]!='#'; i--)
  {if(h[i][x]!='A' && h[i][x]!='x' && h[i][x]!='X') h[i][x] = '=';} printh(h);}

  if((y<=I)&&(x>=J)&&(I-y>x-J))
  { for(int i=y+1; h[i][x]!='#'; i++)
  {if(h[i][x]!='A' && h[i][x]!='x' && h[i][x]!='X') h[i][x] = '+';} printh(h);}  //down1

  if((y<=I)&&(x<=J)&&(I-y>J-x))
  { for(int i=y+1; h[i][x]!='#'; i++)
  {if(h[i][x]!='A' && h[i][x]!='x' && h[i][x]!='X') h[i][x] = '+';} printh(h);}  //down2

  if((y>=I)&&(x>=J)&&(y-I<x-J))
  { for(int i=x-1; h[y][i]!='#'; i--)
  {if(h[y][i]!='A' && h[y][i]!='x' && h[y][i]!='X') h[y][i] = '+';} printh(h);}  //left1

  if((y<=I)&&(x>=J)&&(I-y<x-J))
  { for(int i=x-1; h[y][i]!='#'; i--)
  {if(h[y][i]!='A' && h[y][i]!='x' && h[y][i]!='X') h[y][i] = '+';} printh(h);}  //left2

  if((y>=I)&&(x<=J)&&(y-I<J-x))
  { for(int i=x+1; h[y][i]!='#'; i++)
  {if(h[y][i]!='A' && h[y][i]!='x' && h[y][i]!='X') h[y][i] = '+';} printh(h);}  //right1

  if((y<=I)&&(x<=J)&&(I-y>J-x))
  { for(int i=x+1; h[y][i]!='#'; i++)
  {if(h[y][i]!='A' && h[y][i]!='x' && h[y][i]!='X') h[y][i] = '+';} printh(h);}  //right2


 }

	}


}




void horize(char e[12][12], int y, int xi, int xf, int i2, char ch, int I, int J, int life)
{int x=0, xa = 0;

 for(int j=xi; j<=xf; j++)
 { if(e[y][j]=='x') x = j;
   if(e[y][j]=='A') xa = j;
 } //locate enemy pos

 if(x==0) lifee[life] = 0;
 if(x==0 || lifee[life]<=0) {::e1[i2] = 0; lifee[life] = 0;}

 randomize(); tdamage = random(5);
 if(e1[i2]!=0) eshoot(1, I, J, y, x);
 if(e1[i2]==2) lifee[life]-=tdamage;

 if((x==xi)&&(::e1[i2]==-1)) ::e1[i2] = 1;  //update m1
 if((x==xf)&&(::e1[i2]==1))  ::e1[i2] = -1;

 char next = e[y][x+::e1[i2]];

 if(((xa!=0)&&(e1[i2]==1)&&(xa>x))||((xa!=0)&&(e1[i2]==-1)&&(xa<x)))
 {spotted(); ::countse = 1;}

 if(((xa!=0)&&(e1[i2]==1)&&(x - xa == 1)&&(ch== ' '))||((xa!=0)&&(e1[i2]==-1)&&(x - xa == -1)&&(ch== ' ')))
 {
  e[y][x] = ' ';
 lifee[life] = 0;

 printe(e);
 cout<<"\t\tStealth takedown"; sound3(); getch();}

 if(e[y][x+::e1[i2]]=='*') {landmines(1, y, x+::e1[i2]); e1[i2] = 0;}


 if((e[y][x+::e1[i2]]!='A' && e1[i2]>=-1 && e1[i2]<=1)&&(e[y][x+::e1[i2]]!='@' && e1[i2]>=-1 && e1[i2]<=1))
	{e[y][x + ::e1[i2]] = 'x'; e[y][x] = ' ';}
 x = x + ::e1[i2];

  if(next=='&') {e1[i2] = 2; stimer = 1;}

}

void horizm(char m[20][20], int y, int xi, int xf, int i2, char ch, int I, int J, int life)
{int x=0, xa = 0;

 for(int j=xi; j<=xf; j++)
 { if(m[y][j]=='x') x = j;
   if(m[y][j]=='A') xa = j;
 } //locate enemy pos

 if(x==0) lifem[life] = 0;
 if(x==0 || lifem[life]<=0) {::m1[i2] = 0;lifem[life]=0;}

 randomize(); tdamage = random(5);
 if(m1[i2]!=0) eshoot(2, I, J, y, x);
 if(m1[i2]==2) lifem[life]-=tdamage;

 if((x==xi)&&(::m1[i2]==-1)) ::m1[i2] = 1;  //update m1
 if((x==xf)&&(::m1[i2]==1))  ::m1[i2] = -1;

 char next = m[y][x+::m1[i2]];

 if(((xa!=0)&&(m1[i2]==1)&&(xa>x))||((xa!=0)&&(m1[i2]==-1)&&(xa<x)))
 {spotted(); ::countsm = 1;}

 if(((xa!=0)&&(m1[i2]==1)&&(x - xa == 1)&&(ch== ' '))||((xa!=0)&&(m1[i2]==-1)&&(x - xa == -1)&&(ch== ' ')))
 {m[y][x] = ' ';
 lifem[life] = 0;
 printm(m);
 cout<<"\t\tStealth takedown";sound3();  getch();}

 if(m[y][x+::m1[i2]]=='*') {landmines(2, y, x+::m1[i2]); m1[i2] = 0;}



 if((m[y][x+::m1[i2]]!='A'  && m1[i2]>=-1 && m1[i2]<=1)&&(m[y][x+::m1[i2]]!='@' && m1[i2]>=-1 && m1[i2]<=1))
 {m[y][x + ::m1[i2]] = 'x'; m[y][x] = ' ';}
 x = x + ::m1[i2];

 if(next=='&') {m1[i2] = 2; stimer = 1;}
}

void horizh(char h[24][24], int y, int xi, int xf, int i2, char ch, int I, int J, int life)
{int x=0, xa = 0;

 for(int j=xi; j<=xf; j++)
 { if(h[y][j]=='x') x = j;
   if(h[y][j]=='A') xa = j;
 } //locate enemy pos

 if(x==0) lifeh[life] = 0;
 if(x==0 || lifeh[life]<=0){::h1[i2] = 0;lifeh[life]=0;}

 randomize(); tdamage = random(5);
 if(h1[i2]!=0) eshoot(3, I, J, y, x);
 if(h1[i2]==2) lifeh[life]-=tdamage;

 if((x==xi)&&(::h1[i2]==-1)) ::h1[i2] = 1;  //update h1
 if((x==xf)&&(::h1[i2]==1))  ::h1[i2] = -1;

 char next = h[y][x+::h1[i2]];

 if(((xa!=0)&&(h1[i2]==1)&&(xa>x))||((xa!=0)&&(h1[i2]==-1)&&(xa<x)))
 {spotted(); ::countsh = 1;}

 if(((xa!=0)&&(h1[i2]==1)&&(x - xa == 1)&&(ch== ' '))||((xa!=0)&&(h1[i2]==-1)&&(x - xa == -1)&&(ch== ' ')))
 {h[y][x] = ' ';
 lifeh[life] = 0;
 printh(h);
 cout<<"\t\tStealth takedown"; sound3(); getch();}

 if(h[y][x+::h1[i2]]=='*') {landmines(3, y, x+::h1[i2]); h1[i2] = 0;}


 if((h[y][x+::h1[i2]]!='A' && h1[i2]>=-1 && h1[i2]<=1)&&(h[y][x+::h1[i2]]!='@' && h1[i2]>=-1 && h1[i2]<=1))
 {h[y][x + ::h1[i2]] = 'x'; h[y][x] = ' ';}
 x = x + ::h1[i2];

 if(next=='&') {h1[i2] = 2; stimer = 1;}
}






void verte(char e[12][12], int x, int yi, int yf, int i1, char ch, int I, int J, int life)
{int y=0,ya=0;

 for(int i=yi; i<=yf; i++)
 { if(e[i][x]=='x') y = i;
   if(e[i][x]=='A') ya = i;
 } //locate enemy pos

 if(y==0) lifee[life] = 0;
 if(y==0 || lifee[life]<=0) {::e2[i1] = 0; lifee[life]=0;}

 randomize(); tdamage = random(5);
 if(e2[i1]!=0) eshoot(1, I, J, y, x);
 if(e2[i1]==2) lifee[life]-=tdamage;

 if((y==yi)&&(::e2[i1]==-1))  ::e2[i1] = 1;  //update e1
 if((y==yf)&&(::e2[i1]==1))  ::e2[i1] = -1;

 char next = e[y+::e2[i1]][x];

 if(((ya!=0)&&(e2[i1]==1)&&(ya>y))||((ya!=0)&&(e2[i1]==-1)&&(ya<y)))
 {spotted(); ::countse = 1;}

 if(((ya!=0)&&(e2[i1]==1)&&(y - ya == 1)&&(ch==' '))||((ya!=0)&&(e2[i1]==-1)&&(y - ya == -1)&&(ch==' ')))
 {e[y][x] = ' '; lifee[life] = 0;
 lifee[life] = 0;
 printe(e);
 cout<<"\t\tStealth takedown"; sound3(); getch();}

 if(e[y+::e2[i1]][x]=='*') {landmines(1, y+::e2[i1], x); e2[i1] = 0;}



 if((e[y+::e2[i1]][x]!='A'&& e2[i1]>=-1 && e2[i1]<=1)||(e[y+::e2[i1]][x]!='@'&& e2[i1]>=-1 && e2[i1]<=1))
	{e[y+::e2[i1]][x] = 'x'; e[y][x] = ' ';}
 y = y + ::e2[i1];

 if(next=='&') {e2[i1] = 2; stimer = 1;}

}


void vertm(char m[20][20], int x, int yi, int yf, int i1, char ch, int I, int J, int life)
{int y=0,ya=0;

 for(int i=yi; i<=yf; i++)
 { if(m[i][x]=='x') y = i;
   if(m[i][x]=='A') ya = i;
 } //locate enemy pos

 if(y==0) lifem[life] = 0;
 if(y==0 || lifem[life]<=0) {::m2[i1] = 0; lifem[life]=0;}

 randomize(); tdamage = random(5);
 if(m2[i1]!=0) eshoot(2, I, J, y, x);
 if(m2[i1]==2) lifem[life]-=tdamage;

 if((y==yi)&&(::m2[i1]==-1)) ::m2[i1] = 1;  //update m1
 if((y==yf)&&(::m2[i1]==1))  ::m2[i1] = -1;

 char next = m[y+::m2[i1]][x];

 if(((ya!=0)&&(m2[i1]==1)&&(ya>y))||((ya!=0)&&(m2[i1]==-1)&&(ya<y)))
 {spotted(); ::countsm = 1;}

 if(((ya!=0)&&(m2[i1]==1)&&(y - ya == 1)&&(ch==' '))||((ya!=0)&&(m2[i1]==-1)&&(y - ya == -1)&&(ch==' ')))
 {m[y][x] = ' ';
 lifem[life] = 0;
 printm(m);
 cout<<"\t\tStealth takedown"; sound3(); getch();}

  if(m[y+::m2[i1]][x]=='*') {landmines(2, y+::m2[i1], x); m2[i1] = 0;}


 if((m[y+::m2[i1]][x]!='A'&& m2[i1]>=-1 && m2[i1]<=1 )||(m[y+::m2[i1]][x]!='@'&& m2[i1]>=-1 && m2[i1]<=1))
	{m[y+::m2[i1]][x] = 'x'; m[y][x] = ' ';}
 y = y + ::m2[i1];

  if(next=='&') {m2[i1] = 2; stimer = 1;}
}

void verth(char h[24][24], int x, int yi, int yf, int i1, char ch, int I, int J, int life)
{int y=0,ya=0;

 for(int i=yi; i<=yf; i++)
 { if(h[i][x]=='x') y = i;
   if(h[i][x]=='A') ya = i;
 } //locate enemy pos

 if(y==0) lifeh[life] = 0;
 if(y==0 || lifeh[life]<=0) {::h2[i1] = 0; lifeh[life] = 0;}

 randomize(); tdamage = random(5);
 if(h2[i1]!=0) eshoot(3, I, J, y, x);
 if(h2[i1]==2) lifeh[life]-=tdamage;

 if((y==yi)&&(::h2[i1]==-1)) ::h2[i1] = 1;  //update m1
 if((y==yf)&&(::h2[i1]==1))  ::h2[i1] = -1;

 char next = h[y+::h2[i1]][x];

 if(((ya!=0)&&(h2[i1]==1)&&(ya>y))||((ya!=0)&&(h2[i1]==-1)&&(ya<y)))
 {spotted(); ::countsh = 1;}

 if(((ya!=0)&&(h2[i1]==1)&&(y - ya == 1)&&(ch==' '))||((ya!=0)&&(h2[i1]==-1)&&(y - ya == -1)&&(ch==' ')))
 {h[y][x] = ' ';
 lifeh[life] = 0;
 printh(h);
 cout<<"\t\tStealth takedown"; sound3(); getch();}

  if(h[y+::h2[i1]][x]=='*') {landmines(3, y+::h2[i1], x); h2[i1] = 0;}



 if((h[y+::h2[i1]][x]!='A'&& h2[i1]>=-1 && h2[i1]<=1) || (h[y+::h2[i1]][x]!='@'&& h2[i1]>=-1 && h2[i1]<=1 ))
	{h[y+::h2[i1]][x] = 'x'; h[y][x] = ' ';}

 y = y + ::h2[i1];

  if(next=='&') {h2[i1] = 2; stimer = 1;}
}





//MOVE FUNCTIONS



void movee(char e[12][12], int i, int j, char ch)
{ char next = ' ';

   if((e[i][j-1]=='+' && e[i][j+1]=='+')||(e[i][j-1]=='+' && e[i][j+1]=='#')||(e[i][j-1]=='#' && e[i][j+1]=='+')||(e[i-1][j]=='+' && e[i+1][j]=='+')||(e[i-1][j]=='+' && e[i+1][j]=='#')||(e[i-1][j]=='#' && e[i+1][j]=='+'))
  { printe(e); getch(); gameover(1); menu();}

   if((e[i-1][j]=='%')||(e[i+1][j]=='%')||(e[i][j-1]=='%')||(e[i][j+1]=='%'))
  {gameover(2); menu();}

   if(countse>=1) ++countse;

   for(int v = 0; v<2; v++)
   {if(e1[v]==2 && stimer==0) e1[v]=1; if(e2[v]==2 &&stimer==0) e2[v]=1;}

   if(fi==1) ++counti;
	if(counti==countimax) {counti = 0; e[i][j] = 'A'; fi = 0;}

   if(stimer!=0)  stimer++;
   if(stimer==21) stimer = 0;

   if(utimer!=0)  utimer++;
   if(utimer==20) utimer = 0;

  for(int k = 0; k<12; k++)
 {for(int l = 0; l<12; l++)
	{if(e[k][l]=='%') e[k][l] = ' ';}}

	 if(e[i][j-1]=='X' && ch==' ')
	{ e[i][j-1] = ' ';
	  printe(e);
	  cout<<"      Target eliminated";
	  getch();
	}


 if(ch=='1'||ch=='2'||ch=='3'||ch=='4'||ch=='5'||ch=='6'||ch=='7'||ch=='8'||ch=='9'||ch=='k'||ch=='w'||ch=='a'||ch=='s'||ch=='d')
  {assign('1', ch);


	if(ch=='w'||ch=='a'||ch=='s'||ch=='d')
	{
	int num = ch;
	if(se==1) revolver(1, i, j, num);    //calling shooter
	if(ge==1) machinegun(1, i, j, ch);
	}

   if(ch=='k')
	{if((::ie==1)&&(::fi==0))
		{ ::fi = 1; e[i][j] = '@';}
	 if((::le==1)&&(::li==0))
		{ ::li = 1;}
	 if((::te==1)&&(::ti==0))
		{ ::ti = 1;}

	 if(se==1 && i==9 && j==2)
	 egg1();

	 if(ae==1) airstrike(1);
	}

   }

   if(utimer==0)
	   {
  //up
	   if((ch==72)&&(e[i-1][j]!='#')&&(e[i-1][j]!='x')&&(e[i-1][j]!='X')&&(fi==0))
	   {next = e[i-1][j]; e[i-1][j] = 'A';
	   if(e[i][j]!='x')
	   {if(::li==0 && ti==0) e[i][j] = ' ';
	   if(::li==1) {e[i][j] = '*'; li = 0;}
	   if(::ti==1) {e[i][j] = '&'; ti = 0;}}}

  else if((ch==72)&&(e[i-1][j]!='#')&&(e[i-1][j]!='x')&&(e[i-1][j]!='X')&&(fi==1))
	   {next = e[i-1][j]; e[i-1][j] = '@'; if(e[i][j]!='x') e[i][j] = ' ';}

  //down
	   if((ch==80)&&(e[i+1][j]!='#')&&(e[i+1][j]!='x')&&(e[i+1][j]!='X')&&(fi==0))
	   {next = e[i+1][j]; e[i+1][j] = 'A';
	   if(e[i][j]!='x')
	   {if(::li==0 && ti==0) e[i][j] = ' ';
	   if(::li==1) {e[i][j] = '*'; li = 0;}
	   if(::ti==1) {e[i][j] = '&'; ti = 0;}}}

  else if((ch==80)&&(e[i+1][j]!='#')&&(e[i+1][j]!='x')&&(e[i+1][j]!='X')&&(fi==1))
	   {next = e[i+1][j]; e[i+1][j] = '@'; if(e[i][j]!='x') e[i][j] = ' ';}

  //left
	   if((ch==75)&&(e[i][j-1]!='#')&&(e[i][j-1]!='x')&&(e[i][j-1]!='X')&&(fi==0))
	   {next = e[i][j-1]; e[i][j-1] = 'A';
	   if(e[i][j]!='x')
	   {if(::li==0 && ti==0) e[i][j] = ' ';
	if(::li==1) {e[i][j] = '*'; li = 0;}
	if(::ti==1) {e[i][j] = '&'; ti = 0;}}}

  else if((ch==75)&&(e[i][j-1]!='#')&&(e[i][j-1]!='x')&&(e[i][j-1]!='X')&&(fi==1))
	   {next = e[i][j-1]; e[i][j-1] = '@'; if(e[i][j]!='x') e[i][j] = ' ';}

  //right
	   if((ch==77)&&(e[i][j+1]!='#')&&(e[i][j+1]!='x')&&(e[i][j+1]!='X')&&(fi==0))
	{next = e[i][j+1]; e[i][j+1] = 'A';
	if(e[i][j]!='x')
	{if(::li==0 && ti==0) e[i][j] = ' ';
	 if(::li==1) {e[i][j] = '*'; li = 0;}
	 if(::ti==1) {e[i][j] = '&'; ti = 0;}}}

  else if((ch==77)&&(e[i][j+1]!='#')&&(e[i][j+1]!='x')&&(e[i][j+1]!='X')&&(fi==1))
	{next = e[i][j+1]; e[i][j+1] = '@'; if(e[i][j]!='x') e[i][j] = ' ';}

  }

  if(next=='$') {::money = ::money + 100;}
  if(next=='*') gameover(2);
  if(next=='&') utimer = 1;
}



void movem(char m[20][20], int i, int j, char ch)
{ char next = ' ';

  if((m[i][j-1]=='+' && m[i][j+1]=='+')||(m[i][j-1]=='+' && m[i][j+1]=='#')||(m[i][j-1]=='#' && m[i][j+1]=='+')||(m[i-1][j]=='+' && m[i+1][j]=='+')||(m[i-1][j]=='+' && m[i+1][j]=='#')||(m[i-1][j]=='#' && m[i+1][j]=='+'))
  {printm(m); getch(); gameover(1); menu();}

  if((m[i-1][j]=='%')||(m[i+1][j]=='%')||(m[i][j-1]=='%')||(m[i][j+1]=='%'))
  {gameover(2); menu();}

  if(::fi==1) ++counti;
  if(counti==countimax) { counti = 0; ::fi = 0; m[i][j] = 'A';}

  if(stimer!=0)  stimer++;
  if(stimer==21) stimer = 0;

  if(utimer!=0)  utimer++;
  if(utimer==20) utimer = 0;

  if(countsm>=1) ++countsm;

  for(int v = 0; v<3; v++)
   {if(m1[v]==2 && stimer==0) m1[v]=1; if(m2[v]==2 && stimer==0) m2[v]=1;}


   for(int k = 0; k<20; k++)
 {for(int l = 0; l<20; l++)
	{if(m[k][l]=='%') m[k][l] = ' ';}}

	if(m[i-1][j]=='X' && ch==' ')
	{ m[i-1][j] = ' ';
	  printm(m);
	  cout<<"      Target eliminated";
	  getch();
	}

	if(ch=='1'||ch=='2'||ch=='3'||ch=='4'||ch=='5'||ch=='6'||ch=='k'||ch=='w'||ch=='a'||ch=='s'||ch=='d')
	{assign('2', ch);

	if(ch=='w'||ch=='a'||ch=='s'||ch=='d')
	{
	int num = ch;
	if(sm==1) revolver(2, i, j, num);    //calling shooter
	if(gm==1) machinegun(2, i, j, ch);
	}

	if(ch=='k')
		{ if((::im==1)&&(::fi==0))
			{::fi = 1; m[i][j] = '@';}
		  if((::lm==1)&&(::li==0))
			{ ::li = 1;}
		  if((::tm==1)&&(::ti==0))
		{ ::ti = 1;}

		  if(am==1) airstrike(2);
		}

	}

	if(utimer==0)
	  {
  //up
	   if((ch==72)&&(m[i-1][j]!='#')&&(m[i-1][j]!='x')&&(m[i-1][j]!='X')&&(fi==0))
	{next = m[i-1][j]; m[i-1][j] = 'A';
	if(m[i][j]!='x')
	{if(::li==0 && ti==0) m[i][j] = ' ';
	 if(::li==1) {m[i][j] = '*'; li = 0;}
	 if(::ti==1) {m[i][j] = '&'; ti = 0;}}}

  else if((ch==72)&&(m[i-1][j]!='#')&&(m[i-1][j]!='x')&&(m[i-1][j]!='X')&&(fi==1))
	{next = m[i-1][j]; m[i-1][j] = '@'; if(m[i][j]!='x') m[i][j] = ' ';}

  //down
	   if((ch==80)&&(m[i+1][j]!='#')&&(m[i+1][j]!='x')&&(m[i+1][j]!='X')&&(fi==0))
	{next = m[i+1][j]; m[i+1][j] = 'A';
	if(m[i][j]!='x')
	{if(::li==0 && ti==0) m[i][j] = ' ';
	 if(::li==1) {m[i][j] = '*'; li = 0;}
	 if(::ti==1) {m[i][j] = '&'; ti = 0;}}}

  else if((ch==80)&&(m[i+1][j]!='#')&&(m[i+1][j]!='x')&&(m[i+1][j]!='X')&&(fi==1))
	{next = m[i+1][j]; m[i+1][j] = '@'; if(m[i][j]!='x') m[i][j] = ' ';}

  //left
	   if((ch==75)&&(m[i][j-1]!='#')&&(m[i][j-1]!='x')&&(m[i][j-1]!='X')&&(fi==0))
	{next = m[i][j-1]; m[i][j-1] = 'A';
	if(m[i][j]!='x')
	{if(::li==0 && ti==0) m[i][j] = ' ';
	if(::li==1) {m[i][j] = '*'; li = 0;}
	if(::ti==1) {m[i][j] = '&'; ti = 0;}}}

  else if((ch==75)&&(m[i][j-1]!='#')&&(m[i][j-1]!='x')&&(m[i][j-1]!='X')&&(fi==1))
	{next = m[i][j-1]; m[i][j-1] = '@'; if(m[i][j]!='x') m[i][j] = ' ';}

  //right
	   if((ch==77)&&(m[i][j+1]!='#')&&(m[i][j+1]!='x')&&(m[i][j+1]!='X')&&(fi==0))
	   {next = m[i][j+1]; m[i][j+1] = 'A';
	   if(m[i][j]!='x')
	   {if(::li==0 && ti==0) m[i][j] = ' ';
	   if(::li==1) {m[i][j] = '*'; li = 0;}
	   if(::ti==1) {m[i][j] = '&'; ti = 0;}}}

  else if((ch==77)&&(m[i][j+1]!='#')&&(m[i][j+1]!='x')&&(m[i][j+1]!='X')&&(fi==1))
	   {next = m[i][j+1]; m[i][j+1] = '@'; if(m[i][j]!='x') m[i][j] = ' ';}

	}

  if(next=='$') {::money = ::money + 100;}
  if(next=='*') gameover(2);
  if(next=='&') utimer = 1;
}



void moveh(char h[24][24], int i, int j, char ch)
{ char next = ' ';

  if((h[i][j-1]=='+' && h[i][j+1]=='+')||(h[i][j-1]=='+' && h[i][j+1]=='#')||(h[i][j-1]=='#' && h[i][j+1]=='+')||(h[i-1][j]=='+' && h[i+1][j]=='+')||(h[i-1][j]=='+' && h[i+1][j]=='#')||(h[i-1][j]=='#' && h[i+1][j]=='+'))
  {printh(h); getch(); gameover(1); menu();}

  if((h[i-1][j]=='%')||(h[i+1][j]=='%')||(h[i][j-1]=='%')||(h[i][j+1]=='%'))
  {gameover(2); menu();}

  if((h[i-1][j]=='!')||(h[i+1][j]=='!'))
  {gameover(3); menu();}

  if(::fi==1) ++counti;
  if(counti==countimax) {::counti = 0; ::fi = 0; h[i][j] = 'A';}

  if(stimer!=0)  stimer++;
  if(stimer==21) stimer = 0;

  if(utimer!=0)  utimer++;
  if(utimer==20) utimer = 0;

  if(countsh>=1) ++countsh;

  for(int v = 0; v<7; v++)
   {if(h1[v]==2 && stimer==0) h1[v]=1; if(h2[v]==2 && stimer==0) h2[v]=1;}


  for(int k = 0; k<24; k++)
 {for(int l = 0; l<24; l++)
	{if(h[k][l]=='%') h[k][l] = ' ';}}

	if(h[i-1][j]=='X' && ch==' ')
	{ h[i-1][j] = ' ';
	  printh(h);
	  cout<<"      Target eliminated";
	  getch();
	}

	if(ch=='1'||ch=='2'||ch=='3'||ch=='4'||ch=='5'||ch=='6'||ch=='7'||ch=='8'||ch=='9'||ch=='k'||ch=='w'||ch=='a'||ch=='s'||ch=='d')
	{assign('3', ch);

	if(ch=='w'||ch=='a'||ch=='s'||ch=='d')
	{
	int num = ch;
	if(sh==1) revolver(3, i, j, num);    //calling shooter
	if(gh==1) machinegun(3, i, j, ch);
	}

   if(ch=='k')
	{if((::ih==1)&&(::fi==0))
		{::fi = 1; h[i][j] = '@';}
	 if((::lh==1)&&(::li==0))
		{ ::li = 1;}
	 if((::th==1)&&(::ti==0))
		{ ::ti = 1;}

	 if(sh==1 && i==12  && j==16)
	 egg2();

	 if(ah==1) airstrike(3);
	}

	}

   if(utimer==0)
	 {
  //up
	   if((ch==72)&&(h[i-1][j]!='#')&&(h[i-1][j]!='x')&&(h[i-1][j]!='X')&&(fi==0))
	{next = h[i-1][j]; h[i-1][j] = 'A';
	if(h[i][j]!='x')
	{if(::li==0 && ti==0) h[i][j] = ' ';
	 if(::li==1) {h[i][j] = '*'; li = 0;}
	 if(::ti==1) {h[i][j] = '&'; ti = 0;}}}

  else if((ch==72)&&(h[i-1][j]!='#')&&(h[i-1][j]!='x')&&(h[i-1][j]!='X')&&(fi==1))
	{next = h[i-1][j]; h[i-1][j] = '@'; if(h[i][j]!='x') h[i][j] = ' ';}

  //down
	   if((ch==80)&&(h[i+1][j]!='#')&&(h[i+1][j]!='x')&&(h[i+1][j]!='X')&&(fi==0))
	{next = h[i+1][j]; h[i+1][j] = 'A';
	if(h[i][j]!='x')
	{if(::li==0 && ti==0) h[i][j] = ' ';
	if(::li==1) {h[i][j] = '*'; li = 0;}
	if(::ti==1) {h[i][j] = '&'; ti = 0;}}}

  else if((ch==80)&&(h[i+1][j]!='#')&&(h[i+1][j]!='x')&&(h[i+1][j]!='X')&&(fi==1))
	{next = h[i+1][j]; h[i+1][j] = '@'; if(h[i][j]!='x') h[i][j] = ' ';}

  //left
	   if((ch==75)&&(h[i][j-1]!='#')&&(h[i][j-1]!='x')&&(h[i][j-1]!='X')&&(fi==0))
	{next = h[i][j-1]; h[i][j-1] = 'A';
	if(h[i][j]!='x')
	{if(::li==0 && ti==0) h[i][j] = ' ';
	 if(::li==1) {h[i][j] = '*'; li = 0;}
	 if(::ti==1) {h[i][j] = '&'; ti = 0;}}}

  else if((ch==75)&&(h[i][j-1]!='#')&&(h[i][j-1]!='x')&&(h[i][j-1]!='X')&&(fi==1))
	{next = h[i][j-1]; h[i][j-1] = '@'; if(h[i][j]!='x') h[i][j] = ' ';}

  //right
	   if((ch==77)&&(h[i][j+1]!='#')&&(h[i][j+1]!='x')&&(h[i][j+1]!='X')&&(fi==0))
	{next = h[i][j+1]; h[i][j+1] = 'A';
	if(h[i][j]!='x')
	{if(::li==0 && ti==0) h[i][j] = ' ';
	if(::li==1) {h[i][j] = '*'; li = 0;}
	if(::ti==1) {h[i][j] = '&'; ti = 0;}}}

  else if((ch==77)&&(h[i][j+1]!='#')&&(h[i][j+1]!='x')&&(h[i][j+1]!='X')&&(fi==1))
	{next = h[i][j+1]; h[i][j+1] = '@'; if(h[i][j]!='x') h[i][j] = ' ';}

	 }

  if(next=='$') {::money = ::money + 100;}
  if(next=='*') gameover(2);
  if(next=='&') utimer = 1;
}









void printlogo()
{textcolor(12);
 clrscr();

 cout<<"\n\n";

 cout<<"\t\t         XXXX   XXXX   XXXXXX   XXXXX  \n";
 cout<<"\t\t         X  X   X      X          X    \n";
 cout<<"\t\t         XXXX   XXXX   X  XXX     X    \n";
 cout<<"\t\t         X      X      X    X     X    \n";
 cout<<"\t\t         X      XXXX   XXXXXX   XXXXX  \n";

 cout<<"\n\n";

 cout<<"\t\t             XXXXXXXXXXXXXXXXXXX  \n";
 cout<<"\t\t             X                 X  \n";
 cout<<"\t\t             X                 X  \n";
 cout<<"\t\t             X     X    XXXX   X  \n";
 cout<<"\t\t             X   XXX    X      X  \n";
 cout<<"\t\t             X     X    XXX    X  \n";
 cout<<"\t\t             X     X       X   X  \n";
 cout<<"\t\t             X     X       X   X  \n";
 cout<<"\t\t             X   XXXXX  XXX    X  \n";
 cout<<"\t\t             X                 X  \n";
 cout<<"\t\t             X                 X  \n";
 cout<<"\t\t             XXXXXXXXXXXXXXXXXXX  \n";

 cout<<"\n\n";

 cout<<"\t     Warning:  Game contains graphic content and violence \n";
 cout<<"\t         All rights reserved by Rocksteady Studios Inc.   \n";

 getch();
 beep();
 textcolor(10);

 clrscr();
	cout<<"\n\n\n\n\n\n\n";
	cout<<"\t\t    X   X   XXXXX   XXXXX   XXXXX   XXXXX    	\n";
	cout<<"\t\t    X   X   X         X     X         X       \n";
	cout<<"\t\t    XXXXX   XXXXX     X     XXXXX     X     	\n";
	cout<<"\t\t    X   X   X         X         X     X     	\n";
	cout<<"\t\t    X   X   XXXXX   XXXXX   XXXXX     X     	\n\n\n\n";
	cout<<"\t\t     <<  P R E S S   A N Y   K E Y  >>";
  getch();
  beep();
  menu();
}


void instructions()
{textcolor(9);
 clrscr();
 cout<<"\t\t            I N S T R U C T I O N S:  \n\n\n";

 cout<<"        You are Jack Griffin, a highly trained master thief and assassin.\n\n\n";
 cout<<"           Your OBJECTIVE is to break into a high-security facility and \n";
 cout<<"           eliminate your target without alerting any of the patrolling \n";
 cout<<"           guards, who are all heavily armed and will FIRE ON SIGHT.  \n\n\n";
 cout<<"          Being detected by the target causes an immediate MISSION ABORT. \n";
 cout<<"\n\n";
 cout<<"           COUNTER-MISSION: To steal as much money from the facility    \n";
 cout<<"                            as possible to maximize profits.            \n\n";
 cout<<"\n           Reach the exit point at the other end of the facility    \n";
 cout<<"            for pickup and assimilation of assets.";
 cout<<"\n\n\n                                   Good luck.";
 beep();
 getch();

 menu();
}



void controls()
{textcolor(10);
 clrscr();
 cout<<"\t\t               C O N T R O L S:     \n\n\n";

 cout<<"\t\t   Arrow keys -  Movement                                 \n\n";
 cout<<"\t\t     Spacebar -  Stealth takedown \n";
 cout<<"\t\t                 (when right behind an enemy) \n\n";
 cout<<"\t\t  1/2/3/4/5/6 -  Equip ability   (if purchased)           \n\n";
 cout<<"                                 1 - Silenced pistol          \n";
 cout<<"                                 2 - Invisibility             \n";
 cout<<"                                 3 - Landmines                \n";
 cout<<"                                 4 - Machine Gun                  \n";
 cout<<"                                 5 - Airstrike                \n";
 cout<<"                                 6 - Snare trap               \n\n\n";
 cout<<"\t\t      W/A/S/D -  Shooting \n";
 cout<<"\t                        (when pistol / machine gun is equipped)           \n\n";
 cout<<"\t\t            k -  Use ability                              \n\n";
 beep();
 getch();

 textcolor(14);
 clrscr();
 cout<<"\n\n\n";
 cout<<"\t\t              L E X I C O N:   \n\n\n";
 cout<<"\t\t            A - Player                  \n\n";
 cout<<"\t\t            @ - Player (when invisible) \n\n";
 cout<<"\t\t            x - Patrolling guard        \n\n";
 cout<<"\t\t            X - Assassination target    \n\n";
 cout<<"\t\t            $ - Gold stash ($100)       \n\n";
 cout<<"\t\t            # - Walls                   \n\n";
 cout<<"\t\t            + - Enemy fire              \n\n";
 cout<<"\t\t            % - Explosion shrapnel      \n\n";
 cout<<"\t\t            * - Landmine                \n\n";
 cout<<"\t\t            & - Snare trap              \n\n";
 beep();
 getch();

 menu();
}



void menu()
{lives=maxlives; bullets = maxbullets; ammo = maxammo;
 money = 0;

 counti = 0;
 countse = countsm = countsh = 0;
 builde(e, 1, 1);
 buildm(m, 2, 2);
 buildh(h, 1, 3);

 if(u1=='1'||u2=='1'||u3=='1'||u4=='1'||u5=='1'||u6=='1') unlocked = 1;
 else unlocked = 0;

 for(int v = 0; v<12; v++)
 {if (v<3)lifee[v] = eh;if(v<6)lifem[v] = mh; lifeh[v] = hh;}
clrscr();
if (flag==1)exit(0);
char ch='0', ch2='0';
	textcolor(11);
	clrscr();
	while(ch<'1'||ch>'9')
	   {clrscr();
	   cout<<"\n\n";
	   cout<<"\t\t     X    X    XXXXX    X    X    X    X  \n";
	   cout<<"\t\t     XX  XX    X        XX   X    X    X  \n";
	   cout<<"\t\t     X XX X    XXXXX    X X  X    X    X  \n";
	   cout<<"\t\t     X    X    X        X  X X    X    X  \n";
	   cout<<"\t\t     X    X    XXXXX    X   XX     XXXX   \n";
	cout<<"\n\n\t\t\t\t\t\t\t Funds:"<<totalmoney<<"\n\n";
	cout<<"                     (1)PLAY       \n";
	cout<<"                     (2)INSTRUCTONS\n";
	cout<<"                     (3)CONTROLS   \n";
	cout<<"                     (4)STORE \n";
	cout<<"                     (5)SAVE GAME \n";
	cout<<"                     (6)LOAD GAME \n";
	cout<<"                     (7)ERASE DATA \n";
	cout<<"                     (8)ACHIEVEMENTS \n";
	cout<<"                     (9)QUIT     \n\n\n";
	cout<<"                     ENTER CHOICE(1-9): ";
	ch=getch();
	   }
	switch(ch)
	{case'1':{clrscr(); beep();
		 while(ch2<'1'||ch2>'3')
			   {clrscr();cout<<"\n\n\n\n\n";
			cout<<"                               SELECT LEVEL:   \n\n\n";
			cout<<"                              << ROOKIE   >>   \n\n";
			cout<<"                              << VETERAN  >>   \n\n";
			cout<<"                              << HARDCORE >>   \n\n\n\n";
			cout<<"                           ENTER CHOICE (1/2/3): ";
			ch2=getch();
			   }
		 switch(ch2)
			{case '1':{levelkills=0;
				   builde(e,1,1);
				   textcolor(11);
				   printe(e); sound2();
				   char ch;
				   int I, J, tflag = 0;
				   utimer = 0;
				   money = 0;
				   e[2][4] = 'x';  e1[0] = 1; counti = 0;
				   e[2][6] = 'x';  e2[0] = 1;
				   e[4][10] = 'x'; e2[1] = 1;
				   countse = 0; countsm = 0; countsh = 0;
				   se = 0; ie = 0; le = 0;

				   while(1)
				 { for(int i=0; i<12; i++)
					  {for(int j=0; j<12; j++)
					  {if(e[i][j]=='A')
						  {I = i; J = j;}
					   if(e[i][j]=='@')
						  {I = i; J = j;}
					  }
					  }

					  if(kbhit)
					  {ch = getch();
					   sh = 0;
					   for(int k = 0; k<12; k++)
						{for(int l = 0; l<12; l++)
						{if(e[k][l]=='-'||e[k][l]=='|')
						e[k][l] = ' ';}}

					   if(e[9][2]!='A' && e[9][2]!='@') e[9][2] = '?';
					   if(e[7][6]!='X') tflag = 1;
					   if(::money<0) ::money = 0;
					   if((e[8][6]=='A'&&tflag==0)||(e[9][6]=='A'&&tflag==0)||(e[10][6]=='A'&&tflag==0))
					   {spotted(); gameover(0);}

					  if(ch==75||ch==72||ch==77||ch==80||ch=='1'||ch=='2'||ch=='3'||ch=='4'||ch=='5'||ch=='6'||ch=='7'||ch=='8'||ch=='9'||ch==' '||ch=='k'||ch=='w'||ch=='a'||ch=='s'||ch=='d')
						   {horize(e, 2, 6, 10, 0, ch, I, J, 0);
						   verte(e, 4, 1, 9, 0, ch, I, J, 1);
						   verte(e, 10, 4, 10, 1, ch, I, J, 2);
						   movee(e, I, J, ch);
						   printe(e);
						   }



					   if(e[10][10]=='A' && tflag==1)
						   {complete[0]=1;
						textcolor(10);
						clrscr();
						cout<<"\n\n\n";
						cout<<"\t\t         <<    Y O U   W I N    >> \n\n\n";
						cout<<"\t\t     You stole "<<::money<<" dollars in your heist";
						totalmoney+=money;
						money=0; levelkills = 0; int ghostflag = 1;

						for(int d=0; d<3; d++)
						{if(lifee[d]==0) ++levelkills;
						if(lifee[d]!=10) ghostflag = 0;
						}

						if ((ghostflag==1)&&(lives==maxlives)){achievement[0]='1';nf=1;}
						if (levelkills==3){achievement[1]='1';nf=1;}
						if (complete[0]&&complete[1]&&complete[2]){achievement[4]='1';nf=1;}
						if(nf) {cout<<"\n\n\n\t\t            ACHIEVEMENT UNLOCKED"; nf = 0;}
						winsound();
						getch();
						clrscr();
						menu();
						   }
					   if(ch==27){menu();}
					   }
				 }
				  }
			case '2':{buildm(m,2,2);
				  textcolor(11);
				  printm(m); sound2();
				  char ch;
				  int I, J, tflag = 0;
				  utimer = 0;
				  money = 0;
				  m[7][7] = 'x';   m1[0] = 1; counti = 0;
				  m[11][1] = 'x';  m1[1] = 1;
				  m[14][7] = 'x';  m1[2] = 1;
				  m[6][12] = 'x';  m2[0] = 1;
				  m[4][16] = 'x';  m2[1] = 1;
				  m[12][17] = 'x'; m2[2] = 1;
				  countsm = 0; countse = 0; countsh = 0;
				  sm = 0; im = 0; lm = 0;

				   while(1)
				 { for(int i=0; i<20; i++)
					  {for(int j=0; j<20; j++)
					  {if(m[i][j]=='A')
						  {I = i; J = j;}
					   if(m[i][j]=='@')
						  {I = i; J = j;}
					  }
					  }
					  if(kbhit)
					  {ch = getch();
					   sh = 0;
					   for(int k = 0; k<20; k++)
						{for(int l = 0; l<20; l++)
						{if(m[k][l]=='-'||m[k][l]=='|')
						m[k][l] = ' ';}}

					   if(m[1][16]!='X') tflag = 1;
					   if(::money<0) ::money = 0;
					   if((m[1][17]=='A'&&tflag==0)||(m[1][18]=='A'&&tflag==0))
					   {spotted(); gameover(0);}

						if(ch==75||ch==72||ch==77||ch==80||ch=='1'||ch=='2'||ch=='3'||ch=='4'||ch=='5'||ch=='6'||ch=='7'||ch=='8'||ch=='9'||ch=='k'||ch==' '||ch=='w'||ch=='a'||ch=='s'||ch=='d')
						   {vertm(m, 12, 6, 11, 0, ch, I, J, 0);
							vertm(m, 16, 4, 10, 1, ch, I, J, 1);
							vertm(m, 17, 5, 12, 2, ch, I, J, 2);
							horizm(m, 7, 1, 7, 0, ch, I, J, 3);
							horizm(m, 11, 1, 9, 1, ch, I, J, 4);
							horizm(m, 14, 7, 9, 2, ch, I, J, 5);
						movem(m, I, J, ch);
						printm(m);
						}



					   if(m[18][18]=='A' && tflag==1)
						   {complete[1]=1;
						   textcolor(10);
						   clrscr();
						   cout<<"\n\n\n";
						   cout<<"\t\t          <<   Y O U   W I N   >>\n\n\n";
						   cout<<"\t\t     You stole "<<::money<<" dollars in your heist";
						   totalmoney+=money;
						   money=0; levelkills = 0; int ghostflag = 1;

						for(int d = 0; d<6; d++)
						{if(lifem[d]==0) ++levelkills;
						if(lifem[d]!=20) ghostflag = 0;}

						if ((ghostflag==1)&&(lives==maxlives)){achievement[0]='1';nf=1;}
						if (levelkills==6){achievement[1]='1';nf=1;}
						if (complete[0]&&complete[1]&&complete[2]){achievement[4]='1';nf=1;}
						if(nf) {cout<<"\n\n\n\t\t            ACHIEVEMENT UNLOCKED"; nf = 0;}

						winsound();
						getch();
						clrscr();
						menu();
						   }
					   if(ch==27){menu();}
					   }
				 }}
			case '3':{buildh(h,1,3);
				  textcolor(11);
				  printh(h); sound2();
				  char ch;
				  int I, J, tflag = 0;
				  utimer = 0;
				  money = 0;
				  h[6][1] = 'x';   h1[0] = 1; counti = 0;
				  h[3][8] = 'x';   h1[1] = 1;
				  h[7][14] = 'x';  h1[2] = 1;
				  h[16][10] = 'x';  h1[3] = 1;
				  h[17][7] = 'x';  h1[4] = 1;
				  h[18][11] = 'x';  h1[5] = 1;
				  h[19][9] = 'x';  h1[6] = 1;

				  h[1][19] = 'x';  h2[0] = 1;
				  h[14][17] = 'x'; h2[1] = 1;
				  h[7][19] = 'x';  h2[2] = 1;
				  h[11][11] = 'x'; h2[3] = 1;
				  h[17][13] = 'x'; h2[4] = 1;
				  countsh = 0;
				  sh = 0; ih = 0; lh = 0;

				   while(1)
				 { for(int i=0; i<24; i++)
					  {for(int j=0; j<24; j++)
					  {if(h[i][j]=='A')
						  {I = i; J = j;}
					   if(h[i][j]=='@')
						  {I = i; J = j;}
					  }
					  }
					  if(kbhit)
					  {ch = getch();

					   for(int k = 0; k<24; k++)
						{for(int l = 0; l<24; l++)
						{if(h[k][l]=='-'||h[k][l]=='|')
						h[k][l] = ' ';}}

					   if(h[12][16]!='A' && h[12][16]!='@') h[12][16] = '?';
					   if(h[12][4]!='X') tflag = 1;
					   if(::money<0) ::money = 0;
					   if((h[12][3]=='A'&&tflag==0)||(h[13][3]=='A'&&tflag==0)||(h[12][2]=='A'&&tflag==0)||(h[13][2]=='A'&&tflag==0))
					   {spotted(); gameover(0);}

					   if(ch==75||ch==72||ch==77||ch==80||ch=='1'||ch=='2'||ch=='3'||ch=='4'||ch=='5'||ch=='6'||ch=='7'||ch=='8'||ch=='9'||ch=='k'||ch==' '||ch=='w'||ch=='a'||ch=='s'||ch=='d')
						{verth(h, 1, 6, 10, 0, ch, I, J, 0);
						verth(h, 8, 3, 6, 1, ch, I, J, 1);
						verth(h, 19, 1, 5, 2, ch, I, J, 2);
						verth(h, 19, 7, 12, 3, ch, I, J, 3);
						verth(h, 13, 17, 22, 4, ch, I, J, 4);

						horizh(h, 7, 10, 14, 0, ch, I, J, 5);
						horizh(h, 14, 17, 20, 1, ch, I, J, 6);
						horizh(h, 11, 6, 11, 2, ch, I, J, 7);
						horizh(h, 16, 6, 11, 3, ch, I, J, 8);
						horizh(h, 17, 6, 11, 4, ch, I, J, 9);
						horizh(h, 18, 6, 11, 5, ch, I, J, 10);
						horizh(h, 19, 6, 11, 6, ch, I, J, 11);

						moveh(h, I, J, ch);
						printh(h);
						}



					   if(h[22][22]=='A' && tflag==1)
						   {complete[2]=1;
						textcolor(10);
						clrscr();
						cout<<"\n\n\n";
						cout<<"\t\t          <<   Y O U   W I N   >>\n\n\n";
						cout<<"\t\t     You stole "<<::money<<" dollars in your heist";
						totalmoney+=money;
						money=0; levelkills = 0; int ghostflag = 1;

						for(int d = 0; d<12; d++)
						{if(lifeh[d]==0) ++levelkills;
						 if(lifeh[d]!=50) ghostflag = 0;}

						if ((ghostflag==1)&&(lives==maxlives)){achievement[0]='1';nf=1;}
						if (levelkills==12 && achievement[1]!='1') {achievement[1]='1';nf=1;}
						if (complete[0] && complete[1] && complete[3] && achievement[4]!='1') {achievement[4]='1';nf=1;}
						if(nf) {cout<<"\n\n\n\t\t            ACHIEVEMENT UNLOCKED"; nf = 0;}

						winsound();
						getch();
						clrscr();
						menu();
						   }
					   if(ch==27){menu();}
					   }
				 }}
			default:break;
	 }
	 case '2':{instructions();    break;}
	 case '3':{controls();        break;}
	 case '4':{store();   break;}
	 case '5':{save();            break;}
	 case '6':{retrieve();        break;}
	 case '7':{resetdata();       break;}
	 case '8':{achieve();         break; }

	 default :{exit(0);}
	}
}}


void main()
{clrscr();
printlogo();
menu();
if (flag==1)exit(0);
}