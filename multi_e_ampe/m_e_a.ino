//-------------------------------------------------
//  Voltimeter using Arduino and 7 Segments Display
//  Developed by Caio Luiz Gomes
//  Email: caio.alves at cear.ufpb.br
//-------------------------------------------------

// DEFINE
#define r1       1000000;
#define r2       100000;
#define aRef     5;
#define time_ref 500;
#define a_read_v    10;   //Pino da tensão
#define a_read_i    11;   //Pino da corrente

//Declaração de portas
int a_1[] = {2,3,4,5};
int a_2[] = {6,7,8,9};

// Global variable
float voltage;
unsigned long millis_ref = 0;

// Voltage Function
float voltage_func(int a_read_v){
	return (analogRead(a_read_v)*aRef) / 1023.0 * ((r1+r2)/r2);
}

// Ammeter Function
float amper_func(int a_read_i)
{

}
void setup()
{
	for (int pin = 0; pin < 4; pin++)
	{
		pinMode(a_1[pin],OUTPUT);
		pinMode(a_2[pin],OUTPUT);
	}
	
	pinMode(pin_v,INPUT);
	pinMode(pin_i,INPUT);
}

void loop(){
	if((millis()-millis_ref) > time_ref) {
	voltage = voltage_func(A1);
	millis_ref = millis();
	}
	float v = voltage;

	//Falta mostrar o valor da tensão
}

void display_7(byte num)
{
	for(int i = 0; i < 4; i++)
	{
		if(bitRead(num,i)==1)
		{
			digitalWrite(a_1[i],HIGH);
		}
		else
		{
			digitalWrite(a_1[i],LOW);
		}
	}
}
