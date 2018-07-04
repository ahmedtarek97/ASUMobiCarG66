int change (int a )
{
  if (a==0) a=1;
  else a=0;
  }
void setup() {
  // put your setup code here, to run once:
for (int i= 0 ; i<8 ; i++)
{
  pinMode (i,OUTPUT);
  }
  int a[8]={0,0,0,0,0,0,0,0};
}

void loop() {
  // put your main code here, to run repeatedly:
   int a[8]={0,0,0,0,0,0,0,0};
for (int i=0;i<256;i++)
{   
  change (a[7]);
  if(i%2 ==0){change (a[6]);}
  if(i%4 ==0){change (a[5]);}
  if(i%8 ==0){change (a[4]);}
  if(i%16 ==0){change (a[3]);}
  if(i%32 ==0){change (a[2]);}
  if(i%64 ==0){change (a[1]);}
  if(i%126==0){change (a[0]);}
  for (int i= 0 ; i <8 ; i++)
  {
    if (a[i]==1)
   { digitalWrite (i,HIGH);//pin 0 is the MSB
    delay (1000);}
    else 
    digitalWrite (i ,LOW);
    delay (1000);
    }
  
  }
}
