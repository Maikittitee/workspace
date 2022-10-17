//TODO : Fix digitalWrite()

//define pin
#define LED_W_R 4
#define LED_W_Y 5
#define LED_W_G 6
#define WEST_BUTTON_PIN 2

#define LED_S_R 8
#define LED_S_Y 9
#define LED_S_G 10
#define SOUTH_BUTTON_PIN 3

#define LED_H_R 11
#define LED_H_G 12
#define HUMAN_BUTTON_PIN 13


// define state
#define goW 0
#define waitW 1
#define goS 2
#define waitS 3
#define goH 4
#define off1 5
#define on1 6
#define off2 7
#define on2 8
#define off3 9
#define on3 10


typedef const struct State {
	unsigned long ST_Out;
	unsigned long Time;
	unsigned long Next[8];
} SType;

SType FSM[11] ={
	{B01100001, 2000, {goW, waitW, goW, waitW, waitW, waitW, waitW, waitW}},
	{B01010001, 300, {goS, goS, goS, goS, goH, goH, goH, goH}},
	{B01001100, 2000, {goS, goS, waitS, waitS, waitS, waitS, waitS, waitS}},
	{B01001010, 300, {goH, goW, goW, goW, goH, goH, goH, goH}},
	{B10001001, 2000, {goH, off1, off1, off1, goH, off1, off1, off1}},
	{B00001001, 100, {on1, on1, on1, on1, on1, on1, on1, on1}},
	{B10001001, 100, {off2, off2, off2, off2, off2, off2, off2, off2}},
	{B00001001, 100, {on2, on2, on2, on2, on2, on2, on2, on2}},
	{B10001001, 100, {off3, off3, off3, off3, off3, off3, off3}},
	{B00001001, 100, {on3, on3, on3, on3, on3, on3, on3, on3},
	{B10001001, 100, {goW, goS, goW, goW, goW, goS, goW, goW}}
};

unsigned long S = 0;

void	setup()
{
	pinMode(LED_W_R, OUTPUT);
	pinMode(LED_W_Y, OUTPUT);
	pinMode(LED_W_G, OUTPUT);
	pinMode(WEST_BUTTON_PIN, INPUT);

	pinMode(LED_S_R, OUTPUT);
	pinMode(LED_S_Y, OUTPUT);
	pinMode(LED_S_G, OUTPUT);
	pinMode(SOUTH_BUTTON_PIN, INPUT);
	
	pinMode(LED_H_R, OUTPUT);
	pinMode(LED_H_G, OUTPUT);
	pinMode(HUMAN_BUTTON_PIN, INPUT);
}

int	input;
int	input1;
int	input2;
int input3;
void	loop()
{
	digitalWrite(LED_W_R, FSM[S].ST_Out & B00001000);
	digitalWrite(LED_W_Y, FSM[S].ST_Out & B00010000);
	digitalWrite(LED_W_G, FSM[S].ST_Out & B00100000);

	digitalWrite(LED_S_R, FSM[S].ST_Out & B00000001);
	digitalWrite(LED_S_Y, FSM[S].ST_Out & B00000010);
	digitalWrite(LED_S_G, FSM[S].ST_Out & B00000100);

	digitalWrite(LED_H_R, FSM[S].ST_Out & B01000000);
	digitalWrite(LED_H_G, FSM[S].ST_Out & B10000000);

	delay (FSM[S].Time);

	input1 = digitalRead(SOUTH_BUTTON_PIN);
	input2 = digitalRead(WEST_BUTTON_PIN);
	input3 = digitalRead(HUMAN_BUTTON_PIN);

	input = ((input3 * 2) + input2) * 2 + input1;
	S = FSM[S].Next[input];

}
