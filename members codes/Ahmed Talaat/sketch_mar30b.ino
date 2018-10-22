void setup() {
    pinMode(4, INPUT);
    pinMode(5, INPUT);
    pinMode(6, INPUT);
    pinMode(7, INPUT);
    pinMode(8, INPUT);
    pinMode(9, INPUT);
    pinMode(10, INPUT);
    pinMode(11, INPUT);
    pinMode(13, OUTPUT);

}
int var1 ,var2 ,var3, var4 ,var5 ,var6 ,var7 ,var8 ;
int dec = 0;
void loop() {
 
var1 = digitalRead (4);
dec += (var1 * 1) ;


var2 = digitalRead (5);
dec += (var2 * 2) ;

var3 = digitalRead (6);
dec += (var3 *4) ;


var4 = digitalRead (7);
dec += (var4 * 8) ;


var5 = digitalRead (8);
dec += (var5 *16) ;


var6 = digitalRead (9);
dec += (var6 * 32) ;

var7 = digitalRead (10);
dec += (var7 * 64) ;


var8 = digitalRead (11);
dec += (var8 * 128) ;


digitalWrite (13,HIGH);
delay (dec*4);



}
