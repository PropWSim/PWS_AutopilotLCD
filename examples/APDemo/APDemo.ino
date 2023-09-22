#include <PWS_AutopilotLCD.h>

void testAnnunciator(void);
void testPrompt(void);
void testDigit(void);

void debug(byte, const char *, ...);

PWS_AutopilotLCD	APlcd;

void setup() {
	Serial.begin(115200);

	delay(50);
	APlcd.begin(0xB); // See PWS_AutopilotLCD.h for initialization values. 0xB will give about 3.3V LCD drive with a 5V Vdd.
}

void loop() {
	APlcd.lampTest(1000);
	testPrompt();
	testAnnunciator();
	testDigit();
}

void
testAnnunciator(void)
{
	for (enum ANNUNCIATOR i = AN_AP; i <= AN_INHG; i = static_cast<enum ANNUNCIATOR>(static_cast<int>(i) + 1)) {
		APlcd.annunciator(i, true);
		delay(550);
		APlcd.annunciator(i, false);
	}
}

void
testPrompt(void)
{
	for (enum PROMPT i = B1_HDG; i <= B4_CLR; i = static_cast<enum PROMPT>(static_cast<int>(i) + 1)) {
		APlcd.prompt(i);
		delay(550);
	}
}

void
testDigit(void)
{
	for (int32_t i = -9999; i < 100000; i +=3)
		APlcd.digits(i);
}